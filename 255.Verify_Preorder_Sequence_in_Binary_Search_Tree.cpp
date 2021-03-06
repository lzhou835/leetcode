class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int low=INT_MIN;
        stack<int> s;
        for(auto a:preorder){
            if(a<low) return false;
            while(!s.empty() && s.top()<a){
                low=s.top();
                s.pop();
            }
            s.push(a);
        }
        return true;
    }
};
