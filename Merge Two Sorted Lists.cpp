#include <iostream>
#include <filesystem>
#include <vector>
#include <iterator>
#include <algorithm>
#include <stack>

using namespace std;
using namespace filesystem;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *newList, *tmp, *now;
        if(list1 == nullptr)
        {
            return list2;
        }
        else if(list2 == nullptr)
        {
            return list1;
        }
        
        if(list1->val < list2->val)  // set the begining of the sorted list
        {
            newList = list1;
            list1 = list1->next;  // move the ptr to the position of uncompare node after compare
        }
        else 
        {
            newList = list2;
            list2 = list2->next;
        }
        now = newList;  // set the ptr to the node of last compared node, which is the end of newList

        while(list1 != nullptr && list2 != nullptr)
        {
            if(list1->val < list2->val)
            {
                now->next = list1;
                list1 = list1->next;
            }
            else
            {
                now->next = list2;
                list2 = list2->next;
            }
            now = now->next;
        }
        if(list1 == nullptr)
        {
            now->next = list2;
        }
        else
        {
            now->next = list1;
        }
        return newList;
    }

    void print_list(ListNode *list) {
        while (list != nullptr)
        {
            cout << list->val << "->";
            list = list->next;
        }
        cout << endl;
    }
};

int main(void) {
    Solution s;
    
    ListNode a(1);
    ListNode b(2);
    ListNode c(4);
    a.next = &b;
    b.next = &c;

    ListNode x(1);
    ListNode y(2);
    ListNode z(4);
    x.next = &y;
    y.next = &z;

    s.print_list(s.mergeTwoLists(&a, &x));
}