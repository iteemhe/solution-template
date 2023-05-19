#pragma once
#include <ranges>
#include <vector>
using namespace std;
using ull = unsigned long long;

struct scc {
    vector<vector<ull>> adj, adj_t;
    // components
    vector<ull> comp;
    vector<ull> order;
    vector<bool> seen;
    ull size_;

    // topological order for strongly connected components
    ull topo{};
    auto operator=(scc const &lhs) -> scc & = delete;
    scc(scc const &lhs) = delete;
    scc(scc &&lhs) = delete;

    explicit scc(ull const &N) : adj(N), adj_t(N), comp(N), size_(N) {
        order.reserve(N);
    }

    auto emplace(ull const &u, ull const &v) -> void {
        adj[u].emplace_back(v);
        adj_t[v].emplace_back(u);
    }

    /**
     * Postorder traverse
     */
    auto dfs(ull u) -> void {
        if (seen[u]) return;
        seen[u] = true;
        for (auto &&v : adj[u]) dfs(v);
        order.emplace_back(u);
    }

    auto dfs_t(ull u) -> void {
        if (seen[u]) return;
        seen[u] = true;
        comp[u] = topo;
        // traverse the negated graph
        for (auto &&v : adj_t[u]) dfs_t(v);
    }

    auto gen() -> void {
        for (ull i{}; i < size_; ++i) dfs(i);
        fill(seen.begin(), seen.end(), false);
        for (auto &&u : ranges::reverse_view(order)) {
            if (seen[u]) continue;
            ++topo;
            dfs_t(u);
        }
    }
};
