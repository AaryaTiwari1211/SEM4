#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool isPalindrome(string str, int left, int right)
{
    while (left < right)
    {
        if (str[left++] != str[right--])
        {
            return false;
        }
    }
    return true;
}
vector<string> allPalindromes(string str)
{
    vector<string> result;
    for (int i = 0; i < str.length(); i++)
    {
        for (int j = i; j < str.length(); j++)
        {
            if (isPalindrome(str, i, j))
            {
                if(i!=j)
                {
                    if(i+1!=j)
                    {
                        result.push_back(str.substr(i, j - i + 1));
                    }
                }
            }
        }
    }
    return result;
}
int main()
{
    string str;
    cout << "Enter a string: ";
    cin >> str;
    vector<string> palindromes = allPalindromes(str);
    cout << "All palindromes in the given string (3 letters and more): " << endl;
    for (string s : palindromes)
    {
        cout << s << endl;
    }
    for (string s : palindromes)
    {
        cout<<"\n";
        cout<<"Current s: "<<s<<endl;
        size_t found = str.find(s);
        if(found!=string::npos)
        {
            str.erase(found,s.length());
        }
        
        cout<<" String after removing s: "<<str<<endl;
        cout<<"\n";
    }
    return 0;
}