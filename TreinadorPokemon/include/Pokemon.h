#ifndef POKEMON_H
#define POKEMON_H
#include <string>

class Pokemon{
    protected:
        std::string nome;
        std::string tipo;
        double forcaAtaque;
        double forcaDefesa;
        std::string proxEvolucao;
        double saude;
    public:
        Pokemon();
        Pokemon(std::string _nome, std::string _tipo, std::string _pEvol, double _fA, double _fD, double _saude);
        Pokemon(const Pokemon& pok_);
        std::string getNome();
        void maxSaude();
        void info();
};

#endif
