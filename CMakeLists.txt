# CMake configuration for demo project
cmake_minimum_required(VERSION 3.16)
project(eel-collector-CandidateTemplate LANGUAGES CXX)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

link_libraries(stdc++fs)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  main  main.cpp File.cpp DataCollector.cpp
)

add_executable(
 unit_testing Testing/mainTest.cpp Testing/regexTest.cpp Util.cpp File.cpp Testing/fileTest.cpp Testing/collectorTest.cpp DataCollector.cpp
)

add_executable(
  component_testing Testing/componentTest File.cpp DataCollector.cpp
)
target_link_libraries(
  unit_testing
  gtest_main
)

target_link_libraries(
  component_testing
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(unit_testing)
gtest_discover_tests(component_testing)
