#include <unordered_map>
using namespace std;
    unordered_map<char, char> bracketMap = {{'(', ')'}, {'{', '}'}, {'[', ']'}};
    bool matches(char top, char value) {
        if (bracketMap[top] == value) {
            return true;
        } else {
            return false;
        }
    }
bool isValidParenthesis(string s) {
    stack<char> st;
    int i = 0;
    while (i < s.size()) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            st.push(s[i]);
        } else {
            if (!st.empty()) {
                if (matches(st.top(), s[i])) {
                    st.pop();
                } else {
                    st.push(s[i]);
                }
            } else {
                return false;
            }
        }
        i++;
    }
    if (st.empty()) {
        return true;
    } else {
        return false;
    }
}
