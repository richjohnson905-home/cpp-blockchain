
#include "BlockchainHelper.h"
#include "spdlog/spdlog.h"
#include "nlohmann/json.hpp"
#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

using nlohmann::json;

mycoin_ns::Chain BlockchainHelper::loadChain(const std::string& filename) {
    spdlog::info("BlockchainHelper::loadChain: {}", filename);
    std::ifstream ifs(filename);
    json jf = json::parse(ifs);
    mycoin_ns::Chain myBlockChain = jf;
    return myBlockChain;
}

mycoin_ns::Block BlockchainHelper::createGenesisBlock() {
    spdlog::info("BlockchainHelper::createGenesisBlock");
    mycoin_ns::Block block;
    block.index = 0;
    std::hash<int> hash1;
    block.previousHash = hash1(0);

    time_t current;
    mycoin_ns::TransactionData d;
    d.amount = 0;
    d.receiverKey = "None";
    d.senderKey = "None";
    d.timestamp = time(&current);
    block.data = d;
    block.blockHash = m_util.generateHash(block);
    return block;
}

mycoin_ns::Block BlockchainHelper::createBlock(const mycoin_ns::TransactionData &data,
                                               int index,
                                               size_t prevHash) {
    spdlog::info("BlockchainHelper::createBlock at index: {}", index);
    mycoin_ns::Block block;
    block.index = index;
    block.previousHash = prevHash;
    block.data = data;
    block.blockHash = m_util.generateHash(block);
    return block;
}

void BlockchainHelper::writeChain(const mycoin_ns::Chain& chain, const std::string& filename) {
    spdlog::info("BlockchainHelper::writeChain with size: {}", chain.blocks.size());
    json j = chain;
    std::ofstream out(filename);
    out << j;
    out.close();
}
