#include "Pokebola.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

int Pokebola::cont{0};

Pokebola::Pokebola(){
    pokemon = nullptr;
    id = cont;
    cont++;
}
Pokebola::~Pokebola(){
    delete pokemon;
}


int Pokebola::getId(){

    return id;
 }

void Pokebola::getPokemonCapturado(){

    if(pokemon == nullptr){
        std::cout << "A pokebola não possui um pokemon" << std::endl;
    }else{
        pokemon->info();
    }

}

void Pokebola::guardarPokemon(){
    pokemon->alterarStatus();
}

Pokemon* Pokebola::liberarPokemon(){

    if(pokemon == nullptr){

        return nullptr;
    }

    return pokemon;
}

bool Pokebola::capturar(Pokemon& _pokemon){
    float valorAleatorio = (double)rand() / ((double)RAND_MAX + 1);


    if(valorAleatorio > 0.5){
        PokemonCapturado p{_pokemon};
        pokemon = &p;

        return true;
    }

    return false;
}

