/*
设计一个支持在平均 时间复杂度 O(1) 下， 执行以下操作的数据结构。

注意: 允许出现重复元素。

insert(val)：向集合中插入元素 val。
remove(val)：当 val 存在时，从集合中移除一个 val。
getRandom：从现有集合中随机获取一个元素。每个元素被返回的概率应该与其在集合中的数量呈线性相关。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/insert-delete-getrandom-o1-duplicates-allowed
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
用一个 vector 存储插入的数字，并用一个 unordered_map 存储数字和其下标

插入时，将数字 val 加入 vector ，并将下标加入 unordered_map[val] 对应的 unordered_set 中
若此时下标集合的数量大于 1，说明 val 在 vector 中出现多次，返回false，刚好为1说明是首次插入val，返回true

删除时，查找 map ,若没找到了，说明val不存在，返回false，否则就存在，然后在map[val] 的set中找到第一个下标，
然后交换vector[index]和最后一个元素，删除最后一个元素就行了，这样时间复杂度还是O(1)，之后就是将map[val].set中的index删除，
然后将index加入之前vector最后一个元素所对应的下标set

获得随机元素直接对vector的下标进行随机选，然后返回就行了
*/

class RandomizedCollection {
public:
    vector<int> num;
    unordered_map<int, unordered_set<int>> ms;
    /** Initialize your data structure here. */
    RandomizedCollection() {

    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        num.push_back(val);
        ms[val].insert(num.size() - 1);
        return ms[val].size() == 1;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (ms.find(val) == ms.end()) return false;
        int index = *ms[val].begin();
        num[index] = num[num.size() - 1];
        ms[val].erase(index);
        ms[num[index]].erase(num.size() - 1);
        if (index < num.size() - 1) ms[num[index]].insert(index);
        if (ms[val].size() == 0) ms.erase(val);
        num.pop_back();
        return true;

    }

    /** Get a random element from the collection. */
    int getRandom() {
        return num[rand() % num.size()];
    }
};