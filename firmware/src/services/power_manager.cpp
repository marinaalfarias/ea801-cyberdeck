#include "game_engine.h"
#include "config.h"
#include <Arduino.h>

static StatusCriatura st;

void game_engine_init() {
    st.estado = OVO;
    st.fome = FOME_MAX;
    st.felicidade = FELICIDADE_MAX;
    st.energia = ENERGIA_MAX;
    st.idade_s = 0;
}

void game_engine_tick() {
    st.idade_s++;
    st.fome = max(0, st.fome - FOME_DECAY_POR_TICK);
    st.energia = max(0, st.energia - ENERGIA_DECAY_POR_TICK);

    if (st.fome == 0 || st.energia == 0) st.estado = MORTO;
    else if (st.estado == OVO && st.idade_s > 30) st.estado = BEBE;
    else if (st.estado == BEBE && st.idade_s > 300) st.estado = ADULTO;
}

StatusCriatura& game_engine_status() { return st; }
void game_engine_alimentar() { st.fome = min(FOME_MAX, st.fome + 20); }
void game_engine_brincar()   { st.felicidade = min(FELICIDADE_MAX, st.felicidade + 15); }
void game_engine_sacudir()   { st.felicidade = max(0, st.felicidade - 10); }