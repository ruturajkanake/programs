#include <bits/stdc++.h>
using namespace std;

int main(){
	int nodes,edges,x,y;
	cin>>nodes>>edges;
	vector <int> adj[nodes+1];

	for(int i=0;i<edges;++i){
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	int initial;
	cin>>initial;

	bool visited[nodes+1];
	for(int i=1;i<=nodes;++i){
		visited[i]=false;
	}

	queue <int> q;
	vector <int> sequence;	

	q.push(initial);
	visited[initial]=true;
	sequence.push_back(initial);
	while(!q.empty()){
		int p = q.front();
		q.pop();
		for(int i=0;i<adj[p].size();++i){
			if(visited[adj[p][i]]==false){
				visited[adj[p][i]]=true;
				sequence.push_back(adj[p][i]);
				q.push(adj[p][i]);
			}
		}
	}

	cout<<sequence.size();
	return 0;
}