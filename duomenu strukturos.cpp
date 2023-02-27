#include <iostream>
#include <fstream>
using namespace std;
class listas
{
private:
  struct mazgas
  {
      int duom;
      mazgas* sek;

  };
  mazgas *head;
  mazgas *curr;
  mazgas *temp;
public:
    listas();
    void AddNode(int addData);
    void DeleteNode(int delData);
    void PrintList ();

};
listas::listas()
{
    head = NULL;
    curr = NULL;
    temp = NULL; 
}
void listas::AddNode(int addData)
{
    mazgas *n = new mazgas;
    n->sek = NULL;
    n->duom = addData;
    if(head != NULL)
    {
        curr = head;
        while(curr->sek != NULL)
        {
            curr = curr->sek;
        }
        curr->sek = n;
    }
    else
    {
        head = n;
    }
}
void listas::DeleteNode(int delData)
{
    mazgas *delPtr = NULL;
    temp = head;
    curr = head;
    while (curr != NULL && curr->duom != delData)
    {
        temp = curr;
        curr = curr->sek;
    }
    if (curr == NULL)
    {
        cout<<delData<<"was not in the list"<<endl;
        delete delPtr;
    }
    else
    {
        delPtr = curr;
        curr = curr->sek;
        temp->sek = curr;
        if(delPtr == head)
        {
            head = head->sek;
            temp = NULL;
        }
        delete delPtr;
        cout<<"The value "<<delData<<" was deleted"<<endl;

    }
}
void listas::PrintList()
{
    curr = head;
    while (curr != NULL)
    {
        cout<<curr->duom<<endl;
        curr = curr->sek;
    }
}
int main()
{
    listas xd;
    xd.AddNode(3);
    xd.AddNode(5);
    xd.AddNode(7);
    xd.PrintList();
    xd.DeleteNode(3);
    xd.PrintList();
    return 0;
}
