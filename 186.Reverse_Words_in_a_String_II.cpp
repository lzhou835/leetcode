class Solution {
public:
    void reverse(vector<char> & str, int left, int right){
        while(left<right){
            swap(str[left], str[right]);
            left++;
            right--;
        }
    }
    
    void reverseWords(vector<char>& str) {
        int left=0;
        for(int i=0;i<=str.size();i++){
            if(i==str.size() || str[i]== ' '){
                reverse(str, left, i-1);
                left=i+1;
            }
        }
        reverse(str, 0, str.size()-1);
    }
};
