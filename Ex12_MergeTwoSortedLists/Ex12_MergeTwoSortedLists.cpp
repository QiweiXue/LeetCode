#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode* l)
{
	while (l != NULL)
	{
		std::cout << l->val << " ";
		l = l->next;
	}
	std::cout << std::endl;
}

class Solution {
public:
	ListNode * mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode virtualHead(0);
		ListNode * head = &virtualHead;
		ListNode * pos = head;
		while (!((l1 == NULL) && (l2 == NULL)))
		{
			if (((l2 != NULL) && (l1 != NULL) && (l1->val < l2->val))
				|| (l2 == NULL))
			{
				pos->next = l1;
				pos = pos->next;
				l1 = l1->next;
			}
			else if (((l1 != NULL)&&(l2!=NULL)&&(l1->val >= l2->val))
				||(l1 == NULL))
			{
				pos->next = l2;
				pos = pos->next;
				l2 = l2->next;
			}
		}
		return head->next;
	}
};


int main()
{
	ListNode l1(1), l3(3), l4(4);
	l1.next = &l3;
	l3.next = &l4;

	ListNode ll1(1), ll2(2), ll3(3);
	ll1.next = &ll2;
	ll2.next = &ll3;

	auto res = Solution().mergeTwoLists(&l1, &ll1);
	printList(res);
    return 0;
}

