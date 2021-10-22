#include<bits/stdc++.h>
using namespace std;
#define  pb  push_back
#define  mx  1000

int i,j,n,m,e,s;
int arr[mx];
int largest,l,r;

void heapify(int arr[], int n, int i)
{
    largest = i; // Initialize largest as root
    l = 2 * i + 1; // left = 2*i + 1
    r = 2 * i + 2; // right = 2*i + 2
 
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapsort(int arr[], int n)
{
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    for (i = n - 1; i > 0; i--) 
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void input()
{
	for(i=0;i<n;i++)cin>>arr[i];
}
void output()
{
	for(i=0;i<n;i++)cout<<arr[i]<<' ';
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	cin>>n;
	input();
	heapsort(arr,n);
	output();
}