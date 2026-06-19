#include <iostream>
#include <sstream>
#include <string>
#include <optional>
#include <SFML/Graphics.hpp>
#include "DibujarMatriz.h"
using namespace std;

template <typename T>
struct SNodo {
    int col; T valor; SNodo<T>* siguiente;
    SNodo(int c, T v) : col(c), valor(v), siguiente(nullptr) {}
};

template <typename T>
struct SFila {
    int fila; SNodo<T>* head; SFila<T>* siguiente;
    SFila(int f) : fila(f), head(nullptr), siguiente(nullptr) {}
};

template <typename T>
class CSparseMatrix {
public:
    int nfilas, ncols;
    CSparseMatrix(int f, int c) : nfilas(f), ncols(c), head(nullptr) {}
    ~CSparseMatrix() {
        SFila<T>* f = head;
        while (f) {
            SNodo<T>* c = f->head;
            while (c) { auto* t = c; c = c->siguiente; delete t; }
            auto* t = f; f = f->siguiente; delete t;
        }
    }

    SFila<T>** findx(int f) {
        SFila<T>** p;
        for (p = &head; *p && (*p)->fila < f; p = &(*p)->siguiente);
        return p;
    }
    SNodo<T>** findy(SFila<T>* fila, int c) {
        SNodo<T>** p;
        for (p = &fila->head; *p && (*p)->col < c; p = &(*p)->siguiente);
        return p;
    }

    void set(int f, int c, T val) {
        if (val == T(0)) {
            SFila<T>** fp = findx(f);
            if (!(*fp) || (*fp)->fila != f) return;
            SNodo<T>** cp = findy(*fp, c);
            if (!(*cp) || (*cp)->col != c) return;
            auto* tmp = *cp; *cp = tmp->siguiente; delete tmp;
            return;
        }
        SFila<T>* fila = getFila(f);
        SNodo<T>** cp = findy(fila, c);
        if (*cp && (*cp)->col == c) { (*cp)->valor = val; }
        else {
            auto* nuevo = new SNodo<T>(c, val);
            nuevo->siguiente = *cp; *cp = nuevo;
        }
    }

    T get(int f, int c) {
        SFila<T>** fp = findx(f);
        if (!(*fp) || (*fp)->fila != f) return T(0);
        SNodo<T>** cp = findy(*fp, c);
        if (!(*cp) || (*cp)->col != c) return T(0);
        return (*cp)->valor;
    }

private:
    SFila<T>* head;
    SFila<T>* getFila(int f) {
        SFila<T>** p = findx(f);
        if (!(*p) || (*p)->fila != f) {
            auto* nueva = new SFila<T>(f); nueva->siguiente = *p; *p = nueva;
        }
        return *p;
    }
};

// ── Parsear fila ─────────────────────────────
void parsearFila(const string& linea, CSparseMatrix<double>& A, int fila, int n) {
    stringstream ss(linea); string token; int col = 0;
    while (getline(ss, token, ',') && col <= n) {
        double val = stod(token);
        if (val != 0.0) A.set(fila, col, val);
        col++;
    }
}

// ── Pantalla de ingreso de datos ─────────────
// Devuelve false si el usuario cierra la ventana
// NOTA: ya NO redimensiona ni recentra la ventana — esta se crea una sola
// vez en main() con tamaño fijo, así no hay "saltos" de ventana.
bool PantallaIngreso(sf::RenderWindow& ventana, sf::Font& fuente, int& n,
    CSparseMatrix<double>*& A)
{
    // --- Pedir n ---
    string inputN = "";
    bool nConfirmado = false;

    while (ventana.isOpen() && !nConfirmado) {
        while (const auto ev = ventana.pollEvent()) {
            if (ev->is<sf::Event::Closed>()) { ventana.close(); return false; }
            if (const auto* kp = ev->getIf<sf::Event::KeyPressed>()) {
                if (kp->scancode == sf::Keyboard::Scancode::Escape)
                {
                    ventana.close(); return false;
                }
                if (kp->scancode == sf::Keyboard::Scancode::Backspace && !inputN.empty())
                    inputN.pop_back();
                if (kp->scancode == sf::Keyboard::Scancode::Enter && !inputN.empty()) {
                    n = stoi(inputN);
                    if (n >= 2 && n <= 9) nConfirmado = true;
                    else inputN = "";
                }
            }
            if (const auto* tc = ev->getIf<sf::Event::TextEntered>()) {
                char c = (char)tc->unicode;
                if (c >= '2' && c <= '9') inputN += c;
            }
        }

        ventana.clear(sf::Color(250, 250, 248));
        sf::Text t1(fuente, "Eliminacion Gaussiana", 22);
        t1.setFillColor(sf::Color(30, 30, 30));
        sf::FloatRect b1 = t1.getLocalBounds();
        t1.setOrigin({ b1.position.x + b1.size.x / 2.f, b1.position.y });
        t1.setPosition({ ventana.getSize().x / 2.f, 80.f });
        ventana.draw(t1);

        sf::Text t2(fuente, "Numero de variables (2-9):", 16);
        t2.setFillColor(sf::Color(80, 80, 80));
        sf::FloatRect b2 = t2.getLocalBounds();
        t2.setOrigin({ b2.position.x + b2.size.x / 2.f, b2.position.y });
        t2.setPosition({ ventana.getSize().x / 2.f, 160.f });
        ventana.draw(t2);

        string cursor = inputN + (((int)(ventana.getSize().x) % 60 < 30) ? "|" : " ");
        sf::Text t3(fuente, cursor, 28);
        t3.setFillColor(sf::Color(200, 40, 40));
        sf::FloatRect b3 = t3.getLocalBounds();
        t3.setOrigin({ b3.position.x + b3.size.x / 2.f, b3.position.y });
        t3.setPosition({ ventana.getSize().x / 2.f, 210.f });
        ventana.draw(t3);

        sf::Text t4(fuente, "Presiona Enter para confirmar", 13);
        t4.setFillColor(sf::Color(160, 160, 160));
        sf::FloatRect b4 = t4.getLocalBounds();
        t4.setOrigin({ b4.position.x + b4.size.x / 2.f, b4.position.y });
        t4.setPosition({ ventana.getSize().x / 2.f, 280.f });
        ventana.draw(t4);

        ventana.display();
    }
    if (!ventana.isOpen()) return false;

    A = new CSparseMatrix<double>(n, n + 1);

    // --- Pedir filas ---
    int filaActual = 0;
    string inputFila = "";

    while (ventana.isOpen() && filaActual < n) {
        while (const auto ev = ventana.pollEvent()) {
            if (ev->is<sf::Event::Closed>()) { ventana.close(); return false; }
            if (const auto* kp = ev->getIf<sf::Event::KeyPressed>()) {
                if (kp->scancode == sf::Keyboard::Scancode::Escape)
                {
                    ventana.close(); return false;
                }
                if (kp->scancode == sf::Keyboard::Scancode::Backspace && !inputFila.empty())
                    inputFila.pop_back();
                if (kp->scancode == sf::Keyboard::Scancode::Enter && !inputFila.empty()) {
                    // validar que tenga n+1 valores
                    stringstream ss(inputFila); string tok; int cnt = 0;
                    while (getline(ss, tok, ',')) cnt++;
                    if (cnt == n + 1) {
                        parsearFila(inputFila, *A, filaActual, n);
                        filaActual++;
                        inputFila = "";
                    }
                }
            }
            if (const auto* tc = ev->getIf<sf::Event::TextEntered>()) {
                char c = (char)tc->unicode;
                if ((c >= '0' && c <= '9') || c == '-' || c == ',' || c == '.')
                    inputFila += c;
            }
        }

        ventana.clear(sf::Color(250, 250, 248));

        // Título
        sf::Text tt(fuente, "Ingresa los coeficientes", 18);
        tt.setFillColor(sf::Color(30, 30, 30));
        sf::FloatRect btx = tt.getLocalBounds();
        tt.setOrigin({ btx.position.x + btx.size.x / 2.f, btx.position.y });
        tt.setPosition({ ventana.getSize().x / 2.f, 20.f });
        ventana.draw(tt);

        // Subtitulo formato
        string fmt = "formato: ";
        for (int k = 1; k <= n; k++) fmt += "a" + to_string(k) + (k < n ? "," : "|b -> ");
        for (int k = 1; k <= n; k++) fmt += "x" + to_string(k);
        sf::Text ts(fuente, fmt, 12);
        ts.setFillColor(sf::Color(150, 150, 150));
        sf::FloatRect bts = ts.getLocalBounds();
        ts.setOrigin({ bts.position.x + bts.size.x / 2.f, bts.position.y });
        ts.setPosition({ ventana.getSize().x / 2.f, 50.f });
        ventana.draw(ts);

        // Filas ya ingresadas (preview de la matriz)
        float cellW = min(90.f, (ventana.getSize().x - 160.f) / (n + 1));
        float cellH = 50.f;
        float ox = (ventana.getSize().x - cellW * (n + 1)) / 2.f;
        float oy = 90.f;

        for (int i = 0; i < filaActual; i++) {
            for (int j = 0; j <= n; j++) {
                double val = A->get(i, j);
                ostringstream ss; ss.precision(3);
                if (val == (double)(int)val) ss << (int)val; else ss << val;
                sf::Text ct(fuente, ss.str(), 15);
                ct.setFillColor(sf::Color(30, 30, 30));
                sf::FloatRect bcb = ct.getLocalBounds();
                ct.setOrigin({ bcb.position.x + bcb.size.x / 2.f, bcb.position.y + bcb.size.y / 2.f });
                ct.setPosition({ ox + j * cellW + cellW / 2.f, oy + i * cellH + cellH / 2.f });
                ventana.draw(ct);
            }
        }

        // Línea de ingreso actual
        float lineY = oy + filaActual * cellH;
        sf::RectangleShape lineaH({ cellW * (n + 1), 1.5f });
        lineaH.setFillColor(sf::Color(200, 40, 40));
        lineaH.setPosition({ ox, lineY + cellH - 2.f });
        ventana.draw(lineaH);

        string prompt = "f" + to_string(filaActual + 1) + ":  " + inputFila + "|";
        sf::Text tp(fuente, prompt, 16);
        tp.setFillColor(sf::Color(200, 40, 40));
        tp.setPosition({ ox, lineY + cellH / 2.f - 10.f });
        ventana.draw(tp);

        // Indicacion
        sf::Text ti(fuente, "Enter para confirmar fila  |  ESC para salir", 12);
        ti.setFillColor(sf::Color(160, 160, 160));
        sf::FloatRect bti = ti.getLocalBounds();
        ti.setOrigin({ bti.position.x + bti.size.x / 2.f, bti.position.y });
        ti.setPosition({ ventana.getSize().x / 2.f, (float)ventana.getSize().y - 25.f });
        ventana.draw(ti);

        ventana.display();
    }

    return ventana.isOpen();
}

// ── Gaussiana ────────────────────────────────
void gaussiana(CSparseMatrix<double>& A, int n, sf::RenderWindow& ventana, sf::Font& fuente) {
    DibujarMatriz(A, ventana, fuente, -1, n, "Matriz aumentada");
    if (!EsperarClick(ventana)) return;

    for (int col = 0; col < n; col++) {
        int pivote = -1;
        for (int f = col; f < n; f++)
            if (A.get(f, col) != 0.0) { pivote = f; break; }
        if (pivote == -1) {
            DibujarMatriz(A, ventana, fuente, -1, n, "Sin solucion unica", "columna " + to_string(col + 1) + " sin pivote");
            EsperarCierre(ventana); return;
        }

        if (pivote != col) {
            for (int k = 0; k <= n; k++) {
                double tmp = A.get(col, k);
                A.set(col, k, A.get(pivote, k));
                A.set(pivote, k, tmp);
            }
            DibujarMatriz(A, ventana, fuente, col, n,
                "Intercambio de filas",
                "f" + to_string(col + 1) + " <-> f" + to_string(pivote + 1));
            if (!EsperarClick(ventana)) return;
        }

        double valPivote = A.get(col, col);
        for (int f = col + 1; f < n; f++) {
            double factor = A.get(f, col) / valPivote;
            if (factor == 0.0) continue;
            for (int k = col; k <= n; k++)
                A.set(f, k, A.get(f, k) - factor * A.get(col, k));
        }

        DibujarMatriz(A, ventana, fuente, col, n,
            "Eliminacion  —  paso " + to_string(col + 1) + " de " + to_string(n - 1));
        if (!EsperarClick(ventana)) return;
    }

    // Sustitución hacia atrás
    double* x = new double[n]();
    for (int f = n - 1; f >= 0; f--) {
        double suma = A.get(f, n);
        for (int k = f + 1; k < n; k++) suma -= A.get(f, k) * x[k];
        x[f] = suma / A.get(f, f);
    }

    // Construir string resultado: linea de variables + linea "CS = {(...)}"
    // como en la pizarra de tu profesor
    ostringstream ssVars, ssCS;
    ssVars.precision(5);
    ssCS.precision(5);
    ssCS << "CS = {(";
    for (int i = 0; i < n; i++) {
        ssVars << "x" << (i + 1) << " = " << x[i];
        if (i < n - 1) ssVars << "     ";
        ssCS << x[i];
        if (i < n - 1) ssCS << ", ";
    }
    ssCS << ")}";
    string res = ssVars.str() + "\n" + ssCS.str();

    // NUEVO: pantalla final usa EsperarCierre, no EsperarClick.
    // El resultado se queda en pantalla hasta que el usuario presione
    // ESC o cierre la ventana — ya no se cierra solo de la nada.
    DibujarMatriz(A, ventana, fuente, -1, n, "Forma escalonada", res,
        "ESC o cierra la ventana para salir");
    EsperarCierre(ventana);
    delete[] x;
}

// ── Main ─────────────────────────────────────
int main() {
    // Ventana de tamaño fijo, suficiente para hasta 9 variables.
    // Así nunca se redimensiona ni se recentra a media ejecucion.
    const unsigned int ANCHO = 1060u, ALTO = 830u;
    sf::RenderWindow ventana(sf::VideoMode({ ANCHO, ALTO }), "Eliminacion Gaussiana");
    ventana.setFramerateLimit(60);

    auto desktop = sf::VideoMode::getDesktopMode();
    ventana.setPosition({ (int)(desktop.size.x - ANCHO) / 2,
                         (int)(desktop.size.y - ALTO) / 2 });

    sf::Font fuente;
    if (!cargarFuenteSistema(fuente)) return 1;

    int n = 0;
    CSparseMatrix<double>* A = nullptr;

    if (!PantallaIngreso(ventana, fuente, n, A)) return 0;
    if (A) {
        gaussiana(*A, n, ventana, fuente);
        delete A;
    }
    return 0;
}