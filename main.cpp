#include <print>

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

auto main () -> int
{
    std::println ( "Hello, 🌎!" );
    return 0;
}
