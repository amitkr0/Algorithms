#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,k,ed,a,b;
	cin>>n>>k>>ed;
	vector<list<int> > v(n);
	for(int i=0;i<ed;i++){
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	vector<int> edge(n,0);
	list<int> :: iterator it;
	for(int i=0;i<n;++i){
		for(it=v[i].begin();it!=v[i].end();++it)edge[i]++;
	}
	
	set<int> st;
	for(int i=0;i<n;++i){
		if(edge[i]<k)st.insert(i);
	}
	
	set<int> :: iterator is;
	
	while(!st.empty()){
		is=st.begin();
		edge[*is]=-1;
		for(int i=0;i<n;++i){
			if(i==(*is))v[i].clear();
			else{
				for(it=v[i].begin();it!=v[i].end();++it){
					if(*it==(*is)){
						v[i].erase(it);edge[i]--;
						break;	
					}
				}
			}
			if(edge[i]>=0 && edge[i]<k)st.insert(i);
		}
		st.erase(*is);	
	}
	
	cout<<"New Graph\n";
	
	for(int i=0;i<n;++i){
		if(edge[i]>=k){
			cout<<"NODE "<<i<<" edges with \t";
			for(it=v[i].begin();it!=v[i].end();++it)cout<<(*it)<<" ";
			cout<<endl;
		}
	}
	
	return 0;
}
