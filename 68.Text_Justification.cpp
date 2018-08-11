class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ret;
        int start=0;
        while(start<words.size()){
            int end=start, len=0;
            while(end<words.size() && len+words[end].size()+end-start<=maxWidth){
                len+=words[end++].size();
            }

            int space=maxWidth-len;
            string tmp;
            for(int i=start;i<end;i++){
                tmp+=words[i];
                if(space>0){
                    int cnt=0;
                    if(end==words.size()){
                        if(end-i==1) cnt=space;
                        else cnt=1;
                    }else{
                        if(end-i-1>0){
                            if(space%(end-i-1)==0) cnt=space/(end-i-1);
                            else cnt=space/(end-i-1)+1;
                        }else cnt=space;
                    }
                    tmp.append(cnt, ' ');
                    space-=cnt;
                }
            }
            ret.push_back(tmp);
            start=end;
        }
        return ret;
    }
};
