#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
class listas
{
private:
    struct Grupe
    {
        string pavad;
        Grupe *next;
    };
    struct Fakul
    {
        string kodas;
        Grupe *saka;
        Fakul *pagr;
    };
    Fakul *pr;
    Fakul *pb;
    Fakul *RastiFakul(string fakul)
    {
        Fakul *eiti=pr;
        while(eiti!=NULL && fakul !=eiti->kodas)
            eiti=eiti->pagr;
        return eiti;
    }
    void SpGrupes(Grupe *eitp);
    void PasalintiSaka(Grupe *eitp);

public:
    listas();
    ~listas();
    void Naikinti();
    void SukurtiKamieno(string fakul);
    bool SukurtaSakaA(string fakul, string pav);
    void VisuPerziura();
    bool SpSaka(string fakul);
};
listas::listas()
{
    pr=NULL;
    pb=NULL;
}
listas::~listas()
{
    Naikinti();
}
void listas::SukurtiKamieno(string fakul)
{
    if(pr==NULL)
        pr=pb=new Fakul;
    else
    {
        pb->pagr=new Fakul;
        pb=pb->pagr;
    }
    pb->kodas=fakul;
    pb->pagr=NULL;
    pb->saka=NULL;
}
bool listas::SukurtaSakaA(string fakul, string pav)
{
    Fakul *eiti=RastiFakul(fakul);
    if(eiti==NULL) return false;
    Grupe *d=new Grupe;
    d->pavad=pav;
    d->next=eiti->saka;
    eiti->saka=d;
    return true;
}
void listas::VisuPerziura()
{
    cout<<"Fakultetai ir ju grupes: "<<endl;
    Fakul *eiti = pr;
    while(eiti!=NULL)
    {
        cout<<setw(4)<<eiti->kodas<<endl;
        SpGrupes(eiti->saka);
        eiti=eiti->pagr;
    }
}
void listas::SpGrupes(Grupe *eitp)
{
    while(eitp!=NULL)
    {
        cout<<eitp->pavad<<endl;
        eitp=eitp->next;
    }
}
bool listas::SpSaka(string fakul)
{
    Fakul *eiti=RastiFakul(fakul);
    if(eiti==NULL)
        return false;
    else SpGrupes(eiti->saka);
    return true;

}
void FormuotiSaka(ifstream &fd, listas &vienas, string fakul, int kiek)
{
    string grupe;
    for (int j=0; j<kiek; j++)
    {
        fd>>grupe;
    vienas.SukurtaSakaA(fakul, grupe);
    }
}
void Formuoti(listas &vienas)
{
    string kodas;
    const string Duom = "Duomenys.txt";
    ifstream fd(Duom.c_str());
    int kiekSaka;
    while (!fd.eof())
    {
        fd >> kodas >> kiekSaka;
        vienas.SukurtiKamieno(kodas);
        FormuotiSaka(fd, vienas, kodas, kiekSaka);
    }
    fd.close();

}
void listas::PasalintiSaka(Grupe *eitp)
{
    Grupe *buvo;
    while (eitp != NULL)
    {
        buvo = eitp;
        eitp = eitp -> next;
        delete buvo;
    }
}

void listas::Naikinti()
{
    Fakul *eiti;
    while(pr != NULL)
    {
        PasalintiSaka(pr->saka);
        eiti = pr;
        pr = pr->pagr;
        delete eiti;
    }
}

int main()
{
    listas x;
    Formuoti(x);
    x.VisuPerziura();
    return 0;
}
