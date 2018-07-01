class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> res;
        multimap<int, pair<int, int>> m;
        for(int i=0;i<min(k, (int)nums1.size());i++){
            for(int j=0;j<min(k, (int)nums2.size());j++){
                m.insert({nums1[i]+nums2[j], {nums1[i], nums2[j]}});
            }
        }
        
        for(auto it=m.begin();it!=m.end();it++){
            res.push_back(it->second);
            if(--k<=0) return res;
        }
        
        return res;
    }
};
