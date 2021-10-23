#include<bits/stdc++.h>
using namespace std;
#define pb push_back

int i,j,n,m,e,capacity;

int weight;
int profit;
int TotalProfit=0;

priority_queue<pair<pair<double,int>,pair<int,int>>>order;

vector<double>Selected;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	
	cin>>n>>capacity; //number of item;
	Selected.assign(n+1,0.0);
	for(i=1;i<=n;i++)
	{
		cin>>weight>>profit;
		order.push({{(double)profit/weight,i},{weight,profit}});
	}

 
    while(!order.empty())
    {
    	
    	double d = order.top().first.first; 
    	int element = order.top().first.second;
    	weight = order.top().second.first;
    	profit = order.top().second.second;
        order.pop();
       
        if(weight<=capacity)
        {
        	capacity -= weight;
        	Selected[element] = 1.0;
        	TotalProfit+=profit;
        }
        else
        {
        	if(capacity>0)
        	{
        		int ans =(capacity*profit)/weight;
    	        TotalProfit +=ans;
    	        Selected[element] =(double)capacity/weight;
    	        capacity=0;
        	}
        	else break;
        }
    }
    
    
    cout<<TotalProfit<<endl;
    for(i=1;i<=n;i++)
    {
    	cout<<setprecision(1)<<Selected[i]<<' ';
    }

}