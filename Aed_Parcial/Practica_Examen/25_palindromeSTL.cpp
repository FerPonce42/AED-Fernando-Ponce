/*
 * Implementa isPalindromo(string s) usando
 * un MyStack y un MyQueue, ambos adaptadores de std::deque.
 * MyStack: push, pop, top, empty, size
 * MyQueue: push, pop, front, empty, size
 * Un palíndromo se lee igual de izquierda a derecha
 * que de derecha a izquierda.
 * Ejemplos: oso, radar, reconocer
 */

#include <iostream>
#include <deque>
#include <string>
using namespace std;

template<class T>
class MyStack {
    deque<T> data;
public:
    void push(T x)  { // IMPLEMENTAR
    }
    void pop()      { // IMPLEMENTAR
    }
    T top()         { // IMPLEMENTAR
    }
    bool empty()    { // IMPLEMENTAR
    }
    int size()      { // IMPLEMENTAR
    }
};

template<class T>
class MyQueue {
    deque<T> data;
public:
    void push(T x)  { // IMPLEMENTAR
    }
    void pop()      { // IMPLEMENTAR
    }
    T front()       { // IMPLEMENTAR
    }
    bool empty()    { // IMPLEMENTAR
    }
    int size()      { // IMPLEMENTAR
    }
};

bool isPalindromo(string s) {
    MyStack<char> pila;
    MyQueue<char> cola;
    // IMPLEMENTAR
}

int main() {
    cout << boolalpha;
    cout << isPalindromo("oso")       << endl; // true
    cout << isPalindromo("radar")     << endl; // true
    cout << isPalindromo("reconocer") << endl; // true
    cout << isPalindromo("python")    << endl; // false
    cout << isPalindromo("racecar")   << endl; // true
    cout << isPalindromo("hello")     << endl; // false
}