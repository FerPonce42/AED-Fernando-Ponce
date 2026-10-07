// AED-Luigi-Escaneo.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//


#include <iostream>
#include <vector>
using namespace std;

template<class T>
class Node {
public:
    T val;
    Node<T>* next;

    Node(T v, Node<T>* nxt = nullptr) {
        val = v;
        next = nxt;
    }

};


template<class T>
class LinkedList {

public:
    Node<T>* head = nullptr;

    LinkedList() {}

    void push_front(T val) {

        Node<T>* newNode = new Node<T>(val, head);
        head = newNode;

    }

    void print() {

        cout << "Head -> ";
        for (Node<T>* p = head; p != nullptr; p = p->next) {
            cout << p->val << " -> ";
        }
        cout << "NULL" << endl;

    }


    void sort() {

        // CODEA AQUI :)

        //Necesitamos un caso base: cuando hay 1 o 0 elementos

        Node <T>* p = head;
        // Diferenciar casos nulos 3 mins
        if (!p || !(p->next)) {
            cout << "Lista ordenada/ 1 elemento" << endl;
            return;
        }
        //Cuando si se puede
        Node <T>* r = p->next;
        Node <T>* x = head;;
        int contador = 0;
        while (p && r) {

            if (p->val > r->val) {
               // cout << "x: " << x->val << endl;
                //cout << "p: "<<p->val << endl;
                //cout << "r: "<<r->val << endl;

                if (x == p) {
                    p->next = r->next;
                    r->next = p;

                    head = r;

                     p = head;
                    r = p->next;
                    x = head;
                    contador = 0;
                    print();
                }
                else {
                    (x->next) = r;
                    p->next = r->next;
                    r->next = p;

                    p = head;
                    r = p->next;
                    x = head;
                    contador = 0;
                    print();
                    sort();
                }

            }



            if (contador > 0) {
                x = x->next;
            }
            p = p->next;
            r = r->next;
            contador++;
        }
        print();
        cout << "-------------------------------" << endl;

    }

};


int main() {

    // TEST 1 ------------------------------

    vector<int> nums1 = { 5, 2, 8, 3, 1, 9, 4, 7, 6, 0 };
    LinkedList<int> list1;

    for (int i = 0; i < nums1.size(); ++i) list1.push_front(nums1[i]);

    cout << "\nOrigin Linked List 1:" << endl;
    list1.print();

    list1.sort();

    cout << "\nSorted Linked List 1:" << endl;
    list1.print();




    // TEST 2 ------------------------------

    vector<float> nums2 = { 12.5, 0.8, 15.6, -3.4, 0.0, -12.5, 1.0, 4.7, 6.9, 8.8 };
    LinkedList<float> list2;

    for (int i = 0; i < nums2.size(); ++i) list2.push_front(nums2[i]);

    cout << "\n\nOrigin Linked List 2:" << endl;
    list2.print();

    list2.sort();

    cout << "\nSorted Linked List 2:" << endl;
    list2.print();


    // TEST 3 ------------------------------

    vector<int> nums3 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    LinkedList<int> list3;

    for (int i = 0; i < nums3.size(); ++i) list3.push_front(nums3[i]);

    cout << "\n\nOrigin Linked List 3:" << endl;
    list3.print();

    list3.sort();

    cout << "\nSorted Linked List 3:" << endl;
    list3.print();


    // TEST 4 ------------------------------

    vector<int> nums4 = { 0 };
    LinkedList<int> list4;

    for (int i = 0; i < nums4.size(); ++i) list4.push_front(nums4[i]);

    cout << "\n\nOrigin Linked List 4:" << endl;
    list4.print();

    list4.sort();

    cout << "\nSorted Linked List 4:" << endl;
    list4.print();


    // TEST 5 ------------------------------

    vector<int> nums5;
    LinkedList<int> list5;

    for (int i = 0; i < nums5.size(); ++i) list5.push_front(nums5[i]);

    cout << "\n\nOrigin Linked List 5:" << endl;
    list5.print();

    list5.sort();

    cout << "\nSorted Linked List 5:" << endl;
    list5.print();





    return 0;
}


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
