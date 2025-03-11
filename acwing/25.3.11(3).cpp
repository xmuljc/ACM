//sort的重载 ，对应洛谷P1093 

#include<iostream>
#include<algorithm>

using namespace std;

struct student{
	int id,cn,math,eg,total;
	bool operator<(const student &other)const{
	if(total!=other.total)return total>other.total;
	else if(cn!=other.cn)return cn>other.cn;
	else return id<other.id;
	}	
};

int main (){
	int n;
	cin>>n;
	int a,b,c;
	struct student stu[310];
	for(int i=0;i<n;i++){
		cin>>a>>b>>c;
		stu[i].id=i+1;
		stu[i].cn=a;
		stu[i].math=b;
		stu[i].eg=c;
		stu[i].total=a+b+c;
	}
	
	sort(stu,stu+n);
	
	for(int i=0;i<5;i++){
		cout<<stu[i].id<<' '<<stu[i].total<<endl;	
	}
	return 0;
}
