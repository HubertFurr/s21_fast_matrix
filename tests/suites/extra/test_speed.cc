#include <chrono>
#include <iostream>

#include "./../../test.h"

TEST(TestSpeed, TestCreate1) {
  int rows = 5120;
  int cols = 5120;
  std::cout << "[" << rows << " x " << cols << "]" << std::endl;

  float** matrix1 = nullptr;
  float* matrix2 = nullptr;

  auto start1 = std::chrono::steady_clock::now();
  matrix1 = new float* [rows] {};
  for (int i = 0; i < rows; ++i) {
    matrix1[i] = new float[cols]{};
  }
  auto end1 = std::chrono::steady_clock::now();
  auto diff1 = end1 - start1;
  std::cout
      << "new float**: "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;

  auto start2 = std::chrono::steady_clock::now();
  matrix2 = new float[rows * cols]{};
  auto end2 = std::chrono::steady_clock::now();
  auto diff2 = end2 - start2;
  std::cout
      << "new float*: "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff2).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff2).count()
      << " ms)" << std::endl;

  start1 = std::chrono::steady_clock::now();
  for (int i = 0; i < rows; ++i) {
    delete[] matrix1[i];
  }
  delete[] matrix1;
  matrix1 = nullptr;
  end1 = std::chrono::steady_clock::now();
  diff1 = end1 - start1;
  std::cout
      << "delete float**: "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;

  start2 = std::chrono::steady_clock::now();
  delete[] matrix2;
  matrix2 = nullptr;
  end2 = std::chrono::steady_clock::now();
  diff2 = end2 - start2;
  std::cout
      << "delete float*: "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff2).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff2).count()
      << " ms)" << std::endl;

  start2 = std::chrono::steady_clock::now();
  s21::FastMatrix<float>{rows, cols};
  end2 = std::chrono::steady_clock::now();
  diff2 = end2 - start2;
  std::cout
      << "new matrix"
      << "[" << rows << " x " << cols << "]"
      << ": "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff2).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff2).count()
      << " ms)" << std::endl;
}

TEST(TestSpeed, TestCreate2) {
  int rows = 512;
  int cols = 512;
  std::cout << "[" << rows << " x " << cols << "]" << std::endl;

  float** matrix1 = nullptr;
  float* matrix2 = nullptr;

  auto start1 = std::chrono::steady_clock::now();
  matrix1 = new float* [rows] {};
  for (int i = 0; i < rows; ++i) {
    matrix1[i] = new float[cols]{};
  }
  auto end1 = std::chrono::steady_clock::now();
  auto diff1 = end1 - start1;
  std::cout
      << "new float**: "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;

  auto start2 = std::chrono::steady_clock::now();
  matrix2 = new float[rows * cols]{};
  auto end2 = std::chrono::steady_clock::now();
  auto diff2 = end2 - start2;
  std::cout
      << "new float*: "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff2).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff2).count()
      << " ms)" << std::endl;

  start1 = std::chrono::steady_clock::now();
  for (int i = 0; i < rows; ++i) {
    delete[] matrix1[i];
  }
  delete[] matrix1;
  matrix1 = nullptr;
  end1 = std::chrono::steady_clock::now();
  diff1 = end1 - start1;
  std::cout
      << "delete float**: "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;

  start2 = std::chrono::steady_clock::now();
  delete[] matrix2;
  matrix2 = nullptr;
  end2 = std::chrono::steady_clock::now();
  diff2 = end2 - start2;
  std::cout
      << "delete float*: "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;

  start2 = std::chrono::steady_clock::now();
  s21::FastMatrix<float>{rows, cols};
  end2 = std::chrono::steady_clock::now();
  diff2 = end2 - start2;
  std::cout
      << "new matrix"
      << "[" << rows << " x " << cols << "]"
      << ": "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff2).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff2).count()
      << " ms)" << std::endl;
}

TEST(TestSpeed, TestCopy1) {
  int rows = 5120;
  int cols = 5120;
  std::cout << "[" << rows << " x " << cols << "]" << std::endl;

  s21::FastMatrix<float> matrix1(rows, cols);

  s21_matrix_test_helper::FillMatrix(matrix1, 2.1);

  auto start = std::chrono::steady_clock::now();
  s21::FastMatrix<float> matrix2(matrix1);
  auto end = std::chrono::steady_clock::now();
  auto diff = end - start;
  std::cout
      << "Copy matrix(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff).count()
      << " ms)" << std::endl;
}

TEST(TestSpeed, TestMove1) {
  int rows = 5120;
  int cols = 5120;
  std::cout << "[" << rows << " x " << cols << "]" << std::endl;

  s21::FastMatrix<float> matrix1(rows, cols);

  s21_matrix_test_helper::FillMatrix(matrix1, 2.1);
  s21::FastMatrix<float> matrix_copy1 = matrix1;
  s21::FastMatrix<float> matrix_copy2 = matrix1;

  auto start = std::chrono::steady_clock::now();
  s21::FastMatrix<float> matrix2(std::move(matrix1));
  auto end = std::chrono::steady_clock::now();
  auto diff = end - start;
  std::cout
      << "Move ctor(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff).count()
      << " ms)" << std::endl;

  start = std::chrono::steady_clock::now();
  matrix_copy1 = std::move(matrix_copy2);
  end = std::chrono::steady_clock::now();
  diff = end - start;
  std::cout
      << "Move assign(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff).count()
      << " ms)" << std::endl;
}

TEST(TestSpeed, TestEq1) {
  int rows = 5120;
  int cols = 5120;
  std::cout << "[" << rows << " x " << cols << "]"
            << " == "
            << "[" << rows << " x " << cols << "]" << std::endl;

  s21::FastMatrix<float> matrix1(rows, cols);
  s21::FastMatrix<float> matrix2(rows, cols);

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0);
  s21_matrix_test_helper::FillMatrix(matrix2, 1.0);

  auto start1 = std::chrono::steady_clock::now();
  bool result = matrix1 == matrix2;
  auto end1 = std::chrono::steady_clock::now();
  auto diff1 = end1 - start1;
  std::cout
      << "Equal matrix: "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;
  EXPECT_TRUE(result);
}

TEST(TestSpeed, TestSum1) {
  int rows = 5120;
  int cols = 5120;
  std::cout << "[" << rows << " x " << cols << "]"
            << " + "
            << "[" << rows << " x " << cols << "]" << std::endl;

  s21::FastMatrix<float> matrix1(rows, cols);
  s21::FastMatrix<float> matrix2(rows, cols);

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0);

  auto start = std::chrono::steady_clock::now();
  matrix1.SumMatrix(matrix2);
  auto end = std::chrono::steady_clock::now();
  auto diff = end - start;
  std::cout
      << "SumMatrix(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff).count()
      << " ms)" << std::endl;

  start = std::chrono::steady_clock::now();
  s21::FastMatrix<float> result = matrix1 + matrix2;
  end = std::chrono::steady_clock::now();
  diff = end - start;
  std::cout
      << "operator+(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff).count()
      << " ms)" << std::endl;
}

TEST(TestSpeed, TestSum2) {
  int rows = 51200;
  int cols = 1;
  std::cout << "[" << rows << " x " << cols << "]"
            << " + "
            << "[" << rows << " x " << cols << "]" << std::endl;

  s21::FastMatrix<float> matrix1(rows, cols);
  s21::FastMatrix<float> matrix2(rows, cols);

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0);

  auto start = std::chrono::steady_clock::now();
  matrix1.SumMatrix(matrix2);
  auto end = std::chrono::steady_clock::now();
  auto diff = end - start;
  std::cout
      << "SumMatrix(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff).count()
      << " ms)" << std::endl;

  start = std::chrono::steady_clock::now();
  s21::FastMatrix<float> result = matrix1 + matrix2;
  end = std::chrono::steady_clock::now();
  diff = end - start;
  std::cout
      << "operator+(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff).count()
      << " ms)" << std::endl;
}

TEST(TestSpeed, TestSub1) {
  int rows = 5120;
  int cols = 5120;
  std::cout << "[" << rows << " x " << cols << "]"
            << " - "
            << "[" << rows << " x " << cols << "]" << std::endl;

  s21::FastMatrix<float> matrix1(rows, cols);
  s21::FastMatrix<float> matrix2(rows, cols);

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0);

  auto start = std::chrono::steady_clock::now();
  matrix1.SubMatrix(matrix2);
  auto end = std::chrono::steady_clock::now();
  auto diff = end - start;
  std::cout
      << "SubMatrix(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff).count()
      << " ms)" << std::endl;

  start = std::chrono::steady_clock::now();
  s21::FastMatrix<float> result = matrix1 - matrix2;
  end = std::chrono::steady_clock::now();
  diff = end - start;
  std::cout
      << "operator-(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff).count()
      << " ms)" << std::endl;
}

TEST(TestSpeed, TestSub2) {
  int rows = 51200;
  int cols = 1;
  std::cout << "[" << rows << " x " << cols << "]"
            << " - "
            << "[" << rows << " x " << cols << "]" << std::endl;

  s21::FastMatrix<float> matrix1(rows, cols);
  s21::FastMatrix<float> matrix2(rows, cols);

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0);

  auto start = std::chrono::steady_clock::now();
  matrix1.SubMatrix(matrix2);
  auto end = std::chrono::steady_clock::now();
  auto diff = end - start;
  std::cout
      << "SubMatrix(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff).count()
      << " ms)" << std::endl;

  start = std::chrono::steady_clock::now();
  s21::FastMatrix<float> result = matrix1 - matrix2;
  end = std::chrono::steady_clock::now();
  diff = end - start;
  std::cout
      << "operator-(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff).count()
      << " ms)" << std::endl;
}

TEST(TestSpeed, TestMulNumber1) {
  int rows = 5120;
  int cols = 5120;
  std::cout << "[" << rows << " x " << cols << "]"
            << " * 2.0" << std::endl;

  s21::FastMatrix<float> matrix1(rows, cols);
  s21_matrix_test_helper::FillMatrix(matrix1, 1.0);

  auto start1 = std::chrono::steady_clock::now();
  s21::FastMatrix<float> result = matrix1 * 2.0;
  auto end1 = std::chrono::steady_clock::now();
  auto diff1 = end1 - start1;
  std::cout
      << "opeartor*(number): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;

  start1 = std::chrono::steady_clock::now();
  matrix1.MulNumber(2.0);
  end1 = std::chrono::steady_clock::now();
  diff1 = end1 - start1;
  std::cout
      << "MulNumber(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;
}

TEST(TestSpeed, TestMulNumber2) {
  int rows = 51200;
  int cols = 1;
  std::cout << "[" << rows << " x " << cols << "]"
            << " * 2.0" << std::endl;

  s21::FastMatrix<float> matrix1(rows, cols);
  s21_matrix_test_helper::FillMatrix(matrix1, 1.0);

  auto start1 = std::chrono::steady_clock::now();
  s21::FastMatrix<float> result = matrix1 * 2.0;
  auto end1 = std::chrono::steady_clock::now();
  auto diff1 = end1 - start1;
  std::cout
      << "opeartor*(number): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;

  start1 = std::chrono::steady_clock::now();
  matrix1.MulNumber(2.0);
  end1 = std::chrono::steady_clock::now();
  diff1 = end1 - start1;
  std::cout
      << "MulNumber(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;
}

TEST(TestSpeed, TestMulMatrix1) {
  int rows = 1024;
  int cols = 1024;

  s21::FastMatrix<float> matrix1(rows, cols);
  s21::FastMatrix<float> matrix2(cols, rows);
  std::cout << "[" << rows << " x " << cols << "]"
            << " * "
            << "[" << rows << " x " << cols << "]" << std::endl;

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0);

  s21::FastMatrix<float> matrix3 = matrix1;

  auto start1 = std::chrono::steady_clock::now();
  matrix1.MulMatrix(matrix2);
  auto end1 = std::chrono::steady_clock::now();
  auto diff1 = end1 - start1;
  std::cout
      << "MulMatrix(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;

  start1 = std::chrono::steady_clock::now();
  s21::FastMatrix<float> result = matrix3 * matrix2;
  end1 = std::chrono::steady_clock::now();
  diff1 = end1 - start1;
  std::cout
      << "operator*(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;
}

TEST(TestSpeed, TestMulMatrix2) {
  int rows = 1024;
  int cols = 1024;

  s21::FastMatrix<float> matrix1(rows, cols);
  s21::FastMatrix<float> matrix2(cols, rows);
  std::cout << "[" << rows << " x " << cols << "]"
            << " * "
            << "[" << rows << " x " << cols << "]" << std::endl;

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0);

  auto start1 = std::chrono::steady_clock::now();
  s21::FastMatrix<float> result = matrix1 * matrix2;
  auto end1 = std::chrono::steady_clock::now();
  auto diff1 = end1 - start1;
  std::cout
      << "operator*(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;

  start1 = std::chrono::steady_clock::now();
  matrix1.MulMatrix(matrix2);
  end1 = std::chrono::steady_clock::now();
  diff1 = end1 - start1;
  std::cout
      << "MulMatrix(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;
}

TEST(TestSpeed, TestMulMatrix3) {
  int rows = 2048;
  int cols = 2048;

  s21::FastMatrix<float> matrix1(rows, cols);
  s21::FastMatrix<float> matrix2(cols, 1);

  std::cout << "[" << rows << " x " << cols << "]"
            << " * "
            << "[" << rows << " x " << 1 << "]" << std::endl;

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0);

  auto start1 = std::chrono::steady_clock::now();
  s21::FastMatrix<float> result = matrix1 * matrix2;
  auto end1 = std::chrono::steady_clock::now();
  auto diff1 = end1 - start1;
  std::cout
      << "operator*(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;

  start1 = std::chrono::steady_clock::now();
  matrix1.MulMatrix(matrix2);
  end1 = std::chrono::steady_clock::now();
  diff1 = end1 - start1;
  std::cout
      << "MulMatrix(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;
}

TEST(TestSpeed, TestMulMatrix4) {
  int rows = 8192;
  int cols = 8192;

  s21::FastMatrix<float> matrix1(rows, cols);
  s21::FastMatrix<float> matrix2(cols, 1);

  std::cout << "[" << rows << " x " << cols << "]"
            << " * "
            << "[" << rows << " x " << 1 << "]" << std::endl;

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0);

  auto start1 = std::chrono::steady_clock::now();
  s21::FastMatrix<float> result = matrix1 * matrix2;
  auto end1 = std::chrono::steady_clock::now();
  auto diff1 = end1 - start1;
  std::cout
      << "operator*(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;

  start1 = std::chrono::steady_clock::now();
  matrix1.MulMatrix(matrix2);
  end1 = std::chrono::steady_clock::now();
  diff1 = end1 - start1;
  std::cout
      << "MulMatrix(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;
}

TEST(TestSpeed, TestMulMatrix5) {
  int rows = 512;
  int cols = 784;

  s21::FastMatrix<float> matrix1(rows, cols);
  s21::FastMatrix<float> matrix2(cols, 1);

  std::cout << "[" << rows << " x " << cols << "]"
            << " * "
            << "[" << rows << " x " << 1 << "]" << std::endl;

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0);

  auto start1 = std::chrono::steady_clock::now();
  s21::FastMatrix<float> result = matrix1 * matrix2;
  auto end1 = std::chrono::steady_clock::now();
  auto diff1 = end1 - start1;
  std::cout
      << "operator*(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;

  start1 = std::chrono::steady_clock::now();
  matrix1.MulMatrix(matrix2);
  end1 = std::chrono::steady_clock::now();
  diff1 = end1 - start1;
  std::cout
      << "MulMatrix(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;
}

TEST(TestSpeed, TestGemmMatrix1) {
  int rows = 1024;
  int cols = 1024;

  s21::FastMatrix<float> matrix1(rows, cols);
  s21::FastMatrix<float> matrix2(cols, rows);
  std::cout << "[" << rows << " x " << cols << "]"
            << " * "
            << "[" << rows << " x " << cols << "]" << std::endl;

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0);

  s21::FastMatrix<float> result0{rows, cols};
  s21::FastMatrix<float> result1 = result0;
  s21::FastMatrix<float> result2 = result0;
  s21::FastMatrix<float> result3 = result0;
  s21::FastMatrix<float> result4 = result0;

  auto start1 = std::chrono::steady_clock::now();
  s21::FastMatrix<float>::GemmV0Ref(matrix1.data(), matrix2.data(),
                                    result0.data(), matrix1.get_rows(),
                                    matrix1.get_cols(), matrix2.get_cols());
  auto end1 = std::chrono::steady_clock::now();
  auto diff1 = end1 - start1;
  std::cout
      << "GemmV0Ref(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;

  start1 = std::chrono::steady_clock::now();
  s21::FastMatrix<float>::GemmV1Ref(matrix1.data(), matrix2.data(),
                                    result1.data(), matrix1.get_rows(),
                                    matrix1.get_cols(), matrix2.get_cols());
  end1 = std::chrono::steady_clock::now();
  diff1 = end1 - start1;
  std::cout
      << "GemmV1Ref(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;

  start1 = std::chrono::steady_clock::now();
  s21::FastMatrix<float>::GemmV2Ref(matrix1.data(), matrix2.data(),
                                    result4.data(), matrix1.get_rows(),
                                    matrix1.get_cols(), matrix2.get_cols());
  end1 = std::chrono::steady_clock::now();
  diff1 = end1 - start1;
  std::cout
      << "GemmV2Ref(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;

  start1 = std::chrono::steady_clock::now();
  s21::FastMatrix<float>::GemmV3Ref(matrix1.data(), matrix2.data(),
                                    result2.data(), matrix1.get_rows(),
                                    matrix1.get_cols(), matrix2.get_cols());
  end1 = std::chrono::steady_clock::now();
  diff1 = end1 - start1;
  std::cout
      << "GemmV3Ref(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;

  start1 = std::chrono::steady_clock::now();
  s21::FastMatrix<float>::GemmV4Ref(matrix1.data(), matrix2.data(),
                                    result3.data(), matrix1.get_rows(),
                                    matrix1.get_cols(), matrix2.get_cols());
  end1 = std::chrono::steady_clock::now();
  diff1 = end1 - start1;
  std::cout
      << "GemmV4Ref(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;
}

TEST(TestSpeed, TestGemmMatrix2) {
  int rows = 2048;
  int cols = 2048;

  s21::FastMatrix<float> matrix1(rows, cols);
  s21::FastMatrix<float> matrix2(cols, 1);
  std::cout << "[" << rows << " x " << cols << "]"
            << " * "
            << "[" << rows << " x " << 1 << "]" << std::endl;

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0);

  s21::FastMatrix<float> result0{rows, 1};
  s21::FastMatrix<float> result1 = result0;
  s21::FastMatrix<float> result2 = result0;
  s21::FastMatrix<float> result3 = result0;
  s21::FastMatrix<float> result4 = result0;

  auto start1 = std::chrono::steady_clock::now();
  s21::FastMatrix<float>::GemmV0Ref(matrix1.data(), matrix2.data(),
                                    result0.data(), matrix1.get_rows(),
                                    matrix1.get_cols(), matrix2.get_cols());
  auto end1 = std::chrono::steady_clock::now();
  auto diff1 = end1 - start1;
  std::cout
      << "GemmV0Ref(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;

  start1 = std::chrono::steady_clock::now();
  s21::FastMatrix<float>::GemmV1Ref(matrix1.data(), matrix2.data(),
                                    result1.data(), matrix1.get_rows(),
                                    matrix1.get_cols(), matrix2.get_cols());
  end1 = std::chrono::steady_clock::now();
  diff1 = end1 - start1;
  std::cout
      << "GemmV1Ref(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;

  start1 = std::chrono::steady_clock::now();
  s21::FastMatrix<float>::GemmV2Ref(matrix1.data(), matrix2.data(),
                                    result4.data(), matrix1.get_rows(),
                                    matrix1.get_cols(), matrix2.get_cols());
  end1 = std::chrono::steady_clock::now();
  diff1 = end1 - start1;
  std::cout
      << "GemmV2Ref(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;

  start1 = std::chrono::steady_clock::now();
  s21::FastMatrix<float>::GemmV3Ref(matrix1.data(), matrix2.data(),
                                    result2.data(), matrix1.get_rows(),
                                    matrix1.get_cols(), matrix2.get_cols());
  end1 = std::chrono::steady_clock::now();
  diff1 = end1 - start1;
  std::cout
      << "GemmV3Ref(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;

  start1 = std::chrono::steady_clock::now();
  s21::FastMatrix<float>::GemmV4Ref(matrix1.data(), matrix2.data(),
                                    result3.data(), matrix1.get_rows(),
                                    matrix1.get_cols(), matrix2.get_cols());
  end1 = std::chrono::steady_clock::now();
  diff1 = end1 - start1;
  std::cout
      << "GemmV4Ref(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;
}

TEST(TestSpeed, TestGemmMatrix3) {
  int rows = 9500;
  int cols = 9500;

  s21::FastMatrix<float> matrix1(rows, cols);
  s21::FastMatrix<float> matrix2(cols, 1);
  std::cout << "[" << rows << " x " << cols << "]"
            << " * "
            << "[" << rows << " x " << 1 << "]" << std::endl;

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0);

  s21::FastMatrix<float> result0{rows, 1};
  s21::FastMatrix<float> result1 = result0;
  s21::FastMatrix<float> result2 = result0;
  s21::FastMatrix<float> result3 = result0;
  s21::FastMatrix<float> result4 = result0;

  auto start1 = std::chrono::steady_clock::now();
  s21::FastMatrix<float>::GemmV0Ref(matrix1.data(), matrix2.data(),
                                    result0.data(), matrix1.get_rows(),
                                    matrix1.get_cols(), matrix2.get_cols());
  auto end1 = std::chrono::steady_clock::now();
  auto diff1 = end1 - start1;
  std::cout
      << "GemmV0Ref(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;

  start1 = std::chrono::steady_clock::now();
  s21::FastMatrix<float>::GemmV1Ref(matrix1.data(), matrix2.data(),
                                    result1.data(), matrix1.get_rows(),
                                    matrix1.get_cols(), matrix2.get_cols());
  end1 = std::chrono::steady_clock::now();
  diff1 = end1 - start1;
  std::cout
      << "GemmV1Ref(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;

  start1 = std::chrono::steady_clock::now();
  s21::FastMatrix<float>::GemmV2Ref(matrix1.data(), matrix2.data(),
                                    result4.data(), matrix1.get_rows(),
                                    matrix1.get_cols(), matrix2.get_cols());
  end1 = std::chrono::steady_clock::now();
  diff1 = end1 - start1;
  std::cout
      << "GemmV2Ref(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;

  start1 = std::chrono::steady_clock::now();
  s21::FastMatrix<float>::GemmV3Ref(matrix1.data(), matrix2.data(),
                                    result2.data(), matrix1.get_rows(),
                                    matrix1.get_cols(), matrix2.get_cols());
  end1 = std::chrono::steady_clock::now();
  diff1 = end1 - start1;
  std::cout
      << "GemmV3Ref(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;

  start1 = std::chrono::steady_clock::now();
  s21::FastMatrix<float>::GemmV4Ref(matrix1.data(), matrix2.data(),
                                    result3.data(), matrix1.get_rows(),
                                    matrix1.get_cols(), matrix2.get_cols());
  end1 = std::chrono::steady_clock::now();
  diff1 = end1 - start1;
  std::cout
      << "GemmV4Ref(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;
}

TEST(TestSpeed, TestGemmMatrix4) {
  int rows = 512;
  int cols = 784;

  s21::FastMatrix<float> matrix1(rows, cols);
  s21::FastMatrix<float> matrix2(cols, 1);
  std::cout << "[" << rows << " x " << cols << "]"
            << " * "
            << "[" << rows << " x " << 1 << "]" << std::endl;

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0);

  s21::FastMatrix<float> result0{cols, 1};
  s21::FastMatrix<float> result1 = result0;
  s21::FastMatrix<float> result2 = result0;
  s21::FastMatrix<float> result3 = result0;
  s21::FastMatrix<float> result4 = result0;

  auto start1 = std::chrono::steady_clock::now();
  s21::FastMatrix<float>::GemmV0Ref(matrix1.data(), matrix2.data(),
                                    result0.data(), matrix1.get_rows(),
                                    matrix1.get_cols(), matrix2.get_cols());
  auto end1 = std::chrono::steady_clock::now();
  auto diff1 = end1 - start1;
  std::cout
      << "GemmV0Ref(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;

  start1 = std::chrono::steady_clock::now();
  s21::FastMatrix<float>::GemmV1Ref(matrix1.data(), matrix2.data(),
                                    result1.data(), matrix1.get_rows(),
                                    matrix1.get_cols(), matrix2.get_cols());
  end1 = std::chrono::steady_clock::now();
  diff1 = end1 - start1;
  std::cout
      << "GemmV1Ref(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;

  start1 = std::chrono::steady_clock::now();
  s21::FastMatrix<float>::GemmV2Ref(matrix1.data(), matrix2.data(),
                                    result4.data(), matrix1.get_rows(),
                                    matrix1.get_cols(), matrix2.get_cols());
  end1 = std::chrono::steady_clock::now();
  diff1 = end1 - start1;
  std::cout
      << "GemmV2Ref(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;

  start1 = std::chrono::steady_clock::now();
  s21::FastMatrix<float>::GemmV3Ref(matrix1.data(), matrix2.data(),
                                    result2.data(), matrix1.get_rows(),
                                    matrix1.get_cols(), matrix2.get_cols());
  end1 = std::chrono::steady_clock::now();
  diff1 = end1 - start1;
  std::cout
      << "GemmV3Ref(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;

  start1 = std::chrono::steady_clock::now();
  s21::FastMatrix<float>::GemmV4Ref(matrix1.data(), matrix2.data(),
                                    result3.data(), matrix1.get_rows(),
                                    matrix1.get_cols(), matrix2.get_cols());
  end1 = std::chrono::steady_clock::now();
  diff1 = end1 - start1;
  std::cout
      << "GemmV4Ref(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;
}
