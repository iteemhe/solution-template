#include <fstream>
#include <iostream>
#include <limits>
#include <random>
#include <set>
#include <string>

auto main() -> int {
    using namespace std;

    constexpr int kN = std::numeric_limits<int>::max() / 4;

    std::random_device rd;
    std::mt19937_64 gen{rd()};
    std::uniform_int_distribution dist{-kN, kN};

    auto num_pts = 100'000;

    std::ofstream ofs{"test.out"s};
    ofs << num_pts << std::endl;
    std::set<std::pair<int, int>> seen;

    while (num_pts--) {
        auto x = dist(gen);
        auto y = dist(gen);
        while (seen.count({x, y})) x = dist(gen), y = dist(gen);
        seen.emplace(x, y);
        ofs << x << ' ' << y << std::endl;
    }
}
