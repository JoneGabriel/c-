#ifndef POKEMONCAPTURADO _H
#define POKEMONCAPTURADO _H
#include "Pokemon.h"

class PokemonCapturado: public Pokemon{
    private:
         bool evoluido;
         bool dormindo;
    public:
        PokemonCapturado(Pokemon& _pok);
        void evoluir(double taxaPoder);
        void alterarStatus();
};

#endif
