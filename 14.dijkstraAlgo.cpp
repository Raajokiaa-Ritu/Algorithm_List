#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define inf 1e9
#define pii pair<int,int>

int i,j,node,edges,u,v,w,cost,wgt;
int source,destination;

vector<pair<int,int>>Graph[1000];
priority_queue<pii,vector<pii>,greater<pii>>PQ; //distance,source 


vector<int>Dist;
vector<int>Parent;

void init()
{
	Dist.assign(node+1,inf);
	Parent.assign(node+1,-1);

	Dist[source] = 0;
}

void Dijkstra()
{
	init();
	PQ.push({Dist[source],source});

	while(!PQ.empty())
	{
		cost  = PQ.top().first;
		u     = PQ.top().second;

		PQ.pop();

		vector<pair<int,int>>::iterator it;
		for(it= Graph[u].begin(); it!=Graph[u].end(); it++)		
		{
			v   = it->first;
			wgt = it->second;

			if(cost + wgt <Dist[v])
			{
				Dist[v] =cost+wgt;
				Parent[v] = u;
				PQ.push({Dist[v],v});
			}

		}
	}
	
}

void print()
{
	for(i=0;i<node;i++)
	{
		cout<<source<<" - "<<i<<" : "<<Dist[i]<<'\n';
	}
 
	int target = destination;
    
    vector<int>Path;
	while(target != source)
	{
		Path.push_back(target);
		target = Parent[target];
	}
	Path.push_back(source);
	cout<<"\nshortest path:\n";
	reverse(Path.begin(),Path.end());
	for(auto it:Path)
		cout<<it<<' ';
    cout<<"\ncost : "<<Dist[destination]<<endl;

}
int main()
{

	cin>>node>>edges;
	cin>>source>>destination;

	for(i=0;i<edges;i++)
	{
		cin>>u>>v>>w;
		Graph[u].push_back({v,w});
	    Graph[v].push_back({u,w});	
	}

	Dijkstra();
	print();


}

/*

input:this input is taken from gfg
9 14  ->(node,edge)
7 3   ->(source,destination)
0 1 4 ->(u,v,w)-->all edges
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7


output:
Distance from source: 
7->1 : 11
7->2 : 7
7->3 : 14
7->4 : 13
7->5 : 3
7->6 : 1
7->7 : 0
7->8 : 7

Shortest Path from 7 to 3
7 6 5 2 3 

*/

