#pragma once

#include <string_view>
#include <vector>


enum class TokenType
{
    Keyword,       // I.e. "local", "function", etc.
    Identifier,    // my_var, myVar and _my_var but not 1var ets.
    Number,        // Both decimal and hexadecimal, including exponent notation.
    String,        // Single and double quoted strings.
    Operator,      // The usual suspects: "+ - * / % ^ = .." etc.
    ShortComment,  // From "--" up to but not including "\n".
    LongComment,   // From "--[[" up to and including the closing "--]]".
    Punctuation,   // ". , : ;"
};

class Token
{
  public:
    Token ( std::string_view content, TokenType type ) : _content{ content }, _type{ type }
    {
    }

    auto content ()
    {
        return _content;
    }

    auto type ()
    {
        return _type;
    }

  private:
    std::string_view _content;
    TokenType        _type;
};

auto tokenise ( std::string_view ) -> std::vector<Token>;

// `tokenise` will use these internally.
// TODO: What about Unicode (UTF-8 may not be "chars").
// TODO: How are we going to support multiple languages?

auto is_a_valid_id_start ( char ) -> bool;

auto is_a_valid_id_char ( char ) -> bool;

auto is_a_keyword ( std::string_view ) -> bool;

auto is_a_valid_number_start ( char ) -> bool;

auto is_a_valid_number_char ( char ) -> bool;

auto is_a_number ( std::string_view ) -> bool;

auto is_an_operator ( char ) -> bool;

auto is_an_operator ( std::string_view ) -> bool;

auto starts_a_comment ( std::string_view ) -> bool;

auto starts_a_multiline_comment ( std::string_view ) -> bool;

auto ends_a_multiline_comment ( std::string_view ) -> bool;
