#include <utility>

#include "./../../test.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты для default-матриц (0x0)
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты создания default-матриц
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestDefault, TestConstructorBasicConst1) {
  const s21::FastMatrix<float> matrix_check;
  EXPECT_EQ(matrix_check.get_rows(), 0);
  EXPECT_EQ(matrix_check.get_cols(), 0);

  s21_matrix_test_helper::CheckMatrix(matrix_check, 0.0f);

  s21::FastMatrix<float> matrix_copy{matrix_check};

  EXPECT_EQ(matrix_copy.get_rows(), 0);
  EXPECT_EQ(matrix_copy.get_cols(), 0);
  s21_matrix_test_helper::CheckMatrix(matrix_copy, 0.0f);

  // Интересный факт - в данном случае используется конструктор копирования
  s21::FastMatrix<float> matrix_move{std::move(matrix_check)};
  EXPECT_EQ(matrix_move.get_rows(), 0);
  EXPECT_EQ(matrix_move.get_cols(), 0);
  s21_matrix_test_helper::CheckMatrix(matrix_move, 0.0f);
}

TEST(TestDefault, TestConstructorBasic1) {
  s21::FastMatrix<float> matrix_check;
  EXPECT_EQ(matrix_check.get_rows(), 0);
  EXPECT_EQ(matrix_check.get_cols(), 0);

  s21_matrix_test_helper::CheckMatrix(matrix_check, 0.0f);

  s21::FastMatrix<float> matrix_copy{matrix_check};

  EXPECT_EQ(matrix_copy.get_rows(), 0);
  EXPECT_EQ(matrix_copy.get_cols(), 0);
  s21_matrix_test_helper::CheckMatrix(matrix_copy, 0.0f);

  s21::FastMatrix<float> matrix_move{std::move(matrix_check)};
  EXPECT_EQ(matrix_move.get_rows(), 0);
  EXPECT_EQ(matrix_move.get_cols(), 0);
  s21_matrix_test_helper::CheckMatrix(matrix_move, 0.0f);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты присваивания default-матриц
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestDefault, TestAssignmentCopy1) {
  s21::FastMatrix<float> matrix_test{5, 5};
  s21::FastMatrix<float> matrix_check;

  EXPECT_EQ(matrix_test.get_rows(), 5);
  EXPECT_EQ(matrix_test.get_cols(), 5);
  EXPECT_EQ(matrix_check.get_rows(), 0);
  EXPECT_EQ(matrix_check.get_cols(), 0);

  s21_matrix_test_helper::CheckMatrix(matrix_test, 0.0f);
  s21_matrix_test_helper::CheckMatrix(matrix_check, 0.0f);

  matrix_test = matrix_check;

  EXPECT_EQ(matrix_test.get_rows(), 0);
  EXPECT_EQ(matrix_test.get_cols(), 0);
  EXPECT_EQ(matrix_check.get_rows(), 0);
  EXPECT_EQ(matrix_check.get_cols(), 0);

  s21_matrix_test_helper::CheckMatrix(matrix_test, 0.0f);
  s21_matrix_test_helper::CheckMatrix(matrix_check, 0.0f);
}

TEST(TestDefault, TestAssignmentMove1) {
  s21::FastMatrix<float> matrix_test{5, 5};
  s21::FastMatrix<float> matrix_check;

  EXPECT_EQ(matrix_test.get_rows(), 5);
  EXPECT_EQ(matrix_test.get_cols(), 5);
  EXPECT_EQ(matrix_check.get_rows(), 0);
  EXPECT_EQ(matrix_check.get_cols(), 0);

  s21_matrix_test_helper::CheckMatrix(matrix_test, 0.0f);
  s21_matrix_test_helper::CheckMatrix(matrix_check, 0.0f);

  matrix_test = std::move(matrix_check);

  EXPECT_EQ(matrix_test.get_rows(), 0);
  EXPECT_EQ(matrix_test.get_cols(), 0);

  s21_matrix_test_helper::CheckMatrix(matrix_test, 0.0f);
  s21_matrix_test_helper::CheckMatrix(matrix_check, 0.0f);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты равенства default-матриц
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestDefault, TestEq1) {
  s21::FastMatrix<float> matrix1;
  s21::FastMatrix<float> matrix2;

  EXPECT_TRUE(matrix1 == matrix2);
}

TEST(TestDefault, TestEq2) {
  s21::FastMatrix<float> matrix1;
  s21::FastMatrix<float> matrix2{1, 1};

  EXPECT_FALSE(matrix1 == matrix2);
}

TEST(TestDefault, TestEq3) {
  s21::FastMatrix<float> matrix1{1, 1};
  s21::FastMatrix<float> matrix2;

  EXPECT_FALSE(matrix1 == matrix2);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты сложения default-матриц
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestDefault, TestSum1) {
  s21::FastMatrix<float> matrix1;
  s21::FastMatrix<float> matrix2;

  s21::FastMatrix<float> result = matrix2 + matrix1;
  EXPECT_EQ(result.get_rows(), 0);
  EXPECT_EQ(result.get_cols(), 0);
  EXPECT_TRUE(result == s21::FastMatrix<float>(0, 0));

  matrix1 += matrix2;
  EXPECT_EQ(result.get_rows(), 0);
  EXPECT_EQ(result.get_cols(), 0);
  EXPECT_TRUE(matrix1 == s21::FastMatrix<float>(0, 0));
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты вычитания default-матриц
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestDefault, TestSub1) {
  s21::FastMatrix<float> matrix1;
  s21::FastMatrix<float> matrix2;

  s21::FastMatrix<float> result = matrix2 - matrix1;
  EXPECT_EQ(result.get_rows(), 0);
  EXPECT_EQ(result.get_cols(), 0);
  EXPECT_TRUE(result == s21::FastMatrix<float>(0, 0));

  matrix1 -= matrix2;
  EXPECT_EQ(result.get_rows(), 0);
  EXPECT_EQ(result.get_cols(), 0);
  EXPECT_TRUE(matrix1 == s21::FastMatrix<float>(0, 0));
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты умножения default-матриц
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestDefault, TestMulMatrix1) {
  s21::FastMatrix<float> matrix1;
  s21::FastMatrix<float> matrix2;
  s21::FastMatrix<float> check;

  EXPECT_EQ(matrix1.get_rows(), 0);
  EXPECT_EQ(matrix1.get_cols(), 0);
  EXPECT_EQ(matrix2.get_rows(), 0);
  EXPECT_EQ(matrix2.get_cols(), 0);

  s21::FastMatrix<float> result = matrix1 * matrix2;

  EXPECT_EQ(result.get_rows(), 0);
  EXPECT_EQ(result.get_cols(), 0);
  EXPECT_TRUE(result == check);

  matrix1 *= matrix2;

  EXPECT_EQ(matrix1.get_rows(), 0);
  EXPECT_EQ(matrix1.get_cols(), 0);
  EXPECT_TRUE(matrix1 == check);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты умножения default-матриц на число
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestDefault, TestMulNumber1) {
  s21::FastMatrix<float> matrix1;
  s21::FastMatrix<float> matrix2;
  s21::FastMatrix<float> check;

  EXPECT_EQ(matrix1.get_rows(), 0);
  EXPECT_EQ(matrix1.get_cols(), 0);
  EXPECT_EQ(matrix2.get_rows(), 0);
  EXPECT_EQ(matrix2.get_cols(), 0);

  s21::FastMatrix<float> result1 = matrix1 * 2.0;

  EXPECT_EQ(result1.get_rows(), 0);
  EXPECT_EQ(result1.get_cols(), 0);
  EXPECT_TRUE(result1 == check);

  s21::FastMatrix<float> result2 = 2.0 * matrix1;

  EXPECT_EQ(result2.get_rows(), 0);
  EXPECT_EQ(result2.get_cols(), 0);
  EXPECT_TRUE(result2 == check);

  matrix2 *= 2.0;

  EXPECT_EQ(matrix2.get_rows(), 0);
  EXPECT_EQ(matrix2.get_cols(), 0);
  EXPECT_TRUE(matrix2 == check);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты транспонирования default-матриц
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestDefault, TestTranspose1) {
  s21::FastMatrix<float> matrix;
  s21::FastMatrix<float> result = matrix.Transpose();
  EXPECT_EQ(result.get_rows(), 0);
  EXPECT_EQ(result.get_cols(), 0);
  EXPECT_TRUE(result == s21::FastMatrix<float>(0, 0));
}
