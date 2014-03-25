#include<iostream>
#include<vector>

using namespace std;
unsigned int m, n;
vector<string> names, toppers;
vector<int> marks;
string tempStr;
int temp;

/**
*Function o calculate numerical value of character
*/
int getNumVal(char literal){
	if(int(literal)>=65 && int(literal)<=90)return int(literal)-64;
	else if(int(literal)>=97 && int(literal)<=122)return int(literal)-96;
}

/**
*Function to calculate hash key
*/
int hash(string name){
	int len = name.length();
	int sum = 0;
	for(int i=0;i<len;i++)sum += getNumVal(name.at(i));
	return sum % m;
}

/**
*Function to search marks based on name;
*/
int getMarks(string name){
	int i;
	for(i=0;i<n; i++){
		if(name==names.at(i)){
			break;
		}
	}
	return marks.at(i);
}

/**
*Function to search name based on marks
*/
string getName(int pmarks){
	int i;
	for(i=0;i<n; i++){
		if(pmarks==marks.at(i)){
			break;
		}
	}
	return names.at(i);
}

int main(){
	cin >> m;
	cin >> n;
	vector<vector<string> > values(m);	//Hash table
	for(int i=0;i<n;i++){
		cin >> tempStr;
		names.push_back(tempStr);
		cin >> temp;
		marks.push_back(temp);
	}
	for(vector<string>::iterator it=names.begin(); it!=names.end(); ++it){
		values[hash(*it)].push_back(*it);
	}
	cout << m <<endl;
	//Part which takes care of collisions and all
	for(int i=0;i<m; i++){
		int maxmarks = getMarks(values.at(i).at(0));
		for(int j=1;j< values.at(i).size(); j++){
			if(getMarks(values.at(i).at(j))>maxmarks){
				maxmarks = getMarks(values.at(i).at(j));
			}
		}
		toppers.push_back(getName(maxmarks));
	}
	int count = 0;
	for(vector<string>::iterator it=toppers.begin(); it!=toppers.end(); ++it){
		cout << count << " " << *it << " " << getMarks(*it) << endl;
		count++;
	}	
	return 0;
}
