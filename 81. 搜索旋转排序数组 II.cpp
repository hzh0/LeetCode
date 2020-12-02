class Solution {
public:

    bool func(vector<int>& nums, int left, int right, int target) {
        if (left > right) return false;
        if (left == right) {
            if (nums[left] == target) return true;
            return false;
        }
        if (nums[left] == nums[right]) return func(nums, left + 1, right, target);
        int mid = (left + right) / 2;
        if (nums[mid] == target) return true;
        if (nums[mid] < target) {
            if (nums[right] == target || nums[left] == target) return true;
            if (nums[right] > nums[mid] && nums[right] > target) return false || func(nums, mid + 1, right, target);
            if (nums[right] > nums[mid] && nums[right] < target) return false || func(nums, left, mid - 1, target);
            else if (nums[right] == nums[mid]) return false || func(nums, left, right-1, target);
            else return false || func(nums, mid + 1, right, target);
        }
        else {
            if (nums[left] == target) return true;
            if (nums[left] < nums[mid] && nums[left] > target) return false || func(nums, mid + 1, right, target);
            else if (nums[left] < nums[mid] && nums[left] < target) return false || func(nums, left, mid - 1, target);
            else if (nums[left] == nums[mid]) return false || func(nums, left + 1, right, target);
            else return false || func(nums, left, mid-1, target);
        }
    }

    bool search(vector<int>& nums, int target) {
        return func(nums, 0, nums.size() - 1, target);
    }
};