#include <vector>
#include <string>
#include <iostream>

std::vector<int> prefixFunction(std::string s) {
    int n = (int) s.length();
    std::vector<int> pi(n);
    for (int i = 1; i < s.length(); i++) {
        int j = pi[i - 1];
        while ((j > 0) && (s[i] != s[j])) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            pi[i] = j + 1;
        } else {
            pi[i] = j;
        }
    }
    return pi;
}

int main() {
    std::string p, t;
    std::cin >> p >> t;
    std::vector<int> pi = prefixFunction(p + '#' + t);
    int len = p.size();
    std::vector<int> ans;
    for (int i = 0; i < t.length(); i++) {
        if (pi[len + 1 + i] == len) {
            ans.push_back(i - len + 2);
        }
    }

    std::cout << ans.size() << std::endl;
    for (int i : ans) {
        std::cout << i << ' ';
    }
}