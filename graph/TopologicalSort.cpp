#include<bits/stdc++.h>

using namespace std;

void edge(vector<list<int> > &v,int a,int b){
	v[a].push_back(b);
	//v[b].push_back(a);  //undirected graph
}

void topologicalSort(vector<list<int> > &v,int a,vector<bool> &vis,stack<int> &st){
	vis[a]=true;
	
	list<int> ::iterator i;
	
	for(i=v[a].begin();i!=v[a].end();++i){
		if(!vis[*i])topologicalSort(v,*i,vis,st);
	}
	st.push(a);
}

void tSort(vector<list<int> >&v,int n){
	stack<int> st;
	vector<bool> vis(n,false);
	
	for(int i=0;i<n;++i){
		if(!vis[i])topologicalSort(v,i,vis,st);
	}
	while(!st.empty()){
		cout<<st.top()<<"  ";
		st.pop();
	}
	
	
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
	cout<<"TOPOLOGICAL SORT\n";
	tSort(v,n);
	return 0;
}
