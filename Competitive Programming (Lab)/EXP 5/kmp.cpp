#include <iostream>
#include <string>

using namespace std;

void computeLPSArray(string pattern, int lps[]) {
    int m = pattern.size();
    int len = 0;
    int i = 1;
    lps[0] = 0;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int KMP(string text, string pattern) {
    int n = text.size();
    int m = pattern.size();
    int lps[m];
    int count = 0;

    computeLPSArray(pattern, lps);

    int i = 0; // index for text
    int j = 0; // index for pattern

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            // cout << "Pattern found at index: " << i - j << endl;
            count++;
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return count;
}

int main() {
    string text = "sadasda";
    string pattern = "sda";
    cout << "Text: " << text << endl;
    cout << "Pattern: " << pattern << endl;
    cout << "Number of Occurences: ";
    int x = KMP(text, pattern);
    cout<<x<<endl;
    return 0;
}