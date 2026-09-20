class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int res = students.size();
        vector<int> cnt(2);
        for (int& student : students) {
            cnt[student]++;
        }

        for (int& s : sandwiches) {
            if (cnt[s] > 0) {
                cnt[s]--;
                res--;
            } else {
                break;
            }
        }
        return res;
    }
};