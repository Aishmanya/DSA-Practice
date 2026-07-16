// Left rotate by d places

// BRUTE FORCE

// S.C = O(n) extra memory


#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void leftRotate(int arr[], int n, int d) {  //d is no. of places u wanna rotate
    d = d % n;

    int temp[d];
    for (int i = 0; i < d; i++)
    {
        temp[i] = arr[i];
    }

    for (int i = d; i < n; i++)
    {
        arr[i - d] = arr[i];
    }

    for (int i = n - d; i < n; i++)
    {
        arr[i] = temp[i - (n-d)];
    }
}
int main() {}



// OPTIMAL SOLUTION

// S.C = O(1) extra memory
// T.C = O(2n)


void leftrotate(int arr[], int n , int d){
    reverse(arr, arr+d);
    reverse(arr+d, arr+n);
    reverse(arr, arr+n);
}

int temp;
void Reverse(int arr[], int start, int end){
    while (start<=end){

        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}



