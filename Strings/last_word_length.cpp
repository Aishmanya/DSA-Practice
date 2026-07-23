




class Solution {
public:
    int lengthOfLastWord(string s) {
        int end=s.length()-1;
        int count=0;

        while(end >=0 && s[end] == ' '){end--;}
        while(end >= 0 && s[end]!=' '){
            count++;
            end--;
        }
        return count;
    }
};