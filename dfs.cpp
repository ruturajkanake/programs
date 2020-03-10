#include <bits/stdc++.h>
using namespace std;

stack <int> s;
vector <int> sequence;

void dfs(int k, bool visited[], vector <int> adj[] )
{
	visited[k]=true;
	sequence.push_back(k);
	s.push(k);
	for(int i=0;i<adj[k].size();++i){
		if(visited[adj[k][i]]==false){
			dfs(adj[k][i], visited, adj);
		}
	}
	s.pop();
}

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

	s.push(initial);	
	dfs(initial, visited, adj);
	for(int i=0;i<sequence.size();++i){
		cout<<sequence[i]<<" ";
	}
	return 0;
}