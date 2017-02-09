//
// Created by thongpv87 on 08/01/2017.
//

#pragma once

#include <flatbuffers/flexbuffers.h>
void printBuffer(flexbuffers::Builder& builder) {
    for (size_t i = 0; i < builder.GetBuffer().size(); i++)
        printf("%d ", builder.GetBuffer().data()[i]);
    printf("\n");
}