#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define f(i,x,n) for(int i=x;i<n;++i)


using namespace std;

int main()
{
	int n,e;
	cin>>n>>e;
	vector<pair<pair<int,int>,int> > ed;
	f(i,0,e){
		int a,b,w;
		cin>>a>>b>>w;
		pair<int,int> p=mp(a,b);
		ed.pb(mp(p,w));
	}
	vector<int> dist(n,99999);
	vector<int> par(n,-1);
	int s;
	cin>>s;
	dist[s]=0;
	f(j,0,n-1){
		vector<pair<pair<int,int>,int> > :: iterator it;
		for(it=ed.begin();it!=ed.end();++it){
			pair<int,int> p=it->first;
			if(dist[p.second]>dist[p.first]+it->second){
				dist[p.second]=dist[p.first]+it->second;
				par[p.second]=p.first;
			}
		}	
	}
	cout<<"Shortest Path from "<<s<<endl;
	f(i,0,n){
		cout<<dist[i]<<"  ";	
	}
	cout<<endl;
	
	int count=1;
	cout<<"Path ::::  "<<s<<"  ";
	while(count<n){
		f(i,0,n){
			if(par[i]==s){
				cout<<i<<"  ";
				s=i;
				count++;
			}
		}
	}
	
	return 0;
}
