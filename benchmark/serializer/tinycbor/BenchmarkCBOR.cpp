//
// Created by Quan Nguyen Hoang on 2/6/17.
//

#include <iostream>
#include "CBORSerializer.h"
#include <nonius/nonius.h++>
int main() {
    nonius::configuration cfg;
    cfg.help = true;
    cfg.verbose = false;
    cfg.confidence_interval = 0.95;
    cfg.samples = 696;
    cfg.resamples = 10000;

    nonius::benchmark_registry benchmarks = {
            nonius::benchmark("serialize ComplexObject to CBOR by TinyCBOR", [](nonius::chronometer meter) {
                ComplexObject obj;
                meter.measure([&]() {
                    benchmark_serializer::serializeComplexObjectToTinyCBOR(obj);
                });
            })
    };
    nonius::go(cfg, benchmarks);
}