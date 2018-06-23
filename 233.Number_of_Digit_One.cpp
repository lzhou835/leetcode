class Solution {
public:
    int countDigitOne(int n) {
        int res=0;
        for(long long m=1;m<=n;m*=10){
            int left=n/m, right=n%m;
            res+=(left+8)/10*m+(left%10==1)*(right+1);
        }
        return res;
    }
};
