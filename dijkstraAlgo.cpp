#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 1e9
#define pii pair<int,int>


int i,j,node,edge,u,v,w,wgt,cost;
int source = 0;//Starting point of Traversal

unordered_map<int,vector<pii>>Graph;
priority_queue<pii,vector<pii>,greater<pii>>PQ; //Min Heap

vector<bool>Visited;
vector<int>Path;
vector<int>Dist;

void init()
{
	Visited.assign(node+1,false);
	Path.assign(node+1,-1);
	Dist.assign(node+1,inf);

	//for sourse node
	Visited[source] = true;
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
				Path[v] = u;
				PQ.push({Dist[v],v}); //distance,node
			}
		}

	}
}

void Print_Shortest_Path()
{
	cout<<"Distance from source: \n";
	for(i=1;i<=node;i++)
		cout<<source<<"->"<<i<<" : "<<Dist[i]<<'\n';
	cout<<endl;
	vector<int>parent;
	int target = node;
	while(target != -1)
	{
		parent.push_back(target);
		target = Path[target];
	}

	reverse(parent.begin(),parent.end());
	for(auto it:parent)cout<<it<<' ';

}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	cin>>node>>edge;

	for(i=0;i<edge;i++)
	{		
		cin>>u>>v>>w;
		Graph[u].push_back({v,w});
		Graph[v].push_back({u,w});
	}
	
	Dijkstra();
	Print_Shortest_Path();

/*
9 14
0 1 4
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
*/
}