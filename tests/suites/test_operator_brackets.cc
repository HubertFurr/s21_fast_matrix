#include "./../test.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты исключений
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestOperatorBrackets, TestOperatorBracketsException1) {
  s21::FastMatrix<float> matrix_check{99, 99};
  EXPECT_ANY_THROW(matrix_check(100, 99));
  s21_matrix_test_helper::CheckMatrix(matrix_check, 0.0f);
}

TEST(TestOperatorBrackets, TestOperatorBracketsException2) {
  s21::FastMatrix<float> matrix_check{99, 99};
  EXPECT_ANY_THROW(matrix_check(99, 100));
  s21_matrix_test_helper::CheckMatrix(matrix_check, 0.0f);
}

TEST(TestOperatorBrackets, TestOperatorBracketsException3) {
  s21::FastMatrix<float> matrix_check{99, 99};
  EXPECT_ANY_THROW(matrix_check(100, 100));
  s21_matrix_test_helper::CheckMatrix(matrix_check, 0.0f);
}

TEST(TestOperatorBrackets, TestOperatorBracketsException4) {
  s21::FastMatrix<float> matrix_check{5, 5};
  s21_matrix_test_helper::FillMatrix(matrix_check, 2.0f);
  EXPECT_ANY_THROW(matrix_check(6, 5));
  s21_matrix_test_helper::CheckMatrix(matrix_check, 2.0f);
}

TEST(TestOperatorBrackets, TestOperatorBracketsException5) {
  s21::FastMatrix<float> matrix_check{5, 5};
  s21_matrix_test_helper::FillMatrix(matrix_check, 2.0f);
  EXPECT_ANY_THROW(matrix_check(5, 6));
  s21_matrix_test_helper::CheckMatrix(matrix_check, 2.0f);
}

TEST(TestOperatorBrackets, TestOperatorBracketsException6) {
  s21::FastMatrix<float> matrix_check{5, 5};
  s21_matrix_test_helper::FillMatrix(matrix_check, 2.0f);
  EXPECT_ANY_THROW(matrix_check(999, 999));
  s21_matrix_test_helper::CheckMatrix(matrix_check, 2.0f);
}

TEST(TestOperatorBrackets, TestOperatorBracketsException7) {
  s21::FastMatrix<float> matrix_check{5, 5};
  s21_matrix_test_helper::FillMatrix(matrix_check, 2.0f);
  EXPECT_ANY_THROW(matrix_check(-1, 0));
  s21_matrix_test_helper::CheckMatrix(matrix_check, 2.0f);
}

TEST(TestOperatorBrackets, TestOperatorBracketsException8) {
  s21::FastMatrix<float> matrix_check{5, 5};
  s21_matrix_test_helper::FillMatrix(matrix_check, 2.0f);
  EXPECT_ANY_THROW(matrix_check(0, -1));
  s21_matrix_test_helper::CheckMatrix(matrix_check, 2.0f);
}

TEST(TestOperatorBrackets, TestOperatorBracketsException9) {
  s21::FastMatrix<float> matrix_check{5, 5};
  s21_matrix_test_helper::FillMatrix(matrix_check, 2.0f);
  EXPECT_ANY_THROW(matrix_check(-1, -1));
  s21_matrix_test_helper::CheckMatrix(matrix_check, 2.0f);
}

TEST(TestOperatorBrackets, TestOperatorBracketsException10) {
  s21::FastMatrix<float> matrix_check{5, 5};
  s21_matrix_test_helper::FillMatrix(matrix_check, 2.0f);
  EXPECT_ANY_THROW(matrix_check(-99, -99));
  s21_matrix_test_helper::CheckMatrix(matrix_check, 2.0f);
}

TEST(TestOperatorBrackets, TestOperatorBracketsException11) {
  s21::FastMatrix<float> matrix_check{5, 5};
  s21_matrix_test_helper::FillMatrix(matrix_check, 2.0f);
  EXPECT_ANY_THROW(matrix_check(5, 4));
  s21_matrix_test_helper::CheckMatrix(matrix_check, 2.0f);
}

TEST(TestOperatorBrackets, TestOperatorBracketsException12) {
  s21::FastMatrix<float> matrix_check{5, 5};
  s21_matrix_test_helper::FillMatrix(matrix_check, 2.0f);
  EXPECT_ANY_THROW(matrix_check(4, 5));
  s21_matrix_test_helper::CheckMatrix(matrix_check, 2.0f);
}

TEST(TestOperatorBrackets, TestOperatorBracketsException13) {
  s21::FastMatrix<float> matrix_check{5, 5};
  s21_matrix_test_helper::FillMatrix(matrix_check, 2.0f);
  EXPECT_NO_THROW(matrix_check(4, 4));
  s21_matrix_test_helper::CheckMatrix(matrix_check, 2.0f);
}

TEST(TestOperatorBrackets, TestOperatorBracketsException14) {
  s21::FastMatrix<float> matrix_check{2, 3};
  s21_matrix_test_helper::FillMatrix(matrix_check, 2.0f);
  EXPECT_NO_THROW(matrix_check(1, 2));
  EXPECT_ANY_THROW(matrix_check(2, 2));
  EXPECT_ANY_THROW(matrix_check(1, 3));
  s21_matrix_test_helper::CheckMatrix(matrix_check, 2.0f);
}

TEST(TestOperatorBrackets, TestOperatorBracketsException15) {
  s21::FastMatrix<float> matrix_check{3, 2};
  s21_matrix_test_helper::FillMatrix(matrix_check, 2.0f);
  EXPECT_NO_THROW(matrix_check(2, 1));
  EXPECT_ANY_THROW(matrix_check(3, 1));
  EXPECT_ANY_THROW(matrix_check(2, 2));
  s21_matrix_test_helper::CheckMatrix(matrix_check, 2.0f);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты успешного доступа к полям
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestOperatorBrackets, TestOperatorBrackets1) {
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
}
