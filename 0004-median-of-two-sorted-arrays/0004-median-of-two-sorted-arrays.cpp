class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> a(nums1.size()+nums2.size());
        int i=0,j=0,k=0;
            while(i<nums1.size() && j<nums2.size()){
                if(nums1[i]<nums2[j]){
                    a[k]=nums1[i];
                    i++;
                    k++;
                }
                else{
                    a[k]=nums2[j];
                    k++; j++;
                }
            }
        if(j==nums2.size()){
            while(i<nums1.size()){
                a[k]=nums1[i];
                i++; k++;
            }
        }
        else{
            while(j<nums2.size()){
                a[k]=nums2[j];
                j++; k++;
            }
        }
        int size=nums1.size()+nums2.size();
        if(size%2==0){
            int mid=size/2;
            double med=(a[mid-1]+a[mid])/2.0;
            return med;
        }
        else{
            int mid=size/2;
            return a[mid];
        }
    }
};