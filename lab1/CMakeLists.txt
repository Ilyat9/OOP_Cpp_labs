cmake_minimum_required(VERSION 3.10)
project(first_lab)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.0
  TLS_VERIFY false
)
if (MSVC)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()
FetchContent_MakeAvailable(googletest)

add_executable(lab
    main.cpp
    src/days.cpp
)
target_include_directories(lab PRIVATE include)

enable_testing()

add_executable(count_days_test
    test/main_test.cpp
    test/days_test.cpp
    src/days.cpp
)
target_include_directories(days_test PRIVATE include)
target_link_libraries(days_test gtest_main)

add_test(NAME DaysTests COMMAND days_test)
