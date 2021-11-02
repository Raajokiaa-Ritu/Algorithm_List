#include<bits/stdc++.h>
using namespace std;
#define   pb      push_back
#define   inf     1e9
#define   pii     pair<int,int>
#define   f       first
#define   s       second

int i,j,node,edges,cost,u,v,w;
int minCost=0,source,destination;

vector<pair<int,int>>Graph[1000];
priority_queue<pii,vector<pii>,greater<pii>>PQ; //distance,source

vector<int>visited;
vector<int>parent;
vector<int>SelectedNode;
vector<int>Dist;

void init()
{  
	visited.assign(node+1,false);
	parent.assign(node+1,-1);
	Dist.assign(node+1,inf);
        Dist[source] = 0;
}

void prims_mst()
{
	init();
	PQ.push({Dist[source],source});

	while(!PQ.empty())
	{
		cost = PQ.top().first;
		u    = PQ.top().second;

		PQ.pop();
		if(visited[u] == false)
		{
			visited[u]  =true;
			SelectedNode.push_back(u);
			minCost += cost;
		}
    
    vector<pair<int,int>>::iterator it;
    for(it = Graph[u].begin(); it!=Graph[u].end();it++)
    {
    	v = it->first;
    	w = it->second;

    	if(visited[v]==false && Dist[v] > w)
    	{
    		Dist[v] = w;
    		parent[v] = u;
    		PQ.push({Dist[v],v});
    	}
    }
	}

}
void print_mst()
{
	cout<<"minCost : "<<minCost<<endl;
  
  cout<<"\nSelected Node Serial : ";
  for(auto it:SelectedNode)
  {
  	cout<<it<<' ';
  }cout<<endl;
  
  cout<<"\nMST SET:\n";
  for(auto it:SelectedNode)
  {
  	cout<<it<<" - "<<parent[it]<<" : "<<Dist[it]<<endl;
  }

  int target = destination;
  vector<int>Path;
  while(target != source)
  {
  	Path.push_back(target);
  	target = parent[target];
  }
  Path.push_back(source);

  reverse(Path.begin(),Path.end());

  cout<<"\nPath from "<<source<<" to "<<destination<<" : ";
  for(auto it:Path)cout<<it<<' ';cout<<endl;

  int sum=0;
  for(auto it:Path)
  {
  	sum += Dist[it];
  }
  cout<<"Cost of this path: "<<sum<<endl;


}

int main()
{

	cin>>node>>edges;
	cin>>source>>destination;

	for(i=0;i<edges;i++)
	{
		cin>>u>>v>>w;
		Graph[u].pb({v,w});
		Graph[v].pb({u,w});
	}
        prims_mst();
        print_mst();
}
/*
input:from gfg
9 14 ->(node,edges)
0 3  ->(source,destination)
0 1 4->all edges(u,v,w);
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
minCost : 37

Selected Node Serial : 0 1 2 8 5 6 7 3 4 

MST SET:
0 - -1 : 0
1 - 0 : 4
2 - 1 : 8
8 - 2 : 2
5 - 2 : 4
6 - 5 : 2
7 - 6 : 1
3 - 2 : 7
4 - 3 : 9

Path from 0 to 3 : 0 1 2 3 
Cost of this path: 19




*/
