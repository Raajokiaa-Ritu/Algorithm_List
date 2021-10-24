#include<bits/stdc++.h>
using namespace std;
#define pb push_back

int i,j,n,m,e,capacity;

int weight;
int profit;
int TotalProfit=0;

priority_queue<pair<pair<double,int>,pair<int,int>>>PQ;

vector<double>Solution_Set;//1--n,,0 0 0 0

int main()
{
	
	cin>>n>>capacity; //number of item;
	Solution_Set.assign(n+1,0.0);

	for(i=1;i<=n;i++)
	{
		cin>>weight>>profit;
		PQ.push({{(double)profit/weight,i},{weight,profit}});
	}
    


 
    while(!PQ.empty())
    {
    	
    	double unitProfit = PQ.top().first.first; 
    	int element = PQ.top().first.second;
    	weight = PQ.top().second.first;
    	profit = PQ.top().second.second;
        PQ.pop();
        
        //cout<<element<<'\t'<<unitProfit<<'\t'<<weight<<'\t'<<profit<<endl;
        if(weight<=capacity)
        {
        	capacity -= weight;
        	Solution_Set[element] = 1.0; //0.0
        	TotalProfit+=profit;
        }
        else
        {

        	if(capacity>0)
        	{
                
        		int FractionProfit =(capacity*profit)/weight;                

    	        TotalProfit +=FractionProfit;

    	        Solution_Set[element] =(double)capacity/weight;
    	        capacity=0;
        	}
        	else break;
        }
    }
    
    
    cout<<"TotalProfit : "<<TotalProfit<<endl;
    cout<<"solution vector: ";
    for(i=1;i<=n;i++)
    {
    	cout<<setprecision(1)<<Solution_Set[i]<<' ';
    }

}
