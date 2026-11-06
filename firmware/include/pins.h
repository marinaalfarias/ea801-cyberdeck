#pragma once

// ---------- I2C (MPU6050) ----------
#define PIN_SDA      23
#define PIN_SCL      18

// ---------- Botões ----------
#define PIN_BTN_UP       32
#define PIN_BTN_DOWN     33
#define PIN_BTN_SELECT   27

// ---------- Analógicos ----------
#define PIN_LDR          34
#define PIN_BATTERY      35

// ---------- Buzzer ----------
#define PIN_BUZZER       25

// ---------- Endereços I2C ----------
#define MPU6050_ADDR     0x68


// SPI padrão do ESP32 (não precisa redefinir, a biblioteca usa por padrão)
// MOSI = 23, SCLK = 18, MISO = 19