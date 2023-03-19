
#ifndef MYCOIN_MYCOINAPP_H
#define MYCOIN_MYCOINAPP_H


#include "AppCli.h"
#include "MyCoinJson.h"
#include "BlockValidator.h"
#include "BlockchainHelper.h"
#include "Blockchain.h"

class MyCoinApp {
private:
    AppCli* m_cliApp;
    BlockValidator m_validator;
    BlockchainHelper m_blockchainHelper;
    Blockchain m_blockChain;

public:
    explicit MyCoinApp(AppCli* appCli);
    ~MyCoinApp()= default;

    int run();
};


#endif //MYCOIN_MYCOINAPP_H
