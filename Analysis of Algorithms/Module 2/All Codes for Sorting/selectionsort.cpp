#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void selectionsort(int arr [],int n)
{
    int min;
    int j;
    for(int i=0;i<n;i++)
    {
        min = i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min])
            {
                min = j;
            }
            swap(arr[i],arr[min]);
        }
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
    selectionsort(arr,size);
    cout<<"After Sorting: ";
    print(arr,size);
    
}