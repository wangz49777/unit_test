#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>
 
// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}

std::vector<int> ints = {1,2,3};
std::vector<std::string> strings = {"a","b"};

class CombinationsTest :
    public ::testing::TestWithParam<std::tuple<int, std::string>> {};

TEST_P(CombinationsTest, Basic) {
  std::cout << "int: "        << std::get<0>(GetParam())
            << "  string: \"" << std::get<1>(GetParam())
            << "\"\n";
}

INSTANTIATE_TEST_SUITE_P(AllCombinations,
                        CombinationsTest,
                        ::testing::Combine(::testing::ValuesIn(ints),
                                           ::testing::ValuesIn(strings)));

// int main(int argc, char **argv) {
//   for (int i = 0; i < 10; ++i) {
//     ints.push_back(i * 100);
//     strings.push_back(std::string("String ") + static_cast<char>(i + 65));
//   }
//   testing::InitGoogleTest(&argc, argv);
//   return RUN_ALL_TESTS();
// }