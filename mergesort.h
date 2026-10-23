#pragma once
#include <vector>

struct SortStatistics {
    unsigned long long comparisons = 0;
    double execution_time_ms = 0.0;
};

void Merge(const std::vector<int>& B, const std::vector<int>& C, std::vector<int>& A, unsigned long long& comp_counter);
void MergeSortRecursive(std::vector<int>& A, unsigned long long& comp_counter);
SortStatistics RunMergeSort(std::vector<int>& A);
