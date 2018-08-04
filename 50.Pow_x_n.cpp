class Solution {
public:
    double myPow(double x, int n) {
        double ret=1;

        bool flag=n>=0?true:false;
        int m=abs(n);

        for(int i=31;i>=0;i--)
        {
            ret=ret*ret;
            if( m & (1<<i))
                ret=ret*x;
        }

        if(!flag) ret=1/ret;
        return ret;
    }
};

