#include<bits/stdc++.h>
using namespace std;
#define pb push_back

int i,n;
vector<int>SelectedActivity;

int main()
{

	cin>>n;
	int startTime[n+1];
	int endTime[n+1];
	for(i=1;i<=n;i++)cin>>startTime[i];
	for(i=1;i<=n;i++)cin>>endTime[i];

	
	SelectedActivity.push_back(1);
	int key = 1;

	for(i=2;i<=n;i++)
	{
		if(startTime[i] >= endTime[key])
		{
			SelectedActivity.push_back(i);
			key = i;
		}
	}
    
    cout<<"Activity: ";
	for(i=0;i<SelectedActivity.size();i++)
	{
		cout<<"a"<<SelectedActivity[i]<<' ';
	}
}
