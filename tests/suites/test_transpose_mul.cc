#include "../classes/test_helper.h"
#include "../test.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты умножения с транспонированием первого множителя
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestMulTranspose, TestM1MulTranspose1) {
  s21::FastMatrix<float> matrix1{99, 95};
  s21::FastMatrix<float> matrix2{99, 94};
  s21_matrix_test_helper::FillMatrix(matrix1, 1.99f);
  s21_matrix_test_helper::FillMatrix(matrix2, 1.99f);

  s21::FastMatrix<float> result_check = matrix1.Transpose() * matrix2;
  s21::FastMatrix<float> result{matrix1.get_cols(), matrix2.get_cols()};

  s21::FastMatrix<float>::GemmM1TransposeV0Ref(
      matrix1.data(), matrix2.data(), result.data(), matrix1.get_rows(),
      matrix1.get_cols(), matrix2.get_cols());

  EXPECT_EQ(result_check.get_rows(), result.get_rows());
  EXPECT_EQ(result_check.get_cols(), result.get_cols());
  EXPECT_TRUE(result_check == result);
}

TEST(TestMulTranspose, TestM1MulTranspose2) {
  s21::FastMatrix<float> matrix1{3, 2};
  s21::FastMatrix<float> matrix2{3, 2};
  s21_matrix_test_helper::FillMatrix(matrix1, 1.99f);
  s21_matrix_test_helper::FillMatrix(matrix2, 1.99f);

  s21::FastMatrix<float> result_check = matrix1.Transpose() * matrix2;
  s21::FastMatrix<float> result{matrix1.get_cols(), matrix2.get_cols()};

  s21::FastMatrix<float>::GemmM1TransposeV0Ref(
      matrix1.data(), matrix2.data(), result.data(), matrix1.get_rows(),
      matrix1.get_cols(), matrix2.get_cols());

  EXPECT_EQ(result_check.get_rows(), result.get_rows());
  EXPECT_EQ(result_check.get_cols(), result.get_cols());
  std::cout << result_check;
  std::cout << result;
  EXPECT_TRUE(result_check == result);
}

TEST(TestMulTranspose, TestM1MulTranspose3) {
  s21::FastMatrix<float> matrix1{2, 4};
  s21::FastMatrix<float> matrix2{2, 3};

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(0, 2) = 3;
  matrix1(0, 3) = 4;
  matrix1(1, 0) = 5;
  matrix1(1, 1) = 6;
  matrix1(1, 2) = 7;
  matrix1(1, 3) = 8;

  matrix2(0, 0) = 1;
  matrix2(0, 1) = 2;
  matrix2(0, 2) = 3;
  matrix2(1, 0) = 4;
  matrix2(1, 1) = 5;
  matrix2(1, 2) = 6;

  s21::FastMatrix<float> result_check = matrix1.Transpose() * matrix2;
  s21::FastMatrix<float> result{matrix1.get_cols(), matrix2.get_cols()};

  s21::FastMatrix<float>::GemmM1TransposeV0Ref(
      matrix1.data(), matrix2.data(), result.data(), matrix1.get_rows(),
      matrix1.get_cols(), matrix2.get_cols());

  EXPECT_EQ(result_check.get_rows(), result.get_rows());
  EXPECT_EQ(result_check.get_cols(), result.get_cols());
  std::cout << result_check;
  std::cout << result;
  EXPECT_TRUE(result_check == result);
}

TEST(TestMulTranspose, TestM1MulTranspose4) {
  s21::FastMatrix<float> matrix1{2, 3};
  s21::FastMatrix<float> matrix2{2, 4};

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(0, 2) = 3;
  matrix1(1, 0) = 4;
  matrix1(1, 1) = 5;
  matrix1(1, 2) = 6;

  matrix2(0, 0) = 1;
  matrix2(0, 1) = 2;
  matrix2(0, 2) = 3;
  matrix2(0, 3) = 4;
  matrix2(1, 0) = 5;
  matrix2(1, 1) = 6;
  matrix2(1, 2) = 7;
  matrix2(1, 3) = 8;

  s21::FastMatrix<float> result_check = matrix1.Transpose() * matrix2;
  s21::FastMatrix<float> result{matrix1.get_cols(), matrix2.get_cols()};

  s21::FastMatrix<float>::GemmM1TransposeV0Ref(
      matrix1.data(), matrix2.data(), result.data(), matrix1.get_rows(),
      matrix1.get_cols(), matrix2.get_cols());

  EXPECT_EQ(result_check.get_rows(), result.get_rows());
  EXPECT_EQ(result_check.get_cols(), result.get_cols());
  std::cout << result_check;
  std::cout << result;
  EXPECT_TRUE(result_check == result);
}

TEST(TestMulTranspose, TestM1MulTranspose5) {
  s21::FastMatrix<float> matrix1{3, 3};
  s21::FastMatrix<float> matrix2{3, 3};

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(0, 2) = 3;
  matrix1(1, 0) = 4;
  matrix1(1, 1) = 5;
  matrix1(1, 2) = 6;
  matrix1(2, 0) = 7;
  matrix1(2, 1) = 8;
  matrix1(2, 2) = 9;

  matrix2(0, 0) = 1;
  matrix2(0, 1) = 2;
  matrix2(0, 2) = 3;
  matrix2(1, 0) = 4;
  matrix2(1, 1) = 5;
  matrix2(1, 2) = 6;
  matrix2(2, 0) = 7;
  matrix2(2, 1) = 8;
  matrix2(2, 2) = 9;

  s21::FastMatrix<float> result_check = matrix1.Transpose() * matrix2;
  s21::FastMatrix<float> result{matrix1.get_cols(), matrix2.get_cols()};

  s21_matrix_test_helper::FillMatrix(result, 1.0f);

  s21::FastMatrix<float>::GemmM1TransposeV0Ref(
      matrix1.data(), matrix2.data(), result.data(), matrix1.get_rows(),
      matrix1.get_cols(), matrix2.get_cols());

  EXPECT_EQ(result_check.get_rows(), result.get_rows());
  EXPECT_EQ(result_check.get_cols(), result.get_cols());
  std::cout << result_check;
  std::cout << result;
  EXPECT_TRUE(result_check == result);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты умножения с транспонированием второго множителя
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestMulTranspose, TestMulM2Transpose1) {
  s21::FastMatrix<float> matrix1{95, 99};
  s21::FastMatrix<float> matrix2{94, 99};
  s21_matrix_test_helper::FillMatrix(matrix1, 1.99f);
  s21_matrix_test_helper::FillMatrix(matrix2, 1.99f);

  s21::FastMatrix<float> result_check = matrix1 * matrix2.Transpose();
  s21::FastMatrix<float> result{matrix1.get_rows(), matrix2.get_rows()};

  s21::FastMatrix<float>::GemmM2TransposeV0Ref(
      matrix1.data(), matrix2.data(), result.data(), matrix1.get_rows(),
      matrix1.get_cols(), matrix2.get_rows());

  EXPECT_EQ(result_check.get_rows(), result.get_rows());
  EXPECT_EQ(result_check.get_cols(), result.get_cols());
  EXPECT_TRUE(result_check == result);
}

TEST(TestMulTranspose, TestMulM2Transpose2) {
  s21::FastMatrix<float> matrix1{2, 3};
  s21::FastMatrix<float> matrix2{4, 3};
  s21_matrix_test_helper::FillMatrix(matrix1, 1.99f);
  s21_matrix_test_helper::FillMatrix(matrix2, 1.99f);

  s21::FastMatrix<float> result_check = matrix1 * matrix2.Transpose();
  s21::FastMatrix<float> result{matrix1.get_rows(), matrix2.get_rows()};

  s21::FastMatrix<float>::GemmM2TransposeV0Ref(
      matrix1.data(), matrix2.data(), result.data(), matrix1.get_rows(),
      matrix1.get_cols(), matrix2.get_rows());

  EXPECT_EQ(result_check.get_rows(), result.get_rows());
  EXPECT_EQ(result_check.get_cols(), result.get_cols());
  std::cout << result_check;
  std::cout << result;
  EXPECT_TRUE(result_check == result);
}

TEST(TestMulTranspose, TestMulM2Transpose3) {
  s21::FastMatrix<float> matrix1{2, 3};
  s21::FastMatrix<float> matrix2{4, 3};
  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(0, 2) = 3;
  matrix1(1, 0) = 4;
  matrix1(1, 1) = 5;
  matrix1(1, 2) = 6;

  matrix2(0, 0) = 1;
  matrix2(0, 1) = 2;
  matrix2(0, 2) = 3;
  matrix2(1, 0) = 4;
  matrix2(1, 1) = 5;
  matrix2(1, 2) = 6;
  matrix2(2, 0) = 7;
  matrix2(2, 1) = 8;
  matrix2(2, 2) = 9;
  matrix2(3, 0) = 10;
  matrix2(3, 1) = 11;
  matrix2(3, 2) = 12;

  s21::FastMatrix<float> result_check = matrix1 * matrix2.Transpose();
  s21::FastMatrix<float> result{matrix1.get_rows(), matrix2.get_rows()};

  s21::FastMatrix<float>::GemmM2TransposeV0Ref(
      matrix1.data(), matrix2.data(), result.data(), matrix1.get_rows(),
      matrix1.get_cols(), matrix2.get_rows());

  EXPECT_EQ(result_check.get_rows(), result.get_rows());
  EXPECT_EQ(result_check.get_cols(), result.get_cols());
  std::cout << result_check;
  std::cout << result;
  EXPECT_TRUE(result_check == result);
}

TEST(TestMulTranspose, TestMulM2Transpose4) {
  s21::FastMatrix<float> matrix1{4, 3};
  s21::FastMatrix<float> matrix2{2, 3};

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(0, 2) = 3;
  matrix1(1, 0) = 4;
  matrix1(1, 1) = 5;
  matrix1(1, 2) = 6;
  matrix1(2, 0) = 7;
  matrix1(2, 1) = 8;
  matrix1(2, 2) = 9;
  matrix1(3, 0) = 10;
  matrix1(3, 1) = 11;
  matrix1(3, 2) = 12;

  matrix2(0, 0) = 1;
  matrix2(0, 1) = 2;
  matrix2(0, 2) = 3;
  matrix2(1, 0) = 4;
  matrix2(1, 1) = 5;
  matrix2(1, 2) = 6;

  s21::FastMatrix<float> result_check = matrix1 * matrix2.Transpose();
  s21::FastMatrix<float> result{matrix1.get_rows(), matrix2.get_rows()};

  s21::FastMatrix<float>::GemmM2TransposeV0Ref(
      matrix1.data(), matrix2.data(), result.data(), matrix1.get_rows(),
      matrix1.get_cols(), matrix2.get_rows());

  EXPECT_EQ(result_check.get_rows(), result.get_rows());
  EXPECT_EQ(result_check.get_cols(), result.get_cols());
  std::cout << result_check;
  std::cout << result;
  EXPECT_TRUE(result_check == result);
}

TEST(TestMulTranspose, TestM1MulM2Transpose5) {
  s21::FastMatrix<float> matrix1{3, 3};
  s21::FastMatrix<float> matrix2{3, 3};

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(0, 2) = 3;
  matrix1(1, 0) = 4;
  matrix1(1, 1) = 5;
  matrix1(1, 2) = 6;
  matrix1(2, 0) = 7;
  matrix1(2, 1) = 8;
  matrix1(2, 2) = 9;

  matrix2(0, 0) = 1;
  matrix2(0, 1) = 2;
  matrix2(0, 2) = 3;
  matrix2(1, 0) = 4;
  matrix2(1, 1) = 5;
  matrix2(1, 2) = 6;
  matrix2(2, 0) = 7;
  matrix2(2, 1) = 8;
  matrix2(2, 2) = 9;

  s21::FastMatrix<float> result_check = matrix1 * matrix2.Transpose();
  s21::FastMatrix<float> result{matrix1.get_rows(), matrix2.get_rows()};

  s21_matrix_test_helper::FillMatrix(result, 1.0f);

  s21::FastMatrix<float>::GemmM2TransposeV0Ref(
      matrix1.data(), matrix2.data(), result.data(), matrix1.get_rows(),
      matrix1.get_cols(), matrix2.get_rows());

  EXPECT_EQ(result_check.get_rows(), result.get_rows());
  EXPECT_EQ(result_check.get_cols(), result.get_cols());
  std::cout << result_check;
  std::cout << result;
  EXPECT_TRUE(result_check == result);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты на скорость
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestSpeed, TestM1MulTranspose1) {
  int rows = 1024;
  int cols = 1025;

  s21::FastMatrix<float> matrix1(rows, cols);
  s21::FastMatrix<float> matrix2(rows, cols);
  std::cout << "[" << rows << " x " << cols << "].Transpose()"
            << " * "
            << "[" << rows << " x " << cols << "]" << std::endl;

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0f);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0f);

  s21::FastMatrix<float> result0{cols, cols};
  s21::FastMatrix<float> result1 = result0;
  s21::FastMatrix<float> result2 = result0;
  s21::FastMatrix<float> result3 = result0;
  s21::FastMatrix<float> result4 = result0;

  s21::FastMatrix<float> result = result0;
  auto start1 = std::chrono::steady_clock::now();
  auto transposed1 = matrix1.Transpose();
  s21::FastMatrix<float>::GemmV3Ref(transposed1.data(), matrix2.data(),
                                    result.data(), transposed1.get_rows(),
                                    transposed1.get_cols(), matrix2.get_cols());
  auto end1 = std::chrono::steady_clock::now();
  auto diff1 = end1 - start1;
  std::cout
      << "matrix1.Transpose + GemmV3Ref: "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;

  start1 = std::chrono::steady_clock::now();
  s21::FastMatrix<float>::GemmM1TransposeV0Ref(
      matrix1.data(), matrix2.data(), result0.data(), matrix1.get_rows(),
      matrix1.get_cols(), matrix2.get_cols());
  end1 = std::chrono::steady_clock::now();
  diff1 = end1 - start1;
  std::cout
      << "GemmM1TransposeV0Ref(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;

  start1 = std::chrono::steady_clock::now();
  s21::FastMatrix<float>::GemmM1TransposeV1Ref(
      matrix1.data(), matrix2.data(), result1.data(), matrix1.get_rows(),
      matrix1.get_cols(), matrix2.get_cols());
  end1 = std::chrono::steady_clock::now();
  diff1 = end1 - start1;
  std::cout
      << "GemmM1TransposeV1Ref(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;
}

TEST(TestSpeed, TestM1MulTranspose2) {
  int rows_a = 1280;
  int cols_a = 1280;
  int rows_b = 1280;
  int cols_b = 1;

  s21::FastMatrix<float> matrix1(rows_a, cols_a);
  s21::FastMatrix<float> matrix2(rows_b, cols_b);
  std::cout << "[" << rows_a << " x " << cols_a << "].Transpose()"
            << " * "
            << "[" << rows_b << " x " << cols_b << "]" << std::endl;

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0f);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0f);

  s21::FastMatrix<float> result0{cols_a, cols_b};
  s21::FastMatrix<float> result1 = result0;
  s21::FastMatrix<float> result2 = result0;
  s21::FastMatrix<float> result3 = result0;
  s21::FastMatrix<float> result4 = result0;

  s21::FastMatrix<float> result = result0;
  auto start1 = std::chrono::steady_clock::now();
  auto transposed1 = matrix1.Transpose();
  s21::FastMatrix<float>::GemmV3Ref(transposed1.data(), matrix2.data(),
                                    result.data(), transposed1.get_rows(),
                                    transposed1.get_cols(), matrix2.get_cols());
  auto end1 = std::chrono::steady_clock::now();
  auto diff1 = end1 - start1;
  std::cout
      << "matrix1.Transpose + GemmV3Ref: "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;

  start1 = std::chrono::steady_clock::now();
  s21::FastMatrix<float>::GemmM1TransposeV0Ref(
      matrix1.data(), matrix2.data(), result0.data(), matrix1.get_rows(),
      matrix1.get_cols(), matrix2.get_cols());
  end1 = std::chrono::steady_clock::now();
  diff1 = end1 - start1;
  std::cout
      << "GemmM1TransposeV0Ref(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;

  start1 = std::chrono::steady_clock::now();
  s21::FastMatrix<float>::GemmM1TransposeV1Ref(
      matrix1.data(), matrix2.data(), result1.data(), matrix1.get_rows(),
      matrix1.get_cols(), matrix2.get_cols());
  end1 = std::chrono::steady_clock::now();
  diff1 = end1 - start1;
  std::cout
      << "GemmM1TransposeV1Ref(): "
      << std::chrono::duration_cast<std::chrono::microseconds>(diff1).count()
      << " us ("
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff1).count()
      << " ms)" << std::endl;
}
