#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    map<char, int> count;
    for (char c : str) {
        count[c]++;
    }

    cout << "Number of occurrences of each character in the string: " << endl;
    for (auto it = count.begin(); it != count.end(); it++) {
        cout << it->first << " : " << it->second <<" time"<< endl;
    }

    return 0;
}
