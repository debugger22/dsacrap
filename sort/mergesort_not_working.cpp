#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;
void mergesort(vector<int> vec,int low,int high,int mid)
{
		sort(&vec[low],&vec[mid]);
		sort(&vec[mid+1],&vec[high]);
		//merge(&vec[low],&vec[mid],&vec[mid+1],&vec[high],&vec[low]);
		sort(&vec[low],&vec[high]);
}
int divide(vector<int> vec,int low,int high)
{
	int mid;
	while(low<high)
	{
		mid=(low+high)/2;
		divide(vec,low,mid);
		divide(vec,mid+1,high);
		mergesort(vec,low,high,mid);

	}
	return 0;
}


int main(){

	vector<int> vec;
	int size;
	int temp;
	cin>>size;
	for(int i=0;i<size;i++){
		cin>>temp;
		vec.push_back(temp);
	}
	divide(vec,0,size-1);
	for (vector<int>::iterator it=vec.begin(); it!=vec.end(); ++it)
    cout << ' ' << *it<<endl;
	//for (list<int>::iterator it=mlist.begin(); it!=mlist.end(); ++it)
    //cout<<' ' <<*it;
	
	
	return 0;
}