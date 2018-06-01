//
// Created by only on 18-6-2.
//

#ifndef LEETCODE_UTILITY_H
#define LEETCODE_UTILITY_H

#include <iostream>
#include <vector>
#include <string>
#include <cstddef>

// list
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode *l) {
  while (l!=NULL) {
	std::cout << l->val << " ";
	l = l->next;
  }
  std::cout << std::endl;
}

// Matrix
void printMatrix(std::vector<std::vector<int>> &mat) {
  for (auto &a : mat) {
	for (auto &b : a)
	  std::cout << b << " ";
	std::cout << std::endl;
  }
}

#endif //LEETCODE_UTILITY_H
