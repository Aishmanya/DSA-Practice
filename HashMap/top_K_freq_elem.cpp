// Problem: Top K Frequent Elements
// Link: https://leetcode.com/problems/top-k-frequent-elements/
// Time: O(n) -> Counting frequencies takes O(n), Bucket Sort takes O(n)
// Space: O(n) -> Hash map and Buckets take extra space

// Approach:
// 1. Build a frequency map for all elements.
// 2. Create buckets where index represents the frequency and stores numbers with that frequency.
// 3. Iterate backward through buckets (from highest frequency down) to collect top K elements.


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> countMap;
        for (int num : nums) {
            countMap[num]++;
        }
        
        // Bucket index = frequency, Bucket value = list of numbers with that frequency
        int n = nums.size();
        vector<vector<int>> buckets(n + 1);
        for (auto& pair : countMap) {
            buckets[pair.second].push_back(pair.first);
        }
        
        vector<int> result;
        // Traverse from back (highest possible frequency down to 1)
        for (int i = n; i >= 1 && result.size() < k; i--) {
            for (int num : buckets[i]) {
                result.push_back(num);
                if (result.size() == k) break;
            }
        }
        
        return result;
    }
};