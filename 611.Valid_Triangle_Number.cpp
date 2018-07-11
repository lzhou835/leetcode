class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n=nums.size();
        int ret=0;
        sort(nums.begin(), nums.end());
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                int sum=nums[i]+nums[j];
                int left=j+1, right=n;
                while(left<right){
                    int mid=left+(right-left)/2;
                    if(nums[mid]<sum) left=mid+1;
                    else right=mid;
                }
                ret+=right-1-j;
            }
        }
        return ret;
    }
};

