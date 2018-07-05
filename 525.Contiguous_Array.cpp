class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int one=0;
        int zero=0;
        int len=0;
        unordered_map<int, int> hashmap;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) zero++;
            else one++;

            if(zero==one) len=i+1;
            else if(hashmap.count(one-zero)) len=max(len, i-hashmap[one-zero]);

            if(!hashmap.count(one-zero)) hashmap[one-zero]=i;
        }
        return len;
    }
};

