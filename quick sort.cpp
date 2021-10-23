#include<bits/stdc++.h>
using namespace std;
#define pb push_back

int i,j,high,low,pivot,l,r,n;

int arry[10000];

int partition(int arry[],int low,int high)
{
   pivot = arry[low];
   l = low;
   r = high;

   while(l<r)
   {
       while(arry[l] <= pivot)l++;
       while(arry[r] > pivot)r--;
       if(l<r)       
         swap(arry[l],arry[r]);       
   }
   swap(arry[low],arry[r]);
   return r;
}

void QuickSort(int arry[], int low,int high)
{
   if(low<high)
   {
      pivot = partition(arry,low,high);
      QuickSort(arry,low,pivot-1);
      QuickSort(arry, pivot+1,high);
   }
}

int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
#endif

   cin>>n;
   for(i=0;i<n;i++)cin>>arry[i];

   QuickSort(arry,0,n-1);
   
   for(i=0;i<n;i++)cout<<arry[i]<<' ';

}