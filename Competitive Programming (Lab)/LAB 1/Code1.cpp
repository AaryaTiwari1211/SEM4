#include <iostream>
#include<string.h>
using namespace std;
void printarray(char arr[],int size)
{
    for (int i=0;i<size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}
int main() {
    char arr[50];
    char arrnum[50];
    char arrchar[50];
    char arrspecial[50];
    int i=0;
    int j=0;
    int k=0;
    int l=0;
    cout<<"Enter a string: ";
    cin>>arr;
    int size = sizeof(arr) / sizeof(arr[0]);
    for(i,j,k,l;i<size;i++)
    {
        if(int(arr[i])>=48 && int(arr[i])<=57)
        {
            arrnum[j] = arr[i];
            j++;
        }
        else if((int(arr[i])>=65 && int(arr[i])<=90)||(int(arr[i])>=97 && int(arr[i])<=122))
        {
            arrchar[k] = arr[i];
            k++;
        }
        else
        {
            arrspecial[l] = arr[i];
            l++;
        }
    }
    cout<<"The Numbers are : ";
    printarray(arrnum,strlen(arrnum));
    cout<<endl;
    cout<<"The Characters are : ";
    printarray(arrchar,strlen(arrchar));
    cout<<endl;
    cout<<"The Symbols are : ";
    printarray(arrspecial,strlen(arrspecial));
    cout<<endl;
    return 0;
}