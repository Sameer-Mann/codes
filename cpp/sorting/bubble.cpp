#include<iostream>
using namespace std;
void bubbleSort2(int a[],int i,int n){
	if(n==1){
		return;
	}
	if(i==n-1){
		return bubbleSort2(a,0,n-1);
	}
	if(a[i]>a[i+1]){
		swap(a[i],a[i+1]);
	}
	bubbleSort2(a,i+1,n);
	return;
}
void bubbleSort(int a[],int n){
	// base case
	if(n==1){
		return;
	}
	bubbleSort2(a,0,n);
	// sort 1 element and call for reamining n-1 elements
	// for(int i=0;i<=n-2;i++){
	// 	if(a[i]>a[i+1]){
	// 		swap(a[i],a[i+1]);
	// 	}
	// }
	bubbleSort(a,n-1);
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i)
		cin>>a[i];
	bubbleSort(a,n);
	for (int i = 0; i < n; ++i)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}