//用二分,分治的思想去求第k小的数 

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int search(int arr[],int l,int r,int k){
	int i=l-1,j=r+1,x=arr[(l+r)>>1];
while(i<=j){
		do i++;while(arr[i]<x);
		do j--;while(arr[j]>x);
		if(i<j)
		swap(arr[j],arr[i]);	
	}
	if(k<=j)return search(arr,l,j,k);
	else if(k>=i)return search(arr,i,r,k);
	else return arr[j+1];
}


int main (){
	int k,n,arr[50100];
	 cin>>n>>k;
	 for(int i=0;i<n;i++)scanf("%d",&arr[i]);
	cout<<search(arr,0,n-1,k);
	return 0;
}
