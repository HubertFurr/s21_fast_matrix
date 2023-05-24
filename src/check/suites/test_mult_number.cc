#include "./../classes/random_suites.h"
#include "./../test.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты успешного умножения на число функцией
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestMulNumber, TestMulNumber1) {
  s21::FastMatrix<float> matrix1{95, 99};
  EXPECT_EQ(matrix1.get_rows(), 95);
  EXPECT_EQ(matrix1.get_cols(), 99);

  double number = 2.0;

  s21_matrix_test_helper::FillMatrix(matrix1, 2.5);

  matrix1.MulNumber(number);

  s21_matrix_test_helper::CheckMatrix(matrix1, 2.5 * number);

  matrix1.MulNumber(number);

  s21_matrix_test_helper::CheckMatrix(matrix1, 2.5 * number * number);
}

TEST(TestMulNumber, TestMulNumber2) {
  s21::FastMatrix<float> matrix1{99, 99};
  EXPECT_EQ(matrix1.get_rows(), 99);
  EXPECT_EQ(matrix1.get_cols(), 99);

  double number = -2.5;

  s21_matrix_test_helper::FillMatrix(matrix1, 2.5);

  matrix1.MulNumber(number);

  s21_matrix_test_helper::CheckMatrix(matrix1, 2.5 * number);

  matrix1.MulNumber(number);

  s21_matrix_test_helper::CheckMatrix(matrix1, 2.5 * number * number);
}

TEST(TestMulNumber, TestMulNumber3) {
  s21::FastMatrix<float> matrix1{199, 1};
  EXPECT_EQ(matrix1.get_rows(), 199);
  EXPECT_EQ(matrix1.get_cols(), 1);

  double number = -2.999;

  s21_matrix_test_helper::FillMatrix(matrix1, -1.999);

  matrix1.MulNumber(number);

  s21_matrix_test_helper::CheckMatrix(matrix1, -1.999 * number);

  matrix1.MulNumber(number);

  s21_matrix_test_helper::CheckMatrix(matrix1, -1.999 * number * number);
}

TEST(TestMulNumber, TestMulNumber4) {
  s21::FastMatrix<float> matrix1{1, 199};
  EXPECT_EQ(matrix1.get_rows(), 1);
  EXPECT_EQ(matrix1.get_cols(), 199);

  double number = 2.5999;

  s21_matrix_test_helper::FillMatrix(matrix1, 1.5999);

  matrix1.MulNumber(number);

  s21_matrix_test_helper::CheckMatrix(matrix1, 1.5999 * number);

  matrix1.MulNumber(number);

  s21_matrix_test_helper::CheckMatrix(matrix1, 1.5999 * number * number);
}

TEST(TestMulNumber, TestMulNumber5) {
  s21::FastMatrix<float> matrix1{4, 3};
  EXPECT_EQ(matrix1.get_rows(), 4);
  EXPECT_EQ(matrix1.get_cols(), 3);

  s21::FastMatrix<float> check_matrix = matrix1;
  EXPECT_EQ(check_matrix.get_rows(), 4);
  EXPECT_EQ(check_matrix.get_cols(), 3);

  double number = 1.99;

  matrix1(0, 0) = 1.5;
  matrix1(0, 1) = 2.5;
  matrix1(0, 2) = 3.5;
  matrix1(1, 0) = -1.5;
  matrix1(1, 1) = -2.5;
  matrix1(1, 2) = -3.5;
  matrix1(2, 0) = 0.0;
  matrix1(2, 1) = 0.0;
  matrix1(2, 2) = 0.0;
  matrix1(3, 0) = 1.0;
  matrix1(3, 1) = 1.0;
  matrix1(3, 2) = 1.0;

  check_matrix(0, 0) = 2.985;
  check_matrix(0, 1) = 4.975;
  check_matrix(0, 2) = 6.965;
  check_matrix(1, 0) = -2.985;
  check_matrix(1, 1) = -4.975;
  check_matrix(1, 2) = -6.965;
  check_matrix(2, 0) = 0.0;
  check_matrix(2, 1) = 0.0;
  check_matrix(2, 2) = 0.0;
  check_matrix(3, 0) = 1.99;
  check_matrix(3, 1) = 1.99;
  check_matrix(3, 2) = 1.99;

  matrix1.MulNumber(number);

  EXPECT_TRUE(matrix1 == check_matrix);
}

TEST(TestMulNumber, TestMulNumber6) {
  s21::FastMatrix<float> matrix1{2, 2};
  EXPECT_EQ(matrix1.get_rows(), 2);
  EXPECT_EQ(matrix1.get_cols(), 2);

  s21::FastMatrix<float> check_matrix = matrix1;
  EXPECT_EQ(check_matrix.get_rows(), 2);
  EXPECT_EQ(check_matrix.get_cols(), 2);

  double number = -9.87;

  matrix1(0, 0) = 14.58;
  matrix1(0, 1) = -45;
  matrix1(1, 0) = -2.0;
  matrix1(1, 1) = 67.545;

  check_matrix(0, 0) = 14.58 * number;
  check_matrix(0, 1) = -45 * number;
  check_matrix(1, 0) = -2.0 * number;
  check_matrix(1, 1) = 67.545 * number;

  matrix1.MulNumber(number);

  EXPECT_TRUE(matrix1 == check_matrix);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты успешного умножения на число операторами
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestMulNumber, TestMulNumberOperator1) {
  s21::FastMatrix<float> matrix1{95, 99};
  EXPECT_EQ(matrix1.get_rows(), 95);
  EXPECT_EQ(matrix1.get_cols(), 99);

  double number = 2.0;

  s21_matrix_test_helper::FillMatrix(matrix1, 2.5);
  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> result1 = matrix1 * number;
  s21::FastMatrix<float> result2 = number * matrix1;
  s21::FastMatrix<float> result3 = matrix1;
  result3 *= number;

  s21_matrix_test_helper::CheckMatrix(result1, 2.5 * number);
  s21_matrix_test_helper::CheckMatrix(result2, 2.5 * number);
  s21_matrix_test_helper::CheckMatrix(result3, 2.5 * number);
  EXPECT_TRUE(matrix1_before == matrix1);
}

TEST(TestMulNumber, TestMulNumberOperator2) {
  s21::FastMatrix<float> matrix1{99, 99};
  EXPECT_EQ(matrix1.get_rows(), 99);
  EXPECT_EQ(matrix1.get_cols(), 99);

  double number = -2.5;

  s21_matrix_test_helper::FillMatrix(matrix1, 2.5);
  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> result1 = matrix1 * number;
  s21::FastMatrix<float> result2 = number * matrix1;
  s21::FastMatrix<float> result3 = matrix1;
  result3 *= number;

  s21_matrix_test_helper::CheckMatrix(result1, 2.5 * number);
  s21_matrix_test_helper::CheckMatrix(result2, 2.5 * number);
  s21_matrix_test_helper::CheckMatrix(result3, 2.5 * number);
  EXPECT_TRUE(matrix1_before == matrix1);
}

TEST(TestMulNumber, TestMulNumberOperator3) {
  s21::FastMatrix<float> matrix1{199, 1};
  EXPECT_EQ(matrix1.get_rows(), 199);
  EXPECT_EQ(matrix1.get_cols(), 1);

  double number = -2.999;

  s21_matrix_test_helper::FillMatrix(matrix1, -1.999);
  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> result1 = matrix1 * number;
  s21::FastMatrix<float> result2 = number * matrix1;
  s21::FastMatrix<float> result3 = matrix1;
  result3 *= number;

  s21_matrix_test_helper::CheckMatrix(result1, -1.999 * number);
  s21_matrix_test_helper::CheckMatrix(result2, -1.999 * number);
  s21_matrix_test_helper::CheckMatrix(result3, -1.999 * number);
  EXPECT_TRUE(matrix1_before == matrix1);
}

TEST(TestMulNumber, TestMulNumberOperator4) {
  s21::FastMatrix<float> matrix1{1, 199};
  EXPECT_EQ(matrix1.get_rows(), 1);
  EXPECT_EQ(matrix1.get_cols(), 199);

  double number = 2.5999;

  s21_matrix_test_helper::FillMatrix(matrix1, 1.5999);
  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> result1 = matrix1 * number;
  s21::FastMatrix<float> result2 = number * matrix1;
  s21::FastMatrix<float> result3 = matrix1;
  result3 *= number;

  s21_matrix_test_helper::CheckMatrix(result1, 1.5999 * number);
  s21_matrix_test_helper::CheckMatrix(result2, 1.5999 * number);
  s21_matrix_test_helper::CheckMatrix(result3, 1.5999 * number);
  EXPECT_TRUE(matrix1_before == matrix1);
}

TEST(TestMulNumber, TestMulNumberOperator5) {
  s21::FastMatrix<float> matrix1{4, 3};
  EXPECT_EQ(matrix1.get_rows(), 4);
  EXPECT_EQ(matrix1.get_cols(), 3);

  s21::FastMatrix<float> check_matrix = matrix1;
  EXPECT_EQ(check_matrix.get_rows(), 4);
  EXPECT_EQ(check_matrix.get_cols(), 3);

  double number = 1.99;

  matrix1(0, 0) = 1.5;
  matrix1(0, 1) = 2.5;
  matrix1(0, 2) = 3.5;
  matrix1(1, 0) = -1.5;
  matrix1(1, 1) = -2.5;
  matrix1(1, 2) = -3.5;
  matrix1(2, 0) = 0.0;
  matrix1(2, 1) = 0.0;
  matrix1(2, 2) = 0.0;
  matrix1(3, 0) = 1.0;
  matrix1(3, 1) = 1.0;
  matrix1(3, 2) = 1.0;

  check_matrix(0, 0) = 2.985;
  check_matrix(0, 1) = 4.975;
  check_matrix(0, 2) = 6.965;
  check_matrix(1, 0) = -2.985;
  check_matrix(1, 1) = -4.975;
  check_matrix(1, 2) = -6.965;
  check_matrix(2, 0) = 0.0;
  check_matrix(2, 1) = 0.0;
  check_matrix(2, 2) = 0.0;
  check_matrix(3, 0) = 1.99;
  check_matrix(3, 1) = 1.99;
  check_matrix(3, 2) = 1.99;

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> result1 = matrix1 * number;
  s21::FastMatrix<float> result2 = number * matrix1;
  s21::FastMatrix<float> result3 = matrix1;
  result3 *= number;

  EXPECT_TRUE(result1 == check_matrix);
  EXPECT_TRUE(result2 == check_matrix);
  EXPECT_TRUE(result3 == check_matrix);
  EXPECT_TRUE(matrix1 == matrix1_before);
}

TEST(TestMulNumber, TestMulNumberOperator6) {
  s21::FastMatrix<float> matrix1{2, 2};
  EXPECT_EQ(matrix1.get_rows(), 2);
  EXPECT_EQ(matrix1.get_cols(), 2);

  s21::FastMatrix<float> check_matrix = matrix1;
  EXPECT_EQ(check_matrix.get_rows(), 2);
  EXPECT_EQ(check_matrix.get_cols(), 2);

  double number = -9.87;

  matrix1(0, 0) = 14.58;
  matrix1(0, 1) = -45;
  matrix1(1, 0) = -2.0;
  matrix1(1, 1) = 67.545;

  check_matrix(0, 0) = 14.58 * number;
  check_matrix(0, 1) = -45 * number;
  check_matrix(1, 0) = -2.0 * number;
  check_matrix(1, 1) = 67.545 * number;

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> result1 = matrix1 * number;
  s21::FastMatrix<float> result2 = number * matrix1;
  s21::FastMatrix<float> result3 = matrix1;
  result3 *= number;

  EXPECT_TRUE(result1 == check_matrix);
  EXPECT_TRUE(result2 == check_matrix);
  EXPECT_TRUE(result3 == check_matrix);
  EXPECT_TRUE(matrix1 == matrix1_before);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Рандомные тесты
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

using RMNRO = RandomMulNumberMatrixRangeOne<float>;

TEST_P(RMNRO, TestMulNumberRandom1) {
  s21::FastMatrix<float> matrix_before = test_matrix_;
  float number = s21_matrix_test_helper::GetRandDouble(-1e4, 1e4);
  s21::FastMatrix<float> check_matrix = test_matrix_;

  for (int i = 0; i < check_matrix.get_rows(); i++) {
    for (int j = 0; j < check_matrix.get_cols(); j++) {
      check_matrix(i, j) = test_matrix_(i, j) * number;
    }
  }

  s21::FastMatrix<float> matrix1 = test_matrix_;
  s21::FastMatrix<float> matrix2 = test_matrix_;
  s21::FastMatrix<float> result1 = test_matrix_ * number;
  s21::FastMatrix<float> result2 = number * test_matrix_;
  matrix1.MulNumber(number);
  s21::FastMatrix<float> result3 = matrix2;
  result3 *= number;

  EXPECT_TRUE(result1 == check_matrix);
  EXPECT_TRUE(result2 == check_matrix);
  EXPECT_TRUE(result3 == check_matrix);
  EXPECT_TRUE(matrix_before == test_matrix_);

#if (__DEBUG == 1)
  if (::testing::Test::HasFailure()) {
    s21_matrix_test_helper::Print(test_matrix_);
    s21_matrix_test_helper::PrintTest(test_matrix_);
    s21_matrix_test_helper::PrintWolfram(test_matrix_);
  }
#endif
}

INSTANTIATE_TEST_SUITE_P(
    MulNumberSuite1, RMNRO,
    ::testing::Range(0, s21_matrix_test_helper::kRandomTestNum));
