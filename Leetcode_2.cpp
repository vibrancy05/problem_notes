#include <iostream>
#include<vector>
using namespace std;
//定义数据结构
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 //初始状态：值为0的头结点
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0); // 虚拟头节点，简化操作
        ListNode* current = head; // 当前节点，用于构建结果链表
        int carry = 0; // 进位值

        // 遍历两个链表
        while (l1 || l2 || carry) {//当这一位有数字的时候
            int x = l1 ? l1->val : 0; // 获取 l1 的当前值
            int y = l2 ? l2->val : 0; // 获取 l2 的当前值
            int sum = x + y + carry; // 计算当前位的和
            carry = sum / 10; // 更新进位值
            current->next = new ListNode(sum % 10); // 创建新节点，存储当前位的值
            current = current->next; // 移动 current 指针

            // 移动 l1 和 l2 的指针
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        return head->next; // 返回结果链表的头结点的next，也就是携带第一个有效数字的结点
    }
};

// 辅助函数：创建链表
ListNode* createList(vector<int> nums) {
    ListNode* head = new ListNode(0);
    ListNode* current = head;
    for (int num : nums) {
        current->next = new ListNode(num);
        current = current->next;
    }
    return head->next;
}

// 辅助函数：打印链表
void printList(ListNode* head) {
    while (head) {
        while (head->next) {
            cout << head->val << "->";
            head = head->next;
        }
        cout << head->val << endl;
        break;
    }
}

int main() {
    Solution solution;

    // 测试用例 1
    ListNode* l1 = createList({ 2, 4, 3 }); // 链表 1: 2 -> 4 -> 3
    ListNode* l2 = createList({ 5, 6, 4 }); // 链表 2: 5 -> 6 -> 4
    ListNode* result1 = solution.addTwoNumbers(l1, l2);
    cout << "Test case 1: ";
    printList(result1); // 预期输出: 7 -> 0 -> 8

    // 测试用例 2
    ListNode* l3 = createList({ 0 }); // 链表 1: 0
    ListNode* l4 = createList({ 0 }); // 链表 2: 0
    ListNode* result2 = solution.addTwoNumbers(l3, l4);
    cout << "Test case 2: ";
    printList(result2); // 预期输出: 0

    // 测试用例 3
    ListNode* l5 = createList({ 9, 9, 9, 9, 9, 9, 9 }); // 链表 1: 9 -> 9 -> 9 -> 9 -> 9 -> 9 -> 9
    ListNode* l6 = createList({ 9, 9, 9, 9 }); // 链表 2: 9 -> 9 -> 9 -> 9
    ListNode* result3 = solution.addTwoNumbers(l5, l6);
    cout << "Test case 3: ";
    printList(result3); // 预期输出: 8 -> 9 -> 9 -> 9 -> 0 -> 0 -> 0 -> 1

    // 测试用例 4 (一个链表为空)
    ListNode* l7 = createList({ 1, 2, 3 }); // 链表 1: 1 -> 2 -> 3
    ListNode* l8 = createList({}); // 链表 2: 空链表
    ListNode* result4 = solution.addTwoNumbers(l7, l8);
    cout << "Test case 4: ";
    printList(result4); // 预期输出: 1 -> 2 -> 3

    // 测试用例 5 (两个链表长度不同)
    ListNode* l9 = createList({ 1, 8 }); // 链表 1: 1 -> 8
    ListNode* l10 = createList({ 0 }); // 链表 2: 0
    ListNode* result5 = solution.addTwoNumbers(l9, l10);
    cout << "Test case 5: ";
    printList(result5); // 预期输出: 1 -> 8

    return 0;
}