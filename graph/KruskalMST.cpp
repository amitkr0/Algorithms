#include<bits/stdc++.h>

using namespace std;

//for sorting a/c to weight of edges
bool compare(pair<pair<int,int>,int> p1,pair<pair<int,int>,int> p2)
{
	return (p1.second)<(p2.second);	
}


int find(vector<int> par,int x)
{
	if(par[x]==-1)return x;
	return find(par,par[x]);
}


void Union(vector<int> &par,vector<int> &rank,int x,int y)
{
	if(rank[x]>rank[y]){
		par[y]=x;
	}
	else if(rank[y]>rank[x]){
		par[x]=y;
	}
	else{
		par[x]=y;
		rank[y]++;
	}
}

void MST(vector<pair<pair<int,int>,int> > &ed,vector<pair<pair<int,int>,int> > &v,int n){
	int i=0,j=0;
	vector<int> rank(n+1,0);
	vector<int> par(n+1,-1);
	
	
	
	while(j<n){
		//if(i==ed){flag=false;break;}
		pair<int,int> p=ed[i].first;
		int x=find(par,p.first);
		int y=find(par,p.second);
		if(x!=y){
			pair<int,int> p1=make_pair(p.first,p.second);
			v.push_back(make_pair(p1,ed[i].second));
			j++;
			Union(par,rank,x,y);
		}
		i++;
	}
	
	
}





int main()
{
	int n,e;
	cin>>n>>e;
	vector<list<int> > v(n);
	vector<pair<pair<int,int>,int> > ed;
	for(int i=0;i<e;++i){
		int a,b,w;
		cin>>a>>b>>w;
		v[a].push_back(b);
		v[b].push_back(a);
		pair<int,int> p=make_pair(a,b);
		ed.push_back(make_pair(p,w));
	}
	
/*	for(int i=0;i<e;++i){
		pair<int,int> p=ed[i].first;
		cout<<p.first<<"  "<<p.second<<"  "<<ed[i].second<<endl;
	}
*/	
	sort(ed.begin(),ed.end(),compare);
	
	
	vector<pair<pair<int,int>,int> > ans;
	
	MST(ed,ans,n-1);
	cout<<"Tree with edges \n";
	
	for(int i=0;i<n-1;++i){
		pair<int,int> p=ans[i].first;
		cout<<"edges b/w nodes : "<<p.first<<"  "<<p.second<<"  and weight : "<<ans[i].second<<endl;
	}
	
	return 0;
	
}
