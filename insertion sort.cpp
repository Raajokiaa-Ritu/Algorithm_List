#include<bits/stdc++.h>
using namespace std;
#define pb push_back

int i,j,n,m,e,s,key;
int a[10000];

void input()
{
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
}

void insertion_sort()
{
	for(j=1;j<n;j++)
	{
		key = a[j];
		i=j-1;

		while(i>=0 && a[i]>key)
		{
			a[i+1] = a[i];
			i--;
		}
		a[i+1]=key;
	}
}

void output()
{
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<' ';
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

   input();
   insertion_sort();
   output();


}