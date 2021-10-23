#include<bits/stdc++.h>
using namespace std;
#define pb push_back

int i,j,n,m,e,sum=0;
int leftSum=0,rightSum=0,crossSum=0;

int max_cross_sum(int arry[],int low,int mid,int high)
{
	int left = INT_MIN;
	sum=0;

	for(i=mid;i>=low;i--)
	{
		sum +=arry[i];
		if(sum > left)
		{
			left= sum;
		}else break;
	}


	int right = INT_MIN;
	sum=0;
	for(i=mid+1;i<=high;i++)
	{
		sum += arry[i];
		if(sum>right)
		{
			right = sum;
		}else break;
	}

	return left+right;
}

int max_sum_subarray(int ar[],int l,int h)
{

	if(l == h)return ar[l];	
	int m = (l+h)/2;

   /*
       leftSum  = max_sum_subarray(ar,l,m);
       rightSum = max_sum_subarray(ar,m+1,h);
       crossSum = max_cross_sum(ar,l,m,h);

       return max(leftSum,max(rightSum,crossSum));
    */
    
    return max(max_sum_subarray(ar,l,m),max(max_sum_subarray(ar,m+1,h),max_cross_sum(ar,l,m,h)));
	
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	cin>>n;
	int arry[n+1];
	for(i=0;i<n;i++)cin>>arry[i];

	cout<<"max sum : "<<max_sum_subarray(arry,0,n-1)<<endl;
}
/*
input : 
5
5 -4 -3 -2 -1


output:
max sum : 5

*/
