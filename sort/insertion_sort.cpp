#include <iostream>
#include <vector>

using namespace std;
vector<int> data;
int temp;
unsigned int size;
unsigned int comparision;
unsigned int assignment;


/**
*This program uses bubble sort algorithm to sort a data vector in increasing order
*/
int main(){
	cin>>size;
	for(int i=0;i<size;i++){
		cin>>temp;
		data.push_back(temp);
	}
	comparision = 0;
	assignment = 0;
	for(int i=1;i<data.size();i++){
		for(int j=i;j>0;j--){
			if(data.at(j)<data.at(j - 1)){
				temp = data.at(j);
				data[j] = data.at(j-1);
				data[j-1] = temp;
				assignment+=3;
			}
			comparision++;	
		}
	}
	cout << "========Insertion Sort========"<<endl;
	cout << "Result: ";
	for(vector<int>::iterator it=data.begin();it!=data.end();++it){
		cout<<*it<<" ";
	}

	cout<<endl<<"No. of comparisions: "<<comparision<<endl<<"No. of assignments: "<<assignment<<endl;
	return 0;
}