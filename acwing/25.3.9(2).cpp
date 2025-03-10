#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;
const int N=110;
int inf=0x3f3f3f3f;
int g[N][N];

int main (){
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j)g[i][j]=inf;
			else g[i][j]=0;
		}
	}
		
	int a,b,c;
	while(m--){
		cin>>a>>b>>c;
	    g[a][b]=min(c,g[a][b]);
		g[b][a]=min(c,g[b][a]);
	}
	
	for(int k=1;k<=n;k++)
	 for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++){
	  	g[i][j]=min(g[i][k]+g[k][j],g[i][j]);
	  }
	  
	 int max_ans=0; 
	for(int i=2;i<=n;i++){
		max_ans=max(g[1][i],max_ans);
	}
	if(max_ans==inf)cout<<-1;
	else cout<<max_ans;	
	return 0;
}
