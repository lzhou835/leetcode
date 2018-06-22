class Solution {
public:
    int lengthLongestPath(string input) {
        int res=0, n=input.size(), level=0;
        unordered_map<int, int> m{{0, 0}};
        for(int i=0;i<n;i++){
            int start=i;
            while(i<n && input[i]!='\n' && input[i]!='\t') i++;
            if(i>=n || input[i]=='\n'){
                string s=input.substr(start, i-start);
                if(s.find('.')!=string::npos){
                    res=max(res, m[level]+(int)s.size());
                }else{
                    level++;
                    m[level]=m[level-1]+(int)s.size()+1;
                }
                level=0;
            }else{
                level++;
            }
        }
        return res;
    }
};
