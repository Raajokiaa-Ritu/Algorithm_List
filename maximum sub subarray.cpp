#include<bits/stdc++.h>
using namespace std;
int max_cross_subarray(int a[],int low,int mid,int high)
{

    int left_sum = INT_MIN;
    int max_left;
    int sum = 0;
    int i,j;

    for (i=mid; i>=low; i--)
    {
        sum = sum+a[i];
        if (sum>left_sum)
            left_sum = sum;
            max_left=i;
    }

    int right_sum = INT_MIN;
    int max_right;
    sum = 0;

     for (j=mid+1; j<=high; j++)
     {
           sum=sum+a[j];
           if (sum>right_sum)
               right_sum = sum;
               max_right=j;
     }

    return (max_left,max_right,left_sum+right_sum);
}
int max_subarray(int a[],int low,int high)
{
     int mid,left_sum,right_sum,cross_sum;

     if(high==low)
          return(low,high,a[high]);
     else
          mid=(low+high)/2;

     left_sum =max_subarray(a,low,mid);
     right_sum=max_subarray(a,mid+1,high);
     cross_sum=max_cross_subarray(a,low,mid,high);


     if(left_sum>=right_sum  && left_sum>=cross_sum)
          return left_sum;
     else if(right_sum>=left_sum && right_sum>=cross_sum)
          return right_sum;
     else
          return cross_sum;

}


int main()
{

   int n,i;
   cin>>n;
   int a[n+1];
   for(i=0;i<n;i++)
   {
       cin>>a[i];
   }
   int mxsum=max_subarray(a,0,n-1);
   cout<<"Maximum Contigious Sum : "<<mxsum<<endl;

}
/*
input:
5
5 -4 -3 -2 -1

output:
Maximum Contigious Sum : 5

*/
