#include <iostream> 
using namespace std;
/*
int main(){

    char c = 'a';
    char* p = &c;

    char c2 = *p;

    cout<< c2;
}
*/

/*
- Un array de 5 enteros con los valores que quieras
- Un puntero que apunte al inicio del array
- Recorre todo el array usando SOLO aritmética de punteros (sin usar [])
- Imprime cada valor
*/
/*
int main(){

    int arr[5] = {1,2,3,4,5};

   

    for(int *p = arr ; p < arr + 5 ; p++){

        cout<< *p << " ";
    }

}
*/

/*
- Sin usar p++
- Avanza usando p + i con un índice i
- Imprime solo los valores en posiciones pares (0, 2, 4)
*/
/*
int main(){

    int arr[5] = {1,2,3,4,5};

    int i = 2;
    for(int *p = arr ; p < arr + 5 ; p = p + i){
        cout << *p << " ";
    }
}

*/