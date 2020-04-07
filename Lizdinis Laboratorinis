#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
class Lizdinis
{
private:
    struct Lizdas
    {
        static const int Cn=10;
        string S[Cn], S2[Cn], S4[Cn];
        double S3[Cn], suma[Cn], Vidurkis[Cn];
        int n, kiek[Cn];
        Lizdas *next;
    };
    Lizdas *pr;
    Lizdas *pb;
    Lizdas *temp;
    Lizdas *veikRod;
    int veikInd;
public:
    Lizdinis();
    ~Lizdinis();
    void DetiPradzia(const string duom, const string duom2, const double duom3, const string duom4);
    void FormuotiAtv(string fv);
    void Rodyti();
    void Rikiuok();
    void Skaiciuok();
    int Yra(Lizdas *temp, string krit, int n);
    void Naikinti();
};
Lizdinis::Lizdinis()
{
    pr=NULL;
    pb=NULL;
    temp=NULL;
}
Lizdinis::~Lizdinis()
{
    Naikinti();
}
void Lizdinis::DetiPradzia(const string duom, const string duom2, const double duom3, const string duom4)
{
    if(pr==NULL || pr->n==Lizdas::Cn)
    {
        Lizdas *d = new Lizdas;
        d->S[0]=duom;
        d->S2[0]=duom2;
        d->S3[0]=duom3;
        d->S4[0]=duom4;
        d->n=1;
        d->next=pr;
        pr=d;
    }
    else
    {
        for (int i=pr->n; i>0; i--)
        {
            pr->S[i]=pr->S[i];
            pr->S2[i]=pr->S2[i];
            pr->S3[i]=pr->S3[i];
            pr->S4[i]=pr->S4[i];
        }
        pr->S[pr->n]=duom;
        pr->S2[pr->n]=duom2;
        pr->S3[pr->n]=duom3;
        pr->S4[pr->n]=duom4;
        pr->n++;
    }
    temp=pr;
}
void Lizdinis::FormuotiAtv (string fv)
{
    string a, b, d;
    double c;
    ifstream fd(fv.c_str());
    while(!fd.eof())
    {
        fd>>a>>b>>c>>d;
        DetiPradzia(a, b, c, d);
    }
}
void Lizdinis::Rodyti()
{
    for (Lizdas *r = pr; r!=NULL; r=r->next)
    {
        for (int i=0; i<r->n; i++)
            cout<<r->S[i]<<" "<<r->S2[i]<<" "<<r->S3[i]<<" "<<r->S4[i]<<endl;
        cout<<endl;
    }
}
void Lizdinis::Rikiuok()
{
    string T1;
    for (Lizdas *r = pr; r!=NULL; r=r->next)
    {


    for (int i=0; i<=r->n; i++)
    {
        for (int j=i+1; j<=r->n-1; j++)
            {
                if(r->S2[i]>r->S2[j] && r->S3[i]>r->S3[j])
                {
                    swap(r->S[i], r->S[j]);
                    swap(r->S2[i], r->S2[j]);
                    swap(r->S3[i], r->S3[j]);

                }
            }
    }
    }
}
int Lizdinis::Yra(Lizdas *temp, string krit, int n)
{
    for (int i=0; i<n; i++)
        if(temp->S2[i]==krit)
        return i;
        return -1;
}
void Lizdinis::Skaiciuok()
{
    for (int i=0; i<pr->n; i++)
    {
        pr->suma[i]=pr->S3[i];
        pr->Vidurkis[i]=pr->suma[i];
    }
    int m=0;
    for (int i=0; i<pr->n; i++)
    {
        int k=Yra(temp, pr->S2[i], m);
        if(k>=0)
        {
            temp->suma[k]+=pr->S3[i];
        }
        else
        {
            m++;
        }
    }
    for (int i=0; i<pr->n; i++)
    {
        for (int j=0; j<m; j++)
        {
            if(j==0 && pr->S2[j]==pr->S2[i])
            {
                pr->kiek[0]++;
            }
            if(j==1 && pr->S2[j]==pr->S2[i])
            {
                pr->kiek[1]++;
            }
            if(j==2 && pr->S2[j]==pr->S2[i])
            {
                pr->kiek[2]++;
            }
        }
    }
    for (int i=0; i<m; i++)
    {
        pr->Vidurkis[i]=pr->suma[i]/pr->kiek[i];
    }
        for (int i=0; i<m; i++)
            cout<<pr->S2[i]<<" Bendras kiekis: "<<pr->suma[i]<<" Vidurkis: "<<pr->Vidurkis[i]<<endl;
        cout<<endl;
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
int main()
{
    Lizdinis x;
    x.FormuotiAtv("Duomenys.txt");
    cout<<"Duomenu sarasas:"<<endl;
    x.Rodyti();
    x.Rikiuok();
    cout<<"Surikiuotas Sarasas:"<<endl;
    x.Rodyti();
    cout<<"Skaiciavimai: "<<endl;
    x.Skaiciuok();
    return 0;
}
