#include <iostream>
#include <cstring>
using namespace std;

bool search(char text[], char pattern)
{
    for (size_t i = 0; i < strlen(text); i++)
    {
        if (text[i] == pattern)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    char text[20];
    char pattern;
    cout << "Enter text: ";
    cin >> text;
    cout << "Enter pattern: ";
    cin >> pattern;
    bool x = search(text , pattern);
    if(x)
    {
        cout<<"Match Found";
        cout<<endl;
    }
    else{
        cout<<"Error";
        cout<<endl;
    }
}