#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <map>
#include <functional>
using namespace std;

struct Node
{
    int value;
    int height;
    Node* nodes[2];
    Node* parent;

    Node(int v) : value(v), height(1), parent(nullptr)
    {
        nodes[0] = nullptr;
        nodes[1] = nullptr;
    }
};

int Height(Node* n)
{
    return n ? n->height : 0;
}

void UpdateHeight(Node* n)
{
    if (!n) return;
    n->height = max(Height(n->nodes[0]), Height(n->nodes[1])) + 1;
}

int FB(Node* n)
{
    return n ? Height(n->nodes[0]) - Height(n->nodes[1]) : 0;
}

// inserta en BST normal, sin rotaciones — queda desbalanceado a proposito
Node* InsertBST(Node* root, int v, Node* parent = nullptr)
{
    if (!root)
    {
        Node* n = new Node(v);
        n->parent = parent;
        return n;
    }

    if (v < root->value)
        root->nodes[0] = InsertBST(root->nodes[0], v, root);
    else if (v > root->value)
        root->nodes[1] = InsertBST(root->nodes[1], v, root);

    UpdateHeight(root);
    return root;
}

// dice si todos los nodos tienen FB = 0
bool TodosFBCero(Node* n)
{
    if (!n) return true;
    if (FB(n) != 0) return false;
    return TodosFBCero(n->nodes[0]) && TodosFBCero(n->nodes[1]);
}

// devuelve una copia identica del arbol
Node* CopiarArbol(Node* n, Node* parent = nullptr)
{
    if (!n) return nullptr;

    Node* c = new Node(n->value);
    c->height = n->height;
    c->parent = parent;
    c->nodes[0] = CopiarArbol(n->nodes[0], c);
    c->nodes[1] = CopiarArbol(n->nodes[1], c);

    return c;
}

void LiberarArbol(Node* n)
{
    if (!n) return;
    LiberarArbol(n->nodes[0]);
    LiberarArbol(n->nodes[1]);
    delete n;
}

// cuantos niveles tiene el arbol
int ProfundidadMax(Node* n)
{
    if (!n) return -1;
    return 1 + max(ProfundidadMax(n->nodes[0]), ProfundidadMax(n->nodes[1]));
}

// agarra solo las hojas que estan en el nivel mas profundo
void RecolectarHojasProfundas(Node* n, int nivel, int profMax, vector<Node*>& h)
{
    if (!n) return;

    if (!n->nodes[0] && !n->nodes[1])
    {
        if (nivel == profMax)
            h.push_back(n);
        return;
    }

    RecolectarHojasProfundas(n->nodes[0], nivel + 1, profMax, h);
    RecolectarHojasProfundas(n->nodes[1], nivel + 1, profMax, h);
}

void RecalcularHeights(Node* n)
{
    if (!n) return;
    RecalcularHeights(n->nodes[0]);
    RecalcularHeights(n->nodes[1]);
    UpdateHeight(n);
}

// borra las hojas del nivel mas profundo una vuelta a la vez hasta que todos los FB sean 0
// guarda una foto del arbol antes y despues de cada poda
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

        if (hojas.empty() || (hojas.size() == 1 && hojas[0] == t))
            break;

        for (Node* h : hojas)
        {
            Node* p = h->parent;

            if (p)
            {
                if (p->nodes[0] == h)
                    p->nodes[0] = nullptr;
                else
                    p->nodes[1] = nullptr;
            }

            delete h;
        }

        RecalcularHeights(t);
        snaps.push_back(CopiarArbol(t));
    }

    LiberarArbol(t);
    return snaps;
}

// asigna coordenadas: x por inorden, y por nivel
void CalcPos(Node* n, int nivel, int& cnt, float aw, float ah, map<Node*, sf::Vector2f>& pos)
{
    if (!n) return;
    CalcPos(n->nodes[0], nivel + 1, cnt, aw, ah, pos);
    pos[n] = sf::Vector2f(cnt * aw, nivel * ah);
    cnt++;
    CalcPos(n->nodes[1], nivel + 1, cnt, aw, ah, pos);
}

// escala y centra todo el arbol dentro de la ventana
void RefrescarPos(Node* raiz, map<Node*, sf::Vector2f>& pos,
    unsigned int winW, unsigned int winH, float margen,
    float aw = 64.f, float ah = 88.f)
{
    pos.clear();
    if (!raiz) return;

    int cnt = 0;
    CalcPos(raiz, 0, cnt, aw, ah, pos);

    float minX = 1e9f;
    float maxX = -1e9f;
    float minY = 1e9f;
    float maxY = -1e9f;

    for (auto& p : pos)
    {
        minX = min(minX, p.second.x);
        maxX = max(maxX, p.second.x);
        minY = min(minY, p.second.y);
        maxY = max(maxY, p.second.y);
    }

    float anchoArbol = maxX - minX;
    float altoArbol = maxY - minY;

    float anchoDisponible = (float)winW - margen * 2.f;
    float altoDisponible = (float)winH - margen * 2.f;

    float escalaX = (anchoArbol > 0.f) ? (anchoDisponible / anchoArbol) : 1.f;
    float escalaY = (altoArbol > 0.f) ? (altoDisponible / altoArbol) : 1.f;

    float escala = min(escalaX, escalaY);
    escala = min(escala, 1.f);

    float anchoEscalado = anchoArbol * escala;
    float altoEscalado = altoArbol * escala;

    float offsetCentradoX = (anchoDisponible - anchoEscalado) / 2.f;
    float offsetCentradoY = (altoDisponible - altoEscalado) / 2.f;

    for (auto& p : pos)
    {
        float x = (p.second.x - minX) * escala;
        float y = (p.second.y - minY) * escala;
        p.second.x = x + margen + offsetCentradoX;
        p.second.y = y + margen + offsetCentradoY;
    }
}

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

    int fb = FB(n);

    sf::Text tfb(font);
    tfb.setString(to_string(fb));
    tfb.setCharacterSize(12);
    tfb.setFillColor(fb != 0 ? sf::Color(200, 40, 40) : sf::Color(120, 120, 120));

    sf::FloatRect b = tfb.getLocalBounds();
    tfb.setOrigin(sf::Vector2f(b.position.x + b.size.x / 2.f, b.position.y + b.size.y + 2.f));
    tfb.setPosition(sf::Vector2f(pos.x, pos.y - r - 1.f));
    w.draw(tfb);

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
    const vector<int>& hojasAzules = {})
{
    sf::Color azulPerimetro(0, 180, 220);

    for (auto& par : pos)
    {
        Node* n = par.first;

        for (int i = 0; i < 2; i++)
        {
            if (n->nodes[i] && pos.count(n->nodes[i]))
            {
                sf::Vertex ln[2] = {
                    sf::Vertex(par.second,       sf::Color(110, 110, 110)),
                    sf::Vertex(pos[n->nodes[i]], sf::Color(110, 110, 110))
                };
                window.draw(ln, 2, sf::PrimitiveType::Lines);
            }
        }
    }

    for (auto& par : pos)
    {
        Node* n = par.first;
        bool esAzul = false;

        for (int v : hojasAzules)
        {
            if (v == n->value)
            {
                esAzul = true;
                break;
            }
        }

        if (esAzul)
            DibujarNodo(n, par.second, window, font, azulPerimetro, sf::Color::White);
        else
            DibujarNodo(n, par.second, window, font, sf::Color::White, sf::Color::Black);
    }
}

void DibujarUI(sf::RenderWindow& window, sf::Font& font,
    const string& msg, int paso, int total, bool yaBalanceado)
{
    sf::Vector2u tam = window.getSize();
    float y = (float)tam.y - 62.f;

    sf::RectangleShape barra(sf::Vector2f((float)tam.x, 62.f));
    barra.setPosition(sf::Vector2f(0.f, y));
    barra.setFillColor(sf::Color(225, 225, 225, 235));
    window.draw(barra);

    sf::Text ti(font);
    ti.setString(msg);
    ti.setCharacterSize(13);
    ti.setFillColor(sf::Color(80, 80, 80));
    ti.setPosition(sf::Vector2f(10.f, y + 5.f));
    window.draw(ti);

    sf::Text tp(font);
    tp.setString("Vuelta " + to_string(paso) + " / " + to_string(total));
    tp.setCharacterSize(13);
    tp.setFillColor(sf::Color(140, 140, 140));

    sf::FloatRect btp = tp.getLocalBounds();
    tp.setPosition(sf::Vector2f((float)tam.x - btp.size.x - 12.f, y + 5.f));
    window.draw(tp);
}

int main()
{
    sf::Font font;

    vector<string> fuentes = {
        "C:/Windows/Fonts/arial.ttf",
        "C:/Windows/Fonts/segoeui.ttf",
        "C:/Windows/Fonts/tahoma.ttf",
        "C:/Windows/Fonts/verdana.ttf"
    };

    bool fontCargada = false;

    for (auto& ruta : fuentes)
    {
        if (font.openFromFile(ruta))
        {
            fontCargada = true;
            break;
        }
    }

    if (!fontCargada)
    {
        cerr << "No se pudo cargar ninguna fuente.\n";
        return 1;
    }

    vector<int> valores = { 15, 9, 20, 6, 14, 17, 64, 13, 26, 72 };

    Node* raizBase = nullptr;

    for (int v : valores)
        raizBase = InsertBST(raizBase, v);

    vector<Node*> snaps = Podar(raizBase);
    LiberarArbol(raizBase);

    int paso = 0;
    int total = (int)snaps.size() - 1;

    const unsigned int WIN_W = 1000;
    const unsigned int WIN_H = 650;
    const float MARGEN = 60.f;

    sf::RenderWindow window(sf::VideoMode({ WIN_W, WIN_H }), "08_PodarAVLSFML");
    window.setFramerateLimit(60);

    sf::Vector2u tamanoPantalla = sf::VideoMode::getDesktopMode().size;
    int posX = (int)((tamanoPantalla.x - WIN_W) / 2);
    int posY = (int)((tamanoPantalla.y - WIN_H) / 2);
    window.setPosition(sf::Vector2i(posX, posY));

    map<Node*, sf::Vector2f> pos;

    auto refrescar = [&]()
        {
            RefrescarPos(snaps[paso], pos, WIN_W, WIN_H, MARGEN);
        };

    refrescar();

    vector<int> hojasAPodar;
    bool mostrandoPreview = false;
    string mensaje;

    auto actualizarMensaje = [&]()
        {
            bool balanceado = TodosFBCero(snaps[paso]);

            if (balanceado)
                mensaje = "Arbol balanceado - todos FB = 0";
            else
                mensaje = "[Espacio] Continuar   |   [Esc] Salir";
        };

    actualizarMensaje();

    while (window.isOpen())
    {
        while (auto evOpt = window.pollEvent())
        {
            sf::Event ev = *evOpt;

            if (ev.is<sf::Event::Closed>())
                window.close();

            if (const auto* key = ev.getIf<sf::Event::KeyPressed>())
            {
                if (key->code == sf::Keyboard::Key::Escape)
                    window.close();

                if (key->code == sf::Keyboard::Key::Space)
                {
                    bool balanceado = TodosFBCero(snaps[paso]);

                    if (!balanceado && !mostrandoPreview)
                    {
                        int pm = ProfundidadMax(snaps[paso]);

                        vector<Node*> hojas;
                        RecolectarHojasProfundas(snaps[paso], 0, pm, hojas);

                        hojasAPodar.clear();

                        for (Node* h : hojas)
                            hojasAPodar.push_back(h->value);

                        mostrandoPreview = true;
                    }
                    else if (!balanceado)
                    {
                        if (paso < total)
                        {
                            paso++;
                            refrescar();
                        }

                        hojasAPodar.clear();
                        mostrandoPreview = false;
                    }

                    actualizarMensaje();
                }
            }
        }

        window.clear(sf::Color(248, 248, 248));

        if (mostrandoPreview)
            DibujarArbol(window, font, pos, hojasAPodar);
        else
            DibujarArbol(window, font, pos, {});

        bool yaBalanceado = TodosFBCero(snaps[paso]);
        DibujarUI(window, font, mensaje, paso, total, yaBalanceado);

        window.display();
    }

    for (Node* s : snaps)
        LiberarArbol(s);

    return 0;
}