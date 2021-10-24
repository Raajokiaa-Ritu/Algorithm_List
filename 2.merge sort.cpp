#include<bits/stdc++.h>
using namespace std;

int i,j,k,n,n1,n2;


merge(int array[],int low,int mid,int high)
{
    
    n1=mid-low+1;
    n2=high-mid;

    int L[n1+1]; 
    int R[n2+1]; 

    for(i=1; i<=n1; i++)
    {
        L[i]=array[low+i-1];
    }
    for(j=1; j<=n2; j++)
    {
        R[j]=array[mid+j];
    }

    L[n1+1]=200000;
    R[n2+1]=200000;

    i=1;
    j=1;
    for(k=low; k<=high; k++)
    {
        if(L[i]<=R[j])
        {
            array[k]=L[i];
            i++;
        }
        else
        {
            array[k]=R[j];
            j++;
        }
    }
}


merge_sort(int array[],int low,int high)
{
    int mid;
    if (low<high)
    {
        mid = (low+high)/2;
        merge_sort(array,low,mid);
        merge_sort(array,mid+1,high);
        merge(array,low,mid,high);
    }

}

void print_Array(int array[])
{
    for(i=0; i<n; i++)
        cout<<array[i]<<" ";
    cout<<endl;
}

int main()
{

    cin>>n;
    int array[n+5];
    for(i=0; i<n; i++)
        //cin>>array[i];
        array[i] = rand(); //taking random variable

    print_Array(array); //before sorting
   
    merge_sort(array,0,n-1);

    print_Array(array); //after sorting
    

    return 0;
}
