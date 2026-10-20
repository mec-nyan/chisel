#include "../src/tokenise.hpp"
#include <catch2/catch_test_macros.hpp>


using namespace std::literals::string_view_literals;


TEST_CASE ( "no code, no tokens", "[tokenise]" )
{
    auto tokens{ tokenise ( ""sv ) };

    REQUIRE ( tokens.size() == 0 );
}


TEST_CASE ( "single-line comments", "[tokenise]" )
{
    auto code{ "-- This is a comment"sv };
    auto tokens{ tokenise ( code ) };

    REQUIRE ( tokens.size() == 1 );
    REQUIRE ( tokens[ 0 ].content() == code );
    REQUIRE ( tokens[ 0 ].type() == TokenType::ShortComment );
}


TEST_CASE ( "multi-line comments", "[tokenise]" )
{
    auto code{ R"x(
--[[ This is a comment
--   that spans
--   across
--   several
--   lines.
--]])x"sv };

    auto tokens{ tokenise ( code ) };

    REQUIRE ( tokens.size() == 1 );
    REQUIRE ( tokens[ 0 ].content() == code );
    REQUIRE ( tokens[ 0 ].type() == TokenType::LongComment );
}


TEST_CASE ( "keywords", "[tokenise]" )
{
    // TODO: Test every keyword.
    // TODO: `tokenise` will eventually support several languages, we'll need to change this.
    auto code{ "local"sv };
    auto tokens{ tokenise ( code ) };

    REQUIRE ( tokens.size() == 1 );
    REQUIRE ( tokens[ 0 ].content() == code );
    REQUIRE ( tokens[ 0 ].type() == TokenType::Keyword );
}


TEST_CASE ( "identifiers", "[tokenise]" )
{
    // TODO: Test several valid identifiers.
    // Most languages have the same rule: [_a-zA-Z][_a-zA-Z0-9] ...
    auto code{ "my_var"sv };
    auto tokens{ tokenise ( code ) };

    REQUIRE ( tokens.size() == 1 );
    REQUIRE ( tokens[ 0 ].content() == code );
    REQUIRE ( tokens[ 0 ].type() == TokenType::Identifier );
}


TEST_CASE ( "operators", "[tokenise]" )
{
    // TODO: Test each operator.  This is language dependant.
    auto code{ "+"sv };
    auto tokens{ tokenise ( code ) };

    REQUIRE ( tokens.size() == 1 );
    REQUIRE ( tokens[ 0 ].content() == code );
    REQUIRE ( tokens[ 0 ].type() == TokenType::Operator );
}


TEST_CASE ( "strings", "[tokenise]" )
{
    // TODO: Test double quoted strings.
    auto code{ "'A \\\"single quoted\\\" string'"sv };
    auto tokens{ tokenise ( code ) };

    REQUIRE ( tokens.size() == 1 );
    REQUIRE ( tokens[ 0 ].content() == code );
    REQUIRE ( tokens[ 0 ].type() == TokenType::String );
}


TEST_CASE ( "numbers", "[tokenise]" )
{
    // TODO: Test all valid numbers.  This is also language dependant.
    // For now we'll have decimal and hexadecimal, with possible exponent notation.
    auto code{ "42"sv };
    auto tokens{ tokenise ( code ) };

    REQUIRE ( tokens.size() == 1 );
    REQUIRE ( tokens[ 0 ].content() == code );
    REQUIRE ( tokens[ 0 ].type() == TokenType::Number );
}
