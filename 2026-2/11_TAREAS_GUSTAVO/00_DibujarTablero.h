#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

inline void linea(sf::RenderTarget& destino, sf::Vector2f a, sf::Vector2f b, float grosor) {

	float dx = b.x - a.x;
	float dy = b.y - a.y;
	float largo = sqrt(dx * dx + dy * dy);

	sf::RectangleShape r(sf::Vector2f(largo, grosor));
	r.setOrigin(0.f, grosor / 2.f);
	r.setPosition(a);
	r.setRotation(atan2(dy, dx) * 180.f / 3.14159265f);
	r.setFillColor(sf::Color::Black);

	destino.draw(r);
}

template <class M>
void dibujar(M& m, int n) {

	sf::Font fuente;

	if (!fuente.loadFromFile("C:/Windows/Fonts/arialbd.ttf")) {
		if (!fuente.loadFromFile("C:/Windows/Fonts/arial.ttf")) {
			cout << "No se pudo cargar la fuente" << endl;
			return;
		}
	}

	sf::ContextSettings ajustes;
	ajustes.antialiasingLevel = 8;

	unsigned int w = 700;
	unsigned int h = 700;

	sf::RenderWindow window(sf::VideoMode(w, h), "Tablero", sf::Style::Default, ajustes);
	window.setFramerateLimit(60);

	sf::VideoMode pantalla = sf::VideoMode::getDesktopMode();
	window.setPosition(sf::Vector2i((pantalla.width - w) / 2, (pantalla.height - h) / 2));

	const float margen = 40.f;

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

		float celda = min((ancho - 2 * margen) / n, (alto - 2 * margen) / n);
		float x0 = (ancho - celda * n) / 2.f;
		float y0 = (alto - celda * n) / 2.f;

		window.clear(sf::Color::White);

		for (int i = 0; i <= n; i++) {
			linea(window, sf::Vector2f(x0, y0 + i * celda), sf::Vector2f(x0 + n * celda, y0 + i * celda), 3.f);
			linea(window, sf::Vector2f(x0 + i * celda, y0), sf::Vector2f(x0 + i * celda, y0 + n * celda), 3.f);
		}

		float radio = celda * 0.22f;

		for (int f = 0; f < n; f++) {
			for (int c = 0; c < n; c++) {

				if (m.get(f, c) != 0) {

					float cx = x0 + c * celda + celda / 2.f;
					float cy = y0 + f * celda + celda / 2.f;

					sf::CircleShape mina(radio, 60);
					mina.setOrigin(radio, radio);
					mina.setPosition(cx, cy);
					mina.setFillColor(sf::Color::Blue);
					mina.setOutlineColor(sf::Color::Black);
					mina.setOutlineThickness(2.f);
					window.draw(mina);

					sf::Text equis("X", fuente, (unsigned int)(radio * 1.4f));
					equis.setFillColor(sf::Color::Black);
					sf::FloatRect b = equis.getLocalBounds();
					equis.setOrigin(b.left + b.width / 2.f, b.top + b.height / 2.f);
					equis.setPosition(cx, cy);
					window.draw(equis);
				}
			}
		}

		window.display();
	}
}