/**
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ret = nullptr;
        vector<int> v;
        for (int i = 0; i < lists.size(); i++) {
            ListNode* a = lists[i];
            while (a != nullptr) {
                v.push_back(a->val);
                a = a->next;
            }
        }

        for(int i=0; i<v.size(); i++){
            for(int j=i+1; j<v.size(); j++){
                if(v[i]>v[j]){
                    int q = v[i];
                    v[i] = v[j];
                    v[j] = q;
                }
            }
        }

        for (int i = v.size() - 1; i >= 0; i--) {
            ListNode* el = new ListNode(v[i]);
            el->next = ret;
            ret = el;
        }
        return ret;
    }
};