int d[MAX_V][MAX_V];//d[v][u]は辺e=(v,u)のコスト(defalut:INF d[i][i] = 0)
int V;

void warshall_floyd() {
	for (int k = 0; k < V; k++)
		for (int i = 0; i < V; i++)
			for (int j = 0; j < V; j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}
