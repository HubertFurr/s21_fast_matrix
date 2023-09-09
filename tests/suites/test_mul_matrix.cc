#include "./../classes/random_suites.h"
#include "./../test.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты исключений функции умножения матриц
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestMulMatrix, TestMulMatrixFunctionException1) {
  s21::FastMatrix<float> matrix1{3, 2};
  s21::FastMatrix<float> matrix2{3, 2};

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1.MulMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2.MulMatrix(matrix1));
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrixFunctionException2) {
  s21::FastMatrix<float> matrix1{2, 3};
  s21::FastMatrix<float> matrix2{2, 3};

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1.MulMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2.MulMatrix(matrix1));
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrixFunctionException3) {
  s21::FastMatrix<float> matrix1{2, 2};
  s21::FastMatrix<float> matrix2{3, 3};

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1.MulMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2.MulMatrix(matrix1));
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrixFunctionException4) {
  s21::FastMatrix<float> matrix1{3, 3};
  s21::FastMatrix<float> matrix2{2, 2};

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1.MulMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2.MulMatrix(matrix1));
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrixFunctionException5) {
  s21::FastMatrix<float> matrix1{3, 2};
  s21::FastMatrix<float> matrix2{3, 2};

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0f);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0f);

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1.MulMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2.MulMatrix(matrix1));
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrixFunctionException6) {
  s21::FastMatrix<float> matrix1{2, 3};
  s21::FastMatrix<float> matrix2{2, 3};

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0f);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0f);

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1.MulMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2.MulMatrix(matrix1));
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrixFunctionException7) {
  s21::FastMatrix<float> matrix1{3, 3};
  s21::FastMatrix<float> matrix2{2, 2};

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0f);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0f);

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1.MulMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2.MulMatrix(matrix1));
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrixFunctionException8) {
  s21::FastMatrix<float> matrix1{2, 2};
  s21::FastMatrix<float> matrix2{3, 3};

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0f);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0f);

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1.MulMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2.MulMatrix(matrix1));
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты исключений операций умножения матриц
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestMulMatrix, TestMulMatrixOperatorException1) {
  s21::FastMatrix<float> matrix1{3, 2};
  s21::FastMatrix<float> matrix2{3, 2};

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 * matrix2);
  EXPECT_ANY_THROW(matrix2 * matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrixOperatorException2) {
  s21::FastMatrix<float> matrix1{2, 3};
  s21::FastMatrix<float> matrix2{2, 3};

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 * matrix2);
  EXPECT_ANY_THROW(matrix2 * matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrixOperatorException3) {
  s21::FastMatrix<float> matrix1{3, 3};
  s21::FastMatrix<float> matrix2{2, 2};

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 * matrix2);
  EXPECT_ANY_THROW(matrix2 * matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrixOperatorException4) {
  s21::FastMatrix<float> matrix1{2, 2};
  s21::FastMatrix<float> matrix2{3, 3};

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 * matrix2);
  EXPECT_ANY_THROW(matrix2 * matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrixOperatorException5) {
  s21::FastMatrix<float> matrix1{3, 2};
  s21::FastMatrix<float> matrix2{3, 2};

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0f);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0f);

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 * matrix2);
  EXPECT_ANY_THROW(matrix2 * matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrixOperatorException6) {
  s21::FastMatrix<float> matrix1{2, 3};
  s21::FastMatrix<float> matrix2{2, 3};

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0f);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0f);

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 * matrix2);
  EXPECT_ANY_THROW(matrix2 * matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrixOperatorException7) {
  s21::FastMatrix<float> matrix1{3, 3};
  s21::FastMatrix<float> matrix2{2, 2};

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0f);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0f);

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 * matrix2);
  EXPECT_ANY_THROW(matrix2 * matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrixOperatorException8) {
  s21::FastMatrix<float> matrix1{2, 2};
  s21::FastMatrix<float> matrix2{3, 3};

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0f);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0f);

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 * matrix2);
  EXPECT_ANY_THROW(matrix2 * matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrixOperatorException9) {
  s21::FastMatrix<float> matrix1{3, 2};
  s21::FastMatrix<float> matrix2{3, 2};

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 *= matrix2);
  EXPECT_ANY_THROW(matrix2 *= matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrixOperatorException10) {
  s21::FastMatrix<float> matrix1{2, 3};
  s21::FastMatrix<float> matrix2{2, 3};

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 *= matrix2);
  EXPECT_ANY_THROW(matrix2 *= matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrixOperatorException11) {
  s21::FastMatrix<float> matrix1{3, 3};
  s21::FastMatrix<float> matrix2{2, 2};

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 *= matrix2);
  EXPECT_ANY_THROW(matrix2 *= matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrixOperatorException12) {
  s21::FastMatrix<float> matrix1{2, 2};
  s21::FastMatrix<float> matrix2{3, 3};

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 *= matrix2);
  EXPECT_ANY_THROW(matrix2 *= matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrixOperatorException13) {
  s21::FastMatrix<float> matrix1{3, 2};
  s21::FastMatrix<float> matrix2{3, 2};

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0f);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0f);

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 *= matrix2);
  EXPECT_ANY_THROW(matrix2 *= matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrixOperatorException14) {
  s21::FastMatrix<float> matrix1{2, 3};
  s21::FastMatrix<float> matrix2{2, 3};

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0f);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0f);

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 *= matrix2);
  EXPECT_ANY_THROW(matrix2 *= matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrixOperatorException15) {
  s21::FastMatrix<float> matrix1{3, 3};
  s21::FastMatrix<float> matrix2{2, 2};

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0f);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0f);

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 *= matrix2);
  EXPECT_ANY_THROW(matrix2 *= matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrixOperatorException16) {
  s21::FastMatrix<float> matrix1{2, 2};
  s21::FastMatrix<float> matrix2{3, 3};

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0f);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0f);

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 *= matrix2);
  EXPECT_ANY_THROW(matrix2 *= matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты успешного умножения матриц функцией
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestMulMatrix, TestMulMatrix1) {
  s21::FastMatrix<float> matrix1{95, 98};
  EXPECT_EQ(matrix1.get_rows(), 95);
  EXPECT_EQ(matrix1.get_cols(), 98);

  s21::FastMatrix<float> matrix2{98, 99};
  EXPECT_EQ(matrix2.get_rows(), 98);
  EXPECT_EQ(matrix2.get_cols(), 99);

  s21::FastMatrix<float> check_matrix{95, 99};
  EXPECT_EQ(check_matrix.get_rows(), 95);
  EXPECT_EQ(check_matrix.get_cols(), 99);

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0f);
  s21_matrix_test_helper::FillMatrix(matrix2, 1.0f);
  s21_matrix_test_helper::FillMatrix(check_matrix, 98.0f);

  s21::FastMatrix<float> matrix2_before = matrix2;
  matrix1.MulMatrix(matrix2);

  EXPECT_EQ(matrix1.get_rows(), 95);
  EXPECT_EQ(matrix1.get_cols(), 99);

  ASSERT_TRUE(matrix1 == check_matrix);
  ASSERT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrix2) {
  s21::FastMatrix<float> matrix1{99, 99};
  EXPECT_EQ(matrix1.get_rows(), 99);
  EXPECT_EQ(matrix1.get_cols(), 99);

  s21::FastMatrix<float> matrix2{99, 99};
  EXPECT_EQ(matrix2.get_rows(), 99);
  EXPECT_EQ(matrix2.get_cols(), 99);

  s21::FastMatrix<float> check_matrix{99, 99};
  EXPECT_EQ(check_matrix.get_rows(), 99);
  EXPECT_EQ(check_matrix.get_cols(), 99);

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0f);
  s21_matrix_test_helper::FillMatrix(matrix2, 0.0f);
  s21_matrix_test_helper::FillMatrix(check_matrix, 0.0f);

  s21::FastMatrix<float> matrix2_before = matrix2;
  matrix1.MulMatrix(matrix2);

  EXPECT_EQ(matrix1.get_rows(), 99);
  EXPECT_EQ(matrix1.get_cols(), 99);

  ASSERT_TRUE(matrix1 == check_matrix);
  ASSERT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrix3) {
  s21::FastMatrix<float> matrix1{2, 2};
  EXPECT_EQ(matrix1.get_rows(), 2);
  EXPECT_EQ(matrix1.get_cols(), 2);

  s21::FastMatrix<float> matrix2{2, 2};
  EXPECT_EQ(matrix2.get_rows(), 2);
  EXPECT_EQ(matrix2.get_cols(), 2);

  s21::FastMatrix<float> check_matrix{2, 2};
  EXPECT_EQ(check_matrix.get_rows(), 2);
  EXPECT_EQ(check_matrix.get_cols(), 2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  matrix2(0, 0) = 2;
  matrix2(0, 1) = 3;
  matrix2(1, 0) = 4;
  matrix2(1, 1) = 5;

  check_matrix(0, 0) = 10;
  check_matrix(0, 1) = 13;
  check_matrix(1, 0) = 22;
  check_matrix(1, 1) = 29;

  s21::FastMatrix<float> matrix2_before = matrix2;
  matrix1.MulMatrix(matrix2);

  EXPECT_EQ(matrix1.get_rows(), 2);
  EXPECT_EQ(matrix1.get_cols(), 2);

  ASSERT_TRUE(matrix1 == check_matrix);
  ASSERT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrix4) {
  s21::FastMatrix<float> matrix1{4, 3};
  EXPECT_EQ(matrix1.get_rows(), 4);
  EXPECT_EQ(matrix1.get_cols(), 3);

  s21::FastMatrix<float> matrix2{3, 3};
  EXPECT_EQ(matrix2.get_rows(), 3);
  EXPECT_EQ(matrix2.get_cols(), 3);

  s21::FastMatrix<float> check_matrix{4, 3};
  EXPECT_EQ(check_matrix.get_rows(), 4);
  EXPECT_EQ(check_matrix.get_cols(), 3);

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

  check_matrix(0, 0) = 4.0;
  check_matrix(0, 1) = -5.5;
  check_matrix(0, 2) = 13.0;
  check_matrix(1, 0) = -4.0;
  check_matrix(1, 1) = 5.5;
  check_matrix(1, 2) = -13.0;
  check_matrix(2, 0) = 0.0;
  check_matrix(2, 1) = 0.0;
  check_matrix(2, 2) = 0.0;
  check_matrix(3, 0) = 2.0;
  check_matrix(3, 1) = -1.0;
  check_matrix(3, 2) = 6.0;

  s21::FastMatrix<float> matrix2_before = matrix2;
  matrix1.MulMatrix(matrix2);

  EXPECT_EQ(matrix1.get_rows(), 4);
  EXPECT_EQ(matrix1.get_cols(), 3);

  ASSERT_TRUE(matrix1 == check_matrix);
  ASSERT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrix5) {
  s21::FastMatrix<float> matrix1{2, 3};
  EXPECT_EQ(matrix1.get_rows(), 2);
  EXPECT_EQ(matrix1.get_cols(), 3);

  s21::FastMatrix<float> matrix2{3, 2};
  EXPECT_EQ(matrix2.get_rows(), 3);
  EXPECT_EQ(matrix2.get_cols(), 2);

  s21::FastMatrix<float> check_matrix{2, 2};
  EXPECT_EQ(check_matrix.get_rows(), 2);
  EXPECT_EQ(check_matrix.get_cols(), 2);

  matrix1(0, 0) = 14.58;
  matrix1(0, 1) = -45;
  matrix1(0, 2) = -2.0;
  matrix1(1, 0) = 67.545;
  matrix1(1, 1) = 14.58;
  matrix1(1, 2) = 3.0;

  matrix2(0, 0) = 14.777;
  matrix2(0, 1) = -42;
  matrix2(1, 0) = 3.0;
  matrix2(1, 1) = 0.0;
  matrix2(2, 0) = 2.0;
  matrix2(2, 1) = -3.0;

  check_matrix(0, 0) = 76.44867;
  check_matrix(0, 1) = -606.36;
  check_matrix(1, 0) = 1047.8525;
  check_matrix(1, 1) = -2845.89;

  s21::FastMatrix<float> matrix2_before = matrix2;
  matrix1.MulMatrix(matrix2);

  EXPECT_EQ(matrix1.get_rows(), 2);
  EXPECT_EQ(matrix1.get_cols(), 2);

  ASSERT_TRUE(matrix1 == check_matrix);
  ASSERT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrix6) {
  s21::FastMatrix<float> matrix1{1, 1};
  EXPECT_EQ(matrix1.get_rows(), 1);
  EXPECT_EQ(matrix1.get_cols(), 1);

  s21::FastMatrix<float> matrix2{1, 1};
  EXPECT_EQ(matrix2.get_rows(), 1);
  EXPECT_EQ(matrix2.get_cols(), 1);

  s21::FastMatrix<float> check_matrix{1, 1};
  EXPECT_EQ(check_matrix.get_rows(), 1);
  EXPECT_EQ(check_matrix.get_cols(), 1);

  matrix1(0, 0) = 1.456;

  matrix2(0, 0) = 12.987;

  check_matrix(0, 0) = 18.909072;

  s21::FastMatrix<float> matrix2_before = matrix2;
  matrix1.MulMatrix(matrix2);

  EXPECT_EQ(matrix1.get_rows(), 1);
  EXPECT_EQ(matrix1.get_cols(), 1);

  ASSERT_TRUE(matrix1 == check_matrix);
  ASSERT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrix7) {
  s21::FastMatrix<float> matrix1{2, 3};
  EXPECT_EQ(matrix1.get_rows(), 2);
  EXPECT_EQ(matrix1.get_cols(), 3);

  s21::FastMatrix<float> matrix2{3, 1};
  EXPECT_EQ(matrix2.get_rows(), 3);
  EXPECT_EQ(matrix2.get_cols(), 1);

  s21::FastMatrix<float> check_matrix{2, 1};
  EXPECT_EQ(check_matrix.get_rows(), 2);
  EXPECT_EQ(check_matrix.get_cols(), 1);

  matrix1(0, 0) = 14567.588;
  matrix1(0, 1) = -4542;
  matrix1(0, 2) = -2.0;
  matrix1(1, 0) = 673.545453;
  matrix1(1, 1) = 14567.588;
  matrix1(1, 2) = 3.0;

  matrix2(0, 0) = 14567.777;
  matrix2(1, 0) = -4542;
  matrix2(2, 0) = 3.0;

  check_matrix(0, 0) = 232847131.411876;
  check_matrix(1, 0) = -56353915.737332019;

  s21::FastMatrix<float> matrix2_before = matrix2;
  matrix1.MulMatrix(matrix2);

  EXPECT_EQ(matrix1.get_rows(), 2);
  EXPECT_EQ(matrix1.get_cols(), 1);

  ASSERT_TRUE(matrix1 == check_matrix);
  ASSERT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrix8) {
  s21::FastMatrix<float> matrix1{3, 2};
  EXPECT_EQ(matrix1.get_rows(), 3);
  EXPECT_EQ(matrix1.get_cols(), 2);

  s21::FastMatrix<float> matrix2{2, 1};
  EXPECT_EQ(matrix2.get_rows(), 2);
  EXPECT_EQ(matrix2.get_cols(), 1);

  s21::FastMatrix<float> check_matrix{3, 1};
  EXPECT_EQ(check_matrix.get_rows(), 3);
  EXPECT_EQ(check_matrix.get_cols(), 1);

  matrix1(0, 0) = 14567.588;
  matrix1(0, 1) = -4542;
  matrix1(1, 0) = -2.0;
  matrix1(1, 1) = 673.545453;
  matrix1(2, 0) = 14567.588;
  matrix1(2, 1) = 3.0;

  matrix2(0, 0) = 14567.777;
  matrix2(1, 0) = -4542;

  check_matrix(0, 0) = 232847137.411876;
  check_matrix(1, 0) = -3088379.001526;
  check_matrix(2, 0) = 212203747.411876;

  s21::FastMatrix<float> matrix2_before = matrix2;
  matrix1.MulMatrix(matrix2);

  EXPECT_EQ(matrix1.get_rows(), 3);
  EXPECT_EQ(matrix1.get_cols(), 1);

  ASSERT_TRUE(matrix1 == check_matrix);
  ASSERT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrix9) {
  s21::FastMatrix<float> matrix1{1, 2};
  EXPECT_EQ(matrix1.get_rows(), 1);
  EXPECT_EQ(matrix1.get_cols(), 2);

  s21::FastMatrix<float> matrix2{2, 3};
  EXPECT_EQ(matrix2.get_rows(), 2);
  EXPECT_EQ(matrix2.get_cols(), 3);

  s21::FastMatrix<float> check_matrix{1, 3};
  EXPECT_EQ(check_matrix.get_rows(), 1);
  EXPECT_EQ(check_matrix.get_cols(), 3);

  matrix1(0, 0) = 14567.588;
  matrix1(0, 1) = -4542;

  matrix2(0, 0) = 14567.777;
  matrix2(0, 1) = -4542;
  matrix2(0, 2) = -2.0;
  matrix2(1, 0) = 673.545453;
  matrix2(1, 1) = 14567.588;
  matrix2(1, 2) = 3.0;

  check_matrix(0, 0) = 209158129.96435;
  check_matrix(0, 1) = -132331969.392;
  check_matrix(0, 2) = -42761.176;

  s21::FastMatrix<float> matrix2_before = matrix2;
  matrix1.MulMatrix(matrix2);

  EXPECT_EQ(matrix1.get_rows(), 1);
  EXPECT_EQ(matrix1.get_cols(), 3);

  ASSERT_TRUE(matrix1 == check_matrix);
  ASSERT_TRUE(matrix2 == matrix2_before);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты успешного умножения матриц операторами
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestMulMatrix, TestMulMatrixOperator1) {
  s21::FastMatrix<float> matrix1{95, 98};
  EXPECT_EQ(matrix1.get_rows(), 95);
  EXPECT_EQ(matrix1.get_cols(), 98);

  s21::FastMatrix<float> matrix2{98, 99};
  EXPECT_EQ(matrix2.get_rows(), 98);
  EXPECT_EQ(matrix2.get_cols(), 99);

  s21::FastMatrix<float> check_matrix{95, 99};
  EXPECT_EQ(check_matrix.get_rows(), 95);
  EXPECT_EQ(check_matrix.get_cols(), 99);

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0f);
  s21_matrix_test_helper::FillMatrix(matrix2, 1.0f);
  s21_matrix_test_helper::FillMatrix(check_matrix, 98.0f);

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  s21::FastMatrix<float> result1 = matrix1 * matrix2;
  s21::FastMatrix<float> result2 = matrix1;
  result2 *= matrix2;

  ASSERT_TRUE(result1 == check_matrix);
  ASSERT_TRUE(result2 == check_matrix);
  ASSERT_TRUE(matrix1_before == matrix1);
  ASSERT_TRUE(matrix2_before == matrix2);
}

TEST(TestMulMatrix, TestMulMatrixOperator2) {
  s21::FastMatrix<float> matrix1{99, 99};
  EXPECT_EQ(matrix1.get_rows(), 99);
  EXPECT_EQ(matrix1.get_cols(), 99);

  s21::FastMatrix<float> matrix2{99, 99};
  EXPECT_EQ(matrix2.get_rows(), 99);
  EXPECT_EQ(matrix2.get_cols(), 99);

  s21::FastMatrix<float> check_matrix{99, 99};
  EXPECT_EQ(check_matrix.get_rows(), 99);
  EXPECT_EQ(check_matrix.get_cols(), 99);

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0f);
  s21_matrix_test_helper::FillMatrix(matrix2, 0.0f);
  s21_matrix_test_helper::FillMatrix(check_matrix, 0.0f);

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  s21::FastMatrix<float> result1 = matrix1 * matrix2;
  s21::FastMatrix<float> result2 = matrix1;
  result2 *= matrix2;

  ASSERT_TRUE(result1 == check_matrix);
  ASSERT_TRUE(result2 == check_matrix);
  ASSERT_TRUE(matrix1_before == matrix1);
  ASSERT_TRUE(matrix2_before == matrix2);
}

TEST(TestMulMatrix, TestMulMatrixOperator3) {
  s21::FastMatrix<float> matrix1{2, 2};
  EXPECT_EQ(matrix1.get_rows(), 2);
  EXPECT_EQ(matrix1.get_cols(), 2);

  s21::FastMatrix<float> matrix2{2, 2};
  EXPECT_EQ(matrix2.get_rows(), 2);
  EXPECT_EQ(matrix2.get_cols(), 2);

  s21::FastMatrix<float> check_matrix{2, 2};
  EXPECT_EQ(check_matrix.get_rows(), 2);
  EXPECT_EQ(check_matrix.get_cols(), 2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  matrix2(0, 0) = 2;
  matrix2(0, 1) = 3;
  matrix2(1, 0) = 4;
  matrix2(1, 1) = 5;

  check_matrix(0, 0) = 10;
  check_matrix(0, 1) = 13;
  check_matrix(1, 0) = 22;
  check_matrix(1, 1) = 29;

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  s21::FastMatrix<float> result1 = matrix1 * matrix2;
  s21::FastMatrix<float> result2 = matrix1;
  result2 *= matrix2;

  ASSERT_TRUE(result1 == check_matrix);
  ASSERT_TRUE(result2 == check_matrix);
  ASSERT_TRUE(matrix1_before == matrix1);
  ASSERT_TRUE(matrix2_before == matrix2);
}

TEST(TestMulMatrix, TestMulMatrixOperator4) {
  s21::FastMatrix<float> matrix1{4, 3};
  EXPECT_EQ(matrix1.get_rows(), 4);
  EXPECT_EQ(matrix1.get_cols(), 3);

  s21::FastMatrix<float> matrix2{3, 3};
  EXPECT_EQ(matrix2.get_rows(), 3);
  EXPECT_EQ(matrix2.get_cols(), 3);

  s21::FastMatrix<float> check_matrix{4, 3};
  EXPECT_EQ(check_matrix.get_rows(), 4);
  EXPECT_EQ(check_matrix.get_cols(), 3);

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

  check_matrix(0, 0) = 4.0;
  check_matrix(0, 1) = -5.5;
  check_matrix(0, 2) = 13.0;
  check_matrix(1, 0) = -4.0;
  check_matrix(1, 1) = 5.5;
  check_matrix(1, 2) = -13.0;
  check_matrix(2, 0) = 0.0;
  check_matrix(2, 1) = 0.0;
  check_matrix(2, 2) = 0.0;
  check_matrix(3, 0) = 2.0;
  check_matrix(3, 1) = -1.0;
  check_matrix(3, 2) = 6.0;

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  s21::FastMatrix<float> result1 = matrix1 * matrix2;
  s21::FastMatrix<float> result2 = matrix1;
  result2 *= matrix2;

  ASSERT_TRUE(result1 == check_matrix);
  ASSERT_TRUE(result2 == check_matrix);
  ASSERT_TRUE(matrix1_before == matrix1);
  ASSERT_TRUE(matrix2_before == matrix2);
}

TEST(TestMulMatrix, TestMulMatrixOperator5) {
  s21::FastMatrix<float> matrix1{2, 3};
  EXPECT_EQ(matrix1.get_rows(), 2);
  EXPECT_EQ(matrix1.get_cols(), 3);

  s21::FastMatrix<float> matrix2{3, 2};
  EXPECT_EQ(matrix2.get_rows(), 3);
  EXPECT_EQ(matrix2.get_cols(), 2);

  s21::FastMatrix<float> check_matrix{2, 2};
  EXPECT_EQ(check_matrix.get_rows(), 2);
  EXPECT_EQ(check_matrix.get_cols(), 2);

  matrix1(0, 0) = 14.58;
  matrix1(0, 1) = -45;
  matrix1(0, 2) = -2.0;
  matrix1(1, 0) = 67.545;
  matrix1(1, 1) = 14.58;
  matrix1(1, 2) = 3.0;

  matrix2(0, 0) = 14.777;
  matrix2(0, 1) = -42;
  matrix2(1, 0) = 3.0;
  matrix2(1, 1) = 0.0;
  matrix2(2, 0) = 2.0;
  matrix2(2, 1) = -3.0;

  check_matrix(0, 0) = 76.44867;
  check_matrix(0, 1) = -606.36;
  check_matrix(1, 0) = 1047.8525;
  check_matrix(1, 1) = -2845.89;

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  s21::FastMatrix<float> result1 = matrix1 * matrix2;
  s21::FastMatrix<float> result2 = matrix1;
  result2 *= matrix2;

  ASSERT_TRUE(result1 == check_matrix);
  ASSERT_TRUE(result2 == check_matrix);
  ASSERT_TRUE(matrix1_before == matrix1);
  ASSERT_TRUE(matrix2_before == matrix2);
}

TEST(TestMulMatrix, TestMulMatrixOperator6) {
  s21::FastMatrix<float> matrix1{1, 1};
  EXPECT_EQ(matrix1.get_rows(), 1);
  EXPECT_EQ(matrix1.get_cols(), 1);

  s21::FastMatrix<float> matrix2{1, 1};
  EXPECT_EQ(matrix2.get_rows(), 1);
  EXPECT_EQ(matrix2.get_cols(), 1);

  s21::FastMatrix<float> check_matrix{1, 1};
  EXPECT_EQ(check_matrix.get_rows(), 1);
  EXPECT_EQ(check_matrix.get_cols(), 1);

  matrix1(0, 0) = 1.456;

  matrix2(0, 0) = 12.987;

  check_matrix(0, 0) = 18.909072;

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  s21::FastMatrix<float> result1 = matrix1 * matrix2;
  s21::FastMatrix<float> result2 = matrix1;
  result2 *= matrix2;

  ASSERT_TRUE(result1 == check_matrix);
  ASSERT_TRUE(result2 == check_matrix);
  ASSERT_TRUE(matrix1_before == matrix1);
  ASSERT_TRUE(matrix2_before == matrix2);
}

TEST(TestMulMatrix, TestMulMatrixOperator7) {
  s21::FastMatrix<float> matrix1{2, 3};
  EXPECT_EQ(matrix1.get_rows(), 2);
  EXPECT_EQ(matrix1.get_cols(), 3);

  s21::FastMatrix<float> matrix2{3, 1};
  EXPECT_EQ(matrix2.get_rows(), 3);
  EXPECT_EQ(matrix2.get_cols(), 1);

  s21::FastMatrix<float> check_matrix{2, 1};
  EXPECT_EQ(check_matrix.get_rows(), 2);
  EXPECT_EQ(check_matrix.get_cols(), 1);

  matrix1(0, 0) = 14567.588;
  matrix1(0, 1) = -4542;
  matrix1(0, 2) = -2.0;
  matrix1(1, 0) = 673.545453;
  matrix1(1, 1) = 14567.588;
  matrix1(1, 2) = 3.0;

  matrix2(0, 0) = 14567.777;
  matrix2(1, 0) = -4542;
  matrix2(2, 0) = 3.0;

  check_matrix(0, 0) = 232847131.411876;
  check_matrix(1, 0) = -56353915.737332019;

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  s21::FastMatrix<float> result1 = matrix1 * matrix2;
  s21::FastMatrix<float> result2 = matrix1;
  result2 *= matrix2;

  ASSERT_TRUE(result1 == check_matrix);
  ASSERT_TRUE(result2 == check_matrix);
  ASSERT_TRUE(matrix1_before == matrix1);
  ASSERT_TRUE(matrix2_before == matrix2);
}

TEST(TestMulMatrix, TestMulMatrixOperator8) {
  s21::FastMatrix<float> matrix1{3, 2};
  EXPECT_EQ(matrix1.get_rows(), 3);
  EXPECT_EQ(matrix1.get_cols(), 2);

  s21::FastMatrix<float> matrix2{2, 1};
  EXPECT_EQ(matrix2.get_rows(), 2);
  EXPECT_EQ(matrix2.get_cols(), 1);

  s21::FastMatrix<float> check_matrix{3, 1};
  EXPECT_EQ(check_matrix.get_rows(), 3);
  EXPECT_EQ(check_matrix.get_cols(), 1);

  matrix1(0, 0) = 14567.588;
  matrix1(0, 1) = -4542;
  matrix1(1, 0) = -2.0;
  matrix1(1, 1) = 673.545453;
  matrix1(2, 0) = 14567.588;
  matrix1(2, 1) = 3.0;

  matrix2(0, 0) = 14567.777;
  matrix2(1, 0) = -4542;

  check_matrix(0, 0) = 232847137.411876;
  check_matrix(1, 0) = -3088379.001526;
  check_matrix(2, 0) = 212203747.411876;

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  s21::FastMatrix<float> result1 = matrix1 * matrix2;
  s21::FastMatrix<float> result2 = matrix1;
  result2 *= matrix2;

  ASSERT_TRUE(result1 == check_matrix);
  ASSERT_TRUE(result2 == check_matrix);
  ASSERT_TRUE(matrix1_before == matrix1);
  ASSERT_TRUE(matrix2_before == matrix2);
}

TEST(TestMulMatrix, TestMulMatrixOperator9) {
  s21::FastMatrix<float> matrix1{1, 2};
  EXPECT_EQ(matrix1.get_rows(), 1);
  EXPECT_EQ(matrix1.get_cols(), 2);

  s21::FastMatrix<float> matrix2{2, 3};
  EXPECT_EQ(matrix2.get_rows(), 2);
  EXPECT_EQ(matrix2.get_cols(), 3);

  s21::FastMatrix<float> check_matrix{1, 3};
  EXPECT_EQ(check_matrix.get_rows(), 1);
  EXPECT_EQ(check_matrix.get_cols(), 3);

  matrix1(0, 0) = 14567.588;
  matrix1(0, 1) = -4542;

  matrix2(0, 0) = 14567.777;
  matrix2(0, 1) = -4542;
  matrix2(0, 2) = -2.0;
  matrix2(1, 0) = 673.545453;
  matrix2(1, 1) = 14567.588;
  matrix2(1, 2) = 3.0;

  check_matrix(0, 0) = 209158129.96435;
  check_matrix(0, 1) = -132331969.392;
  check_matrix(0, 2) = -42761.176;

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  s21::FastMatrix<float> result1 = matrix1 * matrix2;
  s21::FastMatrix<float> result2 = matrix1;
  result2 *= matrix2;

  ASSERT_TRUE(result1 == check_matrix);
  ASSERT_TRUE(result2 == check_matrix);
  ASSERT_TRUE(matrix1_before == matrix1);
  ASSERT_TRUE(matrix2_before == matrix2);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Рандомные тесты
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

using RMMRO = RandomMulMatrixRangeOne<float>;

TEST_P(RMMRO, TestMulMatrixRandom1) {
  s21::FastMatrix<float> matrix_before = test_matrix_;
  s21::FastMatrix<float> matrix_identity =
      s21_matrix_test_helper::GetIdentityMatrix<float>(test_matrix_.get_rows());

  s21::FastMatrix<float> check_matrix = test_matrix_;
  s21::FastMatrix<float> matrix1 = test_matrix_;
  s21::FastMatrix<float> matrix2 = test_matrix_;
  s21::FastMatrix<float> result1 = test_matrix_ * matrix_identity;
  s21::FastMatrix<float> result2 = matrix_identity * test_matrix_;
  matrix1.MulMatrix(matrix_identity);
  s21::FastMatrix<float> result3 = matrix2;
  result3 *= matrix_identity;

  EXPECT_TRUE(result1 == check_matrix);
  EXPECT_TRUE(result2 == check_matrix);
  EXPECT_TRUE(result3 == check_matrix);
  EXPECT_TRUE(matrix1 == check_matrix);
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
    MulMatrixSuite1, RMMRO,
    ::testing::Range(0, s21_matrix_test_helper::kRandomTestNum));
