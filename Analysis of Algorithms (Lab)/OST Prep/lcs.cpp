#include<bits/stdc++.h>
#include<string>
using namespace std;

string LCS (string M , string N)
{
    int m = M.size();
    int n = N.size();

    int arr[m+1][n+1];
    // for(int i = 0;i<=m;i++)
    // {
    //     for(int j = 0;j<=n;j++)
    //     {
    //         arr[i][j] = 0;
    //     }
    // }
    for(int i = 0;i<=m;i++)
    {
        for(int j = 0;j<=n;j++)
        {
            if(i==0 || j==0)
            {
                arr[i][j]=0;
            }
            else if(M[i-1]==N[j-1])
            {
                arr[i][j] = arr[i-1][j-1] + 1;
            }
            else
            {
                arr[i][j] = max(arr[i-1][j] , arr[i][j-1]);            
            }
        }
    }
    string lcs = "";
    int i = m;
    int j = n;
    while(i>=0 && j>=0)
    {
        if(M[i-1]==N[j-1])
        {
            lcs = M[i-1] + lcs;
            i--;
            j--; 
        }
        else if(arr[i-1][j] > arr[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    // return arr[m][n];
    return lcs;
}

int main()
{
    string s1 , s2;
    cout<<"Enter string 1: ";
    cin>>s1;
    cout<<"Enter string 2: ";
    cin>>s2;
    string x = LCS(s1,s2);
    cout<<"The longest common subsequence is: "<<x;
}