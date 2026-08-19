#pragma once
#include <SFML/Graphics.hpp>
#include <sstream>
#include <string>
#include <vector>
#include <optional>
#include <cmath>
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
    for (const auto& r : rutas) {
        if (fuente.openFromFile(r)) {
            return true;
        }
    }
    return false;
}

inline void recrearVentana(sf::RenderWindow& ventana, unsigned int w, unsigned int h, const string& titulo) {
    auto desktop = sf::VideoMode::getDesktopMode();
    int px = (int)(desktop.size.x - w) / 2;
    int py = (int)(desktop.size.y - h) / 2;
    ventana.close();
    ventana.create(sf::VideoMode({ w, h }), titulo);
    ventana.setFramerateLimit(60);
    ventana.setPosition({ px, py });
}

template <typename T>
string fmtNum(T val) {
    if (abs((double)val) < 1e-10) {
        return "0";
    }
    if (abs(val - round(val)) < 1e-9) {
        ostringstream ss;
        ss << (int)round(val);
        return ss.str();
    }
    ostringstream ss;
    ss.precision(2);
    ss << fixed << val;
    return ss.str();
}

inline sf::Vector2u tamanoParaN(int n, int opsCharMax = 18) {
    const float CELDA_W = 72.f;
    const float CELDA_H = 60.f;
    const float MARGEN_IZQ = 50.f;
    const float MARGEN_DER = 20.f;
    const float CORCHETE = 20.f;
    const float OPS_W = max(140.f, opsCharMax * 8.f);

    float matrizW = CELDA_W * (n + 1);
    float totalW = MARGEN_IZQ + CORCHETE + matrizW + CORCHETE + 12.f + OPS_W + MARGEN_DER;
    float totalH = 60.f + CELDA_H * n + 60.f;

    unsigned int w = (unsigned int)ceil(totalW);
    unsigned int h = (unsigned int)ceil(totalH);
    w = max(w, 480u);
    h = max(h, 300u);
    return { w, h };
}

template <typename T>
void DibujarMatriz(CSparseMatrix<T>& A, sf::RenderWindow& ventana, sf::Font& fuente,
    int paso, int n, const string& titulo,
    const vector<string>& ops = {},
    const string& hint = "\u2192 continuar   \u2190 retroceder   ESC salir")
{
    const sf::Color BG = sf::Color(28, 32, 38);
    const sf::Color C_WHITE = sf::Color(230, 235, 240);
    const sf::Color C_CYAN = sf::Color(80, 190, 210);
    const sf::Color C_CYAN2 = sf::Color(50, 155, 175);
    const sf::Color C_GRAY = sf::Color(90, 100, 115);
    const sf::Color C_HINT = sf::Color(65, 75, 90);
    const sf::Color C_PIVOT = sf::Color(120, 210, 220);
    const sf::Color C_ELIM = sf::Color(80, 190, 210);

    ventana.clear(BG);
    float W = (float)ventana.getSize().x;
    float H = (float)ventana.getSize().y;

    const float CELDA_W = 72.f;
    const float CELDA_H = 60.f;
    const float MARGEN_IZQ = 50.f;
    const float CORCHETE = 20.f;
    const unsigned int FS = 14u;

    float matrizW = CELDA_W * (n + 1);

    int maxOpsLen = 0;
    for (const auto& s : ops) {
        maxOpsLen = max(maxOpsLen, (int)s.size());
    }
    float opsW = max(100.f, maxOpsLen * 8.f);

    float bloqueW = MARGEN_IZQ + CORCHETE + matrizW + CORCHETE + 12.f + opsW;
    float startX = (W - bloqueW) / 2.f;
    float offsetX = startX + MARGEN_IZQ + CORCHETE;
    float opsX = offsetX + matrizW + CORCHETE + 12.f;
    float offsetY = 56.f;

    {
        sf::Text t(fuente, titulo, FS + 1);
        t.setFillColor(C_WHITE);
        sf::FloatRect b = t.getLocalBounds();
        t.setOrigin({ b.position.x + b.size.x / 2.f, b.position.y });
        t.setPosition({ W / 2.f, 16.f });
        ventana.draw(t);
    }

    {
        sf::Text t(fuente, hint, FS - 3);
        t.setFillColor(C_HINT);
        sf::FloatRect b = t.getLocalBounds();
        t.setOrigin({ b.position.x + b.size.x / 2.f, b.position.y });
        t.setPosition({ W / 2.f, H - 22.f });
        ventana.draw(t);
    }

    for (int j = 0; j <= n; j++) {
        string s = (j == n) ? "b" : ("x" + to_string(j + 1));
        sf::Text enc(fuente, s, FS - 3);
        enc.setFillColor(C_CYAN2);
        sf::FloatRect eb = enc.getLocalBounds();
        enc.setOrigin({ eb.position.x + eb.size.x / 2.f, eb.position.y });
        enc.setPosition({ offsetX + j * CELDA_W + CELDA_W / 2.f, offsetY - FS - 6.f });
        ventana.draw(enc);
    }

    {
        sf::RectangleShape sep({ 1.f, CELDA_H * n });
        sep.setFillColor(C_GRAY);
        sep.setPosition({ offsetX + n * CELDA_W, offsetY });
        ventana.draw(sep);
    }

    auto drawBracket = [&](float x, bool left) {
        float bT = offsetY;
        float bB = offsetY + CELDA_H * n;
        float bW = 6.f;
        float bTh = 1.5f;
        float xV = left ? x : x + bW - bTh;
        sf::RectangleShape v({ bTh, bB - bT });
        v.setFillColor(C_WHITE);
        v.setPosition({ xV, bT });
        ventana.draw(v);
        sf::RectangleShape hT({ bW, bTh });
        hT.setFillColor(C_WHITE);
        hT.setPosition({ x, bT });
        ventana.draw(hT);
        sf::RectangleShape hB({ bW, bTh });
        hB.setFillColor(C_WHITE);
        hB.setPosition({ x, bB - bTh });
        ventana.draw(hB);
        };
    drawBracket(offsetX - 10.f, true);
    drawBracket(offsetX + matrizW + 4.f, false);

    for (int i = 0; i < n; i++) {
        float cy = offsetY + i * CELDA_H + CELDA_H / 2.f;

        if (i > 0) {
            sf::RectangleShape lh({ matrizW, 1.f });
            lh.setFillColor(C_GRAY);
            lh.setPosition({ offsetX, offsetY + i * CELDA_H });
            ventana.draw(lh);
        }

        {
            sf::Text etq(fuente, "f" + to_string(i + 1), FS - 3);
            etq.setFillColor(C_GRAY);
            sf::FloatRect ef = etq.getLocalBounds();
            etq.setOrigin({ ef.position.x + ef.size.x, ef.position.y + ef.size.y / 2.f });
            etq.setPosition({ offsetX - 14.f, cy });
            ventana.draw(etq);
        }

        for (int j = 0; j <= n; j++) {
            T val = A.get(i, j);
            bool esZero = (abs((double)val) < 1e-10);
            bool esPivote = (i == paso && paso >= 0);
            bool esElim = (i > paso && paso >= 0 && j == paso);

            sf::Color col;
            if (esZero) {
                col = C_GRAY;
            }
            else if (esPivote) {
                col = C_PIVOT;
            }
            else if (esElim) {
                col = C_ELIM;
            }
            else {
                col = C_WHITE;
            }

            sf::Text celda(fuente, fmtNum(val), FS);
            celda.setFillColor(col);
            sf::FloatRect cb = celda.getLocalBounds();
            celda.setOrigin({ cb.position.x + cb.size.x / 2.f, cb.position.y + cb.size.y / 2.f });
            celda.setPosition({ offsetX + j * CELDA_W + CELDA_W / 2.f, cy });
            ventana.draw(celda);
        }

        if (i < (int)ops.size() && !ops[i].empty()) {
            sf::Text opT(fuente, ops[i], FS - 2);
            opT.setFillColor(C_CYAN2);
            sf::FloatRect ob = opT.getLocalBounds();
            opT.setOrigin({ ob.position.x, ob.position.y + ob.size.y / 2.f });
            opT.setPosition({ opsX, cy });
            ventana.draw(opT);
        }
    }

    ventana.display();
}

inline int EsperarNavegacion(sf::RenderWindow& ventana) {
    while (ventana.isOpen()) {
        while (const optional<sf::Event> ev = ventana.pollEvent()) {
            if (ev->is<sf::Event::Closed>()) {
                ventana.close();
                return 0;
            }
            if (const auto* kp = ev->getIf<sf::Event::KeyPressed>()) {
                if (kp->scancode == sf::Keyboard::Scancode::Escape) {
                    ventana.close();
                    return 0;
                }
                if (kp->scancode == sf::Keyboard::Scancode::Right) {
                    return +1;
                }
                if (kp->scancode == sf::Keyboard::Scancode::Left) {
                    return -1;
                }
            }
        }
    }
    return 0;
}