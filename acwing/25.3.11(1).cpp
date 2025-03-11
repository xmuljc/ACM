//ÆßÏ¦¼À£¬Ç°×ººÍ+ÅÅÐò 
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

typedef long long LL;
const int N=100010;
int n,m,t;
int row[N],col[N];


LL work (int n,int a[]){
	int sum=0;
	for(int i=1;i<=n;i++)sum+=a[i];
	if(sum%n)return -1;
	int ave=sum/n;
	int s[N+1];//Ç°×ººÍ
	s[1]=0;
	for(int i=2;i<=n;i++)s[i]=s[i-1] +a[i];
	int c[N];
	c[1]=0;
	for(int i=2;i<=n;i++)c[i]=s[i-1]-(i-1)*ave;
	sort(c+1,c+1+n);
	LL res=0;
	for(int i=1;i<=n;i++)res+=abs(c[i]-c[(n+1)/2]);
	
	return res;
}



int main (){
	cin>>n>>m>>t;
	while(t--){
		int a,b;
		cin>>a>>b;
		row[a]++;
		col[b]++;
	}
	
	LL res_r=work(n,row);
	LL res_c=work(m,col);
	if(res_r!=-1&&res_c!=-1)cout<<"both"<<' '<<res_r+res_c<<endl;
	else if(res_r!=-1)cout<<"row"<<' '<<res_r;
	else if(res_c!=-1)cout<<"col"<<' '<<res_c;
	else puts("impossible");
	
	return 0;
}
