class Solution {
public:
    struct TrieNode{
        TrieNode * children[26];
        string str;
        TrieNode(): str(""){
            for(auto & a: children) a=NULL;
        }
    };
    
    struct Trie{
        TrieNode * root;
        Trie():root(new TrieNode()){}
        void insert(string s){
            TrieNode * p=root;
            for(auto & a:s){
                int i=a-'a';
                if(!p->children[i]) p->children[i]=new TrieNode();
                p=p->children[i];
            }
            p->str=s;
        }
    };
    
    void bfs(vector<vector<char>> & board, vector<string> & res, vector<vector<bool>> & visited, TrieNode * p, int i, int j){
        if(!p->str.empty()){
            res.push_back(p->str);
            p->str.clear();
        }
        
        vector<pair<int, int>> dir{{-1,0}, {1,0}, {0,-1}, {0, 1}};
        visited[i][j]=true;
        
        for(auto a:dir){
            int x=i+a.first, y=j+a.second;
            if(x<0 || y<0 || x>=board.size() || y>=board[0].size() || visited[x][y] || !p->children[board[x][y]-'a']) continue;
            bfs(board, res, visited, p->children[board[x][y]-'a'], x, y);
        }
        
        visited[i][j]=false;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        if(words.size()==0 || board.size()==0 || board[0].size()==0 ) return res;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        Trie T;
        for(auto & a:words) T.insert(a);
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(T.root->children[board[i][j]-'a']){
                    bfs(board, res, visited, T.root->children[board[i][j]-'a'], i, j);
                }
            }
        }
        return res;
    }
};
