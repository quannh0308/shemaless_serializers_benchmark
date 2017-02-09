//
// Created by thongpv3 on 19/01/2017.
//

#include <ion.h>
#include <ion_internal.h>
#include <iostream>
#include "../../../include/ion-c/test/tester.h"
#include "../../../include/ion-c/test/ion_binary_test.h"
#include "../../../include/ion-c/test/ion_test_utils.h"
#define BUF_SIZE 128<<10
#define STRING(str, x) {str.value=(BYTE*)x; str.length=(SIZE)strlen((char*)x);}
BOOL  g_no_print             = FALSE;
long  g_value_count          = 0;
long  g_failure_count        = 0;
long  g_total_failure_count  = 0;
char *g_iontests_path        = ".";
int   g_repeat_count         = 1;

SIZE copy_to_bytes(const char *image, BYTE *bytes, int limit)
{
    const char *cp = image;
    BYTE *bp = bytes;
    int   c, len = 0;

    if (!limit || !image) {
        return 0;
    }
    assert(bytes != NULL);

    while(*cp && len < limit) {
        c = *cp++;
        assert(c < 256 && "copy_to_bytes only handles byte sized characters <= 255");
        *bp++ = c;
        len++;
    }
    return len;
}


iERR test_reader_read_all(hREADER hreader)
{
    iENTER;
    ION_TYPE t, t2;
    BOOL     more;
    for (;;) {
        IONDEBUG(ion_reader_next(hreader, &t), "read next");
        if (t == tid_EOF) {
            // TODO IONC-4 does next() return tid_EOF or tid_none at end of stream?
            // See ion_parser_next where it returns tid_none
            assert(t == tid_EOF && "next() at end");
            more = FALSE;
        }
        else {
            more = TRUE;
        }

        IONDEBUG(ion_reader_get_type(hreader, &t2), "get_type");
//      assert(t != t2 && "get_type() should match next()");    // TODO IONC-5

        if (!more) break;


        if (g_no_print) {
            IONDEBUG(test_reader_read_value_no_print(hreader, t), "read & dump value");
        }
        else {
            char * type_name = ion_test_get_type_name(t);
            IONDEBUG(test_reader_read_value_print(hreader, t, type_name), "read & dump value");
        }
    }

    IF_PRINT("reader done\n");

    iRETURN;
}

int testSimple() {
    iENTER;

    BYTE                buffer[BUF_SIZE+1];
    BYTE                bytes[100];
    hWRITER             hwriter;
    ION_WRITER_OPTIONS  options;
    decQuad             dec1;
    double              d;
    ION_TIMESTAMP       timestamp;
    ION_STRING          str;
    char               *image;
    SIZE                used, len, bytes_flushed;


    memset(&buffer[0], 0, BUF_SIZE+1);
    memset(&options, 0, sizeof(options));

    options.output_as_binary = TRUE;


    IONDEBUG(ion_writer_open_buffer(&hwriter, buffer, BUF_SIZE, &options), "opening writer");

    IONDEBUG(ion_writer_write_null(hwriter), "writing simple null");

    // integer values
    IONDEBUG(ion_writer_write_int(hwriter, 10), "writing simple int");

    // double value

    IONDEBUG(ion_writer_write_double(hwriter, 123.5), "writing double");

    IONDEBUG(ion_writer_write_double(hwriter, -124.5), "writing double");

    IONDEBUG(ion_writer_write_double(hwriter, -123456789e20), "writing double");

    IONDEBUG(ion_writer_write_double(hwriter, -123456789e-20), "writing double");

    // decimal values
    IONDEBUG(ion_writer_write_decimal(hwriter, NULL), "writing decimal");

    decQuadFromUInt32(&dec1, 1234567890);
    IONDEBUG(ion_writer_write_decimal(hwriter, &dec1), "writing decimal");


    // a couple of symbols
    str.value = (BYTE *)"test_symbol";
    str.length = (SIZE)strlen((char*)str.value);
    err = ion_writer_write_symbol(hwriter, &str);
    IONDEBUG2(err, "writing symbol value: ", image);

    str.value = (BYTE *)"*%test_symbol";
    str.length = (SIZE)strlen((char*)str.value);
    err = ion_writer_write_symbol(hwriter, &str);
    IONDEBUG2(err, "writing symbol value: ", image);

    // a couple of strings
    str.value = (BYTE *)"test string";
    str.length = (SIZE)strlen((char*)str.value);
    err = ion_writer_write_string(hwriter, &str);
    IONDEBUG2(err, "writing string value: ", image);

    str.value = (BYTE *)"";
    str.length = (SIZE)strlen((char*)str.value);
    err = ion_writer_write_string(hwriter, &str);
    IONDEBUG2(err, "writing string value: ", image);

    str.value = (BYTE *)"line1\nline2";
    str.length = (SIZE)strlen((char*)str.value);
    err = ion_writer_write_string(hwriter, &str);
    IONDEBUG2(err, "writing string value: ", image);

    //clob
    image = "test clob \0 \n more stuff";
    len = copy_to_bytes(image, bytes, sizeof(bytes));
    err = ion_writer_write_clob(hwriter, bytes, len);
    IONDEBUG2(err, "writing clob value: ", image);

    //blob
    // The Input: leasure.   Encodes to bGVhc3VyZS4=
    image = "leasure.";
    len = copy_to_bytes(image, bytes, sizeof(bytes));
    err = ion_writer_write_blob(hwriter, bytes, len);
    IONDEBUG2(err, "writing blob value: ", image);

    // The Input: easure.    Encodes to ZWFzdXJlLg==
    image = "easure.";
    len = copy_to_bytes(image, bytes, sizeof(bytes));
    err = ion_writer_write_blob(hwriter, bytes, len);
    IONDEBUG2(err, "writing blob value: ", image);

    // The Input: asure.     Encodes to YXN1cmUu
    image = "asure.";
    len = copy_to_bytes(image, bytes, sizeof(bytes));
    err = ion_writer_write_blob(hwriter, bytes, len);
    IONDEBUG2(err, "writing blob value: ", image);

    // The Input: sure.      Encodes to c3VyZS4=
    image = "sure.";
    len = copy_to_bytes(image, bytes, sizeof(bytes));
    err = ion_writer_write_blob(hwriter, bytes, len);
    IONDEBUG2(err, "writing blob value: ", image);

    //struct
    IONDEBUG(ion_writer_start_container(hwriter, tid_STRUCT), "writing ion_writer_start_struct");

    IONDEBUG(ion_writer_finish_container(hwriter), "writing ion_writer_end_struct");

    //list
    IONDEBUG(ion_writer_start_container(hwriter, tid_LIST), "starting a LIST container");

    IONDEBUG(ion_writer_finish_container(hwriter), "ion_writer_finish_container for lisT");

    //sexp
    IONDEBUG(ion_writer_start_container(hwriter, tid_SEXP), "writing ion_writer_start_sexp");

    IONDEBUG(ion_writer_finish_container(hwriter), "ion_writer_finish_container for sexp");

    // reader - real soon now

    IONDEBUG(ion_writer_close(hwriter), "closing writer");







    hREADER hreader;
    ION_READER_OPTIONS option_r;
    memset(&option_r, 0, sizeof(option_r));

    option_r.return_system_values = TRUE;
    ion_reader_open_buffer(&hreader, buffer, BUF_SIZE, &option_r);
    test_reader_read_all(hreader);

    iRETURN;
}

int testSimple2() {
    iENTER;

    BYTE                buffer[BUF_SIZE+1];
    BYTE                bytes[100];
    hWRITER             hwriter;
    ION_WRITER_OPTIONS  options;
    double              d;
    ION_TIMESTAMP       timestamp;
    ION_STRING          str;
    char               *image;
    SIZE                used, len, bytes_flushed;

    memset(&buffer[0], 0, BUF_SIZE+1);
    memset(&options, 0, sizeof(options));

    options.output_as_binary = TRUE;

    ion_writer_open_buffer(&hwriter, buffer, BUF_SIZE, &options);
    ion_writer_start_container(hwriter, tid_STRUCT);
    STRING(str, "longFieldName_485u81");
    ion_writer_write_field_name(hwriter, &str);
    ion_writer_write_int32(hwriter, 81);
    STRING(str, "longFieldName_196u82");
    ion_writer_write_field_name(hwriter, &str);
    ion_writer_write_int32(hwriter, 82);
    STRING(str, "longFieldName_584u83");
    ion_writer_write_field_name(hwriter, &str);
    ion_writer_write_int32(hwriter, 83);
    STRING(str, "longFieldName_173u84");
    ion_writer_write_field_name(hwriter, &str);
    ion_writer_write_int32(hwriter, 84);
    STRING(str, "longFieldName_873u85");
    ion_writer_write_field_name(hwriter, &str);
    ion_writer_write_int32(hwriter, 85);
    STRING(str, "longFieldName_494u321");
    ion_writer_write_field_name(hwriter, &str);
    ion_writer_write_int32(hwriter, 326887201);
    STRING(str, "longFieldName_137u322");
    ion_writer_write_field_name(hwriter, &str);
    ion_writer_write_int32(hwriter, 326887202);
    STRING(str, "longFieldName_664u323");
    ion_writer_write_field_name(hwriter, &str);
    ion_writer_write_int32(hwriter, 326887203);
    STRING(str, "longFieldName_871u324");
    ion_writer_write_field_name(hwriter, &str);
    ion_writer_write_int32(hwriter, 326887204);
    STRING(str, "longFieldName_142u325");
    ion_writer_write_field_name(hwriter, &str);
    ion_writer_write_int32(hwriter, 326887205);
    STRING(str, "longFieldName_221u161");
    ion_writer_write_field_name(hwriter, &str);
    ion_writer_write_int32(hwriter, 16001);
    STRING(str, "longFieldName_115u162");
    ion_writer_write_field_name(hwriter, &str);
    ion_writer_write_int32(hwriter, 16002);
    STRING(str, "longFieldName_212u163");
    ion_writer_write_field_name(hwriter, &str);
    ion_writer_write_int32(hwriter, 16003);
    STRING(str, "longFieldName_585u164");
    ion_writer_write_field_name(hwriter, &str);
    ion_writer_write_int32(hwriter, 16004);
    STRING(str, "longFieldName_012u165");
    ion_writer_write_field_name(hwriter, &str);
    ion_writer_write_int32(hwriter, 16005);
    STRING(str, "longFieldName_141u641");
    ion_writer_write_field_name(hwriter, &str);
    ion_writer_write_int32(hwriter, 64984721911L);
    STRING(str, "longFieldName_665u642");
    ion_writer_write_field_name(hwriter, &str);
    ion_writer_write_int32(hwriter, 64984721912L);
    STRING(str, "longFieldName_988u643");
    ion_writer_write_field_name(hwriter, &str);
    ion_writer_write_int32(hwriter, 64984721913L);
    STRING(str, "longFieldName_774u644");
    ion_writer_write_field_name(hwriter, &str);
    ion_writer_write_int32(hwriter, 64984721914L);
    STRING(str, "longFieldName_004u645");
    ion_writer_write_field_name(hwriter, &str);
    ion_writer_write_int32(hwriter, 64984721910L);
    ion_writer_finish_container(hwriter);
    ion_writer_flush(hwriter, &bytes_flushed);
    ion_writer_close(hwriter);


    hREADER hreader;
    ION_READER_OPTIONS option_r;
    memset(&option_r, 0, sizeof(option_r));

    option_r.return_system_values = TRUE;
    ion_reader_open_buffer(&hreader, buffer, BUF_SIZE, &option_r);
    test_reader_read_all(hreader);

//    STRING(str, "longFieldName_774u644")
//    ion_reader_get_field_name(hreader, &str);
//    int32_t number;
//    ion_reader_read_int32(hreader, &number);
//    std::cout << str.value << "number: " << number << std::endl;
    iRETURN;
}


int main() {
    testSimple2();

    return 0;
}



#define TEMP_BUF_SIZE 0x10000

iERR test_reader_read_value_no_print(hREADER hreader, ION_TYPE t)
{
    iENTER;

    ION_TYPE    ion_type;
    BOOL        is_null;
    BOOL        bool_value;
    ION_INT     ion_int_value;
    double      double_value;
    decQuad     decimal_value;
    ION_TIMESTAMP timestamp_value;
    SID         sid;
    ION_STRING  string_value, *indirect_string_value = NULL;
    SIZE        length, remaining;
    BYTE        buf[TEMP_BUF_SIZE];
    hSYMTAB     hsymtab = 0;

    IONCHECK(ion_reader_is_null(hreader, &is_null));
    if (is_null) {
        t = tid_NULL;
    }

    switch (ION_TYPE_INT(t)) {
        case tid_EOF_INT:
            // do nothing
            break;
        case tid_NULL_INT:
        IONCHECK(ion_reader_read_null(hreader, &ion_type));
            break;
        case tid_BOOL_INT:
        IONCHECK(ion_reader_read_bool(hreader, &bool_value));
            break;
        case tid_INT_INT:
        IONCHECK(ion_int_init(&ion_int_value, hreader));
            IONCHECK(ion_reader_read_ion_int(hreader, &ion_int_value));
            // IONCHECK(ion_reader_read_int64(hreader, &long_value));
            break;
        case tid_FLOAT_INT:
        IONCHECK(ion_reader_read_double(hreader, &double_value));
            break;
        case tid_DECIMAL_INT:
        IONCHECK(ion_reader_read_decimal(hreader, &decimal_value));
            break;
        case tid_TIMESTAMP_INT:
        IONCHECK(ion_reader_read_timestamp(hreader, &timestamp_value));
            break;
        case tid_STRING_INT:
        IONCHECK(ion_reader_read_string(hreader, &string_value));
            break;
        case tid_SYMBOL_INT:
        IONCHECK(ion_reader_read_symbol_sid(hreader, &sid));
            // you can only read a value once! IONCHECK(ion_reader_read_string(hreader, &string_value));
            // so we look it up
            IONCHECK(ion_reader_get_symbol_table(hreader, &hsymtab));
            IONCHECK(ion_symbol_table_find_by_sid(hsymtab, sid, &indirect_string_value));
            break;
        case tid_CLOB_INT:
        case tid_BLOB_INT:
        IONCHECK(ion_reader_get_lob_size(hreader, &length));
            // just to cover both API's
            if (length < TEMP_BUF_SIZE) {
                IONCHECK(ion_reader_read_lob_bytes(hreader, buf, TEMP_BUF_SIZE, &length));
            }
            else {
                for (remaining = length; remaining > 0; remaining -= length) {
                    IONCHECK(ion_reader_read_lob_bytes(hreader, buf, TEMP_BUF_SIZE, &length));
                    // IONCHECK(ion_reader_read_chunk(hreader, buf, TEMP_BUF_SIZE, &length));
                }
            }
            break;
        case tid_STRUCT_INT:
        case tid_LIST_INT:
        case tid_SEXP_INT:
        IONCHECK(ion_reader_step_in(hreader));
            IONCHECK(test_reader_read_all(hreader));
            IONCHECK(ion_reader_step_out(hreader));
            break;

        case tid_DATAGRAM_INT:
        default:
            break;
    }

    iRETURN;
}

iERR test_reader_read_value_print(hREADER hreader, ION_TYPE t, char *type_name)
{
    iENTER;

    ION_TYPE    ion_type;
    BOOL        is_null;
    BOOL        bool_value;
    ION_INT     ion_int_value;
    double      double_value;
    decQuad     decimal_value;
    ION_TIMESTAMP timestamp_value;
    SID         sid;
    ION_STRING  string_value, *indirect_string_value = NULL;
    SIZE        length;
    BYTE        buf[TEMP_BUF_SIZE];
    char        decimal_image_buffer[DECQUAD_String];
    char        time_buffer[ION_TIMESTAMP_STRING_LENGTH + 1];
    char       *sym_name;
    hSYMTAB     hsymtab = 0;

    printf("read type %s:: ", type_name);

    IONCHECK(ion_reader_is_null(hreader, &is_null));
    if (is_null) {
        t = tid_NULL;
    }

    switch (ION_TYPE_INT(t)) {
        case tid_EOF_INT:
            // do nothing
            break;
        case tid_NULL_INT:
        IONCHECK(ion_reader_read_null(hreader, &ion_type));
            printf("value: null typed as %d", (intptr_t)ion_type);
            break;
        case tid_BOOL_INT:
        IONCHECK(ion_reader_read_bool(hreader, &bool_value));
            printf("value: %d (%s)", bool_value, bool_value ? "true" : "false");
            break;
        case tid_INT_INT:
            //IONCHECK(ion_reader_read_int(hreader, &xx));
            //IONCHECK(ion_reader_read_int64(hreader, &long_value));
        IONCHECK(ion_int_init(&ion_int_value, hreader));
            IONCHECK(ion_reader_read_ion_int(hreader, &ion_int_value));
            ION_STRING_INIT(&string_value);
            IONCHECK(ion_int_to_string(&ion_int_value, hreader, &string_value));
            printf("value: %s", string_value.value);
            break;
        case tid_FLOAT_INT:
        IONCHECK(ion_reader_read_double(hreader, &double_value));
            printf("value: %f", double_value);
            break;
        case tid_DECIMAL_INT:
        IONCHECK(ion_reader_read_decimal(hreader, &decimal_value));
            decQuadToString(&decimal_value, decimal_image_buffer);
//        IONCHECK(ion_reader_read_double(hreader, &double_value));
//        printf("value: %f, '%s'", double_value, decimal_image_buffer);
            printf("value: '%s'", decimal_image_buffer);
            break;
        case tid_TIMESTAMP_INT:
        IONCHECK(ion_reader_read_timestamp(hreader, &timestamp_value));
//            IONCHECK( ion_timestamp_to_string(&timestamp_value, time_buffer, sizeof(time_buffer), &length, &deccontext));
            assert( length > 1 && length < sizeof(time_buffer) && time_buffer[length] == '\0' );
            printf("value: %s", time_buffer);
            break;
        case tid_STRING_INT:
        IONCHECK(ion_reader_read_string(hreader, &string_value));
            printf("value: \"%s\"", test_make_cstr(&string_value));
            break;
        case tid_SYMBOL_INT:
        IONCHECK(ion_reader_read_symbol_sid(hreader, &sid));
            // you can only read a value once! IONCHECK(ion_reader_read_string(hreader, &string_value));
            // so we look it up
            IONCHECK(ion_reader_get_symbol_table(hreader, &hsymtab));
            IONCHECK(ion_symbol_table_find_by_sid(hsymtab, sid, &indirect_string_value));
            if (!indirect_string_value) {
                sym_name = "<not found>";
            }
            else {
                sym_name = test_make_cstr(indirect_string_value);
            }
            printf("value: %d \"%s\"", sid, sym_name);
            break;
        case tid_CLOB_INT:
        case tid_BLOB_INT:
        IONCHECK(ion_reader_get_lob_size(hreader, &length));
            printf("value length: %d", length);
            IONCHECK(ion_reader_read_lob_bytes(hreader, buf, TEMP_BUF_SIZE, &length));
            //IONCHECK(ion_reader_read_chunk(hreader, &xx));
            break;
        case tid_STRUCT_INT:
        case tid_LIST_INT:
        case tid_SEXP_INT:
            //printf("--- support for collections is not ready");
            printf("value - step into %s\n", type_name);
            IONCHECK(ion_reader_step_in(hreader));
            IONCHECK(test_reader_read_all(hreader));
            IONCHECK(ion_reader_step_out(hreader));
            printf("value - now out of %s\n", type_name);
            break;

        case tid_DATAGRAM_INT:
        default:
            printf(" - can't read value on an illegal type\n");
            break;
    }

    printf("\n");

    iRETURN;
}

char temp_buffer[MAX_TEMP_STRING];
char *test_make_cstr(iSTRING str)
{
    assert(str && str->value);

    int len;
    if ( str->length < MAX_TEMP_STRING ) {
        len = str->length;
    }
    else {
        len = MAX_TEMP_STRING - 1;
    }

    // needs to have UTF-8 support here
    memcpy(temp_buffer, str->value, len);

    temp_buffer[len] = '\0';

    return temp_buffer;
}