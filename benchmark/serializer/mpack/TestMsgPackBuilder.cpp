//
// Created by Quan Nguyen Hoang on 2/8/17.
//

#include <zconf.h>
#include <iostream>
#include "MPackSerializer.h"

int main() {
    sleep(1);
    std::cout << "Hello" << std::endl;
    ComplexObject obj;

    for(int i = 0; i < 100; i++) {
        char* data;
        size_t size;
        benchmark_serializer::serializeComplexObjectToMsgPackByMPack(obj, &data, &size);
    }
}