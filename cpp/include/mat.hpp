#pragma once

#include <vector>
using std::vector;

class sqr_matrix final {
    using ull = unsigned long long int;
    vector<vector<ull>> mat;
    static constexpr auto MOD = 1000000007ULL;

public:
    explicit sqr_matrix(ull const &sz) {
        mat.resize(sz, vector<ull>(sz));
    }

    explicit sqr_matrix(vector<vector<ull>> const &rhs) : mat{rhs} {}

    explicit sqr_matrix(vector<vector<ull>> &&rhs) : mat{rhs} {}

    auto operator*(const sqr_matrix &rhs) -> sqr_matrix {
        sqr_matrix temp(rhs.mat.size());

        for (ull i{}; i < mat.size(); ++i) {
            for (ull j{}; j < mat.size(); ++j) {
                auto mul = [&, this] {
                    ull ret{};
                    for (ull m{}; m < mat.size(); ++m) {
                        ret += mat[i][m] * rhs.mat[m][j];
                        ret %= MOD;
                    }
                    return ret;
                };
                temp.mat[i][j] = mul();
            }
        }
        return temp;
    }

    auto operator[](ull const &r) -> vector<ull> & {
        return mat[r];
    }

    static auto power(sqr_matrix const &mat, ull const &n) -> sqr_matrix {
        if (n == 1) return mat;

        auto &&p = power(mat, n >> 1);
        if (n & 1) return p * p * mat;
        return p * p;
    }
};
