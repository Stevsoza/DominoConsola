#include "funciones.h"

int main()
{
	vector <struct domino> fichas(0);
	vector <struct domino> mesa(0);
	vector <struct domino> play1(0);
	vector <struct domino> play2(0);
	vector <struct domino> play3(0);
	vector <struct domino> play4(0);
	vector <int> opciones(0);
	bool gano = false, opAdecuada = false, terminoJuego = false;
	int juegoInicio = 0, op = 0, numero1 = 0, numero2 = 0, contNoFichas = 0, sumadeGanador = 50, i = 0;
	string elGanador = "";

	do {//se realizara en un ciclo do-while para tener la opcion de volver a jugar
		system("cls");
		cout << "\n\n\n\n\n\n\n\n\n\t======================JUEGO DOMINO=========================\n\n\n\n\n\n\n\n\n\n\n\t";
		system("pause");
		system("cls");
		cout << "\n\n\tPara Iniciar nuevo Juego digite una 1, para salir digite 2\n\t";
		cin >> juegoInicio;
		switch (juegoInicio) {
		case 1:
			//se reinician las variables cada nuevo juego
			gano = false, opAdecuada = false, terminoJuego = false;
			play1.resize(0), play2.resize(0), play3.resize(0), play4.resize(0), mesa.resize(0), opciones.resize(0);
			sumadeGanador = 50, contNoFichas = 0, i = 0;
			elGanador = " ";
			system("cls");
			//se realizan proceso de creacion de fichas, reparticion de fichas y se muestran todas las fichas...
			//que le toco a cada jugador
			crearfichas(fichas);
			repartirfichas(fichas, play1);
			repartirfichas(fichas, play2);
			repartirfichas(fichas, play3);
			repartirfichas(fichas, play4);
			mostrarfichasp(play1, 1);
			mostrarfichasp(play2, 2);
			mostrarfichasp(play3, 3);
			mostrarfichasp(play4, 4);
			cout << "\n\n\tSe han repartido las fichas\n\n\t";
			system("pause");
			i = 0;
			do {//se ejecutara en un do-while mientras no haya ganador o los jugadores tengan aun fichas para colocar
				if (i == 4) {
					i = 0;
					if (gano == false && terminoJuego == false) {
						contNoFichas = 0;//contador de fichas que se reiniciara si no se ha encontrado ganador...
						//y si aun no  termina el juegos, y si la i llega a 4
					}
				}
				if (i + 1 == 1 && gano == false && terminoJuego == false) {
					//se  realiza mientras no haya ganador o hayan fichas para colocar y la iteracion corresponda al jugador actual
					if (size(mesa) == 0) {
						//se realiza comparacion para saber si es la primera vez que se coloca ficha...
						//si no hay una ficha en el vector de mesa se realizara
						opAdecuada = false;
						do {
							system("cls");
							cout << "\n\n\tTurno Jugador 1";
							if (size(opciones) == 0) {
								//de igual manera si no hay opciones se hara un for para guardar las opciones por defecto...
								// ya que no hay fichas colocadas
								opciones.resize(0);
								for (int j = 0; j < size(play1); j++) {
									opciones.push_back(j + 1);
								}
							}
							system("cls");
							cout << "\n\n\tNo hay fichas en el tablero, jugador 1 seleccionara la primera\n";
							mostrarOpciones(opciones, play1);
							cout << "\n\n\tElija ficha(digite el numero de ficha)\n\n\t";
							cin >> op;
							for (int j = 0; j < size(opciones); j++) {
								//este for realiza la busqueda de la opcion seleccionada, entre las opcione disponibles
								if (op == opciones[j]) {
									opAdecuada = true;
								}
							}
							if (opAdecuada != true) {
								//si no se digita una opcion adecuada se mostrara la advertencia
								//y se realizara de nuevo el ciclo
								system("cls");
								cout << "\n\n\tDigite un numero de ficha valido y que este disponible para colocar\n\n\t";
								system("pause");
							}
						} while (opAdecuada == false);
						//se coloca ficha y se muestra el tablero
						colocarFicha(mesa, play1, op);
						system("cls");
						mostrarTablero(mesa);
						cout << "\n\n\t";
						system("pause");
					}
					else {//si la mesa tiene ficha se realizaran las siguientes acciones
						//se realiza una funcion que busca los numeros de los extremos
						//y se comparan con las fichas del actual jugador
						revisarNumerosExtremos(mesa, numero1, numero2);
						compararMesaFichasJ(numero1, numero2, play1, opciones);
						//la variable opciones nos devuelve si se encontro coindicencias
						if (size(opciones) > 0) {
							//si hay conincidencias se realizaran las siguientes acciones
							opAdecuada = false;
							do {
								system("cls");
								cout << "\n\n\tTurno Jugador 1";
								mostrarfichasp(play1, 1);
								mostrarTablero(mesa);
								mostrarOpciones(opciones, play1);
								cout << "\n\n\tElija ficha(digite el numero de ficha)\n\n\t";
								cin >> op;
								for (int j = 0; j < size(opciones); j++) {
									if (op == opciones[j]) {
										opAdecuada = true;
									}
								}
								if (opAdecuada != true) {
									system("cls");
									cout << "\n\n\tDigite un numero de ficha valido y que este disponible para colocar\n\n\t";
									system("pause");
								}
							} while (opAdecuada == false);
							colocarFicha(mesa, play1, op);
							system("cls");
							//se mostrara el tablero cada que se agregue una ficha
							mostrarTablero(mesa);
							cout << "\n\n\t";
							system("pause");
						}
						else {
							system("cls");
							cout << "\n\n\tTurno Jugador 1";
							mostrarfichasp(play1, 1);
							mostrarTablero(mesa);
							cout << "\n\n\tEste jugador no tiene fichas para colocar, paso de turno a siguiente jugador\n\n\t";
							system("pause");
							contNoFichas++;//este contador aumentara cuando no hayan fichas para colocar si llega a 3 se termina el juego
						}
						gano = saberSiGano(play1);
						if (gano == true) {
							//con la funcion de arriba sabremos si gano y en este condicional se mandara a imprimir el mensaje
							elGanador = "El ganador es el jugador 1";
						}
					}
				}
				if (i + 1 == 2 && gano == false && terminoJuego == false) {
					revisarNumerosExtremos(mesa, numero1, numero2);
					compararMesaFichasJ(numero1, numero2, play2, opciones);
					if (size(opciones) > 0) {
						opAdecuada = false;
						do {
							system("cls");
							cout << "\n\n\tTurno Jugador 2";
							mostrarfichasp(play2, 2);

							mostrarTablero(mesa);
							mostrarOpciones(opciones, play2);
							cout << "\n\n\tElija ficha(digite el numero de ficha)\n\n\t";
							cin >> op;
							for (int j = 0; j < size(opciones); j++) {
								if (op == opciones[j]) {
									opAdecuada = true;
								}
							}
							if (opAdecuada != true) {
								system("cls");
								cout << "\n\n\tDigite un numero de ficha valido y que este disponible para colocar\n\n\t";
								system("pause");
							}
						} while (opAdecuada == false);
						colocarFicha(mesa, play2, op);
						system("cls");
						mostrarTablero(mesa);
						cout << "\n\n\t";
						system("pause");
					}
					else {
						system("cls");
						cout << "\n\n\tTurno Jugador 2";
						mostrarfichasp(play2, 2);
						mostrarTablero(mesa);
						cout << "\n\n\tEste jugador no tiene fichas para colocar, paso de turno a siguiente jugador\n\n\t";
						system("pause");
						contNoFichas++;
					}
					gano = saberSiGano(play2);
					if (gano == true) {
						elGanador = "El ganador es el jugador 2";
					}
				}
				if (i + 1 == 3 && gano == false && terminoJuego == false) {
					revisarNumerosExtremos(mesa, numero1, numero2);
					compararMesaFichasJ(numero1, numero2, play3, opciones);
					if (size(opciones) > 0) {
						opAdecuada = false;
						do {
							system("cls");
							cout << "\n\n\tTurno Jugador 3";
							mostrarfichasp(play3, 3);

							mostrarTablero(mesa);
							mostrarOpciones(opciones, play3);
							cout << "\n\n\tElija ficha(digite el numero de ficha)\n\n\t";
							cin >> op;
							for (int j = 0; j < size(opciones); j++) {
								if (op == opciones[j]) {
									opAdecuada = true;
								}
							}
							if (opAdecuada != true) {
								system("cls");
								cout << "\n\n\tDigite un numero de ficha valido y que este disponible para colocar\n\n\t";
								system("pause");
							}
						} while (opAdecuada == false);
						colocarFicha(mesa, play3, op);
						system("cls");
						mostrarTablero(mesa);
						cout << "\n\n\t";
						system("pause");
					}
					else {
						system("cls");
						cout << "\n\n\tTurno Jugador 3";
						mostrarfichasp(play3, 3);
						mostrarTablero(mesa);
						cout << "\n\n\tEste jugador no tiene fichas para colocar, paso de turno a siguiente jugador\n\n\t";
						system("pause");
						contNoFichas++;
					}
					gano = saberSiGano(play3);
					if (gano == true) {
						elGanador = "El ganador es el jugador 3";
					}
				}
				if (i + 1 == 4 && gano == false && terminoJuego == false) {
					revisarNumerosExtremos(mesa, numero1, numero2);
					compararMesaFichasJ(numero1, numero2, play4, opciones);
					if (size(opciones) > 0) {
						opAdecuada = false;
						do {
							system("cls");
							cout << "\n\n\tTurno Jugador 4";
							mostrarfichasp(play4, 4);
							revisarNumerosExtremos(mesa, numero1, numero2);
							compararMesaFichasJ(numero1, numero2, play4, opciones);
							mostrarTablero(mesa);
							mostrarOpciones(opciones, play4);
							cout << "\n\n\tElija ficha(Digite el numero de ficha)\n\n\t";
							cin >> op;
							for (int j = 0; j < size(opciones); j++) {
								if (op == opciones[j]) {
									opAdecuada = true;
								}
							}
							if (opAdecuada != true) {
								system("cls");
								cout << "\n\n\tDigite un numero de ficha valido y que este disponible para colocar\n\n\t";
								system("pause");
							}
						} while (opAdecuada == false);
						colocarFicha(mesa, play4, op);
						system("cls");
						mostrarTablero(mesa);
						cout << "\n\n\t";
						system("pause");
					}
					else {
						system("cls");
						cout << "\n\n\tTurno Jugador 4";
						mostrarfichasp(play4, 4);
						mostrarTablero(mesa);
						cout << "\n\n\tEste jugador no tiene fichas para colocar, paso de turno a siguiente jugador\n\n\t";
						system("pause");
						contNoFichas++;
					}
					gano = saberSiGano(play4);
					if (gano == true) {
						elGanador = "El ganador es el jugador 4";
					}
				}
				if (contNoFichas > 3) {
					//si el contador llega a 3 se procede a la revision de puntajes, gana el que tiene menos
					terminoJuego = true;
					revisarPuntuacion(play1, 1, elGanador, sumadeGanador);
					revisarPuntuacion(play2, 2, elGanador, sumadeGanador);
					revisarPuntuacion(play3, 3, elGanador, sumadeGanador);
					revisarPuntuacion(play4, 4, elGanador, sumadeGanador);
				}
				i++;
			} while (gano == false && terminoJuego == false);
			system("cls");
			//cuando se obtiene ganardor se imprime
			//y se muestra las fichas con las que quedo cada jugador al final
			cout << "\n\n\t" << elGanador;
			mostrarfichasp(play1, 1);
			mostrarfichasp(play2, 2);
			mostrarfichasp(play3, 3);
			mostrarfichasp(play4, 4);
			cout << "\n\n\t";
			system("pause");
			break;
		case 2:
			system("cls");
			cout << "\n\n\tHasta luego! Espero te hayas divertido";
			break;
		}
	} while (juegoInicio != 2);
	cout << "\n\n\n\n\n";


	return 0;
}
