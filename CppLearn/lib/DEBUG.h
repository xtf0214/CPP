#pragma once

template <typename T1, typename T2> auto &operator<<(auto &out, const std::pair<T1, T2> &t) {
    return out << t.first << ":" << t.second;
}
auto &operator<<(auto &out, const auto &a) {
    out << "[";
    for (int i = 0, n = a.size(); const auto &it : a)
        out << it << ",]"[++i == n];
    return out << '\n';
}
void debug(auto... val) { ((std::cerr << val << ", "), ...); }
void debugln(auto... val) { ((std::cerr << val << " "), ...) << '\n'; }
#define Debug(...) std::cerr << "(" #__VA_ARGS__ ") = (", debug(__VA_ARGS__), std::cerr << ")\n";