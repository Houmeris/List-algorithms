#include <iostream>
#include <fstream>
using namespace std;
class ziedas
{
private:
    struct node
    {
        string duom, duom2, duom3, duom4, duom5;
        node *next;
    };
    node *pr;
    node *pb;
public:
    ziedas();
    void padeti(string a, string a2, string a3, string a4, string a5);
    void Formuoti(const string fv);
    void Spausdinti(const string tekstas);
    void Rikiuok();
    void Count();
};
ziedas::ziedas()
{
    pr=NULL;
    pb=NULL;
}
void ziedas::padeti(string a, string a2, string a3, string a4, string a5)
{
    node *d = new node;
    d->duom=a;
    d->duom2=a2;
    d->duom3=a3;
    d->duom4=a4;
    d->duom5=a5;
    d->next=pr;
    pr=d;
    if(pb==NULL) pb=pr;
    pb->next=pr;
}
void ziedas::Formuoti(const string fv)
{
    ifstream fd (fv.c_str());
    string a, a2, a3, a4, a5;
    pr = pb = NULL;
    while(!fd.eof())
    {
        fd>>a>>a2>>a3>>a4>>a5;
        padeti(a, a2, a3, a4, a5);
    }
    fd.close();
}
void ziedas::Spausdinti(const string tekstas)
{
    node *r = pr;
    if(r!=NULL)
    {
    cout<<tekstas<<endl;
    cout<<r->duom<<" "<<r->duom2<<" "<<r->duom3<<" "<<r->duom4<<" "<<r->duom5<<endl;
    r=r->next;
    while(r!=pr)
    {
        cout<<r->duom<<" "<<r->duom2<<" "<<r->duom3<<" "<<r->duom4<<" "<<r->duom5<<endl;
        r=r->next;
    }
    cout<<endl;
    }
}
void ziedas::Rikiuok()
{
    node *current = pr, *index = NULL;
    string temp, temp2, temp3, temp4, temp5;
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
                if(current->duom2>index->duom2)
                {
                    temp2=current->duom2;
                    current->duom2=index->duom2;
                    index->duom2=temp2;
                    temp=current->duom;
                    current->duom=index->duom;
                    index->duom=temp;
                    temp3=current->duom3;
                    current->duom3=index->duom3;
                    index->duom3=temp3;
                    temp4=current->duom4;
                    current->duom4=index->duom4;
                    index->duom4=temp4;
                    temp5=current->duom5;
                    current->duom5=index->duom5;
                    index->duom5=temp5;
                }
                index=index->next;
            }
            current=current->next;
        }
        while(current->next!=pr);
    }
}
void ziedas::Count()
{
    node *current = pr;
    node *index=NULL;
    int k=0, o=0;
    int Counted;
        do
        {
            Counted=0;
            index=current->next;
            while (index!=pr)
            {
                if(current->duom2==current->next->duom2 && current->duom2!=index->next->duom2)
                {
                    k=k+2;
                    Counted=1;

                }
                else if(current->duom2==current->next->duom2)
                {
                    k++;
                    Counted=1;
                }
                current=current->next;
                index=index->next;
            }
        }
        while(Counted);
    cout<<"Yra "<<k<<" bendravardziu"<<endl;
}
int main()
{
    ziedas x;
    x.Formuoti("Duomenys.txt");
    x.Rikiuok();
    x.Spausdinti("Sarasas: ");
    x.Count();

    return 0;
}
