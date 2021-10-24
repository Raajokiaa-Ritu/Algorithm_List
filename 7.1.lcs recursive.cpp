#include <bits/stdc++.h>
using namespace std;

int n,m,i,j;

string A,B;

int lcs(string A, string B, int i, int j)
{
	if (i == 0 || j == 0)
		return 0;

	if (A[i-1] == B[j-1])
		return 1 + lcs(A, B, i - 1, j - 1);
	else
		return max(lcs(A,B,i,j-1),lcs(A,B,i-1,j));
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

	cout << "Length of LCS: " << lcs(A, B, i, j);
}
