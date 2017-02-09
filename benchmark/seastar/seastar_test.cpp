//
// Created by thongpv87 on 07/01/2017.
//

#define NONIUS_RUNNER
#include <nonius/nonius.h++>
#include <nonius/main.h++>
#include <core/sstring.hh>
#include <core/app-template.hh>
#include <core/reactor.hh>
//NONIUS_BENCHMARK("test sstring", [](nonius::chronometer meter) {
//    meter.measure([]() {
//        sstring a = "Hello";
//        std::cout << a << std::endl;
//    });
//});

NONIUS_BENCHMARK("test future", [](nonius::chronometer meter) {
    int i = 0;
    meter.measure([&i]() {
        app_template app;
        ++i;
        std::cout << i << ": Numbers of core " << smp::count << std::endl;
        sleep(1);
        return make_ready_future();
    });
});