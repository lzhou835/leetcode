class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n=nums.size(), left=0, right=nums.back()-nums[0];
        while(left<right){
            int mid=(right-left)/2+left;
            int cnt=0, start=0;
            for(int i=0;i<n;i++){
                while(start<n && nums[i]-nums[start]>mid) start++;
                cnt+=i-start;
            }
            if(cnt<k) left=mid+1;
            else right=mid;
        }
        return right;
    }
};
