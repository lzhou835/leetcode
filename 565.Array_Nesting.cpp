class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n=nums.size(), ret=INT_MIN;
        vector<bool> visited(n, false);
        for(int i=0;i<n;i++){
            if(visited[i]) continue;
            int count=0, k=i;
            while(count==0 || k!=i){
                visited[k]=true;
                count++;
                k=nums[k];
            }
            ret=max(ret, count);
        }
        return ret;
    }
};

