
#include "MyCoinJson.h"

using std::string;
using nlohmann::json;

namespace mycoin_ns {
    void from_json(const json& j, TransactionData& i) {
        i.amount = j.value("amount", double(0));
        i.senderKey = j.value("sender-key", string(""));
        i.receiverKey = j.value("receiver-key", string(""));
        i.timestamp = j.value("timestamp", long(0));
    }
    void to_json(json& j, const TransactionData& i) {
        j = json{
                {"amount",   i.amount},
                {"sender-key",   i.senderKey},
                {"receiver-key",   i.receiverKey},
                {"timestamp",   i.timestamp},
        };
    }

    void from_json(const json& j, Block& i) {
        i.index = j.value("index", int(0));
        i.blockHash = j.value("blockHash", size_t(0));
        i.previousHash = j.value("previousHash", size_t(0));
        i.data = j.value("data", TransactionData{});
    }
    void to_json(json& j, const Block& i) {
        j = json{
                {"index", i.index},
                {"blockHash", i.blockHash},
                {"previousHash", i.previousHash},
                {"data", i.data},
        };
    }

    void from_json(const json &j, Chain &c) {
        c.blocks = j.at("blocks").get<vector<Block>>();
    }
    void to_json(json &j, const Chain &c) {
        j = json{
                {"blocks", c.blocks}
        };
    }
}