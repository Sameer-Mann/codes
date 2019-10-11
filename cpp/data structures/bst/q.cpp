#include <iostream>
using namespace std;
class node{
public:
	int data;
	node* left;
	node* right;
	node(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};
node* insertInBST(node *root,int data){
	if(root == NULL){
		return new node(data);
	}
	if(data <= root->data){
		root->left = insertInBST(root->left,data);
	}else{
		root->right = insertInBST(root->right,data);
	}
	return root;
}
void printPreorder(node *root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	printPreorder(root->left);
	printPreorder(root->right);
}
int main(){
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		int nums[n];
		node* root = NULL;
		while(n--){
			int temp;cin>>temp;
			root = insertInBST(root,temp);
		}
		int rangeLeft;int rangeRight;
		cin>>rangeLeft>>rangeRight;
		cout<<"# Preorder : ";
		printPreorder(root);cout<<endl;
	}
	return 0;
}