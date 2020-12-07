class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        if (arr.size() <=1) return;
        int index = arr.size() - 1;
        while (index >= 0) {
            if (arr[index] == 0) {
                for (int i = arr.size() - 1; i > index; --i) arr[i] = arr[i - 1];
            }
            index--;
        }
    }
};

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int count = 0;
        for (auto i : arr) if (i == 0) count++;
        for (int i = arr.size() - 1; i >= 0; --i) {
            if (arr[i] == 0) {
                if (i + count <= arr.size()-1) arr[i + count] = 0;
                if (i + count-1 <= arr.size() - 1) arr[i + count - 1] = 0;
                  
            count--;
            }
            else {
                if (i + count >= arr.size()) continue;
                arr[i + count] = arr[i];
            }
             
        }
    }
};