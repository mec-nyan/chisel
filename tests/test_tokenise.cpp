#include <catch2/catch_test_macros.hpp>

#include "../src/tokenise.hpp"

using namespace std::literals::string_view_literals;

TEST_CASE ( "no code, no tokens", "[tokenise]" )
{
    auto tokens{ tokenise ( ""sv ) };

    REQUIRE ( tokens.size() == 0 );
}

TEST_CASE ( "identify each token correctly", "[tokenise]" )
{
    SECTION ( "single line comments" )
    {
        auto code{ "-- This is a comment"sv };
        auto tokens{ tokenise ( code ) };

        REQUIRE ( tokens.size() == 1 );
        REQUIRE ( tokens[ 0 ].content() == code );
        REQUIRE ( tokens[ 0 ].type() == TokenType::ShortComment );
    }

    SECTION ( "multi-line comments" )
    {
        auto code{ "--[[ This is a comment\nacross\nseveral\nlines\n--]]"sv };
        auto tokens{ tokenise ( code ) };

        REQUIRE ( tokens.size() == 1 );
        REQUIRE ( tokens[ 0 ].content() == code );
        REQUIRE ( tokens[ 0 ].type() == TokenType::LongComment );
    }
}
