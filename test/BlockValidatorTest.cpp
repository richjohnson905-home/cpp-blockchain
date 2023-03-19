#include <catch2/catch.hpp>
#include "../src/BlockValidator.h"
#include <fakeit.hpp>
#include "spdlog/spdlog.h"

using namespace fakeit;

TEST_CASE("validateChain empty chain") {
    BlockValidator testObject;
    mycoin_ns::Chain chain;
    chain.blocks = {};
    std::vector<mycoin_ns::Block> actual = testObject.validateChain(chain);
    REQUIRE(actual.size() == 0);
}

TEST_CASE("validateChain valid two blocks in chain") {
    spdlog::set_level(spdlog::level::debug);
    BlockValidator testObject;
    mycoin_ns::Chain chain;

    mycoin_ns::TransactionData genesis;
    genesis.receiverKey = "None";
    genesis.senderKey = "None";
    genesis.amount = 3;
    genesis.timestamp = 0;
    mycoin_ns::Block block1;
    block1.blockHash = 9422463218741359442U;
    block1.previousHash = 0;
    block1.index = 0;
    block1.data = genesis;

    mycoin_ns::TransactionData d;
    d.receiverKey = "reciever";
    d.senderKey = "sender";
    d.amount = 3;
    d.timestamp = 0;
    mycoin_ns::Block block2;
    block2.blockHash = 15301990689037496816U;
    block2.previousHash = 9422463218741359442U;
    block2.index = 1;
    block2.data = d;

    chain.blocks = {block1, block2};
    std::vector<mycoin_ns::Block> actual = testObject.validateChain(chain);
    REQUIRE(actual.size() == 2);
}