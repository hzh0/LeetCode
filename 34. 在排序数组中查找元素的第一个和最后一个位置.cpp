class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int mid;
        int lans, rans;
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] == target) {
                lans = mid, rans = mid;
                while (nums[lans] == target) {
                    lans--;
                    if (lans < 0) break;
                }
                while (nums[rans] == target) {
                    rans++;
                    if (rans > nums.size()-1) break;
                    
                }
                return { lans + 1, rans - 1 };
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else right = mid - 1;
        }
        return { -1,-1 };
    }
};