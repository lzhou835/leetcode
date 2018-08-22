class Solution {
public:
    int largestRectangle(vector<int> & heights){
        int ret=0;
        stack<int> s;
        heights.push_back(0);
        for(int i=0;i<heights.size();i++){
            if(s.empty() || heights[s.top()]<heights[i]) s.push(i);
            else{
                int cur=s.top();
                s.pop();
                ret=max(ret, heights[cur]*(s.empty()?i:i-s.top()-1));
                i--;
            }
        }
        return ret;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> heights;
        int ret=0;
        for(int i=0;i<matrix.size();i++){
            heights.resize(matrix[i].size());
            for(int j=0;j<matrix[i].size();j++){
                heights[j]=matrix[i][j]=='0'?0:1+heights[j];
            }
            ret=max(ret, largestRectangle(heights));
        }
        return ret;
    }
};
