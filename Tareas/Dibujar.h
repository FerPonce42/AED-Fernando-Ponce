#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <vector>
#include <string>
using namespace std;

struct Node;

void calcularPosiciones(Node* n, int nivel, int& contador, float ancho, float alto, map<Node*, sf::Vector2f>& posiciones)
{
    if (n == nullptr) {
        return;
    }
    calcularPosiciones(n->nodes[0], nivel + 1, contador, ancho, alto, posiciones);
    posiciones[n] = sf::Vector2f(contador * ancho, nivel * alto + 50.f);
    contador++;
    calcularPosiciones(n->nodes[1], nivel + 1, contador, ancho, alto, posiciones);
}

sf::Vector2u calcularTamanoVentana(map<Node*, sf::Vector2f>& posiciones, float margen = 60.f)
{
    float maxX = 0.f, maxY = 0.f, minX = 999999.f;
    for (auto& par : posiciones) {
        if (par.second.x > maxX) maxX = par.second.x;
        if (par.second.y > maxY) maxY = par.second.y;
        if (par.second.x < minX) minX = par.second.x;
    }
    return sf::Vector2u((unsigned int)(maxX - minX + margen * 2), (unsigned int)(maxY + margen * 2));
}

void drawTree(Node* raiz, sf::RenderWindow& window, sf::Font& font, map<Node*, sf::Vector2f>& posiciones)
{
    float radio = 20.f;

    // LINEASS
    for (auto& par : posiciones) {
        Node* n = par.first;
        sf::Vector2f pos = par.second;
        for (int i = 0; i < 2; i++) {
            if (n->nodes[i] != nullptr && posiciones.count(n->nodes[i])) {
                sf::Vector2f posHijo = posiciones[n->nodes[i]];
                sf::Vertex linea[2] = {
                    sf::Vertex(pos,     sf::Color::Black),
                    sf::Vertex(posHijo, sf::Color::Black)
                };
                window.draw(linea, 2, sf::PrimitiveType::Lines);
            }
        }
    }

    // CIRCULOS Y VALORES
    for (auto& par : posiciones) {
        Node* n = par.first;
        sf::Vector2f pos = par.second;

        sf::CircleShape circulo(radio);
        circulo.setFillColor(sf::Color::White);
        circulo.setOutlineColor(sf::Color::Black);
        circulo.setOutlineThickness(2.f);
        circulo.setOrigin(sf::Vector2f(radio, radio));
        circulo.setPosition(pos);
        window.draw(circulo);

        sf::Text texto(font);
        texto.setString(to_string(n->value));
        texto.setCharacterSize(14);
        texto.setFillColor(sf::Color::Black);
        sf::FloatRect bounds = texto.getLocalBounds();
        texto.setOrigin(sf::Vector2f(
            bounds.position.x + bounds.size.x / 2.f,
            bounds.position.y + bounds.size.y / 2.f
        ));
        texto.setPosition(pos);
        window.draw(texto);
    }
}

void highlightNodos(vector<Node*>& nodos, sf::RenderWindow& window, sf::Font& font, map<Node*, sf::Vector2f>& posiciones)
{
    float radio = 20.f;
    sf::Color celeste(0, 180, 220);

    for (Node* n : nodos) {
        if (posiciones.count(n) == 0) {
            continue;
        }
        sf::Vector2f pos = posiciones[n];

        sf::CircleShape circulo(radio);
        circulo.setFillColor(celeste);
        circulo.setOutlineColor(sf::Color::Black);
        circulo.setOutlineThickness(2.f);
        circulo.setOrigin(sf::Vector2f(radio, radio));
        circulo.setPosition(pos);
        window.draw(circulo);

        sf::Text texto(font);
        texto.setString(to_string(n->value));
        texto.setCharacterSize(14);
        texto.setFillColor(sf::Color::Black);
        sf::FloatRect bounds = texto.getLocalBounds();
        texto.setOrigin(sf::Vector2f(
            bounds.position.x + bounds.size.x / 2.f,
            bounds.position.y + bounds.size.y / 2.f
        ));
        texto.setPosition(pos);
        window.draw(texto);
    }
}