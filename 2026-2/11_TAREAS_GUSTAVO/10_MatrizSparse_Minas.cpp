/*

El profe comenzó a dibujar una matriz.
de 7 columnas por  7 filas


El jueguito:


Es como un BUSCA MINAS... parecido.

Pero ustedes van a armar el tablero en una matriz espartana...

7x7...

En tonces vas a poner 7 minas.

REGLAS:

1. NO hay MINA en la misma FILA.
2. NO hay MINA en la misma COLUMNA.
3. Las MINAS NO se TOCAN.


EJEMPLO:

Minas de manera aleatoria.

1
    1 <- No ponerlo en diagonal. pues estaria cerca.

1   '
    '
        1 Aqui si podria ir.


        pero qeu eso no defina ya que
        recuerda que tiene que saber donde meter las minas.
        ni muy cerca y asi. (ADJUNTO FOTO DEL O QUE EL ESPERARIA)

7x7

- - - - - - -
- - - - - - -
- - - - - - -
- - - - - - -
- - - - - - -
- - - - - - -
- - - - - - -


====


7x7 , los - son espacios, no meter ceros ahi no seas webon.

1 - - - - - -
- - - - - 1 -
- - 1 - - - -
- - - - - - 1
- - - - 1 - -
- 1 - - - - -
- - - 1 - - -


Tiene que funcioanr con 9x9, 8x8 etc.

CONSEJO: "Es parecido al problema de las 9 reinas, ES PARECIDO... pero no es igual. Consderando nuestra reglas."

ADEMAS, le presentas el ESPARSA (que felizmente ya lo construi)



*/



#include <iostream>
#include <assert.h>
#include <cstdlib>
#include <ctime>
#include "tablero.h"
using namespace std;

class CNode {

public:

	int value;
	int fila;
	int columna;

	CNode* next;
	CNode* down;

	CNode(int v, int f, int c) {
		next = nullptr;
		down = nullptr;
		value = v;
		fila = f;
		columna = c;
	}
};


class MatrizV3; // declarar que mas abajo esta todo el cuerpo.

struct CX {

	int fila;
	int columna;
	MatrizV3* pm;

	CX(MatrizV3* mv3, int f, int c) {

		pm = mv3; // guardamos el objeto del main
		fila = f;
		columna = c;

	}

	operator int(); // para cuando piden get

	CX& operator= (int v);

};

class MatrizV3 {

private:


	int TAM_F;
	int TAM_C;

	CNode** FILAS;

	CNode** COLUM;


	bool findF(CNode**& p, int f, int c);

	bool findC(CNode**& p, int f, int c);


	bool ins(int v, int f, int c);

	bool rem(int f, int c);



public:



	MatrizV3(int tf, int tc) {
		TAM_F = tf;
		TAM_C = tc;


		FILAS = new CNode * [TAM_F];
		COLUM = new CNode * [TAM_C];


		for (CNode** x = FILAS; x < FILAS + TAM_F; x++) {
			*x = nullptr;
		}

		for (CNode** y = COLUM; y < COLUM + TAM_C; y++) {
			*y = nullptr;
		}

	}

	~MatrizV3() {

		CNode** p = FILAS;
		CNode* pp = nullptr;
		CNode* tmp = nullptr;

		while (p < FILAS + TAM_F) {

			pp = *p;

			while (pp != nullptr) {
				tmp = pp;
				pp = pp->next;
				delete tmp;
			}


			p++;
		}

		delete[] FILAS;
		delete[] COLUM;

	}


	int get(int f, int c);

	void set(int v, int f, int c);

	CX operator()(int f, int c);


};


bool MatrizV3::findF(CNode**& p, int f, int c) {

	p = FILAS + f;

	while (*p && (*p)->columna < c) {
		p = &((*p)->next);
	}

	return *p && (*p)->columna == c;

}

bool MatrizV3::findC(CNode**& p, int f, int c) {

	p = COLUM + c;

	while (*p && (*p)->fila < f) {
		p = &((*p)->down);
	}

	return *p && (*p)->fila == f;

}

bool MatrizV3::ins(int v, int f, int c) {

	CNode** pf;
	CNode** pc;

	if (!findF(pf, f, c) && !findC(pc, f, c)) {

		CNode* nodo = new CNode(v, f, c);
		nodo->next = *pf;
		*pf = nodo;

		nodo->down = *pc;
		*pc = nodo;

		return true;
	}
	else {
		(*pf)->value = v;
		return false;
	}


}

bool MatrizV3::rem(int f, int c) {

	CNode** pf;
	CNode** pc;

	if (findF(pf, f, c) && findC(pc, f, c)) {

		CNode* tmpfc = *pf;

		*pf = (*pf)->next;
		*pc = (*pc)->down;

		delete tmpfc;

		return true;

	}
	else {
		return false;
	}

}


int MatrizV3::get(int f, int c) {

	assert(f >= 0 && c >= 0 && f < TAM_F && c < TAM_C);
	CNode** pf;
	if (findF(pf, f, c)) {
		return (*pf)->value;
	}
	else {
		return 0;
	}

}

void MatrizV3::set(int v, int f, int c) {

	assert(f >= 0 && c >= 0 && f < TAM_F && c < TAM_C);

	if (v == 0) {
		rem(f, c);
	}
	else {
		ins(v, f, c); // el caso de insertar y setear un valor se resolve directamente en ins.
	}


}

// LOGICA PARA LA MATRIZ.
CX MatrizV3::operator()(int f, int c) {

	return CX(this, f, c);

}


//LOGICA QUE ESTA DENTRO DE CX, AL RECIBIR LO QUE LO ANTERIOR LE DIO

CX::operator int() {
	return pm->get(fila, columna);
}


CX& CX::operator= (int v) {

	pm->set(v, fila, columna);

	return *this;
}

// PARA LA TAREA:

bool esSeguro(MatrizV3& m, int n, int f, int c) {

	for (int r = 0; r < f; r++) {
		if (m.get(r, c) != 0) {
			return false;
		}
	}

	if (f > 0) {

		if (c > 0 && m.get(f - 1, c - 1) != 0) {
			return false;
		}

		if (c < n - 1 && m.get(f - 1, c + 1) != 0) {
			return false;
		}
	}

	return true;
}

bool resolver(MatrizV3& m, int n, int f) {

	if (f == n) {
		return true;
	}

	int inicio = rand() % n;

	for (int i = 0; i < n; i++) {

		int c = (inicio + i) % n;

		if (esSeguro(m, n, f, c)) {

			m(f, c) = 1;

			if (resolver(m, n, f + 1)) {
				return true;
			}

			m(f, c) = 0;
		}
	}

	return false;
}

int main() {

	srand(time(0));

	int n;
	cout << "Tamano N: ";
	cin >> n;

	MatrizV3 m(n, n);

	if (!resolver(m, n, 0)) {
		cout << "No hay solucion para N = " << n << endl;
		return 0;
	}

	dibujar(m, n);

	return 0;
}