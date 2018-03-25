#include<bits/stdc++.h>

using namespace std;


void prim(vector<pair<int,int> > v[],int n,int s)
{
	vector<bool> mset(n,false);
	vector<int>  dist(n,INT_MAX);
	vector<int> par(n,-1);
	priority_queue<pair<int,int> ,vector<pair<int,int> > ,greater<pair<int,int> > > pq;
	dist[s]=0;
	pq.push(make_pair(0,s));
	int maxwt=0;
	while(!pq.empty())
	{
		int u=(pq.top()).second;
		pq.pop();
		maxwt+=pq.top().first;
		mset[u]=true;
		vector<pair<int,int> > :: iterator it;
		for(it=v[u].begin();it!=v[u].end();it++)
		{
			int a=it->first;
			int b=it->second;
			if(!mset[a] && dist[a]>b){
				dist[a]=b;
				pq.push(make_pair(b,a));
				par[a]=u;
			}
		}	
	}
	cout<<maxwt<<endl;
	
	for(int i=1;i<n;++i){
		cout<<par[i]<<"  "<<i<<endl;
	}
}

int main()
{
	int n,e;
	cin>>n>>e;
	vector<pair<int,int> > v[n];
	for(int i=0;i<e;++i)
	{
		int a,b,r;
		cin>>a>>b>>r;
		v[a].push_back(make_pair(b,r));
		v[b].push_back(make_pair(a,r));
	}
	int src=0;
	//cin>>src;
	prim(v,n,src);
}
