
find_package(GTest CONFIG REQUIRED)
include(GoogleTest)

add_executable(SdtsUnitTest test.cpp)
target_compile_features(sdts INTERFACE cxx_std_17)


target_link_libraries(SdtsUnitTest PRIVATE GTest::gtest_main GTest::gtest sdts)
gtest_discover_tests(SdtsUnitTest)
