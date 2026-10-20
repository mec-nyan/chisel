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
