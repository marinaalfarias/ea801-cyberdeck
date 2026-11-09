---
marp: true
theme: default
paginate: true
backgroundColor: #f5f5f5
color: #e04fa4
header: 'Tamagochi — EA801'
footer: 'Mariana Leister (233115) · Marina Farias (188521)'
style: |
  section {
    font-size: 26px;
    line-height: 1.4;
  }
  h1 { font-size: 44px; }
  h2 { font-size: 34px; }
  h3 { font-size: 26px; color: #4a7c59; }
  table { font-size: 20px; }
  code { font-size: 18px; }
---

<!-- _paginate: false -->
<!-- _header: '' -->
<!-- _footer: '' -->

# CyberDeck-Tama

## Dispositivo Portátil Interativo

<br>

**Mariana Leister Gonçalves** — RA: 233115
**Marina Alves Farias** — RA: 188521

<br>

EA801 — Lab. de Projetos de Sistemas Embarcados
06 de novembro de 2026

---

# O que é?

- Protótipo portátil baseado em **ESP32**
- Criatura virtual em **display TFT 1,8"**
- Interação por **3 botões** + **LDR**
- Feedback sonoro com **buzzer passivo**

<br>

---

# Hardware

| Componente | Interface | Pino |
| :--- | :--- | :--- |
| Display TFT | SPI | CS=15, DC=2, RST=22 |
| Display TFT | SPI | MOSI=23, SCLK=18 |
| Botão| GPIO | 19 |
| LDR | ADC | 4 |
| Buzzer | PWM | 16 |

---

# Arquitetura de Software

### FreeRTOS + dois núcleos

<br>

| Task | Núcleo | Período |
| :--- | :--- | :--- |
| `taskUI` | 1 | 100 ms |
| `taskInput` | 1 | 20 ms |
| `taskSensores` | 0 | 500 ms |
| `taskJogo` | 0 | 1000 ms |

<br>

**Núcleo 1:** interface rápida
**Núcleo 0:** lógica e sensores

---

# Tasks do FreeRTOS

### O que cada uma faz

<br>

- **`taskJogo`:** FSM, decaimento de status
- **`taskUI`:** desenha imagem e textos
- **`taskInput`:** lê botões com debounce
- **`taskSensores`:** lê LDR e dorme/acorda

---

# Máquina de Estados (FSM)

### 8 estados
OVO → CHOCANDO → NORMAL ↔ TRISTE ↔ BRAVO ↔ FELIZ
↓
DORMINDO
↓
MORTO

<br>

- **Humor** derivado da fome
- **Sono** ativado pelo LDR
- **Morte** com fome/energia = 0

---

# Regras de Decaimento

| Estado | Fome | Energia |
| :--- | :--- | :--- |
| Acordado | −1/s | −1/s |
| Dormindo | −0,5/s | +3/s |
| Morto | parado | parado |

<br>

**Humor:**
1–14 BRAVO · 15–29 TRISTE · 30–70 NORMAL · 71–100 FELIZ

---

# Interface Visual

### Tela dividida em 2 regiões

<br>

- **Topo (0–80 px):** sprite do bicho
- **Base (80–160 px):** Fome, Energia

<br>

**Otimização:**
- Imagem só redesenha quando o **estado muda**
- Texto redesenha quando valores variam **2+**

---

# Feedback Sonoro

### Melodias por transição

<br>

| Estado | Som |
| :--- | :--- |
| OVO | Dó–Mi |
| CHOCANDO | 1000 Hz repetido |
| NORMAL | Dó–Mi agudo |
| TRISTE | Mi–Dó–Lá–Fá |
| BRAVO | 300 Hz repetido |
| DORMINDO | Dó–Lá–Sol–Fá |
| MORTO | Lá–Fá–Dó–Sol |
| FELIZ | Dó–Mi–Sol–Dó |

---

# Concorrência entre Núcleos

### Problema

Três tasks alteram o estado do jogo → risco de **condição de corrida**.

<br>

### Solução

- `taskInput` e `taskSensores` só **sinalizam intenções** (flags `volatile`)
- **Só `taskJogo` altera o estado**
- Elimina a corrida sem mutex

---

# Resultados

### O que funciona

- ✅ Display com sprites por estado
- ✅ FSM com 8 estados
- ✅ Botões com debounce
- ✅ LDR → dormir/acordar
- ✅ Buzzer com melodias
- ✅ Atualização otimizada

---

# Dificuldades e Soluções

| Problema | Solução |
| :--- | :--- |
| Tela branca | Conectar RST ao GPIO 22 |
| Buzzer mudo | Corrigir transistor |
| LDR instável | Histerese + média |
|Display com glitch junto com buzzer|Problema de corrente|

# Próximos Passos

### Projeto 3

<br>

- Shield em **PCB** com KiCAD
- Integração dos periféricos
- Conectividade Wi-Fi para controle remoto
- Adicionar atividades além de alimentar e dormir
<br>

### Obrigada!

**Perguntas?**