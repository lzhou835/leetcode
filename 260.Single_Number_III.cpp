class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int sum=accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        sum &= -sum;
        vector<int> res(2, 0);
        for(auto n: nums){
            if( sum & n) res[0] ^= n;
            else res[1] ^= n;
        }
        return res;
    }
};
