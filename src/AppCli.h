
#include "CLI/CLI.hpp"

#ifndef MYCOIN_APPCLI_H
#define MYCOIN_APPCLI_H


class AppCli {
private:
    CLI::App* m_app{};
    double m_amount;
    std::string m_receiverKey;
    std::string m_senderKey;
    std::string m_filename;

public:
    explicit AppCli(CLI::App* app);

    double getAmount(){return m_amount;}
    std::string getReceiverKey(){return m_receiverKey;}
    std::string getSenderKey(){return m_senderKey;}
    std::string getFilename(){return m_filename;}
};


#endif //MYCOIN_APPCLI_H
