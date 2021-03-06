#include<iostream>
#include <vector>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode * reverseKGroup(ListNode* head, int k) {
		if (head == NULL || k < 2)
			return head;
		ListNode* virtualHead = new ListNode(0);
		virtualHead->next = head;
		
		ListNode* pre = virtualHead;
		ListNode* first , *last, *back;
		while (true)
		{
			first = pre->next;
			if (first == NULL)
				break;
			int kk = k;
			last = pre;
			while (kk--)
			{
				last = last->next;
				if (last == NULL)
					goto finish;
			}
			back = last->next;

			int kkk = k - 1;
			ListNode *f, *s, *t;
			f = first;
			s = first->next;
			t = s->next;
			while (kkk--)
			{
				s->next = f;
				f = s;
				s = t;
				if (s != NULL)
					t = s->next;
			}
			pre->next = f;
			first->next = back;
			pre = first;
		}
finish :	
		ListNode* res = virtualHead->next;
		delete virtualHead;
		return res;
	}
};

int main()
{
	ListNode l1(1), l2(2), l3(3), l4(4), l5(5);
	l1.next = &l2;
	/*l2.next = &l3;
	l3.next = &l4;
	l4.next = &l5;*/

	ListNode * res = Solution().reverseKGroup(&l1, 2);
	while (res != NULL)
	{
		std::cout << res->val;
		res = res->next;
	}
	return 0;
}

