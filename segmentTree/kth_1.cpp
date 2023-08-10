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
#define decimal(n) fixed<<setprecision(n)
// (ﾉ◕ヮ◕)ﾉ*:･ﾟ✧
bool compare(pair<int, int> &i, pair<int, int> &j) { return i.second < j.second; }
bool comp(pair<int, string> &a, pair<int, string> &b) { return a.second < b.second; }
class SegmentTree{
private:
	int size;

public:
	typedef struct node{
		int sum;
	}node;
	vector<node> values;
	node neutral={0};
//Segment Tree can be build for any associative operation a x (b x c) == (a x b) x c where x is associative operation
	SegmentTree(int n){
		//initialise size of segment tree.. to nearest power of 2
		size=1;
		while(size<n) size*=2;
		values.resize(2*size);
	}
	// build segment tree of a given size of array in O(n)
	node merge(node left,node right){
		return{
			left.sum+right.sum,
		};
	}
	node single(int v){
		return {v};
	}
	void build(vector<int> &arr,int x,int lx,int rx){
		// if leaf node just assign the array value
		if(rx-lx==1){
			// since we have values array of extra size to make to nearst power of 2
			// we have to check that the left segment belongs to array 
			if(lx<(int)arr.size()){
				values[x]=single(arr[lx]);
			}
			return;
		}
		// else call left child and right child
		int m=(lx+rx)/2;
		build(arr,2*x+1,lx,m);
		build(arr,2*x+2,m,rx);
		values[x]=merge(values[2*x+1],values[2*x+2]);
	}
	void build(vector<int> &arr){
		build(arr,0,0,size);
	}
// set function set(i,v) which is to set arr[i]=v  
	void set(int i,int v,int x,int lx,int rx){
		// if segment size is 1 meaning leaf node ... just assign the value
		if(rx-lx==1){
			values[x]=single(v);
			return;
		}
		// if not leaf ! then we have to decide in which segment i belongs to 
		int m=(lx+rx)/2;
		// if i is on left of m then call left segment 
		// else call right segmet
		if(i<m) set(i,v,2*x+1,lx,m);
		else set(i,v,2*x+2,m,rx);
		//after recursion we have to recalculate operation at node x to its left child and right child 
		values[x]=merge(values[2*x+1],values[2*x+2]);

	}
	void set(int i,int v){
		// we will call the above function from root to i
		set(i,v,0,0,size);
	}
	int find(int k,int x,int lx,int rx){
        // if leaf node is reached ! meaning kth one is found... return index--lx
        if(rx-lx==1){
            return lx;
        }
        //find where to locate kth 1 
        int m=(lx+rx)/2;
        //if no. of 1 present in left subtree is strictly smaller means we have to go to left subtree...
        int sl=values[2*x+1].sum;
        if(k<sl){
            find(k,2*x+1,lx,m);
        }
        else{
            find(k-sl,2*x+2,m,rx);
        }
    }
    int find(int k){
        return find(k,0,0,size);
    }
};

void infinite()
{
	int n,m;cin>>n>>m;
	SegmentTree seg(n);
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	seg.build(arr);
	// for(int i=0;i<seg.values.size();i++){
	// 	cout<<seg.values[i].sum<<" ";
	// }
	// cout<<endl;
	// cout<<seg.find(4)<<endl;
	while(m--){
		int op;cin>>op;
        if(op==1){
            int i;cin>>i;
            arr[i]=1-arr[i];
            seg.set(i,arr[i]);
        }
        else{
            int k;cin>>k;
            cout<<seg.find(k)<<endl;
        }
	}
}
int32_t main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	// cin >> t;
	for (int i = 0; i < t; i++)
	{
		infinite();
		// cout<<t;
	}
	cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
    cerr<<__DATE__<<endl<<__TIME__<<endl;
	return 0;
}