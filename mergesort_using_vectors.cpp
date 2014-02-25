#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> data;
unsigned int size;
signed int temp;


vector<int> partition(vector<int> parent){
	vector<int> childL(parent.begin(),parent.begin()+parent.size()/2);
	vector<int> childR(parent.begin()+parent.size()/2,parent.end());
	if(childL.size()>=2){
		partition(childL);
		partition(childR);
		sort(childL.begin(),childL.end());
		sort(childR.begin(),childR.end());
		vector<int> merged(childL.size()+childR.size());
		merge(childL.begin(),childL.end(),childR.begin(),childR.end(),merged.begin());
		return merged;
	}else{
		vector<int> merged(childL.size()+childR.size());
		merge(childL.begin(),childL.end(),childR.begin(),childR.end(),merged.begin());
		return merged;
	}
}

int main(){
	clock_t tStart = clock();
	cin>>size;
	for(int i=0;i<size;i++){
		cin>>temp;
		data.push_back(temp);
	}
	vector<int> sorted;
	sorted = partition(data);
	for(vector<int>::iterator it=sorted.begin();it!=sorted.end();++it)
		cout<<' '<<*it;
	
	cout<<"Time taken"<< (double)(clock() - tStart)/CLOCKS_PER_SEC;
	return 0;
}