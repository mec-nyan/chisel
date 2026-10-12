#include <string_view>
#include <vector>


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
