/*
不使用任何内建的哈希表库设计一个哈希集合

具体地说，你的设计应该包含以下的功能

add(value)：向哈希集合中插入一个值。
contains(value) ：返回哈希集合中是否存在这个值。
remove(value)：将给定值从哈希集合中删除。如果哈希集合中没有这个值，什么也不做。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/design-hashset
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
本题我所采用的方法就是最基本的用单独链表法来模拟哈希表
采用取余的方式 key % size 来将数字加入到其应该在的链表的尾端
所选择的 size 越大，每个链表就越短，其上的操作就越快，但桶所占空间就越大
size 越小，碰撞的几率就会增加，其上的操作就会越慢，但桶所占的空间就越少
*/

class MyHashSet {
public:
    int size = 30;
    struct ListNode
    {
        int val;
        ListNode* next;
        ListNode(int val):val(val), next(nullptr){}
    };
    /** Initialize your data structure here. */
    ListNode** a = (ListNode**)malloc(sizeof(ListNode*)*size);
    MyHashSet() {
        for(auto i = 0; i < size; ++i) a[i] = nullptr;
    }

    void add(int key) {
        if (a[key % size] == nullptr) a[key % size] = new ListNode(key);
        else {
            auto p = a[key % size];
            auto cur = p;
            while (p != nullptr) {
                if (p->val == key) return;
                cur = p;
                p = p->next;
            }
            cur->next = new ListNode(key);
        }
    }

    void remove(int key) {
        if (a[key % size] == nullptr || (a[key % size]->next == nullptr && a[key%size]->val != key)) return;
        if (a[key % size]->val == key) a[key % size] = a[key % size]->next;
        auto p = a[key % size];
        auto cur = p;
        while (p != nullptr) {
            if (p->val == key) {
                cur->next = p->next;
                return;
            }
            cur = p;
            p = p->next;
        }
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        if (a[key % size] == nullptr) return false;
        auto p = a[key % size];
        while (p != nullptr) {
            if (p->val == key) return true;
            p = p->next;
        }
        return false;
    }
};