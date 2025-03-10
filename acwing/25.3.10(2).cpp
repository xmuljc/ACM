#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

const int N=810, M=1450*2+10; // 注意这里将M改为2*M+10,双向边。。。。
const int inf=0x3f3f3f3f;
typedef pair<int,int>PII;
priority_queue<PII,vector<PII>,greater<PII>>heap;

int n,p,c;
int e[M],ne[M],h[N],w[M],idx; 
int id[510],d[N];
bool vt[N];

void add(int a,int b,int c){
    e[idx]=b;
    w[idx]=c;
    ne[idx]=h[a];
    h[a]=idx++;    
}

int dijkstra(int u){
    memset(d,0x3f,sizeof d);
    memset(vt,false,sizeof vt);
    d[u]=0;
    heap.push({0, u});
    while(!heap.empty()){
        auto t=heap.top();
        heap.pop();
        int distance=t.first, u=t.second;
        if(vt[u]) continue;
        vt[u]=true;
        for(int j=h[u]; j!=-1; j=ne[j]){
            int v=e[j];
            if(d[v] > distance + w[j]){
                d[v] = distance + w[j];
                heap.push({d[v], v});
            }
        }
    }
    int res=0;
    for(int j=1; j<=n; j++){//这部分要在dijkstra内部跑
        if(d[id[j]] == inf) return inf;
        res += d[id[j]];
    }
    return res;
}

int main(){
    cin>>n>>p>>c;
    for(int i=1; i<=n; i++) cin>>id[i];
    memset(h, -1, sizeof h);
    while(c--){
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
        add(b,a,c);
    }
    int ans=inf;
    for(int i=1; i<=p; i++){
        int res=dijkstra(i);
        ans = min(ans, res);
    }
    cout<<ans;
    return 0;
}
