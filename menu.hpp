#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#pragma once


using namespace std;

void exibirmenu()
{
    // funcao para criar um menu inicial
    cout << "==========================" << endl;
    cout << "      RPG DE TERMINAL     " << endl; 
    cout << "==========================" << endl;
    cout << "1. Novo Jogo" << endl;
    cout << "3. Sair" << endl;
    cout << "Escolha uma opção: ";
}

void escolherPersonagem()
{
    // funcao para escolher o personagem
    cout << "==========================" << endl;
    cout << "  ESCOLHA SEU PERSONAGEM:  " << endl;
    cout << "==========================" << endl;
}

void iniciarCombate(const std::string& nomeHeroi, const std::string& nomeInimigo) {
    cout << "\n=============================\n";
    cout << "   🗡️  COMBATE INICIADO! 🛡️\n";
    cout << "=============================\n";
    cout << nomeHeroi << " desafia " << nomeInimigo << " para um duelo mortal!\n";
    this_thread::sleep_for(std::chrono::milliseconds(1000));
    cout << "Prepare-se para a batalha...\n\n";
    this_thread::sleep_for(std::chrono::milliseconds(1000));
}




void sairJogo()
{
    this_thread::sleep_for(chrono::milliseconds(1000));
cout << "\nEncerrando o jogo...\n";
this_thread::sleep_for(chrono::milliseconds(1500));
cout << "\n=============================\n";
cout << "   Obrigado por jogar! 🙌\n";
cout << "   Até a próxima, aventureiro.\n";
cout << "=============================\n";

}
