#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <cassert>
#include <list>
#include <queue>
#include <limits>
#include <unordered_set>
#include <sstream>
#include <map>
#include <iterator>
#include <set>
#include <stack>

using namespace::std;

struct BinaryTreeNode
{
	int data;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
	BinaryTreeNode *parent;
	BinaryTreeNode() :data(0), left(nullptr), right(nullptr), parent(nullptr){}
	BinaryTreeNode(int value) :data(value), left(nullptr), right(nullptr), parent(nullptr){}
};

BinaryTreeNode* createNode(int value)
{
	BinaryTreeNode *newNode = new BinaryTreeNode(value);
	return newNode;
}

BinaryTreeNode* connectNode(BinaryTreeNode *parent,
	BinaryTreeNode *leftChild, BinaryTreeNode *rightChild)
{
	parent->left = leftChild;
	parent->right = rightChild;

	if (leftChild != nullptr)
		leftChild->parent = parent;
	if (rightChild != nullptr)
		rightChild->parent = parent;
	return parent;
}

BinaryTreeNode* getNext(BinaryTreeNode *pNode)
{
	if (pNode == nullptr)
		return nullptr;
	BinaryTreeNode *pNext = nullptr;
	if (pNode->right != nullptr) {
		BinaryTreeNode *rightNode = pNode->right;
		while (rightNode->left != nullptr)
			rightNode = rightNode->left;
		pNext = rightNode;
	}
	else if (pNode->parent != nullptr) {
		BinaryTreeNode *pParent = pNode->parent;
		BinaryTreeNode *curNode = pNode;;
		while (curNode == pParent->right
			&& pParent != nullptr) {
			curNode = pParent;
			pParent = pParent->parent;
		}
		pNext = pParent;
	}

	return pNext;
}


struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

	}
};
class Solution {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		TreeLinkNode *pRoot = pNode;
		while (pRoot->next != nullptr)
			pRoot = pRoot->next;
		vector<TreeLinkNode*> vecTree;
		stack<TreeLinkNode*> treeStack;
		TreeLinkNode* currentNode = pRoot;

		while (!treeStack.empty() || currentNode != nullptr) {
			while (currentNode != nullptr) {
				treeStack.push(currentNode);
				currentNode = currentNode->left;
			}

			currentNode = treeStack.top();
			treeStack.pop();
			vecTree.emplace_back(currentNode);
			currentNode = currentNode->right;
		}
		for (int i = 0; i < vecTree.size(); ++i) {
			if (vecTree[i]->val == pNode->val && i < vecTree.size() - 1)
				return vecTree[i + 1];
			if (vecTree[i]->val == pNode->val && i == vecTree.size() - 1)
				return nullptr;
		}
		return nullptr;
	}
};

void test1()
{
	BinaryTreeNode *p10 = new BinaryTreeNode(10);
	BinaryTreeNode *p6 = new BinaryTreeNode(6);
	BinaryTreeNode *p3 = new BinaryTreeNode(3);
	BinaryTreeNode *p7 = new BinaryTreeNode(7);
	BinaryTreeNode *p14 = new BinaryTreeNode(14);
	BinaryTreeNode *p12 = new BinaryTreeNode(12);
	BinaryTreeNode *p15 = new BinaryTreeNode(15);

	BinaryTreeNode *p2 = new BinaryTreeNode(2);
	BinaryTreeNode *p1 = new BinaryTreeNode(1);

	connectNode(p10, p6, p14);
	connectNode(p6, p3, p7);
	connectNode(p14, p12, p15);
	connectNode(p3, p2, nullptr);
	connectNode(p2, p1, nullptr);

	cout << getNext(p7)->data << endl;
	cout << getNext(p12)->data << endl;
	cout << getNext(p10)->data << endl;
}

int main(int argc, char* argv[])
{
	test1();

	return 0;
}


