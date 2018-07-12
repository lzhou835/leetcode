class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        int len=tasks.size();
        for(char a:tasks) count[a-'A']++;
        sort(count.begin(), count.end());
        int i=25, mc=count[25];
        while(i>=0 && count[i]==mc) i--;
        return max(len, (n+1)*(mc-1)+25-i);
    }
};

