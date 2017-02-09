find_package(Boost REQUIRED)
set(TEST_SEASTAR_SRCs
        seastar_test.cpp)
add_executable(seastar_test ${TEST_SEASTAR_SRCs})
target_include_directories(seastar_test PRIVATE ${SEASTAR_INCLUDE} ${NONIUS_INCLUDE})
target_link_libraries(seastar_test PRIVATE pthread fmt-header-only boost_system ${SEASTAR_LIB})