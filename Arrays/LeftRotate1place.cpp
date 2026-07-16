// left rotate an array by 1 place (unsorted array)
// eg:- [1,2,9,4,5]   =>   [2,9,4,5,1]

// BRUTE FORCE

#include <bits/stdc++.h>
vector<int> rotateArray(vector<int> &arr, int n){
    int temp=arr[0];
    for (int i=1; i<n; i++){
        arr[i-1] = arr[i];
    }
    arr[n-1]=temp;
    return arr
}

// T.C = O(n)
// extra S.C =O(1)





