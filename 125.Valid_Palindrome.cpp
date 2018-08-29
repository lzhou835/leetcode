class Solution {
public:
    bool isPalindrome(string s) {
        int left=0;
        int right=s.length()-1;
        while(left<right){
            while(left<s.length() && !isalnum(s[left])) left++;
            while(right>=0 && !isalnum(s[right])) right--;
            if(left>=right) return true;
            if(toupper(s[left++])!=toupper(s[right--])) return false;
        }
        return true;
    }
};

