#include "TQueue.h"
#include <gtest.h>

TEST(TQueue, can_create_queue_with_positive_length)
{
  ASSERT_NO_THROW(TQueue<int> st(10));
}
TEST(TQueue, cant_create_too_large_length)
{
	ASSERT_ANY_THROW(TQueue<int>st(MaxMemSize + 1));
}
TEST(TQueue, can_create_queue_with_negativ_length)
{
	ASSERT_ANY_THROW(TQueue<int>st(-1));
}
TEST(TQueue, check_IsEmpty_with_empty_queue)
{
	TQueue<int> st(5);
	EXPECT_EQ(true, st.IsEmpty());
}
TEST(TQueue, check_IsEmpty_with_not_empty_queue)
{
	TQueue<int> st(5);
	st.Put(2);
	EXPECT_EQ(false, st.IsEmpty());
}
TEST(TQueue, check_IsFull_with_full_queue)
{
	TQueue<int> st(2);
	st.Put(1);
	st.Put(2);
	EXPECT_EQ(true, st.IsFull());
}
TEST(TQueue, check_IsFull_with_not_full_queue)
{
	TQueue<int> st(5);
	st.Put(2);
	EXPECT_EQ(false, st.IsFull());
}

TEST(TQueue, check_Get)
{
	TQueue<int> st(2);
	st.Put(2);
	st.Put(2);
	EXPECT_EQ(2, st.Get());
}