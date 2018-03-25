#include<bits/stdc++.h>
using namespace std;

void floydWarshall(vector<vector<int> > v,int n){
	int dist[n][n];
	int path[n][n]={0};
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			if(v[i][j]==0 && i!=j)dist[i][j]=99999;
			else
				dist[i][j]=v[i][j];
		}
	}
	
	for(int k=0;k<n;++k){
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				if(dist[i][j]>dist[i][k]+dist[k][j]){
					dist[i][j]=dist[i][k]+dist[k][j];
					path[i][j]=path[k][j];
				}
			}
		}
	}
	bool flag=false;
	for(int i=0;i<n;++i){
		if(dist[i][i]<0)flag=true;
	}
	
	if(flag==true){
		cout<<"NEgative cycle\n";
	}
	else{
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				cout<<dist[i][j]<<"  ";
			}
			cout<<endl;
		}
	}
	
}

int main(){
	int n;
	cin>>n;
	vector<vector<int> > v(n);
	for(int i=0;i<n;++i){
		v[i].clear();
		v[i].resize(n,0);
	}
	int e;
	cin>>e;
	for(int i=0;i<e;++i)
	{
		int a,b,w;
		cin>>a>>b>>w;
		v[a][b]=w;
	}
	floydWarshall(v,n);

	return 0;
}	
