#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

struct Nodo {

	int valor;
	int altura;

	Nodo* right;
	Nodo* left;

	Nodo(int v) {
		valor = v;
		right = nullptr;
		left = nullptr;
		altura = 1;
	}

};

struct ItemNodo {
	Nodo* nodo;
	int col;
	int nivel;
	int izq;
	int der;
};

inline int recorrer(Nodo* n, int nivel, int& col, std::vector<ItemNodo>& items) {

	if (n == nullptr) {
		return -1;
	}

	int izq = recorrer(n->left, nivel + 1, col, items);

	ItemNodo it;
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

inline int alturaDe(Nodo* n) {

	if (n == nullptr) {
		return 0;
	}

	return n->altura;
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

// calcular: funcion que recibe el nodo clickeado y llena la lista con los nodos a pintar
inline void dibujar(Nodo* root, void (*calcular)(Nodo*, std::vector<Nodo*>&)) {

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

	std::vector<ItemNodo> items;
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

	// margenes: a los lados queda espacio para el circulo y el texto fb=
	const float margen_x = 80.f;
	const float margen_sup = 90.f;
	const float margen_inf = 45.f;

	// viven fuera del bucle para que el clic los pueda usar
	std::vector<sf::Vector2f> pos(items.size());
	float radio = 32.f;

	Nodo* elegido = nullptr;
	std::vector<Nodo*> pintar;

	while (window.isOpen()) {

		sf::Event e;

		while (window.pollEvent(e)) {

			if (e.type == sf::Event::Closed) {
				window.close();
			}

			if (e.type == sf::Event::Resized) {
				window.setView(sf::View(sf::FloatRect(0.f, 0.f, (float)e.size.width, (float)e.size.height)));
			}

			if (e.type == sf::Event::MouseButtonPressed && e.mouseButton.button == sf::Mouse::Left) {

				float mx = (float)e.mouseButton.x;
				float my = (float)e.mouseButton.y;

				for (int i = 0; i < (int)items.size(); i++) {

					float dx = mx - pos[i].x;
					float dy = my - pos[i].y;

					if (dx * dx + dy * dy <= radio * radio) {
						elegido = items[i].nodo;
						calcular(elegido, pintar);
					}
				}
			}
		}

		float ancho = (float)window.getSize().x;
		float alto = (float)window.getSize().y;

		float paso_x = (cols > 1) ? (ancho - 2 * margen_x) / (cols - 1) : ancho;
		float paso_y = (niveles > 1) ? (alto - margen_sup - margen_inf) / (niveles - 1) : alto;

		radio = std::min(32.f, std::min(paso_x * 0.8f, paso_y * 0.4f));
		radio = std::max(radio, 2.f);

		for (int i = 0; i < (int)items.size(); i++) {

			float x = (cols > 1) ? margen_x + items[i].col * paso_x : ancho / 2.f;
			float y = margen_sup + items[i].nivel * ((niveles > 1) ? paso_y : 0.f);

			pos[i] = sf::Vector2f(x, y);
		}

		window.clear(sf::Color::White);

		sf::Text ayuda("Clic en un nodo para pintar sus primos", fuente, 16);
		ayuda.setFillColor(sf::Color::Black);
		ayuda.setPosition(10.f, 8.f);
		window.draw(ayuda);

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

		// tamano del texto fb=, se achica junto con los circulos
		unsigned int tam_fb = (unsigned int)std::max(8.f, radio * 0.45f);

		for (int i = 0; i < (int)items.size(); i++) {

			bool esPrimo = false;

			for (int j = 0; j < (int)pintar.size(); j++) {
				if (pintar[j] == items[i].nodo) {
					esPrimo = true;
				}
			}

			sf::CircleShape c(radio, 60);
			c.setOrigin(radio, radio);
			c.setPosition(pos[i]);

			if (items[i].nodo == elegido) {
				c.setFillColor(sf::Color(120, 190, 255));
			}
			else if (esPrimo) {
				c.setFillColor(sf::Color(255, 160, 0));
			}
			else {
				c.setFillColor(sf::Color::White);
			}

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

			int fb = alturaDe(items[i].nodo->right) - alturaDe(items[i].nodo->left);

			sf::Text tfb("fb=" + std::to_string(fb), fuente, tam_fb);
			tfb.setFillColor(sf::Color(0, 0, 200));
			tfb.setPosition(pos[i].x + radio + 2.f, pos[i].y - radio - 4.f);
			window.draw(tfb);
		}

		window.display();
	}
}