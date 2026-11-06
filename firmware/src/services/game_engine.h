#pragma once

#include <cstdint>

enum EstadoCriatura { OVO, CHOCANDO, NORMAL, TRISTE, DORMINDO, FELIZ, BRAVO, MORTO };

extern volatile bool tela_precisa_atualizar;

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
void game_engine_recarregar();
void game_engine_set_luz(bool escuro);