#include<bits/stdc++.h>
using namespace std;
#define   pb      push_back
#define   inf     1e9
#define   pii     pair<int,int>
#define   f       first
#define   s       second

int i,node,edges,u,v,w;
int cost,minCost=0,source,destination;

vector<int>SelectedNodes;

vector<int>Parent;  //parent
vector<int>Dist;  //distance
vector<bool>visited; //visited node of mst set

vector<pii>Graph[1000];
priority_queue<pii,vector<pii>,greater<pii>>PQ; //min heap (distance,node)

void init()
{
  Parent.assign(node+1,-1);
  Dist.assign(node+1,inf);
  visited.assign(node+1,false);

  Dist[source] = 0;

}

void prims_mst()
{
	init();
	PQ.push({Dist[source],source});//(distance,node)
	
	while(!PQ.empty())
	{
		cost = PQ.top().first;
		u    = PQ.top().second;

		PQ.pop();
		
		if(visited[u] == false){
			minCost+=cost;
			SelectedNodes.pb(u);
		}
		visited[u]=true;

		vector<pair<int,int>>::iterator it;
		for(it=Graph[u].begin();it!=Graph[u].end();it++)
		{
			v = it->first;
			w = it->second; //wgt of u --> v

			if(visited[v]==false && Dist[v] >w)
			{

				Dist[v] = w;
				Parent[v] = u;
				PQ.push({Dist[v],v});
			}
		}

	}

}
void print_mst()
{
	cout<<"minCost = "<<minCost<<endl;
    
    cout<<"\nNode serial : ";
    for(auto it:SelectedNodes)cout<<it<<' ';cout<<endl;

	cout<<"\nMST SET :\n";
	for(auto it:SelectedNodes)
	{
		cout<<it<<" - "<<Parent[it]<<" : "<<Dist[it]<<endl;
	}
    

    cout<<"\nPath from "<<source<<" to "<<destination<<" : "; 
	int target = destination;
	vector<int>path;
	while(target != source)
	{
		path.push_back(target);
		target = Parent[target];
	}
	path.push_back(source);

	reverse(path.begin(),path.end());
	for(auto it:path)cout<<it<<' ';
	
	cout<<"\nCost :";
	int sum=0;
	for(auto it:path)
	{
		sum += Dist[it];
	}		
	cout<<sum<<endl;
}

int main()
{
	cin>>node>>edges;
	cin>>source>>destination;
	
	for(i=0;i<edges;i++)
	{
	 cin>>u>>v>>w;
	 Graph[u].pb({v,w});
	 Graph[v].pb({u,w}); //undirected graph
	}
    prims_mst();
    print_mst();

}
