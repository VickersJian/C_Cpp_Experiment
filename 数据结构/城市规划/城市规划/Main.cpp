//#include<iostream>
//#include<vector>
//#include<stdlib.h>
//#include<queue>
//using namespace std;
//const int N = 5e4 + 10;
//const int K = 1e2 + 10;
//long long dp[N][K];//dp[u][p]表示在u这棵子树(含u)里选了p个点的最小代价
//long long tmp[K];
//bool ok[N];//ok[u] u是否为重要节点
//class Tree {
//public:
//	struct _Edge {//定义边的结构体，用于构建树
//		int point1;
//		int point2;
//		int weight;
//		_Edge(int point1, int point2, int weight) {
//			this->point1 = point1;
//			this->point2 = point2;
//			this->weight = weight;
//		}
//		bool operator==(const _Edge& a) {
//			if (point1 == a.point1 && point2 == a.point2 && weight == a.weight) {
//				return true;
//			}
//			return false;
//		}
//	};
//	struct TreeNode;
//	struct DirectedEdge {//树节点的边，附带权重
//		TreeNode* point;
//		int weight;
//		DirectedEdge(TreeNode* point, int weight) {
//			this->point = point;
//			this->weight = weight;
//		}
//		void deleteEdge(TreeNode* point1, TreeNode* point2) {
//			if (point1 != nullptr) {
//
//			}
//		}
//		bool operator==(const DirectedEdge& a) {
//			if (point == a.point && weight == a.weight) {
//				return true;
//			}
//			return false;
//		}
//	};
//	struct UndirectedEdges {
//		TreeNode* point1;
//		TreeNode* point2;
//		int weight;
//		UndirectedEdges(TreeNode* point1, TreeNode* point2, int weight) {
//			this->point1 = point1;
//			this->point2 = point2;
//			this->weight = weight;
//		}
//		bool operator==(const UndirectedEdges& a) {
//			if (point1 == a.point1 && point2 == a.point2) {
//				return true;
//			}
//			return false;
//		}
//	};
//	struct TreeNode {//树的节点
//		int name;
//		int num=0;//以该节点为根的子树的重要节点数
//		vector<DirectedEdge> connectedList;
//		TreeNode(int name) {
//			this->name = name;
//		}
//		void addConnected(TreeNode* point,int weight) {
//			connectedList.push_back(DirectedEdge(point,weight));
//		}
//	};
//
//
//	int totalNumber;//公交站总数
//	int importantNumber;//重要的公交站总数
//	int selectNumber;//需要选择的公交站总数
//	vector<int> importantPoints;//所有重要节点的编号,构建完后销毁
//	vector<_Edge> _allEdge;//所有的边，用于构建树，构建完树后被销毁
//	vector<_Edge> importantTreeEdge;
//	vector<TreeNode*> allPointsNode;//所有节点的地址
//	vector<TreeNode*> allimportantPointsNode;//所有重要节点的地址
//	vector<UndirectedEdges> allEdge;//所有无向边
//
//	TreeNode* startPoint;//树建立的起始点
//
//	void init() {//初始化
//		cin >> totalNumber >> importantNumber >> selectNumber;
//		for (int i = 0; i < importantNumber; i++) {
//			int a;
//			cin >> a;
//			importantPoints.push_back(a);
//			ok[a] = true;
//		}
//		for (int i = 0; i < totalNumber - 1; i++) {
//			int x, y, weight;
//			cin >> x >> y >> weight;
//			_allEdge.push_back(_Edge(x, y, weight));
//		}
//		
//		/*int pointx = importantPoints.front();
//		importantPoints.erase(importantPoints.begin());
//		queue<_Edge> r;
//		while (!importantPoints.empty()) {
//			for (vector<_Edge>::iterator it = _allEdge.begin(); it != _allEdge.end();) {
//				if (pointx == (*it).point1 || pointx == (*it).point2) {
//					r.push(*it);
//					it = _allEdge.erase(it);
//				}
//				else {
//					it++;
//				}
//			}
//			while (!r.empty()) {
//				_Edge temp = r.front();
//				r.pop();
//				vector<int>::iterator it;
//				int x;
//				if (pointx != temp.point1) {
//					it = find(importantPoints.begin(), importantPoints.end(), temp.point1);
//					x = temp.point1;
//				}
//				else {
//					it = find(importantPoints.begin(), importantPoints.end(), temp.point2);
//					x = temp.point2;
//				}
//				if (it != importantPoints.end()) {
//					importantTreeEdge.push_back(temp);
//				}
//				else {
//					for (vector<_Edge>::iterator it = _allEdge.begin(); it != _allEdge.end();) {
//						if (x == (*it).point1) {
//							(*it).point1 = pointx;
//							(*it).weight = (*it).weight + temp.weight;
//							r.push(*it);
//							it = _allEdge.erase(it);
//						}
//						else if (x == (*it).point2) {
//							(*it).point2 = pointx;
//							(*it).weight = (*it).weight + temp.weight;
//							r.push(*it);
//							it = _allEdge.erase(it);
//						}
//						else {
//							it++;
//						}
//					}
//				}
//			}
//			pointx = importantPoints.front();
//			importantPoints.erase(importantPoints.begin());
//		}*/
//		Creat(_allEdge);
//	}
//	void Creat(vector<_Edge>& _allEdge) {//创建树
//		queue<TreeNode*> creatChildList;
//		startPoint = new TreeNode(_allEdge.front().point1);
//		creatChildList.push(startPoint);
//		while (!creatChildList.empty()) {
//			TreeNode* temp = creatChildList.front();
//			creatChildList.pop();
//			allPointsNode.push_back(temp);
//			vector<int>::iterator it = find(importantPoints.begin(), importantPoints.end(), temp->name);
//			if (it != importantPoints.end()) {
//				allimportantPointsNode.push_back(temp);
//				importantPoints.erase(it);
//			}
//			vector<_Edge> a = findPointEdge(_allEdge,temp->name);
//			for (int i = 0; i < a.size(); i++) {
//				TreeNode* connectedPoint = new TreeNode((a[i].point1 != temp->name ? a[i].point1 : a[i].point2));
//				connectedPoint->addConnected(temp, a[i].weight);
//				temp->addConnected(connectedPoint, a[i].weight);
//				allEdge.push_back(UndirectedEdges(temp, connectedPoint, a[i].weight));
//				creatChildList.push(connectedPoint);
//			}
//			subSet(_allEdge, a);
//			a.~vector();
//		}
//		//importantPoints.~vector();
//		//_allEdge.~vector();//销毁容器
//	}
//	vector<_Edge> findPointEdge(vector<_Edge>& _allEdge,int point) {//找到由该点关联的边
//		vector<_Edge> set;
//		for (size_t i = 0; i < _allEdge.size(); i++) {
//			if (point == _allEdge[i].point1 || point == _allEdge[i].point2)
//				set.push_back(_allEdge[i]);
//		}
//		return set;
//	}
//	void subSet(vector<_Edge>& parent, vector<_Edge>& subset) {//从parent中去除掉subset中的元素（subset是parent的子集）
//		for (int i = 0; i < subset.size(); i++) {
//			vector<_Edge>::iterator it;
//			it = find(parent.begin(), parent.end(), subset[i]);
//			parent.erase(it);
//		}
//	}
//
//	Tree() {
//		init();
//	}
//
//
//
//	
//};
//
//
//void dfs(Tree t,Tree::TreeNode* u, Tree::TreeNode* fa) {//u是当前的点,fa是父节点
//	dp[u->name][0] = 0;
//	if (ok[u->name]) {//是否为重要节点
//		u->num = 1;;//num[u]表示以u为根节点的树中重要节点的个数 
//		dp[u->name][1] = 0;//如果u是重要节点,那么当只选择一个点时，最优结果为0，即选择了自身，不需要经过任何路径
//	}
//	for (int i = 0; i < u->connectedList.size(); i++) {
//		Tree::TreeNode* v = u->connectedList[i].point;//v点
//		int w = u->connectedList[i].weight;//w:权重
//		if (v == fa) {
//			continue;//跳过父节点的边
//		}
//		dfs(t,v, u);
//		int sum = min(t.selectNumber, u->num + v->num);
//		int mn = min(t.selectNumber, u->num);
//		for (int p = 0; p <= sum; ++p) {
//			tmp[p] = dp[u->name][p];
//		}
//		for (int p = 0; p <= mn; ++p) {//其余子树p个
//			for (int q = 0; p + q <= sum; ++q) {//当前子树q个
//				tmp[p + q] = min(tmp[p + q], dp[u->name][p] + dp[v->name][q] + 1ll * q*(t.totalNumber - q)*w);
//			}
//		}
//		for (int p = 0; p <= sum; ++p) {
//			dp[u->name][p] = min(dp[u->name][p], tmp[p]);
//			//printf("dp[%d][%d]:%lld\n", u, p, dp[u][p]);
//		}
//		u->num += v->num;
//		//cout << u->num;
//	}
//}
//int main() {
//	memset(dp, 0x3f3f3f3f3f3f3f3fll, sizeof dp);
//	Tree tree;
//	dfs(tree, tree.startPoint, nullptr);
//	cout << dp[tree.startPoint->name][tree.selectNumber];
//	for (int i = 1; i <= tree.totalNumber; ++i)
//		for (int j = 1; j <= tree.selectNumber; ++j)
//			printf("dp[%d][%d]:%lld\n", i, j, dp[i][j]);
//	//cout << dp[1][k] << endl;
//	system("pause");
//	return 0;
//}
//
//
///*
//5 3 2
//1 3 5
//1 2 4
//1 3 5
//1 4 3
//4 5 1
//
//9 3 2
//1 3 5
//1 7 1
//1 3 1
//1 4 1
//1 2 1
//1 9 1
//2 8 1
//3 6 1
//4 5 1
//
//*/