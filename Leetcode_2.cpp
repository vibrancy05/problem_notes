#include <iostream>
#include<vector>
using namespace std;
//�������ݽṹ
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 //��ʼ״̬��ֵΪ0��ͷ���
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0); // ����ͷ�ڵ㣬�򻯲���
        ListNode* current = head; // ��ǰ�ڵ㣬���ڹ����������
        int carry = 0; // ��λֵ

        // ������������
        while (l1 || l2 || carry) {//����һλ�����ֵ�ʱ��
            int x = l1 ? l1->val : 0; // ��ȡ l1 �ĵ�ǰֵ
            int y = l2 ? l2->val : 0; // ��ȡ l2 �ĵ�ǰֵ
            int sum = x + y + carry; // ���㵱ǰλ�ĺ�
            carry = sum / 10; // ���½�λֵ
            current->next = new ListNode(sum % 10); // �����½ڵ㣬�洢��ǰλ��ֵ
            current = current->next; // �ƶ� current ָ��

            // �ƶ� l1 �� l2 ��ָ��
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        return head->next; // ���ؽ�������ͷ����next��Ҳ����Я����һ����Ч���ֵĽ��
    }
};

// ������������������
ListNode* createList(vector<int> nums) {
    ListNode* head = new ListNode(0);
    ListNode* current = head;
    for (int num : nums) {
        current->next = new ListNode(num);
        current = current->next;
    }
    return head->next;
}

// ������������ӡ����
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

    // �������� 1
    ListNode* l1 = createList({ 2, 4, 3 }); // ���� 1: 2 -> 4 -> 3
    ListNode* l2 = createList({ 5, 6, 4 }); // ���� 2: 5 -> 6 -> 4
    ListNode* result1 = solution.addTwoNumbers(l1, l2);
    cout << "Test case 1: ";
    printList(result1); // Ԥ�����: 7 -> 0 -> 8

    // �������� 2
    ListNode* l3 = createList({ 0 }); // ���� 1: 0
    ListNode* l4 = createList({ 0 }); // ���� 2: 0
    ListNode* result2 = solution.addTwoNumbers(l3, l4);
    cout << "Test case 2: ";
    printList(result2); // Ԥ�����: 0

    // �������� 3
    ListNode* l5 = createList({ 9, 9, 9, 9, 9, 9, 9 }); // ���� 1: 9 -> 9 -> 9 -> 9 -> 9 -> 9 -> 9
    ListNode* l6 = createList({ 9, 9, 9, 9 }); // ���� 2: 9 -> 9 -> 9 -> 9
    ListNode* result3 = solution.addTwoNumbers(l5, l6);
    cout << "Test case 3: ";
    printList(result3); // Ԥ�����: 8 -> 9 -> 9 -> 9 -> 0 -> 0 -> 0 -> 1

    // �������� 4 (һ������Ϊ��)
    ListNode* l7 = createList({ 1, 2, 3 }); // ���� 1: 1 -> 2 -> 3
    ListNode* l8 = createList({}); // ���� 2: ������
    ListNode* result4 = solution.addTwoNumbers(l7, l8);
    cout << "Test case 4: ";
    printList(result4); // Ԥ�����: 1 -> 2 -> 3

    // �������� 5 (���������Ȳ�ͬ)
    ListNode* l9 = createList({ 1, 8 }); // ���� 1: 1 -> 8
    ListNode* l10 = createList({ 0 }); // ���� 2: 0
    ListNode* result5 = solution.addTwoNumbers(l9, l10);
    cout << "Test case 5: ";
    printList(result5); // Ԥ�����: 1 -> 8

    return 0;
}