class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> ret;
        unordered_map<int, int> m;
        vector<pair<int, int>> v;

        for(int i=0;i<nums.size();i++){
            for(auto num:nums[i]) v.push_back({num, i});
        }

        sort(v.begin(), v.end());
        int left=0, n=v.size(), k=nums.size(), count=0, diff=INT_MAX;
        for(int right=0;right<n;right++){
            if(m[v[right].second]==0) count++;
            m[v[right].second]++;
            while(left<=right && count==k){
                if(diff>v[right].first-v[left].first){
                    diff=v[right].first-v[left].first;
                    ret={v[left].first, v[right].first};
                }
                if(--m[v[left].second]==0) count--;
                left++;
            }
        }

        return ret;
    }
};

