#include <iostream>
#include <fstream>
using namespace std;
class Prognozes {
private:
        struct Orai
    {
        string data;
        string pobudis;
        float kiekis, isviso, kiek;
    };
    struct sar
    {
        Orai o;
        sar *kitas;
    };
    struct pobud
    {
        string pob;
        pobud *sek;
        sar *stud;
    };
    pobud *P;
 public:
    Prognozes() { P = NULL; };
    void Formuoti(string fv);
    void Visi_orai();
    void Rikiuok();
    void Skaiciuok();
};
void Prognozes::Formuoti(string fv)
{
    ifstream fd (fv.c_str());
    pobud *R;
    sar *A;
    int yra;
    while(!fd.eof())
    {
        A = new sar;
        fd>>A->o.data>>A->o.pobudis>>A->o.kiekis;
        yra = 0;
        R = P;
        while(!yra && R)
        if (A->o.pobudis == R->pob) yra = 1;
        else R = R->sek;
    if (!yra)
    {
        R = new pobud;
        R->stud = NULL;
        R->sek = P;
        P = R;
    }
    A->kitas = R->stud;
    R->stud = A;
 }
 fd.close();
}
void Prognozes::Visi_orai()
{
    pobud *R = P;
    cout << "=== Oru prognozes ==="<<endl<<endl;
    while(R)
    {
        cout << R->stud->o.data<<" "<<R->stud->o.pobudis<<" "<<R->stud->o.kiekis<<endl;
        R = R->sek;
    }
}
void Prognozes::Rikiuok()
{
    pobud *ptr;
    pobud *R = P;
    pobud *lptr=NULL;
    int counter;
    if(P==NULL)
        return;
    do
    {
        counter=0;
        ptr=P;
        while (ptr->sek!=lptr)
        {
            if(ptr->stud->o.pobudis>ptr->sek->stud->o.pobudis && ptr->stud->o.kiekis>ptr->sek->stud->o.kiekis)
            {
                swap(ptr->pob, ptr->sek->pob);
                swap(ptr->stud->o.data, ptr->sek->stud->o.data);
                swap(ptr->stud->o.kiekis, ptr->sek->stud->o.kiekis);
                swap(ptr->stud->o.pobudis, ptr->sek->stud->o.pobudis);
                counter = 1;
            }
            ptr=ptr->sek;
        }
        lptr=ptr;
        R=R->sek;
    }
    while(counter);
}
void Prognozes::Skaiciuok()
{
    float a=0, b=0, c=0;
    float lietus=0, snygis=0, dulksna=0;
    pobud *R=P;
        if(R->stud->o.pobudis == "Lietus")
        {
            //R->stud->o.isviso=R->stud->o.isviso+R->stud->o.kiekis+R->sek->stud->o.kiekis;
            a++;
            //R->stud->o.kiek++;
            lietus=lietus+R->stud->o.kiekis;
        }
        else if(R->stud->o.pobudis == "Snygis")
        {
               // R->stud->o.isviso=R->stud->o.isviso+R->stud->o.kiekis+R->sek->stud->o.kiekis;
                b++;
                //R->stud->o.kiek++;
                snygis=snygis+R->stud->o.kiekis;
        }
        else if(R->stud->o.pobudis == "Dulksna")
        {
                //R->stud->o.isviso=R->stud->o.isviso+R->stud->o.kiekis+R->sek->stud->o.kiekis;
                c++;
                //R->stud->o.kiek++;
                dulksna=dulksna+R->stud->o.kiekis;
        }
    R=R->sek;
    while(R!=NULL)
    {
        if(R->stud->o.pobudis == "Lietus")
        {
            //R->stud->o.isviso=R->stud->o.isviso+R->stud->o.kiekis+R->sek->stud->o.kiekis;
            a++;
            //R->stud->o.kiek++;
            lietus=lietus+R->stud->o.kiekis;
        }
        else if(R->stud->o.pobudis == "Snygis")
        {
                //R->stud->o.isviso=R->stud->o.isviso+R->stud->o.kiekis+R->sek->stud->o.kiekis;
                b++;
                //R->stud->o.kiek++;
                snygis=snygis+R->stud->o.kiekis;
        }
        else if(R->stud->o.pobudis == "Dulksna")
        {
                //R->stud->o.isviso=R->stud->o.isviso+R->stud->o.kiekis+R->sek->stud->o.kiekis;
                c++;
                //R->stud->o.kiek++;
                dulksna=dulksna+R->stud->o.kiekis;
        }
            R=R->sek;

    }
    cout<<"Skaiciavimai: "<<endl;
    cout<<"Lietus: "<<"is viso = "<<lietus<<" Vidurkis = "<<lietus/a<<endl;
    cout<<"Snygis: "<<"is viso = "<<snygis<<" Vidurkis = "<<snygis/b<<endl;
    cout<<"Dulksna: "<<"is viso = "<<dulksna<<" Vidurkis = "<<dulksna/c<<endl;
}
int main()
{
    Prognozes A;
    A.Formuoti("Duomenys.txt");
    A.Visi_orai();
    A.Rikiuok();
    A.Visi_orai();
    cout<<endl;
    A.Skaiciuok();
    return 0;
}
