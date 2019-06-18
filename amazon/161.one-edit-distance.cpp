class Solution {
    public:
        bool isOneEditDistance(string s, string t) {
            return method2(s, t);
        }

        /******************************************************************************
        * Function:         bool method1
        * Description:      
        * Where:
        * Return:           
        * Error:            
        *****************************************************************************/
        bool method1(string s, string t){
            if (s.size() < t.size()) {
                swap(s, t);
            }
            int m = s.size(), n = t.size(), diff = m - n;
            if (diff >= 2) {
                return false; 
            } else if (diff == 1) {
                for (int i = 0; i < n; ++i) {
                    if (s[i] != t[i]) {
                        return s.substr(i + 1) == t.substr(i); 
                    }
                }
            } else {
                int cnt = 0;
                for (int i = 0; i < m; ++i) {
                    if (s[i] != t[i]) {
                        ++cnt;
                    }
                }
                return cnt == 1;
            }
        }

        /******************************************************************************
        * Function:         bool method2
        * Description:      
        * Where:
        * Return:           
        * Error:            
        *****************************************************************************/
        bool method2(string word1, string word2){
            for (int i = 0; i < min(word1.size(), word2.size()); ++i) {
                if (word1[i] != word2[i]) {
                   if (word1.size() == word2.size()) {
                       return word1.substr(i + 1) == word2.substr(i + 1);
                   } else if (word1.size() < word2.size()) {
                       return word1.substr(i) == word2.substr(i + 1);
                   } else {
                       return word1.substr(i + 1) == word2.substr(i);
                   }
                }
            }
            return abs((int) word1.size() - (int)word2.size()) == 1;
        }
};
