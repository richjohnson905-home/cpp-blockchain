
#ifndef MYCOIN_BLOCKVALIDATOR_H
#define MYCOIN_BLOCKVALIDATOR_H


#include "MyCoinJson.h"
#include "BlockUtil.h"
#include <vector>

class BlockValidator {
public:
    virtual std::vector<mycoin_ns::Block> validateChain(const mycoin_ns::Chain& chain);

private:
    BlockUtil m_util;

    bool isBlockValid(const mycoin_ns::Block& currentBlock,
                      const mycoin_ns::Block& previousBlock);

    bool isHashValid(const mycoin_ns::Block& myCoinBlock);
};


#endif //MYCOIN_BLOCKVALIDATOR_H
