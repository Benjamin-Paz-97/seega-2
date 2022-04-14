#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h> //funcion radom RAND_MAX
#include <ctime> //para el aleatorio para usar el sran y cada vez que se genere es diferente valor aleatorio
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
using namespace std;
using std::string;

//linea de codigo para poder usar colores en consola
//creamos la funcion para dar color y la llamammos "color"
HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
//declaramos como variable global al tablero
int **Tablero;
//variable global a la matriz que usaremos para agregar sus valores al tablero vacio
int matriza[25][80] = { {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
						{0,0,0,1,1,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1,1,0,1,1,0,0},
						{0,0,0,1,1,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1,1,0,1,1,0,0},
						{0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,0,0,0,1,1,0,1,1,0,0},
						{0,0,3,3,3,3,3,3,3,3,3,0,0,1,1,1,1,1,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,1,1,1,1,1,0,0,3,3,3,3,3,3,3,3,3,0,0},
						{0,1,1,1,1,1,1,1,1,1,1,1,0,1,5,1,5,1,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,1,7,1,7,1,0,1,1,1,1,1,1,1,1,1,1,1,0},
						{0,1,11,1,12,1,13,1,14,1,15,1,0,1,1,1,1,1,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,1,1,1,1,1,0,1,11,1,12,1,13,1,14,1,15,1,0},
						{0,1,16,1,17,1,18,1,19,1,20,1,0,1,5,1,5,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,7,1,7,1,0,1,16,1,17,1,18,1,19,1,20,1,0},
						{0,1,21,1,22,1,1,1,24,1,25,1,0,1,1,1,1,1,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,1,1,1,1,1,0,1,21,1,22,1,1,1,24,1,25,1,0},
						{0,1,26,1,27,1,28,1,29,1,30,1,0,1,5,1,5,1,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,1,7,1,7,1,0,1,26,1,27,1,28,1,29,1,30,1,0},
						{0,1,31,1,32,1,33,1,34,1,35,1,0,1,1,1,1,1,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,1,1,1,1,1,0,1,31,1,32,1,33,1,34,1,35,1,0},
						{0,1,1,1,1,1,1,1,1,1,1,1,0,1,5,1,5,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,7,1,7,1,0,1,1,1,1,1,1,1,1,1,1,1,0},
						{0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0},
						{0,1,1,1,1,1,1,1,1,1,1,1,0,1,5,1,5,1,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,1,7,1,7,1,0,1,1,1,1,1,1,1,1,1,1,1,0},
						{0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0},
						{0,1,1,1,1,1,1,1,1,1,1,1,0,1,5,1,5,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,7,1,7,1,0,1,1,1,1,1,1,1,1,1,1,1,0},
						{0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0},
						{0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0},
						{0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0},
						{0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0},
						{0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0},
						{0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0},
						{0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0},
						{0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0},
						{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} };

//reservamos memoria para la matriz diamica (tablero)
void Reservar_memoria_tablero() {
	Tablero = new int* [25];     //reservando memoria para las filas
	for (int i = 0; i < 25; i++) {
		Tablero[i] = new int[80]; // reservado memoria para las columnas
	}
}

//llenamos el tablero de los valores en la matriz inicializada
void generar_matriz() {
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 80; j++) {
			*(*(Tablero +i)+j) = matriza[i][j];
		}
	}
}

//imprimimos la matriz tablero
void imprimir_matriz(int fichas1,int fichas2) {

	system("cls");
	char txt1[9] = { 'j','u','g','a','d','o','r',' ','1' };
	char txt2[9] = { 'j','u','g','a','d','o','r',' ','2' };
	int k = 0,m=0;
	//int fichas1 = 1, fichas2 = 1;
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 80; j++) {
			if (*(*(Tablero+i)+j) == 0) {
				//imprimimos un espacio en la pocicion indicada, asignandole un color
				SetConsoleTextAttribute(color, 240);
				cout << " ";
			}
			else {
				if (*(*(Tablero + i) + j) == 1) {
					//imprimimos un espacio en la pocicion indicada, asignandole un color
					SetConsoleTextAttribute(color, 00);
					cout << " ";
				}
				else {
					if (*(*(Tablero + i) + j) == 3) {
						SetConsoleTextAttribute(color, 240);//24 (fondo blanco) 0(letras negras)
						if (j > 0 && j < 13) {
							cout << txt1[k];
							k++;
						}
						if (j>67 && j < 79) {
							cout << txt2[m];
							m++;
						}
					}
					else {

						if (*(*(Tablero + i) + j) == 5 || *(*(Tablero + i) + j) == 6 || *(*(Tablero + i) + j) == 7 || *(*(Tablero + i) + j) == 8) {
							if (*(*(Tablero + i) + j) == 5 || *(*(Tablero + i) + j) == 6) {
								if (*(*(Tablero + i) + j) == 5) {
									if (fichas1 > 0) {
										SetConsoleTextAttribute(color, 30);
										cout << " ";
										fichas1--;
									}
									else {
										SetConsoleTextAttribute(color, 00);
										cout << " ";
									}
								}
								else{
									SetConsoleTextAttribute(color, 30);
									cout << " ";
								}
							}
							else{
								if (*(*(Tablero + i) + j) == 7) {
									if (fichas2 > 0) {
										SetConsoleTextAttribute(color, 40);
										cout << " ";
										fichas2--;
									}
									else {
										SetConsoleTextAttribute(color, 00);
										cout << " ";
									}
								}
								else{
									SetConsoleTextAttribute(color, 40);
									cout << " ";
								}
							}
						}
						else {
							SetConsoleTextAttribute(color, 7);
							switch (*(*(Tablero+i)+j)){
							case 11:
								cout << "A";
								break;
							case 12:
								cout << "B";
								break;
							case 13:
								cout << "C";
								break;
							case 14:
								cout << "D";
								break;
							case 15:
								cout << "E";
								break;
							case 16:
								cout << "F";
								break;
							case 17:
								cout << "G";
								break;
							case 18:
								cout << "H";
								break;
							case 19:
								cout << "I";
								break;
							case 20:
								cout << "J";
								break;
							case 21:
								cout << "K";
								break;
							case 22:
								cout << "L";
								break;
							case 23:
								cout << "M";
								break;
							case 24:
								cout << "N";
								break;
							case 25:
								cout << "O";
								break;
							case 26:
								cout << "P";
								break;
							case 27:
								cout << "Q";
								break;
							case 28:
								cout << "R";
								break;
							case 29:
								cout << "S";
								break;
							case 30:
								cout << "T";
								break;
							case 31:
								cout << "U";
								break;
							case 32:
								cout << "V";
								break;
							case 33:
								cout << "W";
								break;
							case 34:
								cout << "X";
								break;
							case 35:
								cout << "Y";
								break;
							default:
								cout << "+";
								break;
							}
							
						}
					}
				}
			}

		}
		cout << "\n";
	}
}

//funcion para poder asigar posicion
void gotoxy(int x, int y) {
	HANDLE Salida;
	Salida = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Posicion_info;
	Posicion_info.X = x;
	Posicion_info.Y = y;
	SetConsoleCursorPosition(Salida, Posicion_info);
}

struct jugador {
	char nombre[11];
	int puntaje;
	int Color_jugador;
} *jugador_1, *jugador_2;

void crear_jugadores(){
	int puntaje = 0;
	gotoxy(0, 26);
	SetConsoleTextAttribute(color, 7);
	cout << "nombres con maximo 11 caracteres" << endl;
	cout << "ingrese el nombre del jugador 1 : ";
	cin>>jugador_1->nombre;
	jugador_1->puntaje = puntaje;
	cout << "ingrese el nombre del jugador 2 : ";
	cin>>jugador_2->nombre;
	jugador_2->puntaje = puntaje;
}

void Imprime_datos_jugadores() {
	cout << endl;
	gotoxy(85, 5);
	SetConsoleTextAttribute(color, 7);
	cout << "		JUGADOR P1 " << endl;
	gotoxy(85, 6);
	cout <<"nombre : "<< jugador_1->nombre << endl;
	gotoxy(85, 7);
	cout << "puntaje : " << jugador_1->puntaje << endl;
	gotoxy(120, 5);
	cout << "		JUGADOR P2 " << endl;
	gotoxy(120, 6);
	cout << "nombre : " << jugador_2->nombre << endl;
	gotoxy(120, 7);
	cout << "puntaje : " << jugador_2->puntaje << endl;
}

int Verificar_Espacio_Dispoible(char opcion) {
	int aux=0;
	switch (opcion) {
	case 'A':
		if (*(*(Tablero + 6) + 2) > 1) 
			aux = 1;
		break;
	case 'B':
		if (*(*(Tablero + 6) + 4) > 1) 
			aux = 1;
		break;
	case 'C':
		if (*(*(Tablero + 6) + 6) > 1) 
			aux = 1;
		break;
	case 'D':
		if (*(*(Tablero + 6) + 8) > 1) 
			aux = 1;
		break;
	case 'E':
		if(*(*(Tablero + 6) + 10) > 1)
			aux = 1;
		break;
	case 'F':
		if (*(*(Tablero + 7) + 2) > 1)
			aux = 1;
		break;

	case 'G':
		if (*(*(Tablero + 7) + 4) > 1)
			aux = 1;
		break;
	case 'H':
		if (*(*(Tablero + 7) + 6) > 1)
			aux = 1;
		break;
	case 'I':
		if (*(*(Tablero + 7) + 8) > 1)
			aux = 1;
		break;

	case 'J':
		if (*(*(Tablero + 7) + 10) > 1)
			aux = 1;
		break;
	case 'K':
		if (*(*(Tablero + 8) + 2) > 1)
			aux = 1;
		break;

	case 'L':
		if (*(*(Tablero + 8) + 4) > 1)
			aux = 1;
		break;
	case 'N':
		if (*(*(Tablero + 8) + 8) > 1)
			aux = 1;
		break;

	case 'O':
		if (*(*(Tablero + 8) + 10) > 1)
			aux = 1;
		break;
	case 'P':
		if (*(*(Tablero + 9) + 2) > 1)
			aux = 1;
		break;

	case 'Q':
		if (*(*(Tablero + 9) + 4) > 1)
			aux = 1;
		break;
	case 'R':
		if (*(*(Tablero + 9) + 6) > 1)
			aux = 1;
		break;
	case 'S':
		if (*(*(Tablero + 9) + 8) > 1)
			aux = 1;
		break;

	case 'T':
		if (*(*(Tablero + 9) + 10) > 1)
			aux = 1;
		break;
	case 'U':
		if (*(*(Tablero + 10) + 2) > 1)
			aux = 1;
		break;

	case 'V':
		if (*(*(Tablero + 10) + 4) > 1)
			aux = 1;
		break;
	case 'W':
		if (*(*(Tablero + 10) + 6) > 1)
			aux = 1;
		break;
	case 'X':
		if (*(*(Tablero + 10) + 8) > 1)
			aux = 1;
		break;

	case 'Y':
		if (*(*(Tablero + 10) + 10) > 1)
			aux = 1 ;
		break;
	}
	return (aux);
}

void Fichas_inicio() {
	int Tipo;  //tipo de posicion de inicio
	srand(time(NULL));
	Tipo = rand()%4 +1 ;
	if (Tipo == 1) {
		//posicion C
		*(*(Tablero + 5) + 40) = 6;
		*(*(Tablero + 6) + 6) = 1;
		*(*(Tablero + 6) + 73) = 1;
		//posicion K
		*(*(Tablero + 13) + 24) = 6;
		*(*(Tablero + 8) + 2) = 1;
		*(*(Tablero + 8) + 69) = 1;
		//posicion O
		*(*(Tablero + 13) + 56) = 8;
		*(*(Tablero + 8) + 10) = 1;
		*(*(Tablero + 8) + 77) = 1;
		//posicion W
		*(*(Tablero + 21) + 40) = 8;
		*(*(Tablero + 10) + 6) = 1;
		*(*(Tablero + 10) + 73) = 1;
	}
	if (Tipo == 2) {
		//posicion C
		*(*(Tablero + 5) + 40) = 8;
		*(*(Tablero + 6) + 6) = 1;
		*(*(Tablero + 6) + 73) = 1;
		//posicion K
		*(*(Tablero + 13) + 24) = 8;
		*(*(Tablero + 8) + 2) = 1;
		*(*(Tablero + 8) + 69) = 1;
		//posicion O
		*(*(Tablero + 13) + 56) = 6;
		*(*(Tablero + 8) + 10) = 1;
		*(*(Tablero + 8) + 77) = 1;
		//posicion W
		*(*(Tablero + 21) + 40) = 6;
		*(*(Tablero + 10) + 6) = 1;
		*(*(Tablero + 10) + 73) = 1;
	}
	if(Tipo == 3) {
		//posicion C
		*(*(Tablero + 5) + 40) = 8;
		*(*(Tablero + 6) + 6) = 1;
		*(*(Tablero + 6) + 73) = 1;
		//posicion K
		*(*(Tablero + 13) + 24) = 6;
		*(*(Tablero + 8) + 2) = 1;
		*(*(Tablero + 8) + 69) = 1;
		//posicion O
		*(*(Tablero + 13) + 56) = 6;
		*(*(Tablero + 8) + 10) = 1;
		*(*(Tablero + 8) + 77) = 1;
		//posicion W
		*(*(Tablero + 21) + 40) = 8;
		*(*(Tablero + 10) + 6) = 1;
		*(*(Tablero + 10) + 73) = 1;
	}
	if (Tipo == 4) {
		//posicion C
		*(*(Tablero + 5) + 40) = 6;
		*(*(Tablero + 6) + 6) = 1;
		*(*(Tablero + 6) + 73) = 1;
		//posicion K
		*(*(Tablero + 13) + 24) = 8;
		*(*(Tablero + 8) + 2) = 1;
		*(*(Tablero + 8) + 69) = 1;
		//posicion O
		*(*(Tablero + 13) + 56) = 8;
		*(*(Tablero + 8) + 10) = 1;
		*(*(Tablero + 8) + 77) = 1;
		//posicion W
		*(*(Tablero + 21) + 40) = 6;
		*(*(Tablero + 10) + 6) = 1;
		*(*(Tablero + 10) + 73) = 1;
	}
}
char ToupperM(char c) {
	switch (c){
		case 'a':
			c = 'A';
			break;
		case 'b':
			c = 'B';
			break;
		case 'c':
			c = 'C';
			break;
		case 'd':
			c = 'D';
			break;
		case 'e':
			c = 'E';
			break;
		case 'f':
			c = 'F';
			break;
		case 'g':
			c = 'G';
			break;
		case 'h':
			c = 'H';
			break;
		case 'i':
			c = 'I';
			break;
		case 'j':
			c = 'J';
			break;
		case 'k':
			c = 'K';
			break;
		case 'l':
			c = 'L';
			break;
		case 'n':
			c = 'N';
			break;
		case 'o':
			c = 'O';
			break;
		case 'p':
			c = 'P';
			break;
		case 'q':
			c = 'Q';
			break;
		case 'r':
			c = 'R';
			break;
		case 's':
			c = 'S';
			break;
		case 't':
			c = 'T';
			break;
		case 'u':
			c = 'U';
			break;
		case 'v':
			c = 'V';
			break;
		case 'w':
			c = 'W';
			break;
		case 'x':
			c = 'X';
			break;
		case 'y':
			c = 'Y';
			break;
	default:
		c = c;
	}
	return c;
}
int agregar_ficha_P1(int Ficha_jugador_1) {
	char op;
	int opNeg=0;
	do {
		gotoxy(85, 10);
		cout << "Tiene " << Ficha_jugador_1 <<" Fichas por colocar..."<<endl;
		gotoxy(85, 11);
		cin>>op;
		op = ToupperM(op);
		opNeg = Verificar_Espacio_Dispoible(op);
	} while (opNeg == 0);
	switch(op){
	case 'A':
		*(*(Tablero + 5) + 24) = 6;
		*(*(Tablero + 6) + 2) = 1;
		*(*(Tablero + 6) + 69) = 1;
		Ficha_jugador_1--;
		break;		
	case 'B':
		*(*(Tablero + 5) + 32) = 6;
		*(*(Tablero + 6) + 4) = 1;
		*(*(Tablero + 6) + 71) = 1;
		Ficha_jugador_1--;
		break;
	case 'C':
		*(*(Tablero + 5) + 40) = 6;
		*(*(Tablero + 6) + 6) = 1;
		*(*(Tablero + 6) + 73) = 1;
		Ficha_jugador_1--;
		break;
	case 'D':
		*(*(Tablero + 5) + 48) = 6;
		*(*(Tablero + 6) + 8) = 1;
		*(*(Tablero + 6) + 75) = 1;
		Ficha_jugador_1--;
		break;
		
	case 'E':
		*(*(Tablero + 5) + 56) = 6;
		*(*(Tablero + 6) + 10) = 1;
		*(*(Tablero + 6) + 77) = 1;
		Ficha_jugador_1--;
		break;
	case 'F':
		*(*(Tablero + 9) + 24) = 6;
		*(*(Tablero + 7) + 2) = 1;
		*(*(Tablero + 7) + 69) = 1;
		Ficha_jugador_1--;
		break;

	case 'G':
		*(*(Tablero + 9) + 32) = 6;
		*(*(Tablero + 7) + 4) = 1;
		*(*(Tablero + 7) + 71) = 1;
		Ficha_jugador_1--;
		break;
	case 'H':
		*(*(Tablero + 9) + 40) = 6;
		*(*(Tablero + 7) + 6) = 1;
		*(*(Tablero + 7) + 73) = 1;
		Ficha_jugador_1--;
		break;
	case 'I':
		*(*(Tablero + 9) + 48) = 6;
		*(*(Tablero + 7) + 8) = 1;
		*(*(Tablero + 7) + 75) = 1;
		Ficha_jugador_1--;
		break;

	case 'J':
		*(*(Tablero + 9) + 56) = 6;
		*(*(Tablero + 7) + 10) = 1;
		*(*(Tablero + 7) + 77) = 1;
		Ficha_jugador_1--;
		break;
	case 'K':
		*(*(Tablero + 13) + 24) = 6;
		*(*(Tablero + 8) + 2) = 1;
		*(*(Tablero + 8) + 69) = 1;
		Ficha_jugador_1--;
		break;

	case 'L':
		*(*(Tablero + 13) + 32) = 6;
		*(*(Tablero + 8) + 4) = 1;
		*(*(Tablero + 8) + 71) = 1;
		Ficha_jugador_1--;
		break;
	case 'N':
		*(*(Tablero + 13) + 48) =6;
		*(*(Tablero + 8) + 8) = 1;
		*(*(Tablero + 8) + 75) = 1;
		Ficha_jugador_1--;
		break;

	case 'O':
		*(*(Tablero + 13) + 56) = 6;
		*(*(Tablero + 8) + 10) = 1;
		*(*(Tablero + 8) + 77) = 1;
		Ficha_jugador_1--;
		break;
	case 'P':
		*(*(Tablero + 17) + 24) = 6;
		*(*(Tablero + 9) + 2) = 1;
		*(*(Tablero + 9) + 69) = 1;
		Ficha_jugador_1--;
		break;

	case 'Q':
		*(*(Tablero + 17) + 32) = 6;
		*(*(Tablero + 9) + 4) = 1;
		*(*(Tablero + 9) + 71) = 1;
		Ficha_jugador_1--;
		break;
	case 'R':
		*(*(Tablero + 17) + 40) = 6;
		*(*(Tablero + 9) + 6) = 1;
		*(*(Tablero + 9) + 73) = 1;
		Ficha_jugador_1--;
		break;
	case 'S':
		*(*(Tablero + 17) + 48) = 6;
		*(*(Tablero + 9) + 8) = 1;
		*(*(Tablero + 9) + 75) = 1;
		Ficha_jugador_1--;
		break;

	case 'T':
		*(*(Tablero + 17) + 56) = 6;
		*(*(Tablero + 9) + 10) = 1;
		*(*(Tablero + 9) + 77) = 1;
		Ficha_jugador_1--;
		break;
	case 'U':
		*(*(Tablero + 21) + 24) = 6;
		*(*(Tablero + 10) + 2) = 1;
		*(*(Tablero + 10) + 69) = 1;
		Ficha_jugador_1--;
		break;

	case 'V':
		*(*(Tablero + 21) + 32) = 6;
		*(*(Tablero + 10) + 4) = 1;
		*(*(Tablero + 10) + 71) = 1;
		Ficha_jugador_1--;
		break;
	case 'W':
		*(*(Tablero + 21) + 40) = 6;
		*(*(Tablero + 10) + 6) = 1;
		*(*(Tablero + 10) + 73) = 1;
		Ficha_jugador_1--;
		break;
	case 'X':
		*(*(Tablero + 21) + 48) = 6;
		*(*(Tablero + 10) + 8) = 1;
		*(*(Tablero + 10) + 75) = 1;
		Ficha_jugador_1--;
		break;

	case 'Y':
		*(*(Tablero + 21) + 56) = 6;
		*(*(Tablero + 10) + 10) = 1;
		*(*(Tablero + 10) + 77) = 1;
		Ficha_jugador_1--;
		break;
	default:
		cout << "+";
		break;
	}
	return(Ficha_jugador_1);
}
int agregar_ficha_P2(int Ficha_jugador_2) {
	char op;
	int opNeg = 0;
	do {
		gotoxy(120, 10);
		cout << "Tiene " << Ficha_jugador_2 << " Fichas por colocar..." << endl;
		gotoxy(120, 11);
		cin >> op;
		op = ToupperM(op);
		opNeg = Verificar_Espacio_Dispoible(op);
	} while (opNeg == 0);
	switch (op) {
	case 'A':
		*(*(Tablero + 5) + 24) = 8;//posicion de la ficha del jugador 
		*(*(Tablero + 6) + 2) = 1;
		*(*(Tablero + 6) + 69) = 1;
		Ficha_jugador_2--;
		break;

	case 'B':
		*(*(Tablero + 5) + 32) = 8;
		*(*(Tablero + 6) + 4) = 1;
		*(*(Tablero + 6) + 71) = 1;
		Ficha_jugador_2--;
		break;
	case 'C':
		*(*(Tablero + 5) + 40) = 8;
		*(*(Tablero + 6) + 6) = 1;
		*(*(Tablero + 6) + 73) = 1;
		Ficha_jugador_2--;
		break;
	case 'D':
		*(*(Tablero + 5) + 48) = 8;
		*(*(Tablero + 6) + 8) = 1;
		*(*(Tablero + 6) + 75) = 1;
		Ficha_jugador_2--;
		break;

	case 'E':
		*(*(Tablero + 5) + 56) = 8;
		*(*(Tablero + 6) + 10) = 1;
		*(*(Tablero + 6) + 77) = 1;
		Ficha_jugador_2--;
		break;
	case 'F':
		*(*(Tablero + 9) + 24) =8;
		*(*(Tablero + 7) + 2) = 1;
		*(*(Tablero + 7) + 69) = 1;
		Ficha_jugador_2--;
		break;

	case 'G':
		*(*(Tablero + 9) + 32) = 8;
		*(*(Tablero + 7) + 4) = 1;
		*(*(Tablero + 7) + 71) = 1;
		Ficha_jugador_2--;
		break;
	case 'H':
		*(*(Tablero + 9) + 40) = 8;
		*(*(Tablero + 7) + 6) = 1;
		*(*(Tablero + 7) + 73) = 1;
		Ficha_jugador_2--;
		break;
	case 'I':
		*(*(Tablero + 9) + 48) = 8;
		*(*(Tablero + 7) + 8) = 1;
		*(*(Tablero + 7) + 75) = 1;
		Ficha_jugador_2--;
		break;

	case 'J':
		*(*(Tablero + 9) + 56) = 8;
		*(*(Tablero + 7) + 10) = 1;
		*(*(Tablero + 7) + 77) = 1;
		Ficha_jugador_2--;
		break;
	case 'K':
		*(*(Tablero + 13) + 24) = 8;
		*(*(Tablero + 8) + 2) = 1;
		*(*(Tablero + 8) + 69) = 1;
		Ficha_jugador_2--;
		break;

	case 'L':
		*(*(Tablero + 13) + 32) = 8;
		*(*(Tablero + 8) + 4) = 1;
		*(*(Tablero + 8) + 71) = 1;
		Ficha_jugador_2--;
		break;
	case 'N':
		*(*(Tablero + 13) + 48) = 8;
		*(*(Tablero + 8) + 8) = 1;
		*(*(Tablero + 8) + 75) = 1;
		Ficha_jugador_2--;

		break;

	case 'O':
		*(*(Tablero + 13) + 56) = 8;
		*(*(Tablero + 8) + 10) = 1;
		*(*(Tablero + 8) + 77) = 1;
		Ficha_jugador_2--;
		break;
	case 'P':
		*(*(Tablero + 17) + 24) = 8;
		*(*(Tablero + 9) + 2) = 1;
		*(*(Tablero + 9) + 69) = 1;
		Ficha_jugador_2--;
		break;

	case 'Q':
		*(*(Tablero + 17) + 32) = 8;
		*(*(Tablero + 9) + 4) = 1;
		*(*(Tablero + 9) + 71) = 1;
		Ficha_jugador_2--;
		break;
	case 'R':
		*(*(Tablero + 17) + 40) = 8;
		*(*(Tablero + 9) + 6) = 1;
		*(*(Tablero + 9) + 73) = 1;
		Ficha_jugador_2--;
		break;
	case 'S':
		*(*(Tablero + 17) + 48) = 8;
		*(*(Tablero + 9) + 8) = 1;
		*(*(Tablero + 9) + 75) = 1;
		Ficha_jugador_2--;
		break;

	case 'T':
		*(*(Tablero + 17) + 56) = 8;
		*(*(Tablero + 9) + 10) = 1;
		*(*(Tablero + 9) + 77) = 1;
		Ficha_jugador_2--;
		break;
	case 'U':
		*(*(Tablero + 21) + 24) = 8;
		*(*(Tablero + 10) + 2) = 1;
		*(*(Tablero + 10) + 69) = 1;
		Ficha_jugador_2--;
		break;

	case 'V':
		*(*(Tablero + 21) + 32) = 8;
		*(*(Tablero + 10) + 4) = 1;
		*(*(Tablero + 10) + 71) = 1;
		Ficha_jugador_2--;
		break;
	case 'W':
		*(*(Tablero + 21) + 40) = 8;
		*(*(Tablero + 10) + 6) = 1;
		*(*(Tablero + 10) + 73) = 1;
		Ficha_jugador_2--;
		break;
	case 'X':
		*(*(Tablero + 21) + 48) = 8;
		*(*(Tablero + 10) + 8) = 1;
		*(*(Tablero + 10) + 75) = 1;
		Ficha_jugador_2--;
		break;

	case 'Y':
		*(*(Tablero + 21) + 56) = 8;
		*(*(Tablero + 10) + 10) = 1;
		*(*(Tablero + 10) + 77) = 1;
		Ficha_jugador_2--;
		break;
	default:
		cout << "+";
		break;
	}
	return(Ficha_jugador_2);
}

//segunda face del juego
void habilitar_piesa_M() {
	for (int i = 12; i < 15; i++) {
		for (int j = 37; j < 43; j++) {
			*(*(Tablero + i) + j) = 0;
		}
	}
	*(*(Tablero + 8) + 6) = 1;
	*(*(Tablero + 8) + 73) = 1;
}


void Imprimir_piezas_Disponibles_jugadores() {
	int k,l,m,n=11;
	k = 6;
	for (int i = 5; i <= 21; i = i + 4) {
		l = 2;
		m = 69;
		for (int j = 24; j <= 56; j = j + 8) {			
			if (*(*(Tablero + 1) + j) != 1) {
				if (*(*(Tablero + i) + j) == 6) {
					*(*(Tablero + k) + l) = n;
					n++;
				}
				else {
					if (n != 23) {
						*(*(Tablero + k) + m) = n;
						n++;
					}
					else {
						n++;
					}
				}
			}
			l = l + 2;
			m = m + 2;
		}
		k++;
	}
}
//movimientos

void Arriba(int i,int j) {
	int aux;
	aux = *(*(Tablero + i) + j);
	*(*(Tablero + i) + j) = 1;
	i = i - 4;
	*(*(Tablero + i) + j) = aux;
}

void Abajo(int i, int j) {
	int aux;
	aux = *(*(Tablero + i) + j);
	*(*(Tablero + i) + j) = 1;
	i = i + 4;
	*(*(Tablero + i) + j) = aux;
}

void derecha( int i, int j) {
	int aux;
	aux = *(*(Tablero + i) + j);
	*(*(Tablero + i) + j) = 1;
	j = j + 8;
	*(*(Tablero + i) + j) = aux;
}

void izquierda(int i, int j) {
	int aux;
	aux = *(*(Tablero + i) + j);
	*(*(Tablero + i) + j) = 1;
	j = j - 8;
	*(*(Tablero + i) + j) = aux;
}

int confirmar_ficha_disponible_P1(char opcion) {
	int aux=0;
	switch (opcion) {
	case 'A':
		if (*(*(Tablero + 6) + 2) == 11)
			aux = 1;
		break;
	case 'B':
		if (*(*(Tablero + 6) + 4) == 12)
			aux = 1;
		break;
	case 'C':
		if (*(*(Tablero + 6) + 6) == 13)
			aux = 1;
		break;
	case 'D':
		if (*(*(Tablero + 6) + 8) == 14)
			aux = 1;
		break;
	case 'E':
		if (*(*(Tablero + 6) + 10) == 15)
			aux = 1;
		break;
	case 'F':
		if (*(*(Tablero + 7) + 2) == 16)
			aux = 1;
		break;

	case 'G':
		if (*(*(Tablero + 7) + 4) == 17)
			aux = 1;
		break;
	case 'H':
		if (*(*(Tablero + 7) + 6) == 18)
			aux = 1;
		break;
	case 'I':
		if (*(*(Tablero + 7) + 8) == 19)
			aux = 1;
		break;

	case 'J':
		if (*(*(Tablero + 7) + 10) == 20)
			aux = 1;
		break;
	case 'K':
		if (*(*(Tablero + 8) + 2) == 21)
			aux = 1;
		break;

	case 'L':
		if (*(*(Tablero + 8) + 4) == 22)
			aux = 1;
		break;
	case 'M':
		if (*(*(Tablero + 8) + 4) == 23)
			aux = 1;
		break;
	case 'N':
		if (*(*(Tablero + 8) + 8) == 24)
			aux = 1;
		break;

	case 'O':
		if (*(*(Tablero + 8) + 10) == 25)
			aux = 1;
		break;
	case 'P':
		if (*(*(Tablero + 9) + 2) == 26)
			aux = 1;
		break;

	case 'Q':
		if (*(*(Tablero + 9) + 4) == 27)
			aux = 1;
		break;
	case 'R':
		if (*(*(Tablero + 9) + 6) == 28)
			aux = 1;
		break;
	case 'S':
		if (*(*(Tablero + 9) + 8) == 29)
			aux = 1;
		break;

	case 'T':
		if (*(*(Tablero + 9) + 10) == 30)
			aux = 1;
		break;
	case 'U':
		if (*(*(Tablero + 10) + 2) == 31)
			aux = 1;
		break;

	case 'V':
		if (*(*(Tablero + 10) + 4) == 32)
			aux = 1;
		break;
	case 'W':
		if (*(*(Tablero + 10) + 6) == 33)
			aux = 1;
		break;
	case 'X':
		if (*(*(Tablero + 10) + 8) == 34)
			aux = 1;
		break;

	case 'Y':
		if (*(*(Tablero + 10) + 10) == 35)
			aux = 1;
		break;
	}
	return(aux);
}

int confirmar_ficha_disponible_P2(char opcion) {
	int aux=0;
	switch (opcion) {
	case 'A':
		if (*(*(Tablero + 6) + 69) == 11)
			aux = 1;
		break;
	case 'B':
		if (*(*(Tablero + 6) + 71) == 12)
			aux = 1;
		break;
	case 'C':
		if (*(*(Tablero + 6) + 73) == 13)
			aux = 1;
		break;
	case 'D':
		if (*(*(Tablero + 6) + 75) == 14)
			aux = 1;
		break;
	case 'E':
		if (*(*(Tablero + 6) + 77) == 15)
			aux = 1;
		break;
	case 'F':
		if (*(*(Tablero + 7) + 69) == 16)
			aux = 1;
		break;

	case 'G':
		if (*(*(Tablero + 7) + 71) == 17)
			aux = 1;
		break;
	case 'H':
		if (*(*(Tablero + 7) + 73) == 18)
			aux = 1;
		break;
	case 'I':
		if (*(*(Tablero + 7) + 75) == 19)
			aux = 1;
		break;

	case 'J':
		if (*(*(Tablero + 7) + 77) == 20)
			aux = 1;
		break;
	case 'K':
		if (*(*(Tablero + 8) + 69) == 21)
			aux = 1;
		break;

	case 'L':
		if (*(*(Tablero + 8) + 71) == 22)
			aux = 1;
		break;
	case 'M':
		if (*(*(Tablero + 8) + 73) == 23)
			aux = 1;
		break;
	case 'N':
		if (*(*(Tablero + 8) + 75) == 24)
			aux = 1;
		break;

	case 'O':
		if (*(*(Tablero + 8) + 77) == 25)
			aux = 1;
		break;
	case 'P':
		if (*(*(Tablero + 9) + 69) == 26)
			aux = 1;
		break;

	case 'Q':
		if (*(*(Tablero + 9) + 71) == 27)
			aux = 1;
		break;
	case 'R':
		if (*(*(Tablero + 9) + 73) == 28)
			aux = 1;
		break;
	case 'S':
		if (*(*(Tablero + 9) + 75) == 29)
			aux = 1;
		break;

	case 'T':
		if (*(*(Tablero + 9) + 77) == 30)
			aux = 1;
		break;
	case 'U':
		if (*(*(Tablero + 10) + 69)== 31)
			aux = 1;
		break;

	case 'V':
		if (*(*(Tablero + 10) + 71) == 32)
			aux = 1;
		break;
	case 'W':
		if (*(*(Tablero + 10) + 73) == 33)
			aux = 1;
		break;
	case 'X':
		if (*(*(Tablero + 10) + 75) == 34)
			aux = 1;
		break;

	case 'Y':
		if (*(*(Tablero + 10) + 77) == 35)
			aux = 1;
		break;
	}
	return(aux);
}


/*
void mover_ficha_P1() {
	int op;
	char opcion;
	do {
		gotoxy(85, 10);
		cout << "Elija la ficha a mover..." << endl;
		gotoxy(85, 11);
		cin >>opcion;
		opcion = ToupperM(opcion);
		op = confirmar_ficha_disponible_P1(opcion);
	} while (op == 0);

	switch (opcion) {
	case 'A':
		
		break;
	case 'B':
		*(*(Tablero + 5) + 32) = 6;
		*(*(Tablero + 6) + 4) = 1;
		*(*(Tablero + 6) + 71) = 1;
		Ficha_jugador_1--;
		break;
	case 'C':
		*(*(Tablero + 5) + 40) = 6;
		*(*(Tablero + 6) + 6) = 1;
		*(*(Tablero + 6) + 73) = 1;
		Ficha_jugador_1--;
		break;
	case 'D':
		*(*(Tablero + 5) + 48) = 6;
		*(*(Tablero + 6) + 8) = 1;
		*(*(Tablero + 6) + 75) = 1;
		Ficha_jugador_1--;
		break;

	case 'E':
		*(*(Tablero + 5) + 56) = 6;
		*(*(Tablero + 6) + 10) = 1;
		*(*(Tablero + 6) + 77) = 1;
		Ficha_jugador_1--;
		break;
	case 'F':
		*(*(Tablero + 9) + 24) = 6;
		*(*(Tablero + 7) + 2) = 1;
		*(*(Tablero + 7) + 69) = 1;
		Ficha_jugador_1--;
		break;

	case 'G':
		*(*(Tablero + 9) + 32) = 6;
		*(*(Tablero + 7) + 4) = 1;
		*(*(Tablero + 7) + 71) = 1;
		Ficha_jugador_1--;
		break;
	case 'H':
		*(*(Tablero + 9) + 40) = 6;
		*(*(Tablero + 7) + 6) = 1;
		*(*(Tablero + 7) + 73) = 1;
		Ficha_jugador_1--;
		break;
	case 'I':
		*(*(Tablero + 9) + 48) = 6;
		*(*(Tablero + 7) + 8) = 1;
		*(*(Tablero + 7) + 75) = 1;
		Ficha_jugador_1--;
		break;

	case 'J':
		*(*(Tablero + 9) + 56) = 6;
		*(*(Tablero + 7) + 10) = 1;
		*(*(Tablero + 7) + 77) = 1;
		Ficha_jugador_1--;
		break;
	case 'K':
		*(*(Tablero + 13) + 24) = 6;
		*(*(Tablero + 8) + 2) = 1;
		*(*(Tablero + 8) + 69) = 1;
		Ficha_jugador_1--;
		break;

	case 'L':
		*(*(Tablero + 13) + 32) = 6;
		*(*(Tablero + 8) + 4) = 1;
		*(*(Tablero + 8) + 71) = 1;
		Ficha_jugador_1--;
		break;
	case 'N':
		*(*(Tablero + 13) + 48) = 6;
		*(*(Tablero + 8) + 8) = 1;
		*(*(Tablero + 8) + 75) = 1;
		Ficha_jugador_1--;
		break;

	case 'O':
		*(*(Tablero + 13) + 56) = 6;
		*(*(Tablero + 8) + 10) = 1;
		*(*(Tablero + 8) + 77) = 1;
		Ficha_jugador_1--;
		break;
	case 'P':
		*(*(Tablero + 17) + 24) = 6;
		*(*(Tablero + 9) + 2) = 1;
		*(*(Tablero + 9) + 69) = 1;
		Ficha_jugador_1--;
		break;

	case 'Q':
		*(*(Tablero + 17) + 32) = 6;
		*(*(Tablero + 9) + 4) = 1;
		*(*(Tablero + 9) + 71) = 1;
		Ficha_jugador_1--;
		break;
	case 'R':
		*(*(Tablero + 17) + 40) = 6;
		*(*(Tablero + 9) + 6) = 1;
		*(*(Tablero + 9) + 73) = 1;
		Ficha_jugador_1--;
		break;
	case 'S':
		*(*(Tablero + 17) + 48) = 6;
		*(*(Tablero + 9) + 8) = 1;
		*(*(Tablero + 9) + 75) = 1;
		Ficha_jugador_1--;
		break;

	case 'T':
		*(*(Tablero + 17) + 56) = 6;
		*(*(Tablero + 9) + 10) = 1;
		*(*(Tablero + 9) + 77) = 1;
		Ficha_jugador_1--;
		break;
	case 'U':
		*(*(Tablero + 21) + 24) = 6;
		*(*(Tablero + 10) + 2) = 1;
		*(*(Tablero + 10) + 69) = 1;
		Ficha_jugador_1--;
		break;

	case 'V':
		*(*(Tablero + 21) + 32) = 6;
		*(*(Tablero + 10) + 4) = 1;
		*(*(Tablero + 10) + 71) = 1;
		Ficha_jugador_1--;
		break;
	case 'W':
		*(*(Tablero + 21) + 40) = 6;
		*(*(Tablero + 10) + 6) = 1;
		*(*(Tablero + 10) + 73) = 1;
		Ficha_jugador_1--;
		break;
	case 'X':
		*(*(Tablero + 21) + 48) = 6;
		*(*(Tablero + 10) + 8) = 1;
		*(*(Tablero + 10) + 75) = 1;
		Ficha_jugador_1--;
		break;

	case 'Y':
		*(*(Tablero + 21) + 56) = 6;
		*(*(Tablero + 10) + 10) = 1;
		*(*(Tablero + 10) + 77) = 1;
		Ficha_jugador_1--;
		break;
	default:
		cout << "+";
		break;
	}

}
*/

int main() {
	//llamamos a las funciones
	jugador_1 = new jugador;
	jugador_2 = new jugador;
	int Ficha_jugador_1;
	int Ficha_jugador_2;
	int Ficha_j1 = 12;
	int Ficha_j2 = 12;
	Ficha_jugador_1 = Ficha_j1;
	Ficha_jugador_2 = Ficha_j2;
	Reservar_memoria_tablero();
	generar_matriz();
	system("cls");
	imprimir_matriz(Ficha_jugador_1,Ficha_jugador_2);
	crear_jugadores();
	SetConsoleTextAttribute(color, 7);
	imprimir_matriz(Ficha_jugador_1, Ficha_jugador_2);
	Imprime_datos_jugadores();
	Fichas_inicio();
	int i=0;
	Ficha_j1 = 10;
	Ficha_j2 = 10;
	do{		
		Ficha_jugador_1 = Ficha_j1;
		Ficha_jugador_2 = Ficha_j2;
		for (int k = 1 ; k < 3; k++) {
			imprimir_matriz(Ficha_jugador_1, Ficha_jugador_2);
			Imprime_datos_jugadores();
			Ficha_j1 = agregar_ficha_P1(Ficha_jugador_1);
			Ficha_jugador_1 = Ficha_j1;
			imprimir_matriz(Ficha_jugador_1, Ficha_jugador_2);
			Imprime_datos_jugadores();
			i++;
		}	
		for (int k = 1; k < 3; k++) {
			imprimir_matriz(Ficha_jugador_1, Ficha_jugador_2);
			Imprime_datos_jugadores();
			Ficha_j2 = agregar_ficha_P2(Ficha_jugador_2);
			Ficha_jugador_2 = Ficha_j2;
			imprimir_matriz(Ficha_jugador_1, Ficha_jugador_2);
			Imprime_datos_jugadores();
			i++;
		}
	} while (i < 20);
	habilitar_piesa_M();
	Imprimir_piezas_Disponibles_jugadores();
	imprimir_matriz(Ficha_jugador_1, Ficha_jugador_2);

	//liberamos memoriria de la matriz dinamica
	for (int i = 0; i < 25; i++) {
		delete[] Tablero[i];
	}
	delete[] Tablero;
	system("pause");
}