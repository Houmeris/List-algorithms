void Srautas::Salinti()
{
    temp = pr;
    if(pr == NULL)
    {
        cout<<"Eile yra tuscia"<<endl;
    }
    else if (temp->next != NULL)
    {
        temp = temp->next;
        delete(pr);
        pr = temp;
    }
    else
    {
        delete(pr);
        pr = NULL;
        pb = NULL;
    }
}
