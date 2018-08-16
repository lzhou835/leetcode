class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ret(digits.size(), 0);

        int value=1;
        for(int i=digits.size()-1;i>=0;i--)
        {
            value=value+digits[i];
            ret[i]=value%10;
            value=value/10;
        }
        if(value) ret.insert(ret.begin(), 1);
        return ret;
    }
};

