#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>


using namespace std;
const int N=2600,M=6600;

typedef pair<int,int>PII;
priority_queue<PII,vector<PII>,greater<PII>>heap;

int n,m,st,ed;
int e[N],ne[N],w[M],h[N],idx;
int d[N];
bool vt[N];

void add(int a,int b,int c){
	e[idx]=b;
	w[idx]=c;
	ne[idx]=h[a];
	h[a]=idx++;
}

void dijkstra(int u){
	d[u]=0;
	heap.push({d[u],u});
	while(heap.size()){
		auto v=heap.top();
		heap.pop();
		int distance =v.first,	u=v.second;
		if(vt[u]==true)//判断是否已经访问过 
			continue;
		vt[u]=true;
		for(int j=h[u];j!=-1;j=ne[j]){
			int i=e[j];
			if(!vt[i]&&d[i]>distance+w[j]){//判断是否已经访问过 
				d[i]=distance+w[j];
				heap.push({d[i],i});
			}
			
		}
	}	
}


int main (){
	cin>>n>>m>>st>>ed;
	int a,b,c;
	memset(h,-1,sizeof h);
	while(m--){
		cin>>a>>b>>c;
		add(a,b,c);	
	}
	memset(d,0x3f,sizeof d);
	dijkstra(st);
	cout<<d[ed]<<endl;
	return 0;
}
