class Solution {
public:
    int cal(int x, int a, int b, int c){
        return a*x*x+b*x+c;
    }
    
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int n=nums.size(), i=0, j=n-1;
        int id=a>=0?n-1:0;
        vector<int> res(n);
        while(i<=j){
            if(a>=0){
                res[id--]=cal(nums[i], a, b, c)>=cal(nums[j], a, b, c)?cal(nums[i++], a, b, c):cal(nums[j--], a, b, c);
            }else{
                res[id++]=cal(nums[i], a, b, c)>=cal(nums[j], a, b, c)?cal(nums[j--], a, b, c):cal(nums[i++], a, b, c);
            }
        }
        return res;
    }
};
