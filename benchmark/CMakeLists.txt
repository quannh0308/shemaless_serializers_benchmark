OPTION(ENABLE_SERIALIZER_BENCHMARK "Enable serializer benchmark" ON)
OPTION(ENABLE_SEASTAR_BENCHMARK "Enable seastar benchmark" ON)




if (ENABLE_SERIALIZER_BENCHMARK)
    add_subdirectory(serializer)
endif()

if (ENABLE_SEASTAR_BENCHMARK)
    add_subdirectory(seastar)
endif()