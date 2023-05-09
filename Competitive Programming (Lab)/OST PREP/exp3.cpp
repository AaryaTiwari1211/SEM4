#include <bits/stdc++.h>
using namespace std;

int prefixSum(int arr[] , int i)
{
    int sum = 0;
    while(i>0)
    {
        sum = sum + arr[i];
        i = i - (i & -i);
    }
    return sum;
}

void update(int arr[],int n,int i , int val)
{
    i = i + 1;
    while(i<=n)
    {
        arr[i] = arr[i] + val;
        i = i + (i&-i);
    }
}

int *construct(int arr[] , int n)
{
    int *BITree = new int[n+1];
    for (int i=1; i<=n; i++)
        BITree[i] = 0;
    for (int i=0; i<n; i++)
        update(BITree, n, i, arr[i]);
    return BITree;
}

int main()
{
    int n;
    cout<<"Enter size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements: ";
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }
    int *BITree = construct(arr, n);
    int sum = prefixSum(BITree , n-1);
    cout<<sum;
}