#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ll = long long int;
using ull = unsigned long long int;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cerr.tie(nullptr);
    cout.precision(5);
    cout.setstate(ios::failbit);
    using namespace std::chrono;
    //  Preparation
    mt19937_64 gen(999);
    uniform_int_distribution<ull> dist(0, 30);
    this_thread::sleep_for(milliseconds(100));
    constexpr ull REP = 1'000'000;
    constexpr ull START = 1'000'000;
    constexpr ull END = START << 10U;

    for (auto N{START}; N <= END; N <<= 1U) {
        cerr << "N = " << N << endl;
        // stable
        this_thread::sleep_for(milliseconds(1000)); // wait 0.1 seconds for
        int x;
        [&]() {
            this_thread::sleep_for(milliseconds(1000));

            auto t1 = high_resolution_clock::now();
            auto t2 = high_resolution_clock::now();
            cerr << "Algorithm 1: "
                 << duration<double, std::nano>(t2 - t1).count() / static_cast<double>(N) << endl;
        }();
        this_thread::sleep_for(milliseconds(1000));
        [&]() {
            this_thread::sleep_for(milliseconds(1000));

            auto t1 = high_resolution_clock::now();
            auto t2 = high_resolution_clock::now();
            cerr << "Algorithm 1: "
                 << duration<double, std::nano>(t2 - t1).count() / static_cast<double>(N) << endl;
        }();
        cerr << "---------------------" << endl;
        this_thread::sleep_for(milliseconds(1000));
    }
}
