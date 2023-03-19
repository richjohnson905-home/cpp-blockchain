#include <catch2/catch.hpp>
#include "TestHelper.h"
#include "../src/MyCoinApp.h"
#include <filesystem>

namespace fs = std::filesystem;

TEST_CASE("Create Genesis Blocks and Add One Block") {

    TestHelper helper;
    fs::remove_all("../test/data/out/");
    fs::create_directories("../test/data/out/");

    CLI::App cliApp("MyCoin Cli Parser");
    AppCli cli(&cliApp);
    auto cliArgs = "--amount 3 \
                   --receiver-key Joe \
                   --sender-key Steve  \
                   --filename ../test/data/out/uatchain.json";
    cliApp.parse(cliArgs);

    SECTION("Genesis blocks creation") {
        MyCoinApp app(&cli);
        int returnCode = app.run();
        REQUIRE(returnCode == 0);
        REQUIRE(helper.getChain("../test/data/out/uatchain.json").blocks.size() == 2);
        SECTION("Add one more") {
            MyCoinApp app(&cli);
            int returnCode = app.run();
            REQUIRE(returnCode == 0);
            REQUIRE(helper.getChain("../test/data/out/uatchain.json").blocks.size() == 3);
        }
    }


}