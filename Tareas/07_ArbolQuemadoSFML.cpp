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

Node* construirArbolDesdeLista(const vector<int>& datos)
{
    int n = (int)datos.size();

    vector<Node*> nodos(n, nullptr);

    for (int i = 0; i < n; i++)
    {
        if (datos[i] != -1)
        {
            nodos[i] = new Node(datos[i]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (!nodos[i])
        {
            continue;
        }

        int indiceIzq = 2 * i + 1;
        int indiceDer = 2 * i + 2;

        if (indiceIzq < n && nodos[indiceIzq])
        {
            nodos[i]->nodes[0] = nodos[indiceIzq];
            nodos[indiceIzq]->parent = nodos[i];
        }

        if (indiceDer < n && nodos[indiceDer])
        {
            nodos[i]->nodes[1] = nodos[indiceDer];
            nodos[indiceDer]->parent = nodos[i];
        }
    }

    return nodos[0];
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

    Node* raiz = construirArbolDesdeLista({ 50,
        30, 70,
        20, 40, 60, 80,
        15, 25, 35, 45, 55, 65, 75, 90,
        12, 17, 22, 28, 32, 38, 42, 48, 52, 58, 62, 68, 72, 78, 85, 95 });

    const unsigned int ANCHO_VENTANA = 1000;
    const unsigned int ALTO_VENTANA = 650;
    const float MARGEN = 60.f;

    map<Node*, sf::Vector2f> posiciones;
    int contador = 0;
    CalcularPosiciones(raiz, 0, contador, 80.f, 90.f, posiciones);

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

    sf::RenderWindow window(sf::VideoMode(tamano), "07_ArbolQuemado");
    window.setFramerateLimit(60);

    sf::Vector2u tamanoPantalla = sf::VideoMode::getDesktopMode().size;
    int posX = (int)((tamanoPantalla.x - tamano.x) / 2);
    int posY = (int)((tamanoPantalla.y - tamano.y) / 2);
    window.setPosition(sf::Vector2i(posX, posY));

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

            if (const auto* resized = event->getIf<sf::Event::Resized>()) {
                sf::FloatRect area(
                    sf::Vector2f(0.f, 0.f),
                    sf::Vector2f((float)resized->size.x, (float)resized->size.y)
                );
                window.setView(sf::View(area));
            }

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
                    sf::Vector2i pixel(click->position.x, click->position.y);
                    sf::Vector2f mouse = window.mapPixelToCoords(pixel);
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