class Solution {
public:
    int maximumSwap(int num) {
        string ret=to_string(num), back=ret;
        for(int i=back.length()-2;i>=0;i--) back[i]=max(back[i], back[i+1]);
        for(int i=0;i<back.length();i++){
            if(back[i]==ret[i]) continue;
            for(int j=back.length()-1;j>i;j--){
                if(ret[j]==back[i]){
                    swap(ret[i], ret[j]);
                    return stoi(ret);
                }
            }
        }
        return stoi(ret);
    }
};

