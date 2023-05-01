#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    cout<<"Enter the string: ";
    cin>>str;
    int size = str.length();
    char ch;
    cout<<"Enter the character you want to delete: ";
    cin>>ch;
    for(int i=0;i<size;i++)
    {
        if(str[i]==ch)
        {
            str.erase(i,1);
        }
    }
    cout<<"String after erasing the character is: "<<str<<endl;
    return 0;
}
