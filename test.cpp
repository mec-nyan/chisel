#include <catch2/catch_test_macros.hpp>

#include "tokenise.hpp"

using namespace std::literals::string_view_literals;

TEST_CASE ( "no code, no tokens", "[tokenise]" )
{
    auto tokens{ tokenise ( ""sv ) };

    REQUIRE ( tokens.size() == 0 );
}

TEST_CASE ( "get token information", "[tokenise]" )
{
    SECTION ( "single line comments are one token" )
    {
        auto tokens{ tokenise ( "-- This is a comment"sv ) };

        REQUIRE ( tokens.size() == 1 );
    }

    SECTION ( "tokens must have the correct content" )
    {
        auto code{ "-- This is a comment"sv };
        auto tokens{ tokenise ( code ) };

        REQUIRE ( tokens[ 0 ].content() == code );
    }

    SECTION ( "tokens must have the correct type" )
    {
        auto code{ "-- This is a comment"sv };
        auto tokens{ tokenise ( code ) };

        REQUIRE ( tokens[ 0 ].type() == TokenType::ShortComment );
    }
}
