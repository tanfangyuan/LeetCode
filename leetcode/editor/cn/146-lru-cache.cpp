//
// 请你设计并实现一个满足 
// LRU (最近最少使用) 缓存 约束的数据结构。
// 
//
// 
// 实现 
// LRUCache 类：
// 
//
// 
// 
// 
// LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存 
// int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。 
// void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组 
//key-value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。 
// 
// 
// 
//
// 函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。 
//
// 
//
// 示例： 
//
// 
//输入
//["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
//[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
//输出
//[null, null, null, 1, null, -1, null, -1, 3, 4]
//
//解释
//LRUCache lRUCache = new LRUCache(2);
//lRUCache.put(1, 1); // 缓存是 {1=1}
//lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
//lRUCache.get(1);    // 返回 1
//lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
//lRUCache.get(2);    // 返回 -1 (未找到)
//lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
//lRUCache.get(1);    // 返回 -1 (未找到)
//lRUCache.get(3);    // 返回 3
//lRUCache.get(4);    // 返回 4
// 
//
// 
//
// 提示： 
//
// 
// 1 <= capacity <= 3000 
// 0 <= key <= 10000 
// 0 <= value <= 10⁵ 
// 最多调用 2 * 10⁵ 次 get 和 put 
// 
//
// Related Topics 设计 哈希表 链表 双向链表 👍 2425 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
// 双向链表
struct DLinkNode {
    int key;
    int value;
    DLinkNode *next;
    DLinkNode *prev;
    DLinkNode(): key(0), value(0), prev(nullptr), next(nullptr){}
    DLinkNode(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr){}
};

class LRUCache {
private:
    unordered_map<int, DLinkNode*> cache;
    DLinkNode *head;
    DLinkNode *tail;
    int size;
    int max_capacity;
private:
    void moveToHead(DLinkNode *node) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    DLinkNode* removeTailNode() {
        DLinkNode *removeNode = tail->prev;
        tail->prev->prev->next = tail;
        tail->prev = tail->prev->prev;
        return removeNode;

    }

    void addToHead(DLinkNode *node) {
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
    }


public:
    LRUCache(int capacity) {
        max_capacity = capacity;
        head = new DLinkNode();
        tail = new DLinkNode();
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    
    int get(int key) {
        // 查找是否存在：存在则直接获取并移动链表头指针；不存在则返回-1
        if (cache.find(key) != cache.end()) {
            DLinkNode *node = cache[key];
            // 获取元素
            int val = node->value;
            // 移动到头指针位置
            moveToHead(node);
            return val;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        // 查找是否存在：存在则直接修改并移动链表头指针；
        // 不存在则判断容量，容量满则删除尾指针指向的然后再增加并设置头指针；
        if (cache.find(key) != cache.end()) {
            DLinkNode *node = cache[key];
            node->value = value;
            // 移动到头指针位置
            moveToHead(node);
        } else {
            // 容量满，移除尾部元素
            if (size == max_capacity) {
                DLinkNode *removeNode = removeTailNode();
                cache.erase(removeNode->key);
                delete removeNode;
                size --;
            }
            DLinkNode *node = new DLinkNode(key, value);
            size ++;
            cache[key] = node;
            // 添加到头指针
            addToHead(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    LRUCache lruCache = LRUCache(2);
    lruCache.put(1, 1); // 缓存是 {1=1}
    lruCache.put(2, 2); // 缓存是 {1=1, 2=2}
    lruCache.get(1);    // 返回 1
    lruCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    lruCache.get(2);    // 返回 -1 (未找到)
    lruCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    lruCache.get(1);    // 返回 -1 (未找到)
    lruCache.get(3);    // 返回 3
    lruCache.get(4);    // 返回 4
}