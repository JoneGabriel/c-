#include "HealthBall .h"

HealthBall::HealthBall(double _intervalo){
    intervalo = _intervalo;
    ultimoUso = 0;
}

bool HealthBall::recuperarPokemon(){

    std::time_t dataAtual;
    time(&dataAtual);

    if(pokemon != nullptr && (difftime(dataAtual,ultimoUso)) > intervalo){
        pokemon->maxSaude();
        ultimoUso = dataAtual;

        return true;
    }

    return false;
}
