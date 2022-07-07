#include <iostream>
#include <windows.h>
#include <time.h>
#include <conio.h> ///para o getch()
///https://stackoverflow.com/questions/34474627/linux-equivalent-for-conio-h-getch

using namespace std;

/*Autores:João Pedro Barreto Arriaga Fernandes, Jamao Khayf De Mello Bernal e
João Victor Rodrigues Santos*/

/*FLAPPY-BIRD*/


int main()
{
    ///ALERTA: NÃO MODIFICAR O TRECHO DE CÓDIGO, A SEGUIR.
    //INICIO: COMANDOS PARA QUE O CURSOR NÃO FIQUE PISCANDO NA TELA
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
    //FIM: COMANDOS PARA QUE O CURSOR NÃO FIQUE PISCANDO NA TELA
    //INÍCIO: COMANDOS PARA REPOSICIONAR O CURSOR NO INÍCIO DA TELA
    COORD coord;
    //FIM: COMANDOS PARA REPOSICIONAR O CURSOR NO INÍCIO DA TELA
    ///ALERTA: NÃO MODIFICAR O TRECHO DE CÓDIGO, ACIMA.

    srand(time(NULL));
    int bird_x=5, bird_y=10, bird_y_box=0;
    int obstaculo1_x=110, obstaculo1_y, obstaculo1_x_box, obstaculo2_x=90, obstaculo2_y, obstaculo2_x_box;
    int tecla, colisao, pontos=0;
    int R1=5,R2=7, R3=5,R4=7, S=200;//variaveis usadas para gerar numeros aleatorios e o valor de sleep
    const char *cls, *pause;

    ///DESENHO DO CENÁRIO
    cout<<"-----------------------------------------------------------------------------------------------------";
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout<<"-----------------------------------------------------------------------------------------------------";


    while (true) { //esse laço faz o jogo rodar para sempre

        ///POSICIONA O PÁSSARO

        coord.X = bird_x;    coord.Y = bird_y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout<<char(190);//gera o pássaro na tela

        coord.X = bird_x;    coord.Y = bird_y_box;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout<< " "; //apaga a posição anterior do pássaro


        ///POSICIONA O OBSTÁCULO

        obstaculo1_y=1;

        while(obstaculo1_y<20){
            coord.X = obstaculo1_x;    coord.Y = obstaculo1_y;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            if(obstaculo1_y<R1 || obstaculo1_y>R2){
                cout<<char(219);
            } else {
                cout<<" ";
            }

            coord.X = obstaculo1_x_box;    coord.Y = obstaculo1_y;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            cout<<" ";//apaga a posição anterior do obstaculo

            if(obstaculo1_x==3){

            obstaculo1_x=110;//reposiciona o obstaculo, para aparecer de novo
            coord.X = obstaculo1_x;    coord.Y = obstaculo1_y;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            cout<<" ";//apaga o obstaculo

            }

            obstaculo1_y++;
        }

        obstaculo2_y=1;

        while(obstaculo2_y<20){
            coord.X = obstaculo2_x;    coord.Y = obstaculo2_y;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            if(obstaculo2_y<R3 || obstaculo2_y>R4){
                cout<<char(219);
            } else {
                cout<<" ";
            }

            coord.X = obstaculo2_x_box;    coord.Y = obstaculo2_y;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            cout<<" ";

            if(obstaculo2_x==3){

            obstaculo2_x=90;
            coord.X = obstaculo2_x;    coord.Y = obstaculo2_y;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            cout<<" ";
            }

            obstaculo2_y++;
        }

        ///VERIFICA COLISÃO

         if(bird_y==0||bird_y==21){//Verifica se o pássaro encostou no chão
                system("cls");
                cout<<"Voce fez "<<pontos<<" pontos!!";
                system("pause");

            }else if((bird_x==obstaculo1_x&&bird_y<R1)||(bird_x==obstaculo1_x&&bird_y>R2)){//Verifica se o passaro tocou a parede
                         system("cls");
                         cout<<"Voce fez "<<pontos<<" pontos!!";
                         system("pause");

            }else if((bird_x==obstaculo2_x&&bird_y<R3)||(bird_x==obstaculo2_x&&bird_y>R4)){
                         system("cls");
                         cout<<"Voce fez "<<pontos<<" pontos!!";
                         system("pause");
            }


        ///GUARDA A POSIÇÃO ANTERIOR
        bird_y_box = bird_y;

        obstaculo1_x_box = obstaculo1_x;

        obstaculo2_x_box = obstaculo2_x;

        ///VERIFICA COMANDO DO JOGADOR
        if (kbhit()) { ///verifica se uma tecla foi pressionada
            tecla=getch(); //verifica comando do jogador
        }

        if ( tecla=='w' ){
            bird_y--;
            tecla='0';
        } else {
            bird_y++;
        }

        ///PÁSSARO CAI 1 POSIÇÃO SE NÃO FOI PRESSIONADO PARA SUBIR

        ///OBSTÁCULO AVANÇA UMA POSIÇÃO PARA ESQUERDA
        if(obstaculo1_x!=1){
            obstaculo1_x--;
        }
        if(obstaculo2_x!=1){
            obstaculo2_x--;
        }

        ///PONTUAÇÃO

        cout<<"\n\n pontos: " <<pontos;
        if(bird_x>obstaculo1_x){//se passar do obstaculo recebe um ponto
            pontos+1;
        }else if(bird_x>obstaculo2_x){
                pontos+1;
        }

        ///GERAÇÃO DE NÚMERO ALEATÓRIO
            if(obstaculo1_x==3){
                R1=rand()%10;
                R2=rand()%14;
            } if (obstaculo2_x==3){
                    R3=rand()%10;
                    R4=rand()%14;
            }
        ///TEMPO DE ESPERA
            Sleep(S);
            if(pontos>1&&pontos%5==0){//a cada 5 obstaculos aumenta a velocidade
                S = S-25;
            }


        }

    return 0;
}