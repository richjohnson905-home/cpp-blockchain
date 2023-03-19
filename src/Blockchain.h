
#ifndef MYCOIN_BLOCKCHAIN_H
#define MYCOIN_BLOCKCHAIN_H

#include "MyCoinJson.h"
#include "BlockValidator.h"
#include "BlockchainHelper.h"
#include <vector>

class Blockchain {
private:
    BlockValidator* m_validator;
    BlockchainHelper *m_helper;

public:
    Blockchain(BlockValidator* validator, BlockchainHelper* helper);

    void initAndValidate(const std::string& filename,
                         std::vector<mycoin_ns::Block>& mycoinChain);
    void handleTransaction(double amount,
                           const std::string &receiver,
                           const std::string &sender,
                           std::vector<mycoin_ns::Block>& mycoinChain);
    void writeChain(const std::string& filename,
                    const std::vector<mycoin_ns::Block>& mycoinChain);
};


#endif //MYCOIN_BLOCKCHAIN_H
