#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <algorithm>

template <class N>
struct ItemNodo {
	N* nodo;
	int col;
	int nivel;
	int izq;
	int der;
};

template <class N>
int recorrer(N* n, int nivel, int& col, std::vector<ItemNodo<N>>& items) {

	if (n == nullptr) {
		return -1;
	}

	int izq = recorrer(n->left, nivel + 1, col, items);

	ItemNodo<N> it;
	it.nodo = n;
	it.col = col;
	it.nivel = nivel;

	col++;

	int der = recorrer(n->right, nivel + 1, col, items);

	it.izq = izq;
	it.der = der;

	items.push_back(it);

	return (int)items.size() - 1;
}

inline void linea(sf::RenderTarget& destino, sf::Vector2f a, sf::Vector2f b, float grosor) {

	float dx = b.x - a.x;
	float dy = b.y - a.y;
	float largo = std::sqrt(dx * dx + dy * dy);

	sf::RectangleShape r(sf::Vector2f(largo, grosor));
	r.setOrigin(0.f, grosor / 2.f);
	r.setPosition(a);
	r.setRotation(std::atan2(dy, dx) * 180.f / 3.14159265f);
	r.setFillColor(sf::Color::Black);

	destino.draw(r);
}

template <class N>
void dibujar(N* root) {

	if (root == nullptr) {
		return;
	}

	sf::Font fuente;

	if (!fuente.loadFromFile("C:/Windows/Fonts/arialbd.ttf")) {
		if (!fuente.loadFromFile("C:/Windows/Fonts/arial.ttf")) {
			std::cout << "No se pudo cargar la fuente" << std::endl;
			return;
		}
	}

	std::vector<ItemNodo<N>> items;
	int col = 0;
	recorrer(root, 0, col, items);

	int cols = col;
	int niveles = 0;

	for (int i = 0; i < (int)items.size(); i++) {
		niveles = std::max(niveles, items[i].nivel + 1);
	}

	sf::ContextSettings ajustes;
	ajustes.antialiasingLevel = 8;

	unsigned int w = 1000;
	unsigned int h = 700;

	sf::RenderWindow window(sf::VideoMode(w, h), "Arbol", sf::Style::Default, ajustes);
	window.setFramerateLimit(60);

	sf::VideoMode pantalla = sf::VideoMode::getDesktopMode();
	window.setPosition(sf::Vector2i((pantalla.width - w) / 2, (pantalla.height - h) / 2));

	const float margen = 40.f;
	const float margen_sup = 90.f;

	while (window.isOpen()) {

		sf::Event e;

		while (window.pollEvent(e)) {

			if (e.type == sf::Event::Closed) {
				window.close();
			}

			if (e.type == sf::Event::Resized) {
				window.setView(sf::View(sf::FloatRect(0.f, 0.f, (float)e.size.width, (float)e.size.height)));
			}
		}

		float ancho = (float)window.getSize().x;
		float alto = (float)window.getSize().y;

		float paso_x = (cols > 1) ? (ancho - 2 * margen) / (cols - 1) : ancho;
		float paso_y = (niveles > 1) ? (alto - margen_sup - margen) / (niveles - 1) : alto;

		float radio = std::min(32.f, std::min(paso_x * 0.8f, paso_y * 0.4f));
		radio = std::max(radio, 2.f);

		std::vector<sf::Vector2f> pos(items.size());

		for (int i = 0; i < (int)items.size(); i++) {

			float x = (cols > 1) ? margen + items[i].col * paso_x : ancho / 2.f;
			float y = margen_sup + items[i].nivel * ((niveles > 1) ? paso_y : 0.f);

			pos[i] = sf::Vector2f(x, y);
		}

		window.clear(sf::Color::White);

		for (int i = 0; i < (int)items.size(); i++) {

			if (items[i].izq != -1) {
				linea(window, pos[i], pos[items[i].izq], 3.f);
			}

			if (items[i].der != -1) {
				linea(window, pos[i], pos[items[i].der], 3.f);
			}
		}

		sf::Vector2f raiz = pos[items.size() - 1];

		sf::Text txt_root("root", fuente, 20);
		txt_root.setFillColor(sf::Color::Black);
		sf::FloatRect br = txt_root.getLocalBounds();
		txt_root.setOrigin(br.left + br.width / 2.f, br.top + br.height / 2.f);
		txt_root.setPosition(raiz.x, raiz.y - radio - 42.f);
		window.draw(txt_root);

		linea(window, sf::Vector2f(raiz.x, raiz.y - radio - 30.f), sf::Vector2f(raiz.x, raiz.y - radio - 12.f), 3.f);

		sf::ConvexShape flecha(3);
		flecha.setPoint(0, sf::Vector2f(raiz.x, raiz.y - radio - 4.f));
		flecha.setPoint(1, sf::Vector2f(raiz.x - 6.f, raiz.y - radio - 14.f));
		flecha.setPoint(2, sf::Vector2f(raiz.x + 6.f, raiz.y - radio - 14.f));
		flecha.setFillColor(sf::Color::Black);
		window.draw(flecha);

		for (int i = 0; i < (int)items.size(); i++) {

			sf::CircleShape c(radio, 60);
			c.setOrigin(radio, radio);
			c.setPosition(pos[i]);
			c.setFillColor(sf::Color::White);
			c.setOutlineColor(sf::Color::Black);
			c.setOutlineThickness(3.f);
			window.draw(c);

			std::ostringstream ss;
			ss << items[i].nodo->valor;
			std::string texto = ss.str();

			float tam = radio * 1.6f / std::max(2, (int)texto.size());
			tam = std::max(tam, 6.f);

			sf::Text t(texto, fuente, (unsigned int)tam);
			t.setFillColor(sf::Color::Black);
			sf::FloatRect b = t.getLocalBounds();
			t.setOrigin(b.left + b.width / 2.f, b.top + b.height / 2.f);
			t.setPosition(pos[i]);
			window.draw(t);
		}

		window.display();
	}
}