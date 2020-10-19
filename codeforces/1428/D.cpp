    /**   Created by: Humberto Yusta
          Codeforces User: humbertoyusta
          Country: Cuba
          Copyright��                    */
#include<bits/stdc++.h>
using namespace std;
/// Pragmas:
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("avx2") //Enable AVX
/// Macros:
#define int long long
#define f first
#define s second
#define db(x) cerr << #x << ": " << (x) << '\n';
#define pb push_back
#define lb lower_bound
#define up upper_bound
#define all(x) x.begin() , x.end()
#define rall(x) x.rbegin() , x.rend()
#define enl '\n'
typedef pair<int,int> ii;
typedef long double ld;
typedef unsigned long long ull;
/// Constraints:
const int maxn = 1000010;
const int mod = 1000000007;
const ld eps = 1e-9;
const int inf = ((1ll<<31ll)-1ll);
const int INF = 1ll * mod * mod;
const ld pi = acos(-1);
/// Prime Numbers:
// 2, 173, 179, 181, 197, 311, 331, 737, 1009, 2011, 2027, 3079, 4001, 10037, 10079, 20011, 20089;
// 100003, 100019, 100043, 200003, 200017, 1000003, 1000033, 1000037, 1000081;
// 2000003, 2000029, 2000039, 1000000007, 1000000021, 2000000099;
/// rng
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
/// Functions:
#define lg2(x) 31 - __builtin_clz(x)
#define lgx(x,b) ( log(x) / log(b) )
/// Red-Black Tree Template ---------------------------------
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update > ordered_set;
/// Quick Pow------------------------------------------------
int qpow(int b,int e){
    if( !e ) return 1;
    if( e & 1 ) return qpow(b,e-1) * b % mod;
    int pwur = qpow(b,e>>1);
    return pwur * pwur % mod;
}
int modinv(int x){
    return qpow(x,mod-2);
}
/// My Code -------------------------------------------------

int n, id[maxn], a[maxn];
vector<int> v;
set<int> w, k;
vector<ii> ans;

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n;

    w.insert(mod);
    k.insert(mod);

    for(int i=1; i<=n; i++){
        v.pb(n-i+1);
        cin >> a[i];
        if( a[i] == 1 ) w.insert(i);
        if( a[i] > 0 ) k.insert(i);
    }

    for(int i=1; i<=n; i++){
        if( a[i] == 0 ) continue;
        if( !id[i] ){
            id[i] = v.back();
            v.pop_back();
            ans.pb({id[i],i});
        }
        if( a[i] == 2 ){
            int x = *w.upper_bound(i);
            if( x == mod ){
                cout << -1 << '\n';
                return 0;
            }
            id[x] = id[i];
            ans.pb({id[x],x});
            w.erase(x);
            if( *k.lower_bound(x) == x )
                k.erase(x);
        }
        if( a[i] == 3 ){
            int x = *k.upper_bound(i);
            if( x == mod ){
                cout << -1 << '\n';
                return 0;
            }
            id[x] = v.back();
            v.pop_back();
            ans.pb({id[i],x});
            ans.pb({id[x],x});
            k.erase(x);
            if( *w.lower_bound(x) == x )
                w.erase(x);
        }
    }

    cout << ans.size() << '\n';
    for( auto i : ans )
        cout << i.f << ' ' << i.s << '\n';

    return 0;
}
