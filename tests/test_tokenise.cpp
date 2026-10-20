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

    SECTION ( "keywords" )
    {
        // TODO: Test every keyword.
        // TODO: `tokenise` will eventually support several languages, we'll need to change this.
        auto code{ "local"sv };
        auto tokens{ tokenise ( code ) };

        REQUIRE ( tokens.size() == 1 );
        REQUIRE ( tokens[ 0 ].content() == code );
        REQUIRE ( tokens[ 0 ].type() == TokenType::Keyword );
    }

    SECTION ( "identifiers" )
    {
        // TODO: Test several valid identifiers.
        // Most languages have the same rule: [_a-zA-Z][_a-zA-Z0-9] ...
        auto code{ "my_var"sv };
        auto tokens{ tokenise ( code ) };

        REQUIRE ( tokens.size() == 1 );
        REQUIRE ( tokens[ 0 ].content() == code );
        REQUIRE ( tokens[ 0 ].type() == TokenType::Identifier );
    }

    SECTION ( "operators" )
    {
        // TODO: Test each operator.  This is language dependant.
        auto code{ "+"sv };
        auto tokens{ tokenise ( code ) };

        REQUIRE ( tokens.size() == 1 );
        REQUIRE ( tokens[ 0 ].content() == code );
        REQUIRE ( tokens[ 0 ].type() == TokenType::Operator );
    }

    SECTION ( "strings" )
    {
        // TODO: Test double quoted strings.
        auto code{ "'A \\\"single quoted\\\" string'"sv };
        auto tokens{ tokenise ( code ) };

        REQUIRE ( tokens.size() == 1 );
        REQUIRE ( tokens[ 0 ].content() == code );
        REQUIRE ( tokens[ 0 ].type() == TokenType::String );
    }

    SECTION ( "numbers" )
    {
        // TODO: Test all valid numbers.  This is also language dependant.
        // For now we'll have decimal and hexadecimal, with possible exponent notation.
        auto code{ "42"sv };
        auto tokens{ tokenise ( code ) };

        REQUIRE ( tokens.size() == 1 );
        REQUIRE ( tokens[ 0 ].content() == code );
        REQUIRE ( tokens[ 0 ].type() == TokenType::Number );
    }
}
