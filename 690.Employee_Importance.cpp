/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int solve(int id, unordered_map<int, Employee *> & m, set<int> & s){
        if(s.count(id)) return 0;
        int ret=m[id]->importance;
        for(int i=0;i<m[id]->subordinates.size();i++){
            ret+=solve((m[id]->subordinates)[i], m, s);
        }
        return ret;
    }

    int getImportance(vector<Employee*> employees, int id) {
        set<int> s;
        unordered_map<int, Employee *> m;
        for(auto e:employees) m[e->id]=e;
        return solve(id, m, s);
    }
};

