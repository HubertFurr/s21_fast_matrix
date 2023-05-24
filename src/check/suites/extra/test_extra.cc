#include "./../../test.h"

TEST(TestExtra, TestOperatorBracketsConst2) {
  const s21::FastMatrix<float> matrix_check{3, 3};
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

  // Расскомментировать, чтобы проверить наличие ошибки при компиляции
  // (конст матрицы нельзя менять!)
  // matrix_check(0, 0) = 1.0;
  // matrix_check(0, 1) = 2.0;
  // matrix_check(1, 0) = 3.0;
  // matrix_check(1, 1) = 4.0;
}

TEST(TestExtra, TestOperatorBracketsParrot) {
  // Расскомментировать, чтобы проверить, позволяет ли класс получать висячие
  // ссылки
  // s21::FastMatrix<float> matrix_check;
  // double& y = matrix_check(0, 0);
  // // double& z = s21::FastMatrix<float>{}(0,0);
  // // const double& zz = s21::FastMatrix<float>{}(0, 0);

  // std::cout << y << std::endl;
  // // std::cout << z << std::endl;
  // // std::cout << zz << std::endl;

  // const s21::FastMatrix<float> matrix_check_const;

  // // double& cy = matrix_check_const(0, 0);
  // const double& ccy = matrix_check_const(0, 0);
  // // double& cz = s21::FastMatrix<float>{}(0,0);
  // // const double& czz = s21::FastMatrix<float>{}(0, 0);

  // // std::cout << cy << std::endl;
  // std::cout << ccy << std::endl;
  // // std::cout << cz << std::endl;
  // // std::cout << czz << std::endl;
}

// Просто проверяем, что данные операции компилируются и выполняются
TEST(TestExtra, TestConstRef1) {
  s21::FastMatrix<float> result1 = s21::FastMatrix<float>(1, 1) + s21::FastMatrix<float>(1, 1);
  s21::FastMatrix<float> result2 = s21::FastMatrix<float>(1, 1) - s21::FastMatrix<float>(1, 1);
  s21::FastMatrix<float> result3 = s21::FastMatrix<float>(1, 1) * s21::FastMatrix<float>(1, 1);
  bool result4 = s21::FastMatrix<float>(1, 1) == s21::FastMatrix<float>(1, 1);
  s21::FastMatrix<float> result5 = s21::FastMatrix<float>(1, 1) * 2.0;
  s21::FastMatrix<float> result6 = 2.0 * s21::FastMatrix<float>(1, 1);

  EXPECT_TRUE(result1 == s21::FastMatrix<float>(1, 1));
  EXPECT_TRUE(result2 == s21::FastMatrix<float>(1, 1));
  EXPECT_TRUE(result3 == s21::FastMatrix<float>(1, 1));
  EXPECT_TRUE(result4);
  EXPECT_TRUE(result5 == s21::FastMatrix<float>(1, 1));
  EXPECT_TRUE(result6 == s21::FastMatrix<float>(1, 1));
}
