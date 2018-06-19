#include <utility.h>

using namespace std;

class Solution {
public:
	ListNode * deleteDuplicates(ListNode* head) {
		if (head == NULL)
			return head;
		ListNode * virtualHead = new ListNode(head->val - 1);
		virtualHead->next = head;
		ListNode * p = virtualHead;
		ListNode * s = head;
		int preVal = virtualHead->val;
		while(s != NULL)
		{
			if (s->val != preVal && (s->next == NULL || s->val != s->next->val))
			{
				p->next = s;
				p = s;
			}
			preVal = s->val;
			s = s->next;
		}
		p->next = NULL;

		ListNode* res = virtualHead->next;
		delete virtualHead;
		return res;
	}
};

int main()
{
	ListNode l1(1), l2(1), l3(2), l4(3), l5(3), l6(4);
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l4;
	l4.next = &l5;
	l5.next = &l6;
	auto res = Solution().deleteDuplicates(&l1);
	printList(res);
	return 0;
}