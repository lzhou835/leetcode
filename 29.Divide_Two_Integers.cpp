class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor==0) return dividend>=0?INT_MAX:INT_MIN;
        if(dividend==INT_MIN && divisor==-1) return INT_MAX;

        bool negative=false;
        if(divisor>0&&dividend<0 || divisor<0&&dividend>0) negative=true;

        long long up=abs((long long)dividend);
        long long down=abs((long long)divisor);

        int i=0;
        while((down<<(i+1)) <= up) i++;

        long long ret=0;
        long long tmp=1;
        while(up>=down)
        {
            if(up >= (down<<i))
            {
                 ret=ret+(tmp<<i);
                 up=up-(down<<i);
            }
            i--;
        }

        return negative?(-ret):ret;
    }
};

