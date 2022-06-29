#include "EvolutionBall .h"
#include "HealthBall .h"
#include "Treinador.h"
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <string>
#include <cmath>

/**
 * @brief Adiciona N pokebolas para o treinador, onde metade ser�o
 * HealthBall e a outra metade EvolutionBall
 * @param t Treinador que ser� atualizado com novas pokebolas
 * @param numHealthBalls O n�mero de evolution balls adicionadas
 * @param numEvolBalls O n�mero de health balls adicionadas
 */
void adicionarPokebolas(Treinador& t, int numHealthBalls, int numEvolBalls) {
    for(int i = 0; i < numHealthBalls; i++) {
        HealthBall* m =  new HealthBall(i + 1);
        t.adicionarPokebola(m);
    }

    for(int i = 0; i < numEvolBalls; i++) {

        double taxaPoder = 1.0/(i + 1);


        EvolutionBall* e = new EvolutionBall(taxaPoder);

        t.adicionarPokebola(e);
    }
}

/**
 * @brief Recebe a entrada do usu�rio para criar uma nova inst�ncia de
 * pok�mon
 * @return Pokemon criado com as entradas do usu�rio
 */
Pokemon criarPokemon() {
    std::string pokName;
    std::string pokTipo;
    std::string pokEvol;
    double pokAtaque;
    double pokDefesa;
    double saude;

    std::cin >> pokName >> pokTipo >> pokAtaque >> pokDefesa >> pokEvol >> saude;
    return Pokemon(pokName, pokTipo, pokEvol, pokAtaque, pokDefesa, saude);
}

/**
 * @brief Tenta capturar um pokemon espec�fico
 * @param pokebola Pokebola que ser� usada
 * @param pokemon Pokemon que ser� capturado
 */
void capturarPokemon(Pokebola* pokebola, Pokemon& pokemon) {
    if (pokebola->capturar(pokemon))
        std::cout << "Pok�mon " << pokemon.getNome() << " capturado." << std::endl;
    else
        std::cout << "Pok�mon " << pokemon.getNome() << " N�O capturado." << std::endl;
}

/**
 * @brief Tenta capturar uma sequencia de pokemons criados
 * @param t Treinador que ser� atualizado com novos pokemons nas pokebolas
 * caso capturados
 */
void adicionarPokemons(Treinador& t) {
    bool continuar = true;
    int id;

    while (continuar) {
        char command;
        std::cin >> command;

        switch (command) {
            case 'e': { // Usa uma evolution ball para capturar
                std::cin >> id;
                Pokemon pokemon = criarPokemon();
                Pokebola* pok = t.selecionarEvolBall(id);
                capturarPokemon(pok, pokemon);
                break;
            }
            case 'h': { // Usa uma health ball para capturar
                std::cin >> id;
                Pokemon pokemon = criarPokemon();
                Pokebola* pok = t.selecionarHealthBall(id);
                capturarPokemon(pok, pokemon);
                break;
            }
            case 'q': { // Encerra o processo de captura
                continuar = false;
                break;
            }
        }
    }
}

/**
 * @brief Tenta evoluir um pok�mon de uma EvolutionBall
 * @param pokebola EvolutionBall
 */
void evoluirPokemon(EvolutionBall* pokebola) {
    std::cout << "EvolutionBall " << pokebola->getId() << std::endl;
    if (pokebola->evoluirPokemon()) {
        Pokemon* pokemon = pokebola->liberarPokemon();
        pokemon->info();
        pokebola->guardarPokemon();
    }
    else {
        std::cout << "Pok�mon N�O evolu�do." << std::endl;
    }
}

/**
 * @brief Tenta recupear um pol�mon de uma HealthBall
 * @param pokebola HealthBall
 */
void recuperarPokemon(HealthBall* pokebola) {
    std::cout << "HealthBall " << pokebola->getId() << std::endl;
    if (pokebola->recuperarPokemon()) {
        Pokemon* pokemon = pokebola->liberarPokemon();
        pokemon->info();
        pokebola->guardarPokemon();
    }
    else
        std::cout << "Pok�mon N�O recuperado." << std::endl;
}

/**
 * @brief Utiliza as a��es das pokebolas
 * @param t Treinador que possui as pokebolas
 */
void acoes(Treinador& t) {
    bool continuar = true;
    int id;

    while (continuar) {
        char command;
        std::cin >> command;

        switch (command) {
            case 'e': { // Evolui um pok�mon de uma evolution ball
                std::cin >> id;
                EvolutionBall* pokebola = t.selecionarEvolBall(id);
                evoluirPokemon(pokebola);
                break;
            }

            case 'h': { // Recupera a sa�de de um pok�mon de uma health ball
                std::cin >> id;
                HealthBall* pokebola = t.selecionarHealthBall(id);
                recuperarPokemon(pokebola);
                break;
            }

            case 'i': { // Pausa o programa por M milisegundos (M � definido pelo "interval")
                int intervalMilisseg;
                std::cin >> intervalMilisseg;
                std::cout << "Intervalo " << intervalMilisseg << " milisegundos" << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(intervalMilisseg));
                break;
            }

            case 'q': { // Encerra o processo de a��es com as pok�bolas
                continuar = false;
                break;
            }
        }
    }
}
/**<  */
int main() {

    // Seta a seed para gerar sempre os mesmos n�meros "aleat�rios"
    srand(5201);

    std::string nome;
    int numEvolBalls;
    int numHealthBalls;

    std::cin >> nome >> numHealthBalls >> numEvolBalls;

    Treinador t(nome);

    adicionarPokebolas(t, numHealthBalls, numEvolBalls);
    t.listarPokemons();
    std::cout << "-------------" << std::endl;
    adicionarPokemons(t);
    std::cout << "-------------" << std::endl;
    t.listarPokemons();
    std::cout << "-------------" << std::endl;
    acoes(t);

    return 0;
}
