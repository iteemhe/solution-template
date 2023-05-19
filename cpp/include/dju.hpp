#pragma onece
#include <vector>

class dju final {
    using ull = unsigned long long;
    std::size_t sz;
    std::vector<ull> arr, rank;

public:
    explicit dju(ull const &sz_) : sz(sz_), rank(sz, 1) {
        arr.reserve(sz);
        for (ull i{}; i < sz; ++i) arr.emplace_back(i);
    }

    auto find(ull const &curr) noexcept -> ull {
        if (curr == arr[curr]) return curr;
        return arr[curr] = find(arr[curr]);
    }

    auto connect(ull const &lhs, ull const &rhs) noexcept -> void {
        auto lr = find(lhs), rr = find(rhs);
        if (lr == rr) return;
        --sz;
        if (rank[lr] < rank[rr]) {
            arr[rr] = lr;
            rank[lr] += rank[rr];
        } else {
            arr[lr] = rr;
            rank[rr] += rank[lr];
        }
    }

    auto size() noexcept -> ull {
        return sz;
    }
};
