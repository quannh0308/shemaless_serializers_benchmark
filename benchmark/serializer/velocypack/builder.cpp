//
// Created by thongpv87 on 07/01/2017.
// BECHMARK VELOCYPACK BUILDER SPEED
//

//using nonius microbechmark lib
#include <nonius/nonius.h++>
//using nonius main function
#define NONIUS_RUNNER
#include <nonius/main.h++>
#include <velocypack/vpack.h>

NONIUS_BENCHMARK("VELOCYPACK build SimpleObject", [](nonius::chronometer meter) {
    using namespace arangodb::velocypack;

    meter.measure([&] {
        Builder b;
        b.add(Value(ValueType::Object));
        b.add("b", Value(12));
        b.add("a", Value(true));
        b.add("l", Value(ValueType::Array));
        b.add(Value(1));
        b.add(Value(2));
        b.add(Value(3));
        b.close();
        b.add("name", Value("thongpv87"));
        b.close();
    });
});

