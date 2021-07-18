#include <iostream> 
#include <string> 
#include <vector> 
#include <cstring> 
using namespace std; 
enum { 
    PALINDROME = 0, SEMI_PALINDROME, NOT_PALINDROME 
}; 
int main(void) { 
    ios_base::sync_with_stdio(0); cin.tie(0); 
    int T; cin >> T; 
    for (int t = 0; t < T; t++) { 
        string s; cin >> s; 
        int result = PALINDROME; 
        for (int i = 0, j = s.length() - 1; i < j; i++, j--) { 
            if (s[i] == s[j]) { 
                continue; 
            } 

            if (s[i + 1] != s[j] && s[i] != s[j - 1]) { 
                result = NOT_PALINDROME; 
                break; 
            } 
            bool isPalindrome = false; 

            for (int k = 0; k < 2 && isPalindrome == false; k++) { 
                int start = i; 
                int end = j; 
                k == 0 ? start++ : end--; 
                isPalindrome = true; 
                for (int a = start, b = end; a < b; a++, b--) { 
                    if (s[a] != s[b]) { 
                        isPalindrome = false; 
                        break; 
                    } 
                }
            } 
            result = isPalindrome ? SEMI_PALINDROME : NOT_PALINDROME; 
            break; 
        } 
        cout << result << "\n"; 
    } 
    return 0; 
}
