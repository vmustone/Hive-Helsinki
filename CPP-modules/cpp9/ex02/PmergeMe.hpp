#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <sstream>
#include <vector>

void mergeInsertSortVec(std::vector<int> &container, int start, int end);
void mergeSortVec(std::vector<int> &container, int start, int mid, int end);
void insertSortVec(std::vector<int> &container, int start, int end);

void mergeInsertSortDeq(std::deque<int> &container, int start, int end);
void mergeSortDeq(std::deque<int> &container, int start, int mid, int end);
void insertSortDeq(std::deque<int> &container, int start, int end);

void caluclateTime(std::vector<int> &Vcon, std::deque<int> &Dcon, double &vecTime, double &deqTime);
void print(std::vector<int> &Vec, std::deque<int> &Deq);

#endif