class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), 0);
        for(int i=0;i<graph.size();i++){
            if(color[i]) continue;
            color[i]=1;
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int j=q.front();
                q.pop();
                for(auto a:graph[j]){
                    if(color[a]==0){
                        color[a]=-1*color[j];
                        q.push(a);
                    }else{
                        if(color[a]==color[j]) return false;
                    }
                }
            }
        }
        return true;
    }
};
