#include <iostream>
using namespace std;

struct Node{
	Node *left,*right;
	int data;
};
Node * createNode(int data){
	Node * node = new Node();
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return(node);
}

void preorder(Node * temp){
	if(temp!=NULL){
		cout<<" "<<temp->data;
		preorder(temp->left);
		preorder(temp->right);
	}
}

void inorder(Node * temp){
	if(temp!=NULL){
		inorder(temp->left);
		cout<<" "<<temp->data;
		inorder(temp->right);
	}
}

void postorder(Node * temp){
	if(temp!=NULL){
		postorder(temp->left);
		postorder(temp->right);
		cout<<" "<<temp->data;
	}
}

int main(){
	Node * root = createNode(9);
	root->left = createNode(5);
	root->right = createNode(17);
	root->right->right = createNode(34);
	root->right->right->left = createNode(28);
	root->right->right->right = createNode(91);
	root->right->right->right->left = createNode(37);
	cout<<"Pre-order";
	preorder(root);
	cout<<endl;
	cout<<"Inorder";
	inorder(root);
	cout<<endl;
	cout<<"Post-order";
	postorder(root);
	cout<<endl;
	return 0;
}
