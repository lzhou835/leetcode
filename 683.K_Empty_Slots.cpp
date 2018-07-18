class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        int n=flowers.size();
        vector<int> tmp(n);
        for(int i=0;i<n;i++) tmp[flowers[i]-1]=i+1;
        int ret=INT_MAX;
        int left=0, right=k+1;
        for(int i=0;right<n;i++)
        {
            if(tmp[i]<tmp[left] || tmp[i]<=tmp[right]){
                if(right==i) ret=min(ret, max(tmp[left], tmp[right]));
                left=i;
                right=k+1+i;
            }
        }
        return (ret==INT_MAX)?-1:ret;
    }
};
~  
