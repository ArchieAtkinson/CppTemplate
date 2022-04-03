#include "foo.hpp"
#include <catch2/catch_test_macros.hpp>


TEST_CASE( "ints are added", "[add]" )
{
   REQUIRE(add(1,1) == 2);
   REQUIRE(add(-1, -1) == -2);
   REQUIRE(add(100000, -100000) == 0);
}