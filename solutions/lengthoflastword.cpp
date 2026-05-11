class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        int save = -1;
        if (s.size() == 1 && s[0] != ' ') return 1;
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == ' ' && s[i + 1] != ' ') {
                save = i;
            }
        }
        for (int j = save + 1; j < s.size(); j++) {
            if (s[j] != ' ') count++;
        }

        return count;
    }
};
