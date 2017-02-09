//
// Created by thongpv87 on 08/01/2017.
//
#include <flatbuffers/flexbuffers.h>
#include <iostream>
#include "flex_utils.h"
#include "../ComplexObject.h"
#include "SFBSerializer.h"

//#define NONIUS_RUNNER
#include <nonius/nonius.h++>
#include <nonius/main.h++>


const int NUM_KEYS = 1000;


void testSimpleObject() {
    using namespace flexbuffers;
    Builder b(256, kBuilderFlagNone);
    b.Map([&]() {
        b.Int("int", 1);
        b.TypedVector("typedVector", [&](){
            b.UInt(1);
            b.UInt(2);
            b.UInt(3);
        });
        b.String("string", "Hello");
    });
    b.Finish();
    printBuffer(b);
}

void testShareKeysAndStrings() {
    using namespace flexbuffers;
    Builder b(512, kBuilderFlagShareKeysAndStrings);
    b.Map([&]() {
        b.Int("A", 1);
        b.String("B", "string");
        b.Map("C", [&]() {
            b.String("A", "hello"); //share key
            b.String("C", "string"); //share key and share string
        });
    });
    b.Finish();
}

void testShareKeysAndStrings2() {
    using namespace flexbuffers;
    Builder b(4096, kBuilderFlagShareKeysAndStrings);
    b.Map([&]() {
        for (auto i=0; i<NUM_KEYS; i++)
            b.String(std::to_string(i).c_str(), std::to_string(i));

        b.Map(std::to_string(NUM_KEYS).c_str(), [&]() {
            for (auto i=0; i<NUM_KEYS; i++)
                b.String(std::to_string(i).c_str(), std::to_string(i));
        });
    });
    b.Finish();
}

void testShareNone() {
    using namespace flexbuffers;
    Builder c(512, kBuilderFlagNone);
    c.Map([&]() {
        c.Int("A", 1);
        c.String("B", "string");
        c.Map("C", [&]() {
            c.String("A", "hello"); //share key
            c.String("C", "string"); //share key and share string
        });
    });
    c.Finish();
}

void testShareNone2() {
    using namespace flexbuffers;
    Builder b(4096, kBuilderFlagNone);
    b.Map([&]() {
        for (auto i=0; i<NUM_KEYS; i++)
            b.String(std::to_string(i).c_str(), std::to_string(i));

        b.Map(std::to_string(NUM_KEYS).c_str(), [&]() {
            for (auto i=0; i<NUM_KEYS; i++)
                b.String(std::to_string(i).c_str(), std::to_string(i));
        });
    });
    b.Finish();

}

NONIUS_BENCHMARK("share none", [](nonius::chronometer meter) {
    meter.measure([&](){
        testShareNone();
    });
});

//NONIUS_BENCHMARK("share keys and strings", [](nonius::chronometer meter) {
//    meter.measure([&]() {
//        testShareKeysAndStrings();
//    });
//});
//
//NONIUS_BENCHMARK("share none 2", [](nonius::chronometer meter) {
//    meter.measure([&](){
//        testShareNone2();
//    });
//});
//
//NONIUS_BENCHMARK("share keys and strings 2", [](nonius::chronometer meter) {
//    meter.measure([&]() {
//        testShareKeysAndStrings2();
//    });
//});

int main() {
    ComplexObject obj;
    flexbuffers::Builder b;
}