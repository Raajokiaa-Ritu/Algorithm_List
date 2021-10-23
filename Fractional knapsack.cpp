#include<bits/stdc++.h>
using namespace std;
#define pb push_back


int i,j,n,m,e,u,key;
int weight[10000];
int profit[10000];
int totalProfit=0,capacity;
double selected[10000];

void knapsack(int n,int capacity)
{
	for(i=1;i<=n;i++)selected[i]=0.0;

	for(i=1;i<n;i++)
	{
		key = i; 		
		for(j=i+1;j<=n;j++)
		{
		    double currProfit =(double)profit[j]/weight[j] ;	
		    double initProfit =(double)profit[key]/weight[key];		
			if(currProfit>initProfit)
			{
				key = j;
			}
		}
		swap(profit[i],profit[key]);
		swap(weight[i],weight[key]);
	}
	
   
	for(i=1;i<=n;i++)
	{
		if(weight[i]>capacity)break;
		else
		{
			selected[i]  = 1.0;
			capacity     = capacity - weight[i];
			totalProfit += profit[i];
		}
	}
	if(i<=n)
	{
		selected[i] =(double) capacity/weight[i];	
		totalProfit+= (capacity*profit[i])/weight[i];
	}
	cout<<"totalProfit : "<<totalProfit<<endl;
	cout<<"solution vector: ";
	for(i=1;i<=n;i++)cout<<setprecision(1)<<selected[i]<<' ';

}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	cin>>n>>capacity;
	for(i=1;i<=n;i++)cin>>weight[i];

	for(i=1;i<=n;i++)cin>>profit[i];

    knapsack(n,capacity);



}