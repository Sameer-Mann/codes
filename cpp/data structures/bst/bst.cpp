#include<iostream>
#include<queue>
#include<climits>
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
void bfs(node *root){
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		node* f = q.front();
		if(f==NULL){
			cout<<endl;
			q.pop();
			if(!q.empty()){
	    		q.push(NULL);
			}
		}
		else{
			cout<<f->data<<",";
			q.pop();
			if(f->left){
	    		q.push(f->left);
			}
			if(f->right){
	    		q.push(f->right);
			}
		}
	}
	return;
}
// inorder print of a bst is always sorted
void printInorder(node *root){
	if(root == NULL){
		return;
	}
	printInorder(root->left);
	cout<<root->data<<",";
	printInorder(root->right);
}
node* build(){
	// will read a list of numbers and stop at -1 and adding each in bst
	int d;cin>>d;
	node*root =  NULL;
	while(d!=-1){
		root = insertInBST(root,d);
		cin>>d;
	}
	return root;
}
node* search(node *root,int n){
	node* ans = NULL;
	if(root == NULL){
		return NULL;
	}
	if(root->data == n){
		return root;
	}
	if(n <= root->data){
		ans = search(root->left,n);
	} else {
		ans = search(root->right,n);
	}
	return ans;
}
node* deleteInBSt(node*root, int data){
	if(root == NULL){
		return NULL;
	}
	else if(data<root->data){
		root->left = deleteInBSt(root->left,data);
		return root;
	}
	else if(data == root->data){
		//Found the node to delete there are 3 cases
		//1. node has zero children
		if(root->left==NULL&&root->right==NULL){
			delete root;
			return NULL;
		}
		//2.has 1child
		if(root->left!=NULL && root->right==NULL){
			node*temp = root->left;
			delete root;
			return temp;
		}
		if(root->right!=NULL && root->left==NULL){
			node*temp = root->right;
			delete root;
			return temp;
		}
		//3. node having two children in this we will find the inorder succesor and replace the current node with it
		// in short here i am finding the smallest element in the right subtree
		node*replace = root->right;
		while(replace->left!=NULL){
			replace = replace->left;
		}
		root->data = replace->data;
		root->right = deleteInBSt(root->right,replace->data);
		return root;
	}
	else{
		root->right = deleteInBSt(root->right,data);
	}
	return root;
}
bool checkIsBST(node*root,int min = INT_MIN,int max = INT_MAX){
	if(root == NULL){
		return true;
	}
	if(root->data >= min && root->data <= max && checkIsBST(root->right,root->data,max) && checkIsBST(root->left,min,root->data)){
		return true;
	}
	return false;
}
// it is called a pair class
class LinkedList
{
public:
	node* head;
	node* tail;
	
};
LinkedList flattenToLinkedList(node *root){
	LinkedList l;
	// it is the case when the tree is empty
	if(root == NULL){
		l.head= l.tail = NULL;
		return l;
	}
	if(root->left == NULL && root->right == NULL){
		l.head = l.tail = root;
		return l;
	}
	if(root->left!=NULL && root->right == NULL){
		LinkedList leftll = flattenToLinkedList(root->left);
		leftll.tail->right = root;
		l.head = leftll.head;
		l.tail = root;
		return l;
	}
	if(root->left == NULL && root->right != NULL){
		LinkedList rightll = flattenToLinkedList(root->right);
		root->right = rightll.head;
		l.head = root;
		l.tail = rightll.tail;
		return l;
	}
	else{
		LinkedList leftll = flattenToLinkedList(root->left);
		LinkedList rightll = flattenToLinkedList(root->right);
		leftll.tail->right = root;
		root->right = rightll.head;

		l.head = leftll.head;
		l.tail = rightll.tail;
		return l;
	}
}
node* sortedArrayToBST(int arr[],int start, int end)  
{  
    if (start > end)  
    return NULL;  
    int mid = (start + end)/2;  
    node *root = new node(arr[mid]);  
    root->left = sortedArrayToBST(arr, start,mid - 1);  
    root->right = sortedArrayToBST(arr, mid + 1, end);
    return root;
}
node *LevelOrder(Node *root , int data)  
{ 
     if(root==NULL){     
        root = new node(data); 
        return root; 
     } 
     if(data <= root->data){
        root->left = LevelOrder(root->left, data); 
     } else {
        root->right = LevelOrder(root->right, data); 
     }
     return root;      
} 
int main(){
	node* root = build();
	bfs(root);
	printInorder(root);cout<<endl;
	// int s;cin>>s;root = deleteInBSt(root,s);printInorder(root);cout<<endl;bfs(root);
	LinkedList l = flattenToLinkedList(root);
	node*temp = l.head;
	while(temp != NULL){
		cout<<temp->data<<"-->";
		temp = temp->right;
	}
	cout<<endl;
	return 0;
}