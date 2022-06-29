#ifndef POKEMONCAPTURADO_H
#define POKEMONCAPTURADO_H
#include "Pokemon.h"

class PokemonCapturado:Pokemon{
    private:
        bool evoluido;
        bool dormindo;
    public:
        PokemonCapturado(Pokemon& _pok);
        void evoluir(double taxaPoder);
};

#endif
