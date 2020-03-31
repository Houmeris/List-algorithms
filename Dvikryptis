#include <iostream>
#include <fstream>
using namespace std;
class listas
{
private:
    struct node
    {
        int duom;             //DUOM
        node *next;
        node *prev;
    };
    node *pb;
    node *pr;
    node *per;
public:
    listas();
    void FormuotiTiesiogini(const string Fv);
    void SpausdintiNuoPr();
    void IterptiUz(node *r, int k);
    void salinti(node *r);
    node *vieta(int R)
    {
      for(node *d = pr; d != NULL; d= d ->next)
    if( d -> duom == R)
    return d;
    return NULL;

    }
};
listas::listas()
{

}
void listas::FormuotiTiesiogini(const string Fv)
{
    node *r;
    int d;
    ifstream fd(Fv.c_str());
    if(!fd.eof())
    {
        fd>>d;
        pr=new node;
        pr->duom=d;
        pr->next=NULL;
        pr->prev=NULL;
        pb=pr;

        while (!fd.eof())
        {
            fd>>d;
            r = new node;
            r->duom=d;
            pb->next=r;
            r->prev=pb;
            pb=r;
            pb->next=NULL;
        }
    }
    fd.close();
}
void listas::SpausdintiNuoPr()
{
    node *d = pr;
    cout<<"Suformuotas sarasas:"<<endl;
    while(d)
    {
        cout<<d->duom<<" ";
        d=d->next;
    }
}
void listas::IterptiUz(node *r, int k)
{
    node *d = new node;
    d->duom = k;
    d->next = r->next;
    d->prev = r;
    if(pb==r) pb=d;
    else
    {
        r->next->prev=d;
        r->next = d;
    }

};
void listas::salinti(node *r)
{
    if(r==pr&&r==pb)
        per=pb=NULL;
        else
            if(r==pr)
        {
            per=pr->next;
            per->prev=NULL;
        }
        else
            if(r==pb)
        {
            pb=pb->prev;
            pb->next=NULL;
        }
        else
        {
            r->prev->next=r->next;
            r->next->prev=r->prev;
        }
        delete r;
}
int main()
{
    listas x;
    x.FormuotiTiesiogini("Duomenys.txt");
    //x.IterptiUz(x.vieta(8), 3);
    //x.salinti(x.vieta(7));
    x.SpausdintiNuoPr();
    return 0;
}
