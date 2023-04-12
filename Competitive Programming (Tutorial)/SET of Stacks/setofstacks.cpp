#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    int capacity, choice;
    vector<stack<int>> SetofStacks;

    cout << "Enter the capacity of each stack: ";
    cin >> capacity;

    while (true) {
        cout<<"Welcome to the Set of Stacks!!";
        cout << "\n1. Push element onto the set of stacks";
        cout << "\n2. Pop element from the set of stacks";
        cout << "\n3. Display all stacks";
        cout << "\n4. Display top element";
        cout << "\n5. Quit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int value;
            if (SetofStacks.empty() || SetofStacks.back().size() == capacity) {
                SetofStacks.push_back(stack<int>());
            }
            cout << "Enter the element to be pushed: ";
            cin >> value;
            SetofStacks.back().push(value);
            break;
        }
        case 2: {
            if (SetofStacks.empty()) {
                cout << "The set of stacks is empty!\n";
            }
            else {
                SetofStacks.back().pop();
                if (SetofStacks.back().empty()) {
                    SetofStacks.pop_back();
                }
            }
            break;
        }
        case 3: {
            if (SetofStacks.empty()) {
                cout << "The set of stacks is empty!\n";
            }
            else {
                for (auto &s : SetofStacks) {
                    stack<int> temp = s;
                    cout << "Stack:";
                    while (!temp.empty()) {
                        cout << " " << temp.top();
                        temp.pop();
                    }
                    cout << endl;
                }
            }
            break;
        }
        case 5: {
            cout << "Quitting program...\n";
            return 0;
        }
        case 4: 
        {
            cout<<"The element at the top is: "<<SetofStacks.back().top()<<endl;
            break;
        }
        default: {
            cout << "Invalid choice, please try again.\n";
            break;
        }
        }
    }
    return 0;
}