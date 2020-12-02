class Solution {
public:

    vector<int> getnum(vector<int>& v, int i) {
        if (i == 0) return {};
        if (v.size() == i) return v;
        vector<int> ans(i, 0);
        int size = v.size();
        int drop_num = size - i;
        int count = 0;
        stack<int> q;
        int index = 0;
        bool flag = false;
        while (index < size) {
            if (q.empty()) q.push(v[index]);
            else {
                if (!flag) {
                    while (!q.empty() && v[index] > q.top()) {
                        q.pop();
                        count++;
                        if (count == drop_num) {
                            flag = true;
                            break;
                        }
                    }
                    q.push(v[index]);
                }
                else q.push(v[index]);
            }
            index++;
        }
        while (count < drop_num) {
            q.pop();
            count++;
        }
        for (auto j = i - 1; j >= 0; --j) {
            ans[j] = q.top();
            q.pop();
        }
        return ans;
    }

    vector<int> merge(vector<int>& v1, vector<int>& v2) {
        vector<int> ans;
        int index1 = 0, index2 = 0;
        while (index1 < v1.size() && index2 < v2.size()) {
            if (v1[index1] > v2[index2]) {
                ans.push_back(v1[index1]);
                index1++;
            }
            else if (v1[index1] == v2[index2]) {
                int n1 = index1, n2 = index2;
                int num1 = v1[n1], num2 = v2[n2];
                while (num1 == num2) {
                    num1 = n1 + 1 >= v1.size() ? -1 : v1[n1 + 1];
                    num2 = n2 + 1 >= v2.size() ? -1 : v2[n2 + 1];
                    if (num1 == -1 && num2 == -1) {
                        ans.push_back(v1[index1]);
                        index1++;
                        break;
                    }
                    if (num1 > num2) {
                        ans.push_back(v1[index1]);
                        index1++;
                        break;
                    }
                    else if (num1 < num2) {
                        ans.push_back(v2[index2]);
                        index2++;
                        break;
                    }
                    else {
                        n1++;
                        n2++;
                    }
                }
            }
            else {
                ans.push_back(v2[index2]);
                index2++;
            }
        }
        while (index1 < v1.size()) {
            ans.push_back(v1[index1]);
            index1++;
        }
        while (index2 < v2.size()) {
            ans.push_back(v2[index2]);
            index2++;
        }
        return ans;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ans(k, 0);
        for (auto i = 0; i <= k; ++i) {
            if (nums1.size() < i) break;
            if (nums2.size() < k - i) continue;
            vector<int> num1 = getnum(nums1, i);
            vector<int> num2 = getnum(nums2, k - i);
            ans = max(ans, merge(num1, num2));
        }
        return ans;
    }
};