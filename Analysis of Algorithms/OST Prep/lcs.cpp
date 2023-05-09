#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;

int LCS(string X , string Y)
{
    int m = X.length();
    int n = Y.length();
    int c[m+1][n+1];
    for(int i = 0;i<=m;i++)
    {
        for(int j = 0;j<=n;j++)
        {
            if(i==0||j==0)
            {
                c[i][j]=0;
            }
            else if(X[i-1]==Y[j-1])
            {
                c[i][j] = c[i-1][j-1] + 1;
            }
            else{
                c[i][j] = max(c[i][j-1] , c[i-1][j]);
            }
        }
    }
    return c[m][n];
}

int main()
{
    string str1;
    string str2;

    cout<<"Enter string 1: ";
    cin>>str1;
    cout<<"Enter string 2: ";
    cin>>str2;
    int lcs = LCS(str1,str2);
    cout<<"The length of LCS is: "<<lcs;
}
// #include <bits/stdc++.h>
// #include <string>
// using namespace std;

// int LCS(string x, string y)
// {
//     int m = x.length();
//     int n = y.length();
//     int c[m + 1][n + 1];

//     for (int i = 0; i <= m; i++)
//     {
//         for (int j = 0; j <= n; j++)
//         {
//             if(i==0 || j==0)
//             {
//                 c[i][j] = 0;
//             }
//             else if(x[i - 1] == y[j - 1])
//             {
//                 c[i][j] = c[i - 1][j - 1] + 1;
//             }
//             else
//             {
//                 c[i][j] = max(c[i][j - 1], c[i - 1][j]);
//             }
//         }
//     }
//     return c[m][n];
// }

// int main()
// {
//     string x, y;
//     cin >> x >> y;

//     int lcsLength = LCS(x, y);

//     cout << "The length of the longest common subsequence is " << lcsLength << endl;

//     return 0;
// }