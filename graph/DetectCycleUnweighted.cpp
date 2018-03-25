#include<bits/stdc++.h>

using namespace std;

void edge(vector<list<int> > &v,int a,int b){
	v[a].push_back(b);
	//v[b].push_back(a);  //undirected graph
}

bool cyclic(vector<list<int> > &v,int a,vector<bool> &vis,vector<bool> &chk){
	
	if(!vis[a]){
		vis[a]=true;
		chk[a]=true;
		list<int> ::iterator i;
		for(i=v[a].begin();i!=v[a].end();++i){
			if(!vis[*i] && cyclic(v,*i,vis,chk))
				return true;
			if(chk[*i])
				return true;
		}	
	}
	chk[a]=false;
	return false;
}




bool isCyclic(vector<list<int> >&v,int n){
	vector<bool> vis(n,false);
	vector<bool> check(n,false);
	
	for(int i=0;i<n;++i){
		if(!vis[i] && cyclic(v,i,vis,check))
			return true;
	}
	return false;
	
}

int main()
{
	int n;
	cin>>n;
	vector<list<int> > v(n);
	int edg;
	cin>>edg;
	int a,b;
	for(int i=0;i<edg;++i){
		cin>>a>>b;
		edge(v,a,b);
	}
	
	cout<<isCyclic(v,n);
	return 0;
}
