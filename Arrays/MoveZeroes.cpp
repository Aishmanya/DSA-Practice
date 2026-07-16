// Q. Given an array , u have to move all zeroes to the end
// eg:- [2,3,1,4,0,5,6,0,9,8]   =>   [2,3,1,4,5,6,9,8,0,0]

// BRUTE FORCE
// T.C = O(2n)
// S.C = O(n)
1  vector<int> moveZeros(int n, vector<int> a) {
2  
3      // step - 1
4      vector<int> temp;
5      for(int i = 0; i < n; i++) {
6          if(a[i] != 0) {
7              temp.push_back(a[i]);
8          }
9      }
10 
11     // step - 2
12     int nz = temp.size();
13     for(int i = 0; i < nz; i++) {
14         a[i] = temp[i];
15     }
16 
17     // step - 3
18     for(int i = nz; i < n; i++) {
19         a[i] = 0;
20     }
21 
22     return a;
23 }


// OPTIMAL

#include <vector>
#include <algorithm>

using namespace std;

/*
 * Time Complexity: O(N) - Linear time to traverse the array.
 * Space Complexity: O(1) - Constant space, operations are done in-place.
 */
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = -1;
        
        for (int i = 0; i < nums.size(); i++){
            if(nums[i] == 0) { 
                j = i;
                break;
            }
        }
        
        if (j == -1) {
            return; 
        }

        for(int i = j + 1; i < nums.size(); i++ ){
            if(nums[i] != 0){
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};




