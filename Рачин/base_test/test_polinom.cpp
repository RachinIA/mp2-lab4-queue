#include "TPolinom.h"
#include <gtest.h>


TEST(TPolinom, can_create_polinom)
{
	ASSERT_NO_THROW(TPolinom* P1);
}

TEST(TPolinom, can_create_copied_polinom)
{
	int arrMn[][2] = { {2, 414}, {2, 111}, {3, 111} };
	int size = sizeof(arrMn) / (2 * sizeof(int));
	TPolinom p(arrMn, size);
	ASSERT_NO_THROW(TPolinom p1(p));
}