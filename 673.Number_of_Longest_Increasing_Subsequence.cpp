class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n<=1) return n;
        int maxlen=0, maxcount=0;
        vector<int> len(n, 1), count(n, 1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]>=nums[i]) continue;

                if(len[i]==len[j]+1) count[i]+=count[j];
                else if(len[i]<len[j]+1){
                    len[i]=len[j]+1;
                    count[i]=count[j];
                }
            }
            if(len[i]==maxlen) maxcount+=count[i];
            else if(len[i]>maxlen){
                maxlen=len[i];
                maxcount=count[i];
            }
        }
        return maxcount;
    }
};

