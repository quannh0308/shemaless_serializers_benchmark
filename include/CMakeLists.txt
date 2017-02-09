add_subdirectory(flatbuffers)
set(FLATBUFFERS_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/flatbuffers/include PARENT_SCOPE)

set(NONIUS_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/nonius/include PARENT_SCOPE)

add_subdirectory(velocypack)
set(VELOCYPACK_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/velocypack PARENT_SCOPE)

#add_subdirectory(seastar)
#set(SEASTAR_INCLUDE ${SEASTAR_INCLUDE} PARENT_SCOPE)
#set(SEASTAR_LIB ${SEASTAR_LIB} PARENT_SCOPE)

add_subdirectory(mpack)
set(MPACK_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/mpack/src PARENT_SCOPE)
set(MPACK_LIB ${MPACK_LIB} PARENT_SCOPE)

add_subdirectory(msgpack)
set(MSGPACK_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/msgpack/include)

add_subdirectory(benchmark)
set(GOOGLE_BENCHMARK_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/benchmark/include)

#add_subdirectory(ion-c)


# ThongPV - libcbor - ALTERNATIVE
#add_subdirectory(libcbor)
#set(LIBCBOR_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/libcbor/src PARENT_SCOPE)

# Quan Nguyen Hoang - tinycbor - ALTERNATIVE
#add_subdirectory(tinycbor)
set(LIBCBOR_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/tinycbor/src PARENT_SCOPE)