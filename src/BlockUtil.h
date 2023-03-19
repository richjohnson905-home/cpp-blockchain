
#ifndef MYCOIN_BLOCKUTIL_H
#define MYCOIN_BLOCKUTIL_H

#include "MyCoinJson.h"

class BlockUtil {
public:
    size_t generateHash(const mycoin_ns::Block& myCoinBlock);
};


#endif //MYCOIN_BLOCKUTIL_H
