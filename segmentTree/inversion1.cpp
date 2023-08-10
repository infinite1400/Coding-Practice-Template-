// जय श्री राम !!
// Do not get stuck on a single approach for long !, think of multiple ways !!
// Always use pen and paper to solve ! Don't directly jump into coding !!
#include <bits/stdc++.h>
using namespace std;
#define code by Murari Pandey Infinite1400 from NITKKR
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define endl "\n"
#define br break
#define loop(i, n) for (int i = 0; i < n; i++)
#define loop1(i, n) for (int i = 1; i <= n; i++)
#define loopn(i, n) for (int i = n - 1; i >= 0; i--)
#define maap map<int, int>
#define minpq priority_queue<int, vector<int>, greater<int>>
#define vec vector<int>
#define int long long int
#define mod 998244353
#define mod1 1000000007
#define decimal(n) fixed << setprecision(n)
// (ﾉ◕ヮ◕)ﾉ*:･ﾟ✧
bool compare(pair<int, int> &i, pair<int, int> &j) { return i.second < j.second; }
bool comp(pair<int, string> &a, pair<int, string> &b) { return a.second < b.second; }
// Segment Tree for Sum operation ! 
// i have calculated size till equal n  
//inversion count 
class SegmentTree
{
private:
    int size;

public:
    typedef struct node{
        int value;
    } node;
    vector<node> values;
    SegmentTree(int n)
    {
        size=1;
        while(size<=n) size*=2;
        values.resize(2*size);
    }
    node neutral={0};
    node merge(node left,node right){
        return{
            left.value+right.value
        };
    }
    node single(int v){
        return {v};
    }
    void build(vector<int> &arr,int x,int lx,int rx){
        if(rx-lx==1){
            if(lx<(int)arr.size()){
                values[x]=single(arr[lx]);
            }
            return;
        }
        int m=(lx+rx)/2;
        build(arr,2*x+1,lx,m);
        build(arr,2*x+2,m,rx);
        values[x]=merge(values[2*x+1],values[2*x+2]);
    }
    void build(vector<int> &arr){
        build(arr,0,0,size);
    }

    void set(int i,int v,int x,int lx,int rx){
        if(rx-lx==1){
            values[x]=single(v);
            return;
        }
        int m=(lx+rx)/2;
        if(i<m) set(i,v,2*x+1,lx,m);
        else set(i,v,2*x+2,m,rx);
        values[x]=merge(values[2*x+1],values[2*x+2]);
    }
    void set(int i,int v){
        set(i,v,0,0,size);
    }
    
    node operation(int l,int r,int x,int lx,int rx){
        if(l>=rx || lx>=r) return neutral;
        if(lx>=l && r>=rx) return values[x];
        int m=(lx+rx)/2;
        node left=operation(l,r,2*x+1,lx,m);
        node right=operation(l,r,2*x+2,m,rx);
        return merge(left,right);
    }
    node operation(int l,int r){
        return operation(l,r,0,0,size);
    }
};
void infinite()
{
    int n;
    cin >> n;
    int arr[n];
    loop(i, n) cin >> arr[i];
    vector<int> ans;
    SegmentTree seg(n);
    cout<<seg.values.size()<<endl;
    for(int i=0;i<n;i++){
        int inversion=seg.operation(arr[i],n+1).value;
        ans.push_back(inversion);
        seg.set(arr[i],1);
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    for (int i = 0; i < t; i++)
    {
        infinite();
        // cout<<t;
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    cerr << __DATE__ << endl
         << __TIME__ << endl;
    return 0;
}