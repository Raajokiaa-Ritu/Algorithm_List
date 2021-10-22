#include<bits/stdc++.h>
using namespace std;
#define   pb   push_back
#define   pii  pair<int,int>
#define   inf  100000

int i,j,n,m,e,s,a,b,mincost=0;
int w,node1,node2,node;

unordered_map<int,int>v;
vector<pair<int,pii>> mstset;
vector<pair<int,pii>>g;

priority_queue<pair<int,pii>, vector<pair<int,pii>>, greater<pair<int,pii>>>pq;

void make_set(int n)
{
  v[n]=n;
}
///path compression
int findset(int n)
{
    if(v[n]==n)return n;
    return v[n]=findset(v[n]);
}
void union_set(int a,int b)
{
    a=findset(a);
    b=findset(b);
    if(a<b)swap(a,b);
    v[a]=b;
}

int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
#endif

   cin>>n>>e;
   for(i=1;i<=n;i++) make_set(i);
   
   for(i=0;i<e;i++)
   {
      int u,v,w;
      cin>>u>>v>>w;
      pq.push({w,{u,v}});
   }
   

   while(!pq.empty())
   {
      
      w = pq.top().first;
      node1 = pq.top().second.first;
      node2 = pq.top().second.second;
      pq.pop();
      a = findset(node1);
      b = findset(node2);
      if(a != b)
      {
         mstset.pb({w,{node1,node2}});
         mincost += w;
         union_set(node1,node2);
      }  
   }
   cout<<"mincost : "<<mincost<<endl;
   sort(mstset.begin(),mstset.end());
   for(auto node : mstset)
   {
     w = node.first;
     a = node.second.first;
     b = node.second.second;

     cout<<a<<" - "<<b<<" : "<<w<<endl;
   }

}