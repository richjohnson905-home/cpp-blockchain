
#include <CLI/App.hpp>
#include "AppCli.h"
#include "MyCoinApp.h"
#include "spdlog/spdlog.h"

int main(int argc, const char *argv[]) {
    spdlog::set_level(spdlog::level::debug);
    CLI::App cli11App("MyCoin Cli App Parser");
    AppCli appCli(&cli11App);
    CLI11_PARSE(cli11App, argc, argv);

    MyCoinApp app(&appCli);
    return app.run();
}
