#include "mergesort.h"
#include <chrono>

void Merge(const std::vector<int>& B, const std::vector<int>& C, std::vector<int>& A, unsigned long long& comp_counter) {
    int p = static_cast<int>(B.size());
    int q = static_cast<int>(C.size());
    int i = 0, j = 0, k = 0;

    while (i < p && j < q) {
        comp_counter++;
        if (B[i] <= C[j]) {
            A[k] = B[i];
            i++;
        }
        else {
            A[k] = C[j];
            j++;
        }
        k++;
    }

    if (i == p) {
        while (j < q) {
            A[k++] = C[j++];
        }
    }
    else {
        while (i < p) {
            A[k++] = B[i++];
        }
    }
}

void MergeSortRecursive(std::vector<int>& A, unsigned long long& comp_counter) {
    int n = static_cast<int>(A.size());
    if (n > 1) {
        int mid = n / 2;

        std::vector<int> B(A.begin(), A.begin() + mid);
        std::vector<int> C(A.begin() + mid, A.end());

        MergeSortRecursive(B, comp_counter);
        MergeSortRecursive(C, comp_counter);

        Merge(B, C, A, comp_counter);
    }
}

SortStatistics RunMergeSort(std::vector<int>& A) {
    SortStatistics stats;
    stats.comparisons = 0;

    auto start = std::chrono::high_resolution_clock::now();
    MergeSortRecursive(A, stats.comparisons);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> duration = end - start;
    stats.execution_time_ms = duration.count();

    return stats;
}