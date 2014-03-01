#include <iostream>
#include <vector>

using namespace std;
int temp;
int dataArray[] = {70,-10,50,5,1,-1,0,9,6,4,5,9,87,54,31,65,4};	//data Array


/**
*This program uses bubble sort algorithm to sort a data vector in increasing order
*/
int main(){
	vector<int> data(dataArray,dataArray+sizeof(dataArray)/4);
	for(int i=0;i<data.size();i++){
		for(int j=i;j<data.size()-1;j++){
			temp = data.at(j);
			if(temp>data.at(j+1)){
				data[j] = data.at(j+1);
				data[j+1] = temp;
			}
		}
	}
	for(vector<int>::iterator it=data.begin();it!=data.end();++it){
		cout<<*it<<" ";
	}
	return 0;
}