#pragma once
#include <stack>
#include <vector>
#include <queue>
#include <deque>
#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BinaryTree
{
public:
	BinaryTree(TreeNode *_head);
	~BinaryTree();
	vector<int> preorderTraversal();
    
    // From segmentfault blog
    TreeNode* LCA(TreeNode *root, TreeNode *node1, TreeNode *node2); // 1
    int DistanceNodes(TreeNode *root, TreeNode * target1, TreeNode * target2); // 1.1
    bool findAllAncestors(TreeNode * root, TreeNode * target); // 2
    int largestWidth(TreeNode *root); // 5
    bool IsCBT(TreeNode *root); // Complete Binary Tree // 3
    int longestSumPath(TreeNode *root); // 6 // not implemented
    vector<int> postFromPreIn(vector<int> preVec, vector<int> inVec); // 4 并重建二叉树 TreeNode *binaryFromPreIn
    
    // From GitHub
    bool isSubtree(TreeNode* p1, TreeNode* p2); // 7
    bool sameStruct(TreeNode* s, TreeNode* t);
    
private:
	TreeNode *head;
	vector<int> preorderTraversal(TreeNode* root);
    int findLevel(TreeNode *from, TreeNode *to);
    void postFromPreIn(vector<int> &preVec, vector<int> &inVec, vector<int> &postVec);
};
