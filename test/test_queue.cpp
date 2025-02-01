#include "/repos/mp2-lab4-QueueList/Queue/TQueue.h"
#include "gtest.h"

TEST(TQueue, can_create_queue)
{
	ASSERT_NO_THROW(TQueue<int> q);
}

TEST(TQueue, can_create_copied_queue)
{
	TQueue<int> q;
	ASSERT_NO_THROW(TQueue<int> q1(q));

}

TEST(TQueue, copied_queue_is_equal_to_source_one)
{
	TQueue<int> q;
	TQueue<int> q1;
	EXPECT_EQ(q, q1);
}

TEST(TQueue, can_set_and_get_elements)
{
	TQueue<int> q;
	ASSERT_NO_THROW(q.Push(10));
	q.Push(5);
	EXPECT_EQ(q.Front(), 10);
	EXPECT_EQ(q.Back(), 5);
	EXPECT_EQ(q.Pop(), 10);
	EXPECT_EQ(q.Pop(), 5);
}

TEST(TQueue, can_clear_queue)
{
	TQueue<int> q;
	for (int i = 0; i < 10; i++) {
		q.Push(i);
	}
	ASSERT_NO_THROW(q.Clear());
	EXPECT_EQ(q.isEmpty(), true);
}

TEST(TQueue, can_assign_queue_to_itself)
{
	TQueue<int> q;
	ASSERT_NO_THROW(q = q);
}

TEST(TQueue, can_assign_queues_of_equal_size)
{
	TQueue<int> q1, q2;
	for (int i = 0; i < 5; i++) {
		q1.Push(1);
		q2.Push(2);
	}
	ASSERT_NO_THROW(q1 = q2);
}

TEST(TQueue, can_assign_queues_of_different_size)
{
	TQueue<int> q1, q2;
	for (int i = 0; i < 5; i++)
	{
		q1.Push(i);
	}
	ASSERT_NO_THROW(q2 = q1);
	EXPECT_EQ(q2, q1);
}

TEST(TQueue, compare_equal_queues_return_true)
{
	TQueue<int> q1, q2;
	for (int i = 0; i < 10; i++) {
		q1.Push(i);
		q2.Push(i);
	}
	EXPECT_EQ(q1 == q2, true);
}

TEST(TQueue, compare_queue_with_itself_return_true)
{
	TQueue<int> q1;
	EXPECT_EQ(q1 == q1, true);
}

TEST(TQueue, queues_with_different_size_are_not_equal)
{
	TQueue<int> q1, q2;
	for (int i = 0; i < 10; i++) q1.Push(i);
	for (int j = 0; j < 20; j++) q2.Push(j);
	EXPECT_EQ(q1 != q2, true);
}

TEST(TQueue, when_queue_is_empty_cant_get_element)
{
	TQueue<int> q;
	ASSERT_ANY_THROW(q.Pop());
}



