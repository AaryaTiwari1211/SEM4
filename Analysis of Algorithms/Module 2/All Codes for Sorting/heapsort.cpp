#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void heapify(int arr [],int n, int i)
{
    int l , r;
    int largest = i;
    l = 2*i+1;
    r = 2*i+2;

    if(l < n && arr[largest] < arr[l])
    {
        largest = l;
    }
    if(r < n && arr[largest] < arr[r])
    {
        largest = r;
    }
    if(largest!=i)
    {
        swap(arr[i],arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapsort(int arr [],int n)
{
    for(int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr,n,i);
    }
    for (int i = n - 1; i >= 0; i--) 
    {
        swap(arr[0],arr[i]);
        heapify(arr, i, 0);
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
    heapsort(arr,size);
    cout<<"After Sorting: ";
    print(arr,size);
    
}