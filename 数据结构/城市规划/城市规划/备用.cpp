//void Creat() {//´´½¨Ê÷
//	queue<TreeNode*> creatChildList;
//	startPoint = new TreeNode(_allEdge.front().point1);
//	creatChildList.push(startPoint);
//	while (!creatChildList.empty()) {
//		TreeNode* temp = creatChildList.front();
//		creatChildList.pop();
//		allPointsNode.push_back(temp);
//		vector<int>::iterator it = find(importantPoints.begin(), importantPoints.end(), temp->name);
//		if (it != importantPoints.end()) {
//			allimportantPointsNode.push_back(temp);
//			importantPoints.erase(it);
//		}
//		vector<_Edge> a = findPointEdge(temp->name);
//		for (int i = 0; i < a.size(); i++) {
//			TreeNode* connectedPoint = new TreeNode((a[i].point1 != temp->name ? a[i].point1 : a[i].point2));
//			connectedPoint->addConnected(temp, a[i].weight);
//			temp->addConnected(connectedPoint, a[i].weight);
//			allEdge.push_back(UndirectedEdges(temp, connectedPoint, a[i].weight));
//			creatChildList.push(connectedPoint);
//		}
//		subSet(_allEdge, a);
//		a.~vector();
//	}
//	importantPoints.~vector();
//	_allEdge.~vector();//Ïú»ÙÈÝÆ÷
//}
//
//
