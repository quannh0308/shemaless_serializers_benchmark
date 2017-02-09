//
// Created by Quan Nguyen Hoang on 1/6/17.
//


#include "../ComplexObject.h"

namespace benchmark_serializer {

    void serializeComplexObject(flexbuffers::Builder& b, const ComplexObject& obj) {
        b.Map([&]() {
            b.UInt("longFieldName_485u81", obj.longFieldName_485u81);
            b.UInt("longFieldName_196u82", obj.longFieldName_196u82);
            b.UInt("longFieldName_584u83", obj.longFieldName_584u83);
            b.UInt("longFieldName_173u84", obj.longFieldName_173u84);
            b.UInt("longFieldName_873u85", obj.longFieldName_873u85);
            b.UInt("longFieldName_494u321", obj.longFieldName_494u321);
            b.UInt("longFieldName_137u322", obj.longFieldName_137u322);
            b.UInt("longFieldName_664u323", obj.longFieldName_664u323);
            b.UInt("longFieldName_871u324", obj.longFieldName_871u324);
            b.UInt("longFieldName_142u325", obj.longFieldName_142u325);
            b.UInt("longFieldName_221u161", obj.longFieldName_221u161);
            b.UInt("longFieldName_115u162", obj.longFieldName_115u162);
            b.UInt("longFieldName_212u163", obj.longFieldName_212u163);
            b.UInt("longFieldName_585u164", obj.longFieldName_585u164);
            b.UInt("longFieldName_012u165", obj.longFieldName_012u165);
            b.UInt("longFieldName_141u641", obj.longFieldName_141u641);
            b.UInt("longFieldName_665u642", obj.longFieldName_665u642);
            b.UInt("longFieldName_988u643", obj.longFieldName_988u643);
            b.UInt("longFieldName_774u644", obj.longFieldName_774u644);
            b.UInt("longFieldName_004u645", obj.longFieldName_004u645);

            b.String("longFieldName_332s1", obj.longFieldName_332s1);
            b.String("longFieldName_421s2", obj.longFieldName_421s2);
            b.String("longFieldName_687s3", obj.longFieldName_687s3);
            b.String("longFieldName_978s4", obj.longFieldName_978s4);
            b.String("longFieldName_325s5", obj.longFieldName_325s5);
            b.String("longFieldName_452ms1", obj.longFieldName_452ms1);
            b.String("longFieldName_661ms2", obj.longFieldName_661ms2);
            b.String("longFieldName_148ms3", obj.longFieldName_148ms3);
            b.String("longFieldName_213ms4", obj.longFieldName_213ms4);
            b.String("longFieldName_644ms5", obj.longFieldName_644ms5);
            b.String("longFieldName_989ls1", obj.longFieldName_989ls1);
            b.String("longFieldName_112ls2", obj.longFieldName_112ls2);
            b.String("longFieldName_210ls3", obj.longFieldName_210ls3);
            b.String("longFieldName_222ls4", obj.longFieldName_222ls4);
            b.String("longFieldName_748ls5", obj.longFieldName_748ls5);

            b.Map("longFieldName_656o1", [&]() {
                b.UInt("id", obj.longFieldName_656o1.id);
                b.String("name", obj.longFieldName_656o1.name);

                b.TypedVector("data", [&]() {
                    for (size_t i = 0; i<obj.longFieldName_656o1.data.size(); i++) {
                        b.UInt(obj.longFieldName_656o1.data[i]);
                    }
                });
            });
            b.Map("longFieldName_664o2", [&]() {
                b.UInt("id", obj.longFieldName_664o2.id);
                b.String("name", obj.longFieldName_664o2.name);

                b.TypedVector("data", [&]() {
                    for (size_t i = 0; i<obj.longFieldName_664o2.data.size(); i++) {
                        b.UInt(obj.longFieldName_664o2.data[i]);
                    }
                });
            });
            b.Map("longFieldName_141o3", [&]() {
                b.UInt("id", obj.longFieldName_141o3.id);
                b.String("name", obj.longFieldName_141o3.name);

                b.TypedVector("data", [&]() {
                    for (size_t i = 0; i<obj.longFieldName_141o3.data.size(); i++) {
                        b.UInt(obj.longFieldName_141o3.data[i]);
                    }
                });
            });
            b.Map("longFieldName_215o4", [&]() {
                b.UInt("id", obj.longFieldName_215o4.id);
                b.String("name", obj.longFieldName_215o4.name);

                b.TypedVector("data", [&]() {
                    for (size_t i = 0; i<obj.longFieldName_215o4.data.size(); i++) {
                        b.UInt(obj.longFieldName_215o4.data[i]);
                    }
                });
            });
            b.Map("longFieldName_521o5", [&]() {
                b.UInt("id", obj.longFieldName_521o5.id);
                b.String("name", obj.longFieldName_521o5.name);

                b.TypedVector("data", [&]() {
                    for (size_t i = 0; i<obj.longFieldName_521o5.data.size(); i++) {
                        b.UInt(obj.longFieldName_521o5.data[i]);
                    }
                });
            });
            b.Map("longFieldName_674o6", [&]() {
                b.UInt("id", obj.longFieldName_674o6.id);
                b.String("name", obj.longFieldName_674o6.name);

                b.TypedVector("data", [&]() {
                    for (size_t i = 0; i<obj.longFieldName_674o6.data.size(); i++) {
                        b.UInt(obj.longFieldName_674o6.data[i]);
                    }
                });
            });
            b.Map("longFieldName_668o7", [&]() {
                b.UInt("id", obj.longFieldName_668o7.id);
                b.String("name", obj.longFieldName_668o7.name);

                b.TypedVector("data", [&]() {
                    for (size_t i = 0; i<obj.longFieldName_668o7.data.size(); i++) {
                        b.UInt(obj.longFieldName_668o7.data[i]);
                    }
                });
            });
            b.Map("longFieldName_913o8", [&]() {
                b.UInt("id", obj.longFieldName_913o8.id);
                b.String("name", obj.longFieldName_913o8.name);

                b.TypedVector("data", [&]() {
                    for (size_t i = 0; i<obj.longFieldName_913o8.data.size(); i++) {
                        b.UInt(obj.longFieldName_913o8.data[i]);
                    }
                });
            });
            b.Map("longFieldName_206o9", [&]() {
                b.UInt("id", obj.longFieldName_206o9.id);
                b.String("name", obj.longFieldName_206o9.name);

                b.TypedVector("data", [&]() {
                    for (size_t i = 0; i<obj.longFieldName_206o9.data.size(); i++) {
                        b.UInt(obj.longFieldName_206o9.data[i]);
                    }
                });
            });
            b.Map("longFieldName_877o10", [&]() {
                b.UInt("id", obj.longFieldName_877o10.id);
                b.String("name", obj.longFieldName_877o10.name);

                b.TypedVector("data", [&]() {
                    for (size_t i = 0; i<obj.longFieldName_877o10.data.size(); i++) {
                        b.UInt(obj.longFieldName_877o10.data[i]);
                    }
                });
            });


            b.TypedVector("longFieldName_171a81", [&]() {
                for(size_t i=0; i<obj.longFieldName_171a81.size(); i++) {
                    b.UInt(obj.longFieldName_171a81[i]);
                }
            });
            b.TypedVector("longFieldName_164a82", [&]() {
                for(size_t i=0; i<obj.longFieldName_164a82.size(); i++) {
                    b.UInt(obj.longFieldName_164a82[i]);
                }
            });
            b.TypedVector("longFieldName_197a83", [&]() {
                for(size_t i=0; i<obj.longFieldName_197a83.size(); i++) {
                    b.UInt(obj.longFieldName_197a83[i]);
                }
            });
            b.TypedVector("longFieldName_323a84", [&]() {
                for(size_t i=0; i<obj.longFieldName_323a84.size(); i++) {
                    b.UInt(obj.longFieldName_323a84[i]);
                }
            });
            b.TypedVector("longFieldName_311a85", [&]() {
                for(size_t i=0; i<obj.longFieldName_311a85.size(); i++) {
                    b.UInt(obj.longFieldName_311a85[i]);
                }
            });
            b.TypedVector("longFieldName_847a161", [&]() {
                for(size_t i=0; i<obj.longFieldName_847a161.size(); i++) {
                    b.UInt(obj.longFieldName_847a161[i]);
                }
            });
            b.TypedVector("longFieldName_852a162", [&]() {
                for(size_t i=0; i<obj.longFieldName_852a162.size(); i++) {
                    b.UInt(obj.longFieldName_852a162[i]);
                }
            });
            b.TypedVector("longFieldName_151a163", [&]() {
                for(size_t i=0; i<obj.longFieldName_151a163.size(); i++) {
                    b.UInt(obj.longFieldName_151a163[i]);
                }
            });
            b.TypedVector("longFieldName_245a164", [&]() {
                for(size_t i=0; i<obj.longFieldName_245a164.size(); i++) {
                    b.UInt(obj.longFieldName_245a164[i]);
                }
            });
            b.TypedVector("longFieldName_368a165", [&]() {
                for(size_t i=0; i<obj.longFieldName_368a165.size(); i++) {
                    b.UInt(obj.longFieldName_368a165[i]);
                }
            });

            b.Vector("longFieldName_742aobj1", [&] {
                for (size_t i=0; i<obj.longFieldName_742aobj1.size(); i++) {
                    b.Map([&]() {
                        b.UInt("id", obj.longFieldName_742aobj1[i].id);
                        b.String("name", obj.longFieldName_742aobj1[i].name);

                        b.TypedVector("data", [&]() {
                            for (size_t i = 0; i<obj.longFieldName_742aobj1[i].data.size(); i++) {
                                b.UInt(obj.longFieldName_742aobj1[i].data[i]);
                            }
                        });
                    });
                }
            });
        });

        b.Finish();
    }

    flexbuffers::Reference readARandomField(const std::string& fieldName, const std::vector<uint8_t>& buff) {
//        auto t = flexbuffers::GetRoot(buff).AsMap()[fieldName];
//        uint64_t x =t.AsUInt64();
        return flexbuffers::GetRoot(buff).AsMap()[fieldName];
    }
}
