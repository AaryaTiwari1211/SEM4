#include<iostream>
using namespace std;

void selectionSort(int arr[] , int size)
{
    for(int i = 0;i<size;i++)
    {
        int minindex = i;
        int min = arr[i];
        for(int j = i + 1;j<size;j++)
        {
            if(arr[j]<min)
            {
                minindex = j;
                min = arr[j];
            }
        }
        swap(arr[i] , arr[minindex]);
    }
}

int main()
{
    int arr[5] = {1,4,3,2,5};
    selectionSort(arr,5);
    for(int i = 0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
}