
# Firmware — CyberDeck-Tama

## Estrutura

- `include/` — headers globais (pins, config, version)
- `src/drivers/` — camada de baixo nível (display, IMU, botões, LDR, buzzer)
- `src/services/` — lógica de negócio (game_engine, wifi, power)
- `src/ui/` — telas e sprites
- `src/tasks/` — tasks do FreeRTOS
