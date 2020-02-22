#include<iostream>
#include<cstdio> 
#include<cstring>
#include<vector>
using namespace std;
typedef pair<int, int> P;
const long long INF = 0x3f3f3f3f3f3f3f3fll;
const int N = 8+1;
const int K = 3+1;
int n, m, k, u, v, w;
int num[N];
long long dp[N][K];//dp[u][p]表示在u这棵子树(含u)里选了p个点的最小代价
long long tmp[K];//辅助数组，用于暂存当前节点的解
vector<P> edge[N];//edge[u] 点u的所有的边
bool ok[N];//ok[u] u是否为重要节点
int min(int a, int b) {
	return a < b ? a : b;
}
int x = 0;
void dfs(int u, int fa) {//u是当前的点,fa是父节点
	dp[u][0] = 0;
	if (ok[u]) {//是否为重要节点
		num[u] = 1;//num[u]表示以u为根节点的树中重要节点的个数 
		dp[u][1] = 0;//如果u是重要节点,那么当只选择一个点时，最优结果为0，即选择了自身，不需要经过任何路径
	}
	for (int i = 0; i < edge[u].size();i++) {
		int v = edge[u][i].first;//v点
		int w = edge[u][i].second;//w:权重
		if (v == fa) {
			continue;//跳过父节点的边
		}
		dfs(v, u);
		int sum = min(k, num[u] + num[v]);
		int mn = min(k, num[u]);
		for (int p = 0; p <= sum; ++p) {
			tmp[p] = dp[u][p];//保存旧状态
		}
		for (int p = 0; p <= mn; ++p) {//其余子树p个（以u为根的子树除去以v为根的子树剩余的重要节点中选p个）
			for (int q = 0; p + q <= sum; ++q) {//当前子树q个（以v为根的子树中的重要节点节点中选q个）
				tmp[p + q] = min(tmp[p + q], dp[u][p] + dp[v][q] + 1ll * q*(k - q)*w);//保存更新状态
				x++;
			}
		}
		for (int p = 0; p <= sum; ++p) {
			dp[u][p] = min(dp[u][p], tmp[p]);//将当前点的解更新为最优解
		}
		num[u] += num[v];//重要节点计数
	}
}
int main() {
	cin >> n >> m >> k;
	memset(dp, INF, sizeof dp);
	for (int i = 0; i < m; i++)
	{
		cin >> v;
		ok[v] = true;
	}
	for (int i = 2; i <= n; i++)
	{
		cin >> u >> v >> w;
		edge[u].push_back(P(v, w));
		edge[v].push_back(P(u, w));
	}
	dfs(1, -1);
	cout << endl;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= k; ++j)
			printf("dp[%d][%d]:%lld\n", i, j, dp[i][j]);
	cout << dp[1][k] << endl;
	cout << x;
	system("pause");
	return 0;
}


/*
5 3 2
1 3 2
1 2 4
1 3 5
1 4 3
4 5 1

8 5 3
3 4 6 7 8
1 2 1
2 3 3
2 4 3
2 5 4
5 6 5
5 7 6
5 8 1

5 5 5
1 2 3 4 5
1 2 1
2 3 2
3 4 3
4 5 4



6 6 2
1 2 3 4 5 6
1 2 1
1 6 8
1 3 7
3 4 3
4 5 3
*/