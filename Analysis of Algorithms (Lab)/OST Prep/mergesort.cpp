#include<bits/stdc++.h>
#include <iostream>
using namespace std;

void print(int arr[],int size){
    for(int i = 0 ; i<size ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void merge(int arr[] , int start , int mid , int end)
{
    int ls1 = mid-start+1;
    int ls2 = end - mid;

    int s1[ls1];
    int s2[ls2];

    for(int i=0;i<ls1;i++)
    {
        s1[i] = arr[start + i];
    }
    for(int j = 0;j<ls2;j++)
    {
        s2[j] = arr[mid+j+1];
    }
    int i = 0;
    int j = 0;
    int k = start;
    while(i<ls1 && j<ls2)
    {
        if(s1[i]>=s2[j])
        {
            arr[k] = s1[i];
            i++;
        }
        else
        {
            arr[k] = s2[j];
            j++;
        }
        k++;
    }
    while(i<ls1)
    {
        arr[k] = s1[i];
        i++;
        k++;
    }
    while(i<ls1)
    {
        arr[k] = s1[i];
        i++;
        k++;
    }

}


void mergeSort(int arr[],int left , int right){
    if(left < right){
        int mid = (left + right)/2;
        mergeSort(arr , left ,mid);
        mergeSort(arr , mid + 1 , right);
        merge(arr,left,mid,right);
    }
}

int main(){
    int n;
    cout<<"size of array :";
    cin>>n;
    int arr[n];
    cout<<"enter values of array ";
    for(int i = 0 ;i < n ;i++){
        cin>>arr[i];
    }
    mergeSort(arr , 0 , n -1 );
    print(arr,n);
}