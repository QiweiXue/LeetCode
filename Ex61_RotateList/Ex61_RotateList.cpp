#include <utility.h>

class Solution {
 public:
  ListNode *rotateRight(ListNode *head, int k) {
	if (head==NULL)
	  return NULL;
	ListNode *tail = head;
	int length = 1;
	while (tail->next!=NULL) {
	  length++;
	  tail = tail->next;
	}
	k = length - k%length;
	if (k==0 || k==length)
	  return head;
	ListNode *changeNode = head;
	while (--k > 0)
	  changeNode = changeNode->next;
	tail->next = head;
	ListNode *res = changeNode->next;
	changeNode->next = NULL;
	ListNode *changeNodeNext = changeNode->next;
	return res;
  }
};

int main() {
  ListNode l1(1), l2(2), l3(3), l4(4), l5(5);
  l1.next = &l2;
  // l2.next = &l3;
//  l3.next = &l4;
//  l4.next = &l5;

  auto res = Solution().rotateRight(&l1, 1);
  printList(res);
  return 0;
}

