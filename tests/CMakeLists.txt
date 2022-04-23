
find_package(GTest CONFIG REQUIRED)
include(GoogleTest)

add_executable(SdtsUnitTest
    test.cpp
    TestInputSignal.cpp)
target_compile_features(SdtsUnitTest INTERFACE cxx_std_17)

target_compile_options(SdtsUnitTest PRIVATE -Wall -Wextra -pedantic -Werror)

target_link_libraries(SdtsUnitTest PRIVATE GTest::gtest_main GTest::gtest sdts)
gtest_discover_tests(SdtsUnitTest)
