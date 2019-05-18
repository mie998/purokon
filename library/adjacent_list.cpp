/* 以下、2つの隣接リストの実装例を紹介する。
   当然、これら以外の実装例も考えられる。
*/

//ex1
vector<int> G[MAX_V];
/*
辺に属性がある場合
struct edge { int to, cost;};
vector<edge> G[MAX_V];
*/
int main() {
	int V,E;
	scanf("%d %d", &V, &E);
	for(int i=0; i < E; i++) {
		//sからtへの辺を貼る
		int s, t;
		scanf("%d %d", &s, &t);
		G[s].push_bach(t);
		// G[t].push_back(s); 無向グラフの場合はさらにtにsへの辺を張る
	}
	// グラフの操作をここに、
}

//ex2
struct vertex {
	vector<vertex*> edge;
	/*
	 頂点の属性
	*/
};
vertex G[MAX_V];

int main() {
	int V,E;
	scanf("%d %d", &V, %E);
	for(int i = 0; i < E; i++) {
		int s, t;
		scanf("%d %d", &s, &t);
		G[s].edge.push_back(&G[t]);
		// G[t].edge.push_back(&G[s]);
	}
	// グラフの操作
}
