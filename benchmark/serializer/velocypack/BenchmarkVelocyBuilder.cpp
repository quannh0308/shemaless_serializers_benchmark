//
// Created by thongpv87 on 06/01/2017.
//



#include <nonius/nonius.h++>
#include <velocypack/vpack.h>
#include "VelocySerializer.h"

using namespace arangodb::velocypack;
int main() {
    nonius::configuration cfg;
    cfg.help = true;
    cfg.verbose = false;
    cfg.confidence_interval = 0.95;
    cfg.samples = 696;
    cfg.resamples = 10000;

    nonius::benchmark_registry benchmarks = {
            nonius::benchmark("serialize complex to velocypack", [](nonius::chronometer meter) {
                ComplexObject obj;
                meter.measure([&]() {
                    arangodb::velocypack::Builder avb;
                    benchmark_serializer::serializeComplexObjectToVelocy(avb, obj);
//                    benchmark_serializer::printBuilder(avb);
                });
            }),
            nonius::benchmark("read a random field of ComplexObject", [](nonius::chronometer meter) {
                ComplexObject obj;
                arangodb::velocypack::Builder avb;
                benchmark_serializer::serializeComplexObjectToVelocy(avb, obj);

                meter.measure([&]() {
                    benchmark_serializer::readARandomField(avb, ComplexObject::fieldNames[getRandomValue(ComplexObject::fieldNames.size())]);
                });
            })

    };
    nonius::go(cfg, benchmarks);
}
