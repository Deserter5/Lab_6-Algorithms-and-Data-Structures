#include <iostream>
#include <string>
#include "mergesort.h"
#include "file_utils.h"

int main() {
    std::cout << "        Lab Work #6: Merge Sort Algorithm            \n";

    int n;
    std::cout << "Enter the size of the random sequence (n): ";
    if (!(std::cin >> n) || n <= 0) {
        std::cerr << "Error: Invalid input size.\n";
        return 1;
    }

    std::string baseName;
    std::cout << "Enter the base file name (e.g. 'dataset'): ";
    std::cin >> baseName;

    std::string rawFileName = baseName + ".txt";
    std::string sortedFileName = baseName + ".sorted";

    std::cout << "\n[1] Generating " << n << " random numbers...\n";
    std::vector<int> array = GenerateRandomSequence(n);

    if (!SaveToFile(rawFileName, array)) {
        std::cerr << "Error: Failed to write to " << rawFileName << "\n";
        return 1;
    }
    std::cout << "  -> Random sequence saved to: " << rawFileName << "\n";

    std::cout << "\n[2] Running MergeSort...\n";
    SortStatistics stats = RunMergeSort(array);

    if (!SaveToFile(sortedFileName, array)) {
        std::cerr << "Error: Failed to write to " << sortedFileName << "\n";
        return 1;
    }
    std::cout << "  -> Sorted sequence saved to: " << sortedFileName << "\n";

    std::cout << "\nEXECUTION RESULTS\n";
    std::cout << "Array size (n):           " << n << "\n";
    std::cout << "Comparisons count:        " << stats.comparisons << "\n";
    std::cout << "Execution time:           " << stats.execution_time_ms << " ms\n";

    return 0;
}