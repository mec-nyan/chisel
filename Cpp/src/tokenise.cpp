#include "tokenise.hpp"
#include <locale>
#include <unordered_set>


auto tokenise ( std::string_view _ ) -> std::vector<Token>
{
    return {};
}


// Helpers.


auto is_a_valid_id_start ( char c ) -> bool
{
    return c == '_' || std::isalpha ( c, std::locale ( "en_US.UTF8" ) );
}

auto is_a_valid_id_char ( char c ) -> bool
{
    return c == '_' || std::isalnum ( c, std::locale ( "en_US.UTF8" ) );
}

auto is_a_keyword ( std::string_view word ) -> bool
{
    std::unordered_set<std::string_view> lua_keywords{
        "and",   "break",    "do",     "else", "elseif", "end",   "for",
        "false", "function", "if",     "in",   "local",  "nil",   "not",
        "or",    "repeat",   "return", "then", "true",   "until", "while" };

    return lua_keywords.contains ( word );
}

auto is_a_valid_number_start ( char ) -> bool
{
    return false;
}

auto is_a_valid_number_char ( char ) -> bool
{
    return false;
}

auto is_a_number ( std::string_view ) -> bool
{
    return false;
}

auto is_an_operator ( char ) -> bool
{
    return false;
}

auto is_an_operator ( std::string_view ) -> bool
{
    return false;
}

auto starts_a_comment ( std::string_view ) -> bool
{
    return false;
}

auto starts_a_multiline_comment ( std::string_view ) -> bool
{
    return false;
}

auto ends_a_multiline_comment ( std::string_view ) -> bool
{
    return false;
}
