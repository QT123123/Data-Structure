//#include <iostream>
//using namespace std;
//#include <cstdlib>
#include "Queue.h"
typedef char BTDataType;
struct BinaryTreeNode {
	BTDataType val;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
};
BinaryTreeNode* treenodecreat(BTDataType x) {
	BinaryTreeNode* root = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
	root->val = x;
	root->left = NULL;
	root->right = NULL;
	return root;
}
void PrevOrder(BinaryTreeNode*root) {
	if (root == NULL) {
		return;
	}
	cout << root->val;
	PrevOrder(root->left);
	PrevOrder(root->right);
}
void InOrder(BinaryTreeNode* root) {
	if (root == NULL) {
		return;
	}
	PrevOrder(root->left);
	cout << root->val;
	PrevOrder(root->right);
}
void PostOrder(BinaryTreeNode* root) {
	if (root == NULL) {
		return;
	}
	PrevOrder(root->left);
	PrevOrder(root->right);
	cout << root->val;
}
int TreeSize(BinaryTreeNode* root) {
	if (root == NULL) {
		return 0;
	}
	return 1 + TreeSize(root->left) + TreeSize(root->right);
}
int TreeLeafSize(BinaryTreeNode* root) {
	if (root == NULL) {
		return 0;
	}
	if (root->left == NULL && root->right == NULL) {
		return 1;
	}
	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}
int BinaryTreeLevelKSize(BinaryTreeNode* root,int k) {
	if (root == NULL) {
		return 0;
	}
	if (k == 1) {
		return 1;
	}
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}
BinaryTreeNode* BinaryTreeFind(BinaryTreeNode* root, BTDataType x) {
	if (root == NULL) {
		return NULL;
	}
	if (root->val == x) {
		return root;
	}
	else {
		BinaryTreeNode* node = BinaryTreeFind(root->left, x);
		if (node) {
			return node;
		}
		node = BinaryTreeFind(root->right, x);
		return node;
	}
}
void BinaryTreeLevelOrder(BinaryTreeNode* root) {
	if (root == NULL) {
		return;
	}
	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);
	while (!QueueEmpty(&q)) {
		BinaryTreeNode* front = QueueFront(&q);
		QueuePop(&q);
		cout << front->val;
		if(front->left)
		QueuePush(&q, front->left);
		if(front->right)
		QueuePush(&q, front->right);
	}
	QueueDestroy(&q);
}
void DestoryTree(BinaryTreeNode* root) {
	if (root == NULL) {
		return;
	}
	DestoryTree(root->left);
	DestoryTree(root->right);
	free(root);
	root == NULL;
}

int BinaryTreeComplete(BinaryTreeNode* root) {
	if (root == NULL) {
		return 1;
	}
	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);
	while (!QueueEmpty(&q)) {
		BinaryTreeNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front == NULL) {
			break;
		}
		QueuePush(&q, front->left);
		QueuePush(&q, front->right);
	}
	while (!QueueEmpty(&q)) {
		BinaryTreeNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front != NULL) {
			QueueDestroy(&q);
			return 0;
		}
	}

	return 1;
}


int main() {
	BinaryTreeNode* A = treenodecreat('A');
	BinaryTreeNode* B = treenodecreat('B');
	BinaryTreeNode* C = treenodecreat('C');
	BinaryTreeNode* D = treenodecreat('D');
	BinaryTreeNode* E = treenodecreat('E');
	BinaryTreeNode* F = treenodecreat('F');
	A->left = B;
	A->right = C;
	B->left = D;
	B->right = E;
	C->right = F;
	//cout << BinaryTreeLevelKSize(A, 2);
	//BinaryTreeLevelOrder(A);
	cout << BinaryTreeComplete(A);
	return 0;
}