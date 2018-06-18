class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int res=0;
        for(int i=L;i<=R;i++){
            int cnt=__builtin_popcount(i);
            res+=cnt<4?cnt>1:(cnt%2 && cnt%3);
        }
        return res;
    }
};
