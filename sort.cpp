#include<iostream>
#include<vector>
#include<list>
#include<algorithm>


using namespace std;

int main(){

	vector<int> vec;
	int size;
	int temp;
	cin>>size;
	for(int i=0;i<size;i++){
		cin>>temp;
		vec.push_back(temp);
	}
	sort(vec.begin(),vec.end());
	reverse(vec.begin(),vec.end());
	//mlist.sort();
	for (vector<int>::iterator it=vec.begin(); it!=vec.end(); ++it)
    cout << ' ' << *it<<endl;
	//for (list<int>::iterator it=mlist.begin(); it!=mlist.end(); ++it)
    //cout<<' ' <<*it;
	return 0;
}