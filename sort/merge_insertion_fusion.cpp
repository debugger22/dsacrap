#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int temp;
bool onceCalled=false;
unsigned int size;
unsigned int k1;
unsigned int k2;
vector<int> data;
vector<int> sorted;

vector<int> partition(vector<int> parent){
	vector<int> childL(parent.begin(),parent.begin()+parent.size()/2);
	vector<int> childR(parent.begin()+parent.size()/2,parent.end());
	if(childL.size()>k1){	
		partition(childL);		//Initiating Merge sort
		partition(childR);
		sort(childL.begin(),childL.end());
		sort(childR.begin(),childR.end());
		vector<int> merged(childL.size()+childR.size());
		merge(childL.begin(),childL.end(),childR.begin(),childR.end(),merged.begin());
		return merged;
	}else{
			vector<int> merged(childL.size()+childR.size());	//Initiating Insertion Sort
				for(int i=1;i<childL.size();i++){
					for(int j=i;j>0;j--){
						if(childL.at(j)<childL.at(j - 1)){
							bool directCopy;
							temp = childL.at(j);
							childL[j] = childL.at(j-1);
							childL[j-1] = temp;
						}	
					}
				}
				for(int i=1;i<childR.size();i++){
					for(int j=i;j>0;j--){
						if(childR.at(j)<childR.at(j - 1)){
							bool directCopy;
							temp = childR.at(j);
							childR[j] = childR.at(j-1);
							childR[j-1] = temp;
						}	
					}
				}
				//---------------------------------Printing work------------------------------
				for(vector<int>::iterator it = childL.begin(); it!=childL.end(); ++it){
					if(it!=childL.end()-1){
						cout<<*it<<" ";
					}else{
						cout<<*it;
					}
				}
				cout<<endl;
				for(vector<int>::iterator it = childR.begin(); it!=childR.end(); ++it){
					if(it!=childR.end()-1){
						cout<<*it<<" ";
					}else{
						cout<<*it;
					}
				}
				cout<<endl;
				//----------------------------------------------------------------------------
				merge(childL.begin(),childL.end(),childR.begin(),childR.end(),merged.begin());
				return merged;
	}
}


int main(){
	cin >> size;
	for(int i=0;i<size;i++){
		cin >> temp;
		data.push_back(temp);
	}
	cin >> k1;
	cin >> k2;
	sorted = partition(data);
	for(vector<int>::iterator it = sorted.begin(); it!=sorted.end(); ++it){
		if(it!=sorted.end()-1){
			cout<<*it<<" ";
		}else{
			cout<<*it;
		}
	}
}

