# CyberDeck-Tama — Projeto 2

Protótipo de um cyberdeck baseado em ESP32 com funcionalidades de Tamagotchi:
criatura virtual exibida em display OLED, interação por botões e sensores
(acelerômetro MPU6050 e LDR), com conectividade Wi-Fi.

## Estrutura do Repositório

- `firmware/` — código embarcado (PlatformIO + ESP32)
- `docs/` — proposta, diagramas e lista de materiais
- `simulations/` — simulação no Wokwi
- `images/` — fotos do protótipo

## Como compilar e gravar

1. Instale o VS Code + extensão PlatformIO.
2. Abra a pasta `firmware/`.
3. Conecte o ESP32 via USB.
4. Clique em **Upload**

## Periféricos Utilizados

- ESP32
- Display OLED SSD1306 0.96" (I2C)
- MPU6050 (I2C)
- LDR (ADC)
- 3 botões (GPIO)
- Buzzer piezoelétrico (PWM)
