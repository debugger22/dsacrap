#include <iostream>
#include <vector>

using namespace std;

vector<int> data;
int temp;
int item;
bool found=false;
unsigned int size;
unsigned int comparision=0;
unsigned int assignment=0;

int main(){
	cin>>size;
	for(int i=0;i<size;i++){
		cin>>temp;
		data.push_back(temp);
	}
	cin>>item;
	for(int i=0;i<data.size();i++){
		if(data.at(i)==item){
			found=true;
			break;
		}
		comparision++;
	}
	cout<<"========Linear Search========"<<endl<<"Result: ";
	if(found){
		cout << "Yes"<<endl;
	}else{
		cout << "No"<<endl;
	}
	cout<<"No. of comparisions: "<<comparision<<endl<<"No. of assignments: "<<assignment<<endl;
}