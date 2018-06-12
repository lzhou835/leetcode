/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int gcd(int x, int y){
        if(x==0) return y;
        return gcd(y%x, x);
    }
    
    int maxPoints(vector<Point>& points) {
        int res=0;
        for(int i=0;i<points.size();i++){
            map<pair<int, int>, int> m;
            int duplicate=1;
            for(int j=i+1;j<points.size();j++){
                if(points[i].x==points[j].x && points[i].y==points[j].y){
                    duplicate++;
                    continue;
                }
                int dy=points[i].y-points[j].y;
                int dx=points[i].x-points[j].x;
                int d=gcd(dy, dx);
                m[{dy/d, dx/d}]++;
            }
            res=max(res, duplicate);
            for(auto a:m){
                res=max(res, a.second+duplicate);
            }
        }
        return res;
    }
};
