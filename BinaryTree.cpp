#include "BinaryTree.h"


BinaryTree::BinaryTree(TreeNode *_head)
{
	head = _head;
}


BinaryTree::~BinaryTree()
{
}

vector<int> BinaryTree::preorderTraversal() {
	vector<int> result = preorderTraversal(head);
	return result;
}

vector<int> BinaryTree::preorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode *> s;
    TreeNode *node = root;
    
    while (node != nullptr || !s.empty()) {
        while (node != nullptr) { // bug: while but not if
            s.push(node);
            res.push_back(node->val);
            node = node->left;
        }
        /*s.pop();
        node = s.top();
        if (node->right != nullptr)
            node = node->right;*/
        
        node = s.top();
        s.pop();
        node = node->right;
    }
    
    return res;
}

TreeNode* BinaryTree::LCA(TreeNode *root, TreeNode *node1, TreeNode *node2)
{   // 1. 搞清楚每层递归传递什么上去
    // 2. 如何对于下层return的结果，进行+/-/&&/||等操作再return上去
    if (root == nullptr) return nullptr;
    if (root == node1 || root == node2) return root;
    TreeNode *left = LCA(root->left, node1, node2);
    TreeNode *right = LCA(root->right, node1, node2); // bug
    
    if (left && right) return root;
    
    return left ? left : right;
}

int BinaryTree::findLevel(TreeNode *from, TreeNode *to)
{
    if (from == nullptr) return -1;
    if (from == to) return 0;
    int l = findLevel(from->left, to);
    int r = findLevel(from->left, to);
    
    if (l == -1 && r == -1) return -1;
    else return max(l, r) + 1; // bug: 如果不+1返回上层的数值都会是一样的了
}

int BinaryTree::DistanceNodes(TreeNode *root, TreeNode * target1, TreeNode * target2)
{
    TreeNode *lcaNode = LCA(root, target1, target2);
    return findLevel(lcaNode, target1) + findLevel(lcaNode, target2); // fix
}

bool BinaryTree::findAllAncestors(TreeNode * root, TreeNode * target)
{
    if (root == target) return true;
    if (root == nullptr) return false;
    
    bool l = findAllAncestors(root->left, target);
    bool r = findAllAncestors(root->right, target);
    
    if (l || r) {
        cout << root->val << " ";
        return true;
    }
    
    return false;
}

bool BinaryTree::IsCBT(TreeNode *root)
{
    bool flag = false;
    queue<TreeNode *> q;
    TreeNode *node = root;
    q.push(node);
    
    while (!q.empty()) {
        node = q.front();
        if (flag) {
            if (node->left || node->right)
                return false;
        }
        
        if (node->left && node->right) {
            // bug: 搞清楚每个if...else中需要发生的事情
            q.push(node->left);
            q.push(node->right);
        }
        else if (node->right)
            return false;
        else if (node->left) {
            flag = true;
            q.push(node->left);
        }
        else {
            flag = true;
        }
        
        q.pop();
    }
    
    return true;
}

int BinaryTree::largestWidth(TreeNode *root)
{
    // bug 1: only count num of node
    // bug : use unsigned int
    if (root == nullptr) return 0;
    deque<pair<TreeNode*, unsigned int>> q;
    TreeNode *node = root;
    int cur_w = 1;
    int res = 1;
    
    q.push_back({root, 0});
    
    while (!q.empty()) {
        int width = q.back().second - q.front().second + 1;
        res = max(res, width);
        cur_w = q.size();
        
        for (int i = 0; i < cur_w; i++) {
            unsigned int label = q.front().second;
            node = q.front().first;
            
            if (node->left)
                q.push_back({node->left, label * 2});
        
            if (node->right)
                q.push_back({node->right, label * 2 + 1});
            
            q.pop_front();
        }
    }
    
    return res;
}

void BinaryTree::postFromPreIn(vector<int> &preVec, vector<int> &inVec, vector<int> &postVec)
{
    //前序：[1 2 4 7 3 5 8 9 6]
    //中序：[4 7 2 1 8 5 9 3 6]
    //后序：[7 4 2 8 9 5 6 3 1]
    if (preVec.size() == 0) return;
    if (preVec.size() == 1) {
        postVec.push_back(preVec[0]);
        return;
    }
    
    int pivot = preVec[0];
    int i = 0;
    for (; i < inVec.size(); i++) {
        if (inVec[i] == pivot)
            break;
    }
    vector<int> leftPre(preVec.begin()+1, preVec.begin()+i+1);
    vector<int> leftIn(inVec.begin(), inVec.begin()+i);
    vector<int> rightPre(preVec.begin()+i+1, preVec.end());
    vector<int> rightIn(inVec.begin()+i+1, inVec.end()); // bug: 游标错误
    
    postFromPreIn(leftPre, leftIn, postVec);
    postFromPreIn(rightPre, rightIn, postVec);
    
    postVec.push_back(pivot);
}

vector<int> BinaryTree::postFromPreIn(vector<int> preVec, vector<int> inVec)
{
    vector<int> postVec;
    postFromPreIn(preVec, inVec, postVec);
    return postVec;
}

bool BinaryTree::sameStruct(TreeNode* s, TreeNode* t) {
    if (!s && !t) return true;
    if (!s || !t) return false;
    if (s->val != t->val) return false;
    
    return sameStruct(s->left, t->left) && sameStruct(s->right, t->right);
    // bug: 递归的时候实参用错
}

bool BinaryTree::isSubtree(TreeNode* s, TreeNode* t) {
    if (!s) return false;
    if (sameStruct(s,t)) return true; // bug: 没有想到该这样用
    
    return isSubtree(s->left, t) || isSubtree(s->right, t);
}
