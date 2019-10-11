//  in this i have entered some of the commonly used function
#include <iostream>
#include <stdio.h>
//#include "imp.h"
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
    bubbleSort2(a,0,n);bubbleSort(a,n-1);
     /*sort 1 element and call for reamining n-1 elements
     for(int i=0;i<=n-2;i++){
         if(a[i]>a[i+1]){
             swap(a[i],a[i+1]);
         }
     }*/
}
void merge(int *a,int start,int end){
    int mid = (start+end)/2;int i=start;int j=mid+1;int k=start;int temp[100];
    while(i<=mid && j<=end){
        if(a[i] < a[j]){
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
        }
    }
    while(i<=mid){
        temp[k++] = a[i++];
    }
    while(j<=end){
        temp[k++] = a[j++];
    }
    for (int i = start; i <= end; i++)
    {
        a[i] = temp[i];
    }
}
void mergeSort(int a[],int start,int end){
    //base case
    if(start>=end){
        return;
    }
    //first divide the array
    int mid = (start+end)/2;
    // recursively sort the arrays,start - mid mid+1 -end
    mergeSort(a,start,mid);mergeSort(a,mid+1,end);merge(a,start,end);
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
    quickSort(a,s,p-1);quickSort(a,p+1,e);
}
