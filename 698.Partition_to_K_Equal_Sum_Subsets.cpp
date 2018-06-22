class Solution {
public:
    bool solve(vector<int> & nums, int k, int target, int start, int cursum, vector<bool> & visited){
        if(k==1) return true;
        if(cursum==target) return solve(nums, k-1, target, 0, 0, visited);
        for(int i=start;i<nums.size();i++){
            if(visited[i]) continue;
            visited[i]=true;
            if(solve(nums, k, target, i+1, cursum+nums[i], visited)) return true;
            visited[i]=false;
        }
        
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=accumulate(nums.begin(), nums.end(), 0);
        if(sum%k) return false;
        vector<bool> visited(nums.size(), false);
        return solve(nums, k, sum/k, 0, 0, visited);
    }
};
