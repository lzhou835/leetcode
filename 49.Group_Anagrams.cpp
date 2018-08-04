class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<int> > table;
        vector<vector<string> > ret;

        for(int i=0;i<strs.size();i++)
        {
            string key=strs[i];
            sort(key.begin(), key.end());
            table[key].push_back(i);
        }

        for(unordered_map<string, vector<int>>::iterator iter=table.begin();iter!=table.end();iter++)
        {
            if((iter->second).size()>0)
            {
                vector<string> tmp;
                for(int i=0;i<(iter->second).size();i++)
                {
                    tmp.push_back(strs[(iter->second)[i]]);
                }
                ret.push_back(tmp);
            }
        }

        return ret;
    }
};

