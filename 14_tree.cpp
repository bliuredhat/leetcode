/*
 * @Author: bliuredhat@gmail.com
 * @Date: 2025-04-09 15:46:31
 * @LastEditors: bliuredhat@gmail.com
 * @LastEditTime: 2025-04-10 17:56:44
 * @Description:
 */
#include <vector>
#include <stack>
#include <queue>
#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *next) : val(x), left(nullptr), right(nullptr) {}
};
typedef TreeNode* TreeNodePtr;
using namespace std;

//中序遍历
void midTraversal(TreeNodePtr root, std::vector<int>& res) {
    if (root == nullptr) {
        return;
    }
    if (root->left != nullptr) {
       midTraversal(root->left, res);  
    }
    res.push_back(root->val);
    if (root->right != nullptr) {
        midTraversal(root->right, res);
    } 
}

//中序遍历，非递归。
void midTraversalV2(TreeNodePtr root, std::vector<int>& res) {
    if (root == nullptr) {
        return ;
    }
    std::stack<TreeNodePtr> st;
    TreeNodePtr curr = root;
    while(!st.empty() || curr != nullptr) {
        while (curr != nullptr) {
            st.push(curr);
            curr = curr->left;
        }
        if (!st.empty()) {
            curr = st.top();
            res.push_back(curr->val);
            st.pop();
            curr = curr->right; 
        }
    }
}

//前序遍历
void preTraversal(TreeNodePtr root, std::vector<int>& res) {
    if (root == nullptr) {
        return;
    }
    res.push_back(root->val);
    if (root->left != nullptr) {
        preTraversal(root->left, res);
    }
    if (root->right != nullptr) {
        preTraversal(root->right, res);
    }
}
//前序遍历: 非递归
void preTraversalV2(TreeNodePtr root, std::vector<int>& res) {
    if (root == nullptr) {
        return;
    }
    std::stack<TreeNodePtr> st;
    auto* curr = root;
    st.push(curr);
    while(!st.empty()) {
        curr = st.top();
        st.pop();
        if (curr != nullptr) {
            res.push_back(curr->val);
        }
        if (curr->right != nullptr) {
            st.push(curr->right);
        }
        if (curr->left != nullptr) {
            st.push(curr->left);
        }
    }
} 

//后续遍历
void postTraversal(TreeNodePtr root, std::vector<int>& res){
    if (root == nullptr) {
        return;
    }
    if (root->left != nullptr) {
        postTraversal(root->left, res);
    }
    if (root->right != nullptr) {
        postTraversal(root->right, res);
    }
    res.push_back(root->val);
}
//后序遍历：非递归
void postTraversalV2(TreeNodePtr root, std::vector<int>& res) {
    if (root == nullptr) {
        return;
    }
    auto* curr = root;
    std::stack<pair<TreeNodePtr, bool>> st;
    st.push(make_pair(root, false));
    bool isVisited = false;
    while(!st.empty() ) {
        root = st.top().first;
        isVisited = st.top().second;
        st.pop();
        if (root == nullptr) {
            continue;
        }
        if (isVisited) {
            res.push_back(root->val);
        } else {
            st.push(make_pair(root, true));
            st.push(make_pair(root->right, false));
            st.push(make_pair(root->left, false));
        }
    }
}

int main() {
    /* 构建测试树：
          1
         / \
        2   3
       / \
      4   5
    */
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new  TreeNode(4);
    root->left->right = new TreeNode(5);
    std::vector<int> vec;
    //postTraversalV2(root, vec); //4,5,2,3,1
    //postTraversal(root, vec);
    //preTraversalV2(root, vec); //1,2,4,5,3
    midTraversalV2(root, vec); //4,2,5,1,3
    for (auto val: vec) {
        std::cout << val << ","; 
    }
    return 1;
}