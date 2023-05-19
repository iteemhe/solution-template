#pragma once
#include <coroutine>
#include <iostream>
#include <optional>

template <std::movable T>
class Generator {
public:
    // NOLINTNEXTLINE(readability-identifier-naming)
    struct promise_type { // NOTE: The naming convention is mandated by the standard.

        // NOLINTNEXTLINE(misc-non-private-member-variables-in-classes)
        std::optional<T> current_value_;

        auto get_return_object() -> Generator<T> {
            return Generator{Handle::from_promise(*this)};
        }
        static auto initial_suspend() noexcept -> std::suspend_always {
            return {};
        }
        static auto final_suspend() noexcept -> std::suspend_always {
            return {};
        }
        auto yield_value(T value) noexcept -> std::suspend_always {
            current_value_ = std::move(value);
            return {};
        }
        // Disallow co_await in generator coroutines.
        void await_transform() = delete;
        [[noreturn]] static void unhandled_exception() {
            throw;
        }
    };

    using Handle = std::coroutine_handle<promise_type>;

    explicit Generator(const Handle coroutine) : m_coroutine_{coroutine} {}
    Generator() = default;
    ~Generator() {
        if (m_coroutine_) m_coroutine_.destroy();
    }

    Generator(const Generator &) = delete;
    auto operator=(const Generator &) -> Generator & = delete;

    Generator(Generator &&other) noexcept : m_coroutine_{other.m_coroutine_} {
        other.m_coroutine_ = {};
    }
    auto operator=(Generator &&other) noexcept -> Generator & {
        if (this != &other) {
            if (m_coroutine_) m_coroutine_.destroy();
            m_coroutine_ = other.m_coroutine_;
            other.m_coroutine_ = {};
        }
        return *this;
    }

    // Range-based for loop support.
    class Iter {
    public:
        void operator++() {
            m_coroutine_.resume();
        }
        auto operator*() const -> const T & {
            return *m_coroutine_.promise().current_value_;
        }
        auto operator==(std::default_sentinel_t /*unused*/) const -> bool {
            return !m_coroutine_ || m_coroutine_.done();
        }

        explicit Iter(const Handle coroutine) : m_coroutine_{coroutine} {}

    private:
        Handle m_coroutine_;
    };

    auto begin() -> Iter {
        if (m_coroutine_) m_coroutine_.resume();
        return Iter{m_coroutine_};
    }

    auto end() -> std::default_sentinel_t {
        return {};
    }

private:
    Handle m_coroutine_;
};
