/*
https://www.acwing.com/problem/content/167/
*/

#include<iostream>
#include<algorithm>

using namespace std;
const int N=20;
int n,m,cat[N],sum[N];
int ans=N;

void dfs(int u,int k){//分支有两种状态，一种是将当前第u个猫放入0~k-1个车中，另一种是将当前猫新开一个车 
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
	
	sum[k]=cat[u];//新开一个车 
	dfs(u+1,k+1);
	sum[k]=0;	
}


int main (){
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>cat[i];
	}
	sort(cat,cat+n);
	reverse(cat,cat+n);//保证根结点的分支较少，让剪枝率加大 
	dfs(0,0);
	cout<<ans<<endl;
	return 0;
} 
