//
// Created by thongpv3 on 12/01/2017.
//

#pragma once

#include <mpack/mpack.h>
#include <cstdlib>
#include "ComplexObject.h"

namespace benchmark_serializer {

    void serializeComplexObjectToMsgPackByMPack(const ComplexObject& obj, char** data, size_t *size) {
        mpack_writer_t w;
        mpack_writer_init_growable(&w, data, size);

        mpack_start_map(&w, ComplexObject::fieldNames.size());
        //write uintvalue
        mpack_write_cstr(&w, "longFieldName_485u81");
        mpack_write_u8(&w, obj.longFieldName_485u81);
        mpack_write_cstr(&w, "longFieldName_196u82");
        mpack_write_u8(&w, obj.longFieldName_196u82);
        mpack_write_cstr(&w, "longFieldName_584u83");
        mpack_write_u8(&w, obj.longFieldName_584u83);
        mpack_write_cstr(&w, "longFieldName_173u84");
        mpack_write_u8(&w, obj.longFieldName_173u84);
        mpack_write_cstr(&w, "longFieldName_873u85");
        mpack_write_u8(&w, obj.longFieldName_873u85);
        mpack_write_cstr(&w, "longFieldName_494u321");
        mpack_write_u32(&w, obj.longFieldName_494u321);
        mpack_write_cstr(&w, "longFieldName_137u322");
        mpack_write_u32(&w, obj.longFieldName_137u322);
        mpack_write_cstr(&w, "longFieldName_664u323");
        mpack_write_u32(&w, obj.longFieldName_664u323);
        mpack_write_cstr(&w, "longFieldName_871u324");
        mpack_write_u32(&w, obj.longFieldName_871u324);
        mpack_write_cstr(&w, "longFieldName_142u325");
        mpack_write_u32(&w, obj.longFieldName_142u325);
        mpack_write_cstr(&w, "longFieldName_221u161");
        mpack_write_u16(&w, obj.longFieldName_221u161);
        mpack_write_cstr(&w, "longFieldName_115u162");
        mpack_write_u16(&w, obj.longFieldName_115u162);
        mpack_write_cstr(&w, "longFieldName_212u163");
        mpack_write_u16(&w, obj.longFieldName_212u163);
        mpack_write_cstr(&w, "longFieldName_585u164");
        mpack_write_u16(&w, obj.longFieldName_585u164);
        mpack_write_cstr(&w, "longFieldName_012u165");
        mpack_write_u16(&w, obj.longFieldName_012u165);
        mpack_write_cstr(&w, "longFieldName_141u641");
        mpack_write_u64(&w, obj.longFieldName_141u641);
        mpack_write_cstr(&w, "longFieldName_665u642");
        mpack_write_u64(&w, obj.longFieldName_665u642);
        mpack_write_cstr(&w, "longFieldName_988u643");
        mpack_write_u64(&w, obj.longFieldName_988u643);
        mpack_write_cstr(&w, "longFieldName_774u644");
        mpack_write_u64(&w, obj.longFieldName_774u644);
        mpack_write_cstr(&w, "longFieldName_004u645");
        mpack_write_u64(&w, obj.longFieldName_004u645);

        //write string
        mpack_write_cstr(&w, "longFieldName_332s1");
        mpack_write_cstr(&w, obj.longFieldName_332s1.c_str());
        mpack_write_cstr(&w, "longFieldName_421s2");
        mpack_write_cstr(&w, obj.longFieldName_421s2.c_str());
        mpack_write_cstr(&w, "longFieldName_687s3");
        mpack_write_cstr(&w, obj.longFieldName_687s3.c_str());
        mpack_write_cstr(&w, "longFieldName_978s4");
        mpack_write_cstr(&w, obj.longFieldName_978s4.c_str());
        mpack_write_cstr(&w, "longFieldName_325s5");
        mpack_write_cstr(&w, obj.longFieldName_325s5.c_str());
        mpack_write_cstr(&w, "longFieldName_452ms1");
        mpack_write_cstr(&w, obj.longFieldName_452ms1.c_str());
        mpack_write_cstr(&w, "longFieldName_661ms2");
        mpack_write_cstr(&w, obj.longFieldName_661ms2.c_str());
        mpack_write_cstr(&w, "longFieldName_148ms3");
        mpack_write_cstr(&w, obj.longFieldName_148ms3.c_str());
        mpack_write_cstr(&w, "longFieldName_213ms4");
        mpack_write_cstr(&w, obj.longFieldName_213ms4.c_str());
        mpack_write_cstr(&w, "longFieldName_644ms5");
        mpack_write_cstr(&w, obj.longFieldName_644ms5.c_str());
        mpack_write_cstr(&w, "longFieldName_989ls1");
        mpack_write_cstr(&w, obj.longFieldName_989ls1.c_str());
        mpack_write_cstr(&w, "longFieldName_112ls2");
        mpack_write_cstr(&w, obj.longFieldName_112ls2.c_str());
        mpack_write_cstr(&w, "longFieldName_210ls3");
        mpack_write_cstr(&w, obj.longFieldName_210ls3.c_str());
        mpack_write_cstr(&w, "longFieldName_222ls4");
        mpack_write_cstr(&w, obj.longFieldName_222ls4.c_str());
        mpack_write_cstr(&w, "longFieldName_748ls5");
        mpack_write_cstr(&w, obj.longFieldName_748ls5.c_str());


        //write an SimpleObject
        mpack_write_cstr(&w, "longFieldName_656o1");
        mpack_start_map(&w, 3);
        mpack_write_cstr(&w, "id");
        mpack_write_u32(&w, obj.longFieldName_656o1.id);
        mpack_write_cstr(&w, "name");
        mpack_write_cstr(&w, obj.longFieldName_656o1.name.c_str());
        mpack_write_cstr(&w, "data");
        mpack_start_array(&w, obj.longFieldName_656o1.data.size());
        for (size_t i = 0; i<obj.longFieldName_656o1.data.size(); i++) {
            mpack_write_u16(&w, obj.longFieldName_656o1.data[i]);
        }
        mpack_finish_array(&w);
        mpack_finish_map(&w); //finish object

        //write an SimpleObject
        mpack_write_cstr(&w, "longFieldName_664o2");
        mpack_start_map(&w, 3);
        mpack_write_cstr(&w, "id");
        mpack_write_u32(&w, obj.longFieldName_664o2.id);
        mpack_write_cstr(&w, "name");
        mpack_write_cstr(&w, obj.longFieldName_664o2.name.c_str());
        mpack_write_cstr(&w, "data");
        mpack_start_array(&w, obj.longFieldName_664o2.data.size());
        for (size_t i = 0; i<obj.longFieldName_664o2.data.size(); i++) {
            mpack_write_u16(&w, obj.longFieldName_664o2.data[i]);
        }
        mpack_finish_array(&w);
        mpack_finish_map(&w); //finish object

        //write an SimpleObject
        mpack_write_cstr(&w, "longFieldName_141o3");
        mpack_start_map(&w, 3);
        mpack_write_cstr(&w, "id");
        mpack_write_u32(&w, obj.longFieldName_141o3.id);
        mpack_write_cstr(&w, "name");
        mpack_write_cstr(&w, obj.longFieldName_141o3.name.c_str());
        mpack_write_cstr(&w, "data");
        mpack_start_array(&w, obj.longFieldName_141o3.data.size());
        for (size_t i = 0; i<obj.longFieldName_141o3.data.size(); i++) {
            mpack_write_u16(&w, obj.longFieldName_141o3.data[i]);
        }
        mpack_finish_array(&w);
        mpack_finish_map(&w); //finish object

        //write an SimpleObject
        mpack_write_cstr(&w, "longFieldName_215o4");
        mpack_start_map(&w, 3);
        mpack_write_cstr(&w, "id");
        mpack_write_u32(&w, obj.longFieldName_215o4.id);
        mpack_write_cstr(&w, "name");
        mpack_write_cstr(&w, obj.longFieldName_215o4.name.c_str());
        mpack_write_cstr(&w, "data");
        mpack_start_array(&w, obj.longFieldName_215o4.data.size());
        for (size_t i = 0; i<obj.longFieldName_215o4.data.size(); i++) {
            mpack_write_u16(&w, obj.longFieldName_215o4.data[i]);
        }
        mpack_finish_array(&w);
        mpack_finish_map(&w); //finish object

        //write an SimpleObject
        mpack_write_cstr(&w, "longFieldName_521o5");
        mpack_start_map(&w, 3);
        mpack_write_cstr(&w, "id");
        mpack_write_u32(&w, obj.longFieldName_521o5.id);
        mpack_write_cstr(&w, "name");
        mpack_write_cstr(&w, obj.longFieldName_521o5.name.c_str());
        mpack_write_cstr(&w, "data");
        mpack_start_array(&w, obj.longFieldName_521o5.data.size());
        for (size_t i = 0; i<obj.longFieldName_521o5.data.size(); i++) {
            mpack_write_u16(&w, obj.longFieldName_521o5.data[i]);
        }
        mpack_finish_array(&w);
        mpack_finish_map(&w); //finish object

        //write an SimpleObject
        mpack_write_cstr(&w, "longFieldName_674o6");
        mpack_start_map(&w, 3);
        mpack_write_cstr(&w, "id");
        mpack_write_u32(&w, obj.longFieldName_674o6.id);
        mpack_write_cstr(&w, "name");
        mpack_write_cstr(&w, obj.longFieldName_674o6.name.c_str());
        mpack_write_cstr(&w, "data");
        mpack_start_array(&w, obj.longFieldName_674o6.data.size());
        for (size_t i = 0; i<obj.longFieldName_674o6.data.size(); i++) {
            mpack_write_u16(&w, obj.longFieldName_674o6.data[i]);
        }
        mpack_finish_array(&w);
        mpack_finish_map(&w); //finish object

        //write an SimpleObject
        mpack_write_cstr(&w, "longFieldName_668o7");
        mpack_start_map(&w, 3);
        mpack_write_cstr(&w, "id");
        mpack_write_u32(&w, obj.longFieldName_668o7.id);
        mpack_write_cstr(&w, "name");
        mpack_write_cstr(&w, obj.longFieldName_668o7.name.c_str());
        mpack_write_cstr(&w, "data");
        mpack_start_array(&w, obj.longFieldName_668o7.data.size());
        for (size_t i = 0; i<obj.longFieldName_668o7.data.size(); i++) {
            mpack_write_u16(&w, obj.longFieldName_668o7.data[i]);
        }
        mpack_finish_array(&w);
        mpack_finish_map(&w); //finish object

        //write an SimpleObject
        mpack_write_cstr(&w, "longFieldName_913o8");
        mpack_start_map(&w, 3);
        mpack_write_cstr(&w, "id");
        mpack_write_u32(&w, obj.longFieldName_913o8.id);
        mpack_write_cstr(&w, "name");
        mpack_write_cstr(&w, obj.longFieldName_913o8.name.c_str());
        mpack_write_cstr(&w, "data");
        mpack_start_array(&w, obj.longFieldName_913o8.data.size());
        for (size_t i = 0; i<obj.longFieldName_913o8.data.size(); i++) {
            mpack_write_u16(&w, obj.longFieldName_913o8.data[i]);
        }
        mpack_finish_array(&w);
        mpack_finish_map(&w); //finish object

        //write an SimpleObject
        mpack_write_cstr(&w, "longFieldName_206o9");
        mpack_start_map(&w, 3);
        mpack_write_cstr(&w, "id");
        mpack_write_u32(&w, obj.longFieldName_206o9.id);
        mpack_write_cstr(&w, "name");
        mpack_write_cstr(&w, obj.longFieldName_206o9.name.c_str());
        mpack_write_cstr(&w, "data");
        mpack_start_array(&w, obj.longFieldName_206o9.data.size());
        for (size_t i = 0; i<obj.longFieldName_206o9.data.size(); i++) {
            mpack_write_u16(&w, obj.longFieldName_206o9.data[i]);
        }
        mpack_finish_array(&w);
        mpack_finish_map(&w); //finish object

        //write an SimpleObject
        mpack_write_cstr(&w, "longFieldName_877o10");
        mpack_start_map(&w, 3);
        mpack_write_cstr(&w, "id");
        mpack_write_u32(&w, obj.longFieldName_877o10.id);
        mpack_write_cstr(&w, "name");
        mpack_write_cstr(&w, obj.longFieldName_877o10.name.c_str());
        mpack_write_cstr(&w, "data");
        mpack_start_array(&w, obj.longFieldName_877o10.data.size());
        for (size_t i = 0; i<obj.longFieldName_877o10.data.size(); i++) {
            mpack_write_u16(&w, obj.longFieldName_877o10.data[i]);
        }
        mpack_finish_array(&w);
        mpack_finish_map(&w); //finish object


        //write an array
        mpack_write_cstr(&w, "longFieldName_171a81");
        mpack_start_array(&w, obj.longFieldName_171a81.size());
        for (size_t i = 0; i<obj.longFieldName_171a81.size(); i++) {
            mpack_write_u16(&w, obj.longFieldName_171a81[i]);
        }
        mpack_finish_array(&w);
        //write an array
        mpack_write_cstr(&w, "longFieldName_164a82");
        mpack_start_array(&w, obj.longFieldName_164a82.size());
        for (size_t i = 0; i<obj.longFieldName_164a82.size(); i++) {
            mpack_write_u16(&w, obj.longFieldName_164a82[i]);
        }
        mpack_finish_array(&w);
        //write an array
        mpack_write_cstr(&w, "longFieldName_197a83");
        mpack_start_array(&w, obj.longFieldName_197a83.size());
        for (size_t i = 0; i<obj.longFieldName_197a83.size(); i++) {
            mpack_write_u16(&w, obj.longFieldName_197a83[i]);
        }
        mpack_finish_array(&w);
        //write an array
        mpack_write_cstr(&w, "longFieldName_323a84");
        mpack_start_array(&w, obj.longFieldName_323a84.size());
        for (size_t i = 0; i<obj.longFieldName_323a84.size(); i++) {
            mpack_write_u16(&w, obj.longFieldName_323a84[i]);
        }
        mpack_finish_array(&w);
        //write an array
        mpack_write_cstr(&w, "longFieldName_311a85");
        mpack_start_array(&w, obj.longFieldName_311a85.size());
        for (size_t i = 0; i<obj.longFieldName_311a85.size(); i++) {
            mpack_write_u16(&w, obj.longFieldName_311a85[i]);
        }
        mpack_finish_array(&w);
        //write an array
        mpack_write_cstr(&w, "longFieldName_847a161");
        mpack_start_array(&w, obj.longFieldName_847a161.size());
        for (size_t i = 0; i<obj.longFieldName_847a161.size(); i++) {
            mpack_write_u16(&w, obj.longFieldName_847a161[i]);
        }
        mpack_finish_array(&w);
        //write an array
        mpack_write_cstr(&w, "longFieldName_852a162");
        mpack_start_array(&w, obj.longFieldName_852a162.size());
        for (size_t i = 0; i<obj.longFieldName_852a162.size(); i++) {
            mpack_write_u16(&w, obj.longFieldName_852a162[i]);
        }
        mpack_finish_array(&w);
        //write an array
        mpack_write_cstr(&w, "longFieldName_151a163");
        mpack_start_array(&w, obj.longFieldName_151a163.size());
        for (size_t i = 0; i<obj.longFieldName_151a163.size(); i++) {
            mpack_write_u32(&w, obj.longFieldName_151a163[i]);
        }
        mpack_finish_array(&w);
        //write an array
        mpack_write_cstr(&w, "longFieldName_245a164");
        mpack_start_array(&w, obj.longFieldName_245a164.size());
        for (size_t i = 0; i<obj.longFieldName_245a164.size(); i++) {
            mpack_write_u64(&w, obj.longFieldName_245a164[i]);
        }
        mpack_finish_array(&w);
        //write an array
        mpack_write_cstr(&w, "longFieldName_368a165");
        mpack_start_array(&w, obj.longFieldName_368a165.size());
        for (size_t i = 0; i<obj.longFieldName_368a165.size(); i++) {
            mpack_write_u16(&w, obj.longFieldName_368a165[i]);
        }
        mpack_finish_array(&w);


        //write an array of object
        mpack_write_cstr(&w, "longFieldName_742aobj1");
        mpack_start_array(&w, obj.longFieldName_742aobj1.size());
        for (size_t i=0; i < obj.longFieldName_742aobj1.size(); i++) {
            //write each SimpleObject of array
            mpack_start_map(&w, 3);
            mpack_write_cstr(&w, "id");
            mpack_write_u32(&w, obj.longFieldName_742aobj1[i].id);
            mpack_write_cstr(&w, "name");
            mpack_write_cstr(&w, obj.longFieldName_742aobj1[i].name.c_str());
            mpack_write_cstr(&w, "data");
            mpack_start_array(&w, obj.longFieldName_742aobj1[i].data.size());
            for (size_t i = 0; i<obj.longFieldName_742aobj1[i].data.size(); i++) {
                mpack_write_u16(&w, obj.longFieldName_742aobj1[i].data[i]);
            }
            mpack_finish_array(&w);
            mpack_finish_map(&w);
        }
        mpack_finish_array(&w);

        mpack_finish_map(&w); //finish complex object
        //destroy writer and update change to data
        if (mpack_writer_destroy(&w) != mpack_ok) {
            std::cout << "An error occurred encoding the data!\n" << std::endl;
            return;
        }
        return;
    }

    mpack_node_t readRandomFieldOfComplexObjectInMsgPackBuffer(const std::string& fieldName, const char * const data, size_t size) {
        mpack_tree_t tree;
        mpack_tree_init(&tree, data, size);
        mpack_tree_parse(&tree);
        mpack_node_t complexObjectNode = mpack_tree_root(&tree);
        return mpack_node_map_cstr(complexObjectNode, fieldName.c_str());
    }
}