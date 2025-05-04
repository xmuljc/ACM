/*https://www.acwing.com/problem/content/1100/*/

#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;
const int N=60;
int n,m,g[N][N];
bool vt[N][N];
int ans_max;
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};


bool judge(int k,int u){
	int a[4][7]={1,8,4,9,5,12,13,1,2,4,3,5,6,7,2,4,8,6,10,12,14,1,2,8,3,10,9,11};
	for(int i=0;i<4;i++){
		for(int j=0;j<7;j++){
			if(a[i][j]==k&&i==u)return true;
		}
	}
	return false;
}


void bfs(int x,int y){
//	cout<<x<<' '<<y<<endl;
	queue<pair<int,int>>q;
	q.push({x,y});
	vt[x][y]=true;
	int cnt=1;
	
	while(!q.empty()){
		auto t=q.front();
		q.pop();
		x=t.first,y=t.second;
		for(int i=0;i<4;i++){
		  int nx=x+dx[i],ny=y+dy[i];
		  if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&vt[nx][ny]==false&&judge(g[x][y],i)){
			vt[nx][ny]=true;
			cnt++;
			q.push({nx,ny});
			}
		 }	
	}	
	ans_max=max(ans_max,cnt);
} 


int main (){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>g[i][j];
		}
	}
	
	int id=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(vt[i][j]==false){
				bfs(i,j);
				id++;
			}
		}
	}
	cout<<id<<endl<<ans_max<<endl;
	return 0;
} 
