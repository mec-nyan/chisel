#include <catch2/catch_test_macros.hpp>

#include "tokenise.hpp"

TEST_CASE ( "There will be no tokens.", "[tokenise]" )
{
    REQUIRE ( tokenise ( "" ).size() == 0 );
}
