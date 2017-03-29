#include <iostream> 
//#define Debug
using namespace std;
typedef long long ll;
ll ans(0);
void Merge(ll l, ll mid, ll r, ll ar[])
{
	static ll temp[100001] = {0};
	ll p = l, q = mid + 1, k = l;
	while (p <= mid&&q <= r)
	{
		if (ar[p] < ar[q])
		{
			temp[k++] = ar[p++];
			ans += r - q + 1;
		}
		else 
		{ 
			temp[k++] = ar[q++]; 
			
		}
	}
	while (p <= mid)temp[k++] = ar[p++];
	while (q <= r)temp[k++] = ar[q++];
	for (ll i = l; i <= r; ++i)
		ar[i] = temp[i];
}
void MergeSort(ll l, ll r, ll ar[])
{
	if (l == r)return;
	ll mid = (l + r) / 2;
	MergeSort(l, mid, ar);
	MergeSort(mid + 1, r, ar);
	Merge(l, mid, r, ar);
	return;
}
int main()
{
	ll n, a;
	ll ar[100001] = { 0 };
	cin >> n >> a;
	for (ll i = 1; i <= n; ++i)
	{
		cin >> ar[i];
		ar[i] -= a;//减去母球标号
		ar[i] += ar[i - 1];//前缀和
	}
#ifdef Debug
	for (ll i = 1; i <= n; ++i)
		cout << ar[i] << " ";
	cout << endl;
#endif

	MergeSort(0, n, ar);
#ifdef Debug
	for (ll i = 1; i <= n; ++i)
		cout << ar[i]<<" ";
	cout << endl;
#endif
	cout << ans;
	return 0;
}