#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <deque>
 
using namespace std;
/*
遍历二叉树
*/
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

//分层遍历, 从上到下
std::vector< std::vector<int> > traverseLevelTree( TreeNode* root) {
	std::vector< std::vector<int> > res;
	if (root == nullptr) {
		return res;
	}
	std::queue<TreeNode*> que;
	que.push(root);
	while(!que.empty()){
		int size = que.size();
		std::vector<int> data;
		for (int idx=0; idx < size; idx++) {
			auto* item =  que.front();
			if (item->left != nullptr) {
				que.push(item->left);
			}
			if (item->right != nullptr) {
				que.push(item->right);
			}
			data.push_back(item->val);
			que.pop();
		}
		res.emplace_back(data);
	}
	return res;
}

//分层遍历， 从下到上， 从左到右
std::vector< std::vector<int> > traverseLevelTree( TreeNode* root) {
	std::vector< std::vector<int> > res;
	if (root == nullptr) {
		return res;
	}
	std::queue<TreeNode*> que;
	que.push(root);
	while(!que.empty()) {
		int size = que.size();
		std::vector<int> data;
		for (int idx=0; idx < size; idx++) {
			auto* item = que.front();
			if (item->left != nullptr) {
				que.push(item->left);
			}
			if (item->right != nullptr) {
				que.push(item->right);
			}
			data.push_back(item->val);
			que.pop();
		}
		res.push_back(data);
	}
	return res;
}

//前序遍历
void preOrderTraverse(TreeNode* root, std::vector<int>& res) {
	if (root == nullptr) {
		return;
	}
	res.push_back(root->val);
	preOrderTraverse(root->left, res);
	preOrderTraverse(root->right, res);
	return;
}

//中序遍历
void inOrderTraverse(TreeNode* root, std::vector<int>& res) {
	if (root ==nullptr) {
		return;
	}
	inOrderTraverse(root->left, res);
	res.push_back(root->val);
	inOrderTraverse(root->right, res);
	return;
}

//后序遍历
void backOrderTraverse(TreeNode* root, std::vector<int>& res){
	if (root == nullptr) {
		return;
	}
	backOrderTraverse(root->left, res);
	backOrderTraverse(root->right, res);
	res.push_back(root->val);
	return;
}



