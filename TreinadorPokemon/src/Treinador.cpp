#include "Treinador.h"
#include <iostream>

Treinador::Treinador(std::string _name){
    name = _name;
};


Treinador::~Treinador(){
    health_balls.clear();
    evolution_balls.clear();
};

HealthBall* Treinador::selecionarHealthBall(int _id){

    for(auto hea_balls:health_balls){

        if(hea_balls->getId() == _id){

            return hea_balls;
        }
    }

    return nullptr;
}

EvolutionBall* Treinador::selecionarEvolBall(int _id){

    for(auto evo_balls:evolution_balls){

        if(evo_balls->getId() == _id){

            return evo_balls;
        }
    }

    return nullptr;
}

void Treinador::adicionarPokebola(HealthBall* pokebola){
    health_balls.push_back(pokebola);
}

void Treinador::adicionarPokebola(EvolutionBall* pokebola){
    evolution_balls.push_back(pokebola);
}

void Treinador::listarPokemons(){

    if(health_balls.size() > 0 && evolution_balls.size() > 0){
        std::cout << "Treinador: " << name << std::endl;
    }



    if(health_balls.size() > 0){
        for(auto hea_balls:health_balls){
            std:: cout << "HealthBall ID: " << hea_balls->getId() << std::endl;
            hea_balls->getPokemonCapturado();
        }
    }

    if(evolution_balls.size() > 0){

        for(auto evo_balls:evolution_balls){
            std:: cout << "EvolutionBall ID: " << evo_balls->getId() << std::endl;
            evo_balls->getPokemonCapturado();
        }
    }

}
