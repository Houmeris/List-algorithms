#include <iostream>
#include <fstream>
using namespace std;
class queue
{
private:
    struct node
    {
        string duom, duom2;
        int duom3;
        struct node *next;
    };
    struct node* pr = NULL;
    struct node* pb = NULL;
    struct node* temp;
public:
    queue();
    void Irasyti(string k, string j, int h);
    void Spausdinti();
    void Formuoti(string fv);
    void Sort();
};
queue::queue()
{

}
void queue::Irasyti(string k, string j, int h)
{
    if(pb == NULL)
    {
        pb = new node;
        pb -> next = NULL;
        pb -> duom = k;
        pb -> duom2 = j;
        pb -> duom3 = h;
        pr = pb;
    }
    else
    {
        temp = new node;
        pb -> next = temp;
        temp -> duom = k;
        temp -> duom2 = j;
        temp -> duom3 = h;
        temp -> next = NULL;
        pb = temp;
    }
}
void queue::Formuoti(string fv)
{
    string a, b;
    int c;
    ifstream fd (fv.c_str());
    while(!fd.eof())
    {
        fd>>a>>b>>c;
        Irasyti(a, b, c);
    }
}
void queue::Spausdinti()
{
    ofstream rf ("Atsakymas.txt");
    temp = pr;
    if((pr == NULL) && (pb == NULL))
    {
        rf<<"Eile yra tuscia"<<endl;
        return;
    }
    while (temp != NULL)
    {
        cout<<temp -> duom<<" "<<temp -> duom2<<" "<<temp -> duom3<<endl;
        rf<<temp -> duom<<" "<<temp -> duom2<<" "<<temp -> duom3<<endl;
        temp = temp -> next;
    }
}
void queue::Sort()
{
    int swapped;
    node *ptr;
    node *lptr = NULL;
    if (pr == NULL)
        return;
        do
        {
            swapped = 0;
            ptr = pr;
            while (ptr -> next != lptr)
            {
                if( ptr->duom > ptr->next->duom && ptr->duom2 > ptr->next->duom2)
                {
                    swap(ptr->duom, ptr->next->duom);
                    swap(ptr->duom2, ptr->next->duom2);
                    swap(ptr->duom3, ptr->next->duom3);
                    swapped = 1;
                }
                ptr = ptr -> next;
            }
        lptr = ptr;
        }
        while(swapped);
}
int main()
{
    queue x;
    x.Formuoti("Duomenys.txt");
    x.Sort();
    x.Spausdinti();
    return 0;
}
