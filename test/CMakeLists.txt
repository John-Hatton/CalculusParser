project(Google_Tests)

file(GLOB_RECURSE TEST_SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable(CalculusParser_Tests 
    ${TEST_SOURCE_FILES}
)

target_link_libraries(CalculusParser_Tests CalculusParser gtest gtest_main)