#include<iostream>
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
class Node{
    public:
    int data;
    Node*left;
    Node*right;
    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};
Node* buildTree(){
    int d;cin>>d;if(d == -1){return NULL;}
    Node *root = new Node(d);root->left = buildTree();root->right = buildTree();return root; 
}
void topview(Node* root,int x,unordered_map<int,int> &isv)
{
	if(root == NULL){
		return;
	}
	if(isv.find(x) == isv.end()){
		isv[x] = (int)root->data;
	}
	topview(root->left,x-1,isv);
	topview(root->right,x+1,isv);
}
void bfs(Node *root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* f = q.front();
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
}
struct Node* insertValue(struct Node* root, int value, 
                         queue<Node *>& q) 
{ 
    Node* node = new Node(value); 
    if (root == NULL) 
        root = node; 
    else if (q.front()->left == NULL) 
        q.front()->left = node; 
    else { 
        q.front()->right = node; 
        q.pop(); 
    } 
    q.push(node); 
    return root; 
} 
Node* createTree(vector<int> v) 
{ 
    Node* root = NULL; 
    queue<Node*> q; 
    for (auto i:v) 
      root = insertValue(root, i, q); 
    return root; 
} 
int main() {
	int d;cin>>d;
	vector<int>v;
	while(d != -1){
		v.push_back(d);
		cin>>d;
	}
	Node* root = createTree(v);
	unordered_map<int,int> isv;
	topview(root,0,isv);
	vector<int>t;
	for(auto x:isv){
		t.push_back(x.first);
	}
	sort(t.begin(),t.end());
	for(auto i:t){
		cout<<isv[i]<<" ";
	}
	return 0;
}