#pragma once
#include <vector>
#include <string>

std::vector<int> GenerateRandomSequence(int size, int min_val = -10000, int max_val = 10000);
bool SaveToFile(const std::string& filename, const std::vector<int>& data);