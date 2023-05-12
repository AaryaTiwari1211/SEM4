#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int start ,int mid , int end){
    // int mid = start + end /2;
    int s1 = mid - start + 1;
    int s2 = end - mid ;
    int arr1[s1];
    int arr2[s2];
    for(int i = 0 ; i < s1 ; i++){
        arr1[i] = arr[start + i];
    }
    for(int i = 0 ; i < s1 ; i++){
        arr2[i] = arr[mid + 1 + i];
    }

    int i=0 , j=0 ;
    int k = start;
    while(i<s1 && j <s2){
        if(arr1[i]<=arr2[j]){
            arr[k] = arr1[i];
            i++;
        }
        else{
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }

    while(i<s1){
        arr[k] = arr1[i];
        i++;
        k++;
    }
    while(j<s2){
        arr[k] = arr2[j];
        j++;
        k++;
    }

}

void mergesort(int arr[], int start , int end){
    if (start < end ){
        int mid = (start + end) /2;
        mergesort(arr,start, mid);
        mergesort(arr,mid+1,end);
        merge(arr,start,mid,end);
    }
}
void print(int arr[] , int size){
    for(int i=0 ; i<size ; i++){
        cout<<arr[i]<<" ";
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
    mergesort(arr , 0 , n -1 );
    print(arr,n);
}
