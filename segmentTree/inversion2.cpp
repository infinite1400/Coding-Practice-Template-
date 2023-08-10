// जय श्री राम !!
// Do not get stuck on a single approach for long !, think of multiple ways !!
// Always use pen and paper to solve ! Don't directly jump into coding !!
#include <bits/stdc++.h>
using namespace std;
#define code by Murari Pandey Infinite1400 from NITKKR
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define endl "\n"
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

class SegmentTree{
private:
    int size;

public:
    typedef struct node{
        int value;
    }node;
    vector<node> values;
    SegmentTree(int n){
        size=1;
        while(size<=n) size*=2;
        values.resize(2*size);
    }
    node merge(node left,node right){
        return {
            left.value+right.value
        };
    }
    node single(int v){
        return {v};
    }
    node neutral={0};

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
        return build(arr,0,0,size);
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
    
    int find(int k,int x,int lx,int rx){
        if(rx-lx==1) return lx;
        int m=(lx+rx)/2;
        int sl=values[2*x+1].value;
        if(k<sl){
            return find(k,2*x+1,lx,m);
        }
        else{
            return find(k-sl,2*x+2,m,rx);
        }
    }
    int find(int k){
        return find(k,0,0,size);
    }
};
void infinite()
{
    //uses segment tree to find back the permutation ! 
    // traversing back the array and finding the (number of one - arr[i]-1)th 1 from starting .. 
    // that particular index will ensure that number of inversions on left will be that particular number 
    // after find set that particular index to 0 and again calculating the same ! 
    int n;cin>>n;
    int arr[n];
    vector<int> check(n,1);
    SegmentTree seg(n);
    seg.build(check);
    int a=n-1;
    vector<int> ans;
    for(int i=n-1;i>=0;i--){
        int k=a-arr[i];
        int index=seg.find(k);
        seg.set(index,0);
        ans.push_back(index+1);
        a--;
    }
    for(int i=ans.size()-1;i>=0;i--){
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