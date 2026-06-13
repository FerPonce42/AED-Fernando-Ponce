#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <map>
#include <functional>
using namespace std;

// ===================== AVL =====================

struct Node
{
    int value, height;
    Node* nodes[2];
    Node* parent;
    Node(int v) : value(v), height(1), parent(nullptr) { nodes[0] = nodes[1] = nullptr; }
};

int Height(Node* n) { return n ? n->height : 0; }
void UpdateHeight(Node* n) { if (!n) return; n->height = max(Height(n->nodes[0]), Height(n->nodes[1])) + 1; }
int FB(Node* n) { return n ? Height(n->nodes[0]) - Height(n->nodes[1]) : 0; }

// BST simple sin rotaciones — el árbol llega desbalanceado a propósito
Node* InsertBST(Node* root, int v, Node* parent = nullptr)
{
    if (!root) { Node* n = new Node(v); n->parent = parent; return n; }
    if (v < root->value)      root->nodes[0] = InsertBST(root->nodes[0], v, root);
    else if (v > root->value) root->nodes[1] = InsertBST(root->nodes[1], v, root);
    UpdateHeight(root);
    return root;
}

// ---- Utilidades ----

bool TodosFBCero(Node* n)
{
    if (!n) return true;
    if (FB(n) != 0) return false;
    return TodosFBCero(n->nodes[0]) && TodosFBCero(n->nodes[1]);
}

Node* CopiarArbol(Node* n, Node* parent = nullptr)
{
    if (!n) return nullptr;
    Node* c = new Node(n->value); c->height = n->height; c->parent = parent;
    c->nodes[0] = CopiarArbol(n->nodes[0], c);
    c->nodes[1] = CopiarArbol(n->nodes[1], c);
    return c;
}

void LiberarArbol(Node* n) { if (!n) return; LiberarArbol(n->nodes[0]); LiberarArbol(n->nodes[1]); delete n; }

// Profundidad máxima del árbol (raíz = nivel 0)
int ProfundidadMax(Node* n)
{
    if (!n) return -1;
    return 1 + max(ProfundidadMax(n->nodes[0]), ProfundidadMax(n->nodes[1]));
}

// Recolecta las hojas que están exactamente en el nivel "profMax"
void RecolectarHojasProfundas(Node* n, int nivel, int profMax, vector<Node*>& h)
{
    if (!n) return;
    if (!n->nodes[0] && !n->nodes[1])
    {
        if (nivel == profMax) h.push_back(n);
        return;
    }
    RecolectarHojasProfundas(n->nodes[0], nivel + 1, profMax, h);
    RecolectarHojasProfundas(n->nodes[1], nivel + 1, profMax, h);
}

// Recalcula heights de todo el arbol (post-orden)
void RecalcularHeights(Node* n)
{
    if (!n) return;
    RecalcularHeights(n->nodes[0]);
    RecalcularHeights(n->nodes[1]);
    UpdateHeight(n);
}

// ===================== PODAR =====================
// Poda hojas nivel por nivel (el más profundo primero) hasta que todos los FB sean 0.
// Devuelve los snapshots: [arbol original, tras poda1, tras poda2, ...]
vector<Node*> Podar(Node* raizOrig)
{
    vector<Node*> snaps;
    snaps.push_back(CopiarArbol(raizOrig));

    Node* t = CopiarArbol(raizOrig);

    while (!TodosFBCero(t))
    {
        int pm = ProfundidadMax(t);

        vector<Node*> hojas;
        RecolectarHojasProfundas(t, 0, pm, hojas);

        if (hojas.empty() || (hojas.size() == 1 && hojas[0] == t)) break;

        for (Node* h : hojas)
        {
            Node* p = h->parent;
            if (p) { if (p->nodes[0] == h) p->nodes[0] = nullptr; else p->nodes[1] = nullptr; }
            delete h;
        }

        RecalcularHeights(t);
        snaps.push_back(CopiarArbol(t));
    }

    LiberarArbol(t);
    return snaps;
}

// ===================== POSICIONES =====================

void CalcPos(Node* n, int nivel, int& cnt, float aw, float ah, map<Node*, sf::Vector2f>& pos)
{
    if (!n) return;
    CalcPos(n->nodes[0], nivel + 1, cnt, aw, ah, pos);
    pos[n] = sf::Vector2f(cnt * aw, nivel * ah + 70.f);
    cnt++;
    CalcPos(n->nodes[1], nivel + 1, cnt, aw, ah, pos);
}

void RefrescarPos(Node* raiz, map<Node*, sf::Vector2f>& pos, unsigned int winW,
    float aw = 64.f, float ah = 88.f)
{
    pos.clear();
    if (!raiz) return;
    int cnt = 0;
    CalcPos(raiz, 0, cnt, aw, ah, pos);
    float minX = 1e9f, maxX = -1e9f;
    for (auto& p : pos) { minX = min(minX, p.second.x); maxX = max(maxX, p.second.x); }
    float offset = ((float)winW - (maxX - minX)) / 2.f - minX;
    for (auto& p : pos) p.second.x += offset;
}

// ===================== DIBUJO =====================

void DibujarNodo(Node* n, sf::Vector2f pos, sf::RenderWindow& w, sf::Font& font,
    sf::Color fill, sf::Color tc)
{
    float r = 22.f;
    sf::CircleShape c(r);
    c.setFillColor(fill);
    c.setOutlineColor(sf::Color(40, 40, 40));
    c.setOutlineThickness(2.f);
    c.setOrigin(sf::Vector2f(r, r));
    c.setPosition(pos);
    w.draw(c);

    // Factor de balance encima del nodo
    int fb = FB(n);
    sf::Text tfb(font);
    tfb.setString(to_string(fb));
    tfb.setCharacterSize(12);
    tfb.setFillColor(fb != 0 ? sf::Color(200, 40, 40) : sf::Color(120, 120, 120));
    sf::FloatRect b = tfb.getLocalBounds();
    tfb.setOrigin(sf::Vector2f(b.position.x + b.size.x / 2.f, b.position.y + b.size.y + 2.f));
    tfb.setPosition(sf::Vector2f(pos.x, pos.y - r - 1.f));
    w.draw(tfb);

    // Valor dentro
    sf::Text tv(font);
    tv.setString(to_string(n->value));
    tv.setCharacterSize(15);
    tv.setFillColor(tc);
    sf::FloatRect bv = tv.getLocalBounds();
    tv.setOrigin(sf::Vector2f(bv.position.x + bv.size.x / 2.f, bv.position.y + bv.size.y / 2.f));
    tv.setPosition(pos);
    w.draw(tv);
}

void DibujarArbol(sf::RenderWindow& window, sf::Font& font,
    map<Node*, sf::Vector2f>& pos,
    const vector<int>& hojasNaranja = {})
{
    // Aristas
    for (auto& par : pos)
    {
        Node* n = par.first;
        for (int i = 0; i < 2; i++)
            if (n->nodes[i] && pos.count(n->nodes[i]))
            {
                sf::Vertex ln[2] = {
                    sf::Vertex(par.second,         sf::Color(110,110,110)),
                    sf::Vertex(pos[n->nodes[i]],   sf::Color(110,110,110))
                };
                window.draw(ln, 2, sf::PrimitiveType::Lines);
            }
    }

    // Nodos
    for (auto& par : pos)
    {
        Node* n = par.first;
        bool esNaranja = false;
        for (int v : hojasNaranja) if (v == n->value) { esNaranja = true; break; }

        if (esNaranja)
            DibujarNodo(n, par.second, window, font, sf::Color(220, 80, 0), sf::Color::White);
        else
            DibujarNodo(n, par.second, window, font, sf::Color::White, sf::Color::Black);
    }
}

// ===================== UI =====================

void DibujarUI(sf::RenderWindow& window, sf::Font& font,
    const string& msg, int paso, int total, bool yaBalanceado)
{
    sf::Vector2u tam = window.getSize();
    float y = (float)tam.y - 62.f;

    sf::RectangleShape barra(sf::Vector2f((float)tam.x, 62.f));
    barra.setPosition(sf::Vector2f(0.f, y));
    barra.setFillColor(sf::Color(225, 225, 225, 235));
    window.draw(barra);

    string instrTxt = yaBalanceado
        ? "[Arbol balanceado - todos FB = 0]   [Esc] Salir"
        : "[Space] Siguiente poda   [Esc] Salir";

    sf::Text ti(font);
    ti.setString(instrTxt);
    ti.setCharacterSize(13);
    ti.setFillColor(yaBalanceado ? sf::Color(0, 140, 60) : sf::Color(80, 80, 80));
    ti.setPosition(sf::Vector2f(10.f, y + 5.f));
    window.draw(ti);

    sf::Text tp(font);
    tp.setString("Vuelta " + to_string(paso) + " / " + to_string(total));
    tp.setCharacterSize(13);
    tp.setFillColor(sf::Color(140, 140, 140));
    sf::FloatRect btp = tp.getLocalBounds();
    tp.setPosition(sf::Vector2f((float)tam.x - btp.size.x - 12.f, y + 5.f));
    window.draw(tp);

    if (!msg.empty())
    {
        sf::Text tm(font);
        tm.setString(msg);
        tm.setCharacterSize(15);
        tm.setFillColor(sf::Color(20, 20, 180));
        tm.setPosition(sf::Vector2f(10.f, y + 26.f));
        window.draw(tm);
    }

    sf::Text tleg(font);
    tleg.setString("numero sobre cada nodo = factor de balance  |  rojo = desbalanceado");
    tleg.setCharacterSize(11);
    tleg.setFillColor(sf::Color(170, 170, 170));
    tleg.setPosition(sf::Vector2f(10.f, y + 46.f));
    window.draw(tleg);
}

// ===================== MAIN =====================

int main()
{
    sf::Font font;
    if (!font.openFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf"))
        if (!font.openFromFile("C:/Windows/Fonts/arial.ttf"))
        {
            cerr << "Fuente no encontrada.\n"; return 1;
        }

    // --- Arbol inicial: cambiar estos valores segun lo que pida el profe ---
    Node* raizBase = nullptr;
    for (int v : {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 45, 5, 15, 22, 27, 33, 38, 42, 48})
        raizBase = InsertBST(raizBase, v);

    // --- Generar todos los snapshots con Podar() ---
    vector<Node*> snaps = Podar(raizBase);
    LiberarArbol(raizBase);

    int paso = 0;
    int total = (int)snaps.size() - 1;   // numero de podas disponibles

    const unsigned int WIN_W = 820, WIN_H = 500;
    sf::RenderWindow window(sf::VideoMode({ WIN_W, WIN_H }), "Arbol AVL - Poda");
    window.setFramerateLimit(60);

    string msgTmp;
    sf::Clock relojMsg;
    auto setMsg = [&](const string& m) { msgTmp = m; relojMsg.restart(); };

    // Flash naranja: valores de hojas justo antes de la poda
    vector<int> flashVals;
    bool flashActivo = false;
    sf::Clock relojFlash;

    map<Node*, sf::Vector2f> pos;
    auto refrescar = [&]() { RefrescarPos(snaps[paso], pos, WIN_W); };
    refrescar();

    while (window.isOpen())
    {
        while (auto evOpt = window.pollEvent())
        {
            sf::Event ev = *evOpt;
            if (ev.is<sf::Event::Closed>()) window.close();

            if (const auto* key = ev.getIf<sf::Event::KeyPressed>())
            {
                if (key->code == sf::Keyboard::Key::Escape) window.close();

                if (key->code == sf::Keyboard::Key::Space)
                {
                    bool balanceado = TodosFBCero(snaps[paso]);

                    if (balanceado)
                    {
                        setMsg("El arbol ya esta balanceado (todos FB = 0).");
                    }
                    else if (paso < total)
                    {
                        // Marcar las hojas mas profundas del snap actual para flash naranja
                        int pm = ProfundidadMax(snaps[paso]);
                        vector<Node*> hojas;
                        RecolectarHojasProfundas(snaps[paso], 0, pm, hojas);
                        flashVals.clear();
                        for (Node* h : hojas) flashVals.push_back(h->value);
                        flashActivo = true;
                        relojFlash.restart();

                        paso++;
                        refrescar();

                        if (TodosFBCero(snaps[paso]))
                            setMsg("Arbol balanceado. Todos los FB = 0.");
                        else
                            setMsg("Poda " + to_string(paso) + " aplicada.");
                    }
                    else
                    {
                        setMsg("No quedan mas podas disponibles.");
                    }
                }
            }
        }

        // Apagar flash despues de 0.6 s
        if (flashActivo && relojFlash.getElapsedTime().asSeconds() > 0.6f)
        {
            flashActivo = false; flashVals.clear();
        }

        // Limpiar mensaje despues de 3 s
        if (!msgTmp.empty() && relojMsg.getElapsedTime().asSeconds() > 3.f)
            msgTmp.clear();

        // --- Render ---
        window.clear(sf::Color(248, 248, 248));

        if (snaps[paso])
        {
            if (flashActivo && paso > 0)
            {
                map<Node*, sf::Vector2f> posAnterior;
                RefrescarPos(snaps[paso - 1], posAnterior, WIN_W);
                DibujarArbol(window, font, posAnterior, flashVals);
            }
            else
            {
                DibujarArbol(window, font, pos, {});
            }
        }

        bool yaBalanceado = TodosFBCero(snaps[paso]);
        DibujarUI(window, font, msgTmp, paso, total, yaBalanceado);

        window.display();
    }

    for (Node* s : snaps) LiberarArbol(s);
    return 0;
}