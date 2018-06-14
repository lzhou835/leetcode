class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2) return 0;
        int mn=INT_MAX, mx=INT_MIN, n=nums.size();
        for(auto a:nums){
            mn=min(mn, a);
            mx=max(mx, a);
        }
        
        int size=(mx-mn)/n+1;
        int cnt=(mx-mn)/size+1;
        
        vector<int> bmin(cnt, INT_MAX);
        vector<int> bmax(cnt, INT_MIN);
        set<int> s;
        for(int i=0;i<n;i++){
            int id=(nums[i]-mn)/size;
            bmin[id]=min(bmin[id], nums[i]);
            bmax[id]=max(bmax[id], nums[i]);
            s.insert(id);
        }
        
        int pre=0, res=0;
        for(int i=1;i<cnt;i++){
            if(!s.count(i)) continue; 
            res=max(res, bmin[i]-bmax[pre]);
            pre=i;
        }
        return res;
    }
};
