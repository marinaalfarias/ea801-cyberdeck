# Mapa de Pinos — CyberDeck-Tama

## Componentes e Conexões

| Componente | Pino do ESP32 | Interface | Observações |
| :--- | :--- | :--- | :--- |
| **Display TFT ST7735S (1,8")** | | | |
| — VCC | 3.3V | Alimentação | Não usar 5V |
| — GND | GND | Alimentação | |
| — CS | GPIO 15 | SPI | Chip Select |
| — DC (A0) | GPIO 2 | SPI | Data/Command |
| — RESET (RES) | GPIO 22 | SPI | Reset do controlador |
| — SDA (MOSI) | GPIO 23 | SPI | Dados |
| — SCL (SCLK) | GPIO 18 | SPI | Clock |
| — BL (LED) | 3.3V | Alimentação | Backlight sempre ligado |
| **Botão UP** | GPIO 12 | GPIO | `INPUT_PULLUP` — alimentar/recarregar |
| **Botão DOWN** | GPIO 13 | GPIO | `INPUT_PULLUP` — brincar |
| **Botão SELECT** | GPIO 14 | GPIO | `INPUT_PULLUP` — reservado para menu |
| **LDR** | GPIO 34 | ADC | Ponto médio do divisor de tensão |
| **Buzzer passivo** | GPIO 25 | PWM | Via transistor NPN (base com resistor 1kΩ) |
