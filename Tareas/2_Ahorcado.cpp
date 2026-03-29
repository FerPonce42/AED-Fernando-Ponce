#include <iostream>
using namespace std;

/*Tarea Nueva:

Tal cual el profesor:

Típico juego del ahorcado…
No es necesario dibujar.

Vidas: 15
Con cada error: -1 vida

En una estructura de datos:
10 palabras (de diferente longitud)
Longitud máxima: 30

Al azar en cada juego eliges una.

EJEMPLO:

Palabra X:

Letra: ?

Letra P
P _ _ _ _

Letra O
P _ _ _ _
No está, entonces vida -1
P _ _ _ _

O ← Se pinta esto para que el usuario no meta la pata.

Vamos a hacer un juego con trampa, un ahorcado con Ctrl Z.

¿Cómo así?
Que el control Z tenga, no sé, una tecla *
Con eso puedes retroceder en caso de que te equivocaste.

Por ende, si te equivocaste, regresas.

Ejemplo:
TODO se retrocede, retrocede TODO lo que hiciste en ese movimiento.

Básicamente el sistema va a memorizar 10 estados.
Si haces 11 movimientos, ya no puedes retroceder más. O sea, tiene límite.

EL RETO ES:
¿Cómo haces para retroceder los estados?

Nos dijo:
10 palabras = 10 elementos del array

Cosas a considerar:

Si metes: A B C D E F G H I J K L M N…
Si haces ese famoso control Z, vas retrocediendo esas veces que la cagaste.

Te quedas en ABC, por lo que solo te acuerdas de C.

Lo más lejano es lo que te olvidas.
Lo más cercano es lo que recordarás.

Básicamente recuerda 10 hacia atrás.

NO es como pila.
NO es como cola. Va por ahí.

Invariable es eso de 10 estados, o sea que es un número fijo.*/


struct Ahorcado {
int vidas;
string* palabras;
int cant_estado;
char letra;

Ahorcado();
~Ahorcado();

void RecibirLetra(char letraopcion);


};


Ahorcado::Ahorcado() {
vidas = 15;
palabras = new string[10]{ "AMBIENTE", "FERROCARRIL", "CELULAR", "ELEFANTE", "UNIVERSIDAD", "SANPABLO", "CHOCOLATE", "PIZARRA", "MONITOR", "AHORCADO" };
cant_estado = 10;
letra = 'A';

}

Ahorcado::~Ahorcado() {
delete[] palabras;
}



void Ahorcado::RecibirLetra(char letraopcion) {
letra = letraopcion;
cout << "Letra Actual: "<< letra << endl;
}







int main() {

Ahorcado juego1;

char letraopcion;
cout << "Letra: "; cin >> letraopcion;
juego1.RecibirLetra(letraopcion);

}