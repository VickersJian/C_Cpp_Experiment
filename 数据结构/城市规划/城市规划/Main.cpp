//#include<iostream>
//#include<vector>
//#include<stdlib.h>
//#include<queue>
//using namespace std;
//const int N = 5e4 + 10;
//const int K = 1e2 + 10;
//long long dp[N][K];//dp[u][p]��ʾ��u�������(��u)��ѡ��p�������С����
//long long tmp[K];
//bool ok[N];//ok[u] u�Ƿ�Ϊ��Ҫ�ڵ�
//class Tree {
//public:
//	struct _Edge {//����ߵĽṹ�壬���ڹ�����
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
//	struct DirectedEdge {//���ڵ�ıߣ�����Ȩ��
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
//	struct TreeNode {//���Ľڵ�
//		int name;
//		int num=0;//�Ըýڵ�Ϊ������������Ҫ�ڵ���
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
//	int totalNumber;//����վ����
//	int importantNumber;//��Ҫ�Ĺ���վ����
//	int selectNumber;//��Ҫѡ��Ĺ���վ����
//	vector<int> importantPoints;//������Ҫ�ڵ�ı��,�����������
//	vector<_Edge> _allEdge;//���еıߣ����ڹ���������������������
//	vector<_Edge> importantTreeEdge;
//	vector<TreeNode*> allPointsNode;//���нڵ�ĵ�ַ
//	vector<TreeNode*> allimportantPointsNode;//������Ҫ�ڵ�ĵ�ַ
//	vector<UndirectedEdges> allEdge;//���������
//
//	TreeNode* startPoint;//����������ʼ��
//
//	void init() {//��ʼ��
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
//	void Creat(vector<_Edge>& _allEdge) {//������
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
//		//_allEdge.~vector();//��������
//	}
//	vector<_Edge> findPointEdge(vector<_Edge>& _allEdge,int point) {//�ҵ��ɸõ�����ı�
//		vector<_Edge> set;
//		for (size_t i = 0; i < _allEdge.size(); i++) {
//			if (point == _allEdge[i].point1 || point == _allEdge[i].point2)
//				set.push_back(_allEdge[i]);
//		}
//		return set;
//	}
//	void subSet(vector<_Edge>& parent, vector<_Edge>& subset) {//��parent��ȥ����subset�е�Ԫ�أ�subset��parent���Ӽ���
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
//void dfs(Tree t,Tree::TreeNode* u, Tree::TreeNode* fa) {//u�ǵ�ǰ�ĵ�,fa�Ǹ��ڵ�
//	dp[u->name][0] = 0;
//	if (ok[u->name]) {//�Ƿ�Ϊ��Ҫ�ڵ�
//		u->num = 1;;//num[u]��ʾ��uΪ���ڵ��������Ҫ�ڵ�ĸ��� 
//		dp[u->name][1] = 0;//���u����Ҫ�ڵ�,��ô��ֻѡ��һ����ʱ�����Ž��Ϊ0����ѡ������������Ҫ�����κ�·��
//	}
//	for (int i = 0; i < u->connectedList.size(); i++) {
//		Tree::TreeNode* v = u->connectedList[i].point;//v��
//		int w = u->connectedList[i].weight;//w:Ȩ��
//		if (v == fa) {
//			continue;//�������ڵ�ı�
//		}
//		dfs(t,v, u);
//		int sum = min(t.selectNumber, u->num + v->num);
//		int mn = min(t.selectNumber, u->num);
//		for (int p = 0; p <= sum; ++p) {
//			tmp[p] = dp[u->name][p];
//		}
//		for (int p = 0; p <= mn; ++p) {//��������p��
//			for (int q = 0; p + q <= sum; ++q) {//��ǰ����q��
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