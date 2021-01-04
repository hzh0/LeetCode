// 基于快排思想
class Solution {
public:

    int quicksort(vector<int>& num, int start, int end) {
        if (start >= end) {
            return start;
        }
        int target = start;
        int left = start + 1, right = end;
        while (left != right) {
            if (num[left] <= num[target]) {
                left++;
            }
            else {
                swap(num[left], num[right]);
                right--;
            }
        }
        if (num[left] <= num[target]) {
            swap(num[left], num[target]);
            return left;
        }
        else {
            swap(num[left - 1], num[target]);
            return left - 1;
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        int start = 0, end = nums.size() - 1, index, wh;
        while (true) {
            index = quicksort(nums, start, end);
            wh = nums.size() - index;
            if (wh == k) {
                return nums[index];
            }
            else if (wh < k) {
                start = start;
                end = index - 1;
            }
            else {
                start = index + 1;
                end = end;
            }
        }
        return -1;
    }
};

// 大根堆的方式
class Solution {
public:

    void MaxHeapfy(vector<int>& v, int i) {
        int size = v.size();
        int largest = i;
        int left = 2 * i + 1, right = 2 * i + 2;
        if (left < size && v[left] > v[largest]) {
            largest = left;
        }
        if (right < size && v[right] > v[largest]) {
            largest = right;
        }
        if (largest != i) {
            swap(v[i], v[largest]);
            MaxHeapfy(v, largest);
        }

    }

    void bulidMaxHeap(vector<int>& v) {
        int size = v.size();
        for (auto i = size/2; i >= 0; --i) {
            MaxHeapfy(v, i);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        bulidMaxHeap(nums);
        for (auto i = 0; i < k-1; ++i) {
            swap(nums[0], nums[nums.size() - 1]);
            nums.pop_back();
            MaxHeapfy(nums, 0);
        }
        return nums[0];
    }
};