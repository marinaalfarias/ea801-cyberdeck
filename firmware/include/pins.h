#pragma once

// Display TFT ST7735S (SPI)
#define TFT_CS    15   // Chip Select
#define TFT_DC     2   // Data/Command
#define TFT_RST    -1  // Se conectar ao EN do ESP32 pode definir como -1, senão especifique um GPIO
#define TFT_BL     4   // Backlight (se o módulo tiver esse pino)

// SPI padrão do ESP32 (não precisa redefinir, a biblioteca usa por padrão)
// MOSI = 23, SCLK = 18, MISO = 19

// ---------- Botões ----------
#define PIN_BTN_UP       12
#define PIN_BTN_DOWN     13
#define PIN_BTN_SELECT   14

// ---------- Analógicos ----------
#define PIN_LDR          34
#define PIN_BATTERY      35

// ---------- Buzzer ----------
#define PIN_BUZZER       25

// ---------- Endereços I2C ----------
#define OLED_ADDR        0x3C
#define MPU6050_ADDR     0x68

// ---------- Dimensões do display ----------
#define OLED_WIDTH       128
#define OLED_HEIGHT      64