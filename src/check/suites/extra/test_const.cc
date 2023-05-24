#include "./../../test.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты на const матрицы
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты создания/присваивания const-матриц
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestConst, TestConstructorParamsConst) {
  const s21::FastMatrix<float> matrix_check(4, 5);
  EXPECT_EQ(matrix_check.get_rows(), 4);
  EXPECT_EQ(matrix_check.get_cols(), 5);

  s21_matrix_test_helper::CheckMatrix(matrix_check, 0.0);
}

TEST(TestConst, TestConstructorCopyConst1) {
  s21::FastMatrix<float> matrix_check = s21::FastMatrix<float>(2, 2);

  matrix_check(0, 0) = 4.0;
  matrix_check(0, 1) = 4.0;
  matrix_check(1, 0) = 4.0;
  matrix_check(1, 1) = 4.0;

  const s21::FastMatrix<float> matrix_copy = matrix_check;

  EXPECT_EQ(matrix_check.get_cols(), 2);
  EXPECT_EQ(matrix_check.get_rows(), 2);

  EXPECT_EQ(matrix_copy.get_cols(), 2);
  EXPECT_EQ(matrix_copy.get_rows(), 2);

  s21_matrix_test_helper::CheckMatrix(matrix_check, 4.0);
  s21_matrix_test_helper::CheckMatrix(matrix_copy, 4.0);
}

TEST(TestConst, TestConstructorCopyConst2) {
  s21::FastMatrix<float> matrix_check = s21::FastMatrix<float>(2, 2);

  matrix_check(0, 0) = 4.0;
  matrix_check(0, 1) = 4.0;
  matrix_check(1, 0) = 4.0;
  matrix_check(1, 1) = 4.0;

  const s21::FastMatrix<float> matrix_copy(matrix_check);

  EXPECT_EQ(matrix_check.get_cols(), 2);
  EXPECT_EQ(matrix_check.get_rows(), 2);

  EXPECT_EQ(matrix_copy.get_cols(), 2);
  EXPECT_EQ(matrix_copy.get_rows(), 2);

  s21_matrix_test_helper::CheckMatrix(matrix_check, 4.0);
  s21_matrix_test_helper::CheckMatrix(matrix_copy, 4.0);
}

TEST(TestConst, TestConstructorMoveConst1) {
  s21::FastMatrix<float> matrix_test{14, 14};
  s21_matrix_test_helper::FillMatrix(matrix_test, 2.0);

  const s21::FastMatrix<float> matrix_check = std::move(matrix_test);

  EXPECT_EQ(matrix_check.get_cols(), 14);
  EXPECT_EQ(matrix_check.get_rows(), 14);
  EXPECT_EQ(matrix_test.get_rows(), 0);
  EXPECT_EQ(matrix_test.get_rows(), 0);

  s21_matrix_test_helper::CheckMatrix(matrix_check, 2.0);
}

TEST(TestConst, TestConstructorMoveConst2) {
  s21::FastMatrix<float> matrix_test{14, 14};
  s21_matrix_test_helper::FillMatrix(matrix_test, 2.0);

  const s21::FastMatrix<float> matrix_check(std::move(matrix_test));

  EXPECT_EQ(matrix_check.get_cols(), 14);
  EXPECT_EQ(matrix_check.get_rows(), 14);
  EXPECT_EQ(matrix_test.get_rows(), 0);
  EXPECT_EQ(matrix_test.get_rows(), 0);

  s21_matrix_test_helper::CheckMatrix(matrix_check, 2.0);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты сравнения const-матриц
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestConst, TestEq1) {
  s21::FastMatrix<float> matrix1{1, 1};
  s21::FastMatrix<float> matrix2{1, 1};
  s21::FastMatrix<float> matrix3{1, 1};
  s21::FastMatrix<float> matrix4{1, 2};
  s21::FastMatrix<float> matrix5{2, 1};
  s21::FastMatrix<float> matrix6{2, 1};
  s21::FastMatrix<float> matrix7{2, 2};

  matrix1(0, 0) = -1.0;
  matrix2(0, 0) = 2.0;
  matrix3(0, 0) = 2.0;

  const s21::FastMatrix<float> matrix1_const = matrix1;
  const s21::FastMatrix<float> matrix2_const = matrix2;
  const s21::FastMatrix<float> matrix3_const = matrix3;
  const s21::FastMatrix<float> matrix4_const = matrix4;
  const s21::FastMatrix<float> matrix5_const = matrix5;
  const s21::FastMatrix<float> matrix6_const = matrix6;
  const s21::FastMatrix<float> matrix7_const = matrix7;

  EXPECT_FALSE(matrix1_const == matrix2_const);
  EXPECT_TRUE(matrix2_const == matrix3_const);
  EXPECT_FALSE(matrix3_const == matrix4_const);
  EXPECT_FALSE(matrix4_const == matrix5_const);
  EXPECT_TRUE(matrix5_const == matrix6_const);
  EXPECT_FALSE(matrix6_const == matrix7_const);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты оператора() для const-матриц
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestConst, TestOperatorBracketsConst1) {
  s21::FastMatrix<float> matrix_check{3, 3};
  EXPECT_EQ(matrix_check.get_rows(), 3);
  EXPECT_EQ(matrix_check.get_cols(), 3);

  ASSERT_NEAR(matrix_check(0, 0), 0.0, s21_matrix_test_helper::kEpsilon);
  ASSERT_NEAR(matrix_check(0, 1), 0.0, s21_matrix_test_helper::kEpsilon);
  ASSERT_NEAR(matrix_check(0, 2), 0.0, s21_matrix_test_helper::kEpsilon);
  ASSERT_NEAR(matrix_check(1, 0), 0.0, s21_matrix_test_helper::kEpsilon);
  ASSERT_NEAR(matrix_check(1, 1), 0.0, s21_matrix_test_helper::kEpsilon);
  ASSERT_NEAR(matrix_check(1, 2), 0.0, s21_matrix_test_helper::kEpsilon);
  ASSERT_NEAR(matrix_check(2, 0), 0.0, s21_matrix_test_helper::kEpsilon);
  ASSERT_NEAR(matrix_check(2, 1), 0.0, s21_matrix_test_helper::kEpsilon);
  ASSERT_NEAR(matrix_check(2, 2), 0.0, s21_matrix_test_helper::kEpsilon);

  matrix_check(0, 0) = 1.0;
  matrix_check(0, 1) = 2.0;
  matrix_check(1, 0) = 3.0;
  matrix_check(1, 1) = 4.0;

  ASSERT_NEAR(matrix_check(0, 0), 1.0, s21_matrix_test_helper::kEpsilon);
  ASSERT_NEAR(matrix_check(0, 1), 2.0, s21_matrix_test_helper::kEpsilon);
  ASSERT_NEAR(matrix_check(0, 2), 0.0, s21_matrix_test_helper::kEpsilon);
  ASSERT_NEAR(matrix_check(1, 0), 3.0, s21_matrix_test_helper::kEpsilon);
  ASSERT_NEAR(matrix_check(1, 1), 4.0, s21_matrix_test_helper::kEpsilon);
  ASSERT_NEAR(matrix_check(1, 2), 0.0, s21_matrix_test_helper::kEpsilon);
  ASSERT_NEAR(matrix_check(2, 0), 0.0, s21_matrix_test_helper::kEpsilon);
  ASSERT_NEAR(matrix_check(2, 1), 0.0, s21_matrix_test_helper::kEpsilon);
  ASSERT_NEAR(matrix_check(2, 2), 0.0, s21_matrix_test_helper::kEpsilon);

  const s21::FastMatrix<float> matrix_copy = matrix_check;

  ASSERT_NEAR(matrix_copy(0, 0), 1.0, s21_matrix_test_helper::kEpsilon);
  ASSERT_NEAR(matrix_copy(0, 1), 2.0, s21_matrix_test_helper::kEpsilon);
  ASSERT_NEAR(matrix_copy(0, 2), 0.0, s21_matrix_test_helper::kEpsilon);
  ASSERT_NEAR(matrix_copy(1, 0), 3.0, s21_matrix_test_helper::kEpsilon);
  ASSERT_NEAR(matrix_copy(1, 1), 4.0, s21_matrix_test_helper::kEpsilon);
  ASSERT_NEAR(matrix_copy(1, 2), 0.0, s21_matrix_test_helper::kEpsilon);
  ASSERT_NEAR(matrix_copy(2, 0), 0.0, s21_matrix_test_helper::kEpsilon);
  ASSERT_NEAR(matrix_copy(2, 1), 0.0, s21_matrix_test_helper::kEpsilon);
  ASSERT_NEAR(matrix_copy(2, 2), 0.0, s21_matrix_test_helper::kEpsilon);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты на сложения для const-матриц
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestConst, TestSumConst1) {
  s21::FastMatrix<float> matrix1{2, 2};
  EXPECT_EQ(matrix1.get_cols(), 2);
  EXPECT_EQ(matrix1.get_rows(), 2);

  s21::FastMatrix<float> matrix2{2, 2};
  EXPECT_EQ(matrix2.get_cols(), 2);
  EXPECT_EQ(matrix2.get_rows(), 2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  matrix2(0, 0) = 4;
  matrix2(0, 1) = 3;
  matrix2(1, 0) = 2;
  matrix2(1, 1) = 1;

  s21::FastMatrix<float> matrix2_before = matrix2;
  const s21::FastMatrix<float> matrix2_const = matrix2;

  matrix1.SumMatrix(matrix2_const);

  s21_matrix_test_helper::CheckMatrix(matrix1, 5);
  EXPECT_TRUE(matrix2_before == matrix2_const);
}

TEST(TestConst, TestSumConst2) {
  s21::FastMatrix<float> matrix1{2, 2};
  EXPECT_EQ(matrix1.get_cols(), 2);
  EXPECT_EQ(matrix1.get_rows(), 2);

  s21::FastMatrix<float> matrix2{2, 2};
  EXPECT_EQ(matrix2.get_cols(), 2);
  EXPECT_EQ(matrix2.get_rows(), 2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  matrix2(0, 0) = 4;
  matrix2(0, 1) = 3;
  matrix2(1, 0) = 2;
  matrix2(1, 1) = 1;

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;
  const s21::FastMatrix<float> matrix1_const = matrix1;
  const s21::FastMatrix<float> matrix2_const = matrix2;

  s21::FastMatrix<float> result;
  result = matrix1_const + matrix2_const;

  EXPECT_EQ(result.get_cols(), 2);
  EXPECT_EQ(result.get_rows(), 2);

  s21_matrix_test_helper::CheckMatrix(result, 5);
  EXPECT_TRUE(matrix1_before == matrix1_const);
  EXPECT_TRUE(matrix2_before == matrix2_const);
}

TEST(TestConst, TestSumConst3) {
  s21::FastMatrix<float> matrix1{2, 2};
  EXPECT_EQ(matrix1.get_cols(), 2);
  EXPECT_EQ(matrix1.get_rows(), 2);

  s21::FastMatrix<float> matrix2{2, 2};
  EXPECT_EQ(matrix2.get_cols(), 2);
  EXPECT_EQ(matrix2.get_rows(), 2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  matrix2(0, 0) = 4;
  matrix2(0, 1) = 3;
  matrix2(1, 0) = 2;
  matrix2(1, 1) = 1;

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;
  const s21::FastMatrix<float> matrix1_const = matrix1;
  const s21::FastMatrix<float> matrix2_const = matrix2;

  s21::FastMatrix<float> result{2, 2};
  result += matrix1_const;

  EXPECT_EQ(result.get_cols(), 2);
  EXPECT_EQ(result.get_rows(), 2);
  EXPECT_TRUE(result == matrix1);

  result += matrix2_const;

  EXPECT_EQ(result.get_cols(), 2);
  EXPECT_EQ(result.get_rows(), 2);
  s21_matrix_test_helper::CheckMatrix(result, 5);
  EXPECT_TRUE(matrix1_before == matrix1_const);
  EXPECT_TRUE(matrix2_before == matrix2_const);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты на вычитание для const-матриц
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestConst, TestSubConst1) {
  s21::FastMatrix<float> matrix1{2, 2};
  EXPECT_EQ(matrix1.get_cols(), 2);
  EXPECT_EQ(matrix1.get_rows(), 2);

  s21::FastMatrix<float> matrix2{2, 2};
  EXPECT_EQ(matrix2.get_cols(), 2);
  EXPECT_EQ(matrix2.get_rows(), 2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  matrix2(0, 0) = -4;
  matrix2(0, 1) = -3;
  matrix2(1, 0) = -2;
  matrix2(1, 1) = -1;

  s21::FastMatrix<float> matrix2_before = matrix2;
  const s21::FastMatrix<float> matrix2_const = matrix2;

  matrix1.SubMatrix(matrix2_const);

  s21_matrix_test_helper::CheckMatrix(matrix1, 5);
  EXPECT_TRUE(matrix2_before == matrix2_const);
}

TEST(TestConst, TestSubConst2) {
  s21::FastMatrix<float> matrix1{2, 2};
  EXPECT_EQ(matrix1.get_cols(), 2);
  EXPECT_EQ(matrix1.get_rows(), 2);

  s21::FastMatrix<float> matrix2{2, 2};
  EXPECT_EQ(matrix2.get_cols(), 2);
  EXPECT_EQ(matrix2.get_rows(), 2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  matrix2(0, 0) = -4;
  matrix2(0, 1) = -3;
  matrix2(1, 0) = -2;
  matrix2(1, 1) = -1;

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;
  const s21::FastMatrix<float> matrix1_const = matrix1;
  const s21::FastMatrix<float> matrix2_const = matrix2;

  s21::FastMatrix<float> result;
  result = matrix1_const - matrix2_const;

  EXPECT_EQ(result.get_cols(), 2);
  EXPECT_EQ(result.get_rows(), 2);

  s21_matrix_test_helper::CheckMatrix(result, 5);
  EXPECT_TRUE(matrix1_before == matrix1_const);
  EXPECT_TRUE(matrix2_before == matrix2_const);
}

TEST(TestConst, TestSubConst3) {
  s21::FastMatrix<float> matrix1{2, 2};
  EXPECT_EQ(matrix1.get_cols(), 2);
  EXPECT_EQ(matrix1.get_rows(), 2);

  s21::FastMatrix<float> matrix2{2, 2};
  EXPECT_EQ(matrix2.get_cols(), 2);
  EXPECT_EQ(matrix2.get_rows(), 2);

  matrix1(0, 0) = 2;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 2;
  matrix1(1, 1) = 2;

  matrix2(0, 0) = -4;
  matrix2(0, 1) = -4;
  matrix2(1, 0) = -4;
  matrix2(1, 1) = -4;

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;
  const s21::FastMatrix<float> matrix1_const = matrix1;
  const s21::FastMatrix<float> matrix2_const = matrix2;

  s21::FastMatrix<float> result{2, 2};
  result -= matrix1_const;

  EXPECT_EQ(result.get_cols(), 2);
  EXPECT_EQ(result.get_rows(), 2);
  s21_matrix_test_helper::CheckMatrix(result, -2);

  result -= matrix2_const;

  EXPECT_EQ(result.get_cols(), 2);
  EXPECT_EQ(result.get_rows(), 2);
  s21_matrix_test_helper::CheckMatrix(result, 2);
  EXPECT_TRUE(matrix1_before == matrix1_const);
  EXPECT_TRUE(matrix2_before == matrix2_const);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты умножения const-матриц
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestConst, TestMulMatrix1) {
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

  s21::FastMatrix<float> matrix1_const = matrix1;

  const s21::FastMatrix<float> result = matrix1_const * matrix2;

  EXPECT_EQ(result.get_rows(), 2);
  EXPECT_EQ(result.get_cols(), 2);

  ASSERT_TRUE(result == check_matrix);
}

TEST(TestConst, TestMulMatrix2) {
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

  s21::FastMatrix<float> matrix2_const = matrix2;

  const s21::FastMatrix<float> result = matrix1 * matrix2_const;

  EXPECT_EQ(result.get_rows(), 2);
  EXPECT_EQ(result.get_cols(), 2);

  ASSERT_TRUE(result == check_matrix);
}

TEST(TestConst, TestMulMatrix3) {
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

  const s21::FastMatrix<float> matrix1_const = matrix1;
  const s21::FastMatrix<float> matrix2_const = matrix2;

  s21::FastMatrix<float> result = matrix1_const * matrix2_const;

  EXPECT_EQ(result.get_rows(), 2);
  EXPECT_EQ(result.get_cols(), 2);

  ASSERT_TRUE(result == check_matrix);
}

TEST(TestConst, TestMulMatrix4) {
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

  const s21::FastMatrix<float> matrix1_const = matrix1;
  const s21::FastMatrix<float> matrix2_const = matrix2;

  const s21::FastMatrix<float> result = matrix1_const * matrix2_const;

  EXPECT_EQ(result.get_rows(), 2);
  EXPECT_EQ(result.get_cols(), 2);

  ASSERT_TRUE(result == check_matrix);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты умножения числа на const-матрицу
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestConst, TestMulNumberConst1) {
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
  const s21::FastMatrix<float> matrix1_const = matrix1;
  s21::FastMatrix<float> result1 = matrix1_const * number;
  s21::FastMatrix<float> result2 = number * matrix1_const;

  EXPECT_TRUE(result1 == check_matrix);
  EXPECT_TRUE(result2 == check_matrix);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix1_const == matrix1_before);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты транспонирования const-матрицы
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestConst, TestTransposeConst1) {
  s21::FastMatrix<float> matrix1{1, 99};
  EXPECT_EQ(matrix1.get_rows(), 1);
  EXPECT_EQ(matrix1.get_cols(), 99);

  s21::FastMatrix<float> result_check{99, 1};
  EXPECT_EQ(result_check.get_rows(), 99);
  EXPECT_EQ(result_check.get_cols(), 1);

  s21_matrix_test_helper::FillMatrix(matrix1, 1.99);
  s21_matrix_test_helper::FillMatrix(result_check, 1.99);

  s21_matrix_test_helper::CheckMatrix(matrix1, 1.99);
  s21_matrix_test_helper::CheckMatrix(result_check, 1.99);

  const s21::FastMatrix<float> const_matrix1 = matrix1;
  const s21::FastMatrix<float> const_result_check = result_check;

  s21::FastMatrix<float> result = const_matrix1.Transpose();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(result == const_result_check);
  EXPECT_TRUE(matrix1 == const_matrix1);
}

TEST(TestConst, TestTransposeConst2) {
  s21::FastMatrix<float> matrix1{2, 3};
  EXPECT_EQ(matrix1.get_rows(), 2);
  EXPECT_EQ(matrix1.get_cols(), 3);

  s21::FastMatrix<float> result_check{3, 2};
  EXPECT_EQ(result_check.get_rows(), 3);
  EXPECT_EQ(result_check.get_cols(), 2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(0, 2) = 3;
  matrix1(1, 0) = 4;
  matrix1(1, 1) = 5;
  matrix1(1, 2) = 6;

  result_check(0, 0) = 1;
  result_check(1, 0) = 2;
  result_check(2, 0) = 3;
  result_check(0, 1) = 4;
  result_check(1, 1) = 5;
  result_check(2, 1) = 6;

  const s21::FastMatrix<float> const_matrix1 = matrix1;
  const s21::FastMatrix<float> const_result_check = result_check;

  s21::FastMatrix<float> result = const_matrix1.Transpose();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(result == const_result_check);
  EXPECT_TRUE(matrix1 == const_matrix1);
}
