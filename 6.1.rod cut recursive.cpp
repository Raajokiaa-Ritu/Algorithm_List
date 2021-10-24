#include<bits/stdc++.h>
using namespace std;
#define mx 1000

int profit[mx];
int n,i,q;

int Cut_Rod(int profit[], int n)
{
    if(n==0) return 0;
    int q = INT_MIN;
    for(int i=1; i<=n; i++)
    {
        q = max(q, profit[i] + Cut_Rod(profit, n-i));
    }
    return q;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    cin >> n;
    for(i=1; i<=n; i++)cin>>profit[i];    

    cout << "\nOptimal Profit : " <<Cut_Rod(profit, n) << endl;
}