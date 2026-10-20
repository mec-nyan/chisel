#include "../src/tokenise.hpp"
#include <catch2/catch_test_macros.hpp>
#include <vector>


using namespace std::literals::string_literals;


TEST_CASE ( "identifier start", "[tokenise_helpers]" )
{
    SECTION ( "valid" )
    {
        auto valid_chars{ "_abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"s };

        for (const auto &c : valid_chars)
        {
            REQUIRE ( is_a_valid_id_start ( c ) );
        }
    }

    SECTION ( "invalid" )
    {
        // TODO: Better ASCII subset.
        auto invalid_chars{ "0123456789+-=*/%<>"s };

        for (const auto &c : invalid_chars)
        {
            REQUIRE_FALSE ( is_a_valid_id_start ( c ) );
        }
    }
}

TEST_CASE ( "identifier character", "[tokenise_helpers]" )
{
    SECTION ( "valid" )
    {
        auto valid_chars{ "_abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"s };

        for (const auto &c : valid_chars)
        {
            REQUIRE ( is_a_valid_id_char ( c ) );
        }
    }

    SECTION ( "invalid" )
    {
        // TODO: Better ASCII subset.
        auto invalid_chars{ "+-=*/%<>"s };

        for (const auto &c : invalid_chars)
        {
            REQUIRE_FALSE ( is_a_valid_id_char ( c ) );
        }
    }
}

TEST_CASE ( "keywords", "[tokenise_helpers]" )
{
    SECTION ( "yes they are" )
    {
        std::vector lua_keywords{ "and",  "break", "do",       "else",   "elseif", "end",
                                  "for",  "false", "function", "if",     "in",     "local",
                                  "nil",  "not",   "or",       "repeat", "return", "then",
                                  "true", "until", "while" };

        for (const auto &kw : lua_keywords)
        {
            REQUIRE ( is_a_keyword ( kw ) );
        }
    }

    SECTION ( "no they're not'" )
    {
        // NOTE: Add more cases!
        std::vector not_lua_keywords{ "And",    "AND",   "_local", "FOR",    "continue",
                                      "f**k",   "what?", "IDK",    "fn",     "def",
                                      "define", "var",   "let",    "don't'", "DO" };

        for (const auto &w : not_lua_keywords)
        {
            REQUIRE_FALSE ( is_a_keyword ( w ) );
        }
    }
}
