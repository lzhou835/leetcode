class Solution {
public:
    bool solve(int length, int total, int used, unordered_map<int, bool> & m){
        if(m.count(used)) return m[used];
        for(int i=0;i<length;i++){
            int cur=(1<<i);
            if((cur & used) ==0){
                if(total<=i+1 || !solve(length, total-(i+1), used | cur, m)){
                    m[used]=true;
                    return true;
                }
            }
        }
        m[used]=false;
        return false;
    }
    
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(maxChoosableInteger>=desiredTotal) return true;
        if((maxChoosableInteger+1)*maxChoosableInteger/2<desiredTotal) return false;
        unordered_map<int, bool> m;
        return solve(maxChoosableInteger, desiredTotal, 0, m);
    }
};
