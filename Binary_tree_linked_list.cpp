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
		cout<<" "<<temp->data;
		postorder(temp->right);
	}
}

int main(){
	Node * root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->left->left = createNode(4);
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
