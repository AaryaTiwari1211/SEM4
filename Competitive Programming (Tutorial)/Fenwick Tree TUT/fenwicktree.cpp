#include <iostream>
#include <vector>

using namespace std;

class FenwickTree {
    private:
        vector<int> tree;
        int size;

    public:
        FenwickTree(int n) {
            size = n;
            tree.resize(n + 1);
        }

        void update(int i, int delta) {
            while (i <= size) {
                tree[i] += delta;
                i += i & -i;
            }

            cout<<endl;
        }

        int query(int i) {
            int sum = 0;
            while (i > 0) {
                sum += tree[i];
                i -= i & -i;
            }
            return sum;
        }

        int query(int i, int j) {
            return query(j) - query(i - 1);
        }
};

int main() {
    int n, q;
    cout<<"Enter size of array: ";
    cin >> n;
    cout<<"Enter number of queries: ";
    cin>>q;
    FenwickTree ft(n);

    for (int i = 1; i <= n; i++) {
        int val;
        cout<<"Enter element "<<i<<": ";
        cin >> val;
        cout<<endl;
        ft.update(i, val);
    }
    cout<<"\n";
    while (q--) {
        cout<<"Query "<<q<<"---";
        int type, i, j;
        cout<<"Enter query type: \n1. Update Value \n2. Sum of range \nChoose option: ";
        cin >> type;
        
        if (type == 1) {
            cout<<"Enter index to replace: ";
            cin>>i;
            cout<<"Enter element to replace: ";
            cin>>j;
            ft.update(i, j);
            cout<<"Update successful";
        } else {
            cout<<"Enter start index of range: ";
            cin>>i;
            cout<<"Enter end index of range: ";
            cin>>j;
            cout <<"The sum of the given range is: "<< ft.query(i, j) << "\n";
        }
        cout<<endl;
    }

    return 0;
}
