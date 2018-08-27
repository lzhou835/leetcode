class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret;
        if(rowIndex<0) return ret;
        ret.assign(rowIndex+1, 0);
        for(int i=0;i<=rowIndex;i++){
            if(i==0){
                ret[0]=1;
                continue;
            }else{
                for(int j=rowIndex;j>=1;j--) ret[j]=ret[j]+ret[j-1];
            }
        }
        return ret;
    }
};

