class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int sum=(C-A)*(D-B)+(G-E)*(H-F);
        if(B>=H || C<=E || D<=F || A>=G) return sum;
        return sum-(min(C, G)-max(E,A))*(min(D, H)-max(B,F));
    }
};
