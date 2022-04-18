
add_executable(SdtsUnitTest test.cpp)

target_link_libraries(SdtsUnitTest PRIVATE GTest::gtest_main GTest::gtest sdts)