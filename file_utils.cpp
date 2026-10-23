#include "file_utils.h"
#include <fstream>
#include <random>

std::vector<int> GenerateRandomSequence(int size, int min_val, int max_val) {
    std::vector<int> data(size);
    std::mt19937 rng(1337);
    std::uniform_int_distribution<int> dist(min_val, max_val);

    for (int i = 0; i < size; ++i) {
        data[i] = dist(rng);
    }
    return data;
}

bool SaveToFile(const std::string& filename, const std::vector<int>& data) {
    std::ofstream out(filename);
    if (!out.is_open()) {
        return false;
    }

    for (size_t i = 0; i < data.size(); ++i) {
        out << data[i] << " ";
        if ((i + 1) % 20 == 0) {
            out << "\n";
        }
    }
    out.close();
    return true;
}