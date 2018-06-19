#include <utility.h>

using namespace std;


class Solution {
public:
	ListNode * partition(ListNode* head, int x) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode * virtualHead = new ListNode(0);
		virtualHead->next = head;
		ListNode * p = virtualHead;
		ListNode * s = head;
		ListNode * preS = virtualHead;
		ListNode * afterS;
		ListNode * afterP;
		while (s != NULL)
		{
			if (s->val >= x)
			{
				preS = s;
				s = s->next;
			}
			else
			{
				if (p->next == s)
				{
					p = s;
					preS = p;
					s = s->next;
				}
				else 
				{
					afterS = s->next;
					preS->next = afterS;

					afterP = p->next;
					p->next = s;
					s->next = afterP;
					p = s;
					s = afterS;
				}
			}
		}

		auto res = virtualHead->next;
		delete virtualHead;
		return res;
	}
};

int main()
{
	ListNode l1(1), l2(2), l3(3), l4(2), l5(5), l6(2);
	l1.next = &l2;
	/*l2.next = &l3;
	l3.next = &l4;
	l4.next = &l5;
	l5.next = &l6;*/
	auto res = Solution().partition(&l1, 3);
	printList(res);
	return 0;
}
