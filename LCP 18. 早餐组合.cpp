// 先对 staple 和 drinks 进行从小到大的排序
// 然后依次选择 staple 中的一个食物，下表为index，然后去 drinks 寻找满足 drinks[i] <= x - staple[index] 的饮料 i 
// 因为是排好序的数组，我们可以直接使用二分查找寻找满足条件的 i
// 然后将每种 staple 对应的所有满足条件的饮料个数相加返回即可 

class Solution {
public:

    int bfind(int x, vector<int>& v) {
        if (v[v.size() - 1] <= x) return v.size();
        long start = 0, end = v.size() - 1, mid;
        while (start <= end) {
            mid = (start + end) / 2;
            if (v[mid] > x) {
                if (mid - 1 >= 0 && v[mid - 1] <= x) return mid;
                else end = mid - 1;
            }
            else if (v[mid] == x) {
                while (mid + 1 < v.size()) {
                    if (v[mid + 1] == x) {
                        mid++;
                    }
                    else {
                        break;
                    }
                }
                return mid + 1;
            }
            else if (v[mid] < x) {
                if (mid + 1 < v.size() && v[mid + 1] > x) return mid+1;
                else start = mid + 1;
            }
        }
        return 0;
    }

    int breakfastNumber(vector<int>& staple, vector<int>& drinks, int x) {
        sort(staple.begin(), staple.end(), less<int>());
        sort(drinks.begin(), drinks.end(), less<int>());
        int index = 0;
        int ans = 0;
        while (index < staple.size()) {
            if (staple[index] >= x) break;
            int num = bfind(x - staple[index], drinks);
             ans += (num % (int)(1e9 + 7));
            index++;
        }
        return ans % (int)(1e9 + 7);
    }
};