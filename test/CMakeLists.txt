message(STATUS "Building Unit Tests ${UNITTEST}")

set(mycoin_SRCS
        ../src/MyCoinJson.cpp
        ../src/Blockchain.cpp
        ../src/AppCli.cpp
        ../src/MyCoinApp.cpp
        ../src/BlockValidator.cpp
        ../src/BlockchainHelper.cpp
        ../src/BlockUtil.cpp)

set(mycoin_ut_SRCS
        ${mycoin_SRCS}
        main.cpp
        BlockchainTest.cpp
        TestHelper.cpp
        BlockValidatorTest.cpp)

set(mycoin_uat_SRCS
        ${mycoin_SRCS}
        main.cpp
        TestHelper.cpp
        UatScenarioTest.cpp)

add_executable(BlockchainTest ${mycoin_ut_SRCS})
target_link_libraries(BlockchainTest ${CONAN_LIBS} )
add_test(NAME BlockchainTest COMMAND BlockchainTest WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(UatScenarioTest ${mycoin_uat_SRCS})
target_link_libraries(UatScenarioTest ${CONAN_LIBS} )
add_test(NAME UatScenarioTest COMMAND UatScenarioTest WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

set_property(GLOBAL PROPERTY CTEST_TARGETS_ADDED 1)
enable_testing()