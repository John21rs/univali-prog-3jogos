#include <iostream>
#include<windows.h>
#include<time.h>
using namespace std;
#define TAM 4
int main(){

//Autores: João Pedro Barreto Arriaga Fernandes, Jamao Khayf De Mello Bernal, João Victor Rodrigues Santos, Vítor Martins

    int matprin[TAM][TAM]={1,4,5,2,7,2,8,7,3,6,1,4,6,5,3,8};
    int jogo[TAM][TAM]={}, gab[TAM][TAM];
    int opcao, L1, L2, C1, C2, p=0, sm_gab=0,sm_jogo;
    const char *cls, *pause;
    srand(time(NULL));

    opcao=rand()%3;/*Randomiza como será a matriz gabarito*/

    switch(opcao){/*Seleciona um modo de jogo a partir do número aleatório*/
        case 0:
            for(int i=0;i<TAM;i++){ /*Seleciona a linha em que o número será escrito*/
                for(int j=0;j<TAM;j++){/*Seleciona a coluna em que o número será escrito*/
                    gab[i][j]=matprin[i][j];/*Escreve a matriz gabarito igual a principal*/
                }
            }
            break;
        case 1:
            for(int i=0;i<TAM;i++){
                for(int j=0;j<TAM;j++){
                    gab[i][j]=matprin[j][i];/*Escreve a matriz gabarito igual a transposta da principal*/
                }
            }
            break;
        case 2:
            for(int i=0;i<TAM;i++){
                for(int j=0;j<TAM;j++){
                    gab[i][j]= matprin[TAM-1-i][j];/*Escreve a matriz gabarito invertendo as linhas da principal*/
                }
            }
            break;
        case 3:
            for(int i=0;i<TAM;i++){
                for(int j=0;j<TAM;j++){
                    gab[i][j]= matprin[i][TAM-1-j];/*Escreve a matriz gabarito invertendo as colunas da principal*/
                }
            }
            break;
    }

    for(int i=0;i<TAM;i++){/*Seleciona a linha do número que vai ser somado*/
        for(int j=0;j<TAM;j++){/*Seleciona a coluna do número que vai ser somado*/
            sm_gab+=gab[i][j];/*Somatório dos valores da matriz gabarito*/
        }
    }

    while(p<=TAM*6){/*Faz o jogo ciclar até p ser igual ao triplo do número de pares*/

        for(int i=0;i<TAM;i++){
            for(int j=0;j<TAM;j++){
                cout<<jogo[i][j]<<"\t";/*Escreve a matriz jogo*/
            }
            cout<<endl;
        }
        cout<<"Jogadas realizadas: "<<p;

        int m=0;
        while(m!=1){/*Cicla até m ser igual a 1*/
            cout<<"\nDigite um valor entre 0 e 3 para a linha";
            cin>>L1;/*Dá o valor digitado a cima para linha*/
            cout<<"\nDigite um valor entre 0 e 3 para a coluna";
            cin>>C1;/*Dá o valor digitado a cima para coluna*/
            cout<<"\n";
            if(jogo[L1][C1]==0){/*Testa se a posição está livre*/
                m=1;
                jogo[L1][C1]=gab[L1][C1];/*Escreve em jogo o valor de gabarito na mesma posição*/
                system("cls");
                for(int i=0;i<TAM;i++){
                    for(int j=0;j<TAM;j++){
                        cout<<jogo[i][j]<<"\t";/*Reescreve a matriz jogo com o valor "virado"*/
                    }
                    cout<<endl;
                }
            }else{
                m=0;
                cout<<"Essa combinacao ja foi usada!";
            }
        }

        int n=0;
        while(n!=1){/*Cicla até n ser igual a 1*/
            cout<<"\nDigite um valor entre 0 e 3 para a linha";
            cin>>L2;/*Dá o valor digitado a cima para linha*/
            cout<<"\nDigite um valor entre 0 e 3 para a coluna";
            cin>>C2;/*Dá o valor digitado a cima para coluna*/
            cout<<"\n";
            if(jogo[L2][C2]==0){/*Testa se a posição está livre*/
                n=1;
                jogo[L2][C2]=gab[L2][C2];/*Escreve em jogo o valor de gabarito na mesma posição*/
                system("cls");
                for(int i=0;i<TAM;i++){
                    for(int j=0;j<TAM;j++){
                        cout<<jogo[i][j]<<"\t";/*Reescreve a matriz jogo com o valor "virado"*/
                    }
                    cout<<endl;
                }
            }else{
                cout<<"Essa combinacao ja foi usada"<<"\n";
                n=0;
            }
        }

        if(jogo[L1][C1]==jogo[L2][C2]){/*Testa se os numeros são iguais*/
            cout<<"\nJogada OK!!";

        }else{
            cout<<"\nJogada NOK!!";
            jogo[L1][C1]={};/*"Desvira" o valor dessa posição*/
            jogo[L2][C2]={};
        }

        Sleep(2000);
        system("cls");
        p++;
        sm_jogo=0;

        for(int i=0;i<TAM;i++){
            for(int j=0;j<TAM;j++){
                sm_jogo+=jogo[i][j];/*Somatório dos valores da matriz jogo*/
            }
        }

        if(sm_jogo==sm_gab){/*Testa se o somatório de jogo e gabarito são iguais*/
            system("cls");
            cout<<"PARABENS, VOCE VENCEU!!!";
            system("pause");

        }
    }

    if(sm_jogo==sm_gab&&p==TAM*6){/*Testa se o somatório de jogo e gabarito são iguais e se o jogo acabou*/
        system("cls");
        cout<<"FIM DE JOGO, VOCE VENCEU!!!";
        system("pause");
    }else{
        system("cls");
        cout<<"FIM DE JOGO, VOCE PERDEU!!!";
        system("pause");
        }

    return 0;
}