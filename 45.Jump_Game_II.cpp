class Solution {
public:
    int jump(vector<int>& nums) {
        int steps=0;
        int i=0;
        int maxlen=0;

        while(maxlen<nums.size()-1){
            int lastmaxlen=maxlen;
            for(;i<=lastmaxlen;i++)
            {
                maxlen=max(maxlen, i+nums[i]);
            }
            steps++;
            if(lastmaxlen == maxlen) return -1;
        }
        return steps;
    }
};
~  
