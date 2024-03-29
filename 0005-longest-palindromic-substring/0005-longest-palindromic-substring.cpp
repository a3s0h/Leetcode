// class Solution {
// public:
//     std::string longestPalindrome(std::string s) {
//         if (s.length() <= 1) {
//             return s;
//         }
        
//         int max_len = 1;
//         std::string max_str = s.substr(0, 1);
        
//         for (int i = 0; i < s.length(); ++i) {
//             for (int j = i + max_len; j <= s.length(); ++j) {
//                 if (j - i > max_len && isPalindrome(s.substr(i, j - i))) {
//                     max_len = j - i;
//                     max_str = s.substr(i, j - i);
//                 }
//             }
//         }

//         return max_str;
//     }

// private:
//     bool isPalindrome(const std::string& str) {
//         int left = 0;
//         int right = str.length() - 1;
        
//         while (left < right) {
//             if (str[left] != str[right]) {
//                 return false;
//             }
//             ++left;
//             --right;
//         }
        
//         return true;
//     }
// };

// better approach

// class Solution {
// public:
//     std::string longestPalindrome(std::string s) {
//         if (s.length() <= 1) {
//             return s;
//         }

//         auto expand_from_center = [&](int left, int right) {
//             while (left >= 0 && right < s.length() && s[left] == s[right]) {
//                 left--;
//                 right++;
//             }
//             return s.substr(left + 1, right - left - 1);
//         };

//         std::string max_str = s.substr(0, 1);

//         for (int i = 0; i < s.length() - 1; i++) {
//             std::string odd = expand_from_center(i, i);
//             std::string even = expand_from_center(i, i + 1);

//             if (odd.length() > max_str.length()) {
//                 max_str = odd;
//             }
//             if (even.length() > max_str.length()) {
//                 max_str = even;
//             }
//         }

//         return max_str;
//     }
// };

// dp approach
class Solution {
public:
    std::string longestPalindrome(std::string s) {
        int n =s.size();
        if(n<=1) return s;
        
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        int start = 0;
        int end = 0;
        int max_len = 1;
        
        for(int i =0;i<n;i++)
        {
            dp[i][i] = true;
            for(int j =0;j<i;j++)
            {
                if(s[j] == s[i] && (i-j <=2 || dp[j+1][i-1]))
                {
                    dp[j][i] = true;
                    if(i-j+1 > max_len)
                    {
                        max_len = i-j+1;
                        start = j;
                        end = i;
                    }
                }
            }
        }
        return s.substr(start , end - start +1 );
    }
};