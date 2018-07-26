class Solution {
public:
    int findK(vector<int> & nums1, int startm,int lenm, vector<int>& nums2, int startn, int lenn, int k)
    {
        if(lenm==0) return nums2[startn+k-1];
        if(lenn==0) return nums1[startm+k-1];


        int i=lenm/2;
        int j=lenn/2;

        if(nums1[startm+i]<=nums2[startn+j])
        {
                if(k>i+j+1)
                {
                        return findK(nums1, startm+i+1, lenm-i-1, nums2, startn, lenn, k-i-1);
                }else{
                        return findK(nums1, startm, lenm, nums2, startn, j, k);
                }
        }else{
                if(k>i+j+1)
                {
                        return findK(nums1, startm, lenm, nums2, startn+j+1, lenn-j-1, k-j-1);
                }else{
                        return findK(nums1, startm, i, nums2, startn, lenn, k);
                }
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        int mid=(m+n)/2;

        if((m+n)%2 == 0)
        {
                return ((double)findK(nums1, 0, m, nums2, 0, n, mid)+(double)findK(nums1, 0, m, nums2, 0, n, mid+1))/2.0;
        }else{
                return (double)findK(nums1, 0, m, nums2, 0, n, mid+1);
        }
    }
};

