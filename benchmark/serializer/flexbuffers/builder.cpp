//
// Created by thongpv87 on 07/01/2017.
// BECHMARK FLEXBUFFER SPEED
//

//include nonius header
#include <nonius/nonius.h++>
//using existed main
#define NONIUS_RUNNER

#include <nonius/main.h++>
#include <flatbuffers/flexbuffers.h>

NONIUS_BENCHMARK("FLEXBUFFERS build SimpleObject - 128, shareNone", [](nonius::chronometer meter) {
    meter.measure([&]() {
        flexbuffers::Builder builder(128, flexbuffers::kBuilderFlagNone);
        builder.Map([&]() {
            builder.Int("b", 12);

            builder.Bool("a", true);

            builder.TypedVector("l", [&]() {
                builder.Int(1);
                builder.Int(2);
                builder.Int(3);
            });

            builder.String("name", "thongpv87");
        });
        builder.Finish();
    });
});

//NONIUS_BENCHMARK("FLEXBUFFERS build SimpleObject - 512, shareKeyandString", [](nonius::chronometer meter) {
//    meter.measure([&]() {
//        flexbuffers::Builder builder(512, flexbuffers::kBuilderFlagShareKeysAndStrings);
//        builder.Map([&]() {
//            builder.Int("b", 12);
//
//            builder.Bool("a", true);
//
//            builder.TypedVector("l", [&]() {
//                builder.Int(1);
//                builder.Int(2);
//                builder.Int(3);
//            });
//
//            builder.String("name", "thongpv87");
//        });
//        builder.Finish();
//    });
//});

