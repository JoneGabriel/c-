#ifndef HEALTHBALL _H
#define HEALTHBALL _H
#include "Pokebola.h"
#include <ctime>
class HealthBall:public Pokebola{
    private:
        std::time_t ultimoUso;
        double intervalo;
    public:
        HealthBall(double _intervalo);
        bool recuperarPokemon();
};

#endif
