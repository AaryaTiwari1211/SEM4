#include <iostream>
using namespace std;
int main() 
{
    int n;
    cin>>n;
    int arr[n];
    if(n>=1)
    {
        for(int i=0;i<n;i++)
        {
            
            cin>>arr[i];
            
            
        }
        if((arr[n-1]%10)==0)
        {
            cout<<"Yes";
        }
        else
        {
            cout<<"No";
        }
    }
    
    return 0;
}
