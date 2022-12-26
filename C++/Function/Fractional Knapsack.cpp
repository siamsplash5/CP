/*********************************Library Function*************************************/

#include <bits/stdc++.h>

/*******************************preprocessor directives********************************/

#define faster           ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define test             lld t; cin >>t; while(t--)
#define strsort(s)       sort(s.begin(), s.end());
#define cs(tst)          prlldf("Case %d: ", tst);
#define Y                cout <<"YES" <<endl;
#define N                cout <<"NO" <<endl;
#define noo              cout <<"-1" <<endl;
#define pi a             cos(-1)
#define cube(x)          (x*x*x)
#define sqr(x)           (x*x)

/***********************************type definition***********************************/

typedef unsigned long long   ull;
typedef long long int        lld;
typedef long double          ld;
using namespace std;

lld i, j; //loop variable

/***********************************----START----************************************/

struct item
{
    int price;
    int weight;
};

int main()
{
    int knapsack = 16;
    item ara[] =  { { 6, 3 }, { 8, 4 }, { 10, 5 } , {12, 6}, {16, 8} };
    int total_item = 5;
    int table[total_item+1][knapsack+1] = {0};
    int pricePerWeight;
    int available_weight = ara[0].weight;

    for(i=0; i<total_item+1; i++)
    {
        for(j=0; j<knapsack+1; j++)
        {
            if(i==0 || j==0)
            {
                table[i][j] = 0;
            }
            else
            {
                pricePerWeight = ara[i-1].price/ara[i-1].weight;
                if(j<=available_weight)
                {
                    table[i][j] = pricePerWeight*j;
                }
            }
        }
        if(i>0)
        {
            available_weight+=ara[i].weight;
        }
    }
    cout <<"Maximum Profit is " <<table[total_item][knapsack] <<endl;
    return 0;
}
