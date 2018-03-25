#include<bits/stdc++.h>
using namespace std;

void dijkstra(vector<pair<int,int> > v[],int n,int s)
{
	vector<bool> ver(n,false);
	vector<int> dist(n,INT_MAX);
	priority_queue<pair<int,int> , vector<pair<int,int> > , greater<pair<int,int> > > pq;
	
	pq.push(make_pair(0,s));
	dist[s]=0;
	while(!pq.empty())
	{
		int u=pq.top().second;
		int wt=pq.top().first;
		pq.pop();
		if(ver[u])continue;
		ver[u]=true;
		vector<pair<int,int> > :: iterator it;
		for(it=v[u].begin();it!=v[u].end();++it){
			if(!ver[it->first] && dist[it->first]>dist[u]+it->second){
				dist[it->first]=dist[u]+it->second;
				pq.push(make_pair(dist[it->first],it->first));
			}
		}
	}
	for(int i=0;i<n;++i){
		cout<<i<<"  "<<dist[i]<<endl;
	}
}

int main()
{
	int n,e;
	cin>>n>>e;
	vector<pair<int,int> > v[n];
	for(int i=0;i<e;++i){
		int a,b,r;
		cin>>a>>b>>r;
		v[a].push_back(make_pair(b,r));
		v[b].push_back(make_pair(a,r));
	}
	int src=0;
	//cin>>src;
	dijkstra(v,n,src);
	
	return 0;
}





/*
int main(){
	
	int n,e;
	cin>>n>>e;
	vector<pair<int,int> > v[n];
	for(int i=0;i<e;++i){
		int a,b,w;
		cin>>a>>b>>w;
		v[a-1].push_back(make_pair(b-1,w));
		v[b-1].push_back(make_pair(a-1,w));
	}
	vector<int> dist(n,INT_MAX);
	vector<bool> st(n,false);
	int i,l=0;
	cin>>i;
	i--;
	dist[i]=0;
	while(true){
		int x=dist[i];
		cout<<i<<" :::  ";
		vector<pair<int,int> > :: iterator it;
		for(it=v[i].begin();it!=v[i].end();++it){
			int f=it->first,sec=it->second;
			if(!st[i] && (x+sec)<dist[f]){
				dist[f]=(x+sec);
				cout<<f<<"  "<<dist[f]<<",  ";
			}
		}
		cout<<endl;
		st[i]=true;
		int miN=INT_MAX,m=0;
		for(int k=0;k<n;++k){
			if(!st[k] && miN>dist[k]){
				miN=dist[k];
				m=k;
			}
		}
		i=m;
		l++;
		if(st[i])break;
	}
	cout<<endl<<endl;
	cout<<l<<endl;
	for(int k=0;k<n;++k){
		if(dist[k]==INT_MAX)cout<<"-1 ";
            else{
                cout<<dist[k]<<" ";
            }
	}
}
*/
