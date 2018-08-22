class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int ret=0;
        heights.push_back(0);
        for(int i=0;i<heights.size();i++){
            if(s.empty() || heights[i]>heights[s.top()]) s.push(i);
            else {
                int cur=s.top();
                s.pop();
                ret=max(ret, heights[cur]*(s.empty()?i:i-s.top()-1));
                i--;
            }
        }
        return ret;
    }
};
