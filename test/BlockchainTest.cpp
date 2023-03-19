
#include <catch2/catch.hpp>
#include "../src/Blockchain.h"
#include <fakeit.hpp>

using namespace fakeit;

TEST_CASE("initAndValidate non-existing chain file invokes create genesis block") {
    // Arrange
    Mock<BlockValidator> mockValidator;
    Mock<BlockchainHelper> mockHelper;
    Blockchain testObject(&mockValidator.get(), &mockHelper.get());

    mycoin_ns::Block genesisBlock;
    std::vector<mycoin_ns::Block> mycoinChain;


    When(Method(mockHelper, createGenesisBlock)).Return(genesisBlock);

    std::string chainFile = "../test/data/DoesNotExist.json";

    // act
    testObject.initAndValidate(chainFile, mycoinChain);

    // assert
    REQUIRE(mycoinChain.size() == 1);
    Verify(Method(mockHelper, loadChain)).Never();
    Verify(Method(mockHelper, createGenesisBlock)).Once();
    Verify(Method(mockValidator, validateChain)).Never();
}

TEST_CASE("initAndValidate with existing valid chain file") {
    Mock<BlockValidator> mockValidator;
    Mock<BlockchainHelper> mockHelper;
    Blockchain testObject(&mockValidator.get(), &mockHelper.get());

    std::string chainFile = "../test/data/usecase1.json";
    mycoin_ns::Chain chain;
    std::vector<mycoin_ns::Block> blocks;
    std::vector<mycoin_ns::Block> mycoinChain;

    When(Method(mockHelper, loadChain)).Return(chain);
    When(Method(mockValidator, validateChain)).Return(blocks);

    testObject.initAndValidate(chainFile, mycoinChain);

    REQUIRE(mycoinChain.size() == 0);
    Verify(Method(mockHelper, loadChain)).Once();
    Verify(Method(mockHelper, createGenesisBlock)).Never();
    Verify(Method(mockValidator, validateChain)).Once();
}

TEST_CASE("handleTransaction correctly initializes block") {
    Mock<BlockValidator> mockValidator;
    Mock<BlockchainHelper> mockHelper;
    Blockchain testObject(&mockValidator.get(), &mockHelper.get());

    int blockHash = 123456789;

    mycoin_ns::Block newBlock;
    newBlock.blockHash = blockHash;

    When(Method(mockHelper, createBlock)).AlwaysDo(
            [&](const mycoin_ns::TransactionData &data, int index, size_t prevHash){
                if (data.amount == 3 && data.senderKey == "Joe" && data.receiverKey == "Rich") {
                    return newBlock;
                } else {
                    mycoin_ns::Block failBlock;
                    FAIL("Test failed on TransactionData");
                    return failBlock;
                }
    });

    std::vector<mycoin_ns::Block> mycoinChain;
    mycoinChain.push_back(newBlock);

    testObject.handleTransaction(3, "Rich", "Joe", mycoinChain);

    Verify(Method(mockHelper, createBlock).Using(_, 1, blockHash)).Once();
}

TEST_CASE("writeChain") {
    Mock<BlockValidator> mockValidator;
    Mock<BlockchainHelper> mockHelper;
    Blockchain testObject(&mockValidator.get(), &mockHelper.get());

    std::string actualFile;
    mycoin_ns::Block actualBlock;
    When(Method(mockHelper, writeChain)).Do([&](const mycoin_ns::Chain& chain, const std::string& filename){
        actualFile = filename;
        actualBlock = chain.blocks[0];
    });

    std::string chainFile = "../test/data/usecase1.json";
    mycoin_ns::Block someBlock;
    someBlock.blockHash = 123456789;
    someBlock.previousHash = 111;
    someBlock.index = 1;
    std::vector<mycoin_ns::Block> blocks = {someBlock};

    testObject.writeChain(chainFile, blocks);

    Verify(Method(mockHelper, writeChain)).Once();
    REQUIRE(actualFile == chainFile);
    REQUIRE(actualBlock.blockHash == 123456789);
}