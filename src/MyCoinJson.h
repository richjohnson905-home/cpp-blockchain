
#ifndef MYCOIN_MYCOINJSON_H
#define MYCOIN_MYCOINJSON_H

#include "nlohmann/json.hpp"

namespace mycoin_ns {
    using json = nlohmann::json;
    using std::vector;
    using std::string;

    struct TransactionData {
        double amount;
        string senderKey;
        string receiverKey;
        long timestamp;
    };
    void to_json(json& j, const TransactionData& i);
    void from_json(const json& j, TransactionData& i);

    struct Block {
        int index;
        size_t blockHash;
        size_t previousHash;
        TransactionData data;
    };
    void to_json(json& j, const Block& i);
    void from_json(const json& j, Block& i);

    struct Chain {
        vector<Block> blocks;
    };
    void to_json(json& j, const Chain& i);
    void from_json(const json& j, Chain& i);
}

#endif //MYCOIN_MYCOINJSON_H
