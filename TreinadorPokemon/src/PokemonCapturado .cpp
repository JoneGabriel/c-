#include "PokemonCapturado .h"

void PokemonCapturado::alterarStatus(){
    dormindo=true;
}
PokemonCapturado::PokemonCapturado(Pokemon& pok_){
    evoluido = false;
    dormindo = true;
    Pokemon novoPokemon (pok_);
}

void PokemonCapturado::evoluir(double taxaPoder){
    nome = proxEvolucao;
    proxEvolucao = "";
    forcaAtaque = (forcaAtaque*taxaPoder) + forcaAtaque;
    forcaDefesa = (forcaDefesa*taxaPoder) + forcaAtaque;
}
