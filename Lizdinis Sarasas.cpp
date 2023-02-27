#include <iostream>
#include <fstream>
using namespace std;
class Lizdinis
{
private:
    struct Lizdas
    {
        static const int Cn=4;
        int S[Cn];
        int n;
        Lizdas *next;
    };
    Lizdas *pr;
    Lizdas *per;
    Lizdas *veikRod;
    int veikInd;
public:
    Lizdinis();
    void DetiPradzia(const int duom);
    void FormuotiAtv(string fv);
    void Rodyti();
    bool YraReiksme(const int duom);
    void NustatytiVeik(int duom);
    void DetiNaujaUzveik(const int duom);
    void Naikinti();
    void SalintiVeik();
};
Lizdinis::Lizdinis()
{
    pr=NULL;
}
void Lizdinis::DetiPradzia(const int duom)
{
    if(pr==NULL || pr->n==Lizdas::Cn)
    {
        Lizdas *d = new Lizdas;
        d->S[0]=duom;
        d->n=1;
        d->next=pr;
        pr=d;
    }
    else
    {
        for (int i=pr->n; i>0; i--)
            pr->S[i]=pr->S[i-1];
        pr->S[0]=duom;
        pr->n++;
    }
}
void Lizdinis::FormuotiAtv (string fv)
{
    int sk;
    ifstream fd(fv.c_str());
    while(!fd.eof())
    {
        fd>>sk;
        DetiPradzia(sk);
    }
}
void Lizdinis::Rodyti()
{
    for (Lizdas *r = pr; r!=NULL; r=r->next)
    {
        for (int i=0; i<r->n; i++)
            cout<<r->S[i]<<' ';
        cout<<endl;
    }
}
bool Lizdinis::YraReiksme(const int duom)
{
    for (Lizdas*r = pr; r!=NULL; r=r->next)
        for (int i=0; i<r->n;i++)
        if(r->S[i]==duom) return true;
    return false;
}
void Lizdinis::NustatytiVeik(int duom)
{
    veikRod=NULL;
    veikInd=-1;
    for (Lizdas *r=pr; r!=NULL && veikRod==NULL; r=r->next)
        for (int i=0; i<r->n && veikRod==NULL; i++)
        if(r->S[i]==duom)
    {
        veikRod=r;
        veikInd=i;
    }
    cout<<"Elementas "<<duom<<" yra:"<<" vieta "<<veikInd<<endl;
}
void Lizdinis::DetiNaujaUzveik(const int duom)
{
    if(veikRod==NULL) return;
    if(veikRod->n==Lizdas::Cn)
    {
        Lizdas *d=new Lizdas;
        if(veikInd==veikRod->n-1)
            d->S[0]=duom;
        else
        {
            d->S[0]=veikRod->S[veikRod->n-1];
            for (int i=veikRod->n-1; i>veikInd+1; i--)
                veikRod->S[i]=veikRod->S[i-1];
            veikRod->S[veikInd+1]=duom;
        }
        d->n=1;
        d->next=veikRod->next;
        veikRod->next=d;
    }
    else
    {
        for (int i=veikRod->n; i>veikInd+1; i--)
            veikRod->S[i]=veikRod->S[i-1];
        veikRod->n++;
    }
}
void Lizdinis::Naikinti()
{
    Lizdas *d;
    while(pr!=NULL)
    {
        d=pr;
        pr=pr->next;
        delete d;
    }
    veikRod=NULL;
    veikInd=-1;
    cout<<"Sarasas Tuscias!"<<endl;
}
void Lizdinis::SalintiVeik()
{
    if(veikRod==NULL) return;
    Lizdas *vr=veikRod;
    int vi=veikInd;
    if(vi==vr->n-1)
    {
        vr=vr->next;
        vi=0;
    }
    for (int i=veikInd; i<veikRod->n-1; i++)
        veikRod->S[i]=veikRod->S[i+1];
    veikRod->n-=1;
    if(veikRod->n==0)
    {


    if(veikRod==pr) pr=pr->next;
    else
    {
        Lizdas *d=pr;
        while (d->next !=veikRod)
            d=d->next;
        d->next=veikRod->next;
    }
    delete veikRod;
    }
    veikRod=vr;
    veikInd=vi;

}
int main()
{
    Lizdinis x;
    x.FormuotiAtv("Duomenys.txt");
    //x.DetiNaujaUzveik(5)
    //x.Naikinti();
    //x.SalintiVeik();
    x.Rodyti();
    //x.NustatytiVeik(4);
    return 0;
}
