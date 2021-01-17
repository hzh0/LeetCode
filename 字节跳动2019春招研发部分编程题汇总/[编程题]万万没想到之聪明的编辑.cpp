#include <iostream>
#include <string>

using namespace std;

string func(string& s) {
    string ans;
    if (s.size() <= 2) {
        return s;
    }
    ans = ans + s[0] + s[1];
    for (auto i = 2; i < s.size(); ++i) {
        if (s[i] == ans[ans.size()-1] && s[i] == ans[ans.size()-2]) {
            continue;
        }
        if (ans.size() >=3 && s[i] == ans[ans.size()-1] && ans[ans.size()-2] == ans[ans.size()-3]) {
            continue;
        }
        ans += s[i];
    }
    return ans;
}

int main(void) {
    int count;
    string s;
    cin >> count;
    for (auto i = 0; i < count; ++i) {
        cin >> s;
        cout << func(s) << endl;
    }
    return 0;
}