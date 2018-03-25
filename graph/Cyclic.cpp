#include<bits/stdc++.h>
using namespace std;


void edge(vector<list<int> > &v,int a,int b){
	v[a].push_back(b);
	//v[b].push_back(a);  //undirected graph
}

int findP(vector<int> &p,int a)
{
	if(p[a]==-1)return a;
	return findP(p,p[a]);
}

void Union(vector<int> &p,int a,int b){
	int pb=findP(p,b);
	int pa=findP(p,a);
	p[pa]=pb;
}

int isCyclic(vector<list<int> > &v,int n){
	vector<int> par(n,-1);
	for(int i=0;i<n;++i){
		list<int> ::iterator it;
		for(it=v[i].begin();it!=v[i].end();++it){
			int x=findP(par,*it);
			int y=findP(par,i);
				
			if(x==y)return 1;
				
			Union(par,x,y);
		}
	}
	return 0;	
	
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
}
