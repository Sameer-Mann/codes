#include<iostream>
using namespace std;
class node{
public:
	int data;
	node* next;
	// constructor for node
	node(int d){
		data = d;
		next = NULL;
	}
};
void insertHead(node*&head,int data){
	node*n = new node(data);
	n->next = head;
	head = n;
}
int length(node*head){
	int l = 0;
	while(head!=NULL){
		head = head->next;
		l+=1;
	}
	return l;
}
void insertAtTail(node*&head,int data){
	// in case if the list is empty
	if(head==NULL){
		head = new node(data);
		return;
	}
	node*tail = head;
	while(tail->next!=NULL){
		tail = tail->next;
	}
	tail->next = new node(data);
	return;
}
void insertInMiddle(node*&head,int data,int pos){
	if(head==NULL||pos==0){
		insertHead(head,data);
	}
	else if(pos>length(head)){
		insertAtTail(head,data);
	}else{
		// inserting at middle
		 //take p-1 jumps
		int jump = 1;
		node*temp = head;
		while(jump<=pos-1){
			temp = temp->next;
			jump+=1;
		}
		node*n = new node(data);
		n->next = temp->next;
		temp->next = n;
	}
}
void deleteAtHead(node*&head){
	if(head==NULL){
		return;
	}
	node*temp = head;
	head = head->next;
	delete temp;
	return;
}
void deleteAtTail(node*&head){
	node*previous=NULL;
	node*temp=head;
	while(temp->next != NULL){
		previous = temp;
		temp = temp->next;
	}
	delete temp;
	previous->next = NULL;
	return;
}
void deleteInTheMiddle(node*&head,int pos){
	if(head==NULL||pos==0){
		return;
	}
	else if(pos>length(head)){
		deleteAtTail(head);
		return;
	}
	else if(pos == 1){
		deleteAtHead(head);
		return;
	}
	else{
		int jump = 1;
		node*previous=NULL;
		node*temp = head;
		while(jump<=pos-1){
			previous= temp;
			temp = temp->next;
			jump++;
		}
		previous->next = temp->next;
		delete temp;
		return;
	}
}
bool searchRecursive(node*head,int val){
	if(head == NULL){
		return false;
	}
	if(head->data == val){
		return true;
	}
	return searchRecursive(head->next,val);
}
bool searchIterative(node*head,int val){
	while(head!=NULL){
		if(head->data==val){
			return true;
		}
		head = head->next;
	}
	return false;
}
void buildList(node*&head){
	int temp;
	cin>>temp;
	while(temp != -1){
		insertAtTail(head,temp);
		cin>>temp;
	}
}
void print(node* head){
	// node*temp = head;
	// we can use head as it is passed by value
	// so here the actual head does not change
	while(head != NULL){
		cout<<head->data;
		head = head->next;
		cout<<"-->";
	}
	cout<<endl;

}
void reverseList(node*&head){
	node*c = head;node*p = NULL;node*n;
	while(c!=NULL){
		// save the next node
		n = c->next;
		// make the current node point to previoius
		c->next = p;
		//just update prev and current
		p = c;
		c = n;
	}
	head= p;
}
node* reverseRecursive(node*head){
	// if list is empty or has only one element 
	// it is the reverse of itself
	if(head->next==NULL||head==NULL){
		return head;
	}
	node*smallHead = reverseRecursive(head->next);
	node*c = head;
	c->next->next = c;
	c->next = NULL;
	return smallHead;
}
node* midPoint(node*head){
	if(head==NULL|| head->next==NULL){
		return head;
	}
	node*slow = head;
	node*fast = head->next;
	while(fast!= NULL && fast->next != NULL){
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}
node* kthNodeFromLast(node*head,int k){
	node*slow = head;
	node*fast = head;
	int jumps=0;
	while(jumps<k){
		fast = fast->next;
		jumps++;
	}
	while(fast != NULL){
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}
node* mergeTwoSortedLinkedList(node*a,node*b){
	if(a==NULL){
		return b;
	}
	return head;
}
/*taking linked list as input using operator overloading
istream& operator>>(istream &is,node*&head){
	buildList(head);
	return is;
}
ostream& operator<<(ostream &os,node*&head){
	print(head);
	return os;
}*/
int main(){
	node* head = NULL;
	insertHead(head,5);insertHead(head,3);insertHead(head,4);insertAtTail(head,10);insertAtTail(head,25);insertInMiddle(head,-2,3);
	// if(searchRecursive(head,5)){cout<<"Element is present\n";}else{cout<<"Element is not present\n";}
	// if(searchIterative(head,25)){cout<<"Element is present\n";}else{cout<<"Element is not present\n";}
	// deleteAtTail(head);deleteInTheMiddle(head,2);
	print(head);
	// head =  reverseRecursive(head);
	// cout<<midPoint(head)->data;
	cout<<kthNodeFromLast(head,2)->data;
	// print(head);
	return 0;
}