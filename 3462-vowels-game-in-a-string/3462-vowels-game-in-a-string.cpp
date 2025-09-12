class Solution {
public:
    bool doesAliceWin(const string& s) {
        static const bool isVowel[256] = {
            ['a'] = true, ['e'] = true, ['i'] = true, ['o'] = true, ['u'] = true
        };

        for (char ch : s) {
            if (isVowel[(unsigned char)ch]) return true;
        }
        return false;
    }
};
