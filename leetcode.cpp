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
const int N = 1e5 + 5;
bool isPrime[N];
vector<int> primes;
// (ﾉ◕ヮ◕)ﾉ*:･ﾟ✧
bool compare(pair<int, int> &i, pair<int, int> &j) { return i.second < j.second; }
bool comp(pair<int, string> &a, pair<int, string> &b) { return a.second < b.second; }
bool co(pair<int,int> &a,pair<int,int> &b){
    if(a.first==b.first){
        return a.second>b.second;
    }
}
void infinite()
{
    int n,k;cin>>n>>k;
	int arr[n];
	loop(i,n) cin>>arr[i];
	vector<pair<int,int>> pq;
	for(int i=0;i<n;i++){
		pq.push_back({arr[i],i+1});
	}
	sort(pq.begin(),pq.end());
	vector<int> ans;
	for(int i=pq.size()-1;i>=0;i--){
		if(pq[i].first<=k){
			ans.push_back(pq[i].second);
			pq[i]={-1,pq[i].second};
		}
		else{
			pq[i]={pq[i].first%k,pq[i].second};
		}
	}
	sort(pq.begin(),pq.end(),co);
	for(int i=pq.size()-1;i>=0;i--){
		if(pq[i].first!=-1){
			ans.push_back(pq[i].second);
		}
	}
	for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    
}
int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // prime Number in a range from 2 to N
    // sieve();
    // setbits();
    // ofstream Myfile("bits.txt");
    // for (int i = 0; i <= 100000+20; i++)
    // {
    // 	if (isprime(i))
    // 	{
    // 		Myfile << i << ", ";
    // 	}
    // }
    // cout<<"done"<<endl;
    int t=1;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        infinite();
        // cout<<t;
    }
    cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
    cerr<<__DATE__<<endl<<__TIME__<<endl;
    return 0;
}