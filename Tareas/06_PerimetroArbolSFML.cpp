#include <iostream>
#include <initializer_list>
#include <stack>
#include <map>
#include <vector>
#include <SFML/Graphics.hpp>
using namespace std;

struct Node
{
    int value;
    Node* nodes[2];
    Node(int v) { value = v; nodes[0] = nodes[1] = nullptr; }
};

#include "dibujar.h"

class CBinTree
{
public:
    Node* root;
    CBinTree() { root = nullptr; }

    bool find(int x, Node**& p)
    {
        for (p = &root; *p && (*p)->value != x;
            p = &((*p)->nodes[x > (*p)->value]));
        return *p && (*p)->value == x;
    }
    bool ins(int x)
    {
        Node** p;
        if (find(x, p)) return 0;
        *p = new Node(x);
        return 1;
    }
    void ins(initializer_list<int> values)
    {
        for (int x : values) ins(x);
    }
    void inorder(Node* n)
    {
        if (n == nullptr) return;
        inorder(n->nodes[0]);
        cout << n->value << " ";
        inorder(n->nodes[1]);
    }

    vector<Node*> perimeter()
    {
        vector<Node*> resultado;
        if (root == nullptr) {
            return resultado;
        }

        // BORDE IZQUIERDO (raiz incluida, hojas excluidas)
        Node* p = root;
        while (p != nullptr) {
            bool es_hoja = p->nodes[0] == nullptr && p->nodes[1] == nullptr;
            if (!es_hoja) {
                resultado.push_back(p);
            }
            if (p->nodes[0] != nullptr) {
                p = p->nodes[0];
            }
            else {
                p = p->nodes[1];
            }
        }

        // BORDE INFERIOR: hojas de izq a der
        stack<Node*> pila;
        pila.push(root);
        while (!pila.empty()) {
            Node* n = pila.top(); pila.pop();
            bool es_hoja = n->nodes[0] == nullptr && n->nodes[1] == nullptr;
            if (es_hoja) {
                resultado.push_back(n);
            }
            else {
                if (n->nodes[1] != nullptr) pila.push(n->nodes[1]);
                if (n->nodes[0] != nullptr) pila.push(n->nodes[0]);
            }
        }

        // BORDE DERECHO: camino der en stack, se imprime al reves
        stack<Node*> camino;
        p = root->nodes[1];
        while (p != nullptr) {
            bool es_hoja = p->nodes[0] == nullptr && p->nodes[1] == nullptr;
            if (!es_hoja) {
                camino.push(p);
            }
            if (p->nodes[1] != nullptr) {
                p = p->nodes[1];
            }
            else {
                p = p->nodes[0];
            }
        }
        while (!camino.empty()) {
            resultado.push_back(camino.top());
            camino.pop();
        }

        return resultado;
    }
};

int main()
{
    CBinTree t;
    t.ins({ 50,
            30, 70,
            20, 40, 60, 80,
            15, 25, 35, 45, 55, 65, 75, 90,
            12, 17, 22, 28, 32, 38, 42, 48, 52, 58, 62, 68, 72, 78, 85, 95 });

    sf::Font font;
    if (!font.openFromFile("C:/Windows/Fonts/arial.ttf")) {
        cout << "No se pudo cargar Arial\n";
        return -1;
    }

    map<Node*, sf::Vector2f> posiciones;
    int contador = 0;
    calcularPosiciones(t.root, 0, contador, 50.f, 80.f, posiciones);

    // CENTRAR horizontalmente
    float minX = 999999.f, maxX = 0.f;
    for (auto& par : posiciones) {
        if (par.second.x < minX) minX = par.second.x;
        if (par.second.x > maxX) maxX = par.second.x;
    }
    float anchoArbol = maxX - minX;
    sf::Vector2u tamano = calcularTamanoVentana(posiciones);
    float offsetX = (tamano.x - anchoArbol) / 2.f - minX;
    for (auto& par : posiciones) {
        posiciones[par.first].x += offsetX;
    }

    sf::RenderWindow window(sf::VideoMode(tamano), "06_Perimetro_ArbolSFML");

    vector<Node*> perim = t.perimeter();

    while (window.isOpen()) {
        while (const auto evento = window.pollEvent()) {
            if (evento->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        window.clear(sf::Color::White);
        drawTree(t.root, window, font, posiciones);
        highlightNodos(perim, window, font, posiciones);
        window.display();
    }

    return 0;
}