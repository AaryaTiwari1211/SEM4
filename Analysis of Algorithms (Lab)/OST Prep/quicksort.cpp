#include<bits/stdc++.h>
using namespace std;

int partition(int arr[] , int low,int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low;j<high;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i + 1;
}

void quickSort(int arr[] , int low,int high)
{
    if(low<high)
    {
        int pivot = partition(arr,low,high);
        quickSort(arr,low,pivot-1);
        quickSort(arr,pivot+1,high);
    }
}

int main()
{
    int arr[6] = {1,4,3,2,5,6};
    quickSort(arr,0,5);
    for(int i=0;i<6;i++)
    {
        cout<<arr[i]<<" ";
    }
}
