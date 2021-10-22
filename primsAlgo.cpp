#include<bits/stdc++.h>
using namespace std;
#define   pb      push_back
#define   inf     10000
#define   pii     pair<int,int>
#define   f       first
#define   s       second

int i,j,n,m,e,s,wgt,u,v,w;
int cost,node,minCost=0,node1;

vector<int>p;  //parent
vector<int>d;  //distance
vector<bool>visit; //visited node of mst set
unordered_map<int,vector<pii>>g; //graph nilam
priority_queue<pii,vector<pii>,greater<pii>>pq; //min heap (distance,node)

void init()
{
  visit.assign(n,false);
  d.assign(n,inf);
  p.assign(n,-1);
  d[0] = 0;
  p[0] = -1;
  visit[0] = true;
}

void prims_mst()
{
	pq.push({0,0}); //(distance,node)
	while(!pq.empty())
	{
		cost = pq.top().f;  // wgt of node u
		u    = pq.top().s;  //node u
        pq.pop();

    if(!visit[u]) minCost+=cost;
        visit[u]=true;
       
		for(auto child: g[u])
		{
			v = child.f; //node v
			w = child.s; // wgt of u--->v
			if(visit[v]==false && d[v] >w)
			{
				d[v] = w;
				p[v] = u;
				pq.push({d[v],v});
			}
		}
	}
}
void print_mst()
{
	cout<<"minCost = "<<minCost<<endl;
	cout<<"path    : ";
	for(i=0;i<n;i++)cout<<p[i]<<' ';cout<<endl;
	cout<<"distance: ";
	for(i=0;i<n;i++)cout<<d[i]<<' ';cout<<endl;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	cin>>n>>e;
	init();
	for(i=0;i<e;i++)
	{
	 cin>>u>>v>>w;
	 g[u].pb({v,w});
	 g[v].pb({u,w}); //undirected graph
	}
   prims_mst();
   print_mst();

}