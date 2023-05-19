template <typename T, int I>
struct report {
    static_assert(I < 0, "report");
};

template <typename First, typename Second>
struct Pair {
    using car = First;
    using cdr = Second;
};

template <typename T>
using car_t = typename T::car;
template <typename T>
using cdr_t = typename T::cdr;

struct nil {};

template <typename T>
struct is_empty {
    static constexpr bool value = false;
};

template <>
struct is_empty<nil> {
    static constexpr bool value = true;
};

template <typename T>
static constexpr bool is_empty_v = is_empty<T>::value;

auto main() -> int {}
