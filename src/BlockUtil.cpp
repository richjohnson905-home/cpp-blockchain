
#include "BlockUtil.h"

size_t BlockUtil::generateHash(const mycoin_ns::Block& myCoinBlock) {
    std::hash<std::string> hash1;
    std::hash<size_t> hash2;
    std::hash<size_t> finalHash;
    std::string toHash = std::to_string(myCoinBlock.data.amount) +
            myCoinBlock.data.receiverKey +
            myCoinBlock.data.senderKey +
            std::to_string(myCoinBlock.data.timestamp);

    return finalHash(hash1(toHash) + hash2(myCoinBlock.previousHash));
}