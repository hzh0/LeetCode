class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int index = A.size() - 1;
        vector<int> ans;
        int carry = 0;
        int num;
        while (index >= 0 && K != 0) {
            num = A[index] + K % 10 + carry;
            ans.push_back(num % 10);
            carry = num / 10;
            K /= 10;
            index--;
        }
        while (index >= 0) {
            num = A[index] + carry;
            ans.push_back(num % 10);
            carry = num / 10;
            index--;
        }
        while (K != 0) {
            num = K%10 + carry;
            ans.push_back(num % 10);
            carry = num / 10;
            K /= 10;
        }
        if (carry) ans.push_back(1);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};