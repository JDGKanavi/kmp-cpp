class Solution {
public:
    int strStr(string haystack, string needle) {
        int i1 = 0,i2 = 0;
        vector<int> next = get_next(needle);
        while (i1 < haystack.size() && i2 < needle.size()) {
            if (haystack[i1] == needle[i2]) {
                i1++;
                i2++;
            }else if (i2 != 0) {
                i2 = next[i2];
            }else {
                i1++;
            }
        }
        return i2 == needle.size() ? i1 - i2 : -1;
    }

private:
    vector<int> get_next(string s){
        vector<int> next(s.size(),0);
        if (s.size() == 1){
            return {-1};
        }
        next[0] = -1;
        next[1] = 0;
        int i = 2;
        int cn = 0; //cn既代表需要比对的index，也是next[i-1]的值
        while (i < s.size()) {
            if (s[i - 1] == s[cn]) {
                next[i++] = ++cn;
            }else if (cn != 0) {
                cn = next[cn];
            }else {
                next[i++] = 0;
            }
        }
    return next;
    }
};
//change1
//change 2
//change 5
