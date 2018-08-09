class Solution {
public:
    string addBinary(string a, string b) {
        string sum;
        int n=max(a.length(), b.length());
        reverse(b.begin(), b.end());
        reverse(a.begin(), a.end());

        int value=0;
        for(int i=0;i<n;i++)
        {
            if(i<a.length()) value+=(a[i]-'0');
            if(i<b.length()) value+=(b[i]-'0');

            sum.push_back('0'+value%2);
            value=value/2;
        }

        if(value) sum.push_back(1+'0');
        reverse(sum.begin(), sum.end());
        return sum;
    }
};
