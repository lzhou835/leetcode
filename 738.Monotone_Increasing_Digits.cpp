class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string s=to_string(N);
        int n=s.size(), j=n;
        for(int i=n-1;i>=0;i--){
            if(s[i-1]<=s[i]) continue;
            s[i-1]--;
            j=i;
        }
        
        for(int i=j;i<n;i++) s[i]='9';
        return stoi(s);
    }
};
