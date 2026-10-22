#include "../src/tokenise.hpp"
#include <catch2/catch_test_macros.hpp>
#include <limits>
#include <vector>


using namespace std::literals::string_literals;

// NOTE: On identifiers/names, I'm sticking with ASCII to check for valid chars.
// In my personal experience I've never found a case for using Unicode letters in identifiers.
// This won't affect Unicode (i.e. utf-8) code points in strings or comments, since we parse a
// string until the closing quote and a comment until the comment terminator.


TEST_CASE ( "identifier start", "[tokenise_helpers]" )
{
    SECTION ( "valid" )
    {
        // Test every possible value of "char" (maybe this is too much...).
        for (char character{ '\0' }; character <= std::numeric_limits<char>::max(); ++character)
        {
            // Identifiers can begin with a lower case letter, an upper case letter or an
            // underscore.
            if (( character >= 'A' && character <= 'Z' ) ||
                ( character >= 'a' && character <= 'z' ) || ( character == '_' ))
            {
                REQUIRE ( is_a_valid_id_start ( character ) );
            }
            else
            {
                REQUIRE_FALSE ( is_a_valid_id_start ( character ) );
            }
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
