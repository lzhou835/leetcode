class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;

        int denominator=1;
        while(x/denominator >= 10)
        {
            denominator*=10;
        }

        while(x>0)
        {
            int high=x/denominator;
            int low=x%10;

            if(high != low) return false;
            x=x%denominator;
            x=x/10;
            denominator/=100;
        }

        return true;
    }
};

