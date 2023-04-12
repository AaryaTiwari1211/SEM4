#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e5+5;
int a[MAXN], seg[4*MAXN];

void build(int i, int l, int r) {
    if (l==r) {
        seg[i]=a[l];
        return;
    }
    int m=l+(r-l)/2;
    build(i*2, l, m);
    build(i*2+1, m+1, r);
    seg[i]=seg[i*2]+seg[i*2+1];
}

int query(int i, int l, int r, int ql, int qr) {
    if (r<ql || qr<l) return 0;
    if (ql<=l && r<=qr) return seg[i];
    int m=l+(r-l)/2;
    return query(i*2, l, m, ql, qr)+query(i*2+1, m+1, r, ql, qr);
}

void update(int i, int l, int r, int idx, int val) {
    if (l==r) {
        seg[i]=val;
        return;
    }
    int m=l+(r-l)/2;
    if (idx<=m) update(i*2, l, m, idx, val);
    else update(i*2+1, m+1, r, idx, val);
    seg[i]=seg[i*2]+seg[i*2+1];
}

int main() {
    int n,q;
    cin>>n>>q;
    for (int i=1; i<=n; i++) cin>>a[i];
    build(1,1,n);
    while (q--) {
        int t,x,y;
        cin>>t>>x>>y;
        if (t==1) {
            update(1,1,n,x,y);
        } else {
            cout<<query(1,1,n,x,y)<<endl;
        }
    }
    return 0;
}
