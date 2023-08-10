// जय श्री राम !!
// Do not get stuck on a single approach for long !, think of multiple ways !!
// Always use pen and paper to solve ! Don't directly jump into coding !!
#include <bits/stdc++.h>
using namespace std;
#define code by Murari Pandey Infinite1400 from NITKKR
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define nl cout << "\n";
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
const int N = 1e5 + 5;
bool isPrime[N];
vector<int> primes;
bool compare(pair<int, int> &i, pair<int, int> &j) { return i.second < j.second; }
bool comp(pair<int, string> &a, pair<int, string> &b) { return a.second < b.second; }
bool rev(int a, int b) { return a > b; }
void sieve()
{
	fill(isPrime + 2, isPrime + N, true);
	for (int i = 2; i * i < N; i++)
	{
		for (int j = i * i; j < N; j += i)
		{
			isPrime[j] = false;
		}
	}
	for (int i = 2; i < N; i++)
	{
		if (isPrime[i])
		{
			primes.push_back(i);
		}
	}
}

int calcPrime(int n)
{
	// prime number till n
	sieve();
	int res = 0;
	for (int i : primes)
	{
		if (i * i > n)
		{
			break;
		}
		while (n % i == 0)
		{
			n /= i;
			res++;
		}
	}
	if (n > 1)
	{
		res++;
	}
	return res;
}

bool perfectsquare(int n)
{

	if (ceil((double)sqrt(n)) == floor((double)sqrt(n)))
	{
		cout << "perfect square";
		return true;
	}
	else
	{
		cout << "not a perfect square";
		return false;
	}
}

int countSC(int N)
{
	int res = (int)sqrt(N) - (int)cbrt(N);
	return res;
}

bool isprime(int n)
{
	// n is prime or not
	if (n == 1)
	{
		return false;
	}
	if (!(n % 2) && n > 2)
	{
		return false;
	}
	if (n == 2)
	{
		return true;
	}
	else
	{
		for (int i = 3; i * i <= n; i += 2)
		{
			if (n % i == 0)
			{
				return false;
			}
		}
	}
	return true;
}

int smallestDivisor(int n)
{
	if (n % 2 == 0)
		return 2;
	for (int i = 3; i * i <= n; i += 2)
	{
		if (n % i == 0)
			return i;
	}
	return n;
}

int sumarray(int arr[], int n)
{
	// sum of array
	int x = 0;
	for (int i = 0; i < n; i++)
		x += arr[i];
	return x;
}
template <typename T>
T maximum(T a, T b)
{
	if (a > b)
		return a;
	else
		return b;
}
template <typename T>
T minimum(T a, T b)
{
	if (a > b)
		return b;
	else
		return a;
}

int maxarray(int arr[], int n)
{
	// minimum array
	int m = -5e18;
	for (int i = 0; i < n; i++)
	{
		if (m < arr[i])
		{
			m = arr[i];
		}
	}
	return m;
}

int minarray(int arr[], int n)
{
	// minimum array
	int m = 5e18;
	for (int i = 0; i < n; i++)
	{
		if (m > arr[i])
		{
			m = arr[i];
		}
	}
	return m;
}
template <typename T>
void printarray(T arr[], int n)
{
	// array print
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
template <typename T>
void printvector(vector<T> &v)
{
	// vector print
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

bool ispalindrome(string str)
{
	// palindrome or not
	int n = str.length();
	int x = n - 1;
	for (int i = 0; i < n / 2; i++)
	{
		if (str[i] != str[x])
		{
			return false;
		}
		x--;
	}
	return true;
}
bool sorted(vector<int> &v)
{
	// sorted array or not
	for (int i = 0; i < v.size() - 1; i++)
	{
		if (v[i] > v[i + 1])
		{
			return false;
		}
	}
	return true;
}
bool rsorted(vector<int> &v)
{
	// reverse sorted array or not
	for (int i = 0; i < v.size() - 1; i++)
	{
		if (v[i] < v[i + 1])
		{
			return false;
		}
	}
	return true;
}
int smallestprimefactor(int n)
{
	// smallest factor to a number !
	if (n % 2 != 0)
	{
		return 2;
	}
	for (int i = 3; i <= sqrt(n); i += 2)
	{
		if (n % i != 0)
		{
			return i;
		}
	}
	return sqrt(n) + 1;
}

int digitsum(int n)
{
	// Digit sum of a number
	int sum = 0;
	while (n)
	{
		sum += n % 10;
		n /= 10;
	}
	return sum;
}
int minvector(vector<int> &v)
{
	// minimum of vector
	int m = 5e18;
	for (int i = 0; i < v.size(); i++)
	{
		m = minimum(m, v[i]);
	}
	return m;
}

int maxvector(vector<int> &v)
{
	// maximum of vector
	int m = -5e18;
	for (int i = 0; i < v.size(); i++)
	{
		m = maximum(m, v[i]);
	}
	return m;
}
vector<int> arra(int a)
{
	// number to vector digit by digit
	vector<int> x;
	while (a)
	{
		x.push_back(a % 10);
		a /= 10;
	}
	reverse(x.begin(), x.end());
	return x;
}
bool ispermutation(int arr[], int n)
{
	// check if permutation or not
	sort(arr, arr + n);
	for (int i = 0; i < n; i++)
	{
		// st.insert(arr[i]);
		if (arr[i] != i + 1)
		{
			return false;
		}
	}
	return true;
}
vector<int> convertbits(int n)
{
	// number to binary vector
	vector<int> v;
	while (n)
	{
		if (n % 2 == 0)
		{
			v.push_back(0);
		}
		else
		{
			v.push_back(1);
		}
		n /= 2;
	}
	reverse(v.begin(), v.end());
	return v;
}
int power(int x, int y)
{
	// power Function
	int temp;
	if (y == 0)
		return 1;
	temp = power(x, y / 2);
	if (y % 2 == 0)
		return temp * temp;
	else
		return x * temp * temp;
}
int ceil(int a, int b)
{
	int x = a / b;
	if (a % b != 0)
		x++;
	return x;
}
int convert_to_number(vector<int> &v)
{
	int ans = 0;
	int a = 1;
	reverse(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		int a = power(2, i);
		if (v[i] == 1)
		{
			ans += a;
		}
	}
	return ans;
}

void setbits()
{
	int bits[20][200001] = {0};
	// storing numbers from 0 to 200000 set bits
	// like for 0th position is storing the count of number from 0 to 200000 that has first bit set
	// likewise till 20 twenty..
	// lamen
	// storing count of number that has 1 to 20 bits are set..
	for (int i = 0; i < 20; i++)
	{
		for (int j = 1; j < 200001; j++)
		{
			bits[i][j] = bits[i][j - 1] + (j >> i & 1);
		}
	}
	//(j >> i & 1)
	// meaning is--dividing j with 2^i and the result has and operation with 1
}
vector<int> suffix(int arr[], int n)
{
	vector<int> suff(n + 1, 0);
	int x = 1;
	for (int i = n - 1; i >= 0; i--)
	{
		suff[x] = suff[x - 1] + arr[i];
		x++;
	}
	return suff;
}

vector<int> prefix(int arr[], int n)
{
	vector<int> pref(n + 1, 0);
	for (int i = 0; i < n; i++)
	{
		pref[i + 1] = pref[i] + arr[i];
	}
	return pref;
}
int lower_bound(int arr[], int n, int x)
{
	int low = 0;
	int high = n - 1;
	while (high > low)
	{
		int mid = (low + high) / 2;
		if (x <= arr[mid])
		{
			high = mid;
		}
		else
		{
			low = mid + 1;
		}
	}
	if (low < n && arr[low] < x)
	{
		low++;
	}
	return low;
}

int upper_bound(int arr[], int n, int x)
{
	int low = 0, high = n - 1;
	while (high > low)
	{
		int mid = (low + high) / 2;
		if (x > arr[mid])
		{
			low = mid + 1;
		}
		else
		{
			high = mid;
		}
	}
	if (low < n && arr[low] <= x)
	{
		low++;
	}
	return low;
}
void infinite()
{
	int n;cin>>n;
	int arr[n];
	loop(i,n) cin>>arr[i];
	printarray(arr,n);
}
int32_t main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// prime Number in a range from 2 to N
	//   sieve();
	// setbits();
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		infinite();
		// cout<<t;
	}
	return 0;
}