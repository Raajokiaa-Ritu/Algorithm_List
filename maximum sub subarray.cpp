#include<bits/stdc++.h>
using namespace std;
#define pb push_back

int i,j,n,m,e,sum=0,mid;
int left_sum=0,right_sum=0,cross_sum=0;

int max(int a, int b) { return (a > b) ? a : b; }

int max(int a, int b, int c) { return max(max(a, b), c); }

int maxCrossingSum(int arr[], int l, int m, int h)
{
	sum = 0;
	left_sum = INT_MIN;

	for (int i = m; i >= l; i--) {
		sum  += arr[i];
		if (sum > left_sum)
			left_sum = sum;
	}
	
	sum = 0;
    right_sum = INT_MIN;

	for (int i = m + 1; i <= h; i++) {
		sum  += arr[i];
		if (sum > right_sum)
			right_sum = sum;
	}

	return max(left_sum + right_sum, left_sum, right_sum);
}
int maxSubArraySum(int arr[], int l, int h)
{
	if (l == h)
		return arr[l];

	int m = (l + h) / 2;

	left_sum = maxSubArraySum(arr,l,m);
	right_sum = maxSubArraySum(arr,m+1,h);
	cross_sum = maxCrossingSum(arr,l,m,h);

	return max(left_sum,right_sum,cross_sum);

}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	cin>>n;
	int array[n+1];

	for(i=0;i<n;i++)
		cin>>array[i];

    sum = maxSubArraySum(array,0,n-1);
    cout<<sum<<endl;
}