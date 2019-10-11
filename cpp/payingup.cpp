//
//  payingup.cpp
//  cpp
//
//  Created by Sameer Mann on 16/08/19.
//  Copyright © 2019 Sameer Mann. All rights reserved.
//

#include <stdio.h>
#include "iostream"
using namespace std;
bool filterBits(int *a,int i,int k){
    int ans = 0;
    int counter = 0;
    int temp = 0;
    while(i>0){
        temp = (i&1);
        if(temp)
            ans += a[counter];
        counter++;
        i = i>>1;
    }
    if(ans == k)
        return true;
    return false;
}
int main(){
    int test;cin>>test;
    while(test--){
        int n,k;
        cin>>n>>k;
        int note[n];
        for (int i=0; i<n; i++) {
            cin>>note[i];
        }
        int val = (1<<n) - 1;
        bool flag = false;
        for (int i=0; i<=val; i++) {
            if(filterBits(note,i,k)){
                flag = true;
                break;
            }
        }
        if(flag){
            cout<<"Yes"<<endl;
        } else {
            cout<<"No"<<endl;
        }
    }
    return 0;
}
