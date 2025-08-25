#include <iostream>
#include <vector> //vitooooooor
#include <stdlib.h>
#include <thread>
#include <chrono> // essa e o thread serve para pausar o tempo de 1 segundo como na funcao iniciarcombate
#include "include/menu.hpp"
#include "include/types.hpp"
#include "include/characters.hpp"

using namespace std;

int main()   
{
    // caso queira acessar fora do switch case
    int op;
    personagem jogador;
    inimigo atual;

    // chama a funcao do menu
    exibirmenu();

    cin >> op;

    switch (op)
    {
    case 1:

        int escolhaPersonagem;
        int escolhaInimigo;

        system("clear");

        escolherPersonagem();

        vector<personagem> personagens = inicializarPersonagem();

        for (size_t i = 0; i < personagens.size(); i++) // for para mostrar os personagens disponiveis
        {
            cout << i + 1 << "º Classe: " << personagens[i].nome << endl;
            cout << " Vida: " << personagens[i].vida << endl;
            cout << " Dano: " << personagens[i].ataque << endl;
            cout << " descricão: " << personagens[i].descricao << endl;
        }

        while (true)
        {

            cout << "Escreva a classe que gostaria de jogar: " << endl;
            cin >> escolhaPersonagem;

            // verificacao para ver se esta dentro das escolhas, ele pega o tamanho do array para verificar ajudando no futuro se bota mais persona
            if (escolhaPersonagem >= 1 && static_cast<size_t>(escolhaPersonagem) <= personagens.size())
        {
                jogador = personagens[escolhaPersonagem - 1]; // -1 pois os indices começam em zero
                break;
            }
            else
            {
                cout << "Escolha Invalida! " << endl;
                continue;
            }
        }

        system("clear");

         vector<inimigo> inimigos = inicializarInimigos(); // chama funcao 

        for (size_t i = 0; i < inimigos.size(); i++) // for para mostrar os inimigos disponiveis
        {
            cout << i + 1 << "º Classe: " << inimigos[i].nome << endl;
            cout << "Vida: ??" << endl;
            cout << "Dano: ??" << endl;
        }

        while (true)
        {

            cout << "Qual inimigo gostaria de lutar primeiro: " << endl;
            cin >> escolhaInimigo;

            // para verificar intervalo do inimigo
           if (escolhaInimigo >= 1 && static_cast<size_t>(escolhaInimigo) <= inimigos.size())
            {
                atual = inimigos[escolhaInimigo - 1]; // -1 pois os indices começam em zero
                break;
            }

            else
            {
                cout << "Escolha Invalida! " << endl;
                continue;
            }
        }

        this_thread::sleep_for(chrono::milliseconds(1000));
        system("clear");

        // escolher inimigo e acabar com o misterio
        cout << "Você vai enfrentar: " << atual.nome << endl;
        cout << "Vida: " << atual.vida << endl;
        cout << "Dano: " << atual.ataque << endl;
        cout << "Lore: " << atual.lore << endl;

        // falta criar dano/defesa do inimigo/personagem vou usar rand
        // sistema de batalha, while etc em turno

        this_thread::sleep_for(chrono::milliseconds(8000));

        system("clear");

        iniciarCombate(jogador.nome, atual.nome);

        // loop para batalha absurda suprema omg jesus cristh
        // 0 + 1 = 0 / 1 + 1 = 1/ 0 + 0 = 1
        while (atual.vida > 0 && jogador.vida > 0)
        {

            int atkDefHeroi;
            int atkDefEnemy = 1 + (rand() % 2);
            int danoHeroi = 0;
            int defesaHeroi = 0;
            int danoInimigo = 0;
            int defesaInimigo = 0;

            cout << "Digite 1 para Atacar ou 2 Para defender:" << endl;
            cin >> atkDefHeroi;

            if (atkDefHeroi == 1)
            {
                danoHeroi = 1 + rand() % jogador.ataque;
            }
            else if (atkDefHeroi == 2)
            {
                defesaHeroi = rand() % 20; // baseado na media do dano do heroi/ falta escalar
            }

            // aqui supostamente é aleatorio
            if (atkDefEnemy == 1)
            {
                danoInimigo = 1 + rand() % atual.ataque; // dano do inimigo baseado num sistema aleatorio que vai de 0 até o dano max
            }
            else if (atkDefEnemy == 2)
            {
                defesaInimigo = rand() % 20; // baseado na media do dano do inimigo/ falta escalar
            }

            // para nao dar dano negativo e quebrar
            int danoFinalHeroi = danoHeroi - defesaInimigo;
            if (danoFinalHeroi < 0)
                danoFinalHeroi = 0;

            // mema fita
            int danoFinalInimigo = danoInimigo - defesaHeroi;
            if (danoFinalInimigo < 0)
                danoFinalInimigo = 0;

            // pega a vida atual e faz menos o dano final do heroi e acumula
            atual.vida -= danoFinalHeroi;
            // mema coisa ao contrario
            jogador.vida -= danoFinalInimigo;

            // formatacão bonitinha
            cout << "Dano final no inimigo: " << danoFinalHeroi << "\n";
            cout << "Dano final em você: " << danoFinalInimigo << "\n";

            cout << "Vida restante - Você: " << jogador.vida << " | " << atual.nome << ": " << atual.vida << "\n";
            cout << "--------------------------------------\n";

            // n tenho a menor ideia
            this_thread::sleep_for(chrono::milliseconds(800));
        }

        break;
    }

    sairJogo();

    return 0;
}
