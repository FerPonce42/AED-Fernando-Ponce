#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <optional>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "DibujarMatriz.h"
using namespace std;

static const string TITULO = "09_EcuacionesLinealesSFML";

template <typename T>
struct SNodo {
    int col;
    T valor;
    SNodo<T>* siguiente;

    SNodo(int c, T v) : col(c), valor(v), siguiente(nullptr) {}
};

template <typename T>
struct SFila {
    int fila;
    SNodo<T>* head;
    SFila<T>* siguiente;

    SFila(int f) : fila(f), head(nullptr), siguiente(nullptr) {}
};

template <typename T>
class CSparseMatrix {
public:
    int nfilas, ncols;

    CSparseMatrix(int f, int c) : nfilas(f), ncols(c), head(nullptr) {}

    ~CSparseMatrix() {
        SFila<T>* f = head;
        while (f != nullptr) {
            SNodo<T>* c = f->head;
            while (c != nullptr) {
                auto* t = c;
                c = c->siguiente;
                delete t;
            }
            auto* t = f;
            f = f->siguiente;
            delete t;
        }
    }

    SFila<T>** findx(int f) {
        SFila<T>** p;
        for (p = &head; *p != nullptr && (*p)->fila < f; p = &(*p)->siguiente) {}
        return p;
    }

    SNodo<T>** findy(SFila<T>* fila, int c) {
        SNodo<T>** p;
        for (p = &fila->head; *p != nullptr && (*p)->col < c; p = &(*p)->siguiente) {}
        return p;
    }

    void set(int f, int c, T val) {
        if (abs(val) < 1e-10) {
            SFila<T>** fp = findx(f);
            if (!(*fp) || (*fp)->fila != f) {
                return;
            }
            SNodo<T>** cp = findy(*fp, c);
            if (!(*cp) || (*cp)->col != c) {
                return;
            }
            auto* tmp = *cp;
            *cp = tmp->siguiente;
            delete tmp;
            return;
        }
        SFila<T>* fila = getFila(f);
        SNodo<T>** cp = findy(fila, c);
        if (*cp != nullptr && (*cp)->col == c) {
            (*cp)->valor = val;
        }
        else {
            auto* n = new SNodo<T>(c, val);
            n->siguiente = *cp;
            *cp = n;
        }
    }

    T get(int f, int c) {
        SFila<T>** fp = findx(f);
        if (!(*fp) || (*fp)->fila != f) {
            return T(0);
        }
        SNodo<T>** cp = findy(*fp, c);
        if (!(*cp) || (*cp)->col != c) {
            return T(0);
        }
        return (*cp)->valor;
    }

private:
    SFila<T>* head;

    SFila<T>* getFila(int f) {
        SFila<T>** p = findx(f);
        if (!(*p) || (*p)->fila != f) {
            auto* n = new SFila<T>(f);
            n->siguiente = *p;
            *p = n;
        }
        return *p;
    }
};

void parsearFila(const string& linea, CSparseMatrix<double>& A, int fila, int n) {
    stringstream ss(linea);
    string token;
    int col = 0;
    while (getline(ss, token, ',') && col <= n) {
        double val = stod(token);
        if (abs(val) > 1e-10) {
            A.set(fila, col, val);
        }
        col++;
    }
}

string opStr(int fDest, int fPiv, double factor) {
    string s = "f" + to_string(fDest + 1) + " \u2192 ";
    double coef = -factor;
    string cs;
    if (abs(coef - round(coef)) < 1e-9) {
        int ci = (int)round(coef);
        if (ci == 1) {
            cs = "";
        }
        else if (ci == -1) {
            cs = "-";
        }
        else {
            cs = to_string(ci);
        }
    }
    else {
        ostringstream oss;
        oss.precision(2);
        oss << fixed << coef;
        cs = oss.str();
    }
    s += cs + "f" + to_string(fPiv + 1) + " + f" + to_string(fDest + 1);
    return s;
}

int maxOpsLen(const vector<string>& ops) {
    int mx = 0;
    for (const auto& s : ops) {
        mx = max(mx, (int)s.size());
    }
    return mx;
}

bool PantallaIngreso(sf::RenderWindow& ventana, sf::Font& fuente, int& n, CSparseMatrix<double>*& A) {
    const sf::Color BG = sf::Color(28, 32, 38);
    const sf::Color WHITE = sf::Color(230, 235, 240);
    const sf::Color CYAN = sf::Color(80, 190, 210);
    const sf::Color GRAY = sf::Color(80, 90, 105);

    recrearVentana(ventana, 420u, 320u, TITULO);

    auto dc = [&](const string& t, unsigned int sz, float y, sf::Color col) {
        sf::Text tx(fuente, t, sz);
        tx.setFillColor(col);
        sf::FloatRect b = tx.getLocalBounds();
        tx.setOrigin({ b.position.x + b.size.x / 2.f, b.position.y });
        tx.setPosition({ (float)ventana.getSize().x / 2.f, y });
        ventana.draw(tx);
        };

    string inputN = "";
    bool nOk = false;
    while (ventana.isOpen() && !nOk) {
        while (const auto ev = ventana.pollEvent()) {
            if (ev->is<sf::Event::Closed>()) {
                ventana.close();
                return false;
            }
            if (const auto* kp = ev->getIf<sf::Event::KeyPressed>()) {
                if (kp->scancode == sf::Keyboard::Scancode::Escape) {
                    ventana.close();
                    return false;
                }
                if (kp->scancode == sf::Keyboard::Scancode::Backspace && !inputN.empty()) {
                    inputN.pop_back();
                }
                if (kp->scancode == sf::Keyboard::Scancode::Enter && !inputN.empty()) {
                    n = stoi(inputN);
                    if (n >= 2 && n <= 9) {
                        nOk = true;
                    }
                    else {
                        inputN = "";
                    }
                }
            }
            if (const auto* tc = ev->getIf<sf::Event::TextEntered>()) {
                char c = (char)tc->unicode;
                if (c >= '2' && c <= '9') {
                    inputN += c;
                }
            }
        }
        ventana.clear(BG);
        dc("Eliminacion Gaussiana", 16, 70.f, WHITE);
        dc("numero de variables  (2 - 9)", 12, 130.f, GRAY);
        dc(inputN + "|", 22, 165.f, CYAN);
        dc("Enter para confirmar", 10, 230.f, GRAY);
        ventana.display();
    }
    if (!ventana.isOpen()) {
        return false;
    }

    A = new CSparseMatrix<double>(n, n + 1);

    unsigned int h = max(280u, (unsigned int)(110 + n * 56 + 50));
    recrearVentana(ventana, 460u, h, TITULO);

    int filaActual = 0;
    string inputFila = "";
    while (ventana.isOpen() && filaActual < n) {
        while (const auto ev = ventana.pollEvent()) {
            if (ev->is<sf::Event::Closed>()) {
                ventana.close();
                return false;
            }
            if (const auto* kp = ev->getIf<sf::Event::KeyPressed>()) {
                if (kp->scancode == sf::Keyboard::Scancode::Escape) {
                    ventana.close();
                    return false;
                }
                if (kp->scancode == sf::Keyboard::Scancode::Backspace && !inputFila.empty()) {
                    inputFila.pop_back();
                }
                if (kp->scancode == sf::Keyboard::Scancode::Enter && !inputFila.empty()) {
                    stringstream ss(inputFila);
                    string tok;
                    int cnt = 0;
                    while (getline(ss, tok, ',')) {
                        cnt++;
                    }
                    if (cnt == n + 1) {
                        parsearFila(inputFila, *A, filaActual, n);
                        filaActual++;
                        inputFila = "";
                    }
                }
            }
            if (const auto* tc = ev->getIf<sf::Event::TextEntered>()) {
                char c = (char)tc->unicode;
                if ((c >= '0' && c <= '9') || c == '-' || c == ',' || c == '.') {
                    inputFila += c;
                }
            }
        }

        ventana.clear(BG);
        float W = (float)ventana.getSize().x;

        auto dcl = [&](const string& t, unsigned int sz, float y, sf::Color col) {
            sf::Text tx(fuente, t, sz);
            tx.setFillColor(col);
            sf::FloatRect b = tx.getLocalBounds();
            tx.setOrigin({ b.position.x + b.size.x / 2.f, b.position.y });
            tx.setPosition({ W / 2.f, y });
            ventana.draw(tx);
            };

        dcl("Ingresa los coeficientes", 14, 14.f, WHITE);
        string fmt = "";
        for (int k = 1; k <= n; k++) {
            fmt += "a" + to_string(k) + (k < n ? "," : "|b");
        }
        dcl(fmt, 10, 38.f, GRAY);

        float cellW = min(70.f, (W - 100.f) / (n + 1));
        float cellH = 50.f;
        float ox = (W - cellW * (n + 1)) / 2.f;
        float oy = 64.f;

        for (int i = 0; i < filaActual; i++) {
            for (int j = 0; j <= n; j++) {
                double val = A->get(i, j);
                sf::Text ct(fuente, fmtNum(val), 13);
                ct.setFillColor(WHITE);
                sf::FloatRect bcb = ct.getLocalBounds();
                ct.setOrigin({ bcb.position.x + bcb.size.x / 2.f, bcb.position.y + bcb.size.y / 2.f });
                ct.setPosition({ ox + j * cellW + cellW / 2.f, oy + i * cellH + cellH / 2.f });
                ventana.draw(ct);
            }
            if (i > 0) {
                sf::RectangleShape lh({ cellW * (n + 1), 1.f });
                lh.setFillColor(GRAY);
                lh.setPosition({ ox, oy + i * cellH });
                ventana.draw(lh);
            }
        }

        float lineY = oy + filaActual * cellH;
        sf::RectangleShape lr({ cellW * (n + 1), 1.f });
        lr.setFillColor(CYAN);
        lr.setPosition({ ox, lineY + cellH - 2.f });
        ventana.draw(lr);

        sf::Text tp(fuente, "f" + to_string(filaActual + 1) + ":  " + inputFila + "|", 13);
        tp.setFillColor(CYAN);
        tp.setPosition({ ox, lineY + cellH / 2.f - 9.f });
        ventana.draw(tp);

        dcl("Enter confirma   ESC salir", 10, (float)ventana.getSize().y - 18.f, GRAY);
        ventana.display();
    }
    return ventana.isOpen();
}

struct Paso {
    vector<vector<double>> mat;
    string titulo;
    vector<string> ops;
    int pivoteFila;
};

void agregarPaso(CSparseMatrix<double>& A, int n, vector<Paso>& hist,
    const string& titulo, const vector<string>& ops, int pivoteFila) {
    Paso p;
    p.titulo = titulo;
    p.ops = ops;
    p.pivoteFila = pivoteFila;
    for (int i = 0; i < n; i++) {
        vector<double> fila;
        for (int j = 0; j <= n; j++) {
            fila.push_back(A.get(i, j));
        }
        p.mat.push_back(fila);
    }
    hist.push_back(p);
}

// algoritmo del video ucsp sistemas de ecuaciones 3 variables gauss 1
void gaussJordan(CSparseMatrix<double>& A, int n, sf::RenderWindow& ventana, sf::Font& fuente) {
    vector<Paso> hist;
    agregarPaso(A, n, hist, "Matriz aumentada", {}, -1);

    for (int col = 0; col < n; col++) {
        int pivote = -1;
        for (int f = col; f < n; f++) {
            if (abs(A.get(f, col)) > 1e-10) {
                pivote = f;
                break;
            }
        }
        if (pivote == -1) {
            agregarPaso(A, n, hist, "Sin solucion unica", { "col " + to_string(col + 1) + " sin pivote" }, -1);
            break;
        }
        if (pivote != col) {
            for (int k = 0; k <= n; k++) {
                double tmp = A.get(col, k);
                A.set(col, k, A.get(pivote, k));
                A.set(pivote, k, tmp);
            }
            vector<string> ops(n, "");
            ops[col] = "f" + to_string(col + 1) + " \u2194 f" + to_string(pivote + 1);
            ops[pivote] = "f" + to_string(pivote + 1) + " \u2194 f" + to_string(col + 1);
            agregarPaso(A, n, hist, "Intercambio de filas", ops, col);
        }
        double vp = A.get(col, col);
        vector<string> ops(n, "");
        bool hayOp = false;
        for (int f = col + 1; f < n; f++) {
            double factor = A.get(f, col) / vp;
            if (abs(factor) < 1e-10) {
                continue;
            }
            for (int k = col; k <= n; k++) {
                A.set(f, k, A.get(f, k) - factor * A.get(col, k));
            }
            ops[f] = opStr(f, col, factor);
            hayOp = true;
        }
        if (hayOp) {
            agregarPaso(A, n, hist, "Eliminacion  paso " + to_string(col + 1), ops, col);
        }
    }

    {
        vector<string> ops(n, "");
        bool hayOp = false;
        for (int f = 0; f < n; f++) {
            double piv = A.get(f, f);
            if (abs(piv - 1.0) < 1e-10) {
                continue;
            }
            double inv = 1.0 / piv;
            for (int k = f; k <= n; k++) {
                A.set(f, k, A.get(f, k) * inv);
            }
            ops[f] = "(1/" + fmtNum(piv) + ") f" + to_string(f + 1);
            hayOp = true;
        }
        if (hayOp) {
            agregarPaso(A, n, hist, "Normalizacion de pivotes", ops, -1);
        }
    }

    for (int col = n - 1; col >= 1; col--) {
        vector<string> ops(n, "");
        bool hayOp = false;
        for (int f = col - 1; f >= 0; f--) {
            double factor = A.get(f, col);
            if (abs(factor) < 1e-10) {
                continue;
            }
            for (int k = col; k <= n; k++) {
                A.set(f, k, A.get(f, k) - factor * A.get(col, k));
            }
            ops[f] = opStr(f, col, factor);
            hayOp = true;
        }
        if (hayOp) {
            agregarPaso(A, n, hist, "Eliminacion hacia arriba  col " + to_string(col + 1), ops, col);
        }
    }

    {
        ostringstream ssV, ssCS;
        ssCS << "CS = {(";
        for (int i = 0; i < n; i++) {
            double xi = A.get(i, n);
            ssV << "x" << (i + 1) << " = " << fmtNum(xi);
            if (i < n - 1) {
                ssV << "   ";
            }
            ssCS << fmtNum(xi);
            if (i < n - 1) {
                ssCS << ", ";
            }
        }
        ssCS << ")}";
        vector<string> ops(n, "");
        ops[0] = ssV.str();
        if (n >= 2) {
            ops[1] = ssCS.str();
        }
        agregarPaso(A, n, hist, "Forma escalonada reducida", ops, -1);
    }

    int maxLen = 0;
    for (const auto& p : hist) {
        maxLen = max(maxLen, maxOpsLen(p.ops));
    }

    auto tam = tamanoParaN(n, maxLen);
    recrearVentana(ventana, tam.x, tam.y, TITULO);

    int idx = 0;
    while (ventana.isOpen()) {
        const Paso& p = hist[idx];
        CSparseMatrix<double> tmp(n, n + 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= n; j++) {
                if (abs(p.mat[i][j]) > 1e-10) {
                    tmp.set(i, j, p.mat[i][j]);
                }
            }
        }

        bool esUltimo = (idx == (int)hist.size() - 1);
        string hint;
        if (esUltimo) {
            hint = "\u2190 retroceder   ESC salir";
        }
        else if (idx == 0) {
            hint = "\u2192 continuar   ESC salir";
        }
        else {
            hint = "\u2192 continuar   \u2190 retroceder   ESC salir";
        }

        DibujarMatriz(tmp, ventana, fuente, p.pivoteFila, n, p.titulo, p.ops, hint);

        int nav = EsperarNavegacion(ventana);
        if (nav == 0) {
            break;
        }
        if (nav == +1 && idx < (int)hist.size() - 1) {
            idx++;
        }
        if (nav == -1 && idx > 0) {
            idx--;
        }
    }
}

int main() {
    sf::RenderWindow ventana(sf::VideoMode({ 420u, 320u }), TITULO);
    ventana.setFramerateLimit(60);
    auto desktop = sf::VideoMode::getDesktopMode();
    ventana.setPosition({ (int)(desktop.size.x - 420) / 2, (int)(desktop.size.y - 320) / 2 });

    sf::Font fuente;
    if (!cargarFuenteSistema(fuente)) {
        return 1;
    }

    int n = 0;
    CSparseMatrix<double>* A = nullptr;
    if (!PantallaIngreso(ventana, fuente, n, A)) {
        return 0;
    }
    if (A) {
        gaussJordan(*A, n, ventana, fuente);
        delete A;
    }
    return 0;
}