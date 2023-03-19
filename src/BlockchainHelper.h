
#ifndef MYCOIN_BLOCKCHAINHELPER_H
#define MYCOIN_BLOCKCHAINHELPER_H

#include "MyCoinJson.h"
#include "BlockUtil.h"
#include <vector>

class BlockchainHelper {
private:
    BlockUtil m_util;

public:
    virtual mycoin_ns::Block createGenesisBlock();
    virtual mycoin_ns::Chain loadChain(const std::string& filename);

    virtual mycoin_ns::Block createBlock(const mycoin_ns::TransactionData &data, int index, size_t prevHash);

    virtual void writeChain(const mycoin_ns::Chain& chain, const std::string& filename);

};


#endif //MYCOIN_BLOCKCHAINHELPER_H
