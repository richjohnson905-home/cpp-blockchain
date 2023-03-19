
#ifndef MYCOIN_TESTHELPER_H
#define MYCOIN_TESTHELPER_H

#include "nlohmann/json.hpp"
#include "../src/MyCoinJson.h"

class TestHelper {
public:
    mycoin_ns::Chain getChain(const std::string& filename);
};


#endif //MYCOIN_TESTHELPER_H
