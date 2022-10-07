/*
    link: https://leetcode.com/problems/search-in-rotated-sorted-array/
*/


// ----------------------------------------------------------------------------------------------------------------------- //
/*
    simple binary search
    TC: O(logn)
*/
int search(vector<int>& nums, int target) {
    int size = nums.size();
    auto i = nums.begin();
    i = min_element(nums.begin(), nums.end());

    // pos is the index of smallest ele.
    int pos = i - nums.begin();
    int l = 0;
    int r = size - 1;

    // set the value range.
    if (target == nums[r]) return r;
    if (target > nums[r]) r = pos - 1;
    else l = pos;

    // till now we have already set l and r for our defined range.
    while (l <= r) {
        int mid = (l + r) / 2;
        if (target == nums[mid]) return mid;
        if (target < nums[mid]) r = mid - 1;
        else l = mid + 1;
    }
    return -1;
}



// ----------------------------------------------------------------------------------------------------------------------- //
class Solution {
public:
    int search(vector<int>& nums, int tar) {
        int l=0, r=nums.size()-1;
        while(l<=r){
            int mid=(l+r)>>1;
            if(tar==nums[mid])return mid;
            if(nums[l]<=nums[mid]){
                if(tar<nums[l] || tar>nums[mid])
                    l=mid+1;
                else
                    r=mid-1;
            }
            else {
                if(tar<nums[mid] || tar>nums[r])
                    r=mid-1;
                else
                    l=mid+1;
            }
        }
        return -1;
    }
};