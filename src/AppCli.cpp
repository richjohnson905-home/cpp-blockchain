
#include "AppCli.h"

AppCli::AppCli(CLI::App* app):m_app(app) {
    m_app->add_option("-a,--amount", m_amount, "Transaction Amount")
        ->required();
    m_app->add_option("-r,--receiver-key", m_receiverKey, "The receiver key for transaction")
        ->required();
    m_app->add_option("-s,--sender-key", m_senderKey, "The sender key for transaction")
        ->required();
    m_app->add_option("-f,--filename", m_filename, "The json chain file")
        ->required();

}