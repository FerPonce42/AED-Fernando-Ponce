/*

Clase 12 - 05 - 26

Arbol Balanceado

ARBOL AVL



Busca que no se disotrsiene, para que se hagan rotaciones  y siempre se vea balanceado.
Esto ocurre luego de la insercción, chekea arregla.

El mismo arbol, con un POST proceso luego de la insercción.dadadadasdadad

*/

#include <iostream>
#include <algorithm>

using namespace std;

struct Node
{
    int value;
    int height;

    Node* left;
    Node* right;

    Node(int v)
    {
        value = v;
        height = 1;

        left = nullptr;
        right = nullptr;
    }
};

class AVL
{
private:

    Node* root;

    int Height(Node* n)
    {
        return (n == nullptr) ? 0 : n->height;
    }

    int Balance(Node* n)
    {
        if (n == nullptr)
            return 0;

        return Height(n->left) - Height(n->right);
    }

    void UpdateHeight(Node* n)
    {
        if (n == nullptr)
            return;

        n->height =
            1 + max(Height(n->left),
                    Height(n->right));
    }

    Node* RotateRight(Node* y)
    {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        UpdateHeight(y);
        UpdateHeight(x);

        return x;
    }

    Node* RotateLeft(Node* x)
    {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        UpdateHeight(x);
        UpdateHeight(y);

        return y;
    }

    Node* Insert(Node* node, int value)
    {
        if (node == nullptr)
            return new Node(value);

        if (value < node->value)
            node->left = Insert(node->left, value);

        else if (value > node->value)
            node->right = Insert(node->right, value);

        else
            return node;

        UpdateHeight(node);

        int fb = Balance(node);

        // LL
        if (fb > 1 &&
            value < node->left->value)
        {
            return RotateRight(node);
        }

        // RR
        if (fb < -1 &&
            value > node->right->value)
        {
            return RotateLeft(node);
        }

        // LR
        if (fb > 1 &&
            value > node->left->value)
        {
            node->left = RotateLeft(node->left);
            return RotateRight(node);
        }

        // RL
        if (fb < -1 &&
            value < node->right->value)
        {
            node->right = RotateRight(node->right);
            return RotateLeft(node);
        }

        return node;
    }

    void InOrden(Node* n)
    {
        if (!n) return;

        InOrden(n->left);
        cout << n->value << " ";
        InOrden(n->right);
    }

    void PreOrden(Node* n)
    {
        if (!n) return;

        cout << n->value << " ";
        PreOrden(n->left);
        PreOrden(n->right);
    }

    void MostrarFB(Node* n)
    {
        if (!n) return;

        MostrarFB(n->left);

        cout
            << "Nodo: "
            << n->value
            << "  FB="
            << Balance(n)
            << endl;

        MostrarFB(n->right);
    }

    void Destroy(Node* n)
    {
        if (!n) return;

        Destroy(n->left);
        Destroy(n->right);

        delete n;
    }

public:

    AVL()
    {
        root = nullptr;
    }

    ~AVL()
    {
        Destroy(root);
    }

    void Insert(int value)
    {
        root = Insert(root, value);
    }

    void InOrden()
    {
        InOrden(root);
        cout << endl;
    }

    void PreOrden()
    {
        PreOrden(root);
        cout << endl;
    }

    void MostrarFactores()
    {
        MostrarFB(root);
    }
};

int main()
{
    AVL tree;

    int datos[] =
    {
        50,
        20,
        70,
        10,
        30,
        60,
        80,
        25,
        35
    };

    for (int x : datos)
        tree.Insert(x);

    cout << "INORDEN:" << endl;
    tree.InOrden();

    cout << endl;

    cout << "PREORDEN:" << endl;
    tree.PreOrden();

    cout << endl;

    cout << "FACTORES DE BALANCE:" << endl;
    tree.MostrarFactores();

    return 0;
}