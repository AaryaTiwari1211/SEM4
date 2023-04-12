#include <iostream>
using namespace std;
void printarr(int arr[],int size)
{
    for(int i = 0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main() {
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter element "<<i+1<<" : ";
        cin>>arr[i];
    }
    for(int i = 0;i<n;i++)
    {
        int remain;
        int reverse = 0;
        if(i%2==0)
        {
            if(arr[i]%2!=0)
            {
                while(arr[i]!=0)
                {
                    remain = arr[i]%10;
                    reverse = reverse*10 + remain;
                    arr[i] = arr[i]/10;
                }
                arr[i] = reverse;
            }
            else{
                continue;
            }
        }
        else
        {
            if(arr[i]%2==0)
            {
                while(arr[i]!=0)
                {
                    remain = arr[i]%10;
                    reverse = reverse*10 + remain;
                    arr[i] = arr[i]/10;
                }
                arr[i] = reverse;
            }
            else{
                continue;
            }
        }
    }
    printarr(arr,n);
    return 0;
}