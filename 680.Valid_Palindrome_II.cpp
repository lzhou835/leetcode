class Solution {
public:
    bool valid(string & s, int left, int right, int count){
        if(left>=right) return true;

        if(s[left]==s[right]) return valid(s, left+1, right-1, count);

        return count>0 && (valid(s, left+1, right, count-1) || valid(s, left, right-1, count-1));
    }

    bool validPalindrome(string s) {
        return valid(s, 0, s.length()-1, 1);
    }
};
~       
