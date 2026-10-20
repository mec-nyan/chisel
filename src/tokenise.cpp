#include "tokenise.hpp"


auto tokenise ( std::string_view _ ) -> std::vector<Token>
{
    return {};
}


// Helpers.


auto is_a_valid_id_start ( char ) -> bool
{
    return false;
}

auto is_a_valid_id_char ( char ) -> bool
{
    return false;
}

auto is_a_keyword ( std::string_view ) -> bool
{
    return false;
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
