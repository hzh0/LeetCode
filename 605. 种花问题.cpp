class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cap = 0;
        int size = flowerbed.size();
        if (size == 1) {
            if (flowerbed[0] == 1) {
                if (n == 0) {
                    return true;
                }
                return false;
            } 
            return true;
        }
        if (n > size / 2 + 2) {
            return false;
        }
        if (flowerbed[1] == 0 && flowerbed[0] == 0) {
            flowerbed[0] = 1;
            cap++;
            if (cap >= n) {
                return true;
            }
        }
        for (auto i = 1; i < size-1; ++i) {
            if (flowerbed[i-1] == 0 && flowerbed[i+1] == 0 && flowerbed[i] == 0) {
                flowerbed[i] = 1;
                cap++;
                if (cap >= n) {
                    return true;
                }
            }
        }
        if (flowerbed[size-2] == 0 && flowerbed[size-1] == 0) {
            cap++;
            if (cap >= n) {
                return true;
            }
        }
        if (cap >= n) {
            return true;
        }
        return false;

    }
};