
# Firmware — CyberDeck-Tama

## Estrutura

- `include/` — headers globais (pins, config, version)
- `src/drivers/` — camada de baixo nível (display, IMU, botões, LDR, buzzer)
- `src/services/` — lógica de negócio (game_engine, wifi, power)
- `src/ui/` — telas e sprites
- `src/tasks/` — contém as tarefas que rodam em paralelo nos dois núcleos da ESP32, cada arquivo tem um loop infinito e deve terminar sempre em `vTaskDelay` ou `vTaskUntil`

## Arquivos
### Services
- `src/services/game_engine.cpp` e `src/services/game_engine.h`
    - a máquina de estados principal, define status de fome, energia, felicidade, estado atual
    - tem as funções
        - `game_engine_init()`
        - `game_engine_tick()`: faz o tempo decair
        - `alimentar()`, `brincar()`, etc: funções de interação
    - a `task_jogo.cpp` chama o `tick()` e a `task_input.cpp` chama as funções de interação
- `src/services/power_manager.cpp` e `src/services/power_manager.cpp`
    - gerencia a energia 
    - deve conter funções para controlar bateria, calcular porcentagem de carga e decidir quando entrar em modo economia de energia (projeto 3)
### Tasks
- `src/tasks/task_jogo.cpp`
    - o "relógio" do jogo
    - tem um loop que chama `game_engine_tick()` a cada intervalo de tempo determinado (definido no config.h como `TICK_JOGO_MS`)
- `src/tasks/task_input.cpp`
    - lê as entradas do usuário
    - tem um loop que lê os estados dos botões a cada intervalo de tempo determinado, quando detecta um clique, chama a função correspondente no `game_engine`
- `src/tasks/task_sensores.cpp`
    - lê os sensores físicos
    - tem um loop que lê o acelerômetro e o LDR; se detectar uma sacudida, chama `game_engine_sacudir()` e se detectar que está escuro, muda o estado para `DORMINDO`
- `src/tasks/task_ui.cpp`
    - desenha na tela
    - um loop lê o estado atual em `game_engine` e chama as funções de desenho na pasta `ui/`
- `src/tasks/task_net.cpp`
    - cuida da rede
    - implementada no projeto 3
### UI
- `src/ui/screen_game.h` e `src/ui/screen_game.cpp`
    - desenha a tela principal do jogo
    - contem a função `screen_game_draw(StatusCriatura status)`
    - desenha o estado do bichinho, barras de progresso para fome e energia
- `src/ui/screen_menu.h` e `src/ui/screen_menu.cpp`
    - desenha o menu de navegação
- `src/ui/sprites.h`
    - arquivo de imagens
    - contem matrizes de bytes ou valores hexadecimais que representam os desenhos do bichinho e ícones de fome/felicidade