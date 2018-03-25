#include<bits/stdc++.h>

using namespace std;

void edge(vector<list<int> > &v,int a,int b){
	v[a].push_back(b);
	v[b].push_back(a);  //undirected graph
}

void dfs(vector<list<int> > &v,int a,vector<bool> &vis){
	vis[a]=true;
	cout<<a<<" ";
	list<int> ::iterator i;
	for(i=v[a].begin();i!=v[a].end();++i){
		if(!vis[*i])dfs(v,*i,vis);
	}
}

void dfsIter(vector<list<int> > &v,int a,int n){
	vector<bool> vis(n,false);
	stack<int> st;
	
	st.push(a);
	list<int> ::iterator it;
	while(!st.empty()){
		a=st.top();
		st.pop();
		if(!vis[a]){
			cout<<a<<"  ";
			vis[a]=true;
		}
		
		for(it=v[a].begin();it!=v[a].end();++it){
			if(!vis[*it])st.push(*it);
		}
	}
	return;
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
	cout<<"DFS TRAVERSAL\n";
	vector<bool> vis(n,false);
	dfs(v,0,vis);
	cout<<endl;
	dfsIter(v,0,n);
	return 0;
}
