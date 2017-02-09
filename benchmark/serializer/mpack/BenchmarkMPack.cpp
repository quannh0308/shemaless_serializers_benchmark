//
// Created by thongpv3 on 12/01/2017.
//
#include <nonius/nonius.h++>
#include "MPackSerializer.h"


int main() {
    nonius::configuration cfg;
    cfg.help = true;
    cfg.verbose = false;
    cfg.confidence_interval = 0.95;
    cfg.samples = 696;
    cfg.resamples = 10000;

    nonius::benchmark_registry benchmarks = {
            nonius::benchmark("serialize ComplexObject to MsgPack by MPack", [](nonius::chronometer meter) {
                ComplexObject obj;
                meter.measure([&]() {
                    char* data;
                    size_t size;
                    benchmark_serializer::serializeComplexObjectToMsgPackByMPack(obj, &data, &size);
                    MPACK_FREE(data);
                });
            }),
            nonius::benchmark("get a random field from Complex Object in MsgPack by MPack", [](nonius::chronometer meter) {
                ComplexObject obj;
                char* data;
                size_t size;
                benchmark_serializer::serializeComplexObjectToMsgPackByMPack(obj, &data, &size);
                meter.measure([&]() {
                    benchmark_serializer::readRandomFieldOfComplexObjectInMsgPackBuffer(ComplexObject::fieldNames[getRandomValue(ComplexObject::fieldNames.size())], data, size);
                });
            })
    };
    nonius::go(cfg, benchmarks);
}