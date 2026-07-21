// QUESTION

/* You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.*/

// This is a 'dynamic programming' approach as I am memorizing the previous result. (Greedy Technique)

//




// MY BRUTE FORCE

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min=prices[0];
        int profit=0;
        int start= 0;
        int diff=0;
        for (int i=1; i<prices.size(); i++){
            if (prices[i]<min){min=prices[i];
            start=i;}
        }

        for(int j=start; j<prices.size(); j++){
            diff=prices[j]-prices[start];
            if(diff>profit){
                profit=diff;
            }
        }
        return profit;
        
    }
};



