#include "EvolutionBall .h"

EvolutionBall::EvolutionBall(double _taxaPoder){
    taxaPoder = _taxaPoder;
}

bool EvolutionBall::evoluirPokemon(){

    if(habilidadeUsada || pokemon == nullptr){

       return false;
    }

    pokemon->evoluir(taxaPoder);
    habilidadeUsada = true;

    return true;
}
