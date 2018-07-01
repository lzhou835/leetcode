class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> res(findNums.size());
        unordered_map<int, int> m;
        for(int i=0;i<nums.size();i++)
            m[nums[i]]=i;
        
        for(int i=0;i<findNums.size();i++){
            res[i]=-1;
            int start=m[findNums[i]];
            for(int j=start+1;j<nums.size();j++){
                if(nums[j]>nums[start]){
                    res[i]=nums[j];
                    break;
                }
            }
        }
        
        return res;
    }
};
