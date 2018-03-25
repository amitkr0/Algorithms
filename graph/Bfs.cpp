#include<bits/stdc++.h>

using namespace std;

void edge(vector<list<int> > &v,int a,int b){
	v[a].push_back(b);
	v[b].push_back(a);  //undirected graph
}
void bfs(vector<list<int> >&v,int a,vector<bool> &vis)
{
	queue<int> q;
	q.push(a);
	vis[a]=true;
	list<int> :: iterator it;
	while(!q.empty())
	{
		a=q.front();
		cout<<a<<"  ";
		q.pop();
		for(it=v[a].begin();it!=v[a].end();++it){
			if(!vis[*it]){
				q.push(*it);
				vis[*it]=true;
			}
		}
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
	cout<<"BFS TRAVERSAL\n";
	vector<bool> vis(n,false);
	bfs(v,0,vis);
	return 0;
}
