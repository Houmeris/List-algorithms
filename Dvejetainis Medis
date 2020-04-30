#include <iostream>
#include <fstream>
using namespace std;
class Medis
{
private:
    struct node
    {
        int sk;
        node* left;
        node* right;
    };
    node* p;
public:
    Medis();
    void Skaityti(const string fv);
    void Padeti(int s);
    void Spausdinti();
    void Mesti(int s);
    void Perkelti(node* d);
};
Medis::Medis()
{
    p = NULL;
}
void Medis::Skaityti(const string fv)
{
    int s;
    ifstream fd(fv.c_str());
    while (!fd.eof())
    {
        fd >> s;
        Padeti(s);
    }
    fd.close();
}
void Medis::Padeti(int s)
{
    node* d = new node;
    d->sk = s;
    d->right = d->left = NULL;
    node* r, * rl;
    r = rl = p;
    while (r)
    {
        rl = r;
        if (s < r->sk)
            r = r->left;
        else
            r = r->right;
    }
    if (rl)
        if (s < rl->sk)
            rl->left = d;
        else
            rl->right = d;
    else
        p = d;
}
void Medis::Spausdinti()
{
    node* A[100];
    int n = 0;
    node* d = p;
    while(d||(n>0))
        if (d)
        {
            A[n++] = d;
            d = d->left;
        }
        else
        {
            d = A[--n];
            cout<<d->sk<<" ";
            d = d->right;
        }
}
void Medis::Mesti(int s)
{
    node* r, * rl, * d;
    bool yra = false;
    r = rl = d = p;
    if (!p)
        return;
    while (r && !yra)
        if (s != r->sk)
        {
            rl = r;
            if (s < r->sk)
                r = r->left;
            else
                r = r->right;
        }
        else
            yra = true;
    if (!yra)
        return;
    if (r == p)
    {
        if (p->right == NULL)
            p = p->left;
        else
            if (p->left == NULL)
                p = p->right;
            else
            {
                p = p->left;
                d = p->right;
                Perkelti(d);
            }
        delete r;
    }
    else
        if (r->left == r->right)
        {
            if (rl->left == r)
                rl->left = NULL;
            else
                rl->right = NULL;
            delete r;
        }
        else
            if (r->left == NULL)
            {
                d = r->right;
                *r = *r->right;
                delete d;
            }
            else
                if (r->right == NULL)
                {
                    d = r->left;
                    *r = *r->left;
                    delete d;
                }
                else
                {
                    d = r->right;
                    rl = r->left;
                    *r = *r->left;
                    delete rl;
                    Perkelti(d);
                }
}
void Medis::Perkelti(node* d)
{
    node* r, * rl;
    r = rl = p;
    while (r)
    {
        rl = r;
        if (d->sk < r->sk)
            r = r->left;
        else
            r = r->right;
    }
    if (d->sk < rl->sk)
        rl->left = d;
    else
        rl->right = d;
}
int main()
{
    Medis x;
    x.Skaityti("Duomenys.txt");
    x.Mesti(10);
    x.Spausdinti();
}
