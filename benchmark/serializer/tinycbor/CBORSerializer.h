//
// Created by Quan Nguyen Hoang on 2/6/17.
//

#include "../ComplexObject.h"
#include "cbor.h"
#include "cborencoder.c"

namespace benchmark_serializer {
    void justForFun() {
        std::cout << "justForFun()" << std::endl;
        uint8_t buf[160];
        CborEncoder encoder;
        cbor_encoder_init(&encoder, &buf[0], sizeof(buf), 0);
        cbor_encode_int(&encoder, 17);
        std::cout << "Buffer size = " << cbor_encoder_get_buffer_size(&encoder, &buf[0]) << std::endl;
        std::cout << "Print out the buffer:" << std::endl;
        for (int i = 0; i < 160; i++) {
            printf("%d ", buf[i]);
        }
        printf("\n");
    }

    void serializeComplexObjectToTinyCBOR(ComplexObject const &obj) {

        uint8_t buf[6500];
        // create root-sub
        CborEncoder rootEncoder;
        CborEncoder complexEncoder;
        cbor_encoder_init(&rootEncoder, &buf[0], sizeof(buf), 0);
        cbor_encoder_create_map(&rootEncoder, &complexEncoder, 0); // initial map size with length = 0

        // longFieldName_485u81
        cbor_encode_text_stringz(&complexEncoder, "longFieldName_485u81");
        cbor_encode_uint(&complexEncoder, obj.longFieldName_485u81);
        // longFieldName_196u82
        cbor_encode_text_stringz(&complexEncoder, "longFieldName_196u82");
        cbor_encode_uint(&complexEncoder, obj.longFieldName_196u82);
        // longFieldName_584u83
        cbor_encode_text_stringz(&complexEncoder, "longFieldName_584u83");
        cbor_encode_uint(&complexEncoder, obj.longFieldName_584u83);
        // longFieldName_173u84
        cbor_encode_text_stringz(&complexEncoder, "longFieldName_173u84");
        cbor_encode_uint(&complexEncoder, obj.longFieldName_173u84);
        // longFieldName_873u85
        cbor_encode_text_stringz(&complexEncoder, "longFieldName_873u85");
        cbor_encode_uint(&complexEncoder, obj.longFieldName_873u85);
        // longFieldName_494u321
        cbor_encode_text_stringz(&complexEncoder, "longFieldName_494u321");
        cbor_encode_uint(&complexEncoder, obj.longFieldName_494u321);
        // longFieldName_137u322
        cbor_encode_text_stringz(&complexEncoder, "longFieldName_137u322");
        cbor_encode_uint(&complexEncoder, obj.longFieldName_137u322);
        // longFieldName_664u323
        cbor_encode_text_stringz(&complexEncoder, "longFieldName_664u323");
        cbor_encode_uint(&complexEncoder, obj.longFieldName_664u323);
        // longFieldName_871u324
        cbor_encode_text_stringz(&complexEncoder, "longFieldName_871u324");
        cbor_encode_uint(&complexEncoder, obj.longFieldName_871u324);
        // longFieldName_142u325
        cbor_encode_text_stringz(&complexEncoder, "longFieldName_142u325");
        cbor_encode_uint(&complexEncoder, obj.longFieldName_142u325);
        // longFieldName_221u161
        cbor_encode_text_stringz(&complexEncoder, "longFieldName_221u161");
        cbor_encode_uint(&complexEncoder, obj.longFieldName_221u161);
        // longFieldName_115u162
        cbor_encode_text_stringz(&complexEncoder, "longFieldName_115u162");
        cbor_encode_uint(&complexEncoder, obj.longFieldName_115u162);
        // longFieldName_212u163
        cbor_encode_text_stringz(&complexEncoder, "longFieldName_212u163");
        cbor_encode_uint(&complexEncoder, obj.longFieldName_212u163);
        // longFieldName_585u164
        cbor_encode_text_stringz(&complexEncoder, "longFieldName_585u164");
        cbor_encode_uint(&complexEncoder, obj.longFieldName_585u164);
        // longFieldName_012u165
        cbor_encode_text_stringz(&complexEncoder, "longFieldName_012u165");
        cbor_encode_uint(&complexEncoder, obj.longFieldName_012u165);
        // longFieldName_141u641
        cbor_encode_text_stringz(&complexEncoder, "longFieldName_141u641");
        cbor_encode_uint(&complexEncoder, obj.longFieldName_141u641);
        // longFieldName_665u642
        cbor_encode_text_stringz(&complexEncoder, "longFieldName_665u642");
        cbor_encode_uint(&complexEncoder, obj.longFieldName_665u642);
        // longFieldName_988u643
        cbor_encode_text_stringz(&complexEncoder, "longFieldName_988u643");
        cbor_encode_uint(&complexEncoder, obj.longFieldName_988u643);
        // longFieldName_774u644
        cbor_encode_text_stringz(&complexEncoder, "longFieldName_774u644");
        cbor_encode_uint(&complexEncoder, obj.longFieldName_774u644);
        // longFieldName_004u645
        cbor_encode_text_stringz(&complexEncoder, "longFieldName_004u645");
        cbor_encode_uint(&complexEncoder, obj.longFieldName_004u645);


        // write strings
        cbor_encode_text_stringz(&complexEncoder, "longFieldName_332s1");
        cbor_encode_text_stringz(&complexEncoder, obj.longFieldName_332s1.c_str());
        cbor_encode_text_stringz(&complexEncoder, "longFieldName_421s2");
        cbor_encode_text_stringz(&complexEncoder, obj.longFieldName_421s2.c_str());
        cbor_encode_text_stringz(&complexEncoder, "longFieldName_687s3");
        cbor_encode_text_stringz(&complexEncoder, obj.longFieldName_687s3.c_str());
        cbor_encode_text_stringz(&complexEncoder, "longFieldName_978s4");
        cbor_encode_text_stringz(&complexEncoder, obj.longFieldName_978s4.c_str());
        cbor_encode_text_stringz(&complexEncoder, "longFieldName_325s5");
        cbor_encode_text_stringz(&complexEncoder, obj.longFieldName_325s5.c_str());
        cbor_encode_text_stringz(&complexEncoder, "longFieldName_452ms1");
        cbor_encode_text_stringz(&complexEncoder, obj.longFieldName_452ms1.c_str());
        cbor_encode_text_stringz(&complexEncoder, "longFieldName_661ms2");
        cbor_encode_text_stringz(&complexEncoder, obj.longFieldName_661ms2.c_str());
        cbor_encode_text_stringz(&complexEncoder, "longFieldName_148ms3");
        cbor_encode_text_stringz(&complexEncoder, obj.longFieldName_148ms3.c_str());
        cbor_encode_text_stringz(&complexEncoder, "longFieldName_213ms4");
        cbor_encode_text_stringz(&complexEncoder, obj.longFieldName_213ms4.c_str());
        cbor_encode_text_stringz(&complexEncoder, "longFieldName_644ms5");
        cbor_encode_text_stringz(&complexEncoder, obj.longFieldName_644ms5.c_str());
        cbor_encode_text_stringz(&complexEncoder, "longFieldName_989ls1");
        cbor_encode_text_stringz(&complexEncoder, obj.longFieldName_989ls1.c_str());
        cbor_encode_text_stringz(&complexEncoder, "longFieldName_112ls2");
        cbor_encode_text_stringz(&complexEncoder, obj.longFieldName_112ls2.c_str());
        cbor_encode_text_stringz(&complexEncoder, "longFieldName_210ls3");
        cbor_encode_text_stringz(&complexEncoder, obj.longFieldName_210ls3.c_str());
        cbor_encode_text_stringz(&complexEncoder, "longFieldName_222ls4");
        cbor_encode_text_stringz(&complexEncoder, obj.longFieldName_222ls4.c_str());
        cbor_encode_text_stringz(&complexEncoder, "longFieldName_748ls5");
        cbor_encode_text_stringz(&complexEncoder, obj.longFieldName_748ls5.c_str());

        // write simple objects
        //
        {
            cbor_encode_text_stringz(&complexEncoder, "longFieldName_656o1");
            CborEncoder tempEncoder;
            cbor_encoder_create_map(&complexEncoder, &tempEncoder, 3); // FIXME 0 is default and OK too
            // id
            cbor_encode_text_stringz(&tempEncoder, "id");
            cbor_encode_uint(&tempEncoder, obj.longFieldName_656o1.id);
            // name
            cbor_encode_text_stringz(&tempEncoder, "name");
            cbor_encode_text_stringz(&tempEncoder, obj.longFieldName_656o1.name.c_str());
            // data
            CborEncoder tempArrEncoder;
            cbor_encoder_create_array(&tempEncoder, &tempArrEncoder, obj.longFieldName_656o1.data.size());
            for(uint16_t item : obj.longFieldName_656o1.data) {
                cbor_encode_uint(&tempArrEncoder, item);
            }
            cbor_encoder_close_container(&tempEncoder, &tempArrEncoder); // close data
            cbor_encoder_close_container(&complexEncoder, &tempEncoder); // close this field container
        }
        //
        {
            cbor_encode_text_stringz(&complexEncoder, "longFieldName_664o2");
            CborEncoder tempEncoder;
            cbor_encoder_create_map(&complexEncoder, &tempEncoder, 3);
            // id
            cbor_encode_text_stringz(&tempEncoder, "id");
            cbor_encode_uint(&tempEncoder, obj.longFieldName_664o2.id);
            // name
            cbor_encode_text_stringz(&tempEncoder, "name");
            cbor_encode_text_stringz(&tempEncoder, obj.longFieldName_664o2.name.c_str());
            // data
            CborEncoder tempArrEncoder;
            cbor_encoder_create_array(&tempEncoder, &tempArrEncoder, obj.longFieldName_664o2.data.size());
            for(uint16_t item : obj.longFieldName_664o2.data) {
                cbor_encode_uint(&tempArrEncoder, item);
            }
            cbor_encoder_close_container(&tempEncoder, &tempArrEncoder); // close data
            cbor_encoder_close_container(&complexEncoder, &tempEncoder); // close this field container
        }
        //
        {
            cbor_encode_text_stringz(&complexEncoder, "longFieldName_141o3");
            CborEncoder tempEncoder;
            cbor_encoder_create_map(&complexEncoder, &tempEncoder, 3);
            // id
            cbor_encode_text_stringz(&tempEncoder, "id");
            cbor_encode_uint(&tempEncoder, obj.longFieldName_141o3.id);
            // name
            cbor_encode_text_stringz(&tempEncoder, "name");
            cbor_encode_text_stringz(&tempEncoder, obj.longFieldName_141o3.name.c_str());
            // data
            CborEncoder tempArrEncoder;
            cbor_encoder_create_array(&tempEncoder, &tempArrEncoder, obj.longFieldName_141o3.data.size());
            for(uint16_t item : obj.longFieldName_141o3.data) {
                cbor_encode_uint(&tempArrEncoder, item);
            }
            cbor_encoder_close_container(&tempEncoder, &tempArrEncoder); // close data
            cbor_encoder_close_container(&complexEncoder, &tempEncoder); // close this field container
        }
        //
        {
            cbor_encode_text_stringz(&complexEncoder, "longFieldName_215o4");
            CborEncoder tempEncoder;
            cbor_encoder_create_map(&complexEncoder, &tempEncoder, 3);
            // id
            cbor_encode_text_stringz(&tempEncoder, "id");
            cbor_encode_uint(&tempEncoder, obj.longFieldName_215o4.id);
            // name
            cbor_encode_text_stringz(&tempEncoder, "name");
            cbor_encode_text_stringz(&tempEncoder, obj.longFieldName_215o4.name.c_str());
            // data
            CborEncoder tempArrEncoder;
            cbor_encoder_create_array(&tempEncoder, &tempArrEncoder, obj.longFieldName_215o4.data.size());
            for(uint16_t item : obj.longFieldName_215o4.data) {
                cbor_encode_uint(&tempArrEncoder, item);
            }
            cbor_encoder_close_container(&tempEncoder, &tempArrEncoder); // close data
            cbor_encoder_close_container(&complexEncoder, &tempEncoder); // close this field container
        }
        //
        {
            cbor_encode_text_stringz(&complexEncoder, "longFieldName_521o5");
            CborEncoder tempEncoder;
            cbor_encoder_create_map(&complexEncoder, &tempEncoder, 3);
            // id
            cbor_encode_text_stringz(&tempEncoder, "id");
            cbor_encode_uint(&tempEncoder, obj.longFieldName_521o5.id);
            // name
            cbor_encode_text_stringz(&tempEncoder, "name");
            cbor_encode_text_stringz(&tempEncoder, obj.longFieldName_521o5.name.c_str());
            // data
            CborEncoder tempArrEncoder;
            cbor_encoder_create_array(&tempEncoder, &tempArrEncoder, obj.longFieldName_521o5.data.size());
            for(uint16_t item : obj.longFieldName_521o5.data) {
                cbor_encode_uint(&tempArrEncoder, item);
            }
            cbor_encoder_close_container(&tempEncoder, &tempArrEncoder); // close data
            cbor_encoder_close_container(&complexEncoder, &tempEncoder); // close this field container
        }
        //
        {
            cbor_encode_text_stringz(&complexEncoder, "longFieldName_674o6");
            CborEncoder tempEncoder;
            cbor_encoder_create_map(&complexEncoder, &tempEncoder, 3);
            // id
            cbor_encode_text_stringz(&tempEncoder, "id");
            cbor_encode_uint(&tempEncoder, obj.longFieldName_674o6.id);
            // name
            cbor_encode_text_stringz(&tempEncoder, "name");
            cbor_encode_text_stringz(&tempEncoder, obj.longFieldName_674o6.name.c_str());
            // data
            CborEncoder tempArrEncoder;
            cbor_encoder_create_array(&tempEncoder, &tempArrEncoder, obj.longFieldName_674o6.data.size());
            for(uint16_t item : obj.longFieldName_674o6.data) {
                cbor_encode_uint(&tempArrEncoder, item);
            }
            cbor_encoder_close_container(&tempEncoder, &tempArrEncoder); // close data
            cbor_encoder_close_container(&complexEncoder, &tempEncoder); // close this field container
        }
        //
        {
            cbor_encode_text_stringz(&complexEncoder, "longFieldName_668o7");
            CborEncoder tempEncoder;
            cbor_encoder_create_map(&complexEncoder, &tempEncoder, 3);
            // id
            cbor_encode_text_stringz(&tempEncoder, "id");
            cbor_encode_uint(&tempEncoder, obj.longFieldName_668o7.id);
            // name
            cbor_encode_text_stringz(&tempEncoder, "name");
            cbor_encode_text_stringz(&tempEncoder, obj.longFieldName_668o7.name.c_str());
            // data
            CborEncoder tempArrEncoder;
            cbor_encoder_create_array(&tempEncoder, &tempArrEncoder, obj.longFieldName_668o7.data.size());
            for(uint16_t item : obj.longFieldName_668o7.data) {
                cbor_encode_uint(&tempArrEncoder, item);
            }
            cbor_encoder_close_container(&tempEncoder, &tempArrEncoder); // close data
            cbor_encoder_close_container(&complexEncoder, &tempEncoder); // close this field container
        }
        //
        {
            cbor_encode_text_stringz(&complexEncoder, "longFieldName_913o8");
            CborEncoder tempEncoder;
            cbor_encoder_create_map(&complexEncoder, &tempEncoder, 3);
            // id
            cbor_encode_text_stringz(&tempEncoder, "id");
            cbor_encode_uint(&tempEncoder, obj.longFieldName_913o8.id);
            // name
            cbor_encode_text_stringz(&tempEncoder, "name");
            cbor_encode_text_stringz(&tempEncoder, obj.longFieldName_913o8.name.c_str());
            // data
            CborEncoder tempArrEncoder;
            cbor_encoder_create_array(&tempEncoder, &tempArrEncoder, obj.longFieldName_913o8.data.size());
            for(uint16_t item : obj.longFieldName_913o8.data) {
                cbor_encode_uint(&tempArrEncoder, item);
            }
            cbor_encoder_close_container(&tempEncoder, &tempArrEncoder); // close data
            cbor_encoder_close_container(&complexEncoder, &tempEncoder); // close this field container
        }
        //
        {
            cbor_encode_text_stringz(&complexEncoder, "longFieldName_206o9");
            CborEncoder tempEncoder;
            cbor_encoder_create_map(&complexEncoder, &tempEncoder, 3);
            // id
            cbor_encode_text_stringz(&tempEncoder, "id");
            cbor_encode_uint(&tempEncoder, obj.longFieldName_206o9.id);
            // name
            cbor_encode_text_stringz(&tempEncoder, "name");
            cbor_encode_text_stringz(&tempEncoder, obj.longFieldName_206o9.name.c_str());
            // data
            CborEncoder tempArrEncoder;
            cbor_encoder_create_array(&tempEncoder, &tempArrEncoder, obj.longFieldName_206o9.data.size());
            for(uint16_t item : obj.longFieldName_206o9.data) {
                cbor_encode_uint(&tempArrEncoder, item);
            }
            cbor_encoder_close_container(&tempEncoder, &tempArrEncoder); // close data
            cbor_encoder_close_container(&complexEncoder, &tempEncoder); // close this field container
        }
        //
        {
            cbor_encode_text_stringz(&complexEncoder, "longFieldName_877o10");
            CborEncoder tempEncoder;
            cbor_encoder_create_map(&complexEncoder, &tempEncoder, 3);
            // id
            cbor_encode_text_stringz(&tempEncoder, "id");
            cbor_encode_uint(&tempEncoder, obj.longFieldName_877o10.id);
            // name
            cbor_encode_text_stringz(&tempEncoder, "name");
            cbor_encode_text_stringz(&tempEncoder, obj.longFieldName_877o10.name.c_str());
            // data
            CborEncoder tempArrEncoder;
            cbor_encoder_create_array(&tempEncoder, &tempArrEncoder, obj.longFieldName_877o10.data.size());
            for(uint16_t item : obj.longFieldName_877o10.data) {
                cbor_encode_uint(&tempArrEncoder, item);
            }
            cbor_encoder_close_container(&tempEncoder, &tempArrEncoder); // close data
            cbor_encoder_close_container(&complexEncoder, &tempEncoder); // close this field container
        }


        // write vectors
        //
        {
            cbor_encode_text_stringz(&complexEncoder, "longFieldName_171a81");
            CborEncoder tempArrEncoder;
            cbor_encoder_create_array(&complexEncoder, &tempArrEncoder, obj.longFieldName_171a81.size());
            for(auto item : obj.longFieldName_171a81) {
                cbor_encode_uint(&tempArrEncoder, item);
            }
            cbor_encoder_close_container(&complexEncoder, &tempArrEncoder);
        }
        //
        {
            cbor_encode_text_stringz(&complexEncoder, "longFieldName_164a82");
            CborEncoder tempArrEncoder;
            cbor_encoder_create_array(&complexEncoder, &tempArrEncoder, obj.longFieldName_164a82.size());
            for(auto item : obj.longFieldName_164a82) {
                cbor_encode_uint(&tempArrEncoder, item);
            }
            cbor_encoder_close_container(&complexEncoder, &tempArrEncoder);
        }
        //
        {
            cbor_encode_text_stringz(&complexEncoder, "longFieldName_197a83");
            CborEncoder tempArrEncoder;
            cbor_encoder_create_array(&complexEncoder, &tempArrEncoder, obj.longFieldName_197a83.size());
            for(auto item : obj.longFieldName_197a83) {
                cbor_encode_uint(&tempArrEncoder, item);
            }
            cbor_encoder_close_container(&complexEncoder, &tempArrEncoder);
        }
        //
        {
            cbor_encode_text_stringz(&complexEncoder, "longFieldName_323a84");
            CborEncoder tempArrEncoder;
            cbor_encoder_create_array(&complexEncoder, &tempArrEncoder, obj.longFieldName_323a84.size());
            for(auto item : obj.longFieldName_323a84) {
                cbor_encode_uint(&tempArrEncoder, item);
            }
            cbor_encoder_close_container(&complexEncoder, &tempArrEncoder);
        }
        //
        {
            cbor_encode_text_stringz(&complexEncoder, "longFieldName_311a85");
            CborEncoder tempArrEncoder;
            cbor_encoder_create_array(&complexEncoder, &tempArrEncoder, obj.longFieldName_311a85.size());
            for(auto item : obj.longFieldName_311a85) {
                cbor_encode_uint(&tempArrEncoder, item);
            }
            cbor_encoder_close_container(&complexEncoder, &tempArrEncoder);
        }
        //
        {
            cbor_encode_text_stringz(&complexEncoder, "longFieldName_847a161");
            CborEncoder tempArrEncoder;
            cbor_encoder_create_array(&complexEncoder, &tempArrEncoder, obj.longFieldName_847a161.size());
            for(auto item : obj.longFieldName_847a161) {
                cbor_encode_uint(&tempArrEncoder, item);
            }
            cbor_encoder_close_container(&complexEncoder, &tempArrEncoder);
        }
        //
        {
            cbor_encode_text_stringz(&complexEncoder, "longFieldName_852a162");
            CborEncoder tempArrEncoder;
            cbor_encoder_create_array(&complexEncoder, &tempArrEncoder, obj.longFieldName_852a162.size());
            for(auto item : obj.longFieldName_852a162) {
                cbor_encode_uint(&tempArrEncoder, item);
            }
            cbor_encoder_close_container(&complexEncoder, &tempArrEncoder);
        }
        //
        {
            cbor_encode_text_stringz(&complexEncoder, "longFieldName_151a163");
            CborEncoder tempArrEncoder;
            cbor_encoder_create_array(&complexEncoder, &tempArrEncoder, obj.longFieldName_151a163.size());
            for(auto item : obj.longFieldName_151a163) {
                cbor_encode_uint(&tempArrEncoder, item);
            }
            cbor_encoder_close_container(&complexEncoder, &tempArrEncoder);
        }
        //
        {
            cbor_encode_text_stringz(&complexEncoder, "longFieldName_245a164");
            CborEncoder tempArrEncoder;
            cbor_encoder_create_array(&complexEncoder, &tempArrEncoder, obj.longFieldName_245a164.size());
            for(auto item : obj.longFieldName_245a164) {
                cbor_encode_uint(&tempArrEncoder, item);
            }
            cbor_encoder_close_container(&complexEncoder, &tempArrEncoder);
        }
        //
        {
            cbor_encode_text_stringz(&complexEncoder, "longFieldName_368a165");
            CborEncoder tempArrEncoder;
            cbor_encoder_create_array(&complexEncoder, &tempArrEncoder, obj.longFieldName_368a165.size());
            for(auto item : obj.longFieldName_368a165) {
                cbor_encode_uint(&tempArrEncoder, item);
            }
            cbor_encoder_close_container(&complexEncoder, &tempArrEncoder);
        }

        // write array of objects
        {
            cbor_encode_text_stringz(&complexEncoder, "longFieldName_742aobj1");
            CborEncoder tempArrEncoder;
            cbor_encoder_create_array(&complexEncoder, &tempArrEncoder, obj.longFieldName_742aobj1.size());
            for(auto item : obj.longFieldName_742aobj1) {
                CborEncoder tempObjEncoder;
                cbor_encoder_create_map(&tempArrEncoder, &tempObjEncoder, 3); // FIXME - this is WRONG???
                // id
                cbor_encode_text_stringz(&tempObjEncoder, "id");
                cbor_encode_uint(&tempObjEncoder, item.id);
                // name
                cbor_encode_text_stringz(&tempObjEncoder, "name");
                cbor_encode_text_stringz(&tempObjEncoder, item.name.c_str());
                // data
                CborEncoder tempInnerArrEncoder;
                cbor_encoder_create_array(&tempObjEncoder, &tempInnerArrEncoder, item.data.size());
                for(uint16_t it : item.data) {
                    cbor_encode_uint(&tempInnerArrEncoder, it);
                }
                cbor_encoder_close_container(&tempObjEncoder, &tempInnerArrEncoder); // close data


                cbor_encoder_close_container(&tempArrEncoder, &tempObjEncoder); // close this field container FIXME - this is WRONG???
            }
            cbor_encoder_close_container(&complexEncoder, &tempArrEncoder);
        }

        // close root-ComplexObject
        cbor_encoder_close_container(&rootEncoder, &complexEncoder);


        /**finally, print out the buffer FIXME how to resize the buf, how to truncate the 0s */
/**
        std::cout << "Buffer size = " << cbor_encoder_get_buffer_size(&rootEncoder, &buf[0]) << std::endl;
        std::cout << "Print out the buffer:" << std::endl;
        for (int i = 0; i < 8192; i++) {
            printf("%d ", buf[i]);
        }
        printf("\n");
*/

    }
}