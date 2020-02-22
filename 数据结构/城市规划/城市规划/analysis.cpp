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
long long dp[N][K];//dp[u][p]��ʾ��u�������(��u)��ѡ��p�������С����
long long tmp[K];//�������飬�����ݴ浱ǰ�ڵ�Ľ�
vector<P> edge[N];//edge[u] ��u�����еı�
bool ok[N];//ok[u] u�Ƿ�Ϊ��Ҫ�ڵ�
int min(int a, int b) {
	return a < b ? a : b;
}
int x = 0;
void dfs(int u, int fa) {//u�ǵ�ǰ�ĵ�,fa�Ǹ��ڵ�
	dp[u][0] = 0;
	if (ok[u]) {//�Ƿ�Ϊ��Ҫ�ڵ�
		num[u] = 1;//num[u]��ʾ��uΪ���ڵ��������Ҫ�ڵ�ĸ��� 
		dp[u][1] = 0;//���u����Ҫ�ڵ�,��ô��ֻѡ��һ����ʱ�����Ž��Ϊ0����ѡ������������Ҫ�����κ�·��
	}
	for (int i = 0; i < edge[u].size();i++) {
		int v = edge[u][i].first;//v��
		int w = edge[u][i].second;//w:Ȩ��
		if (v == fa) {
			continue;//�������ڵ�ı�
		}
		dfs(v, u);
		int sum = min(k, num[u] + num[v]);
		int mn = min(k, num[u]);
		for (int p = 0; p <= sum; ++p) {
			tmp[p] = dp[u][p];//�����״̬
		}
		for (int p = 0; p <= mn; ++p) {//��������p������uΪ����������ȥ��vΪ��������ʣ�����Ҫ�ڵ���ѡp����
			for (int q = 0; p + q <= sum; ++q) {//��ǰ����q������vΪ���������е���Ҫ�ڵ�ڵ���ѡq����
				tmp[p + q] = min(tmp[p + q], dp[u][p] + dp[v][q] + 1ll * q*(k - q)*w);//�������״̬
				x++;
			}
		}
		for (int p = 0; p <= sum; ++p) {
			dp[u][p] = min(dp[u][p], tmp[p]);//����ǰ��Ľ����Ϊ���Ž�
		}
		num[u] += num[v];//��Ҫ�ڵ����
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