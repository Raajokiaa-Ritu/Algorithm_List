#include<bits/stdc++.h>
using namespace std;
#define mx 1000

int item,capacity,i,j,n;

int profit[mx];
int weight[mx];

int knapSack(int capacity, int wt[], int p[], int n)
{
    if (n == 0 || capacity == 0)
        return 0;
    if (wt[n-1] > capacity)
        return knapSack(capacity, wt, p, n - 1);
    else
        return max(p[n - 1] + knapSack(capacity - wt[n - 1],wt, p, n - 1), knapSack(capacity, wt,p, n - 1));
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

    int ans = knapSack(capacity,weight,profit,item);
    cout<<"Optimal profit : "<<ans<<endl;

}
