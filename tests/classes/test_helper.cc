#include "test_helper.h"

#include <gtest/gtest.h>

#include <random>

namespace s21_matrix_test_helper {

int GetRandInt(int min, int max) {
  std::random_device rd;
  std::mt19937 generator(rd());
  std::uniform_int_distribution<> distribution(min, max);
  return distribution(generator);
}

double GetRandDouble(double min, double max) {
  std::random_device rd;
  std::mt19937 generator(rd());
  std::uniform_real_distribution<double> distribution(min, max);
  return distribution(generator);
}

}  // namespace s21_matrix_test_helper
