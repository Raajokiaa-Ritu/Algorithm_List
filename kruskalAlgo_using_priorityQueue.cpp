#include<bits/stdc++.h>
using namespace std;
#define   pb   push_back
#define   pii  pair<int,pair<int,int>>
#define   inf  100000

int i,node,edges,mincost=0,source,destination;
int u,v,w,a,b;

unordered_map<int,int>parent;
vector<pii> mstset;

vector<pair<int,int>>Graph[1000];
priority_queue<pii,vector<pii>,greater<pii>>pq;

void make_set(int n)
{
  parent[n]=n;
}
///path compression
int findset(int n)
{
    if(parent[n]==n)return n;
    return parent[n]=findset(parent[n]);
}
void union_set(int a,int b)
{
    a=findset(a);
    b=findset(b);
    if(a<b)swap(a,b);
    parent[a]=b;
}

int main()
{

   cin>>node>>edges;
  
   for(i=1;i<=node;i++) make_set(i);
   
   for(i=0;i<edges;i++)
   {
      int u,v,w;
      cin>>u>>v>>w;
      pq.push({w,{u,v}});
   }
   

   while(!pq.empty())
   {      
      w = pq.top().first;
      u = pq.top().second.first;
      v = pq.top().second.second;
      pq.pop();
      a = findset(u);
      b = findset(v);
      if(a != b)
      {
         mstset.pb({w,{u,v}});
         mincost += w;
         union_set(u,v);
      }  
   }
   cout<<"mincost : "<<mincost<<endl;

   cout<<"\nMST SET :\n";
   sort(mstset.begin(),mstset.end());
   for(auto node : mstset)
   {
     w = node.first;
     u = node.second.first;
     v = node.second.second;

     cout<<u<<" - "<<v<<" : "<<w<<endl;
   }

}
/*
input:gfg
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

output:
mincost : 37

MST SET :
6 - 7 : 1
2 - 8 : 2
5 - 6 : 2
0 - 1 : 4
2 - 5 : 4
2 - 3 : 7
0 - 7 : 8
3 - 4 : 9

*/
