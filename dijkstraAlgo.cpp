#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 1e9
#define pii pair<int,int>



int i,j,node,edge,u,v,w,wgt,cost;
int source,destination;//Starting point of Traversal


vector<pair<int,int>>Graph[100005];
priority_queue<pii,vector<pii>,greater<pii>>PQ; //Min Heap


vector<int>Parent;
vector<int>Dist;

void init()
{

	Parent.assign(node+1,-1);
	Dist.assign(node+1,inf);

	Dist[source]    = 0;

}

void Dijkstra()
{
	init();

	PQ.push({Dist[source],source});//(distance,SourceNode);

	while(!PQ.empty())
	{
		cost = PQ.top().first;
		u    = PQ.top().second;
		PQ.pop();				
        
        for(auto child : Graph[u])
		{
			v   = child.first;
			wgt = child.second;

			if(cost + wgt < Dist[v])
			{
				Dist[v] = cost+wgt;
				Parent[v] = u;
				PQ.push({Dist[v],v}); //distance,node
			}
		}

	}
}

void Print_Shortest_Path()
{
	cout<<"Distance from source: \n";
	for(i=1;i<node;i++)
		cout<<source<<"->"<<i<<" : "<<Dist[i]<<'\n';
	cout<<endl;

	vector<int>Path;
	int target = destination;
	while(target != source)
	{
		Path.push_back(target);
		target = Parent[target];
	}
    Path.push_back(source);
    
    cout<<"Shortest Path from "<<source<<" to "<<destination<<":"<<endl;
	reverse(Path.begin(),Path.end());
	for(auto it:Path)cout<<it<<' ';

}

int main()
{

	cin>>node>>edge;
	cin>>source>>destination;

	for(i=0;i<edge;i++)
	{		
		cin>>u>>v>>w;
		Graph[u].push_back({v,w});
		Graph[v].push_back({u,w});
	}
	
	Dijkstra();
	Print_Shortest_Path();

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
}
