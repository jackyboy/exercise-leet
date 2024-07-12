/**
 * You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
 *	You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int n = 0;
        int c = 0;
        int r = 0;
        n = l1->val;
        c = l2->val;
        l1 = l1->next;
        l2 = l2->next;
        int sum = n + c;

        if (sum - 10 >= 0) {
            sum = sum - 10 + r;
            if (sum >= 10) {
                sum = sum - 10;
            }
            r = 1;
        } else {
            sum = sum + r;
            if (sum >= 10) {
                sum = sum - 10;
                r = 1;
            } else {
                r = 0;
            }
        }

        ListNode* ret = new ListNode(sum);

        while (l1 != nullptr || l2 != nullptr) {
            n = 0;
            c = 0;
            if (l1 != nullptr) {
                n = l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                c = l2->val;
                l2 = l2->next;
            }
            sum = n + c;
            if (sum - 10 >= 0) {
                sum = sum - 10 + r;
                if (sum >= 10) {
                    sum = sum - 10;
                }
                r = 1;
            } else {
                sum = sum + r;
                if (sum >= 10) {
                    sum = sum - 10;
                    r = 1;
                } else {
                    r = 0;
                }
            }
            ListNode* el = new ListNode(sum);
            el->next = ret;
            ret = el;
        }
        if (r == 1) {
            ListNode* el = new ListNode(1);
            el->next = ret;
            ret = el;
        }
        int* arr;
        arr = listToArray(ret);

        ListNode* res = arrayToList(arr);

        return res;
    }

    int* listToArray(ListNode* l) {
        int* a = new int[100];
        for (int i = 0; i < 100; i++) {
            a[i] = -1;
        }
        int j = 0;
        while (l != nullptr) {
            a[j] = l->val;
            l = l->next;
            j=j+1;
        }
        return a;
    }

    ListNode* arrayToList(int* a) {
        ListNode* ret = new ListNode(a[0]);
        for (int i = 1; i < 100; i++) {
            if (a[i] != -1) {
                ListNode* el = new ListNode(a[i]);
                el->next = ret;
                ret = el;
            } else {
                break;
            }
        }
        return ret;
    }
};