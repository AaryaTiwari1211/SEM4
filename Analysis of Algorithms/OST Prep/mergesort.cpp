#include<bits/stdc++.h>
#include <iostream>
using namespace std;

void print(int arr[],int size){
    for(int i = 0 ; i<size ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    // cout<<endl;
}
void merge(int arr[] , int start , int mid , int end){
    // create two arrays like a[start to mid] and a[mid+1 to end]
    int lengthOfSubarrayone = mid - start + 1;
    int lenghtOfSubarraytwo = end - mid;

    int subarrayone[lengthOfSubarrayone];
    int subarraytwo[lenghtOfSubarraytwo];

    for(int i = 0 ; i < lengthOfSubarrayone ; i++){
        subarrayone[i] = arr[start + i];
    }
    for(int j = 0 ; j < lenghtOfSubarraytwo ; j++){
        subarraytwo[j] = arr[mid + 1 + j];
    }
    int i = 0;
    int j = 0;
    int k = start;
    while(i < lengthOfSubarrayone && j < lenghtOfSubarraytwo){
        if(subarrayone[i] <= subarraytwo[j]){
            arr[k] = subarrayone[i];
            i++;
        }
        else{
            arr[k] = subarraytwo[j];
            j++;
        }
        k++;
    }
    while(i < lengthOfSubarrayone){
        arr[k] = subarrayone[i];
        i++;
        k++;
    }
    while(j < lenghtOfSubarraytwo){
        arr[k] = subarraytwo[j];
        j++;
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