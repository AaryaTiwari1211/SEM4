#include<iostream>
#include<vector>
using namespace std;

int sum(vector<int> &freq , int start,int end)
{
    int s = 0;
    for(int i=start;i<=end;i++)
    {
        s+=freq[i];
    }
    return s;
}

int obst(vector<int> &keys,vector<int> &freq,int n)
{
    vector<vector<int>> cost(n+1 , vector<int>(n+1,0));
    for(int i = 0;i<n;i++)
    {
        cost[i][i] = freq[i];
    }
    for(int L = 2; L<=n ; L++)
    {
        for(int i=0;i<n-L+1;i++)
        {
            int j = i + L - 1;
            cost[i][j] = INT_MAX;
            for(int r = i; r<=j;r++)
            {
                int c;
                if(r>i && r<j)
                {
                    c = cost[i][r-1] + cost[r+1][j] + sum(freq,i,j);
                }
                else if(r>i)
                {
                    c = cost[i][r-1] + sum(freq,i,j);
                }
                else if(r<j)
                {
                    c = cost[r+1][j] + sum(freq,i,j);
                }
                else
                {
                    c = freq[r];
                }
                if(c<cost[i][j])
                {
                    cost[i][j] = c;
                    keys[i] = r;
                }
            }
        }
    }
    return cost[0][n-1];
}

int main() {
    vector<int> keys = {10,20,30,40};
    vector<int> freq = {4,2,6,3};
    int n = keys.size();
    int cost = obst(keys ,freq, n);
    cout << "The cost of optimal binary search tree is " << cost << endl;
    return 0;
}

