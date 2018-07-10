class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> ret;
        unordered_map<string, int> hashmap;
        int n1=list1.size(),n2=list2.size();
        int minsum=INT_MAX, sum=0;
        for(int i=0;i<n1;i++) hashmap[list1[i]]=i;
        for(int i=0;i<n2;i++){
            if(hashmap.count(list2[i])){
                sum=hashmap[list2[i]]+i;
                if(sum==minsum) ret.push_back(list2[i]);
                else if(sum<minsum){
                    minsum=sum;
                    ret={list2[i]};
                }
            }
        }

        return ret;
    }
};

