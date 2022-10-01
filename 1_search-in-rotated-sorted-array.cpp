https : // leetcode.com/problems/search-in-rotated-sorted-array/

        Input : nums = [ 4, 5, 6, 7, 0, 1, 2 ],
                target = 0 Output : 4

                class Solution
{
public:
    int search(vector<int> &nums, int tar)
    {
        int s = 0, e = nums.size() - 1;
        int ans = -1;
        while (s <= e)
        {
            int mid = (e + s) >> 1;
            if (nums[mid] == tar)
                return mid;
            if (nums[s] <= nums[mid])
            {
                if (nums[mid] < tar || tar < nums[s])
                {
                    s = mid + 1;
                }
                else
                    e = mid - 1;
            }
            else
            {
                if (nums[mid] < tar && nums[e] >= tar)
                {
                    s = mid + 1;
                }
                else
                    e = mid - 1;
            }
        }
        return -1;
    }
};