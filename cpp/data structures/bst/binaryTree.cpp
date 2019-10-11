#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;
class node{
    public:
    int data;
    node*left;
    node*right;
    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};
// 22738
// 1 2 3 4 8 5 6 7
// 3 2 8 4 1 6 7 5
/*there are four types of order namely
preorder call's order is: root left right
inorder call's order is: left root right 
postorder call's order is: left right root
levelorder
this order is called preorder tree build
3 4 -1 6 -1 -1 5 1 -1 -1 -1 this is how the tree will
be given in the input 
height balanced tree means that at every node the difference between the height of left and right child is less than or equal to one
If we are given an preorder and an inorder traversal for a tree there exists a unique tree otherwise if we have only one of them then there can be multiple trees possible
same is with post + inorder */
node* buildTree(){
    int d;cin>>d;if(d == -1){return NULL;}
    node *root = new node(d);root->left = buildTree();root->right = buildTree();return root; 
}
void print(node *root){
    if(root == NULL){return;}
    cout<<root->data<<" ";print(root->left);print(root->right);
}
void printInOrder(node *root){
    if(root == NULL){
        return;
    }
    printInOrder(root->left);cout<<root->data<<" ";printInOrder(root->right);
}
void printPostOrder(node *root){
    if(root == NULL){
        return;
    }
    printPostOrder(root->left);printPostOrder(root->right);cout<<root->data<<" ";
}
void printkthlevel(node*root,int k){
    if(root==NULL){
        return;
    }
    if(k==1){
        cout<<root->data<<" ";
        return;
    }
    printkthlevel(root->left,k-1);
    printkthlevel(root->right,k-1);
    return;
}
int height(node*root){
    if(root == NULL){return 0;}
    return (max(height(root->left),height(root->right))+1);
}
void printAllLevels(node*root){
    int h = height(root);
    for (int i = 1; i <= h; ++i)
    {
        printkthlevel(root,i);
        cout<<endl;
    }
    return;
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
}
int countAllNode(node*root){
    if(root==NULL){
        return 0;
    }
    return(1+countAllNode(root->left)+countAllNode(root->right));
}
int sumAllNodes(node*root){
    if(root==NULL){
        return 0;
    }
    return(root->data + sumAllNodes(root->left) +sumAllNodes(root->right));
}
// this function calculates the height for every subtree at every node O(n^2)
int diameter(node*root){
    if(root==NULL){
        return 0;
    }
    int heightleft = height(root->left);
    int heightright = height(root->right);
    int op1 = heightleft+heightright+1;
    int op2 = diameter(root->left);
    int op3 = diameter(root->right);
    return max(op1,max(op3,op2));
}
// class Pair{
// public:
//     int height;
//     int diameter;
// };
// Pair fastDiameter(node*root){
//     Pair p;
//     if(root==NULL){
//         p.diameter = p.height = 0;
//         return p;
//     }
//     Pair left = fastDiameter(root->left);
//     Pair right = fastDiameter(root->right);

//     p.height = max(left.height,right.height)+1;
//     p.diameter = max((left.height+right.height),max(left.diameter,right,diameter));
//     return p;
// }
int replaceBySum(node*&root){
    if(root==NULL){
        return 0;
    }
    if(root->left == NULL && root->right== NULL){
        return root->data;
    }
    int leftSum = replaceBySum(root->left);
    int rightSum = replaceBySum(root->right);
    int temp = root->data;
    root->data = leftSum + rightSum;
    return temp + root->data;
}
class HBPair{
    public:
        int height;
        bool balance;
};

HBPair isHeightBalanced(node *root){
    HBPair p;
    if(root == NULL){
        p.height = 0;
        p.balance = true;
        return p;
    }
    HBPair left =  isHeightBalanced(root->left);
    HBPair right = isHeightBalanced(root->right);
    p.height = max(left.height , right.height)+ 1;
    if(abs(left.height - right.height) <= 1  && left.balance && right.balance){
        p.balance = true;
    } else {
        p.balance = false;
    }
    return p;
}
node* bstFromArray(int arr[],int start,int end){
    if(start>end){
        return NULL;
    }
    int mid = (start+end)/2;
    node* root = new node(arr[mid]);
    root->left = bstFromArray(arr,start,mid-1);
    root->right = bstFromArray(arr,mid+1,end);
    return root;
}
/* 1) iteratively pick one data from preorder array
   2) search for that elem in inorder array(i)
   3) f(a,s,i-1)*/
// the start and end are for the preoder array
node* treeFromTraversal(int *inorderArray,int *preorderArray,int start,int end){
    static int i = 0;
    if(start>end){
        return NULL;
    }
    node* root = new node(preorderArray[i]);
    // it is the index of the elem in inorderArray
    int index = -1;
    for(int j=start;j<=end;j++){
        if(inorderArray[j]==preorderArray[i]){
            index=j;
            break;
        }
    }
    i++;
    root->left = treeFromTraversal(inorderArray,preorderArray,start,index-1);
    root->right = treeFromTraversal(inorderArray,preorderArray,index+1,end);
    return root;
}
bool isIdentical(Node* r1,Node* r2)
{
    if(r1 == NULL && r2 == NULL)
    {
        return true;
    }
    if(r1 != NULL && r2 == NULL) return false;
    
    if(r1 == NULL && r2 != NULL) return false;
    
    bool ans1 =  r1->data == r2->data;
    
    bool ans2 = f(r1->left,r2->left);
    
    bool ans3 = f(r1->right,r2->right);
    
    return ans1&&ans2&&ans3;
}
int main(){
    // node*root = buildTree();
    int inorderArray[] = {3,2,8,4,1,6,7,5};
    int preorderArray[] = {1,2,3,4,8,5,6,7};
    int n = sizeof(inorderArray)/sizeof(int);
    /*cout<<"print in preorder";print(root);cout<<endl;
    cout<<"print in printInOrder";printInOrder(root);cout<<endl;
    cout<<"print in postorder";printPostOrder(root);cout<<endl;
    cout<<height(root)<<endl;
    printAllLevels(root);
    bfs(root);
    cout<<countAllNode(root)<<endl<<sumAllNodes(root);*/
    // node* root = bstFromArray(arr,0,6);
    node* root = treeFromTraversal(inorderArray,preorderArray,0,n-1);
    bfs(root);
    return 0;
}