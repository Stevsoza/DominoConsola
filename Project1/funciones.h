#include "struct.h"

void crearfichas(vector <struct domino>& vec) {
	int aumento = 0, llegar = 7, cont = 0, i = 0, cont2 = 0;
	//esta funcion crea las fichas
	vec.resize(28);
	for (int j = 0; j < size(vec); j++) {
		//este for reinicia el vector en contenido 0
		vec[j].izquier = 0;
		vec[j].derecha = 0;
	}

	do {//este ciclo realiza el conteo del valor de las fichas
		// y guarda los valores
		//cuenta desde el numero del contador que luego aumenta hasta que llega al maximo que se establece con la variable "llegar"
		//esta variable decrece por lo tanto realizara el conteo como el domino de sus fichas
		if (cont2 == llegar) {
			llegar--;
			aumento++;
			cont = aumento;
			cont2 = 0;
		}
		vec[i].izquier = aumento;
		vec[i].derecha = cont;
		cont++;
		cont2++;
		i++;
	} while (i < 28);
}


void repartirfichas(vector <struct domino>& vec, vector<struct domino>& play) {
	//esta funcion nos reparte todas las fichas a los 4 jugadores
	//de manera aleatoria
	int indice = 0;
	srand(time(NULL));

	for (int i = 0; i < 7; i++) {
		play.resize(size(play) + 1);//cambiando el tamaño del vector y luego borrando la ficha del vector de las fichas
		indice = rand() % size(vec);
		play[size(play) - 1].izquier = vec[indice].izquier;
		play[size(play) - 1].derecha = vec[indice].derecha;
		vec[indice].izquier = vec[size(vec) - 1].izquier;
		vec[indice].derecha = vec[size(vec) - 1].derecha;
		vec.pop_back();
	}
}

void mostrarfichasp(vector<struct domino> play, int jugador) {
	cout << "\n\n\tFichas Jugador " << jugador << "\n\n\t";
	//esta funcion muestra las fichas de cada jugador
	for (int i = 0; i < size(play); i++) {
		cout << "[ " << play[i].izquier << " | " << play[i].derecha << " ]";
	}
}

void colocarFicha(vector<struct domino>& table, vector<struct domino>& play, int opcion) {
	table.resize(size(table) + 1);//se cambia el tamaño del vector cada que se va a ingresar una nueva ficha
	int op = 0;
	//esta funcion guarda la ficha en el tablero de juego actual
	if (size(table) == 1) {
		//este if se realiza si es la primera vez que vamos a ingresar una ficha
		table[size(table) - 1].izquier = play[opcion - 1].izquier;
		table[size(table) - 1].derecha = play[opcion - 1].derecha;
		play.erase(play.begin() + opcion - 1);//borra la ficha agregada ya al tablero
	}


	if (size(table) > 1) {
		//este if se realiza si ya hay ficha colocada
		if (play[opcion - 1].izquier == table[size(table) - 2].derecha && play[opcion - 1].izquier == table[0].izquier || play[opcion - 1].derecha == table[size(table) - 2].derecha && play[opcion - 1].derecha == table[0].izquier) {
			//se realiza comprobacion para saber si se puede elegir lado de colocacion de ficha
			do {
				cout << "\n\n\tDonde quiere posicionar su ficha?... izquierda digite 1, Derecha digite 2\n\n\t";
				cin >> op;
			} while (op < 1 || op > 2);
		}
		//se asignara la ficha dependiendo se cumplas las siguientes condiciones
		if (table[size(table) - 2].derecha == play[opcion - 1].izquier && op == 0) {
			//las comprobaciones revisan si los numeros coinciden
			//dependiendo donde este la coincidencia podrian realizarce cambios de lado para asi se vea como el domino
			table[size(table) - 1].izquier = play[opcion - 1].izquier;
			table[size(table) - 1].derecha = play[opcion - 1].derecha;
			play.erase(play.begin() + opcion - 1);
		}
		else if (table[size(table) - 2].derecha == play[opcion - 1].derecha && op == 2) {
			table[size(table) - 1].derecha = play[opcion - 1].izquier;
			table[size(table) - 1].izquier = play[opcion - 1].derecha;
			play.erase(play.begin() + opcion - 1);
		}
		else if (table[size(table) - 2].derecha == play[opcion - 1].izquier && op == 2) {
			table[size(table) - 1].derecha = play[opcion - 1].derecha;
			table[size(table) - 1].izquier = play[opcion - 1].izquier;
			play.erase(play.begin() + opcion - 1);
		}
		else if (table[size(table) - 2].derecha == play[opcion - 1].derecha && op == 0) {
			table[size(table) - 1].izquier = play[opcion - 1].derecha;
			table[size(table) - 1].derecha = play[opcion - 1].izquier;
			play.erase(play.begin() + opcion - 1);
		}
		else if (table[0].izquier == play[opcion - 1].izquier && op == 0) {
			for (int i = size(table) - 1; i > 0; i--) {
				table[i].izquier = table[i - 1].izquier;
				table[i].derecha = table[i - 1].derecha;
			}
			table[0].izquier = play[opcion - 1].derecha;
			table[0].derecha = play[opcion - 1].izquier;
			play.erase(play.begin() + opcion - 1);
		}
		else if (table[0].izquier == play[opcion - 1].izquier && op == 1) {
			for (int i = size(table) - 1; i > 0; i--) {
				table[i].izquier = table[i - 1].izquier;
				table[i].derecha = table[i - 1].derecha;
			}
			table[0].izquier = play[opcion - 1].derecha;
			table[0].derecha = play[opcion - 1].izquier;
			play.erase(play.begin() + opcion - 1);
		}
		else if (table[0].izquier == play[opcion - 1].derecha && op == 1) {
			for (int i = size(table) - 1; i > 0; i--) {
				table[i].izquier = table[i - 1].izquier;
				table[i].derecha = table[i - 1].derecha;
			}
			table[0].derecha = play[opcion - 1].derecha;
			table[0].izquier = play[opcion - 1].izquier;
			play.erase(play.begin() + opcion - 1);
		}
		else if (table[0].izquier == play[opcion - 1].derecha && op == 0) {
			for (int i = size(table) - 1; i > 0; i--) {
				table[i].izquier = table[i - 1].izquier;
				table[i].derecha = table[i - 1].derecha;
			}
			table[0].izquier = play[opcion - 1].izquier;
			table[0].derecha = play[opcion - 1].derecha;
			play.erase(play.begin() + opcion - 1);
		}
	}
}

void mostrarOpciones(vector<int> opes, vector<struct domino> play) {
	cout << "\n\tFichas Disponibles a colocar";
	//esta funcion muestra solo las opciones que coinciden los numeros
	for (int i = 0; i < size(play); i++) {
		for (int j = 0; j < size(opes); j++) {
			if (opes[j] == i + 1) {
				cout << "\n\n\tficha " << i + 1 << " [ " << play[i].izquier << " | " << play[i].derecha << " ] \n";
			}
		}
	}
}

void mostrarTablero(vector<struct domino> mesa) {
	cout << "\n\n\tMostrando Tablero actual\n\n\t";
	//esta funcion muestra el tablero mediante un ciclo for
	for (int i = 0; i < size(mesa); i++) {
		cout << "[ " << mesa[i].izquier << " | " << mesa[i].derecha << " ]";
		if ((i + 1) % 10 == 0) {
			cout << "\n\t";
		}
	}
	cout << "\n\n\t";
}

void revisarNumerosExtremos(vector <struct domino> mesa, int& n1, int& n2) {
	//se asignan los valor de los extremos a las variables para luego comparalos
	n1 = mesa[0].izquier;
	n2 = mesa[size(mesa) - 1].derecha;
}

void compararMesaFichasJ(int n1, int n2, vector <struct domino> play, vector<int>& op) {
	//esta funcion compara las opciones 
	//si coiniciden los numeros se guarda en el vector de opciones para luego 
	op.resize(0);
	bool siEsta = false;
	for (int i = 0; i < size(play); i++) {
		if (n1 == play[i].derecha || n1 == play[i].izquier) {
			op.push_back(i + 1);
		}
	}
	for (int i = 0; i < size(play); i++) {
		siEsta = false;
		if (n2 == play[i].derecha || n2 == play[i].izquier) {
			for (int j = 0; j < size(op); j++) {
				//este for anidado se realiza para que no hayan opciones repetidas
				if (op[j] == i + 1) {
					siEsta = true;
				}
			}
			if (siEsta == false) {
				//sino se repite, se guarda la opcion
				op.push_back(i + 1);
			}
		}
	}
}

bool saberSiGano(vector<struct domino> play) {
	//esta funcion nos retorna ganador si el jugador ya no tiene fichas
	bool respuesta = false;
	if (size(play) == 0) {
		respuesta = true;
	}
	else {
		respuesta == false;
	}
	return respuesta;
}

void revisarPuntuacion(vector<struct domino> player, int jugador, string& ganador, int& menorSuma) {
	int suma = 0;
	//esta funcion nos hace las suma para saber cual gano por medio de puntuacion, el menor siempre sera el ganador
	if (size(player) > 0) {
		for (int i = 0; i < size(player); i++) {
			suma += player[i].izquier;
			suma += player[i].derecha;
		}
		if (suma < menorSuma) {
			menorSuma = suma;
			ganador = "EL ganador el es jugador " + to_string(jugador) + " con una suma  de " + to_string(menorSuma);
		}
	}
}