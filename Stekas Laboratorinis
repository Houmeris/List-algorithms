#include <iostream>
#include <fstream>
using namespace std;
class listas
{
private:
struct node
{
    string data, data2, data3;
    node *next;
};
    node *n;
    node *e;
public:
    listas();
    void push(string x, string z, string y);
    string top();
    string pop();
    string pop2();
    string pop3();
    void Formuoti(string fv);
    void ISort(listas & A, string op, string ip, string up);
    void Sort(listas & A);
    node *t;
};
listas::listas()
{
    t=NULL;
}
void listas::push(string x, string z, string y)
{
    n = new node;
    n->next = t;
    t = n;
    t->data = x;
    t->data2 = z;
    t->data3 = y;
}
void listas::Formuoti(string fv)
{
    string a, b, c;
    ifstream fd(fv.c_str());
    while(!fd.eof())
    {
        fd>>a>>b>>c;
        push(a, b, c);
    }
}
string listas::top()
{
    return t-> data + " " + t->data2 + " " + t->data3;
}
string listas::pop()
{
    if (t != NULL)
    {
      node *Temp = t;
      t = t->next;
      string b = Temp->data;
      string c = Temp->data2;
      string d = Temp->data3;
      delete Temp;
      return b + " " + c + " " + d;
    }
  else
    cout << "Stack Empty..";
}
void listas::ISort(listas & A, string op, string ip, string up)
{
    if (t == NULL || (t->data > op && t->data2 > ip) )
        A.push(op, ip, up);
    else
    {
      string l = A.pop();
      ISort (A, op, ip, up);
      A.push (l, "", "");
    }
}

void listas::Sort(listas & A)
{
  if (t != NULL)
    {
      string f= A.pop();
      Sort(A);
      ISort(A, f, "", "");
    }
}
int main()
{
    listas x;
    x.Formuoti("Duomenys.txt");
    /*ifstream df ("duomenys.txt");
    string a, b, c;
    while (!df.eof())
    {
        df>>a>>b>>c;
        a=a+" "+b+" "+c;
        x.push(a);
    }*/
    x.Sort(x);
    cout << "Sukurtas stekas:\n";
    while(x.t->next != NULL)
    {
        cout<<x.top()<<endl;
        x.pop();
        if(x.t->next == 0) cout << x.top()<<endl;
    }
    cout<<endl;
    cout << "Pabaiga!" << endl;
    return 0;
}
