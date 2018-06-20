#include <utility.h>
#include <xhash>

using namespace std;

class Solution {
public:
	ListNode * reverseBetween(ListNode* head, int m, int n) {
		int length = n - m;
		if (m == n)
			return head;
		ListNode * virtualHead = new ListNode(0);
		virtualHead->next = head;
		ListNode * h = virtualHead;
		while ( -- m)
		{
			h = h->next;
		}

		ListNode* p = h->next;
		ListNode* pbak = p;
		ListNode* q = p->next;
		ListNode* r;
		while ( length -- )
		{
			r = q->next;
			q->next = p;
			p = q;
			q = r;
		}
		h->next = p;
		pbak->next = r;

		auto res = virtualHead->next;
		delete virtualHead;
		return res;

	}
};

int main(int argc, char* argv[])
{
	ListNode l1(1), l2(2), l3(3), l4(4), l5(5);
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l4;
	l4.next = &l5;
	auto res = Solution().reverseBetween(&l1, 2, 4);
	printList(res);
	return 0;
}
