#include <print>
#include <string_view>
#include <vector>

using namespace std::literals;

// Simple format
// =============
//
// Simply format code files.
//
// I'll start with a "simple" language like Lua.  This is the basic idea:
//
//     - Read the file as one string_view containing the newlines.
//     - Keep the newlines (don't change text width).
//     - Parse the line and tokenise with a little twist:
//         - We won't split the line into "tokens", instead, each token will contain:
//             - A pair (begin, end) position on the string.
//             - A type.
//     - Then apply the format to each line, following certain rules.
//         - For now the rules are fixed, but the idea is to read from a configuration file and
//         don't be "opinionated".  The user knows what they want.  Respect that.  "Good enough" is
//         rarely good enough.
//         - Remember: readability counts.
//
// MPV:
//
//    Start with an in memory representation (so, a string haha) and a simple code fragment.
//
//    Eventually read this from stdin.
//
//    Add tokens and rules (both for parsing and formatting) as the program grows.
//
//    Keep it simple.
//
//

enum class Token_type
{
    Keyword,
    Identifier,
    Number,
    String,
    Operator,
};

class Token
{
  public:
    explicit Token ( std::string_view content, Token_type type ) : content{ content }, type{ type }
    {
    }

  private:
    std::string_view content;
    Token_type       type;
};

auto tokenise ( std::string_view ) -> std::vector<Token>;

auto format ( std::vector<Token> ) -> std::string;

auto main () -> int
{
    // What we got:
    // ```
    // local a=21
    //
    // local b=63
    //
    // local answer=a+b/3
    //
    // print("The answer is",answer)
    // ```
    // What we want:
    // ```
    // local a = 21
    //
    // local b = 63
    //
    // local answer = a + b / 3
    //
    // print("The answer is", answer)
    // ```
    auto code{
        R"x(
local a=21

local b=63

local answer=a+b/3

print("The answer is", answer)
		)x"s };

    auto tokens{ tokenise ( code ) };
    auto result{ format ( tokens ) };

    std::println ( "Output:\n\n{}\n", result );

    return 0;
}
