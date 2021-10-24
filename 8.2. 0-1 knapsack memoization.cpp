#include <bits/stdc++.h>
using namespace std;
#define mx 10000

int item,capacity,i;
int w[mx];
int p[mx];
int dp[mx][mx];

int knapSack(int capacity,int w[],int p[],int n,int dp[][mx])
{
	if(dp[capacity][n] != -1)
	{
		return dp[capacity][n];
	}
	if(capacity<=0 || n==0)
	{
		dp[capacity][n]=0;
		return dp[capacity][n];
	}
	else if(w[n]>capacity)
	{
		dp[capacity][n] = knapSack(capacity,w,p,n-1,dp);
		return dp[capacity][n];
	}
	else
	{
		dp[capacity][n] = max(knapSack(capacity,w,p,n-1,dp), p[n]+knapSack(capacity-w[n],w,p,n-1,dp));
		return dp[capacity][n];
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	cin>>item>>capacity;
	for(i=1;i<=item;i++)cin>>w[i];

	for(i=1;i<=item;i++)cin>>p[i];
    
    memset(dp,-1,sizeof(dp));

	int ans = knapSack(capacity,w,p,item,dp);
	cout<<"Optimal profit : "<<ans<<endl;

}
