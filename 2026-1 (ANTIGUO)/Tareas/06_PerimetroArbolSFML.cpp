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

#include "Dibujar.h"

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

        Node* p = root;
        while (p != nullptr && p->nodes[0] != nullptr) {
            bool es_hoja = p->nodes[0] == nullptr && p->nodes[1] == nullptr;
            if (!es_hoja) {
                resultado.push_back(p);
            }
            p = p->nodes[0];
        }

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
    t.ins({ 15, 9, 20, 6, 14, 17, 64, 13, 26, 72 });

    sf::Font font;
    if (!font.openFromFile("C:/Windows/Fonts/arial.ttf")) {
        cout << "No se pudo cargar Arial\n";
        return -1;
    }

    const unsigned int ANCHO_VENTANA = 1000;
    const unsigned int ALTO_VENTANA = 650;
    const float MARGEN = 60.f;

    map<Node*, sf::Vector2f> posiciones;
    int contador = 0;
    CalcularPosiciones(t.root, 0, contador, 50.f, 80.f, posiciones);

    float minX = 999999.f;
    float maxX = -999999.f;
    float minY = 999999.f;
    float maxY = -999999.f;

    for (auto& par : posiciones) {
        minX = min(minX, par.second.x);
        maxX = max(maxX, par.second.x);
        minY = min(minY, par.second.y);
        maxY = max(maxY, par.second.y);
    }

    float anchoArbol = maxX - minX;
    float altoArbol = maxY - minY;

    float anchoDisponible = (float)ANCHO_VENTANA - MARGEN * 2.f;
    float altoDisponible = (float)ALTO_VENTANA - MARGEN * 2.f;

    float escalaX = (anchoArbol > 0.f) ? (anchoDisponible / anchoArbol) : 1.f;
    float escalaY = (altoArbol > 0.f) ? (altoDisponible / altoArbol) : 1.f;

    float escala = min(escalaX, escalaY);
    escala = min(escala, 1.f);

    float anchoEscalado = anchoArbol * escala;
    float altoEscalado = altoArbol * escala;

    float offsetCentradoX = (anchoDisponible - anchoEscalado) / 2.f;
    float offsetCentradoY = (altoDisponible - altoEscalado) / 2.f;

    for (auto& par : posiciones) {
        float x = (par.second.x - minX) * escala;
        float y = (par.second.y - minY) * escala;
        par.second.x = x + MARGEN + offsetCentradoX;
        par.second.y = y + MARGEN + offsetCentradoY;
    }

    sf::Vector2u tamano(ANCHO_VENTANA, ALTO_VENTANA);

    sf::RenderWindow window(sf::VideoMode(tamano), "06_Perimetro_ArbolSFML");

    sf::Vector2u tamanoPantalla = sf::VideoMode::getDesktopMode().size;
    int posX = (int)((tamanoPantalla.x - tamano.x) / 2);
    int posY = (int)((tamanoPantalla.y - tamano.y) / 2);
    window.setPosition(sf::Vector2i(posX, posY));

    vector<Node*> perim = t.perimeter();

    while (window.isOpen()) {
        while (const auto evento = window.pollEvent()) {
            if (evento->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        window.clear(sf::Color::White);
        DibujarArbol(t.root, window, font, posiciones);
        PintarNodo(perim, window, font, posiciones);
        window.display();
    }

    return 0;
}