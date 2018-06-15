class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left=1, right=nums.size()-1;
        while(left<right){
            int cnt=0;
            int mid=left+(right-left)/2;
            for(auto a:nums){
                if(a<=mid) cnt++;
            }
            if(cnt<=mid) left=mid+1;
            else right=mid;
        }
        return left;
    }
};
