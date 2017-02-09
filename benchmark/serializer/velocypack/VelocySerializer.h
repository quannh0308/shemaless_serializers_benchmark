//
// Created by Quan Nguyen Hoang on 1/6/17.
//

#include "ComplexObject.h"
#include <iostream>

namespace benchmark_serializer {
    using namespace arangodb::velocypack;

    void printBuilder(arangodb::velocypack::Builder& b) {
        auto buffer = b.buffer().get()->data();
        auto size = b.buffer().get()->length();
        std::cout << "VelocyPackBufferSize = " << size << std::endl;
        for(auto i = 0; i < size;i++) {
            printf("%d ", buffer[i]);
        }
        std::cout << std::endl;
    }

    void serializeComplexObjectToVelocy(arangodb::velocypack::Builder& b, const ComplexObject& obj) {
        //start complex object
        b.add(Value(ValueType::Object));

        b.add("longFieldName_485u81", Value(obj.longFieldName_485u81));
        b.add("longFieldName_196u82", Value(obj.longFieldName_196u82));
        b.add("longFieldName_584u83", Value(obj.longFieldName_584u83));
        b.add("longFieldName_173u84", Value(obj.longFieldName_173u84));
        b.add("longFieldName_873u85", Value(obj.longFieldName_873u85));
        b.add("longFieldName_494u321", Value(obj.longFieldName_494u321));
        b.add("longFieldName_137u322", Value(obj.longFieldName_137u322));
        b.add("longFieldName_664u323", Value(obj.longFieldName_664u323));
        b.add("longFieldName_871u324", Value(obj.longFieldName_871u324));
        b.add("longFieldName_142u325", Value(obj.longFieldName_142u325));
        b.add("longFieldName_221u161", Value(obj.longFieldName_221u161));
        b.add("longFieldName_115u162", Value(obj.longFieldName_115u162));
        b.add("longFieldName_212u163", Value(obj.longFieldName_212u163));
        b.add("longFieldName_585u164", Value(obj.longFieldName_585u164));
        b.add("longFieldName_012u165", Value(obj.longFieldName_012u165));
        b.add("longFieldName_141u641", Value(obj.longFieldName_141u641));
        b.add("longFieldName_665u642", Value(obj.longFieldName_665u642));
        b.add("longFieldName_988u643", Value(obj.longFieldName_988u643));
        b.add("longFieldName_774u644", Value(obj.longFieldName_774u644));
        b.add("longFieldName_004u645", Value(obj.longFieldName_004u645));
        b.add("longFieldName_332s1", Value(obj.longFieldName_332s1));
        b.add("longFieldName_421s2", Value(obj.longFieldName_421s2));
        b.add("longFieldName_687s3", Value(obj.longFieldName_687s3));
        b.add("longFieldName_978s4", Value(obj.longFieldName_978s4));
        b.add("longFieldName_325s5", Value(obj.longFieldName_325s5));
        b.add("longFieldName_452ms1", Value(obj.longFieldName_452ms1));
        b.add("longFieldName_661ms2", Value(obj.longFieldName_661ms2));
        b.add("longFieldName_148ms3", Value(obj.longFieldName_148ms3));
        b.add("longFieldName_213ms4", Value(obj.longFieldName_213ms4));
        b.add("longFieldName_644ms5", Value(obj.longFieldName_644ms5));
        b.add("longFieldName_989ls1", Value(obj.longFieldName_989ls1));
        b.add("longFieldName_112ls2", Value(obj.longFieldName_112ls2));
        b.add("longFieldName_210ls3", Value(obj.longFieldName_210ls3));
        b.add("longFieldName_222ls4", Value(obj.longFieldName_222ls4));
        b.add("longFieldName_748ls5", Value(obj.longFieldName_748ls5));

        b.add("longFieldName_656o1", Value(ValueType::Object)); //create simple object
        b.add("id", Value(obj.longFieldName_656o1.id));
        b.add("name", Value(obj.longFieldName_656o1.name));
        b.add("data", Value(ValueType::Array));
        for (size_t i = 0; i<obj.longFieldName_656o1.data.size(); i++) {
            b.add(Value(obj.longFieldName_656o1.data[i]));
        }
        b.close();
        b.close();//end simple object

        b.add("longFieldName_664o2", Value(ValueType::Object)); //create simple object
        b.add("id", Value(obj.longFieldName_664o2.id));
        b.add("name", Value(obj.longFieldName_664o2.name));
        b.add("data", Value(ValueType::Array));
        for (size_t i = 0; i<obj.longFieldName_664o2.data.size(); i++) {
            b.add(Value(obj.longFieldName_664o2.data[i]));
        }
        b.close();
        b.close();//end simple object

        b.add("longFieldName_141o3", Value(ValueType::Object)); //create simple object
        b.add("id", Value(obj.longFieldName_141o3.id));
        b.add("name", Value(obj.longFieldName_141o3.name));
        b.add("data", Value(ValueType::Array));
        for (size_t i = 0; i<obj.longFieldName_141o3.data.size(); i++) {
            b.add(Value(obj.longFieldName_141o3.data[i]));
        }
        b.close();
        b.close();//end simple object

        b.add("longFieldName_215o4", Value(ValueType::Object)); //create simple object
        b.add("id", Value(obj.longFieldName_215o4.id));
        b.add("name", Value(obj.longFieldName_215o4.name));
        b.add("data", Value(ValueType::Array));
        for (size_t i = 0; i<obj.longFieldName_215o4.data.size(); i++) {
            b.add(Value(obj.longFieldName_215o4.data[i]));
        }
        b.close();
        b.close();//end simple object

        b.add("longFieldName_521o5", Value(ValueType::Object)); //create simple object
        b.add("id", Value(obj.longFieldName_521o5.id));
        b.add("name", Value(obj.longFieldName_521o5.name));
        b.add("data", Value(ValueType::Array));
        for (size_t i = 0; i<obj.longFieldName_521o5.data.size(); i++) {
            b.add(Value(obj.longFieldName_521o5.data[i]));
        }
        b.close();
        b.close();//end simple object

        b.add("longFieldName_674o6", Value(ValueType::Object)); //create simple object
        b.add("id", Value(obj.longFieldName_674o6.id));
        b.add("name", Value(obj.longFieldName_674o6.name));
        b.add("data", Value(ValueType::Array));
        for (size_t i = 0; i<obj.longFieldName_674o6.data.size(); i++) {
            b.add(Value(obj.longFieldName_674o6.data[i]));
        }
        b.close();
        b.close();//end simple object

        b.add("longFieldName_668o7", Value(ValueType::Object)); //create simple object
        b.add("id", Value(obj.longFieldName_668o7.id));
        b.add("name", Value(obj.longFieldName_668o7.name));
        b.add("data", Value(ValueType::Array));
        for (size_t i = 0; i<obj.longFieldName_668o7.data.size(); i++) {
            b.add(Value(obj.longFieldName_668o7.data[i]));
        }
        b.close();
        b.close();//end simple object

        b.add("longFieldName_913o8", Value(ValueType::Object)); //create simple object
        b.add("id", Value(obj.longFieldName_913o8.id));
        b.add("name", Value(obj.longFieldName_913o8.name));
        b.add("data", Value(ValueType::Array));
        for (size_t i = 0; i<obj.longFieldName_913o8.data.size(); i++) {
            b.add(Value(obj.longFieldName_913o8.data[i]));
        }
        b.close();
        b.close();//end simple object

        b.add("longFieldName_913o8", Value(ValueType::Object)); //create simple object
        b.add("id", Value(obj.longFieldName_913o8.id));
        b.add("name", Value(obj.longFieldName_913o8.name));
        b.add("data", Value(ValueType::Array));
        for (size_t i = 0; i<obj.longFieldName_913o8.data.size(); i++) {
            b.add(Value(obj.longFieldName_913o8.data[i]));
        }
        b.close();
        b.close();//end simple object

        b.add("longFieldName_206o9", Value(ValueType::Object)); //create simple object
        b.add("id", Value(obj.longFieldName_206o9.id));
        b.add("name", Value(obj.longFieldName_206o9.name));
        b.add("data", Value(ValueType::Array));
        for (size_t i = 0; i<obj.longFieldName_206o9.data.size(); i++) {
            b.add(Value(obj.longFieldName_206o9.data[i]));
        }
        b.close();
        b.close();//end simple object

        b.add("longFieldName_171a81", Value(ValueType::Array));
        for (size_t i = 0; i<obj.longFieldName_171a81.size(); i++) {
            b.add(Value(obj.longFieldName_171a81[i]));
        }
        b.close();

        b.add("longFieldName_164a82", Value(ValueType::Array));
        for (size_t i = 0; i<obj.longFieldName_164a82.size(); i++) {
            b.add(Value(obj.longFieldName_164a82[i]));
        }
        b.close();

        b.add("longFieldName_197a83", Value(ValueType::Array));
        for (size_t i = 0; i<obj.longFieldName_197a83.size(); i++) {
            b.add(Value(obj.longFieldName_197a83[i]));
        }
        b.close();

        b.add("longFieldName_323a84", Value(ValueType::Array));
        for (size_t i = 0; i<obj.longFieldName_323a84.size(); i++) {
            b.add(Value(obj.longFieldName_323a84[i]));
        }
        b.close();

        b.add("longFieldName_311a85", Value(ValueType::Array));
        for (size_t i = 0; i<obj.longFieldName_311a85.size(); i++) {
            b.add(Value(obj.longFieldName_311a85[i]));
        }
        b.close();

        b.add("longFieldName_847a161", Value(ValueType::Array));
        for (size_t i = 0; i<obj.longFieldName_847a161.size(); i++) {
            b.add(Value(obj.longFieldName_847a161[i]));
        }
        b.close();

        b.add("longFieldName_852a162", Value(ValueType::Array));
        for (size_t i = 0; i<obj.longFieldName_852a162.size(); i++) {
            b.add(Value(obj.longFieldName_852a162[i]));
        }
        b.close();

        b.add("longFieldName_151a163", Value(ValueType::Array));
        for (size_t i = 0; i<obj.longFieldName_151a163.size(); i++) {
            b.add(Value(obj.longFieldName_151a163[i]));
        }
        b.close();

        b.add("longFieldName_245a164", Value(ValueType::Array));
        for (size_t i = 0; i<obj.longFieldName_245a164.size(); i++) {
            b.add(Value(obj.longFieldName_245a164[i]));
        }
        b.close();

        b.add("longFieldName_368a165", Value(ValueType::Array));
        for (size_t i = 0; i<obj.longFieldName_368a165.size(); i++) {
            b.add(Value(obj.longFieldName_368a165[i]));
        }
        b.close();

        b.add("longFieldName_742aobj1", Value(ValueType::Array));
        for (size_t i = 0; i<obj.longFieldName_742aobj1.size(); i++) {
            b.add(Value(ValueType::Object));
            b.add("id", Value(obj.longFieldName_742aobj1[i].id));
            b.add("name", Value(obj.longFieldName_742aobj1[i].name));
            b.add("data", Value(ValueType::Array));
            for (size_t i = 0; i<obj.longFieldName_742aobj1[i].data.size(); i++) {
                b.add(Value(obj.longFieldName_742aobj1[i].data[i]));
            }
            b.close();
            b.close();
        }
        b.close();

        b.close();
    }

    Slice readARandomField(const arangodb::velocypack::Builder& b, const std::string& fieldName) {
        Slice s(b.start());
//        auto t = s.get(fieldName);
//        std::cout << t.toJson() << std::endl;
        return s.get(fieldName);
    }
}

