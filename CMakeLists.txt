cmake_minimum_required(VERSION 3.10)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

set(src
  src/nn/vector.c
  src/nn/string_set.c
  src/nn/log.c
  )


set(test_src
  test/nn/vector_test.cpp
  test/nn/string_set_test.cpp
  test/nn/log_test.cpp
  test/unit_test.cpp

  )

add_library(nn "${src}")
target_include_directories(nn PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(nn_test "${test_src}")
target_link_libraries(nn_test ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} nn)
target_compile_definitions(nn_test PRIVATE -DBOOST_TEST_DYN_LINK)
