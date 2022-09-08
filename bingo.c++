// Trabalho Algoritmos 2 - BINGO.
// Universidade do Vale do Itajai.
// Professor: Rafeal Ballottin Martins.
// Cursos: Engenharia da Computa��o e Ci�ncia da Computa��o.
// Alunos: Abd Al Hadi Al Dairi, Jamao Khayf de Mello Bernal, Joao Victor Rodrigues, Yuri Rodrigues.
// Data de Conclusao: 07/09/2022.
#include <iostream>
#include <locale.h>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
//Defini��es das cores
#define BLACK        0
#define BLUE         1
#define GREEN        2
#define AQUA         3
#define RED          4
#define PURPLE       5
#define YELLOW       6
#define WHITE        7
#define GREY         8
#define LIGHTBLUE    9
#define LIGHTGREEN   10
#define LIGHTAQUA    11
#define LIGHTRED     12
#define LIGHTPURPLE  13
#define LIGHTYELLOW  14
#define BRIGHTWHITE  15
#define TAM 5 // Tamanho da matriz (cartela).
#define TAMVET 75 // N�meros sorteados a serem mostrados.

using namespace std;

void textcolor(int forecolor, int backcolor) { // Fun��o para mudar as cores das letras.
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)(forecolor | backcolor << 4));
}

void cartela(int matriz[][TAM]) { // Fazer a cartela gerando os n�meros conforme cada case.
	int linha, coluna, num, j, cond;

	for (linha = 0; linha < TAM; linha++) {
		for (coluna = 0; coluna < TAM; coluna++) {
			cond = 1;
			while (cond == 1) {
				cond = 0;
				switch (linha) { // Nesse switch, ir� gerar os n�meros conforme cada rand. Na primeira linha, ir� gerar n�meros de 1 � 15 e assim por diante.
				case 0:
					num = rand() % 15 + 1; // 1 � 15.
					break;
				case 1:
					num = rand() % 15 + 16; // 16 � 30.
					break;
				case 2:
					num = rand() % 15 + 31; // 31 � 45.
					break;
				case 3:
					num = rand() % 15 + 46; // 46 � 60.
					break;
				case 4:
					num = rand() % 15 + 61; // 61 � 75.
					break;
				}
				for (j = 0; j < TAM; j++) { // Verificador de n�meros. Se algum n�mero da linha for igual, ir� gerar outros n�meros.
					if (matriz[linha][j] == num) {
						cond = 1;
					}
				}
			}
			matriz[linha][coluna] = num; // Sa�da da matriz caso cond = 0.
		}
	}
}

void ordenar(int matriz[][TAM]) { // Ordenar a matriz em cada linha, no estilo BubbleSort.
	int i, j, cond, temp, linha = 0, coluna, vet[TAM];

	for (linha = 0; linha < TAM; linha++) {
		for (coluna = 0; coluna < TAM; coluna++) {
			vet[coluna] = matriz[linha][coluna];
		}
		cond = 1;
		for (i = TAM - 1; (TAM >= 1) && (cond == 1); i--) {
			cond = 0;
			for (j = 0; j < i; j++) {
				if (vet[j + 1] < vet[j]) {
					temp = vet[j];
					vet[j] = vet[j + 1];
					vet[j + 1] = temp;
					cond = 1;
				}
			}
		}
		for (coluna = 0; coluna < TAM; coluna++) { // Se tudo ordenado, os n�meros ir�o para a matriz em cada linha correspondente.
			matriz[linha][coluna] = vet[coluna];
		}
	}
}

void sorteia1(int vet[]) { // Sortear um n�mero por vez.
	int i, num, cond = 0;

	while (cond == 0) {
		num = rand() % TAMVET + 1;
		for (i = 0; i < TAMVET; i++) {
			if (vet[i] == 0) {
				vet[i] = num;
				cond = 1;
				break;
			}
			else if (vet[i] == num) {
				break;
			}
		}
	}
}

void imprimirVet(int vet[]) { // Mostrar os n�meros j� sorteados
	int i;
	cout << "\nOs numeros sorteados foram estes: ";
	for (i = 0; i < TAMVET; i++) {
		if (vet[i] != 0) {
			textcolor(RED, BLACK);
			cout << " " << vet[i] << "\t";
		}
		textcolor(WHITE, BLACK);
	}
	cout << endl;
}

void imprime(int matriz[][TAM], int vet[]) { // Fun��o para mostrar as 5 cartelas.
	int linha = 0, coluna, i, cond = 0, temp = 0;

	for (linha = 0; linha < TAM; linha++) {
		for (coluna = 0; coluna < TAM; coluna++) {
			cond = 0;
			for (i = 0; i < TAMVET; i++) {
				if (vet[i] == matriz[linha][coluna]) {
					cond = 1;
				}
			}
			if (cond == 1) { // Se o n�mero sorteado for igual ao n�mero que tiver na cartela, o n�mero estar� na cor vermelho.
				textcolor(RED, BLACK);
				cout << matriz[linha][coluna] << "\t";
				temp++;
			}
			else { // Se n�o estiver em vermelho, mostrar� em branco.
				textcolor(WHITE, BLACK);
				cout << matriz[linha][coluna] << "\t";
			}
		}
		cout << endl << endl;
		textcolor(WHITE, BLACK);
	}
}

int verificarDuasMat(int c1[][TAM], int c2[][TAM]) { // Fun��o  para verificar os valores das matrizes, se uma matriz for igual a outra.
	int linha, coluna;
	for (linha = 0; linha < TAM; linha++) {
		for (coluna = 0; coluna < TAM; coluna++) {
			if (c1[linha][coluna] != c2[linha][coluna]) {
				return 1; // Retornar 1 caso for diferente.
			}
		}
	}
	return 0; // Retornar 0 caso for igual.
}

void verificaECriaTabela(int c1[][TAM], int c2[][TAM], int c3[][TAM], int c4[][TAM], int c5[][TAM]) {// Fun��o para verificar a igualdade das matrizes.
	int linha, coluna, cond = 0;

	do {

		cond = 1;

		cartela(c1);
		cartela(c2);
		cartela(c3);
		cartela(c4);
		cartela(c5);

		// Se as matrizes forem iguais, o cond ser� igual a 0 e ir� gerar novas cartelas.
		if (verificarDuasMat(c1,c2) == 0 || verificarDuasMat(c1, c3) == 0 || verificarDuasMat(c1, c4) == 0 || verificarDuasMat(c1, c5) == 0) {
			cond = 0;
		}
		if (verificarDuasMat(c2, c3) == 0 || verificarDuasMat(c2, c4) == 0 || verificarDuasMat(c2, c5) == 0) {
			cond = 0;
		}
		if (verificarDuasMat(c3, c4) == 0 || verificarDuasMat(c3, c5) == 0) {
			cond = 0;
		}
		if (verificarDuasMat(c4, c5) == 0) {
			cond = 0;
		}
	} while (cond == 0);// S� vai finalizar o processo quando o cond for diferente de 0.
}

void vencedor(int vet[], int mat[][TAM], string nome, int& stop, int numC) {// Fun��o para indicar o vencedor.
	int linha, coluna, i, temp = 0;
	for (linha = 0; linha < TAM; linha++) {
		for (coluna = 0; coluna < TAM; coluna++) {
			for (i = 0; i < TAMVET; i++) {
				if (mat[linha][coluna] == vet[i]) {
					temp++;
				}
			}
		}
	}
	if (temp == 25) {// Se o temp for igual a 25 o vencedor � indicado.
		textcolor(AQUA, BLACK);
		cout << "\n" << nome << ", voce eh o vencedor do BINGO!" << endl;
		cout << "Cartela " << numC << ": " << endl << endl;
		for (linha = 0; linha < TAM; linha++) {
			for (coluna = 0; coluna < TAM; coluna++) {
				textcolor(RED, BLACK);
				cout << mat[linha][coluna] << "\t";
			}
			cout << endl << endl;
		}
		textcolor(WHITE, BLACK);
		stop = 1;
	}
}

void mostrarCartela(string nome, int n, int mat[][TAM], int vet[]) {
	textcolor(AQUA, BLACK);
	cout << "\n" << nome;
	cout << "\nCartela " << n << ":" << endl << endl;
	textcolor(WHITE, BLACK);
	imprime(mat, vet);
}
void game() {// Fun��o do jogo com pausas.
	int vet[TAMVET] = { 0 };
	int	c1[TAM][TAM], c2[TAM][TAM], c3[TAM][TAM], c4[TAM][TAM], c5[TAM][TAM];
	int stop = 0; // Solicitar os nomes.
	string n1, n2, n3, n4, n5;

	cout << "\nDigite o nome do primeiro jogador: ";
	cin >> n1;

	cout << "\nDigite o nome do segundo jogador: ";
	cin >> n2;

	cout << "\nDigite o nome do terceiro jogador: ";
	cin >> n3;

	cout << "\nDigite o nome do quarto jogador: ";
	cin >> n4;

	cout << "\nDigite o nome do quinto jogador: ";
	cin >> n5;

	system("cls");

	verificaECriaTabela(c1, c2, c3, c4, c5); // Verificar as cartelas, se possui alguma cartela completamente repetida.

	ordenar(c1);// Ordena as tabelas.
	ordenar(c2);
	ordenar(c3);
	ordenar(c4);
	ordenar(c5);

	textcolor(BLUE, BLACK);
	cout << "__________CARTELAS__________" << endl;
	mostrarCartela(n1, 1, c1, vet);
	mostrarCartela(n2, 2, c2, vet);
	mostrarCartela(n3, 3, c3, vet);
	mostrarCartela(n4, 4, c4, vet);
	mostrarCartela(n5, 4, c5, vet);
	system("pause");

	while (stop == 0){ // Parar o jogo se stop = 1 e todos os n�meros da cartela serem preenchidas por vermelho, ou seja, j� sorteados.

		system("cls");
		textcolor(AQUA, BLACK);
		cout << "-----BINGO-----" << endl;
		textcolor(WHITE, BLACK);
		sorteia1(vet);
		imprimirVet(vet);

		mostrarCartela(n1, 1, c1, vet);
		mostrarCartela(n2, 2, c2, vet);
		mostrarCartela(n3, 3, c3, vet);
		mostrarCartela(n4, 4, c4, vet);
		mostrarCartela(n5, 4, c5, vet);
		system("pause");
		system("cls");

		vencedor(vet,c1, n1, stop, 1);// Aqui � as chamadas de fun��o para verificar quem foi o campe�o.
		vencedor(vet, c2, n2,stop, 2);
		vencedor(vet, c3, n3, stop, 3);
		vencedor(vet, c4, n4, stop, 4);
		vencedor(vet, c5, n5, stop, 5);
	}
}

int main()
{
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	int escolha;

	do { // Menu Inicial

		textcolor(AQUA, BLACK);
		cout << "|------------------------|" << endl;
		textcolor(LIGHTGREEN, BLACK);
		cout << "|          MENU          |" << endl;
		textcolor(AQUA, BLACK);
		cout << "|------------------------|" << endl;
		cout << "|                        |" << endl;
		textcolor(LIGHTGREEN, BLACK);
		cout << "|1:Jogo                  |" << endl;
		textcolor(AQUA, BLACK);
		cout << "|                        |" << endl;
		textcolor(LIGHTGREEN, BLACK);
		cout << "|2:Creditos              |" << endl;
		textcolor(AQUA, BLACK);
		cout << "|                        |" << endl;
		textcolor(LIGHTGREEN, BLACK);
		cout << "|3:Sair                  |" << endl;
		textcolor(AQUA, BLACK);
		cout << "|                        |" << endl;
		cout << "|------------------------|";
		cout << "\n|Ecolha uma das opcoes: ";
		cin >> escolha;
		system("cls");

		switch (escolha) {
		case 1:
			game();// Jogo com pausas.
			system("pause");
			system("cls");
			break;
		case 2:// Creditos.
			textcolor(LIGHTRED, BLACK);
			cout << "Trabalho Algoritmos 2 - BINGO." << endl;
			cout << "Universidade do Vale do Itajai" << endl;
			cout << "Professor: Rafeal Ballottin Martins." << endl;
			cout << "Cursos: Engenharia da Computa��o e Ci�ncia da Computa��o." << endl;
			cout << "Alunos: Abd Al Hadi Al Dairi, Jamao Khayf de Mello Bernal, Joao Victor Rodrigues, Yuri Rodrigues." << endl;
			cout << "Data de Conclusao: 06/09/2022." << endl << endl;
			textcolor(WHITE, BLACK);
			system("pause");
			system("cls");
			break;
		case 3:// Sair do jogo.
			textcolor(WHITE, BLACK);
			break;
		default:
			cout << "Op��o invalida!" << endl;
			system("pause");
			system("cls");
			break;
		}
	} while (escolha != 3);
}
