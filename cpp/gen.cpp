#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#define NDEBUG
#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ll = long long int;
using ull = unsigned long long int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
[[maybe_unused]]                 //
constexpr ll inf = 1000000007ll; // 1e9 + 7
auto gen() -> void;
auto main() -> int {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    gen();
}

auto gen() -> void {
    ofstream ofs("test_input.txt");
    mt19937_64 gen(999);
    uniform_real_distribution<> dist(1, 99999999);
    ofs << "200000 200000\n";
    for (int i = 0; i < 200000; ++i) {
        ofs << (i % (ll)1e9) + 1 << ' ';
    }
    ofs << endl;
    for (int i = 0; i < 200000; ++i) {
        ofs << "1 200000" << endl;
    }
}
