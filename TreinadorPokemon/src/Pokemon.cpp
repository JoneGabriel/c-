#include "Pokemon.h"
#include <iostream>

Pokemon:: Pokemon(){
    nome = "";
    tipo = "";
    forcaAtaque = 0;
    forcaDefesa = 0;
    proxEvolucao = "";
    saude = 0;
}

Pokemon::Pokemon(const Pokemon& pok_):nome(pok_.nome), tipo(pok_.tipo), forcaAtaque(pok_.forcaAtaque), proxEvolucao(pok_.proxEvolucao), saude(pok_.saude){}

Pokemon::Pokemon(std::string _nome, std::string _tipo, std::string _pEvol, double _fA, double _fD, double _saude){
    nome = _nome;
    tipo = _tipo;
    forcaAtaque = _fA;
    forcaDefesa = _fD;
    proxEvolucao = _pEvol;
    saude = _saude;
}

void Pokemon::maxSaude(){
    saude = 100;
}

std::string Pokemon::getNome(){

    return nome;
}

void Pokemon::info(){

    std::cout << "Pokemon: " << nome << ", " << tipo << ", " << forcaAtaque << ", " << forcaDefesa << ", " << saude << std::endl;
}
