cmake_minimum_required(VERSION 3.28)
project(CMakeProject LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 选项：是否构建为共享库，共享库设为 ON；静态库设为 OFF
# option(BUILD_SHARED_LIBS "Build libraries as shared" OFF)

add_executable(main src/main.cpp)
target_compile_features(main PRIVATE cxx_std_17)

# 测试 & 打包
enable_testing()
add_test(NAME SmokeTest
         COMMAND main
         WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
set_tests_properties(SmokeTest PROPERTIES
  TIMEOUT 15
)

set(CPACK_PACKAGE_NAME "TextAttribute-Linux")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_VENDOR "HDU")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Text-Attribute-Linux")
set(CPACK_PACKAGE_CONTACT "contact@example.com")
include(CPack)