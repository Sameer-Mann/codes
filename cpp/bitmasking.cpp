//
//  bitmasking.cpp
//  cpp
//
//  Created by Sameer Mann on 16/08/19.
//  Copyright © 2019 Sameer Mann. All rights reserved.
//

#include <stdio.h>
using namespace std;
#include <iostream>
#include <cstring>
int countSetBits(int n){
    //  this calculates the setbits in no. of total bits
    /* int ans = 0;
     for(;n>0;n=n>>1){
     ans += n&1;
     }
     return ans; */
    // this works in O of no. of set bits
    // as doing n&n-1 removes the last set bit each time until it reaches to zero
    int count = 0;
    while(n){
        count++;
        n = n&(n-1);
    }
    return count;
}
int getIthBit(int n,int i){
    // logic is to generate a no. such that & of n and that no. returns that bit
    return (n &(1<<i))!=0?1:0;
}
// change the ith bit of a no. to 1
void setIthBit(int &n, int i){
    n = (n|(1<<i));
}
void clearIthBit(int &n,int i){
    n = (n&(~(1<<i)));
}
// generating all subsets using bitmasking
void filterChars(char *a,int n){
    int i=0;
    while(n>0){
        (n&1)?cout<<a[i]:cout<<"";
        i++;
        n = n>>1;
    }
    cout<<endl;
}
void generateSubsets(int *a){
    // generate a range of numbers from 0 to 2^n - 1
    int n = strlen(a);
    int range = (1<<n) - 1;
    for (int i=0; i<=range; i++) {
        filterChars(a,i);
    }
}
