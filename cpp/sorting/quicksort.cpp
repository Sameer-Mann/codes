//uses divide and conquer 
// divides the array into 2 parts about a pivot
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
void shuffle(int *arr,int s,int e){
	srand(time(NULL));
	int i,j,tmp;
	for (int i = e; i > 0; i--)
	{
		j = rand()%(i+1);
		swap(arr[i],arr[j]);
	}
}
int partitioin(int *a,int s, int e){
	int i=s-1;
	int j=s;
	int pivot=a[e];
	for ( ;j<e; j++)
	{
		if(a[j]<=pivot) {
			i++;
			swap(a[i],a[j]);
		}
	}
	swap(a[i+1],a[e]);
	return i+1;
}
void quickSort(int *a, int s,int e){
	if(s>=e){
		return;
	}
	int p = partitioin(a,s,e);
	quickSort(a,s,p-1);
	quickSort(a,p+1,e);
}
int main(){
	int a[] = {2,1,5,6,7,5,8};
	int n = sizeof(a)/sizeof(int);
	shuffle(a,0,n);
	
	quickSort(a,0,n-1);
	for (int i = 0; i < n; i++)
	{
		cout<<a[i]<<' ';
	}
	return 0;
}