#include "../src/tokenise.hpp"
#include <catch2/catch_test_macros.hpp>


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
            REQUIRE ( is_a_valid_id_start ( c ) == false );
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
            REQUIRE ( is_a_valid_id_char ( c ) == false );
        }
    }
}
