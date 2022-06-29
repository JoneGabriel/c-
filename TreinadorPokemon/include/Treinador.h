#ifndef TREINADOR_H
#define TREINADOR_H
#include <string>
#include <vector>
#include "EvolutionBall .h"
#include "HealthBall .h"

class Treinador{
    private:
        std::string name;
        std::vector<EvolutionBall*> evolution_balls;
        std::vector<HealthBall*> health_balls;
    public:
        Treinador(std::string _name);
        ~Treinador();
        HealthBall* selecionarHealthBall(int _id);
        EvolutionBall* selecionarEvolBall(int _id);
        void adicionarPokebola(HealthBall* pokebola);
        void adicionarPokebola(EvolutionBall* pokebola);
        void listarPokemons();
};

#endif
