class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n==0) return true;
        for(int i=0;i<flowerbed.size();i++){
            if(flowerbed[i]==0){
                int next=i==flowerbed.size()-1?0:flowerbed[i+1];
                int pre=i==0?0:flowerbed[i-1];
                if(pre+next==0){
                    flowerbed[i]=1;
                    n--;
                }
            }
        }
        return n<=0;
    }
};

