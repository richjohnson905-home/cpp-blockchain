message(STATUS "Building MyCoin core library")

set(mycoin_SRCS
        MyCoinJson.cpp
        Blockchain.cpp
        AppCli.cpp
        MyCoinApp.cpp
        BlockValidator.cpp
        BlockchainHelper.cpp
        BlockUtil.cpp)

add_library(mycoinlib STATIC
        ${mycoin_SRCS}
        )

target_include_directories(mycoinlib PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        )

target_link_libraries(mycoinlib
        ${CONAN_LIBS}
        )