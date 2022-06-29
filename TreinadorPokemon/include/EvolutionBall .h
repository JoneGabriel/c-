#ifndef EVOLUTIONBALL _H
#define EVOLUTIONBALL _H
#include "Pokebola.h"

class EvolutionBall:public Pokebola{
    private:
        double taxaPoder;
         bool habilidadeUsada ;
    public:
        EvolutionBall(double _taxaPoder);
        bool evoluirPokemon();
};

#endif
