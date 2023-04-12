#include <iostream>
#include<stdlib.h>
#include<bits.h>
using namespace std;
void printarr(int arr[]){
    for(int i = 0;i<7;i++){
        cout<<arr[i]<<" ";
    }
}
int main() 
{
    int arr[7] = {2,4,NULL,8,10,NULL,14};
    cout<<"The array before filling null values: ";
    printarr(arr);
    for(int i = 0;i<7;i++){
        if(arr[i] == NULL){
            arr[i] = 2*(i+1);
        }
    }
    cout<<endl;
    cout<<"The array after filling the null values: ";
    printarr(arr);
    return 0;
}