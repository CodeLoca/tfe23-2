#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"

auto main(int argc, char **argv) -> int
{
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */

    auto counter{20}; /*set a default of 20*/

    CLI::App app{PROJECT_NAME}; /*create an instance of an App with the variable name app*/
    try
    {

        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        /*add a command line option to the app and fill the variable counter*/
        app.add_option("-c,--count", counter, "How many times to insert");
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError &e)
    {
        return app.exit(e);
    }

    std::vector<int> numbers(counter);

    srand(time(0));

    for (int &number : numbers)
    {
        number = rand() % 100 +1;
    }

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */

    fmt::print("Numbers: ");
    for (const auto &number : numbers)
    {
        fmt::print("{} ", number);
    }

    fmt::print("\nHello, {}!\n", app.get_name());

    fmt::print("Count, {}!\n", counter);

    fmt::print("Value of argc: {}\n", argc);

    fmt::print("Value of argv: {}\n", argv[1]); /*print the first argument of argv*/

    return 0; /* exit gracefully*/
}
