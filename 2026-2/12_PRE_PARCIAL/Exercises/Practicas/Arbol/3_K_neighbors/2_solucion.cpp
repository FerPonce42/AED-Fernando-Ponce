#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////

struct CBinNode
{
    CBinNode(int _v)
    { value = _v; nodes[0] = nodes[1] = 0;  }
    int value;
    CBinNode* nodes[2];
};

////////////////////////////////////////////////////////////////////////////////////////////////////////

class CBinTree
{
public:
    CBinTree();
    ~CBinTree();
    bool Insert(int x);
    void Print();
    void kneighbors(int x, int k);
private:
    bool Find(int x, CBinNode**& p);
    void InOrder(CBinNode* n);
    CBinNode* m_root;
};

CBinTree::CBinTree()
{   m_root = 0; }

CBinTree::~CBinTree()
{}

bool CBinTree::Find(int x, CBinNode**& p)
{
    for ( p = &m_root ; *p && (*p)->value != x ; p = &( (*p)->nodes[ (*p)->value < x ] ) );
    return *p && (*p)->value == x;
}

bool CBinTree::Insert(int x)
{
    CBinNode** p;
    if ( Find(x,p) ) return 0;
    *p = new CBinNode(x);
    return 0;
}

void CBinTree::InOrder(CBinNode* n)
{
    if ( !n ) return;
    InOrder(n->nodes[0]);
    cout<<n->value<<" ";
    InOrder(n->nodes[1]);
}

void CBinTree::Print()
{
    InOrder(m_root);
    cout<<endl;
}

void CBinTree::kneighbors(int x, int k)
{
    std::cout<<"\n("<<x<<","<<k<<") => ";
    // The code goes from here down
    
    if (k <= 0)
        return;

    int values[1000];
    int n = 0;

    auto fill = [&](auto self, CBinNode* node) -> void
    {
        if (!node) return;
        self(self, node->nodes[0]);
        values[n++] = node->value;
        self(self, node->nodes[1]);
    };

    fill(fill, m_root);

    int pos = 0;
    while (pos < n && values[pos] < x)
        pos++;

    int selected[1000];
    int count = 0;

    if (pos < n && values[pos] == x)
    {
        selected[count++] = x;
        int left = pos - 1;
        int right = pos + 1;

        for (int i = 0; i < k && (left >= 0 || right < n); i++)
        {
            if (left < 0)
                selected[count++] = values[right++];
            else if (right >= n)
                selected[count++] = values[left--];
            else if (x - values[left] <= values[right] - x)
                selected[count++] = values[left--];
            else
                selected[count++] = values[right++];
        }
    }
    else
    {
        int left = pos - 1;
        int right = pos;

        for (int i = 0; i < k && (left >= 0 || right < n); i++)
        {
            if (left < 0)
                selected[count++] = values[right++];
            else if (right >= n)
                selected[count++] = values[left--];
            else if (x - values[left] <= values[right] - x)
                selected[count++] = values[left--];
            else
                selected[count++] = values[right++];
        }
    }

    for (int i = 1; i < count; i++)
    {
        int temp = selected[i];
        int j = i - 1;

        while (j >= 0 && selected[j] > temp)
        {
            selected[j + 1] = selected[j];
            j--;
        }

        selected[j + 1] = temp;
    }

    for (int i = 0; i < count; i++)
        std::cout << selected[i] << " ";
}

////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    CBinTree t;
    t.Insert(55); t.Insert(41); t.Insert(77);
    t.Insert(33); t.Insert(47); t.Insert(61);
    t.Insert(88); t.Insert(20); t.Insert(36);
    t.Insert(44); t.Insert(51); t.Insert(57);
    t.Insert(65); t.Insert(80); t.Insert(99);
    t.Print();
    
    t.kneighbors(33,4);
    t.kneighbors(88,3);
    t.kneighbors(76,2);
    t.kneighbors(47,5);
    t.kneighbors(61,4);
    t.kneighbors(50,3);
    t.kneighbors(81,5);
    t.kneighbors(20,7);
}
