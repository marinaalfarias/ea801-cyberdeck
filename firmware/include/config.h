#pragma once

// ---------- Tempos do jogo (ms) ----------
#define TICK_JOGO_MS         1000
#define TICK_UI_MS           100
#define TICK_SENSORES_MS     50

// ---------- Regras do Tamagotchi ----------
#define FOME_MAX             100
#define FELICIDADE_MAX       100
#define ENERGIA_MAX          100
#define FOME_DECAY_POR_TICK  1
#define ENERGIA_DECAY_POR_TICK 1

// ---------- Wi-Fi ----------
#define WIFI_SSID            "SEU_SSID"
#define WIFI_PASSWORD        "SUA_SENHA"
#define NTP_SERVER           "pool.ntp.org"
#define GMT_OFFSET_SEC       -10800   // UTC-3 (Brasília)
#define DAYLIGHT_OFFSET_SEC  0