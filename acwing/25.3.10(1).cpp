#include<iostream>
#include<algorithm>

using namespace std;
const int inf=0x3f3f3f3f;

int main (){
	int n,p,c;
	cin>>n>>p>>c;
	int hash[600],g[90][90];
	for(int i=1;i<=p;i++){
		for(int j=1;j<=p;j++){
			if(i!=j)g[i][j]=inf;
			else g[i][j]=0;
		}
	}
	
	for(int i=1;i<=n;i++)cin>>hash[i];

	for(int i=1;i<=c;i++){
		int a,b,c;
		cin>>a>>b>>c;
		g[a][b]=min(c,g[a][b]);
		g[b][a]=min(c,g[b][a]);
	}
	int max_ans=0;
	for(int i=1;i<=p;i++){
		int res=0,count=0;
		for(int j=1;j<=p;j++){
			if(g[i][j]!=inf&&hash[j]){
				res+=g[i][j];
				count++;
			}	
		}
		if(count==n)max_ans=max(max_ans,res);
	}
	cout<<max_ans;
	return 0;
}
