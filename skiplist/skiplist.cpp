#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <random>

const int MAX_LEVEL = 16; // 最大层数

// 跳表节点
struct SkipListNode {
    int value;
    std::vector<SkipListNode*> next; // 每层的下一个节点指针

    SkipListNode(int val, int level) : value(val), next(level, nullptr) {}
};

// 跳表
class SkipList {
private:
    int level; // 当前层数
    SkipListNode* head; // 头节点

    // 随机生成节点层数
    int randomLevel() {
        thread_local static std::mt19937 gen(std::random_device{}());
        std::bernoulli_distribution d(0.5);
        int lvl = 1;
        while (d(gen) && (lvl < MAX_LEVEL)) {
            lvl++;
        }
        return lvl;
    }

public:
    SkipList() : level(1), head(new SkipListNode(INT_MIN, MAX_LEVEL)) {}
    // 查找
    bool search(int target) {
        SkipListNode* curr = head;
        for (int i = level - 1; i >= 0; i--) {
            while (curr->next[i] && curr->next[i]->value < target) {
                curr = curr->next[i];
            }
        }
        curr = curr->next[0];
        return curr && curr->value == target;
    }
    // 插入
    void insert(int value) {
        std::vector<SkipListNode*> update(MAX_LEVEL, nullptr);
        SkipListNode* curr = head;

        for (int i = level - 1; i >= 0; i--) {
            while (curr->next[i] && curr->next[i]->value < value) {
                curr = curr->next[i];
            }
            update[i] = curr;
        }

        int newLevel = randomLevel();
        if (newLevel > level) {
            for (int i = level; i < newLevel; i++) {
                update[i] = head;
            }
            level = newLevel;
        }

        SkipListNode* newNode = new SkipListNode(value, newLevel);
        for (int i = 0; i < newLevel; i++) {
            newNode->next[i] = update[i]->next[i];
            update[i]->next[i] = newNode;
        }
    }

    // 删除
    void remove(int value) {
        std::vector<SkipListNode*> update(MAX_LEVEL, nullptr);
        SkipListNode* curr = head;

        for (int i = level - 1; i >= 0; i--) {
            while (curr->next[i] && curr->next[i]->value < value) {
                curr = curr->next[i];
            }
            update[i] = curr;
        }

        curr = curr->next[0];
        if (curr && curr->value == value) {
            for (int i = 0; i < level; i++) {
                if (update[i]->next[i] != curr) {
                    break;
                }
                update[i]->next[i] = curr->next[i];
            }
            delete curr;

            while (level > 1 && head->next[level - 1] == nullptr) {
                level--;
            }
        }
    }

    // 打印跳表
    void print() {
        for (int i = level - 1; i >= 0; i--) {
            SkipListNode* curr = head->next[i];
            std::cout << "Level " << i << ": ";
            while (curr) {
                std::cout << curr->value << " ";
                curr = curr->next[i];
            }
            std::cout << std::endl;
        }
    }
};

```
