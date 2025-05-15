#include <iostream>
#include <vector> //vitooooooor
#include <stdlib.h>
#include <thread>
#include <chrono> // essa e o thread serve para pausar o tempo de 1 segundo como na funcao iniciarcombate

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




int main()
{
    // caso queira acessar fora do switch case  
    int op;
    personagem jogador;
    inimigo atual;

    //chama a funcao do menu
    exibirmenu();

    cin >> op;


    switch (op)
    {
    case 1:
        
        
        int escolhaPersonagem;
        int escolhaInimigo;

        system("clear");


        cout << "==========================" << endl;
        cout << "  ESCOLHA SEU PERSONAGEM:  " << endl;
        cout << "==========================" << endl;

        vector<personagem> personagens =  //vetor para armazenar os personagens, podendo colocar outros depois
        {
        {"Guerreiro", 300, 90, "Forte e resistente"},
        {"Mago", 200, 110, "Frágil, mas poderoso"},
        {"Ladino", 120, 100, "Ágil e sorrateiro"}
        };

        for(int i = 0; i < personagens.size(); i++) // for para mostrar os personagens disponiveis 
        {
            cout << i + 1 << "º Classe: " <<  personagens[i].nome << endl << endl;
            cout << " Vida: " << personagens[i].vida << endl;
            cout << " Dano: " << personagens[i].ataque << endl;
            cout << " descricão: " << personagens[i].descricao << endl;
        }

        cout << "Escreva a classe que gostaria de jogar: " << endl;
        cin >> escolhaPersonagem;

        // verificacao para ver se esta dentro das escolhas, ele pega o tamanho do array para verificar ajudando no futuro se bota mais persona
        if(escolhaPersonagem >= 1 &&  escolhaPersonagem <= personagens.size())
        {
            jogador = personagens[escolhaPersonagem - 1]; // -1 pois os indices começam em zero 
        }
        else
        {
            cout << "Escolha Invalida! " << endl;
        }


            system("clear");

          vector<inimigo>  inimigos =  //vetor para armazenar os inimigos, podendo colocar outros depois
        {
        {"Goblin", 50, 20, "Fragil e chato"},
        {"Orc", 300, 80 , "Tank, mas nao da dano"},
        {"Dragão", 400, 120, "tanka e da dano(meta atual)"}
        };

        for(int i = 0; i < inimigos.size(); i++) // for para mostrar os inimigos disponiveis 
        {
            cout << i + 1 << "º Classe: " << inimigos[i].nome << endl;
            cout << "Vida: ??" << endl;
            cout << "Dano: ??" << endl;
        }


        cout << "Qual inimigo gostaria de lutar primeiro: " << endl;
        cin >> escolhaInimigo;

        //para verificar intervalo do inimigo  
        if(escolhaInimigo >= 1 &&  escolhaInimigo <= inimigos.size())
        {
            atual = inimigos[escolhaInimigo - 1]; // -1 pois os indices começam em zero 
        }
        else
        {
            cout << "Escolha Invalida! " << endl;
        }
        this_thread::sleep_for(chrono::milliseconds(1000));
        system("clear");


        //escolher inimigo e acabar com o misterio
        cout << "Você vai enfrentar: " << atual.nome << endl;
        cout << "Vida: " << atual.vida << endl;
        cout << "Dano: " << atual.ataque << endl;
        cout << "Lore: " << atual.lore << endl;

        //falta criar dano/defesa do inimigo/personagem vou usar rand
        //sistema de batalha, while etc em turno

        this_thread::sleep_for(chrono::milliseconds(8000));

        system("clear");

        iniciarCombate(jogador.nome, atual.nome);

        // loop para batalha absurda suprema omg jesus cristh
        // 0 + 1 = 0 / 1 + 1 = 1/ 0 + 0 = 1
        while(atual.vida > 0 && jogador.vida > 0 ){

            int atkDefHeroi;
            int atkDefEnemy = 1 + (rand() % 2);    
            int danoHeroi = 0;
            int defesaHeroi = 0;
            int danoInimigo = 0;
            int defesaInimigo = 0;
          
            
            cout << "Digite 1 para Atacar ou 2 Para defender:" << endl;
            cin >> atkDefHeroi;

            if(atkDefHeroi == 1)
            {
                danoHeroi = 1 +rand() % jogador.ataque;
            }
            else if(atkDefHeroi == 2)
            {
                defesaHeroi = rand() % 20; //baseado na media do dano do heroi/ falta escalar
                 
            }

            // aqui supostamente é aleatorio 
            if(atkDefEnemy == 1)
            {
                danoInimigo = 1 + rand() % atual.ataque; // dano do inimigo baseado num sistema aleatorio que vai de 0 até o dano max
            }
            else if(atkDefEnemy == 2)
            {
                defesaInimigo = rand() % 20; //baseado na media do dano do inimigo/ falta escalar
            }

            // para nao dar dano negativo e quebrar  
            int danoFinalHeroi = danoHeroi - defesaInimigo;
            if (danoFinalHeroi < 0) danoFinalHeroi = 0;

            //mema fita
            int danoFinalInimigo = danoInimigo - defesaHeroi;
            if (danoFinalInimigo < 0) danoFinalInimigo = 0;


            //pega a vida atual e faz menos o dano final do heroi e acumula
            atual.vida -= danoFinalHeroi;
            //mema coisa ao contrario
            jogador.vida -= danoFinalInimigo;

            //formatacão bonitinha
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
