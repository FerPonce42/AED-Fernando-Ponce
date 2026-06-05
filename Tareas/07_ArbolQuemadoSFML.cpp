#include <SFML/Graphics.hpp>
#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <set>
#include <string>
using namespace std;

struct Node {
    int value;
    Node* nodes[2];
    Node* parent;

    Node(int v) : value(v), parent(nullptr) {
        nodes[0] = nodes[1] = nullptr;
    }
};

#include "Dibujar.h"

Node* construirArbolProfe() {
    Node* n12 = new Node(12);
    Node* n19 = new Node(19);
    Node* n82 = new Node(82);
    Node* n41 = new Node(41);
    Node* n2 = new Node(2);
    Node* n15 = new Node(15);
    Node* n95 = new Node(95);
    Node* n21 = new Node(21);
    Node* n7 = new Node(7);
    Node* n16 = new Node(16);

    n12->nodes[0] = n19;  n19->parent = n12;
    n12->nodes[1] = n82;  n82->parent = n12;

    n19->nodes[0] = n41;  n41->parent = n19;
    n19->nodes[1] = n2;   n2->parent = n19;

    n82->nodes[0] = n15;  n15->parent = n82;
    n82->nodes[1] = n95;  n95->parent = n82;

    n15->nodes[0] = n21;  n21->parent = n15;

    n95->nodes[0] = n7;   n7->parent = n95;
    n95->nodes[1] = n16;  n16->parent = n95;

    return n12;
}

vector<vector<Node*>> calcularQuemado(Node* raiz, int objetivo) {
    Node* start = nullptr;
    {
        queue<Node*> q;
        q.push(raiz);
        while (!q.empty() && !start) {
            Node* cur = q.front(); q.pop();
            if (cur->value == objetivo) { start = cur; break; }
            for (int i = 0; i < 2; i++)
                if (cur->nodes[i]) q.push(cur->nodes[i]);
        }
    }
    if (!start) return {};

    vector<vector<Node*>> vueltas;
    set<Node*> quemados;
    queue<Node*> q;
    q.push(start);
    quemados.insert(start);

    while (!q.empty()) {
        int sz = (int)q.size();
        vector<Node*> vuelta;
        for (int i = 0; i < sz; i++) {
            Node* cur = q.front(); q.pop();
            vuelta.push_back(cur);
            for (int j = 0; j < 2; j++) {
                if (cur->nodes[j] && !quemados.count(cur->nodes[j])) {
                    quemados.insert(cur->nodes[j]);
                    q.push(cur->nodes[j]);
                }
            }
            if (cur->parent && !quemados.count(cur->parent)) {
                quemados.insert(cur->parent);
                q.push(cur->parent);
            }
        }
        vueltas.push_back(vuelta);
    }
    return vueltas;
}

Node* nodoBajoCursor(sf::Vector2f mouse, map<Node*, sf::Vector2f>& posiciones) {
    float radio = 20.f;
    for (auto& par : posiciones) {
        sf::Vector2f pos = par.second;
        float dx = mouse.x - pos.x;
        float dy = mouse.y - pos.y;
        if (dx * dx + dy * dy <= radio * radio)
            return par.first;
    }
    return nullptr;
}

int main() {
    sf::Font font;
    if (!font.openFromFile("C:/Windows/Fonts/arial.ttf")) {
        cerr << "No se pudo cargar la fuente\n";
        return 1;
    }

    Node* raiz = construirArbolProfe();

    map<Node*, sf::Vector2f> posiciones;
    int contador = 0;
    CalcularPosiciones(raiz, 0, contador, 80.f, 90.f, posiciones);

    float minX = 999999.f;
    for (auto& p : posiciones) minX = min(minX, p.second.x);
    for (auto& p : posiciones) p.second.x -= minX - 60.f;

    sf::Vector2u tamano = CalcularTamanoVentana(posiciones, 60.f);
    tamano.x = max(tamano.x, 400u);
    tamano.y = max(tamano.y, 300u);

    sf::RenderWindow window(sf::VideoMode(tamano), "07_ArbolQuemado");
    window.setFramerateLimit(60);

    vector<vector<Node*>> vueltas;
    vector<Node*> quemadosAcum;
    int vueltaActual = 0;
    bool objetivoElegido = false;

    sf::Text instruccion(font);
    instruccion.setCharacterSize(13);
    instruccion.setFillColor(sf::Color(50, 50, 50));
    instruccion.setPosition(sf::Vector2f(10.f, (float)tamano.y - 30.f));
    instruccion.setString("Haz clic en un nodo para que sea el objetivo...");

    while (window.isOpen()) {
        while (const std::optional<sf::Event> event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();

            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if (keyPressed->scancode == sf::Keyboard::Scan::Escape)
                    window.close();

                if (keyPressed->scancode == sf::Keyboard::Scan::Space && objetivoElegido) {
                    if (vueltaActual < (int)vueltas.size()) {
                        for (Node* n : vueltas[vueltaActual])
                            quemadosAcum.push_back(n);
                        vueltaActual++;

                        if (vueltaActual <= (int)vueltas.size())
                            instruccion.setString("Vuelta " + to_string(vueltaActual) + "/" +
                                to_string(vueltas.size()) + "  |  ESPACIO: siguiente  |  R: reiniciar");
                        else
                            instruccion.setString("Quemado completo!!!  |  R: reiniciar  |  ESC: salir");
                    }
                }

                if (keyPressed->scancode == sf::Keyboard::Scan::R) {
                    vueltas.clear();
                    quemadosAcum.clear();
                    vueltaActual = 0;
                    objetivoElegido = false;
                    instruccion.setString("Click en un nodo para elegir objetivo");
                }
            }

            if (const auto* click = event->getIf<sf::Event::MouseButtonPressed>()) {
                if (click->button == sf::Mouse::Button::Left && !objetivoElegido) {
                    sf::Vector2f mouse((float)click->position.x, (float)click->position.y);
                    Node* elegido = nodoBajoCursor(mouse, posiciones);
                    if (elegido) {
                        vueltas = calcularQuemado(raiz, elegido->value);
                        objetivoElegido = true;
                        instruccion.setString("Objetivo: " + to_string(elegido->value) +
                            "  |  SPACE: iniciar  |  R: reiniciar");
                    }
                }
            }
        }

        window.clear(sf::Color(245, 245, 240));
        DibujarArbol(raiz, window, font, posiciones);
        PintarNodoQuemado(quemadosAcum, window, font, posiciones);
        window.draw(instruccion);
        window.display();
    }

    return 0;
}