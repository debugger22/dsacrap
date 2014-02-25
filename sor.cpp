#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int x;
	int ar[12];
	cin>>x;
	for(int i=0;i<x;i++)
	{
		cin>>ar[i];
	}
	sort(ar,ar+x);
	for(int i=0;i<x;i++)
	{
		cout<<ar[i]<<" ";
	}


}
