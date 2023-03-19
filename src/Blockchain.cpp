
#include "Blockchain.h"
#include <spdlog/spdlog.h>
#include "nlohmann/json.hpp"
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

using nlohmann::json;

Blockchain::Blockchain(BlockValidator* validator, BlockchainHelper* helper)
:m_validator(validator),
m_helper(helper) {

}

void Blockchain::initAndValidate(const std::string &filename,
                                 std::vector<mycoin_ns::Block>& mycoinChain) {
    if (fs::exists(filename)) {
        spdlog::info("Blockchain::initAndValidate file exists: {}", filename);
        mycoinChain = m_validator->validateChain(m_helper->loadChain(filename));
        spdlog::debug("Blockchain::initAndValidate complete with chain size: {}", mycoinChain.size());
    } else {
        spdlog::info("Blockchain::initAndValidate creating genesis block. File does NOT exists: {}", filename);
        mycoinChain.push_back(m_helper->createGenesisBlock());
    }
}

void Blockchain::handleTransaction(double amount,
                                   const std::string &receiver,
                                   const std::string &sender,
                                   std::vector<mycoin_ns::Block>& mycoinChain) {
    spdlog::info("Blockchain::handleTransaction");
    time_t current;
    mycoin_ns::TransactionData d;
    d.timestamp = time(&current);
    d.amount = amount;
    d.receiverKey = receiver;
    d.senderKey = sender;

    mycoinChain.push_back(m_helper->createBlock(d, mycoinChain.size(), mycoinChain.back().blockHash));
}

void Blockchain::writeChain(const std::string& filename,
                            const std::vector<mycoin_ns::Block>& mycoinChain) {
    spdlog::info("Blockchain::writeChain to file: {} Chain Size: {}", filename, mycoinChain.size());
    mycoin_ns::Chain chain;
    chain.blocks = mycoinChain;
    m_helper->writeChain(chain, filename);
}

