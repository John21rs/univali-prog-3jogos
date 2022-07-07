#include <iostream>

using namespace std;

int main()
{
    /*Esse codigo foi feito por Joao Pedro Barreto Arriaga Fernandes, Jamao Khayf De Mello Bernal e Joao Victor Rodrigues Santos*/

    long long int codigo;
    int D0, D1, D2,D3, D4,D5, D6, D7, D8, D9, D10, D11, D12, somatorio, soma_opr;
    /* aqui estao as variaveis que usamos para criar esse codigo,
    foi usado long long int por ter mais digitos do que uma variavel int suporta*/

    cout << "digite os numeros do codigo de barras: ";
    cin >> codigo;

    D0 = codigo%10;
    codigo = codigo/10;
    D1 = codigo%10*3;
    codigo = codigo/10;
    D2 = codigo%10;
    codigo = codigo/10;
    D3 = codigo%10*3;
    codigo = codigo/10;
    D4 = codigo%10;
    codigo = codigo/10;
    D5 = codigo%10*3;
    codigo = codigo/10;
    D6 = codigo%10;
    codigo = codigo/10;
    D7 = codigo%10*3;
    codigo = codigo/10;
    D8 = codigo%10;
    codigo = codigo/10;
    D9 = codigo%10*3;
    codigo = codigo/10;
    D10 = codigo%10;
    codigo = codigo/10;
    D11 = codigo%10*3;
    codigo = codigo/10;
    D12 = codigo%10;
    /*nesse trecho, é onde foi separado digito por digito do codigo de barras para efetuar o calculo,
    alem disso os digitos impares foram multiplicados por tres nessa parte, pois assim agilizaria o calculo*/

    if (codigo >=10){
        cout << "\ncodigo invalido";
        return 0;
    } else if(D12 == 0){
        cout << "\ncodigo invalido";
        return 0;
    } /*essa parte está identificado se o codigo de barras tem mais de 13 digitos ou menos*/

    somatorio = D12+D11+D10+D9+D8+D7+D6+D5+D4+D3+D2+D1;
    soma_opr = somatorio/10;
    soma_opr = soma_opr+1;
    soma_opr = soma_opr*10;
    soma_opr = soma_opr - somatorio; /*nesse trecho é onde o codigo efetua o calculo para verificar o ultimo digito*/

    if (soma_opr%10 == 0){
        soma_opr = 0;/*nessa parte se o calculo do ultimo numero for divisivel por 10 ele sera trocado por zero*/
    }

    if(soma_opr == D0){
        cout << "\ncodigo digitado corretamente!";
    } else {
        cout << "\ncodigo digitado incorretamente!";
        /* e por fim aqui é onde se analisa e diz se o codigo de barras é valido*/
    }
    return 0;
}