#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mx 1000

int i,j,n;
int profit[mx];
int table[mx][mx];

vector<int>cutPoint;

int Rod_Cut()
{
    for(i=0;i<=n;i++)
        for(j=0;j<=n;j++)
            table[i][j]=0;

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(j<i) table[i][j] = table[i-1][j];
            else
            {
                table[i][j] = max(table[i-1][j],profit[i]+table[i][j-i]); 
            }
        }
    }
    return table[n][n];
}

void find_cutPoint()
{
    i = n;
    j = n;
    while(j>0 and i>0)
    {
        if(table[i][j] == table[i-1][j])
            i--;
        else
        {
            cutPoint.push_back(i);
            j = j-i;
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    cin>>n;
    for(i=1;i<=n;i++)cin>>profit[i];

    cout<<"Optimal profit: "<<Rod_Cut()<<endl; 

    find_cutPoint();
    cout<<"cutting point: ";
    for(i=0;i<cutPoint.size();i++)cout<<cutPoint[i]<<' ';


}
/*
input:
5
2 5 9 6 7

output:
Optimal profit: 14
cutting point: 3 2 

*/