// NOLINTBEGIN
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#include <bits/stdc++.h>
using namespace std;
using ui = uint32_t;
using ll = int64_t;
using ull = uint64_t;
template <typename T, typename Comp = greater<>>
using min_heap = priority_queue<T, vector<T>, Comp>;
template <typename T, typename Comp = less<>>
using max_heap = priority_queue<T, vector<T>, Comp>;
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define ep emplace
#define epb emplace_back
#define mp make_pair
#define mt make_tuple
#define rep(i, a, b) for (auto(i){a}; (i) < static_cast<decltype(a)>(b); ++(i))
#define rev(i, a, b) for (auto(i){a}; (i) >= static_cast<decltype(a)>(b); --(i))
#define all(cont) (cont).begin(), (cont).end()
#define endl ('\n')
[[maybe_unused]] constexpr ull MOD = 1000000007;
enum class SeenType : uint8_t { None, Some, All };
template <typename... Args>
auto put(Args &&...args) {
    ((cout << args << ' '), ...);
}
template <typename... Args>
auto putl(Args &&...args) {
    put(args...);
    cout << '\n';
}
template <typename... Args>
auto see(Args &&...args) {
    ((cin >> args), ...);
}
template <typename T> // should've checked Iteratable trait
auto print(T &&t) {
    for (auto &&el : t) put(el);
    putl();
}
auto solve() -> void;
auto main() -> int {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#if defined(LOCAL)
    auto t1 = chrono::high_resolution_clock::now();
#endif
    solve();
#if defined(LOCAL)
    auto t2 = chrono::high_resolution_clock::now();
    auto time = chrono::duration<double, std::nano>(t2 - t1).count();
    clog.precision(5);
    clog << endl
         << endl
         << "------------------------------" << endl
         << "RUNNING TIME:" << endl
         << time / 1e9 << " s" << endl
         << time / 1e6 << " ms" << endl
         << time << " ns" << endl;
#endif
    cout.flush();
}
// NOLINTEND

auto solve() -> void {}
