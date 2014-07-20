#include <gtest/gtest.h>
#include "Sequence.hpp"

TEST(Sequence, DefaultConstructor)
{
	Sequence<int> seq;
	ASSERT_TRUE(seq.size() == 0);
}

TEST(Sequence, ParameterPackConstructor)
{
	Sequence<int> seq(1, 2, 3, 4, 5, 6, 7, 8, 9, 0);
	ASSERT_TRUE(seq.size() == 10);
}

TEST(Sequence, InitializerListConstructor)
{
	Sequence<int> seq {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	ASSERT_TRUE(seq.size() == 10);
}