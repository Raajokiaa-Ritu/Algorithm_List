#include<bits/stdc++.h>
using namespace std;
#define mx 1000

int i,n,q;
int profit[mx];

int rod_cut_aux(int profit[], int n, int dp[])
{
    if(dp[n]!= -1) return dp[n];

    if(n==0) q = 0;
    else q = INT_MIN;

    for(int i=1; i<=n; i++)
    {
        q = max(q, profit[i]+rod_cut_aux(profit, n-i, dp));
    }
    dp[n] = q;
    return dp[n];
}

int rod_cut(int profit[], int n)
{
    int dp[n+1];
    for(int i=0; i<=n; i++) dp[i] = -1;

    return rod_cut_aux(profit, n, dp);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    
    cin >> n;
    for(i=1;i<=n;i++)cin>>profit[i];

    int ans = rod_cut(profit, n);
    cout << "Optimal profit: " << ans << endl;
}