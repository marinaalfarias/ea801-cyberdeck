#pragma once

void buzzer_init();
void buzzer_play_tone(int freq, int duration_ms);
void buzzer_stop();
void buzzer_melodia(const int* notas, const int* duracoes, int tamanho);
void som_ovo();
void som_chocando();
void som_triste();
void som_bravo();   
void som_dormindo();
void som_morto();
void som_feliz();