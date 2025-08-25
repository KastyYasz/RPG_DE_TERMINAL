#include <iostream>
#include <string>
#include <vector>
#include "types.hpp"
#pragma once


using namespace std;

vector<inimigo> inicializarInimigos()
{
    vector<inimigo> inimigos = {
        {"Goblin", 50, 20, "Frágil e chato"},
        {"Orc", 300, 80, "Tank, mas não dá dano"},
        {"Dragão", 400, 120, "Tank e dá dano (meta atual)"}};

    return inimigos;
}

vector<personagem> inicializarPersonagem()
{
    vector<personagem> personagens = {

        {"Guerreiro", 300, 90, "Forte e resistente"},
        {"Mago", 200, 110, "Frágil, mas poderoso"},
        {"Ladino", 120, 100, "Ágil e sorrateiro"}};

    return personagens;
}
