#include <iostream>
using namespace std;

template<class T>
struct Vector{

    int ELEM;
    int TAM = 6;

    T* ARR = new T[TAM];

    Vector(){
        ELEM = 0; 
    }

    ~Vector(){
        delete[] ARR;
    }


    void colapse(); // YA

    void expand(); // YA

    void push_front(T valor);  //YA

    void push_back(T valor); //YA
    void pop_front();  //YA
    void pop_back(); //YA

    T& operator[](int valor); //ya ta 

    T& front(); // ya ta
    T& back(); // ya ta 

    void print(); //ya ta

};

template<class T>
void Vector<T>::expand(){
    TAM*=2;
    T* ARR_E = new T[TAM];

    T* p = ARR;
    T* q = ARR_E;

    T* fin = ARR + ELEM;

    while(p < fin){
        *q = *p; 
        p++;
        q++;
    }

    delete[] ARR;
    ARR = ARR_E;
}

template<class T>
void Vector<T>::colapse(){

    if(TAM <= 6) return;
    TAM/=2;

    T* ARR_C = new T[TAM];

    T* p = ARR;
    T* fin_ARR = ARR + ELEM;
    T* q = ARR_C;

    while(p < fin_ARR){

        *q = *p;
        p++;
        q++;

    }

    delete[] ARR;

    ARR = ARR_C;

}

template<class T>
void Vector<T>::push_back(T valor){

    if(ELEM == TAM){
        expand();
    }

    T* p = ARR;

    *(p + ELEM) = valor;

    ELEM++;

}

template<class T>
void Vector<T>::push_front(T valor){

    if(ELEM == TAM){
        expand();
    }

    T* p = ARR;
    T* q = ARR + ELEM;
    while(p < q){

        *q = *(q - 1);
        q--;

    }

    *p = valor;

    ELEM++;

}

template<class T>
void Vector<T>::pop_back(){
    if(ELEM == 0){
        cout<<"VACIO! nada que sacar."<<endl;
        return;
    }
    
    ELEM--;

    if(ELEM <= TAM / 2){
         // 2 <= 3
        colapse();
    }
}

template<class T>
void Vector<T>::pop_front(){

    if(ELEM == 0){
        cout<<"NADA QUE SACAR, VACIO!"<<endl;
        return;       
    }

    T* p = ARR;
    T* q = ARR + ELEM - 1;

    while(p < q){

        *p = *(p + 1);
        p++;
    }

    ELEM--;

    if(ELEM <= TAM/2){
        colapse();
    }

}


template<class T>
T& Vector<T>::operator[](int valor){
    return *(ARR + valor);
}

template<class T>
T& Vector<T>::front(){

    return *ARR;

}

template<class T>
T& Vector<T>::back(){

    return *(ARR+ELEM-1);
}



template<class T>
void Vector<T>::print(){
    T* p = ARR;
    T* q = ARR + ELEM;

    while(p < q){
        cout<< *p <<" ";
        p++;
    }

    cout<<endl;
    
}


/*

/*
 * TAREA 3: Conversión de Expresión Infija a Postfija (RPN) y Evaluación
 *
 * ---------------------------------------------------------------------
 * PRIMERA PARTE: Conversión Infija -> Postfija
 * ---------------------------------------------------------------------
 * - Estructura: 
 *   Uso de vectores (el vector principal debe comportarse como una PILA).
 *   Se requiere implementar el algoritmo usando TEMPLATES.
 *
 * - Formato de las expresiones:
 *   Solo operandos de 1 DÍGITO para simplificar el parseo durante la conversión.
 *
 * - Reglas de flujo:
 *   1. NUMEROS/OPERANDOS -> Pasan directo al DESPLIEGUE (funciona como una COLA).
 *   2. SIGNOS/OPERADORES -> Van a la PILA.
 *   3. PARÉNTESIS QUE CIERRA ')' -> Realiza 'pop' a la PILA enviando los elementos
 *      al DESPLIEGUE hasta encontrar el PARÉNTESIS QUE ABRE '('.
 *   4. FIN DE LA ENTRADA -> Se extrae todo lo restante de la PILA y se pasa al DESPLIEGUE.
 *
 * - Ejemplo:
 *   Entrada (Infija) : -(3+5) * (7-4)
 *   Salida (Postfija): 3 5 + 7 4 - *
 *
 * ---------------------------------------------------------------------
 * SEGUNDA PARTE: Evaluación de la Expresión Postfija
 * ---------------------------------------------------------------------
 * - Operación:
 *   Usando la expresión postfija obtenida, se evalúa para obtener el resultado final.
 *   Para esta etapa de cálculo sí se opera con todos los dígitos completos.
 *
 * - Reglas de evaluación (usando la PILA):
 *   1. Si NO ES OPERADOR (es número) -> Se ingresa a la PILA.
 *   2. Si LLEGA UN OPERADOR -> Se sacan dos operandos de la PILA y se aplica la operación.
 *   
 * - Orden de operandos (¡MUCHO CUIDADO!):
 *   Al hacer pop:
 *     op2 = pop()
 *     op1 = pop()
 *   Para '7 - 4 = 3' (CORRECTO), la operación debe ser: op1 - op2.
 *   (Revisar la corrección hecha por el profesor sobre la diapo del Moodle).
 *
 * ---------------------------------------------------------------------
 * ENTREGABLE
 * ---------------------------------------------------------------------
 * 1. Ingresar expresión infija.
 * 2. Convertir y evaluar.
 * 3. Desplegar el resultado final.
 *
 * Nota: Revisar el PPTX subido al Moodle.
 *
 * La cumbia de los minions
 */



int main() {

}