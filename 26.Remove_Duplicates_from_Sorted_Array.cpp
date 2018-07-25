class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n<2) return n;
        int i=0;
        for(int j=1;j<n;j++)
        {
            if(nums[j]!=nums[i])
            {
                i++;
                if(i!=j) nums[i]=nums[j];
            }
        }
        return i+1;
    }
};

