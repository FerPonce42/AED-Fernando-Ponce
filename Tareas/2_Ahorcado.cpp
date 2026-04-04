/*
	TAREA 2: AHORCADO CON CTRL Z

	Juego clasico del ahorcado con sistema de retroceso.

	REGLAS BASE:
	- 15 vidas, -1 por cada error
	- 10 palabras de diferente longitud (max 30 caracteres)
	- La palabra se elige al azar cada partida
	- No es necesario dibujar el ahorcado

	SISTEMA DE RETROCESO (Ctrl Z):
	- Tecla especial: *
	- Permite deshacer el ultimo movimiento (retrocede TODO lo del turno)
	- Memoria de hasta 10 estados hacia atras
	- Si llevas 11 movimientos, ya no puedes retroceder el primero
	- Lo mas reciente se recuerda, lo mas lejano se olvida
	- NO es pila, NO es cola. Estructura fija de 10 estados.

	EL RETO:
	Como guardar y restaurar los 10 estados del juego?
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Estado {

	string palabra_progreso = "";
	int vidas = 0;

};


struct Ahorcado {
	int vidas;
	string* arreglo_palabras;
	char letra;
	string palabra_actual;
	bool letra_acertada;
	string palabra_progreso;

	Estado historial[10];
	int indice_historial;


	Ahorcado();
	~Ahorcado();

	bool RecibirLetra(char letraopcion);

	void MarcarAciertos();

	bool VerificarVictoria();

	void CtrlZ();

};

Ahorcado::Ahorcado() {
	vidas = 15;
	arreglo_palabras = new string[10]{ "AMBIENTE", "FERROCARRIL", "CELULAR", "ELEFANTE", "UNIVERSIDAD", "SANPABLO", "CHOCOLATE", "PIZARRA", "MONITOR", "AHORCADO" };

	letra = '\0';

	palabra_actual = "";
	letra_acertada = false;
	palabra_progreso = "";

	indice_historial = 0;

	srand(time(NULL));
	int indice = rand() % 10;
	palabra_actual = arreglo_palabras[indice];

	for (int i = 0; i < palabra_actual.length(); i++) {
		palabra_progreso += "_";
	}
}

Ahorcado::~Ahorcado() {
	delete[] arreglo_palabras;
}

bool Ahorcado::RecibirLetra(char letraopcion) {

	historial[indice_historial].palabra_progreso = palabra_progreso;
	historial[indice_historial].vidas = vidas;
	indice_historial = (indice_historial + 1) % 10;

	letra = letraopcion;

	letra_acertada = false;

	for (int i = 0; i < palabra_actual.length(); i++) {
		if (letra == palabra_actual[i]) {
			letra_acertada = true;
			palabra_progreso[i] = letra;
		}
	}

	if (letra_acertada == false) {
		vidas--;
		cout << "Ups! -1 vida!" << endl;
	}

	return letra_acertada;
}

void Ahorcado::MarcarAciertos() {
	cout << palabra_progreso << endl;
}

bool Ahorcado::VerificarVictoria() {
	for (int i = 0; i < palabra_progreso.length(); i++) {
		if (palabra_progreso[i] == '_') {
			return false;
		}
	}

	return true;
}



void Ahorcado::CtrlZ() {
	int indice_anterior = (indice_historial + 9) % 10;

	palabra_progreso = historial[indice_anterior].palabra_progreso;
	vidas = historial[indice_anterior].vidas;

	indice_historial = indice_anterior;
}



int main() {

	Ahorcado juego1;

	char letraopcion = '\0';

	cout << "\n===============================" << endl;
	cout << "         AHORCADO" << endl;
	cout << "===============================" << endl;
	cout << "Palabra: " << juego1.palabra_progreso << endl;

	while ((juego1.vidas > 0) && (juego1.VerificarVictoria() == false)) {
		cout << "\n-------------------------------" << endl;
		cout << "Vidas: " << juego1.vidas << " / 15" << endl;
		cout << "Ingresa una letra (* para retroceder): "; cin >> letraopcion;

		if (letraopcion == '*') {
			juego1.CtrlZ();
		}
		else {
			juego1.RecibirLetra(letraopcion);
		}

		cout << "Palabra: ";
		juego1.MarcarAciertos();
	}

	cout << "\n===============================" << endl;
	if (juego1.VerificarVictoria()) {
		cout << "GANASTE! La palabra era: " << juego1.palabra_actual << endl;
	}
	else {
		cout << "PERDISTE! La palabra era: " << juego1.palabra_actual << endl;
	}
	cout << "===============================" << endl;
}