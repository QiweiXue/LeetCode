#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode * swapPairs(ListNode* head) {
		if (head == NULL)
			return head;
		ListNode* virtualHead =  new ListNode(0);
		virtualHead->next = head;
		ListNode * pre = virtualHead, * first , *second, * third;
		while (true)
		{
			first = pre->next;
			if (first == NULL)
				break;
			second = first->next;
			if (second == NULL)
				break;
			third = second->next;

			first->next = third;
			second->next = first;
			pre->next = second;

			pre = first;
		}

		ListNode* res = virtualHead->next;
		delete virtualHead;
		return res;
	}
};

int main()
{
	ListNode l1(1), l2(2), l3(3),l4(4), l5(5);
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l4;
	l4.next = &l5;
	
	ListNode * res = Solution().swapPairs(&l1);
	while (res != NULL)
	{
		std::cout << res->val;
		res = res->next;
	}

    return 0;
}

