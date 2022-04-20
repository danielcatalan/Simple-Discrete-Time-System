
find_package(GTest CONFIG REQUIRED)
include(GoogleTest)
add_executable(SdtsUnitTest test.cpp)

set_property(TARGET SdtsUnitTest PROPERTY CXX_STANDARD 14)

target_link_libraries(SdtsUnitTest PRIVATE GTest::gtest_main GTest::gtest sdts)
gtest_discover_tests(SdtsUnitTest)
