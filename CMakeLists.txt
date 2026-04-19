cmake_minimum_required(VERSION 3.24)
project(CalculusParser)

set(CMAKE_CXX_STANDARD 23)

include_directories(include/CalculusParserApi)
add_subdirectory(source)
add_subdirectory(test)

#
##
#
########
#
##
#

###################
#					#
#    Google Test	#
#					#
###################



include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.17.0 # most recent version 04/2026 Check GITHUB!
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

#
##
#
########
#
##
#
