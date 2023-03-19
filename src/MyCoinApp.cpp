
#include "MyCoinApp.h"
#include "Blockchain.h"
#include "spdlog/spdlog.h"

MyCoinApp::MyCoinApp(AppCli *appCli): 
    m_cliApp(appCli), 
    m_blockChain(&m_validator, &m_blockchainHelper) {

}

int MyCoinApp::run() {
    spdlog::info("MyCoinApp::run");
    std::vector<mycoin_ns::Block> mycoinChain;
    try {
        m_blockChain.initAndValidate(m_cliApp->getFilename(), mycoinChain);
    } catch (const std::exception& ex) {
        std::cerr << "Chain Corrupt: " << ex.what() << std::endl;
        return 1;
    }

    m_blockChain.handleTransaction(m_cliApp->getAmount(),
                                   m_cliApp->getReceiverKey(),
                                   m_cliApp->getSenderKey(),
                                   mycoinChain);

    m_blockChain.writeChain(m_cliApp->getFilename(), mycoinChain);

    return 0;
}