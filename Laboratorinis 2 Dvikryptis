#include <iostream>
#include <fstream>
using namespace std;
class listas
{
private:
    struct node
    {
        string duom, duom2, duom3, duom4, duom5;             //DUOM
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
    void Bubble();
    void Bendravardziai();
};
listas::listas()
{

}
void listas::FormuotiTiesiogini(const string Fv)
{
    node *r;
    string a, b , c , d, e;
    ifstream fd(Fv.c_str());
    if(!fd.eof())
    {
        fd>>a>>b>>c>>d>>e;
        pr=new node;
        pr->duom=a;
        pr->duom2=b;
        pr->duom3=c;
        pr->duom4=d;
        pr->duom5=e;
        pr->next=NULL;
        pr->prev=NULL;
        pb=pr;

        while (!fd.eof())
        {
            fd>>a>>b>>c>>d>>e;
            r = new node;
            r->duom=a;
            r->duom2=b;
            r->duom3=c;
            r->duom4=d;
            r->duom5=e;
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
        cout<<d->duom<<" "<<d->duom2<<" "<<d->duom3<<" "<<d->duom4<<" "<<d->duom5<<endl;
        d=d->next;
    }
}
void listas::Bubble()
{
    int swapped;
    node *ptr;
    node *lptr=NULL;
    if(pr==NULL)
        return;
    do
    {
        swapped=0;
        ptr=pr;
        while (ptr->next!=lptr)
        {
            if(ptr->duom2>ptr->next->duom2)
            {
                swap(ptr->duom2, ptr->next->duom2);
                swap(ptr->duom, ptr->next->duom);
                swap(ptr->duom3, ptr->next->duom3);
                swap(ptr->duom4, ptr->next->duom4);
                swap(ptr->duom5, ptr->next->duom5);
                swapped=1;
            }
            ptr=ptr->next;
        }
        lptr=ptr;
    }
    while(swapped);
}
void listas::Bendravardziai()
{
    node *ptr=pr;
    int c=0;
    int Counted;
    do
    {
        Counted=0;
        while (ptr->next!=NULL)
        {
            if (ptr->duom2==ptr->next->duom2)
            {
                c++;
                Counted=1;
            }
            ptr=ptr->next;
            if (ptr->duom2==ptr->prev->duom2)
            {
                c++;
            }
            if (ptr->next!=NULL && ptr->duom2==ptr->prev->duom2 && ptr->duom2==ptr->next->duom2)
            {
                c--;
            }
        }
    }
    while(Counted);
    cout<<"Isviso yra tiek bendravardziu = "<<c<<endl;
}
int main()
{
    listas x;
    x.FormuotiTiesiogini("Duomenys.txt");
    x.Bubble();
    x.SpausdintiNuoPr();
    x.Bendravardziai();
    return 0;
}
