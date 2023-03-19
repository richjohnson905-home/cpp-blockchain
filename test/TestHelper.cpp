
#include "TestHelper.h"
#include <fstream>

using nlohmann::json;

mycoin_ns::Chain TestHelper::getChain(const std::string& filename) {
    std::ifstream ifs(filename);
    json jf = json::parse(ifs);
    mycoin_ns::Chain myBlockChain = jf;
    return myBlockChain;
}