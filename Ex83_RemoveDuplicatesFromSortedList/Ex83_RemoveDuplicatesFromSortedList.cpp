#include <utility.h>

using namespace std;

class Solution {
public:
	ListNode * deleteDuplicates(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode * p = head;
		ListNode * s = head->next;
		while (s != NULL)
		{
			if(s->val != p->val)
			{
				p->next = s;
				p = s;
			}
			s = s->next;
		}
		p->next = NULL;
		return head;
	}
};

int main()
{
	ListNode l1(1), l2(1), l3(2), l4(3), l5(4), l6(4);
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l4;
	l4.next = &l5;
	l5.next = &l6;
	auto res = Solution().deleteDuplicates(&l1);
	printList(res);
	return 0;
}
