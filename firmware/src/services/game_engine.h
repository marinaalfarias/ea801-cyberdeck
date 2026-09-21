#pragma once

enum EstadoCriatura { OVO, BEBE, ADULTO, DORMINDO, MORTO };

struct StatusCriatura {
    EstadoCriatura estado;
    int fome;         // 0..100
    int felicidade;   // 0..100
    int energia;      // 0..100
    uint32_t idade_s; // segundos
};

void game_engine_init();
void game_engine_tick();
StatusCriatura& game_engine_status();
void game_engine_alimentar();
void game_engine_brincar();
void game_engine_sacudir();