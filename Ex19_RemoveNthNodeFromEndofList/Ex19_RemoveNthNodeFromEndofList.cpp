#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode * removeNthFromEnd(ListNode* head, int n) {
		ListNode * p = head;
		std::vector<ListNode*> nodes;
		while (p != nullptr)
		{
			nodes.push_back(p);
			p = p->next;
		}
		nodes.push_back(nullptr);

		int total = nodes.size() - 1;
		if (n == total)
			return nodes[1];
		nodes[total - n - 1]->next = nodes[total - n + 1];
		return head;
	}
};
int main()
{
	//Solution().removeNthFromEnd();
    return 0;
}

