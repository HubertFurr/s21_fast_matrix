#include <utility>

#include "./../../test.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты для пустых матриц (m×0 и 0×n)
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты конструкторов/присваиваний
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestConstructor, TestConstructor1) {
  s21::FastMatrix<float> matrix(0, 3);

  EXPECT_EQ(matrix.get_rows(), 0);
  EXPECT_EQ(matrix.get_cols(), 3);

  s21::FastMatrix<float> matrix_copy = matrix;
  EXPECT_EQ(matrix_copy.get_rows(), 0);
  EXPECT_EQ(matrix_copy.get_cols(), 3);
  EXPECT_TRUE(matrix_copy == matrix);

  s21::FastMatrix<float> matrix1(3, 3);
  matrix1 = matrix;
  EXPECT_EQ(matrix1.get_rows(), 0);
  EXPECT_EQ(matrix1.get_cols(), 3);
  EXPECT_TRUE(matrix1 == matrix);

  s21::FastMatrix<float> matrix_move = std::move(matrix);
  EXPECT_EQ(matrix_move.get_rows(), 0);
  EXPECT_EQ(matrix_move.get_cols(), 3);
  EXPECT_TRUE(matrix_move == matrix_copy);

  s21::FastMatrix<float> matrix2(3, 3);
  matrix2 = std::move(matrix_copy);
  EXPECT_EQ(matrix2.get_rows(), 0);
  EXPECT_EQ(matrix2.get_cols(), 3);
  EXPECT_TRUE(matrix2 == matrix_move);
}

TEST(TestConstructor, TestConstructor2) {
  s21::FastMatrix<float> matrix(3, 0);

  EXPECT_EQ(matrix.get_rows(), 3);
  EXPECT_EQ(matrix.get_cols(), 0);

  s21::FastMatrix<float> matrix_copy = matrix;
  EXPECT_EQ(matrix_copy.get_rows(), 3);
  EXPECT_EQ(matrix_copy.get_cols(), 0);
  EXPECT_TRUE(matrix_copy == matrix);

  s21::FastMatrix<float> matrix1(3, 3);
  matrix1 = matrix;
  EXPECT_EQ(matrix1.get_rows(), 3);
  EXPECT_EQ(matrix1.get_cols(), 0);
  EXPECT_TRUE(matrix1 == matrix);

  s21::FastMatrix<float> matrix_move = std::move(matrix);
  EXPECT_EQ(matrix_move.get_rows(), 3);
  EXPECT_EQ(matrix_move.get_cols(), 0);
  EXPECT_TRUE(matrix_move == matrix_copy);

  s21::FastMatrix<float> matrix2(3, 3);
  matrix2 = std::move(matrix_copy);
  EXPECT_EQ(matrix2.get_rows(), 3);
  EXPECT_EQ(matrix2.get_cols(), 0);
  EXPECT_TRUE(matrix2 == matrix_move);
}

TEST(TestConstructor, TestConstructor3) {
  s21::FastMatrix<float> matrix(0, 0);

  EXPECT_EQ(matrix.get_rows(), 0);
  EXPECT_EQ(matrix.get_cols(), 0);

  s21::FastMatrix<float> matrix_copy = matrix;
  EXPECT_EQ(matrix_copy.get_rows(), 0);
  EXPECT_EQ(matrix_copy.get_cols(), 0);
  EXPECT_TRUE(matrix_copy == matrix);

  s21::FastMatrix<float> matrix1(3, 3);
  matrix1 = matrix;
  EXPECT_EQ(matrix1.get_rows(), 0);
  EXPECT_EQ(matrix1.get_cols(), 0);
  EXPECT_TRUE(matrix1 == matrix);

  s21::FastMatrix<float> matrix_move = std::move(matrix);
  EXPECT_EQ(matrix_move.get_rows(), 0);
  EXPECT_EQ(matrix_move.get_cols(), 0);
  EXPECT_TRUE(matrix_move == matrix_copy);

  s21::FastMatrix<float> matrix2(3, 3);
  matrix2 = std::move(matrix_copy);
  EXPECT_EQ(matrix2.get_rows(), 0);
  EXPECT_EQ(matrix2.get_cols(), 0);
  EXPECT_TRUE(matrix2 == matrix_move);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты равенства
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestEmpty, TestEq1) {
  EXPECT_TRUE(s21::FastMatrix<float>(3, 0) == s21::FastMatrix<float>(3, 0));
  EXPECT_TRUE(s21::FastMatrix<float>(1, 0) == s21::FastMatrix<float>(1, 0));
  EXPECT_TRUE(s21::FastMatrix<float>(0, 1) == s21::FastMatrix<float>(0, 1));
  EXPECT_TRUE(s21::FastMatrix<float>(0, 3) == s21::FastMatrix<float>(0, 3));
  EXPECT_FALSE(s21::FastMatrix<float>(0, 3) == s21::FastMatrix<float>(3, 0));
  EXPECT_FALSE(s21::FastMatrix<float>(1, 0) == s21::FastMatrix<float>(0, 1));
  EXPECT_FALSE(s21::FastMatrix<float>(0, 3) == s21::FastMatrix<float>(0, 2));
  EXPECT_FALSE(s21::FastMatrix<float>(2, 0) == s21::FastMatrix<float>(1, 0));
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты сложения
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestEmpty, TestSum1) {
  s21::FastMatrix<float> matrix1(3, 0);
  s21::FastMatrix<float> matrix2(3, 0);
  s21::FastMatrix<float> matrix1_copy = matrix1;
  s21::FastMatrix<float> matrix2_copy = matrix2;

  s21::FastMatrix<float> result1 = matrix1 + matrix2;
  EXPECT_TRUE(result1 == s21::FastMatrix<float>(3, 0));

  s21::FastMatrix<float> result2 = matrix2 + matrix1;
  EXPECT_TRUE(result2 == s21::FastMatrix<float>(3, 0));

  matrix1_copy += matrix2_copy;
  EXPECT_TRUE(matrix1_copy == s21::FastMatrix<float>(3, 0));

  matrix2_copy += matrix1;
  EXPECT_TRUE(matrix2_copy == s21::FastMatrix<float>(3, 0));
}

TEST(TestEmpty, TestSum2) {
  s21::FastMatrix<float> matrix1(0, 3);
  s21::FastMatrix<float> matrix2(0, 3);
  s21::FastMatrix<float> matrix1_copy = matrix1;
  s21::FastMatrix<float> matrix2_copy = matrix2;

  s21::FastMatrix<float> result1 = matrix1 + matrix2;
  EXPECT_TRUE(result1 == s21::FastMatrix<float>(0, 3));

  s21::FastMatrix<float> result2 = matrix2 + matrix1;
  EXPECT_TRUE(result2 == s21::FastMatrix<float>(0, 3));

  matrix1_copy += matrix2_copy;
  EXPECT_TRUE(matrix1_copy == s21::FastMatrix<float>(0, 3));

  matrix2_copy += matrix1;
  EXPECT_TRUE(matrix2_copy == s21::FastMatrix<float>(0, 3));
}

TEST(TestEmpty, TestSum3) {
  s21::FastMatrix<float> matrix1(0, 2);
  s21::FastMatrix<float> matrix2(3, 0);

  EXPECT_ANY_THROW(matrix1 + matrix2);
  EXPECT_ANY_THROW(matrix1 += matrix2);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты вычитания
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestEmpty, TestSub1) {
  s21::FastMatrix<float> matrix1(3, 0);
  s21::FastMatrix<float> matrix2(3, 0);
  s21::FastMatrix<float> matrix1_copy = matrix1;
  s21::FastMatrix<float> matrix2_copy = matrix2;

  s21::FastMatrix<float> result1 = matrix1 - matrix2;
  EXPECT_TRUE(result1 == s21::FastMatrix<float>(3, 0));

  s21::FastMatrix<float> result2 = matrix2 - matrix1;
  EXPECT_TRUE(result2 == s21::FastMatrix<float>(3, 0));

  matrix1_copy -= matrix2_copy;
  EXPECT_TRUE(matrix1_copy == s21::FastMatrix<float>(3, 0));

  matrix2_copy -= matrix1;
  EXPECT_TRUE(matrix2_copy == s21::FastMatrix<float>(3, 0));
}

TEST(TestEmpty, TestSub2) {
  s21::FastMatrix<float> matrix1(0, 3);
  s21::FastMatrix<float> matrix2(0, 3);
  s21::FastMatrix<float> matrix1_copy = matrix1;
  s21::FastMatrix<float> matrix2_copy = matrix2;

  s21::FastMatrix<float> result1 = matrix1 - matrix2;
  EXPECT_TRUE(result1 == s21::FastMatrix<float>(0, 3));

  s21::FastMatrix<float> result2 = matrix2 - matrix1;
  EXPECT_TRUE(result2 == s21::FastMatrix<float>(0, 3));

  matrix1_copy -= matrix2_copy;
  EXPECT_TRUE(matrix1_copy == s21::FastMatrix<float>(0, 3));

  matrix2_copy -= matrix1;
  EXPECT_TRUE(matrix2_copy == s21::FastMatrix<float>(0, 3));
}

TEST(TestEmpty, TestSub3) {
  s21::FastMatrix<float> matrix1(0, 2);
  s21::FastMatrix<float> matrix2(3, 0);

  EXPECT_ANY_THROW(matrix1 - matrix2);
  EXPECT_ANY_THROW(matrix1 -= matrix2);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты умножения
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestEmpty, TestMulMatrix1) {
  s21::FastMatrix<float> matrix1(3, 0);
  s21::FastMatrix<float> matrix2(0, 3);
  s21::FastMatrix<float> matrix1_copy = matrix1;
  s21::FastMatrix<float> matrix2_copy = matrix2;

  s21::FastMatrix<float> result1 = matrix1 * matrix2;
  EXPECT_TRUE(result1 == s21::FastMatrix<float>(3, 3));

  s21::FastMatrix<float> result2 = matrix2 * matrix1;
  EXPECT_TRUE(result2 == s21::FastMatrix<float>(0, 0));

  matrix1_copy *= matrix2_copy;
  EXPECT_TRUE(matrix1_copy == s21::FastMatrix<float>(3, 3));

  matrix2_copy *= matrix1;
  EXPECT_TRUE(matrix2_copy == s21::FastMatrix<float>(0, 0));
}

TEST(TestEmpty, TestMulMatrix2) {
  s21::FastMatrix<float> matrix1(0, 2);
  s21::FastMatrix<float> matrix2(3, 0);

  EXPECT_ANY_THROW(matrix1 * matrix2);
  EXPECT_ANY_THROW(matrix1 *= matrix2);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты умножения на число
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestEmpty, TestMulNumber1) {
  s21::FastMatrix<float> matrix1(1, 0);
  s21::FastMatrix<float> matrix2(1, 0);
  s21::FastMatrix<float> check(1, 0);

  s21::FastMatrix<float> result1 = matrix1 * 2.0;
  EXPECT_TRUE(result1 == check);

  s21::FastMatrix<float> result2 = 2.0 * matrix1;
  EXPECT_TRUE(result2 == check);

  matrix2 *= 2.0;
  EXPECT_TRUE(matrix2 == check);
}

TEST(TestEmpty, TestMulNumber2) {
  s21::FastMatrix<float> matrix1(0, 1);
  s21::FastMatrix<float> matrix2(0, 1);
  s21::FastMatrix<float> check(0, 1);

  s21::FastMatrix<float> result1 = matrix1 * 2.0;
  EXPECT_TRUE(result1 == check);

  s21::FastMatrix<float> result2 = 2.0 * matrix1;
  EXPECT_TRUE(result2 == check);

  matrix2 *= 2.0;
  EXPECT_TRUE(matrix2 == check);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты транспонирования
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestEmpty, TestTranspose1) {
  s21::FastMatrix<float> matrix(1, 0);
  s21::FastMatrix<float> result = matrix.Transpose();
  EXPECT_EQ(result.get_rows(), 0);
  EXPECT_EQ(result.get_cols(), 1);
  EXPECT_TRUE(result == s21::FastMatrix<float>(0, 1));
}

TEST(TestEmpty, TestTranspose2) {
  s21::FastMatrix<float> matrix(0, 1);
  s21::FastMatrix<float> result = matrix.Transpose();
  EXPECT_EQ(result.get_rows(), 1);
  EXPECT_EQ(result.get_cols(), 0);
  EXPECT_TRUE(result == s21::FastMatrix<float>(1, 0));
}
