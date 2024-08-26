#pragma once

#include "BinNode.h"

template <typename T> class BinTree {
  public:
    BinTree() : _root(nullptr), _size(0) {}
    BinNodePtr<T> root() const { return _root; }
    int size() { return _size; }
    template <typename VST> void travPre(const VST &visit) { travPre(_root, visit); }
    template <typename VST> void travIn(const VST &visit) { travIn(_root, visit); }
    template <typename VST> void travPost(const VST &visit) { travPost(_root, visit); }

  protected:
    template <typename VST> void travPre(BinNodePtr<T> cur, const VST &visit) {
        if (!cur)
            return;
        visit(cur);
        travPre(cur->_lc, visit);
        travPre(cur->_rc, visit);
    }
    template <typename VST> void travIn(BinNodePtr<T> cur, const VST &visit) {
        if (!cur)
            return;
        travIn(cur->_lc, visit);
        visit(cur);
        travIn(cur->_rc, visit);
    }
    template <typename VST> void travPost(BinNodePtr<T> cur, const VST &visit) {
        if (!cur)
            return;
        travPost(cur->_lc, visit);
        travPost(cur->_rc, visit);
        visit(cur);
    }
    BinNodePtr<T> _root;
    int _size;
};