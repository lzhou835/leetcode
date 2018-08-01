class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int ret=0;

        vector<int> left(n,0);
        vector<int> right(n,0);

        for(int i=1;i<n;i++)
            left[i]=max(left[i-1],height[i-1]);

        for(int i=n-2;i>=0;i--)
        {
            right[i]=max(right[i+1],height[i+1]);
            int tmp=min(left[i],right[i]);
            if(tmp>height[i]) ret=ret+(tmp-height[i]);
        }
        return ret;
    }
};

