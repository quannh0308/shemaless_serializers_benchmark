set(MPACK_LIB mpack)

set(MPACK_HEADERS src/mpack/mpack.h
        src/mpack/mpack-common.h
        src/mpack/mpack-expect.h
        src/mpack/mpack-node.h
        src/mpack/mpack-platform.h
        src/mpack/mpack-reader.h
        src/mpack/mpack-writer.h
        src/mpack/mpack-common.h)

set(MPACK_SRCs src/mpack/mpack-writer.c
        src/mpack/mpack-reader.c
        src/mpack/mpack-platform.c
        src/mpack/mpack-node.c
        src/mpack/mpack-expect.c
        src/mpack/mpack-common.c)

add_library(${MPACK_LIB} STATIC  ${MPACK_SRCs} ${MPACK_HEADERS})
target_include_directories(${MPACK_LIB} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(MPACK_LIB ${MPACK_LIB} PARENT_SCOPE)