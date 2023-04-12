#include<iostream>
using namespace std;

void countingsort(int arr [], int n)
{
    int key;
    int j;
    for(int i = 1; i < n;i++)
    {
        key = arr[i];
        j = i - 1;
        while(arr[j]>key && j>0)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void print(int arr [],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int size;
    cout<<"Enter Size: ";
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++)
    {
        cout<<"Enter the elements: ";
        cin>>arr[i];
    }
    cout<<"Before Sorting: ";
    print(arr,size);
    cout<<endl;
    countingsort(arr,size);
    cout<<"After Sorting: ";
    print(arr,size);
    
}