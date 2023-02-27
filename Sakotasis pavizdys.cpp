#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
using namespace std;
    typedef struct studentas
    {
        char pavard[10];
        char vardas[10];
        char fakult[10];
        float vidur;
    };
    typedef struct sar
    {
        studentas st;
        sar *kitas;
    };
    typedef struct fakultetas
    {
        char fak[10];
        fakultetas *sek;
        sar *stud;
    };
// Klasės Uni aprašymas
class Uni {
    fakultetas *P; // Dinaminio sąrašo pradžia
 public:
    Uni() { P = NULL; }; // Konstruktorius
    void Formuoti(string fv); // Formuoja sąrašą
    void Spausdinti(sar *); // Spausdina sąrašą
    void Visi_stud();
    void Pasirink();
};
// Pagrindinė programa
int main()
{
    Uni A; // Klasės Uni objektas
    A.Formuoti("Duomenys.txt");
    A.Visi_stud();
    A.Pasirink();
}
// Sąrašo formavimas
void Uni::Formuoti(string fv)
{
    ifstream fd (fv.c_str());
    fakultetas *R;
    sar *A;
    int yra;
    while(!fd.eof())
    {
        A = new sar;
        fd>>A->st.pavard>>A->st.vardas>>A->st.fakult>>A->st.vidur;
        yra = 0;
        R = P;
        while(!yra && R)
        if (strcmp(A->st.fakult, R->fak) == 0) yra = 1;
        else R = R->sek;
    if (!yra)
    {
        R = new fakultetas;
        R->stud = NULL;
        strcpy(R->fak, A->st.fakult);
        R->sek = P;
        P = R;
    }
    A->kitas = R->stud;
    R->stud = A;
 }
 fd.close();
}
// Spausdina vieno fakulteto studentų sąrašą
void Uni::Spausdinti(sar *R)
{
    while(R)
    {
        cout << R->st.pavard << " "<<R->st.vardas<<" "<<R->st.vidur<<"\n";
        R = R->kitas;
    }
 cout << "------------------------\n";
}
// Spausdina visų fakultetų studentų sąrašus
void Uni::Visi_stud()
{
    fakultetas *R = P;
    cout << "=== Fakultetu ir studentu sarasai ===\n\n";
    while(R)
    {
        cout << "Fakultetas " << R->fak << ":\n";
        Spausdinti(R->stud);
        R = R->sek;
    }
}
// Pageidaujamo fakulteto studentų sąrašo spausdinimas
void Uni::Pasirink()
{
    fakultetas *R;
    char fk[10], s;
    int yra, rinkti = 1;
    while(rinkti)
    {
        cout << "Fakultetas= ";
        cin >> fk;
        yra = 0;
        R = P;
        while(!yra && R)
        if (strcmp(fk, R->fak) == 0) yra = 1;
        else R = R->sek;
        if (yra)
        {
            cout << R->fak << ":\n";
            Spausdinti( R->stud );
        }
        else cout << fk << " sarase nerastas\n";
        cout << "------------------------\n";
        cout << "Ar dar renkate fakulteta(T)?";
        cin >> s;
        if ((s != 'T') && (s != 't')) rinkti = 0;
 }
}
