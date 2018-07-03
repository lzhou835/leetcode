class Solution {
public:
    int merge_sort(vector<int>::iterator begin, vector<int>::iterator end){
        if(end-begin <=1) return 0;
        auto mid=begin+(end-begin)/2;

        int count=merge_sort(begin, mid)+merge_sort(mid, end);
        for(auto i=begin, j=mid;i!=mid;i++)
        {
            while(j!=end && (*i) > 2L * (*j)) j++;
            count+=(j-mid);
        }
        inplace_merge(begin, mid, end);
        return count;
    }

    int reversePairs(vector<int>& nums) {
        return merge_sort(nums.begin(), nums.end());
    }
};

