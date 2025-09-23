#include <fmt/format.h>

int main()
{
    fmt::print("Hello, world!\n");

    int answer = 42;
    std::string msg = fmt::format("The answer is {}.\n", answer);
    fmt::print(msg);

    return 0;
}