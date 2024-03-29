#include <iostream>
#include <fstream>
using namespace std;
class ziedas
{
private:
    struct node
    {
        int duom;
        node *next;
    };
    node *pr;
    node *pb;
public:
    ziedas();
    ~ziedas(){Naikinti();}
    void padeti(int sk);
    void Formuoti(const string fv);
    void Spausdinti(const string tekstas);
    void Naikinti();
    void Mesti(node *rm);
    void MestiDid();
    void MestiPirma();
    void Rikiuok();
    node *RastiDid()
    {
        node *r = pr;
        if(pr)
        {
            node *d=pr->next;
            while(d!=pr)
            {
                if(d->duom>r->duom)
                    r=d;
                d=d->next;
            }

        }
        return r;
    };
};
ziedas::ziedas()
{
    pr=NULL;
    pb=NULL;
}
void ziedas::padeti(int sk)
{
    node *d = new node;
    d->duom=sk;
    d->next=pr;
    pr=d;
    if(pb==NULL) pb=pr;
    pb->next=pr;
}
void ziedas::Formuoti(const string fv)
{
    ifstream fd (fv.c_str());
    int sk;
    pr = pb = NULL;
    while(!fd.eof())
    {
        fd>>sk;
        padeti(sk);
    }
    fd.close();
}
void ziedas::Spausdinti(const string tekstas)
{
    node *r = pr;
    if(r!=NULL)
    {
    cout<<tekstas<<endl;
    cout<<r->duom<<endl;
    r=r->next;
    while(r!=pr)
    {
        cout<<r->duom<<endl;
        r=r->next;
    }
    cout<<endl;
    //cout<<RastiDid()<<endl;
    }

}
void ziedas::Naikinti()
{
    if(pb!=NULL)
    {
        pb->next=NULL;
        while(pr)
        {
            pb=pr;
            pr=pr->next;
            delete pb;

        }
    }
    pb=NULL;
}
void ziedas::Mesti(node *rm)
{
    node *rpries=pr;
    if(pr)
    {
        if(pr==rm && pr->next==pr)
        {
            delete pr;
            pr=NULL;
        }
        else
        {
            if(rm==pr) pr=pr->next;
            while(rpries->next!=rm)
                rpries=rpries->next;
            rpries->next=rm->next;
            delete rm;
        }
    }
}
void ziedas::MestiDid()
{
    Mesti(RastiDid());
}
void ziedas::MestiPirma()
{
    Mesti(pr);
}
void ziedas::Rikiuok()
{
    node *current = pr, *index = NULL;
    int temp;
    if(pr==NULL)
    {
        cout<<"List is empty"<<endl;
    }
    else
    {
        do
        {
            index=current->next;
            while (index!=pr)
            {
                if(current->duom>index->duom)
                {
                    temp=current->duom;
                    current->duom=index->duom;
                    index->duom=temp;
                }
                index=index->next;
            }
            current=current->next;
        }
        while(current->next!=pr);
    }
}
int main()
{
    ziedas x;
    x.Formuoti("Duomenys.txt");
    //x.Naikinti();
    //x.MestiDid();
    //x.MestiPirma();
    x.Rikiuok();
    x.Spausdinti("Duotas: ");
    return 0;
}
