#ifndef S21_FAST_MATRIX_TESTS_CLASSES_TEST_HELPER_H_
#define S21_FAST_MATRIX_TESTS_CLASSES_TEST_HELPER_H_

#include "../../include/fast_matrix/fast_matrix.h"

namespace s21_matrix_test_helper {

constexpr double kEpsilon = 1e-6;
constexpr int kRandomTestNum = 50;
constexpr int kRandomMatrixMaxSize = 20;  // 9!

template <typename Type>
s21::FastMatrix<Type> TestMoveConstructor(s21::FastMatrix<Type> test) {
  return test;
}

int GetRandInt(const int min, int max);
double GetRandDouble(const double min, double max);

template <typename Type>
s21::FastMatrix<Type> GetRandMatrix(int rows, int cols, double min,
                                    double max) {
  s21::FastMatrix<Type> result{rows, cols};

  for (int i = 0; i < result.get_rows(); ++i) {
    for (int j = 0; j < result.get_cols(); ++j) {
      result(i, j) = s21_matrix_test_helper::GetRandDouble(min, max);
    }
  }

  return result;
}

template <typename Type>
void FillMatrix(s21::FastMatrix<Type>& matrix, double value) {
  for (int i = 0; i < matrix.get_rows(); ++i) {
    for (int j = 0; j < matrix.get_cols(); ++j) {
      matrix(i, j) = value;
    }
  }
}

template <typename Type>
void CheckMatrix(const s21::FastMatrix<Type>& matrix, double value) {
  for (int i = 0; i < matrix.get_rows(); ++i) {
    for (int j = 0; j < matrix.get_cols(); ++j) {
      ASSERT_NEAR(matrix(i, j), value, s21_matrix_test_helper::kEpsilon);
    }
  }
}

template <typename Type>
s21::FastMatrix<Type> GetIdentityMatrix(int size) {
  s21::FastMatrix<Type> result{size, size};

  for (int i = 0; i < result.get_rows(); i++) {
    for (int j = 0; j < result.get_cols(); j++) {
      if (i == j) {
        result(i, j) = 1.0;
      }
    }
  }

  return result;
}

}  // namespace s21_matrix_test_helper

#endif  // S21_FAST_MATRIX_TESTS_CLASSES_TEST_HELPER_H_
