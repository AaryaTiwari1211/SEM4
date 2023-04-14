#include <bits/stdc++.h>

using namespace std;

int main()

{

    int t;

    cin >> t;

    while (t--)

    {

        string s;

        cin >> s;

        int n1 = 0;

        int n2 = 0;

        sort(s.begin(), s.end());

        int i = 0;

        while (i < s.size())

        {

            if (i % 2 == 0)

                n1 = n1 * 10 + s[i] - '0';

            else

                n2 = n2 * 10 + s[i] - '0';

            i++;
        }

        cout << n1 + n2 << endl;
    }

    return 0;
}