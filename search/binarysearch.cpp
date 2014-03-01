#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> data;
int temp;
int item;
bool found=false;
unsigned int size;
unsigned int comparision=0;
unsigned int assignment=0;

/**
*This function applies binary search algorithm recursively
*/
bool binarySearch(vector<int> data,unsigned int lowerBound,unsigned int upperBound,int key){
	unsigned int mid = (lowerBound+upperBound)/2;
	cout << mid<<lowerBound<<upperBound<<endl;
	comparision++;
	if(upperBound-lowerBound==-1)return false;
	if(key==data.at(mid)){
		return true;
	}else if(key<data.at(mid)){
		upperBound = mid-1;
		comparision++;
		return binarySearch(data,lowerBound,upperBound,key);
	}else{
		lowerBound = mid+1;
		comparision++;
		return binarySearch(data,lowerBound,upperBound,key);
	}
}

int main(){
	cin>>size;
	for(int i=0;i<size;i++){
		cin>>temp;
		data.push_back(temp);
	}
	cin>>item;
	sort(data.begin(),data.end()); //Sorting to use in binary search
	found = binarySearch(data,0,data.size()-1,item);
	cout<<"========Binary Search========"<<endl<<"Result: ";
	if(found){
		cout << "Yes"<<endl;
	}else{
		cout << "No"<<endl;
	}
	cout<<"No. of comparisions: "<<comparision<<endl<<"No. of assignments: "<<assignment<<endl;
}