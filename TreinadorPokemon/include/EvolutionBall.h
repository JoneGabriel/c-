#ifndef EVOLUTIONBALL_H
#define EVOLUTIONBALL_H
#include "Pokebola.h"

class EvolutionBall:Pokebola{
    private:
        double taxaPoder;
        bool habilidadeUsada;
    public:
        EvolutionBall(double _taxaPoder);
        bool evoluirPokemon() ;
};

#endif
