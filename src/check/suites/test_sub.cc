#include "./../test.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты исключений функции вычитания
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestSub, TestSubFunctionException1) {
  s21::FastMatrix<float> matrix1{2, 2};
  s21::FastMatrix<float> matrix2{2, 3};

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1.SubMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2.SubMatrix(matrix1));
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSub, TestSubFunctionException2) {
  s21::FastMatrix<float> matrix1{2, 2};
  s21::FastMatrix<float> matrix2{3, 2};

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1.SubMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2.SubMatrix(matrix1));
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSub, TestSubFunctionException3) {
  s21::FastMatrix<float> matrix1{3, 2};
  s21::FastMatrix<float> matrix2{2, 2};

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1.SubMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2.SubMatrix(matrix1));
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSub, TestSubFunctionException4) {
  s21::FastMatrix<float> matrix1{2, 3};
  s21::FastMatrix<float> matrix2{2, 2};

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1.SubMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2.SubMatrix(matrix1));
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSub, TestSubFunctionException5) {
  s21::FastMatrix<float> matrix1{2, 2};
  s21::FastMatrix<float> matrix2{2, 3};

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0);

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1.SubMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2.SubMatrix(matrix1));
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSub, TestSubFunctionException6) {
  s21::FastMatrix<float> matrix1{2, 2};
  s21::FastMatrix<float> matrix2{3, 2};

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0);

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1.SubMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2.SubMatrix(matrix1));
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSub, TestSubFunctionException7) {
  s21::FastMatrix<float> matrix1{3, 2};
  s21::FastMatrix<float> matrix2{2, 2};

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0);

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1.SubMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2.SubMatrix(matrix1));
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSub, TestSubFunctionException8) {
  s21::FastMatrix<float> matrix1{2, 3};
  s21::FastMatrix<float> matrix2{2, 2};

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0);

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1.SubMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2.SubMatrix(matrix1));
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты исключений операций вычитания
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestSub, TestSubOperatorException1) {
  s21::FastMatrix<float> matrix1{2, 2};
  s21::FastMatrix<float> matrix2{2, 3};

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 - matrix2);
  EXPECT_ANY_THROW(matrix2 - matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSub, TestSubOperatorException2) {
  s21::FastMatrix<float> matrix1{2, 2};
  s21::FastMatrix<float> matrix2{3, 2};

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 - matrix2);
  EXPECT_ANY_THROW(matrix2 - matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSub, TestSubOperatorException3) {
  s21::FastMatrix<float> matrix1{3, 2};
  s21::FastMatrix<float> matrix2{2, 2};

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 - matrix2);
  EXPECT_ANY_THROW(matrix2 - matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSub, TestSubOperatorException4) {
  s21::FastMatrix<float> matrix1{2, 3};
  s21::FastMatrix<float> matrix2{2, 2};

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 - matrix2);
  EXPECT_ANY_THROW(matrix2 - matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSub, TestSubOperatorException5) {
  s21::FastMatrix<float> matrix1{2, 2};
  s21::FastMatrix<float> matrix2{2, 3};

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0);

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 - matrix2);
  EXPECT_ANY_THROW(matrix2 - matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSub, TestSubOperatorException6) {
  s21::FastMatrix<float> matrix1{2, 2};
  s21::FastMatrix<float> matrix2{3, 2};

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0);

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 - matrix2);
  EXPECT_ANY_THROW(matrix2 - matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSub, TestSubOperatorException7) {
  s21::FastMatrix<float> matrix1{3, 2};
  s21::FastMatrix<float> matrix2{2, 2};

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0);

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 - matrix2);
  EXPECT_ANY_THROW(matrix2 - matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSub, TestSubOperatorException8) {
  s21::FastMatrix<float> matrix1{2, 3};
  s21::FastMatrix<float> matrix2{2, 2};

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0);

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 - matrix2);
  EXPECT_ANY_THROW(matrix2 - matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSub, TestSubOperatorException9) {
  s21::FastMatrix<float> matrix1{2, 2};
  s21::FastMatrix<float> matrix2{2, 3};

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 -= matrix2);
  EXPECT_ANY_THROW(matrix2 -= matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSub, TestSubOperatorException10) {
  s21::FastMatrix<float> matrix1{2, 2};
  s21::FastMatrix<float> matrix2{3, 2};

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 -= matrix2);
  EXPECT_ANY_THROW(matrix2 -= matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSub, TestSubOperatorException11) {
  s21::FastMatrix<float> matrix1{3, 2};
  s21::FastMatrix<float> matrix2{2, 2};

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 -= matrix2);
  EXPECT_ANY_THROW(matrix2 -= matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSub, TestSubOperatorException12) {
  s21::FastMatrix<float> matrix1{2, 3};
  s21::FastMatrix<float> matrix2{2, 2};

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 -= matrix2);
  EXPECT_ANY_THROW(matrix2 -= matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSub, TestSubOperatorException13) {
  s21::FastMatrix<float> matrix1{2, 2};
  s21::FastMatrix<float> matrix2{2, 3};

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0);

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 -= matrix2);
  EXPECT_ANY_THROW(matrix2 -= matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSub, TestSubOperatorException14) {
  s21::FastMatrix<float> matrix1{2, 2};
  s21::FastMatrix<float> matrix2{3, 2};

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0);

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 -= matrix2);
  EXPECT_ANY_THROW(matrix2 -= matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSub, TestSubOperatorException15) {
  s21::FastMatrix<float> matrix1{3, 2};
  s21::FastMatrix<float> matrix2{2, 2};

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0);

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 -= matrix2);
  EXPECT_ANY_THROW(matrix2 -= matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSub, TestSubOperatorException16) {
  s21::FastMatrix<float> matrix1{2, 3};
  s21::FastMatrix<float> matrix2{2, 2};

  s21_matrix_test_helper::FillMatrix(matrix1, 1.0);
  s21_matrix_test_helper::FillMatrix(matrix2, 2.0);

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 -= matrix2);
  EXPECT_ANY_THROW(matrix2 -= matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты успешного суммирования функцией
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestSub, TestSub1) {
  s21::FastMatrix<float> matrix1{95, 99};
  EXPECT_EQ(matrix1.get_rows(), 95);
  EXPECT_EQ(matrix1.get_cols(), 99);

  s21::FastMatrix<float> matrix2{95, 99};
  EXPECT_EQ(matrix2.get_rows(), 95);
  EXPECT_EQ(matrix2.get_cols(), 99);

  s21_matrix_test_helper::FillMatrix(matrix1, 2.5);
  s21_matrix_test_helper::FillMatrix(matrix2, 3.5);

  matrix1.SubMatrix(matrix2);

  s21_matrix_test_helper::CheckMatrix(matrix1, -1.0);

  matrix2.SubMatrix(matrix1);

  s21_matrix_test_helper::CheckMatrix(matrix2, 4.5);
}

TEST(TestSub, TestSub2) {
  s21::FastMatrix<float> matrix1{99, 99};
  EXPECT_EQ(matrix1.get_rows(), 99);
  EXPECT_EQ(matrix1.get_cols(), 99);

  s21::FastMatrix<float> matrix2{99, 99};
  EXPECT_EQ(matrix2.get_rows(), 99);
  EXPECT_EQ(matrix2.get_cols(), 99);

  s21_matrix_test_helper::FillMatrix(matrix1, 2.5);
  s21_matrix_test_helper::FillMatrix(matrix2, 3.5);

  matrix1.SubMatrix(matrix2);

  s21_matrix_test_helper::CheckMatrix(matrix1, -1.0);

  matrix2.SubMatrix(matrix1);

  s21_matrix_test_helper::CheckMatrix(matrix2, 4.5);
}

TEST(TestSub, TestSub3) {
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
  check_matrix(0, 1) = 1.5;
  check_matrix(0, 2) = 1.5;
  check_matrix(1, 0) = -4.5;
  check_matrix(1, 1) = -2.5;
  check_matrix(1, 2) = -7.5;
  check_matrix(2, 0) = 1.0;
  check_matrix(2, 1) = 2.0;
  check_matrix(2, 2) = 0.0;
  check_matrix(3, 0) = 4.0;
  check_matrix(3, 1) = 1.0;
  check_matrix(3, 2) = -3.0;

  matrix1.SubMatrix(matrix2);

  EXPECT_TRUE(matrix1 == check_matrix);
}

TEST(TestSub, TestSub4) {
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

  check_matrix(0, 0) = 131110199.811;
  check_matrix(0, 1) = 0.0;
  check_matrix(1, 0) = 673549.54545324;
  check_matrix(1, 1) = 145678000.588;

  matrix1.SubMatrix(matrix2);

  EXPECT_TRUE(matrix1 == check_matrix);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты успешного суммирования операторами
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TEST(TestSub, TestSubOperation1) {
  s21::FastMatrix<float> matrix1{95, 99};
  EXPECT_EQ(matrix1.get_rows(), 95);
  EXPECT_EQ(matrix1.get_cols(), 99);

  s21::FastMatrix<float> matrix2{95, 99};
  EXPECT_EQ(matrix2.get_rows(), 95);
  EXPECT_EQ(matrix2.get_cols(), 99);

  s21_matrix_test_helper::FillMatrix(matrix1, 2.5);
  s21_matrix_test_helper::FillMatrix(matrix2, 3.5);

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;
  s21::FastMatrix<float> result = matrix1 - matrix2;

  EXPECT_EQ(result.get_rows(), 95);
  EXPECT_EQ(result.get_cols(), 99);
  s21_matrix_test_helper::CheckMatrix(result, -1.0);
  EXPECT_TRUE(matrix1_before == matrix1);
  EXPECT_TRUE(matrix2_before == matrix2);
}

TEST(TestSub, TestSubOperation2) {
  s21::FastMatrix<float> matrix1{99, 99};
  EXPECT_EQ(matrix1.get_rows(), 99);
  EXPECT_EQ(matrix1.get_cols(), 99);

  s21::FastMatrix<float> matrix2{99, 99};
  EXPECT_EQ(matrix2.get_rows(), 99);
  EXPECT_EQ(matrix2.get_cols(), 99);

  s21_matrix_test_helper::FillMatrix(matrix1, 2.5);
  s21_matrix_test_helper::FillMatrix(matrix2, 4.5);

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;
  s21::FastMatrix<float> result = matrix1 - matrix2;

  EXPECT_EQ(result.get_rows(), 99);
  EXPECT_EQ(result.get_cols(), 99);
  s21_matrix_test_helper::CheckMatrix(result, -2.0);
  EXPECT_TRUE(matrix1_before == matrix1);
  EXPECT_TRUE(matrix2_before == matrix2);
}

TEST(TestSub, TestSubOperation3) {
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
  check_matrix(0, 1) = 1.5;
  check_matrix(0, 2) = 1.5;
  check_matrix(1, 0) = -4.5;
  check_matrix(1, 1) = -2.5;
  check_matrix(1, 2) = -7.5;
  check_matrix(2, 0) = 1.0;
  check_matrix(2, 1) = 2.0;
  check_matrix(2, 2) = 0.0;
  check_matrix(3, 0) = 4.0;
  check_matrix(3, 1) = 1.0;
  check_matrix(3, 2) = -3.0;

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;
  s21::FastMatrix<float> result = matrix1 - matrix2;

  EXPECT_EQ(result.get_rows(), 4);
  EXPECT_EQ(result.get_cols(), 3);

  EXPECT_TRUE(result == check_matrix);
  EXPECT_TRUE(matrix1_before == matrix1);
  EXPECT_TRUE(matrix2_before == matrix2);
}

TEST(TestSub, TestSubOperation4) {
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

  check_matrix(0, 0) = 131110199.811;
  check_matrix(0, 1) = 0.0;
  check_matrix(1, 0) = 673549.54545324;
  check_matrix(1, 1) = 145678000.588;

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;
  s21::FastMatrix<float> result = matrix1 - matrix2;

  EXPECT_EQ(result.get_rows(), 2);
  EXPECT_EQ(result.get_cols(), 2);

  EXPECT_TRUE(result == check_matrix);
  EXPECT_TRUE(matrix1_before == matrix1);
  EXPECT_TRUE(matrix2_before == matrix2);
}

TEST(TestSub, TestSubOperation5) {
  s21::FastMatrix<float> matrix1{95, 99};
  EXPECT_EQ(matrix1.get_rows(), 95);
  EXPECT_EQ(matrix1.get_cols(), 99);

  s21::FastMatrix<float> matrix2{95, 99};
  EXPECT_EQ(matrix2.get_rows(), 95);
  EXPECT_EQ(matrix2.get_cols(), 99);

  s21_matrix_test_helper::FillMatrix(matrix1, 2.5);
  s21_matrix_test_helper::FillMatrix(matrix2, 3.5);

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;
  s21::FastMatrix<float> result{95, 99};

  result -= matrix1;

  EXPECT_EQ(result.get_rows(), 95);
  EXPECT_EQ(result.get_cols(), 99);
  s21_matrix_test_helper::CheckMatrix(result, -2.5);

  result -= matrix2;

  EXPECT_EQ(result.get_rows(), 95);
  EXPECT_EQ(result.get_cols(), 99);
  s21_matrix_test_helper::CheckMatrix(result, -6.0);

  EXPECT_TRUE(matrix1_before == matrix1);
  EXPECT_TRUE(matrix2_before == matrix2);
}

TEST(TestSub, TestSubOperation6) {
  s21::FastMatrix<float> matrix1{99, 99};
  EXPECT_EQ(matrix1.get_rows(), 99);
  EXPECT_EQ(matrix1.get_cols(), 99);

  s21::FastMatrix<float> matrix2{99, 99};
  EXPECT_EQ(matrix2.get_rows(), 99);
  EXPECT_EQ(matrix2.get_cols(), 99);

  s21_matrix_test_helper::FillMatrix(matrix1, 2.5);
  s21_matrix_test_helper::FillMatrix(matrix2, -3.5);

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;
  s21::FastMatrix<float> result{99, 99};

  result -= matrix1;

  EXPECT_EQ(result.get_rows(), 99);
  EXPECT_EQ(result.get_cols(), 99);
  s21_matrix_test_helper::CheckMatrix(result, -2.5);

  result -= matrix2;

  EXPECT_EQ(result.get_rows(), 99);
  EXPECT_EQ(result.get_cols(), 99);
  s21_matrix_test_helper::CheckMatrix(result, 1.0);

  EXPECT_TRUE(matrix1_before == matrix1);
  EXPECT_TRUE(matrix2_before == matrix2);
}

TEST(TestSub, TestSubOperation7) {
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
  check_matrix(0, 1) = 1.5;
  check_matrix(0, 2) = 1.5;
  check_matrix(1, 0) = -4.5;
  check_matrix(1, 1) = -2.5;
  check_matrix(1, 2) = -7.5;
  check_matrix(2, 0) = 1.0;
  check_matrix(2, 1) = 2.0;
  check_matrix(2, 2) = 0.0;
  check_matrix(3, 0) = 4.0;
  check_matrix(3, 1) = 1.0;
  check_matrix(3, 2) = -3.0;

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;
  s21::FastMatrix<float> result = matrix1;
  result -= matrix2;

  EXPECT_EQ(result.get_rows(), 4);
  EXPECT_EQ(result.get_cols(), 3);

  EXPECT_TRUE(result == check_matrix);
  EXPECT_TRUE(matrix1_before == matrix1);
  EXPECT_TRUE(matrix2_before == matrix2);
}

TEST(TestSub, TestSubOperation8) {
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

  check_matrix(0, 0) = 131110199.811;
  check_matrix(0, 1) = 0.0;
  check_matrix(1, 0) = 673549.54545324;
  check_matrix(1, 1) = 145678000.588;

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;
  s21::FastMatrix<float> result = matrix1;
  result -= matrix2;

  EXPECT_EQ(result.get_rows(), 2);
  EXPECT_EQ(result.get_cols(), 2);

  EXPECT_TRUE(result == check_matrix);
  EXPECT_TRUE(matrix1_before == matrix1);
  EXPECT_TRUE(matrix2_before == matrix2);
}

TEST(TestSub, TestSubOperation9) {
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
  check_matrix(0, 0) = 0.5;

  s21::FastMatrix<float> matrix1_before = matrix1;
  s21::FastMatrix<float> matrix2_before = matrix2;
  s21::FastMatrix<float> result1 = matrix1;
  s21::FastMatrix<float> result2 = matrix1 - matrix2;
  result1 -= matrix2;

  EXPECT_EQ(result1.get_rows(), 1);
  EXPECT_EQ(result1.get_cols(), 1);
  EXPECT_TRUE(result1 == check_matrix);

  EXPECT_EQ(result2.get_rows(), 1);
  EXPECT_EQ(result2.get_cols(), 1);
  EXPECT_TRUE(result2 == check_matrix);

  EXPECT_TRUE(matrix1_before == matrix1);
  EXPECT_TRUE(matrix2_before == matrix2);
}
