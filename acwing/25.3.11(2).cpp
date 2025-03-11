//使用set去重 
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

int main (){
	int n;
	cin>>n;
	set<int>num;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		num.insert(a);
	} 
	
	
	cout<<num.size()<<endl;
	 for(auto t=num.begin();t!=num.end();t++){
	 	cout<<*t<<' ';
	 }
	 
	
	return 0;
}
