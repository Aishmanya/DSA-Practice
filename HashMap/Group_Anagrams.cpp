// Problem: Group Anagrams
// Link: https://leetcode.com/problems/group-anagrams/
// Time: O(N * K log K) -> N is number of strings, K is maximum length of a string
// Space: O(N * K) -> To store strings inside the hash map

// Approach:
// Anagrams yield the exact same string when sorted.
// Iterate through each string, sort a copy of it to use as a key in an unordered_map.
// Group original strings into vectors mapped to their corresponding sorted keys.
// Extract all grouped vectors into the final 2D result.


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        //filling map (by grouping and filtering)
        for(const string&s : strs){
            string key=s;
            sort(key.begin(),key.end());
            mp[key].push_back(s);
        }

        //map ka sare values ko result vector me as vectors add kar rheh like [['bat','tab'],['ate','eat','tea']]
        vector<vector<string>> result;
        for(auto& it:mp){
            result.push_back(it.second);
        }

        return result;
    }
};