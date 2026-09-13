class Solution {
public:
    bool isValid(string s) {
        stack<char> records;
        for (int i = 0 ; i < s.size(); i++) {
            char curr = s[i];
            if (curr == '(' || curr == '{' || curr == '[') {
                records.push(curr);
            }
            else if (curr ==')') {
                if (!records.empty() && records.top() == '('){
                    records.pop();
                }
                else return false;
            }
            else if (curr ==']') {
                if (!records.empty() && records.top() == '['){
                    records.pop();
                }
                else return false;
            }
            else if (curr =='}') {
                if (!records.empty() && records.top() == '{'){
                    records.pop();
                }
                else return false;
            }
        }
        return records.empty();
    }
};
