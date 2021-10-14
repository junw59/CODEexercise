class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int c = 0;
        int ck = 0;
        while (c < g.size() && ck < s.size()){
            if (g[c] <= s[ck]) c++;
            ck++;
        }

        return c;
    }
};