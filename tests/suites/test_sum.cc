#include "./../test.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты исключений функции суммирования
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestSum, TestSumFunctionException1) {
  s21::FastMatrix<float> matrix1{2, 2};
  s21::FastMatrix<float> matrix2{2, 3};

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1.SumMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2.SumMatrix(matrix1));
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSum, TestSumFunctionException2) {
  s21::FastMatrix<float> matrix1{2, 2};
  s21::FastMatrix<float> matrix2{3, 2};

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1.SumMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2.SumMatrix(matrix1));
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSum, TestSumFunctionException3) {
  s21::FastMatrix<float> matrix1{3, 2};
  s21::FastMatrix<float> matrix2{2, 2};

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1.SumMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2.SumMatrix(matrix1));
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSum, TestSumFunctionException4) {
  s21::FastMatrix<float> matrix1{2, 3};
  s21::FastMatrix<float> matrix2{2, 2};

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1.SumMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2.SumMatrix(matrix1));
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSum, TestSumFunctionException5) {
  s21::FastMatrix<float> matrix1{2, 2};
  s21::FastMatrix<float> matrix2{2, 3};

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0f);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0f);

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1.SumMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2.SumMatrix(matrix1));
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSum, TestSumFunctionException6) {
  s21::FastMatrix<float> matrix1{2, 2};
  s21::FastMatrix<float> matrix2{3, 2};

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0f);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0f);

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1.SumMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2.SumMatrix(matrix1));
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSum, TestSumFunctionException7) {
  s21::FastMatrix<float> matrix1{3, 2};
  s21::FastMatrix<float> matrix2{2, 2};

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0f);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0f);

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1.SumMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2.SumMatrix(matrix1));
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSum, TestSumFunctionException8) {
  s21::FastMatrix<float> matrix1{2, 3};
  s21::FastMatrix<float> matrix2{2, 2};

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0f);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0f);

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1.SumMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2.SumMatrix(matrix1));
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты исключений операций суммирования
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestSum, TestSumOperatorException1) {
  s21::FastMatrix<float> matrix1{2, 2};
  s21::FastMatrix<float> matrix2{2, 3};

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 + matrix2);
  EXPECT_ANY_THROW(matrix2 + matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSum, TestSumOperatorException2) {
  s21::FastMatrix<float> matrix1{2, 2};
  s21::FastMatrix<float> matrix2{3, 2};

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 + matrix2);
  EXPECT_ANY_THROW(matrix2 + matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSum, TestSumOperatorException3) {
  s21::FastMatrix<float> matrix1{3, 2};
  s21::FastMatrix<float> matrix2{2, 2};

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 + matrix2);
  EXPECT_ANY_THROW(matrix2 + matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSum, TestSumOperatorException4) {
  s21::FastMatrix<float> matrix1{2, 3};
  s21::FastMatrix<float> matrix2{2, 2};

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 + matrix2);
  EXPECT_ANY_THROW(matrix2 + matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSum, TestSumOperatorException5) {
  s21::FastMatrix<float> matrix1{2, 2};
  s21::FastMatrix<float> matrix2{2, 3};

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0f);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0f);

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 + matrix2);
  EXPECT_ANY_THROW(matrix2 + matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSum, TestSumOperatorException6) {
  s21::FastMatrix<float> matrix1{2, 2};
  s21::FastMatrix<float> matrix2{3, 2};

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0f);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0f);

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 + matrix2);
  EXPECT_ANY_THROW(matrix2 + matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSum, TestSumOperatorException7) {
  s21::FastMatrix<float> matrix1{3, 2};
  s21::FastMatrix<float> matrix2{2, 2};

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0f);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0f);

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 + matrix2);
  EXPECT_ANY_THROW(matrix2 + matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSum, TestSumOperatorException8) {
  s21::FastMatrix<float> matrix1{2, 3};
  s21::FastMatrix<float> matrix2{2, 2};

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0f);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0f);

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 + matrix2);
  EXPECT_ANY_THROW(matrix2 + matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSum, TestSumOperatorException9) {
  s21::FastMatrix<float> matrix1{2, 2};
  s21::FastMatrix<float> matrix2{2, 3};

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 += matrix2);
  EXPECT_ANY_THROW(matrix2 += matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSum, TestSumOperatorException10) {
  s21::FastMatrix<float> matrix1{2, 2};
  s21::FastMatrix<float> matrix2{3, 2};

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 += matrix2);
  EXPECT_ANY_THROW(matrix2 += matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSum, TestSumOperatorException11) {
  s21::FastMatrix<float> matrix1{3, 2};
  s21::FastMatrix<float> matrix2{2, 2};

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 += matrix2);
  EXPECT_ANY_THROW(matrix2 += matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSum, TestSumOperatorException12) {
  s21::FastMatrix<float> matrix1{2, 3};
  s21::FastMatrix<float> matrix2{2, 2};

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 += matrix2);
  EXPECT_ANY_THROW(matrix2 += matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSum, TestSumOperatorException13) {
  s21::FastMatrix<float> matrix1{2, 2};
  s21::FastMatrix<float> matrix2{2, 3};

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0f);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0f);

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 += matrix2);
  EXPECT_ANY_THROW(matrix2 += matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSum, TestSumOperatorException14) {
  s21::FastMatrix<float> matrix1{2, 2};
  s21::FastMatrix<float> matrix2{3, 2};

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0f);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0f);

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 += matrix2);
  EXPECT_ANY_THROW(matrix2 += matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSum, TestSumOperatorException15) {
  s21::FastMatrix<float> matrix1{3, 2};
  s21::FastMatrix<float> matrix2{2, 2};

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0f);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0f);

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 += matrix2);
  EXPECT_ANY_THROW(matrix2 += matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSum, TestSumOperatorException16) {
  s21::FastMatrix<float> matrix1{2, 3};
  s21::FastMatrix<float> matrix2{2, 2};

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0f);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0f);

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 += matrix2);
  EXPECT_ANY_THROW(matrix2 += matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты успешного суммирования функцией
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestSum, TestSum1) {
  s21::FastMatrix<float> matrix1{95, 99};
  EXPECT_EQ(matrix1.get_rows(), 95);
  EXPECT_EQ(matrix1.get_cols(), 99);

  s21::FastMatrix<float> matrix2{95, 99};
  EXPECT_EQ(matrix2.get_rows(), 95);
  EXPECT_EQ(matrix2.get_cols(), 99);

  s21_matrix_test_helper::FillMatrix(matrix1, 2.5f);
  s21_matrix_test_helper::FillMatrix(matrix2, 3.5f);

  matrix1.SumMatrix(matrix2);

  s21_matrix_test_helper::CheckMatrix(matrix1, 2.5f + 3.5f);

  matrix2.SumMatrix(matrix1);

  s21_matrix_test_helper::CheckMatrix(matrix2, 3.5f + 2.5f + 3.5f);
}

TEST(TestSum, TestSum2) {
  s21::FastMatrix<float> matrix1{99, 99};
  EXPECT_EQ(matrix1.get_rows(), 99);
  EXPECT_EQ(matrix1.get_cols(), 99);

  s21::FastMatrix<float> matrix2{99, 99};
  EXPECT_EQ(matrix2.get_rows(), 99);
  EXPECT_EQ(matrix2.get_cols(), 99);

  s21_matrix_test_helper::FillMatrix(matrix1, 2.5f);
  s21_matrix_test_helper::FillMatrix(matrix2, -2.5f);

  matrix1.SumMatrix(matrix2);

  s21_matrix_test_helper::CheckMatrix(matrix1, 0.0f);

  matrix2.SumMatrix(matrix1);

  s21_matrix_test_helper::CheckMatrix(matrix2, -2.5f);
}

TEST(TestSum, TestSum3) {
  s21::FastMatrix<float> matrix1{4, 3};
  EXPECT_EQ(matrix1.get_rows(), 4);
  EXPECT_EQ(matrix1.get_cols(), 3);

  s21::FastMatrix<float> matrix2{4, 3};
  EXPECT_EQ(matrix2.get_rows(), 4);
  EXPECT_EQ(matrix2.get_cols(), 3);

  s21::FastMatrix<float> check_matrix{4, 3};
  EXPECT_EQ(matrix2.get_rows(), 4);
  EXPECT_EQ(matrix2.get_cols(), 3);

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

  matrix2(0, 0) = 0.0;
  matrix2(0, 1) = 1.0;
  matrix2(0, 2) = 2.0;
  matrix2(1, 0) = 3.0;
  matrix2(1, 1) = 0.0;
  matrix2(1, 2) = 4.0;
  matrix2(2, 0) = -1.0;
  matrix2(2, 1) = -2.0;
  matrix2(2, 2) = 0.0;
  matrix2(3, 0) = -3.0;
  matrix2(3, 1) = 0.0;
  matrix2(3, 2) = 4.0;

  check_matrix(0, 0) = 1.5;
  check_matrix(0, 1) = 3.5;
  check_matrix(0, 2) = 5.5;
  check_matrix(1, 0) = 1.5;
  check_matrix(1, 1) = -2.5;
  check_matrix(1, 2) = 0.5;
  check_matrix(2, 0) = -1.0;
  check_matrix(2, 1) = -2.0;
  check_matrix(2, 2) = 0.0;
  check_matrix(3, 0) = -2.0;
  check_matrix(3, 1) = 1.0;
  check_matrix(3, 2) = 5.0;

  matrix1.SumMatrix(matrix2);

  EXPECT_TRUE(matrix1 == check_matrix);
}

TEST(TestSum, TestSum4) {
  s21::FastMatrix<float> matrix1{2, 2};
  EXPECT_EQ(matrix1.get_rows(), 2);
  EXPECT_EQ(matrix1.get_cols(), 2);

  s21::FastMatrix<float> matrix2{2, 2};
  EXPECT_EQ(matrix2.get_rows(), 2);
  EXPECT_EQ(matrix2.get_cols(), 2);

  s21::FastMatrix<float> check_matrix{2, 2};
  EXPECT_EQ(matrix2.get_rows(), 2);
  EXPECT_EQ(matrix2.get_cols(), 2);

  matrix1(0, 0) = 145678000.588;
  matrix1(0, 1) = -4542;
  matrix1(1, 0) = 673552.54545324;
  matrix1(1, 1) = 145678000.588;

  matrix2(0, 0) = 14567800.777;
  matrix2(0, 1) = -4542;
  matrix2(1, 0) = 3.0;
  matrix2(1, 1) = 0.0;

  check_matrix(0, 0) = 160245801.365;
  check_matrix(0, 1) = -9084;
  check_matrix(1, 0) = 673555.54545324;
  check_matrix(1, 1) = 145678000.588;

  matrix1.SumMatrix(matrix2);

  EXPECT_TRUE(matrix1 == check_matrix);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты успешного суммирования операторами
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestSum, TestSumOperation1) {
  s21::FastMatrix<float> matrix1{95, 99};
  EXPECT_EQ(matrix1.get_rows(), 95);
  EXPECT_EQ(matrix1.get_cols(), 99);

  s21::FastMatrix<float> matrix2{95, 99};
  EXPECT_EQ(matrix2.get_rows(), 95);
  EXPECT_EQ(matrix2.get_cols(), 99);

  s21_matrix_test_helper::FillMatrix(matrix1, 2.5f);
  s21_matrix_test_helper::FillMatrix(matrix2, 3.5f);

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;
  s21::FastMatrix<float> result = matrix1 + matrix2;

  EXPECT_EQ(result.get_rows(), 95);
  EXPECT_EQ(result.get_cols(), 99);
  s21_matrix_test_helper::CheckMatrix(result, 2.5f + 3.5f);
  EXPECT_TRUE(matrix1_before == matrix1);
  EXPECT_TRUE(matrix2_before == matrix2);
}

TEST(TestSum, TestSumOperation2) {
  s21::FastMatrix<float> matrix1{99, 99};
  EXPECT_EQ(matrix1.get_rows(), 99);
  EXPECT_EQ(matrix1.get_cols(), 99);

  s21::FastMatrix<float> matrix2{99, 99};
  EXPECT_EQ(matrix2.get_rows(), 99);
  EXPECT_EQ(matrix2.get_cols(), 99);

  s21_matrix_test_helper::FillMatrix(matrix1, 2.5f);
  s21_matrix_test_helper::FillMatrix(matrix2, -2.5f);

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;
  s21::FastMatrix<float> result = matrix1 + matrix2;

  EXPECT_EQ(result.get_rows(), 99);
  EXPECT_EQ(result.get_cols(), 99);
  s21_matrix_test_helper::CheckMatrix(result, 0.0f);
  EXPECT_TRUE(matrix1_before == matrix1);
  EXPECT_TRUE(matrix2_before == matrix2);
}

TEST(TestSum, TestSumOperation3) {
  s21::FastMatrix<float> matrix1{4, 3};
  EXPECT_EQ(matrix1.get_rows(), 4);
  EXPECT_EQ(matrix1.get_cols(), 3);

  s21::FastMatrix<float> matrix2{4, 3};
  EXPECT_EQ(matrix2.get_rows(), 4);
  EXPECT_EQ(matrix2.get_cols(), 3);

  s21::FastMatrix<float> check_matrix{4, 3};
  EXPECT_EQ(matrix2.get_rows(), 4);
  EXPECT_EQ(matrix2.get_cols(), 3);

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

  matrix2(0, 0) = 0.0;
  matrix2(0, 1) = 1.0;
  matrix2(0, 2) = 2.0;
  matrix2(1, 0) = 3.0;
  matrix2(1, 1) = 0.0;
  matrix2(1, 2) = 4.0;
  matrix2(2, 0) = -1.0;
  matrix2(2, 1) = -2.0;
  matrix2(2, 2) = 0.0;
  matrix2(3, 0) = -3.0;
  matrix2(3, 1) = 0.0;
  matrix2(3, 2) = 4.0;

  check_matrix(0, 0) = 1.5;
  check_matrix(0, 1) = 3.5;
  check_matrix(0, 2) = 5.5;
  check_matrix(1, 0) = 1.5;
  check_matrix(1, 1) = -2.5;
  check_matrix(1, 2) = 0.5;
  check_matrix(2, 0) = -1.0;
  check_matrix(2, 1) = -2.0;
  check_matrix(2, 2) = 0.0;
  check_matrix(3, 0) = -2.0;
  check_matrix(3, 1) = 1.0;
  check_matrix(3, 2) = 5.0;

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;
  s21::FastMatrix<float> result = matrix1 + matrix2;

  EXPECT_EQ(result.get_rows(), 4);
  EXPECT_EQ(result.get_cols(), 3);

  EXPECT_TRUE(result == check_matrix);
  EXPECT_TRUE(matrix1_before == matrix1);
  EXPECT_TRUE(matrix2_before == matrix2);
}

TEST(TestSum, TestSumOperation4) {
  s21::FastMatrix<float> matrix1{2, 2};
  EXPECT_EQ(matrix1.get_rows(), 2);
  EXPECT_EQ(matrix1.get_cols(), 2);

  s21::FastMatrix<float> matrix2{2, 2};
  EXPECT_EQ(matrix2.get_rows(), 2);
  EXPECT_EQ(matrix2.get_cols(), 2);

  s21::FastMatrix<float> check_matrix{2, 2};
  EXPECT_EQ(matrix2.get_rows(), 2);
  EXPECT_EQ(matrix2.get_cols(), 2);

  matrix1(0, 0) = 145678000.588;
  matrix1(0, 1) = -4542;
  matrix1(1, 0) = 673552.54545324;
  matrix1(1, 1) = 145678000.588;

  matrix2(0, 0) = 14567800.777;
  matrix2(0, 1) = -4542;
  matrix2(1, 0) = 3.0;
  matrix2(1, 1) = 0.0;

  check_matrix(0, 0) = 160245801.365;
  check_matrix(0, 1) = -9084;
  check_matrix(1, 0) = 673555.54545324;
  check_matrix(1, 1) = 145678000.588;

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;
  s21::FastMatrix<float> result = matrix1 + matrix2;

  EXPECT_EQ(result.get_rows(), 2);
  EXPECT_EQ(result.get_cols(), 2);

  EXPECT_TRUE(result == check_matrix);
  EXPECT_TRUE(matrix1_before == matrix1);
  EXPECT_TRUE(matrix2_before == matrix2);
}

TEST(TestSum, TestSumOperation5) {
  s21::FastMatrix<float> matrix1{95, 99};
  EXPECT_EQ(matrix1.get_rows(), 95);
  EXPECT_EQ(matrix1.get_cols(), 99);

  s21::FastMatrix<float> matrix2{95, 99};
  EXPECT_EQ(matrix2.get_rows(), 95);
  EXPECT_EQ(matrix2.get_cols(), 99);

  s21_matrix_test_helper::FillMatrix(matrix1, 2.5f);
  s21_matrix_test_helper::FillMatrix(matrix2, 3.5f);

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;
  s21::FastMatrix<float> result{95, 99};

  result += matrix1;

  EXPECT_EQ(result.get_rows(), 95);
  EXPECT_EQ(result.get_cols(), 99);
  s21_matrix_test_helper::CheckMatrix(result, 2.5f);

  result += matrix2;

  EXPECT_EQ(result.get_rows(), 95);
  EXPECT_EQ(result.get_cols(), 99);
  s21_matrix_test_helper::CheckMatrix(result, 2.5f + 3.5f);

  EXPECT_TRUE(matrix1_before == matrix1);
  EXPECT_TRUE(matrix2_before == matrix2);
}

TEST(TestSum, TestSumOperation6) {
  s21::FastMatrix<float> matrix1{99, 99};
  EXPECT_EQ(matrix1.get_rows(), 99);
  EXPECT_EQ(matrix1.get_cols(), 99);

  s21::FastMatrix<float> matrix2{99, 99};
  EXPECT_EQ(matrix2.get_rows(), 99);
  EXPECT_EQ(matrix2.get_cols(), 99);

  s21_matrix_test_helper::FillMatrix(matrix1, 2.5f);
  s21_matrix_test_helper::FillMatrix(matrix2, -2.5f);

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;
  s21::FastMatrix<float> result{99, 99};

  result += matrix1;

  EXPECT_EQ(result.get_rows(), 99);
  EXPECT_EQ(result.get_cols(), 99);
  s21_matrix_test_helper::CheckMatrix(result, 2.5f);

  result += matrix2;

  EXPECT_EQ(result.get_rows(), 99);
  EXPECT_EQ(result.get_cols(), 99);
  s21_matrix_test_helper::CheckMatrix(result, 0.0f);

  EXPECT_TRUE(matrix1_before == matrix1);
  EXPECT_TRUE(matrix2_before == matrix2);
}

TEST(TestSum, TestSumOperation7) {
  s21::FastMatrix<float> matrix1{4, 3};
  EXPECT_EQ(matrix1.get_rows(), 4);
  EXPECT_EQ(matrix1.get_cols(), 3);

  s21::FastMatrix<float> matrix2{4, 3};
  EXPECT_EQ(matrix2.get_rows(), 4);
  EXPECT_EQ(matrix2.get_cols(), 3);

  s21::FastMatrix<float> check_matrix{4, 3};
  EXPECT_EQ(matrix2.get_rows(), 4);
  EXPECT_EQ(matrix2.get_cols(), 3);

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

  matrix2(0, 0) = 0.0;
  matrix2(0, 1) = 1.0;
  matrix2(0, 2) = 2.0;
  matrix2(1, 0) = 3.0;
  matrix2(1, 1) = 0.0;
  matrix2(1, 2) = 4.0;
  matrix2(2, 0) = -1.0;
  matrix2(2, 1) = -2.0;
  matrix2(2, 2) = 0.0;
  matrix2(3, 0) = -3.0;
  matrix2(3, 1) = 0.0;
  matrix2(3, 2) = 4.0;

  check_matrix(0, 0) = 1.5;
  check_matrix(0, 1) = 3.5;
  check_matrix(0, 2) = 5.5;
  check_matrix(1, 0) = 1.5;
  check_matrix(1, 1) = -2.5;
  check_matrix(1, 2) = 0.5;
  check_matrix(2, 0) = -1.0;
  check_matrix(2, 1) = -2.0;
  check_matrix(2, 2) = 0.0;
  check_matrix(3, 0) = -2.0;
  check_matrix(3, 1) = 1.0;
  check_matrix(3, 2) = 5.0;

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;
  s21::FastMatrix<float> result = matrix1;
  result += matrix2;

  EXPECT_EQ(result.get_rows(), 4);
  EXPECT_EQ(result.get_cols(), 3);

  EXPECT_TRUE(result == check_matrix);
  EXPECT_TRUE(matrix1_before == matrix1);
  EXPECT_TRUE(matrix2_before == matrix2);
}

TEST(TestSum, TestSumOperation8) {
  s21::FastMatrix<float> matrix1{2, 2};
  EXPECT_EQ(matrix1.get_rows(), 2);
  EXPECT_EQ(matrix1.get_cols(), 2);

  s21::FastMatrix<float> matrix2{2, 2};
  EXPECT_EQ(matrix2.get_rows(), 2);
  EXPECT_EQ(matrix2.get_cols(), 2);

  s21::FastMatrix<float> check_matrix{2, 2};
  EXPECT_EQ(matrix2.get_rows(), 2);
  EXPECT_EQ(matrix2.get_cols(), 2);

  matrix1(0, 0) = 145678000.588;
  matrix1(0, 1) = -4542;
  matrix1(1, 0) = 673552.54545324;
  matrix1(1, 1) = 145678000.588;

  matrix2(0, 0) = 14567800.777;
  matrix2(0, 1) = -4542;
  matrix2(1, 0) = 3.0;
  matrix2(1, 1) = 0.0;

  check_matrix(0, 0) = 160245801.365;
  check_matrix(0, 1) = -9084;
  check_matrix(1, 0) = 673555.54545324;
  check_matrix(1, 1) = 145678000.588;

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;
  s21::FastMatrix<float> result = matrix1;
  result += matrix2;

  EXPECT_EQ(result.get_rows(), 2);
  EXPECT_EQ(result.get_cols(), 2);

  EXPECT_TRUE(result == check_matrix);
  EXPECT_TRUE(matrix1_before == matrix1);
  EXPECT_TRUE(matrix2_before == matrix2);
}

TEST(TestSum, TestSumOperation9) {
  s21::FastMatrix<float> matrix1{1, 1};
  EXPECT_EQ(matrix1.get_rows(), 1);
  EXPECT_EQ(matrix1.get_cols(), 1);

  s21::FastMatrix<float> matrix2{1, 1};
  EXPECT_EQ(matrix2.get_rows(), 1);
  EXPECT_EQ(matrix2.get_cols(), 1);

  s21::FastMatrix<float> check_matrix{1, 1};
  EXPECT_EQ(matrix2.get_rows(), 1);
  EXPECT_EQ(matrix2.get_cols(), 1);

  matrix1(0, 0) = 1.0;
  matrix2(0, 0) = 0.5;
  check_matrix(0, 0) = 1.5;

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;
  s21::FastMatrix<float> result1 = matrix1;
  s21::FastMatrix<float> result2 = matrix1 + matrix2;
  result1 += matrix2;

  EXPECT_EQ(result1.get_rows(), 1);
  EXPECT_EQ(result1.get_cols(), 1);
  EXPECT_TRUE(result1 == check_matrix);

  EXPECT_EQ(result2.get_rows(), 1);
  EXPECT_EQ(result2.get_cols(), 1);
  EXPECT_TRUE(result2 == check_matrix);

  EXPECT_TRUE(matrix1_before == matrix1);
  EXPECT_TRUE(matrix2_before == matrix2);
}
