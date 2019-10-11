#include <iostream>
#include<vector>
using namespace std;

class Heap{
	vector<int> v;
	bool minHeap;

	bool compare(int a,int b){
		if(minHeap){
			return a<b;
		} else{
			return a>b;
		}
	}
	void heapify(int i){
		int left = 2*i;
		int right = 2*i + 1;
		int minIndex = i;
		//left<v.size is to check whether the left element exists or not
		if(left < v.size() && compare(v[left],v[i])){
			minIndex = left;
		}
		if(right < v.size() && compare(v[right],v[minIndex])){
			minIndex = right;
		}
		if(minIndex != i){
			swap(v[i],v[minIndex]);
			heapify(minIndex);
		}
	}
public:
	Heap(bool type=true){
		minHeap = type;
		//block the 0th index
		v.push_back(-1);
	}
	void push(int data){
		//insert at last
		v.push_back(data);
		//take that element to the correct position to reastore the heap property
		int index = v.size() - 1;
		int parent = index/2;
		while(index>1 && compare(v[index],v[parent])){
			swap(v[index],v[parent]);
			index = parent;
			parent/=2;
		}
	}
	bool empty(){
		return v.size() == 1;
	}
	int top(){
		return v[1];
	}
	void pop(){
		//remove the topmost element
		swap(v[1],v[v.size()-1]);
		v.pop_back();
		heapify(1);
	}
};
int main(){
	Heap h(false);
	h.push(5);h.push(15);h.push(2);h.push(20);h.push(3);
	// cout<<h.top()<<endl;
	while(!h.empty()){
		cout<<h.top()<<endl;
		h.pop();
	}
	return 0;
}