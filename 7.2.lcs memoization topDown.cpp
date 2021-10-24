#include <bits/stdc++.h>
using namespace std;
#define mx 1000

int dp[mx][mx];

string A,B;
int i,j;

int lcs(string A, string B, int i, int j, int dp[][mx])
{

	if (i == 0 || j == 0)
		return 0;
	if(dp[i-1][j-1] != -1) return dp[i-1][j-1];

    if (A[i-1] == B[j-1]){
		dp[i-1][j-1] =  1 + lcs(A, B, i - 1, j - 1,dp);
		return dp[i-1][j-1];
    }
	else {

		dp[i - 1][j - 1] = max(lcs(A, B, i, j - 1, dp),lcs(A, B, i- 1, j, dp));
		return dp[i - 1][j - 1];
	}
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	
	cin>>A>>B;
	i = A.length();
	j = B.length();


	// assign -1 to all positions
	memset(dp, -1, sizeof(dp));

	cout << "Length of LCS: " << lcs(A,B,i,j,dp);

	return 0;
}
