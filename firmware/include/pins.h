#pragma once

// ---------- I2C (compartilhado: OLED + MPU6050) ----------
#define PIN_I2C_SDA      21
#define PIN_I2C_SCL      22

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
#define OLED_ADDR        0x3C
#define MPU6050_ADDR     0x68

// ---------- Dimensões do display ----------
#define OLED_WIDTH       128
#define OLED_HEIGHT      64