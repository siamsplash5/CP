void f(lld n)                  //always call it with 0
{
    if(n<0 || n>1000000000005) //here, range = 1000000000005
        return;                // we can take it as our needs
    if(n>0)
        v.pb(n);               //declare a vector to store the numbers
    f(n*10 + 4);               // if you need 3 digit combination,
    f(n*10 + 7);               // call it 3 times recurrsively
    f(n*10 + 6);               // if need 2 then call 2 times
                               // here we call for the number 4, 7 and 6.
}
