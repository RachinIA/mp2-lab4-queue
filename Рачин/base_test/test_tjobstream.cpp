#include "TJobStream.h"
#include <gtest.h>

TEST(TJobStream, can_create_stream_without_data)
{
	ASSERT_NO_THROW(TJobStream T);
}


