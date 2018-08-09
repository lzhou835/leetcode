class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n=nums.size(), maxsum=0;
        vector<int> sum={0}, iLeft(n, 0), iRight(n, n-k), ret(3, 0);
        for(int num:nums) sum.push_back(sum.back()+num);
        for(int i=k, range=sum[k]-sum[0];i<n;i++){
            if(sum[i+1]-sum[i+1-k]>range){
                range=sum[i+1]-sum[i+1-k];
                iLeft[i]=i+1-k;
            }else iLeft[i]=iLeft[i-1];
        }

        for(int i=n-k-1, range=sum[n]-sum[n-k];i>=0;i--){
            if(sum[i+k]-sum[i]>=range){
                range=sum[i+k]-sum[i];
                iRight[i]=i;
            }else iRight[i]=iRight[i+1];
        }

        for(int i=k;i<=n-2*k;i++){
            int l=iLeft[i-1], r=iRight[i+k];
            int range=sum[i+k]-sum[i]+sum[l+k]-sum[l]+sum[r+k]-sum[r];
            if(range>maxsum){
                maxsum=range;
                ret={l,i,r};
            }
        }
        return ret;
    }
};

