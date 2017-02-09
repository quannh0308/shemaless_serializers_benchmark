//
// Created by thongpv87 on 06/01/2017.
//

#include <nonius/nonius.h++>
#include <flatbuffers/flexbuffers.h>
#include "SFBSerializer.h"
#include "flex_utils.h"

using namespace std::chrono;

int main() {
    nonius::configuration cfg;
    cfg.help = true;
    cfg.verbose = false;
    cfg.confidence_interval = 0.95;
    cfg.samples = 696;
    cfg.resamples = 10000;

    nonius::benchmark_registry benchmarks = {
            nonius::benchmark("serialize_ComplexObject_to_flexbuffer", [](nonius::chronometer meter) {
                ComplexObject obj;

                meter.measure([&]() {
                    flexbuffers:: Builder builder(1024, flexbuffers::kBuilderFlagNone);
                    benchmark_serializer::serializeComplexObject(builder, obj);
                });
            }),
            nonius::benchmark("read_a_random_field_from_ComplexObject_in_flexbuffer", [](nonius::chronometer meter) {
                ComplexObject obj;
                flexbuffers::Builder builder;
                benchmark_serializer::serializeComplexObject(builder, obj);
                meter.measure([&]() {
                        benchmark_serializer::readARandomField(ComplexObject::fieldNames[getRandomValue(ComplexObject::fieldNames.size())], builder.GetBuffer());
                });
            })
    };
    nonius::go(cfg, benchmarks);
}
