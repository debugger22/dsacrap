#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> data;
int temp;
int item;
int found=0;
unsigned int size;
unsigned int comparision=0;
unsigned int assignment=0;
unsigned int gLowB;
unsigned int gUpB;
int init;
int final;


/**
*This function applies binary search algorithm recursively
*/
int binarySearch(vector<int> data,unsigned int lowerBound,unsigned int upperBound,int key){
	unsigned int mid = (lowerBound+upperBound)/2;
	//cout << mid<<lowerBound<<upperBound<<endl;
	comparision++;
	if(upperBound-lowerBound==-1)return -1;
	if(key==data.at(mid)){
		gLowB = lowerBound;
		gUpB = upperBound;
		return mid;
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
	for(vector<int>::iterator it=data.begin();it!=data.end();++it)cout<<" "<<*it;
	found = binarySearch(data,0,data.size()-1,item);
	while(true){
		temp = binarySearch(data,gLowB,found-1,item);
		cout<<temp<<" "<<data.at(temp)<<data.at(temp-1)<<" "<<item<<endl;
		if(data.at(temp)==item){
			init = temp;
		}
		if(data.at(temp-1)<item){
			break;
		}
	}
	
	while(true){
		temp = binarySearch(data,found+1,data.size(),item);
		cout<<temp<<" "<<data.at(temp)<<data.at(temp+2)<<" "<<item<<endl;
		if(data.at(temp)==item){
			final = temp;
		}
		if(data.at(temp+2)>item){
			break;
		}
	}

	cout<<found<<endl;
	cout<<init<<endl;
	cout<<"========Binary Search========"<<endl<<"Result: ";
	if(found){
		cout << "Yes"<<endl;
	}else{
		cout << "No"<<endl;
	}
	cout<<"No. of comparisions: "<<comparision<<endl<<"No. of assignments: "<<assignment<<endl;
}