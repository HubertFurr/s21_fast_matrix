#ifndef S21_FAST_MATRIX_TESTS_CLASSES_RANDOM_SUITES_H_
#define S21_FAST_MATRIX_TESTS_CLASSES_RANDOM_SUITES_H_

#include <gtest/gtest.h>

#include "../../include/fast_matrix/fast_matrix.h"
#include "test_helper.h"

template <typename Type>
class RandomMulNumberMatrixRangeOne : public ::testing::TestWithParam<int> {
 public:
  RandomMulNumberMatrixRangeOne() {
    int num_rows = s21_matrix_test_helper::GetRandInt(
        1, s21_matrix_test_helper::kRandomMatrixMaxSize);
    int num_cols = num_rows;

    test_matrix_ = s21_matrix_test_helper::GetRandMatrix<Type>(
        num_rows, num_cols, -1e4, 1e4);
  }

 protected:
  s21::FastMatrix<Type> test_matrix_;
};

template <typename Type>
class RandomMulMatrixRangeOne : public ::testing::TestWithParam<int> {
 public:
  RandomMulMatrixRangeOne() {
    int num_rows = s21_matrix_test_helper::GetRandInt(
        1, s21_matrix_test_helper::kRandomMatrixMaxSize);
    int num_cols = num_rows;

    test_matrix_ = s21_matrix_test_helper::GetRandMatrix<Type>(
        num_rows, num_cols, -1e4, 1e4);
  }

 protected:
  s21::FastMatrix<Type> test_matrix_;
};

#endif  // S21_FAST_MATRIX_TESTS_CLASSES_RANDOM_SUITES_H_
