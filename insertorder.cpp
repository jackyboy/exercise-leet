/**
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ret = nullptr;
        vector<int> r;
        while (list1 != nullptr || list2 != nullptr) {
            if (list1 == nullptr) {
                if (list2 != nullptr) {
                    r.push_back(list2->val);
                    list2 = list2->next;
                }
            } else if (list2 == nullptr) {
                if (list1 != nullptr) {
                    r.push_back(list1->val);
                    list1 = list1->next;
                }
            } else if (list1->val <= list2->val) {
                r.push_back(list1->val);
                list1 = list1->next;
            } else {
                r.push_back(list2->val);
                list2 = list2->next;
            }
        }
        for (int i = r.size() - 1; i >= 0; i--) {
            ListNode* el = new ListNode(r[i]);
            el->next = ret;
            ret = el;
        }
        return ret;
    }
};