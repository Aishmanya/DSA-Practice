// BRUTE FORCE 

// T.C= O(n2)      BADDD
// S.C= O()

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        for (int i=0; i<nums.size();i++){
            for(int j=i+1; j<nums.size();j++){
                if (nums[i]==nums[j]) return true;
            }
        }
        return false;
    }
};

// BETTER 

// Time Complexity per lookup/insertion: O(log n)
// Total Time Complexity: O(n log n)

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> mpp;
        for (int i=0; i<nums.size(); i++){
            if (mpp.find(nums[i]) != mpp.end()){
                return true;
            }
            else {
                mpp[nums[i]]=i;
            }
        }
        return false;
    }
};



// OPTIMAL  (using unordered map / unordered set)

// Using unordered_map switches the underlying structure to a Hash Table, 
// changing your lookup and insertion times from  O(log n) to O(1) on average.

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // Using unordered_set gives us O(1) average time complexity for lookups/insertions
        unordered_set<int> seen;
        
        for (int i = 0; i < nums.size(); i++) {
            if (seen.find(nums[i]) != seen.end()) {
                return true;
            }
            seen.insert(nums[i]);
        }
        
        return false;
    }
};


