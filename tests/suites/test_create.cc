#include <ostream>

#include "./../test.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты исключений конструкторов
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestConstructor, TestConstructorException1) {
  EXPECT_ANY_THROW(s21::FastMatrix<float>(-1, 99));
}

TEST(TestConstructor, TestConstructorException2) {
  EXPECT_ANY_THROW(s21::FastMatrix<float>(99, -1));
}

TEST(TestConstructor, TestConstructorException3) {
  EXPECT_ANY_THROW(s21::FastMatrix<float>(-1, -1));
}

TEST(TestConstructor, TestConstructorException4) {
  EXPECT_ANY_THROW(s21::FastMatrix<float>(-99, -99));
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты успешного создания объектов
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestConstructor, TestConstructorParams1) {
  s21::FastMatrix<float> matrix_check(5, 4);
  EXPECT_EQ(matrix_check.get_rows(), 5);
  EXPECT_EQ(matrix_check.get_cols(), 4);

  s21_matrix_test_helper::CheckMatrix(matrix_check, 0.0f);
}

TEST(TestConstructor, TestConstructorParams2) {
  s21::FastMatrix<float> matrix_check(999, 1999);
  EXPECT_EQ(matrix_check.get_rows(), 999);
  EXPECT_EQ(matrix_check.get_cols(), 1999);

  s21_matrix_test_helper::CheckMatrix(matrix_check, 0.0f);
}

TEST(TestConstructor, TestConstructorCopy1) {
  s21::FastMatrix<float> matrix_check = s21::FastMatrix<float>(2, 2);

  matrix_check(0, 0) = 4.0;
  matrix_check(0, 1) = 4.0;
  matrix_check(1, 0) = 4.0;
  matrix_check(1, 1) = 4.0;

  s21::FastMatrix<float> matrix_copy = matrix_check;

  EXPECT_EQ(matrix_check.get_cols(), 2);
  EXPECT_EQ(matrix_check.get_rows(), 2);

  EXPECT_EQ(matrix_copy.get_cols(), 2);
  EXPECT_EQ(matrix_copy.get_rows(), 2);

  s21_matrix_test_helper::CheckMatrix(matrix_check, 4.0f);
  s21_matrix_test_helper::CheckMatrix(matrix_copy, 4.0f);
}

TEST(TestConstructor, TestConstructorCopy2) {
  s21::FastMatrix<float> matrix_check = s21::FastMatrix<float>(2, 2);

  matrix_check(0, 0) = 4.0;
  matrix_check(0, 1) = 4.0;
  matrix_check(1, 0) = 4.0;
  matrix_check(1, 1) = 4.0;

  s21::FastMatrix<float> matrix_copy(matrix_check);

  EXPECT_EQ(matrix_check.get_cols(), 2);
  EXPECT_EQ(matrix_check.get_rows(), 2);

  EXPECT_EQ(matrix_copy.get_cols(), 2);
  EXPECT_EQ(matrix_copy.get_rows(), 2);

  s21_matrix_test_helper::CheckMatrix(matrix_check, 4.0f);
  s21_matrix_test_helper::CheckMatrix(matrix_copy, 4.0f);

  std::cout << matrix_copy << std::endl;
}

TEST(TestConstructor, TestConstructorMove1) {
  s21::FastMatrix<float> matrix_check =
      s21_matrix_test_helper::TestMoveConstructor(s21::FastMatrix<float>{5, 5});

  EXPECT_EQ(matrix_check.get_cols(), 5);
  EXPECT_EQ(matrix_check.get_rows(), 5);

  s21_matrix_test_helper::CheckMatrix(matrix_check, 0.0f);
}

TEST(TestConstructor, TestConstructorMove2) {
  s21::FastMatrix<float> matrix_test{14, 14};
  s21_matrix_test_helper::FillMatrix<float>(matrix_test, 2.0);

  s21::FastMatrix<float> matrix_check = std::move(matrix_test);

  EXPECT_EQ(matrix_check.get_cols(), 14);
  EXPECT_EQ(matrix_check.get_rows(), 14);
  EXPECT_EQ(matrix_test.get_rows(), 0);
  EXPECT_EQ(matrix_test.get_rows(), 0);

  s21_matrix_test_helper::CheckMatrix(matrix_check, 2.0f);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты операторов присваивания
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestConstructor, TestAssignmentCopy) {
  s21::FastMatrix<float> matrix_test{5, 5};
  s21::FastMatrix<float> matrix_check{2, 2};

  s21_matrix_test_helper::FillMatrix<float>(matrix_test, 2.0);
  s21_matrix_test_helper::FillMatrix<float>(matrix_check, 5.0);

  matrix_check = matrix_test;

  EXPECT_EQ(matrix_check.get_cols(), 5);
  EXPECT_EQ(matrix_check.get_rows(), 5);
  EXPECT_EQ(matrix_test.get_rows(), 5);
  EXPECT_EQ(matrix_test.get_rows(), 5);

  s21_matrix_test_helper::CheckMatrix(matrix_test, 2.0f);
  s21_matrix_test_helper::CheckMatrix(matrix_check, 2.0f);
}

TEST(TestConstructor, TestAssignmentMove1) {
  s21::FastMatrix<float> matrix_test{5, 5};
  s21::FastMatrix<float> matrix_check{2, 2};

  s21_matrix_test_helper::FillMatrix<float>(matrix_test, 2.0);
  s21_matrix_test_helper::FillMatrix<float>(matrix_check, 5.0);

  matrix_check = s21_matrix_test_helper::TestMoveConstructor(matrix_test);

  EXPECT_EQ(matrix_check.get_cols(), 5);
  EXPECT_EQ(matrix_check.get_rows(), 5);
  EXPECT_EQ(matrix_test.get_rows(), 5);
  EXPECT_EQ(matrix_test.get_rows(), 5);

  s21_matrix_test_helper::CheckMatrix(matrix_check, 2.0f);
}

TEST(TestConstructor, TestAssignmentMove2) {
  s21::FastMatrix<float> matrix_test{5, 5};
  s21::FastMatrix<float> matrix_check{2, 2};

  s21_matrix_test_helper::FillMatrix<float>(matrix_test, 2.0);
  s21_matrix_test_helper::FillMatrix<float>(matrix_check, 5.0);

  matrix_check = std::move(matrix_test);

  EXPECT_EQ(matrix_check.get_cols(), 5);
  EXPECT_EQ(matrix_check.get_rows(), 5);
  EXPECT_EQ(matrix_test.get_rows(), 2);
  EXPECT_EQ(matrix_test.get_rows(), 2);

  s21_matrix_test_helper::CheckMatrix(matrix_check, 2.0f);
}
