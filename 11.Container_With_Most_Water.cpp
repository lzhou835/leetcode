class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int ret=0;
        int left=0;
        int right=n-1;

        while(left<right)
        {
            int tmparea=(right-left)*min(height[left],height[right]);
            if(tmparea>ret) ret=tmparea;

            if(height[left]<height[right])
            {
                left++;
            }else if(height[left]>height[right])
            {
                right--;
            }
            else if(height[left]==height[right])
            {
                left++;
                right--;
            }
        }

        return ret;
    }
};

