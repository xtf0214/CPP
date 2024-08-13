/**
 * @file    :   AVL树
 * @author  :   Tanphoon
 * @date    :   2024/08/11 01:40
 * @version :   2024/08/11 01:40
 */
#include "BST.h"

template <typename T> class AVL : public BST<T> {
  protected:
    BinNodePtr<T> maintain(BinNodePtr<T> cur) override {
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