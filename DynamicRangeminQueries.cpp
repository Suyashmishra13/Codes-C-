#include <bits/stdc++.h>
using namespace std;

struct segtree{
    int size;
    vector<int> sums;
    void initialize(int x){
        size = 1;
        while(size < x){ size*=2;}
        sums.assign(2*size,0);
    }
    void build(vector<int> &a, int x,int left,int right){
        if(right - left == 1){
            if(left < int(a.size())) sums[x] = a[left];
            return;
        }
        int mid = (left + right ) / 2;
        build(a,2*x+1,left,mid);
        build(a,2*x+2,mid,right);
        sums[x]  = min(sums[2*x+1],sums[2*x+2]);
        return;
    }
    
    void build(vector<int> &a){
        build(a,0,0,size);
    }
    
    void update(int i,int value, int x,int left,int right){
        if(right - left == 1){
            sums[x] = value;
            return;
        }
        int mid = (left + right) / 2;
        if(i < mid) update(i,value,2*x+1,left,mid);
        else update(i,value,2*x+2,mid,right);
        sums[x]  = min(sums[2*x+1],sums[2*x+2]);
        return;
    }
    void update(int pos,int value){
        update(pos,value,0,0,size);
    }

    long long query(int ql,int qr, int x,int left, int right){
        if(qr <= left || right <= ql) return INT_MAX;
        if(qr >= right && ql <= left){
            return sums[x];
        }
        int mid = (left + right ) / 2;
        long long leftpart = query(ql,qr, (2*x+1), left,mid);
        long long rightpart = query(ql,qr, (2*x+2), mid,right);
        return min(leftpart,rightpart);
    }
    long long query(int left,int right){
        return query(left,right,0,0,size);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    for(int &x : a) cin>>x;
    segtree mst;
    mst.initialize(n);
    mst.build(a);
    while(q--){
        long long query;
        cin>>query;
        if(query == 1){
            long long pos,tomake;
            cin>>pos>>tomake;
            mst.update(--pos,tomake);
        }
        else{
            long long start,end;
            cin>>start>>end;
            cout<<mst.query(--start,end)<<endl;
        }
    }
    return 0;
}