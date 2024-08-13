/**
 * @file    :   BST
 * @author  :   Tanphoon
 * @date    :   2024/08/11 03:00
 * @version :   2024/08/11 03:00
 */
#pragma once

#include "BinTree.h"

template <typename T> class BST : public BinTree<T> {
  public:
    BinNodePtr<T> search(T val) {
        BinNodePtr<T> cur = this->_root;
        while (cur && val != cur->_val) {
            if (val < cur->_val) {
                cur = cur->_lc;
            } else {
                cur = cur->_rc;
            }
        }
        return cur;
    }
    bool insert(T val) {
        if (search(val)) {
            return false;
        } else {
            this->_size++;
            this->_root = add(this->_root, val);
            return true;
        }
    }
    bool erase(T val) {
        if (search(val)) {
            this->_size--;
            this->_root = del(this->_root, val);
            return true;
        } else {
            return false;
        }
    }
    // 查找满足 >=key greater<>() 的最小节点 和 <=key less<>() 的最大节点
    template <typename Comparator> BinNodePtr<T> find(T val, Comparator comp) {
        BinNodePtr<T> ans = nullptr, cur = this->_root;
        while (cur) {
            if (comp(cur->_val, val))
                ans = cur;
            if (val == cur->_val) {
                ans = cur;
                break;
            } else if (val < cur->_val) {
                cur = cur->_lc;
            } else {
                cur = cur->_rc;
            }
        }
        return ans;
    }
  protected:
    BinNodePtr<T> add(BinNodePtr<T> cur, T val) {
        if (!cur) {
            return new BinNode<T>(val);
        } else {
            if (val < cur->_val)
                cur->_lc = add(cur->_lc, val);
            else
                cur->_rc = add(cur->_rc, val);
            cur->updateHeight();
            return maintain(cur);
        }
    }
    BinNodePtr<T> del(BinNodePtr<T> cur, T val) {
        if (val < cur->_val)
            cur->_lc = del(cur->_lc, val);
        else if (val > cur->_val)
            cur->_rc = del(cur->_rc, val);
        else
            cur = del(cur);
        if (cur)
            cur->updateHeight();
        return maintain(cur);
    }
    BinNodePtr<T> del(BinNodePtr<T> cur) {
        BinNodePtr<T> succ = nullptr; // 删除cur后形成子树的根节点
        if (!cur->_lc) {
            succ = cur->_rc;
        } else if (!cur->_rc) {
            succ = cur->_lc;
        } else {
            succ = cur;
            BinNodePtr<T> pre = cur;
            for (cur = cur->_rc; cur->_lc; cur = cur->_lc)
                pre = cur;
            (pre == succ ? pre->_rc : pre->_lc) = cur->_rc;
            std::swap(cur->_val, succ->_val);
        }
        delete cur;
        return succ;
    }
    virtual BinNodePtr<T> maintain(BinNodePtr<T> cur) { return cur; }
};
