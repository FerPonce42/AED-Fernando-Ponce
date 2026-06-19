#pragma once
#include <SFML/Graphics.hpp>
#include <sstream>
#include <string>
#include <vector>
#include <optional>
using namespace std;

template <typename T> class CSparseMatrix;

inline bool cargarFuenteSistema(sf::Font& fuente) {
    static const vector<string> rutas = {
        "C:/Windows/Fonts/consola.ttf",
        "C:/Windows/Fonts/cour.ttf",
        "C:/Windows/Fonts/arial.ttf",
        "C:/Windows/Fonts/calibri.ttf",
        "/usr/share/fonts/truetype/dejavu/DejaVuSansMono.ttf",
        "/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf",
        "/usr/share/fonts/truetype/liberation/LiberationMono-Regular.ttf",
        "/System/Library/Fonts/Menlo.ttc",
    };
    for (const auto& r : rutas)
        if (fuente.openFromFile(r)) return true;
    return false;
}

// ── Dibuja la matriz estilo pizarra ──────────────────────────────────────────
// NUEVO: parametro "instruccion" para poder cambiar el texto de abajo
// (ej. en el paso final ya no dice "click para continuar", dice "ESC o cierra la ventana")
template <typename T>
void DibujarMatriz(CSparseMatrix<T>& A, sf::RenderWindow& ventana, sf::Font& fuente,
    int paso, int n, const string& mensaje, const string& submensaje = "",
    const string& instruccion = "click para continuar     ESC para salir")
{
    ventana.clear(sf::Color(250, 250, 248)); // blanco hueso

    // Calcular tamaño de celda según ventana
    float margenX = 80.f;
    float margenY = 100.f;
    float areaW = ventana.getSize().x - margenX * 2.f;
    float areaH = ventana.getSize().y - margenY - 80.f;
    float celdaW = areaW / (n + 1);
    float celdaH = areaH / n;
    celdaW = min(celdaW, 90.f);
    celdaH = min(celdaH, 70.f);

    float offsetX = (ventana.getSize().x - celdaW * (n + 1)) / 2.f;
    float offsetY = margenY;

    unsigned int fontSize = (unsigned int)max(12.f, min(18.f, celdaH * 0.35f));

    // ── Título / paso actual ─────────────────
    sf::Text titulo(fuente, mensaje, fontSize + 2);
    titulo.setFillColor(sf::Color(30, 30, 30));
    sf::FloatRect tb = titulo.getLocalBounds();
    titulo.setOrigin({ tb.position.x + tb.size.x / 2.f, tb.position.y });
    titulo.setPosition({ ventana.getSize().x / 2.f, 18.f });
    ventana.draw(titulo);

    // ── Subtítulo (solución o hint) ──────────
    if (!submensaje.empty()) {
        sf::Text sub(fuente, submensaje, fontSize - 1);
        sub.setFillColor(sf::Color(100, 100, 100));
        sf::FloatRect sb = sub.getLocalBounds();
        sub.setOrigin({ sb.position.x + sb.size.x / 2.f, sb.position.y });
        sub.setPosition({ ventana.getSize().x / 2.f, 48.f });
        ventana.draw(sub);
    }

    // ── Instrucción abajo ────────────────────
    sf::Text inst(fuente, instruccion, fontSize - 2);
    inst.setFillColor(sf::Color(160, 160, 160));
    sf::FloatRect ib = inst.getLocalBounds();
    inst.setOrigin({ ib.position.x + ib.size.x / 2.f, ib.position.y });
    inst.setPosition({ ventana.getSize().x / 2.f,
                      ventana.getSize().y - 30.f });
    ventana.draw(inst);

    // ── Línea separadora augmented matrix ───
    // Línea vertical entre coefs y término independiente
    float lineX = offsetX + n * celdaW;
    sf::RectangleShape separador({ 1.5f, celdaH * n });
    separador.setFillColor(sf::Color(180, 180, 180));
    separador.setPosition({ lineX, offsetY });
    ventana.draw(separador);

    // ── Corchete izquierdo ───────────────────
    float brkT = offsetY;
    float brkB = offsetY + celdaH * n;
    float brkX = offsetX - 14.f;
    float brkW = 8.f;
    float brkThick = 2.f;
    // vertical
    sf::RectangleShape bL({ brkThick, brkB - brkT });
    bL.setFillColor(sf::Color(80, 80, 80));
    bL.setPosition({ brkX, brkT });
    ventana.draw(bL);
    // horizontales
    sf::RectangleShape bLT({ brkW, brkThick });
    bLT.setFillColor(sf::Color(80, 80, 80));
    bLT.setPosition({ brkX, brkT });
    ventana.draw(bLT);
    sf::RectangleShape bLB({ brkW, brkThick });
    bLB.setFillColor(sf::Color(80, 80, 80));
    bLB.setPosition({ brkX, brkB - brkThick });
    ventana.draw(bLB);

    // ── Corchete derecho ─────────────────────
    float brkXR = offsetX + celdaW * (n + 1) + 6.f;
    sf::RectangleShape bR({ brkThick, brkB - brkT });
    bR.setFillColor(sf::Color(80, 80, 80));
    bR.setPosition({ brkXR + brkW - brkThick, brkT });
    ventana.draw(bR);
    sf::RectangleShape bRT({ brkW, brkThick });
    bRT.setFillColor(sf::Color(80, 80, 80));
    bRT.setPosition({ brkXR, brkT });
    ventana.draw(bRT);
    sf::RectangleShape bRB({ brkW, brkThick });
    bRB.setFillColor(sf::Color(80, 80, 80));
    bRB.setPosition({ brkXR, brkB - brkThick });
    ventana.draw(bRB);

    // ── Encabezados ──────────────────────────
    for (int j = 0; j <= n; j++) {
        string s = (j == n) ? "b" : ("x" + to_string(j + 1));
        sf::Text enc(fuente, s, fontSize - 2);
        enc.setFillColor(sf::Color(150, 150, 150));
        sf::FloatRect eb = enc.getLocalBounds();
        enc.setOrigin({ eb.position.x + eb.size.x / 2.f, eb.position.y });
        enc.setPosition({ offsetX + j * celdaW + celdaW / 2.f,
                         offsetY - fontSize - 8.f });
        ventana.draw(enc);
    }

    // ── Celdas ───────────────────────────────
    for (int i = 0; i < n; i++) {
        // etiqueta fila
        sf::Text etq(fuente, "f" + to_string(i + 1), fontSize - 2);
        etq.setFillColor(sf::Color(150, 150, 150));
        sf::FloatRect ef = etq.getLocalBounds();
        etq.setOrigin({ ef.position.x + ef.size.x, ef.position.y + ef.size.y / 2.f });
        etq.setPosition({ offsetX - 20.f,
                         offsetY + i * celdaH + celdaH / 2.f });
        ventana.draw(etq);

        for (int j = 0; j <= n; j++) {
            float cx = offsetX + j * celdaW + celdaW / 2.f;
            float cy = offsetY + i * celdaH + celdaH / 2.f;

            // Línea horizontal separadora entre filas (sutil)
            if (i > 0) {
                sf::RectangleShape linH({ celdaW * (n + 1), 1.f });
                linH.setFillColor(sf::Color(220, 220, 220));
                linH.setPosition({ offsetX, offsetY + i * celdaH });
                ventana.draw(linH);
            }

            T val = A.get(i, j);
            ostringstream ss;
            ss.precision(3);
            // Mostrar enteros sin decimales
            if (val == (T)(int)val && val != T(0))
                ss << (int)val;
            else
                ss << val;

            string valStr = ss.str();

            // Color: rojo solo si es la fila pivote activa O la columna que se elimina
            bool esPivote = (i == paso && paso >= 0);
            bool esEliminar = (i > paso && paso >= 0); // filas que se modifican

            sf::Color colorTexto;
            if (esPivote)
                colorTexto = sf::Color(200, 40, 40);   // rojo — fila pivote
            else if (esEliminar && j == paso)
                colorTexto = sf::Color(200, 40, 40);   // rojo — columna eliminada
            else if (val == T(0))
                colorTexto = sf::Color(200, 200, 200); // gris — cero
            else
                colorTexto = sf::Color(30, 30, 30);    // negro — normal

            sf::Text celda(fuente, valStr, fontSize);
            celda.setFillColor(colorTexto);
            sf::FloatRect cb = celda.getLocalBounds();
            celda.setOrigin({ cb.position.x + cb.size.x / 2.f,
                             cb.position.y + cb.size.y / 2.f });
            celda.setPosition({ cx, cy });
            ventana.draw(celda);
        }
    }

    ventana.display();
}

// ── Esperar click o ESC (avanza al siguiente paso) ───────────
bool EsperarClick(sf::RenderWindow& ventana) {
    while (ventana.isOpen()) {
        while (const optional<sf::Event> ev = ventana.pollEvent()) {
            if (ev->is<sf::Event::Closed>()) { ventana.close(); return false; }
            if (const auto* kp = ev->getIf<sf::Event::KeyPressed>())
                if (kp->scancode == sf::Keyboard::Scancode::Escape)
                {
                    ventana.close(); return false;
                }
            if (ev->is<sf::Event::MouseButtonPressed>()) return true;
        }
    }
    return false;
}

// ── NUEVO: Esperar cierre (NO avanza con click, solo se cierra cuando
//    el usuario presiona ESC o la X de la ventana). Usar en el paso final,
//    para que el resultado se quede en pantalla hasta que el usuario decida. ──
void EsperarCierre(sf::RenderWindow& ventana) {
    while (ventana.isOpen()) {
        while (const optional<sf::Event> ev = ventana.pollEvent()) {
            if (ev->is<sf::Event::Closed>()) { ventana.close(); return; }
            if (const auto* kp = ev->getIf<sf::Event::KeyPressed>())
                if (kp->scancode == sf::Keyboard::Scancode::Escape)
                {
                    ventana.close(); return;
                }
            // Nota: aquí NO se escucha MouseButtonPressed a propósito,
            // un click no debe cerrar ni avanzar nada en esta pantalla.
        }
    }
}