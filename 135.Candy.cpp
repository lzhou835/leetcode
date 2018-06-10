class Solution {
public:
    int candy(vector<int>& ratings) {
        int res=0, len=ratings.size();
        vector<int> num(len, 1);
        for(int i=0;i<len-1;i++)
            if(ratings[i]<ratings[i+1]) num[i+1]=num[i]+1;
        for(int i=len-1;i>0;i--)
            if(ratings[i-1]>ratings[i]) num[i-1]=max(num[i-1], num[i]+1);
        for(int n:num) res+=n;
        return res;
    }
};
