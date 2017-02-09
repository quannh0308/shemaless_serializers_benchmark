//
// Created by Quan Nguyen Hoang on 2/8/17.
//

#include <iostream>
#include <zconf.h>
#include "../ComplexObject.h"
#include "CBORSerializer.h"

int main() {
    sleep(1);
    std::cout << "Hello" << std::endl;
    ComplexObject obj;
    for(int i = 0; i < 100; i++) {
        benchmark_serializer::serializeComplexObjectToTinyCBOR(obj);
    }
}