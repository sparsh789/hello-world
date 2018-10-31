#include<bits/stdc++.h>
using namespace std;

const int N = int(1e5)+10;

vector<int> G[N],RG[N];
int tin[N],tout[N],vis[N];
int T;
vector<int> order;
void dfs(int u)
{
	tin[u] = T++;
	vis[u] = 1;
	for(int i=0; i<G[u].size(); i++)
		if(!vis[G[u][i]])
			dfs(G[u][i]);
	tout[u] = T++;
	order.push_back(u);
}

void dfs1(int u)
{
	printf("%d ",u);
	vis[u] = 1;
	for(int i=0; i<RG[u].size(); i++)
		if(!vis[RG[u][i]])
			dfs1(RG[u][i]);
}

int main()
{
	int n,m; scanf("%d %d",&n,&m);
	for(int i=0; i<m; i++)
	{
		int u,v;
		scanf("%d %d %d",&u,&v);
		G[u].push_back(v);
		RG[v].push_back(u);
	}
	T = 0;
	for(int i=1; i<=n; i++)
		if(!vis[i])
			dfs(i);
	memset(vis,0,sizeof(vis));
	for(int i=n-1; i>=0; i--)
	{
		int u = order[i];
		if(!vis[u]) dfs1(u);
		printf("\n");
	}

















}
