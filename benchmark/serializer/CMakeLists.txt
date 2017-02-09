set(FLEXBUFFERS_BENCHMARK_SRCs
        flexbuffers/BechmarkFlexbuffers.cpp)

set(VELOCYPACK_BENCHMARK_SRCs
        velocypack/BenchmarkVelocyBuilder.cpp)

set(MPACK_BECHMARK_SRCs
        mpack/BenchmarkMPack.cpp mpack/MPackSerializer.h)

set(ION_BENCHMARK_SRCs
        ion/BenchmarkION.cpp)


add_executable(flexbuffers_benchmark ${FLEXBUFFERS_BENCHMARK_SRCs})
target_include_directories(flexbuffers_benchmark PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${NONIUS_INCLUDE} ${FLATBUFFERS_INCLUDE})
target_link_libraries(flexbuffers_benchmark PRIVATE flatbuffers pthread)


add_executable(velocypack_benchmark ${VELOCYPACK_BENCHMARK_SRCs})
target_include_directories(velocypack_benchmark PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${NONIUS_INCLUDE} ${FLATBUFFERS_INCLUDE})
target_link_libraries(velocypack_benchmark PRIVATE velocypack pthread)


add_executable(mpack_bechmark ${MPACK_BECHMARK_SRCs})
target_include_directories(mpack_bechmark PRIVATE ${MPACK_INCLUDE} ${NONIUS_INCLUDE} ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(mpack_bechmark PRIVATE ${MPACK_LIB} pthread)

# Quan Nguyen Hoang - MsgPack test - add to FlameGraph to detect slowness
add_executable(test_mpack_builder mpack/TestMsgPackBuilder.cpp)
target_include_directories(test_mpack_builder PRIVATE ${MPACK_INCLUDE} ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(test_mpack_builder PRIVATE ${MPACK_LIB} pthread)


add_executable(ion_benchmark ${ION_BENCHMARK_SRCs})
target_link_libraries(ion_benchmark PRIVATE ionc)

# ThongPV3 - CBOR nearly official lib
#add_executable(cbor_benchmark libcbor/BenchmarkCBOR.cpp)
#target_include_directories(cbor_benchmark PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${LIBCBOR_INCLUDE} ${NONIUS_INCLUDE})
#target_link_libraries(cbor_benchmark PRIVATE cbor pthread)
#set_target_properties(cbor_benchmark PROPERTIES INTERPROCEDURAL_OPTIMIZATION True)

# Quan Nguyen Hoang - CBOR lib replacement
add_executable(tinycbor_benchmark tinycbor/BenchmarkCBOR.cpp)
target_include_directories(tinycbor_benchmark PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${LIBCBOR_INCLUDE} ${NONIUS_INCLUDE})
#target_link_libraries(tinycbor_benchmark PRIVATE cbor pthread)
target_link_libraries(tinycbor_benchmark PRIVATE pthread)
set_target_properties(tinycbor_benchmark PROPERTIES INTERPROCEDURAL_OPTIMIZATION True)


# Quan Nguyen Hoang - CBOR test - add to FlameGraph to detect slowness
add_executable(test_tinyCBOR_builder tinycbor/TestTinyCBORBuilder.cpp)
target_include_directories(test_tinyCBOR_builder PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${LIBCBOR_INCLUDE})


#temp executable
add_executable(test_flexbuffers_api flexbuffers/TestFlexbuffersAPI.cpp)
target_include_directories(test_flexbuffers_api PRIVATE ${FLATBUFFERS_INCLUDE} ${NONIUS_INCLUDE})
target_link_libraries(test_flexbuffers_api PRIVATE flatbuffers pthread)

#temp executable
add_executable(test_velocy_builder velocypack/TestBuilder.cpp)
target_include_directories(test_velocy_builder PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(test_velocy_builder PRIVATE velocypack)