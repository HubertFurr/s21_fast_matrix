#include "test.h"

int main(int argc, char *argv[]) {
  // Задаем фильтры для запуска некоторых тестов
  // ::testing::GTEST_FLAG(filter) = "TestSpeed.TestGemm*";
  // ::testing::GTEST_FLAG(filter) = "*TestM1MulTranspose2*";
  // ::testing::GTEST_FLAG(filter) =
  // "TestSpeed.TestM1MulTranspose1:TestSpeed.TestGemmMatrix1";

  // Передаем параметры командной строки в gtest
  testing::InitGoogleTest(&argc, argv);

  // Запускаем все тесты
  return RUN_ALL_TESTS();
}
