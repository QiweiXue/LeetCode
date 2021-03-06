//
// Created by only on 18-6-2.
//

#ifndef LEETCODE_UTILITY_H
#define LEETCODE_UTILITY_H

#include <iostream>
#include <vector>
#include <string>
#include <cstddef>
#include <algorithm>

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
template< typename T>
void printMatrix(std::vector<std::vector<T>> &mat) {
  for (auto &a : mat) {
	for (auto &b : a)
	  std::cout << b << " ";
	std::cout << std::endl;
  }
}

// digits
template<typename T>
void printDigits(std::vector<T> &digits) {
  for (auto &a : digits)
	std::cout << a << " ";
  std::cout << std::endl;
}

#endif //LEETCODE_UTILITY_H
