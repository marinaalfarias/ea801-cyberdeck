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

    if (st.estado != MORTO) {
        st.fome = max(0, st.fome - FOME_DECAY_POR_TICK);
        st.energia = max(0, st.energia - ENERGIA_DECAY_POR_TICK);
    }
    if (st.fome == 0 || st.energia == 0) st.estado = MORTO;
    else if (st.estado == OVO && st.idade_s > 5) st.estado = CHOCANDO;
    else if (st.estado == CHOCANDO && st.idade_s > 10) st.estado = NORMAL;
    else if (st.estado == NORMAL && st.fome < 30) st.estado = TRISTE;
    else if (st.estado == TRISTE && st.fome > 70) st.estado = FELIZ;
    else if (st.estado == FELIZ && st.fome < 15) st.estado = BRAVO;
    else if (st.estado == BRAVO && st.fome < 60) st.estado = NORMAL;
}

StatusCriatura& game_engine_status() { return st; }

void game_engine_alimentar() { 
    st.fome = min(FOME_MAX, st.fome + 20); 
}
void game_engine_brincar() { 
    st.felicidade = min(FELICIDADE_MAX, st.felicidade + 15); 
}
void game_engine_sacudir(){
    st.felicidade = max(0, st.felicidade - 10); 
}
volatile bool tela_precisa_atualizar = false;
void game_engine_recarregar() {
    if (st.estado != MORTO) {
        st.energia = min(ENERGIA_MAX, st.energia + 20);
        tela_precisa_atualizar = true;
    }
}

void game_engine_set_luz(bool escuro) {
    if (st.estado == MORTO) return; // morto não dorme

    if (escuro && st.estado != DORMINDO) {
        // Guarda o estado anterior para restaurar quando acordar
        // (opcional: você pode guardar em uma variável estática)
        st.estado = DORMINDO;
    } 
    else if (!escuro && st.estado == DORMINDO) {
        // Acorda e volta a ser bebê ou adulto (dependendo da idade)
        if (st.idade_s > 300) st.estado = NORMAL;
        else st.estado = OVO;
    }
}