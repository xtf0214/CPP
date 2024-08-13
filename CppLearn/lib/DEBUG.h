#pragma once
#include <bits/stdc++.h>
#define printContainer(a, format, split, start, end)                                               \
    out << start;                                                                                  \
    for (const auto &it : a)                                                                       \
        out << format << split;                                                                    \
    return out << end;

template <typename T1, typename T2> auto &operator<<(auto &out, const std::pair<T1, T2> &t) {
    return out << t.first << ":" << t.second;
}
template <typename T> auto &operator<<(auto &out, const std::vector<int> &a) {
    printContainer(a, (it == 1e9 ? INFINITY : it), ", ", "[ ", "]");
}
template <typename T> auto &operator<<(auto &out, const std::vector<T> &a) {
    printContainer(a, it, ", ", "[ ", "]");
}
template <typename T> auto &operator<<(auto &out, const std::vector<std::vector<T>> &a) {
    printContainer(a, it, "\n", "", "");
}
template <typename T> auto &operator<<(auto &out, const std::set<T> &a) {
    printContainer(a, it, ", ", "{ ", "}")
}
template <typename K, typename V> auto &operator<<(auto &out, const std::map<K, V> &a) {
    printContainer(a, it, ", ", "{ ", "}")
}

template <typename Info>
void segTreePrint(const std::vector<Info> &info, int n, int width, int scale = 1) {
    int height = std::__lg(n - 1) + 2;
    std::vector output(scale << height, std::vector<std::string>(scale << height, " "));
    std::function<void(int, int, int, int, int, int)> write = [&](int p, int l, int r, int y, int x,
                                                                  int h) {
        std::ostringstream ss;
        ss << info[p];
        output[y][x] = ss.str();
        if (l == r)
            return;
        int mid = (l + r) / 2;
        for (int i = 1; i < scale << h; i++)
            output[y][x + i] = '-';
        write(p << 1, l, mid, y, x + (scale << h), h - 1);
        for (int i = 1; i < scale << h; i++)
            output[y + i][x + i] = '\\';
        write(p << 1 | 1, mid + 1, r, y + (scale << h), x + (scale << h), h - 1);
    };
    write(1, 1, n, 0, 0, height - 1);
    for (int j = 0, h = height - 1; h >= 0; j += scale << h, h--)
        for (int i = 0; i < scale << height; i++)
            output[i][j].resize(width, ' ');
    for (int i = 0; i < output.size(); i++, std::cout << std::endl)
        for (int j = 0; j < output[i].size(); j++)
            std::cout << output[i][j];
}

template <typename Node> class BinTreeUtil {
  public:
    BinTreeUtil(const Node *root) : root(root), h(calcHeight(root)) {}
    void show(int scale = 1) {
        if (!root) return;
        output.resize(scale << h, std::string(scale * ((2 << h) - 1), ' '));
        write1(root, 0, scale * ((1 << h) - 1), h - 1, scale << h - 1);
        for (int i = 0; i < output.size(); i++)
            std::cout << output[i] << std::endl;
    }
    void print(bool compressed = true, int scale = 1) {
        if (!root) return;
        output.resize((h << 1) - 1, std::string(scale * (2 << h) - 1, ' '));
        write2(root, 0, scale * ((1 << h) - 1), h - 1, scale << h - 1);
        std::vector<int> space(output[0].size());
        iota(space.begin(), space.end(), 0);
        if (compressed) {
            for (int j = 0; j < output[0].size(); j++) {
                bool allSpace = true;
                for (int i = 0; i < output.size(); i++)
                    allSpace &= (output[i][j] == ' ');
                if (allSpace)
                    space[j] = -1;
            }
        }
        for (int i = 0; i < output.size(); i++, std::cout << std::endl)
            for (int j = 0; j < output[0].size(); j++)
                if (j == 0 || space[j] != space[j - 1])
                    std::cout << output[i][j];
    }
    static int calcHeight(const Node *cur) {
        return cur ? std::max(calcHeight(cur->left()), calcHeight(cur->right())) + 1 : 0;
    }
    std::vector<std::string> arrayStorage() {
        std::vector<std::string> output(1 << h, "null");
        std::function<void(const Node *, int)> trav = [&](const Node *cur, int i) {
            if (!cur)
                return;
            output[i] = cur->val();
            trav(cur->left(), i << 1);
            trav(cur->right(), i << 1 | 1);
        };
        trav(root, 1);
        return output;
    }

  private:
    void write1(const Node *cur, int y, int x, int h, int gap) {
        output[y].replace(x, cur->val().size(), cur->val());
        if (cur->left()) {
            for (int i = 1; i < gap; i++)
                output[y + i][x - i] = '/';
            write1(cur->left(), y + gap, x - gap, h - 1, gap >> 1);
        }
        if (cur->right()) {
            for (int i = 1; i < gap; i++)
                output[y + i][x + i] = '\\';
            write1(cur->right(), y + gap, x + gap, h - 1, gap >> 1);
        }
    }
    void write2(const Node *cur, int y, int x, int h, int gap) {
        output[y].replace(x, cur->val().size(), cur->val());
        if (cur->left()) {
            output[y + 1][x - gap / 2] = '/';
            write2(cur->left(), y + 2, x - gap, h - 1, gap >> 1);
        }
        if (cur->right()) {
            output[y + 1][x + gap / 2] = '\\';
            write2(cur->right(), y + 2, x + gap, h - 1, gap >> 1);
        }
    }
    const Node *root;
    std::vector<std::string> output;
    int scale, h;
};

template <typename First, typename... Args> void _debug(First first, const Args &...args) {
    std::cerr << first;
    if constexpr (sizeof...(args) > 0)
        ((std::cerr << ", " << args), ...);
}
template <typename First, typename... Args> void debug(First first, const Args &...args) {
    _debug(first, args...), std::cerr << std::endl;
}
#define Log(...)                                                                                   \
    std::cerr << "(" #__VA_ARGS__ ") = (", _debug(__VA_ARGS__), std::cerr << ")" << std::endl