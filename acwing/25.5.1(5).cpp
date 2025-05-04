/*
https://www.acwing.com/problem/content/167/
*/

#include<iostream>
#include<algorithm>

using namespace std;
const int N=20;
int n,m,cat[N],sum[N];
int ans=N;

void dfs(int u,int k){//��֧������״̬��һ���ǽ���ǰ��u��è����0~k-1�����У���һ���ǽ���ǰè�¿�һ���� 
	if(k>=ans)return;
	if(u==n){
		ans=k;
		return;
	}
	for(int i=0;i<k;i++){
		if(sum[i]+cat[u]<=m){
			sum[i]+=cat[u];
			dfs(u+1,k);
			sum[i]-=cat[u];
		}
	}
	
	sum[k]=cat[u];//�¿�һ���� 
	dfs(u+1,k+1);
	sum[k]=0;	
}


int main (){
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>cat[i];
	}
	sort(cat,cat+n);
	reverse(cat,cat+n);//��֤�����ķ�֧���٣��ü�֦�ʼӴ� 
	dfs(0,0);
	cout<<ans<<endl;
	return 0;
} 
