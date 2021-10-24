#include<bits/stdc++.h>
using namespace std;
#define mx 1000

int i,j,m,n;
string A,B;

int lcs[mx][mx];
char print[mx][mx];

int LCS_Length(string A,string B)
{
    m = A.length();
    n = B.length();

    for(i=0;i<=m;i++){
        lcs[i][0]=0;
        print[i][0]='*';
    }
    for(j=0;j<=n;j++){
        lcs[0][j]=0;
        print[0][j]='*';
    }

    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(A[i-1] == B[j-1])
            {
                lcs[i][j] = 1+lcs[i-1][j-1];
                print[i][j] = 'C';
            }
            else if(lcs[i-1][j]>=lcs[i][j-1])
            {
                lcs[i][j] = lcs[i-1][j];
                print[i][j] = 'U';
            }
            else
            {
                lcs[i][j] = lcs[i][j-1];
                print[i][j] = 'L';
            }
        }
    }
    return lcs[m][n];
}

string print_lcs(string A,string B)
{
    i = A.length();
    j = B.length();
    
    string ans="";
    while(i>0 && j>0)
    {
        if(print[i][j] == 'C')
        {
            ans +=A[j-1];
            i--;j--;
        }
        else if(print[i][j] == 'L')
        {
            j--;
        }
        else
        {
            i--; 
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    cin>>A>>B;

    int len = LCS_Length(A,B);
    string ans = print_lcs(A,B);

    cout<<"Length of LCS  =  "<<len<<endl;
    cout<<"LCS = "<<ans<<endl;
   
}