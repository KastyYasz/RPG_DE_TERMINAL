#include <string>
#include <iostream>
#pragma once


using namespace std;

// tipo uma estrutura para personagem
struct personagem
{
    string nome;
    int vida;
    int ataque;
    string descricao;

};

// tipo uma estrutura para o inimigo
struct inimigo
{
    string nome;
    int vida;
    int ataque;
    string lore;

};
