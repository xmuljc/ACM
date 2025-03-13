#include<iostream>
#include<algorithm>

using namespace std;

int n,m,arr[1000010];

 bool check(int x){
 	int res=0,num=0;
 	for(int i=0;i<n;i++){
 		if(arr[i]+res<=x)res+=arr[i];
 		else res=arr[i],num++;
	 }
 	return num>=m;
 }
 
 int main (){
 	cin>>n>>m;
 	int l=0,r=0;
 	for(int i=0;i<n;i++){
 		cin>>arr[i];
 		l=max(l,arr[i]);
 		r+=arr[i];
	 }
	 
	 int mid;
 	while(l<r){
 		 mid=(l+r+1)>>1;
 		if(check(mid))l=mid;
 		else r=mid-1;
	 }
 	cout<<mid;
 	
 	return 0;
 }
