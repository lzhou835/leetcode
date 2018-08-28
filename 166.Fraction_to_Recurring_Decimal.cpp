class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0) return "0";
        if(denominator == 0) return "";

        string ret;

        if(numerator != 0 && (numerator^denominator)>>31 )
        {
            ret="-";
        }

        long long llnumerator=llabs(numerator);
        long long lldenominator=llabs(denominator);

        ret+=to_string(llnumerator/lldenominator);
        llnumerator%=lldenominator;

        if(llnumerator>0) ret+=".";
        unordered_map<long long, int> tmp;
        while(llnumerator && tmp.count(llnumerator)==0)
        {
            tmp[llnumerator]=ret.length();
            llnumerator*=10;
            ret += to_string(llnumerator/lldenominator);
            llnumerator%=lldenominator;
        }

        if(tmp.count(llnumerator))
        {
            ret.insert(tmp[llnumerator], "(");
            ret.push_back(')');
        }

        return ret;
    }
};

