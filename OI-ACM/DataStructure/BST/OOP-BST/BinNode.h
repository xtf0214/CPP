#pragma once

#include <sstream>
#include <string>
#define height(p) (p ? p->_height : 0)

template <typename T> struct BinNode;
template <typename T> using BinNodePtr = BinNode<T> *;

template <typename T> struct BinNode {
    BinNodePtr<T> _lc, _rc; // 左右子树
    T _val;             // 键值对
    int _height;        // 高度
    BinNode(T val) : _lc(nullptr), _rc(nullptr), _val(val), _height(1) {}
    int updateHeight() { return _height = std::max(height(_lc), height(_rc)) + 1; }
    BinNodePtr<T> zig() { // 右旋
        if (!_lc) return this;
        BinNodePtr<T> lc = _lc;
        _lc = lc->_rc;
        lc->_rc = this;
        updateHeight();
        lc->updateHeight();
        return lc;
    }
    BinNodePtr<T> zag() { // 左旋
        if (!_rc) return this;
        BinNodePtr<T> rc = _rc;
        _rc = rc->_lc;
        rc->_lc = this;
        updateHeight();
        rc->updateHeight();
        return rc;
    }
    // 可视化接口
    BinNodePtr<T> left() const { return _lc; }
    BinNodePtr<T> right() const { return _rc; }
    std::string val() const {
        std::ostringstream ss;
        ss << _val;
        return ss.str();
    }
};