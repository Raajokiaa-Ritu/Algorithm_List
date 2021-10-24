#include <bits/stdc++.h>
using namespace std;
#define mx 10000

int item,capacity,i,j,w; 
int dp[mx][mx];
int weight[mx];
int profit[mx];

int KnapSack(int capacity,int weight[],int profit[],int n)
{
    for(i=0;i<=n;i++)
    {
        for(w=0;w<=capacity;w++)
        {
            if(i==0 or w==0)
            {
                dp[i][w] = 0;
            }
            else if(weight[i-1] <= w)
            {
                dp[i][w] = max(profit[i-1]+dp[i-1][w - weight[i-1]] , dp[i-1][w]); 
            }
            else
                dp[i][w] = dp[i-1][w];
        }
    }
    return dp[n][capacity];
}

void selected_element()
{
     int res = dp[item][capacity];
     w = capacity;

     for (i = item; i > 0 && res > 0; i--) 
     {
        if (res == dp[i - 1][w])
            continue;
        else {
            cout<<weight[i - 1]<<" -> "<<profit[i-1]<<endl;
            res = res - profit[i - 1];
            w = w - weight[i - 1];
        }
    }
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    cin>>item>>capacity; 
    for(i=0;i<item;i++)cin>>weight[i];
    for(i=0;i<item;i++)cin>>profit[i];

    int ans = KnapSack(capacity,weight,profit,item);
    cout<<"Optimal profit : "<<ans<<endl;
    cout<<"\nselected_element :\n";
    selected_element();
}
/*
input:
4 8
2 2 4 5
2 4 6 9

output:
Optimal profit : 13

selected_element :
5 -> 9
2 -> 4



*/
