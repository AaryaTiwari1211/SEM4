#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    if(arr[n-1]%10==0)
    {
        cout<<"Yes it is divisible by 10";
    }
    else{
        cout<<"No it is not divisible by 10";
    }
}
