
This c++ simple example of a blockchain is from a youtube demo using javascript: https://www.youtube.com/watch?v=zVqczFZr124

It is a very simple implementation that shows the basics for blockchains that maintain relationship from a hash of previous block as part of the current block.

The chain is stored in a json file for convenience.

Build System Requirements (MacOS)
-------------------------

    pip install conan       (package management)
    brew install cmake      (build system)

Usage
------

    MyCoin Cli App Parser
    Usage: ./bin/MyCoin [OPTIONS]
    
    Options:
        -h,--help                   Print this help message and exit
        -a,--amount FLOAT REQUIRED  Transaction Amount
        -r,--receiver-key TEXT REQUIRED
                                  The receiver key for transaction
        -s,--sender-key TEXT REQUIRED
                                  The sender key for transaction
        -f,--filename TEXT REQUIRED The json chain file

Conanfile Dependencies
---------------------------
Conan Dependencies | Description
--- | ---
catch2 | unit testing framework
fakeit | simple mocking framework
cli11 | command line parser
nlohmann_json | JSON for Modern C++

Build
------

    git clone https://gitlab.wwt.com/Rich.Johnson/cpp-blockchain.git mycoin
    cd mycoin
    mkdir cmake-build-debug
    cd cmake-build-debug
    conan install ../conanfile.txt
    cmake ..
    cmake --build .
    ctest

Smoke Test
------------
Exercising the validation. Run a few commands to build the chain and then:

1. For single block validation edit any of the json values in the block that make the hash (TransactionData fields).
2. For current-block with previous-block validation, remove a whole blocks or edit block hashes.
3. Assert that the correct errors are reported.


    ./bin/MyCoin -a 3 -r Joe -s Steve -f mycoin.json
    ./bin/MyCoin --amount 3 --receiver-key Joe --sender-key Steve --filename mycoin.json