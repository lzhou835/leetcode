class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n=wall.size(),mx=0;
        unordered_map<int, int> hmap;
        for(auto a:wall){
            int sum=0;
            for(int i=0;i<a.size()-1;i++){
                sum+=a[i];
                hmap[sum]++;
                mx=max(mx, hmap[sum]);
            }
        }
        return n-mx;
    }
};
