#ifndef HEALTHBALL_H
#define HEALTHBALL_H
#include "Pokebola.h"
#include <ctime>
class HealthBall:Pokebola{
    private:
        std::time_t ultimoUso;
        double intervalo;
    public:
        HealthBall(double _intervalo);
        bool recuperarPokemon();
};

#endif
