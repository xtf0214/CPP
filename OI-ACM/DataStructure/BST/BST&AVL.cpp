/**
 * @file    :   BST
 * @author  :   Tanphoon
 * @date    :   2024/08/11 03:00
 * @version :   2024/08/11 03:00
 */
#include <bits/stdc++.h>
using namespace std;
#include <DEBUG.h>

#define height(p) (p ? p->_height : 0)
template <typename T> struct BinNode {
    BinNode *_lc, *_rc; // 左右子树
    T _val;             // 键值对
    int _height;        // 高度
    BinNode(T val) : _lc(nullptr), _rc(nullptr), _val(val), _height(1) {}
    int updateHeight() {
        return _height = std::max(height(this->_lc), height(this->_rc)) + 1;
    } // 更新高度
    BinNode *zig() { // 右旋
        if (!_lc)
            return this;
        BinNode *lc = _lc;
        _lc = lc->_rc;
        lc->_rc = this;
        updateHeight();
        lc->updateHeight();
        return lc;
    }
    BinNode *zag() { // 左旋
        if (!_rc)
            return this;
        BinNode *rc = _rc;
        _rc = rc->_lc;
        rc->_lc = this;
        updateHeight();
        rc->updateHeight();
        return rc;
    }
    // 可视化接口
    const BinNode *left() const { return _lc; }
    const BinNode *right() const { return _rc; }
    std::string val() const {
        std::ostringstream ss;
        ss << _val;
        return ss.str();
    }
};

template <typename T> class BST {
  public:
    using Node = BinNode<T>;
    BST() : _root(nullptr), _size(0) {}
    Node *search(T val) {
        Node *cur = _root;
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
            _size++;
            _root = add(_root, val);
            return true;
        }
    }
    bool erase(T val) {
        if (search(val)) {
            _root = del(_root, val);
            return true;
        } else {
            return false;
        }
    }
    Node *root() const { return _root; }

  protected:
    Node *add(Node *cur, T val) {
        if (!cur) {
            return new Node(val);
        } else {
            if (val < cur->_val)
                cur->_lc = add(cur->_lc, val);
            else
                cur->_rc = add(cur->_rc, val);
            cur->updateHeight();
            return maintain(cur);
        }
    }
    Node *del(Node *cur, T val) {
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
    static Node *del(Node *cur) {
        Node *succ = nullptr; // 删除cur后形成子树的根节点
        if (!cur->_lc) {
            succ = cur->_rc;
        } else if (!cur->_rc) {
            succ = cur->_lc;
        } else {
            succ = cur;
            Node *pre = cur;
            for (cur = cur->_rc; cur->_lc; cur = cur->_lc)
                pre = cur;
            (pre == succ ? pre->_rc : pre->_lc) = cur->_rc;
            swap(cur->_val, succ->_val);
        }
        delete cur;
        return succ;
    }
    virtual Node *maintain(Node *cur) { return cur; }
    Node *_root;
    int _size;
};
template <typename T> class AVL : public BST<T> {
  protected:
    BinNode<T> *maintain(BinNode<T> *cur) override {
        if (!cur)
            return nullptr;
        int Lheight = height(cur->_lc);   // 计算出cur左树的高度
        int Rheight = height(cur->_rc);   // 计算出cur右树的高度
        if (abs(Lheight - Rheight) > 1) { // 出现不平衡
            if (Lheight > Rheight) {
                // 计算cur左树的左右子树的高度
                int LLheight = cur->_lc ? height(cur->_lc->_lc) : 0;
                int LRheight = cur->_lc ? height(cur->_lc->_rc) : 0;
                if (LLheight >= LRheight) { // LL型右单旋转
                    cur = cur->zig();
                } else { // LR型左右双旋
                    cur->_lc = cur->_lc->zag();
                    cur = cur->zig();
                }
            } else {
                // 计算cur右树的左右子树的高度
                int RLheight = cur->_rc ? height(cur->_rc->_lc) : 0;
                int RRheight = cur->_rc ? height(cur->_rc->_rc) : 0;
                if (RRheight >= RLheight) { // RR型左单旋转
                    cur = cur->zag();
                } else { // RL型右左双旋
                    cur->_rc = cur->_rc->zig();
                    cur = cur->zag();
                }
            }
        }
        return cur; // 返回调整好的新父节点
    }
};
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    BST<int> bst;
    AVL<int> avl;
    vector<int> a{45, 24, 55, 12, 37, 53, 60, 28, 40, 70};
    vector<int> b{53, 17, 78, 9, 45, 65, 94, 23, 81, 88};
    shuffle(a.begin(), a.end(), mt19937(random_device()()));
    for (int x : a) {
        bst.insert(x);
        avl.insert(x);
        BinTreeUtil(bst.root()).print();
        debug(string(20, '-'));
        BinTreeUtil(avl.root()).print();
        debug(string(40, '-'));
    }
    return 0;
}