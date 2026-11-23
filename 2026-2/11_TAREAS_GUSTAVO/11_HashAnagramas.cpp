/*
Ultima tarea de AED:

Tu tu tabla hash en tu momento lo hiciste con ints... ahora..
Hash - Classificcacion:

de ANAGRAMAS...? que chucha es eso.


Hacer una tabla hash...

[ "eat", "tea", "ate", "nat", "tam", "bat"]

Ustedes tienen una tabla hash. Se supone que todos los que no se que.
Entonces lo que tienen que hacer HACER LA TABLA y la FUNCION

La funcion idnentifica tiene que identificar que son anagramas (palabras quetienen las miams letras)


Entonces la tabla hash lo clasificaria asi:

[ "eat", "tea", "ate"]
["nat", "tan"]
["bat"]


Eso es lo que tienes que hacer.
Es... dificultad media.
--------------------------------------------------------



*/


#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;


class HashV4 {

private:

    int tam;
    vector<list<string>> v;

public:

    HashV4(int t) {

        tam = t;

        v.assign(tam, list<string>());
    }


    int hash(string x);

    bool esAnagrama(string a, string b);

    void insertar(string x);

    void mostrar();


};


int HashV4::hash(string x) {

    int cant_car = 0;

    for (int i = 0; i < x.length(); i++) {
        cant_car = cant_car + x[i];
    }

    int pos = cant_car % tam;

    return pos;

}


bool HashV4::esAnagrama(string a, string b) {

    // ordena las letras de las dos palabras: si quedan iguales, tenian las mismas letras
    // se comparan dos porque el hash solo dice "misma suma", no "mismas letras"
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    return a == b;

}


void HashV4::insertar(string x) {

    int i = hash(x);

    for (auto j = v[i].begin(); j != v[i].end(); j++) {

        if (esAnagrama(x, *j)) {

            while (j != v[i].end() && esAnagrama(x, *j)) {
                j++;
            }

            v[i].insert(j, x);
            return;
        }
    }

    v[i].push_back(x);

}


void HashV4::mostrar() {

    for (int i = 0; i < tam; i++) {

        cout << "[" << i << "]  =  ";

        bool inicio = true;

        for (auto j = v[i].begin(); j != v[i].end(); j++) {

            if (inicio) {
                cout << "[ ";
            }

            cout << "\"" << *j << "\"";

            auto sig = j;
            sig++;

            if (sig != v[i].end() && esAnagrama(*j, *sig)) {
                cout << ", ";
                inicio = false;
            }
            else {
                cout << " ]  ";
                inicio = true;
            }
        }

        cout << endl;
    }

}


int main() {

    cout << "===== PIZARRA =====" << endl;

    HashV4 pizarra(7);

    pizarra.insertar("eat");
    pizarra.insertar("tea");
    pizarra.insertar("ate");
    pizarra.insertar("nat");
    pizarra.insertar("tan");
    pizarra.insertar("bat");

    pizarra.mostrar();

    cout << endl;


    cout << "===== CASOS RAROS =====" << endl;

    HashV4 tabla(7);

    // los de la pizarra
    tabla.insertar("eat");
    tabla.insertar("tea");
    tabla.insertar("ate");
    tabla.insertar("nat");
    tabla.insertar("tan");
    tabla.insertar("bat");

    // misma suma pero NO son anagramas, mezclados a proposito
    tabla.insertar("ad");
    tabla.insertar("bc");
    tabla.insertar("da");
    tabla.insertar("cb");

    // palabra repetida
    tabla.insertar("eat");

    // una letra sola, cae en el mismo bucket que eat
    tabla.insertar("a");

    // mayuscula (no es anagrama de "eat")
    tabla.insertar("Eat");

    // palabra vacia
    tabla.insertar("");

    tabla.mostrar();

    cout << endl;


    cout << "===== TABLA DE TAMANO 1 =====" << endl;

    HashV4 una(1);

    una.insertar("eat");
    una.insertar("bat");
    una.insertar("tea");
    una.insertar("tab");

    una.mostrar();

    return 0;
}