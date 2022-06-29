#ifndef POKEBOLA_H
#define POKEBOLA_H
#include "PokemonCapturado .h"
#include "Pokemon.h"

class Pokebola{
    private:
        static int cont;
    protected:
        int id;
        PokemonCapturado* pokemon;
    public:
        Pokebola();
        ~Pokebola();
        int getId();
        void getPokemonCapturado();
        void guardarPokemon();
        Pokemon* liberarPokemon();
        bool capturar(Pokemon& _pokemon);
};

#endif
