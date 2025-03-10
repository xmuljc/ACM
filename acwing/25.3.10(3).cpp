#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;
const int N=2100,M=1e5+10;

int e[M],ne[M],h[M],idx;
double w[M],d[M];
int vq[N];
int n,m;
void add(int a,int b,double c){
	e[idx]=b;
	w[idx]=c;
	ne[idx]=h[a];
	h[a]=idx++;
}

void spfa(int u){
	for(int i=1;i<=M;i++)d[i]=0;
	d[u]=1;
	queue<int>q;
	q.push(u);
	vq[u]=true;
	while(q.size()){
		int t=q.front();
		q.pop();
		vq[t]=false;
		for(int j=h[t];j!=-1;j=ne[j]){
			int i=e[j];
			if(d[i]<d[t]*w[j]){
				d[i]=d[t]*w[j];
				if(!vq[i]){
					q.push(i);
					vq[i]=true;
				}
			}			
		}	
	}		
}

int main (){
	cin>>n>>m;
	int a,b;
    double c;
    memset(h,-1,sizeof h);
	while(m--){
		cin>>a>>b>>c;
		c*=0.01;
		add(a,b,1.0-c);
		add(b,a,1.0-c);
	}
 	cin>>a>>b;
 	spfa(a);
 	printf("%.8lf",100/d[b]);
	return 0;
}


