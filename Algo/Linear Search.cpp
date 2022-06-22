
bool linearSearch(int ara[], int searching_Element, int array_size)
{
    bool check = false;
    for(int i=0; i<array_size; i++)
    {
        if(ara[i]==searching_Element)
        {
            check = true;
            return check;
        }
    }
    return check;
}
