
#include "BlockValidator.h"
#include "spdlog/spdlog.h"

std::vector<mycoin_ns::Block> BlockValidator::validateChain(const mycoin_ns::Chain& chain) {
    spdlog::info("BlockValidator::validateChain size: {}", chain.blocks.size());
    std::vector<mycoin_ns::Block>::const_iterator it;
    std::vector<mycoin_ns::Block>::const_iterator prev;
    int chainLength = static_cast<int>(chain.blocks.size());

    bool isFirst = true;
    for(it = chain.blocks.begin(), prev = chain.blocks.end(); it != chain.blocks.end(); prev = it, ++it) {
        if (isFirst) {
            isFirst = false;
            continue;
        }
        mycoin_ns::Block currentBlock = *it;
        if (!isHashValid(currentBlock)) {
            throw std::runtime_error(" This block's hash has been altered. Index: " + std::to_string(currentBlock.index));
        }
        if (chainLength > 1) {
            if (isBlockValid(currentBlock, *(prev))) {
                throw std::runtime_error("the current block's previous hash does not match the hash of the preceding block's hash at index: " + std::to_string(currentBlock.index));
            }
        }
    }
    return chain.blocks;
}

bool BlockValidator::isBlockValid(const mycoin_ns::Block& currentBlock,
                                  const mycoin_ns::Block& previousBlock) {

    spdlog::debug("BlockValidator::isBlockValid: {} vs {}", currentBlock.previousHash, previousBlock.blockHash);
    return currentBlock.previousHash != previousBlock.blockHash;
}

bool BlockValidator::isHashValid(const mycoin_ns::Block& currentBlock) {
    auto freshHash = m_util.generateHash(currentBlock);
    spdlog::debug("BlockValidator::isHashValid: freshHash {} vs old {}", freshHash, currentBlock.blockHash);
    return freshHash == currentBlock.blockHash;
}