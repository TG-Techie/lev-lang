#pragma once

#include "varad_macro.h"


#define _to_macro_call_a(macroname, ...) macroname(__VA_ARGS__)
#define _to_macro_call_b(macroname, ...) macroname(__VA_ARGS__)
#define _to_macro_call_c(macroname, ...) macroname(__VA_ARGS__)
#define _call_strip(...) strip_trailing(__VA_ARGS__)


#define mbrof(varname, vartype, mbrs) \
    _to_macro_call_a(_mbrof_once_stripped, varname, vartype, _call_strip( _unpack_##mbrs ))
#define _mbrof_once_stripped(varname, vartype, mbrs) \
    _to_macro_call_b(_direct_mbrof_call, varname, vartype, mbrs, num_##mbrs)
#define _direct_mbrof_call(varname, vartype, mbrs, count) \
    _to_macro_call_c(_mbrof_chain_##count, var_##varname, vartype, _unpack_##mbrs)
        //_fmt_mbrof(var_##varname, vartype, _unpack_##mbrs)

        // chain_accessed_mbrs(\
        //     content_ptr_##vartype(&var_##varname), \
        //     _unpack_##mbrs\
        // )\



#define _unpack_mbrs(...) __VA_ARGS__
#define _unpack_mbr(name, type) name, type

// this accounts for a trailling comma on mbrs(...) lists
#define strip_trailing(first, ...) mbrs(first VARAD_VARNT_MACRO(strip_, __VA_ARGS__))
#define VARNT_IMPL_strip_
#define VARNT_IMPL_strip_mbr(name, type) ,mbr(name, type)

// MODIFIED: https://stackoverflow.com/questions/2124339/c-preprocessor-va-args-number-of-arguments
#define num_mbrs(...) NUM_VARAD_ARGS(__VA_ARGS__)
#define NUM_VARAD_ARGS(...) \
         NUM_VARAD_ARGS_(__VA_ARGS__,PP_RSEQ_N())
#define NUM_VARAD_ARGS_(...) \
         PP_ARG_N(__VA_ARGS__)
#define PP_ARG_N( \
          _1, _2, _3, _4, _5, _6, _7, _8, _9,_10, \
         _11,_12,_13,_14,_15,_16,_17,_18,_19,_20, \
         _21,_22,_23,_24,_25,_26,_27,_28,_29,_30, \
         _31,_32,_33,_34,_35,_36,_37,_38,_39,_40, \
         _41,_42,_43,_44,_45,_46,_47,_48,_49,_50, \
         _51,_52,_53,_54,_55,_56,_57,_58,_59,_60, \
         _61,_62,_63,N,...) N
#define PP_RSEQ_N() \
         63,62,61,60,                   \
         59,58,57,56,55,54,53,52,51,50, \
         49,48,47,46,45,44,43,42,41,40, \
         39,38,37,36,35,34,33,32,31,30, \
         29,28,27,26,25,24,23,22,21,20, \
         19,18,17,16,15,14,13,12,11,10, \
         9,8,7,6,5,4,3,2,1,0

//terminal case

#define _mbrof_chain_1(var, vartype, mbr) \
    _call_link_1(var, vartype, _unpack_##mbr)
#define _call_link_1(...) _link_1(__VA_ARGS__)
#define _link_1(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname //, mbrtype

// rest fo the cases

#define _mbrof_chain_2(var, vartype, mbr, ...) \
    _call_chain_1_from_2(_call_link_2(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_2(...) _link_2(__VA_ARGS__)
#define _call_chain_1_from_2(...) _mbrof_chain_1(__VA_ARGS__)
#define _link_2(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_3(var, vartype, mbr, ...) \
    _call_chain_2_from_3(_call_link_3(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_3(...) _link_3(__VA_ARGS__)
#define _call_chain_2_from_3(...) _mbrof_chain_2(__VA_ARGS__)
#define _link_3(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_4(var, vartype, mbr, ...) \
    _call_chain_3_from_4(_call_link_4(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_4(...) _link_4(__VA_ARGS__)
#define _call_chain_3_from_4(...) _mbrof_chain_3(__VA_ARGS__)
#define _link_4(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_5(var, vartype, mbr, ...) \
    _call_chain_4_from_5(_call_link_5(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_5(...) _link_5(__VA_ARGS__)
#define _call_chain_4_from_5(...) _mbrof_chain_4(__VA_ARGS__)
#define _link_5(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_6(var, vartype, mbr, ...) \
    _call_chain_5_from_6(_call_link_6(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_6(...) _link_6(__VA_ARGS__)
#define _call_chain_5_from_6(...) _mbrof_chain_5(__VA_ARGS__)
#define _link_6(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_7(var, vartype, mbr, ...) \
    _call_chain_6_from_7(_call_link_7(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_7(...) _link_7(__VA_ARGS__)
#define _call_chain_6_from_7(...) _mbrof_chain_6(__VA_ARGS__)
#define _link_7(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_8(var, vartype, mbr, ...) \
    _call_chain_7_from_8(_call_link_8(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_8(...) _link_8(__VA_ARGS__)
#define _call_chain_7_from_8(...) _mbrof_chain_7(__VA_ARGS__)
#define _link_8(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_9(var, vartype, mbr, ...) \
    _call_chain_8_from_9(_call_link_9(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_9(...) _link_9(__VA_ARGS__)
#define _call_chain_8_from_9(...) _mbrof_chain_8(__VA_ARGS__)
#define _link_9(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_10(var, vartype, mbr, ...) \
    _call_chain_9_from_10(_call_link_10(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_10(...) _link_10(__VA_ARGS__)
#define _call_chain_9_from_10(...) _mbrof_chain_9(__VA_ARGS__)
#define _link_10(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_11(var, vartype, mbr, ...) \
    _call_chain_10_from_11(_call_link_11(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_11(...) _link_11(__VA_ARGS__)
#define _call_chain_10_from_11(...) _mbrof_chain_10(__VA_ARGS__)
#define _link_11(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_12(var, vartype, mbr, ...) \
    _call_chain_11_from_12(_call_link_12(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_12(...) _link_12(__VA_ARGS__)
#define _call_chain_11_from_12(...) _mbrof_chain_11(__VA_ARGS__)
#define _link_12(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_13(var, vartype, mbr, ...) \
    _call_chain_12_from_13(_call_link_13(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_13(...) _link_13(__VA_ARGS__)
#define _call_chain_12_from_13(...) _mbrof_chain_12(__VA_ARGS__)
#define _link_13(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_14(var, vartype, mbr, ...) \
    _call_chain_13_from_14(_call_link_14(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_14(...) _link_14(__VA_ARGS__)
#define _call_chain_13_from_14(...) _mbrof_chain_13(__VA_ARGS__)
#define _link_14(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_15(var, vartype, mbr, ...) \
    _call_chain_14_from_15(_call_link_15(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_15(...) _link_15(__VA_ARGS__)
#define _call_chain_14_from_15(...) _mbrof_chain_14(__VA_ARGS__)
#define _link_15(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_16(var, vartype, mbr, ...) \
    _call_chain_15_from_16(_call_link_16(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_16(...) _link_16(__VA_ARGS__)
#define _call_chain_15_from_16(...) _mbrof_chain_15(__VA_ARGS__)
#define _link_16(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_17(var, vartype, mbr, ...) \
    _call_chain_16_from_17(_call_link_17(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_17(...) _link_17(__VA_ARGS__)
#define _call_chain_16_from_17(...) _mbrof_chain_16(__VA_ARGS__)
#define _link_17(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_18(var, vartype, mbr, ...) \
    _call_chain_17_from_18(_call_link_18(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_18(...) _link_18(__VA_ARGS__)
#define _call_chain_17_from_18(...) _mbrof_chain_17(__VA_ARGS__)
#define _link_18(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_19(var, vartype, mbr, ...) \
    _call_chain_18_from_19(_call_link_19(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_19(...) _link_19(__VA_ARGS__)
#define _call_chain_18_from_19(...) _mbrof_chain_18(__VA_ARGS__)
#define _link_19(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_20(var, vartype, mbr, ...) \
    _call_chain_19_from_20(_call_link_20(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_20(...) _link_20(__VA_ARGS__)
#define _call_chain_19_from_20(...) _mbrof_chain_19(__VA_ARGS__)
#define _link_20(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_21(var, vartype, mbr, ...) \
    _call_chain_20_from_21(_call_link_21(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_21(...) _link_21(__VA_ARGS__)
#define _call_chain_20_from_21(...) _mbrof_chain_20(__VA_ARGS__)
#define _link_21(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_22(var, vartype, mbr, ...) \
    _call_chain_21_from_22(_call_link_22(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_22(...) _link_22(__VA_ARGS__)
#define _call_chain_21_from_22(...) _mbrof_chain_21(__VA_ARGS__)
#define _link_22(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_23(var, vartype, mbr, ...) \
    _call_chain_22_from_23(_call_link_23(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_23(...) _link_23(__VA_ARGS__)
#define _call_chain_22_from_23(...) _mbrof_chain_22(__VA_ARGS__)
#define _link_23(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_24(var, vartype, mbr, ...) \
    _call_chain_23_from_24(_call_link_24(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_24(...) _link_24(__VA_ARGS__)
#define _call_chain_23_from_24(...) _mbrof_chain_23(__VA_ARGS__)
#define _link_24(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_25(var, vartype, mbr, ...) \
    _call_chain_24_from_25(_call_link_25(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_25(...) _link_25(__VA_ARGS__)
#define _call_chain_24_from_25(...) _mbrof_chain_24(__VA_ARGS__)
#define _link_25(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_26(var, vartype, mbr, ...) \
    _call_chain_25_from_26(_call_link_26(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_26(...) _link_26(__VA_ARGS__)
#define _call_chain_25_from_26(...) _mbrof_chain_25(__VA_ARGS__)
#define _link_26(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_27(var, vartype, mbr, ...) \
    _call_chain_26_from_27(_call_link_27(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_27(...) _link_27(__VA_ARGS__)
#define _call_chain_26_from_27(...) _mbrof_chain_26(__VA_ARGS__)
#define _link_27(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_28(var, vartype, mbr, ...) \
    _call_chain_27_from_28(_call_link_28(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_28(...) _link_28(__VA_ARGS__)
#define _call_chain_27_from_28(...) _mbrof_chain_27(__VA_ARGS__)
#define _link_28(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_29(var, vartype, mbr, ...) \
    _call_chain_28_from_29(_call_link_29(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_29(...) _link_29(__VA_ARGS__)
#define _call_chain_28_from_29(...) _mbrof_chain_28(__VA_ARGS__)
#define _link_29(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_30(var, vartype, mbr, ...) \
    _call_chain_29_from_30(_call_link_30(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_30(...) _link_30(__VA_ARGS__)
#define _call_chain_29_from_30(...) _mbrof_chain_29(__VA_ARGS__)
#define _link_30(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_31(var, vartype, mbr, ...) \
    _call_chain_30_from_31(_call_link_31(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_31(...) _link_31(__VA_ARGS__)
#define _call_chain_30_from_31(...) _mbrof_chain_30(__VA_ARGS__)
#define _link_31(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_32(var, vartype, mbr, ...) \
    _call_chain_31_from_32(_call_link_32(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_32(...) _link_32(__VA_ARGS__)
#define _call_chain_31_from_32(...) _mbrof_chain_31(__VA_ARGS__)
#define _link_32(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_33(var, vartype, mbr, ...) \
    _call_chain_32_from_33(_call_link_33(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_33(...) _link_33(__VA_ARGS__)
#define _call_chain_32_from_33(...) _mbrof_chain_32(__VA_ARGS__)
#define _link_33(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_34(var, vartype, mbr, ...) \
    _call_chain_33_from_34(_call_link_34(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_34(...) _link_34(__VA_ARGS__)
#define _call_chain_33_from_34(...) _mbrof_chain_33(__VA_ARGS__)
#define _link_34(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_35(var, vartype, mbr, ...) \
    _call_chain_34_from_35(_call_link_35(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_35(...) _link_35(__VA_ARGS__)
#define _call_chain_34_from_35(...) _mbrof_chain_34(__VA_ARGS__)
#define _link_35(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_36(var, vartype, mbr, ...) \
    _call_chain_35_from_36(_call_link_36(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_36(...) _link_36(__VA_ARGS__)
#define _call_chain_35_from_36(...) _mbrof_chain_35(__VA_ARGS__)
#define _link_36(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_37(var, vartype, mbr, ...) \
    _call_chain_36_from_37(_call_link_37(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_37(...) _link_37(__VA_ARGS__)
#define _call_chain_36_from_37(...) _mbrof_chain_36(__VA_ARGS__)
#define _link_37(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_38(var, vartype, mbr, ...) \
    _call_chain_37_from_38(_call_link_38(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_38(...) _link_38(__VA_ARGS__)
#define _call_chain_37_from_38(...) _mbrof_chain_37(__VA_ARGS__)
#define _link_38(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_39(var, vartype, mbr, ...) \
    _call_chain_38_from_39(_call_link_39(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_39(...) _link_39(__VA_ARGS__)
#define _call_chain_38_from_39(...) _mbrof_chain_38(__VA_ARGS__)
#define _link_39(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_40(var, vartype, mbr, ...) \
    _call_chain_39_from_40(_call_link_40(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_40(...) _link_40(__VA_ARGS__)
#define _call_chain_39_from_40(...) _mbrof_chain_39(__VA_ARGS__)
#define _link_40(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_41(var, vartype, mbr, ...) \
    _call_chain_40_from_41(_call_link_41(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_41(...) _link_41(__VA_ARGS__)
#define _call_chain_40_from_41(...) _mbrof_chain_40(__VA_ARGS__)
#define _link_41(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_42(var, vartype, mbr, ...) \
    _call_chain_41_from_42(_call_link_42(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_42(...) _link_42(__VA_ARGS__)
#define _call_chain_41_from_42(...) _mbrof_chain_41(__VA_ARGS__)
#define _link_42(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_43(var, vartype, mbr, ...) \
    _call_chain_42_from_43(_call_link_43(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_43(...) _link_43(__VA_ARGS__)
#define _call_chain_42_from_43(...) _mbrof_chain_42(__VA_ARGS__)
#define _link_43(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_44(var, vartype, mbr, ...) \
    _call_chain_43_from_44(_call_link_44(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_44(...) _link_44(__VA_ARGS__)
#define _call_chain_43_from_44(...) _mbrof_chain_43(__VA_ARGS__)
#define _link_44(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_45(var, vartype, mbr, ...) \
    _call_chain_44_from_45(_call_link_45(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_45(...) _link_45(__VA_ARGS__)
#define _call_chain_44_from_45(...) _mbrof_chain_44(__VA_ARGS__)
#define _link_45(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_46(var, vartype, mbr, ...) \
    _call_chain_45_from_46(_call_link_46(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_46(...) _link_46(__VA_ARGS__)
#define _call_chain_45_from_46(...) _mbrof_chain_45(__VA_ARGS__)
#define _link_46(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_47(var, vartype, mbr, ...) \
    _call_chain_46_from_47(_call_link_47(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_47(...) _link_47(__VA_ARGS__)
#define _call_chain_46_from_47(...) _mbrof_chain_46(__VA_ARGS__)
#define _link_47(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_48(var, vartype, mbr, ...) \
    _call_chain_47_from_48(_call_link_48(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_48(...) _link_48(__VA_ARGS__)
#define _call_chain_47_from_48(...) _mbrof_chain_47(__VA_ARGS__)
#define _link_48(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_49(var, vartype, mbr, ...) \
    _call_chain_48_from_49(_call_link_49(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_49(...) _link_49(__VA_ARGS__)
#define _call_chain_48_from_49(...) _mbrof_chain_48(__VA_ARGS__)
#define _link_49(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_50(var, vartype, mbr, ...) \
    _call_chain_49_from_50(_call_link_50(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_50(...) _link_50(__VA_ARGS__)
#define _call_chain_49_from_50(...) _mbrof_chain_49(__VA_ARGS__)
#define _link_50(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_51(var, vartype, mbr, ...) \
    _call_chain_50_from_51(_call_link_51(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_51(...) _link_51(__VA_ARGS__)
#define _call_chain_50_from_51(...) _mbrof_chain_50(__VA_ARGS__)
#define _link_51(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_52(var, vartype, mbr, ...) \
    _call_chain_51_from_52(_call_link_52(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_52(...) _link_52(__VA_ARGS__)
#define _call_chain_51_from_52(...) _mbrof_chain_51(__VA_ARGS__)
#define _link_52(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_53(var, vartype, mbr, ...) \
    _call_chain_52_from_53(_call_link_53(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_53(...) _link_53(__VA_ARGS__)
#define _call_chain_52_from_53(...) _mbrof_chain_52(__VA_ARGS__)
#define _link_53(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_54(var, vartype, mbr, ...) \
    _call_chain_53_from_54(_call_link_54(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_54(...) _link_54(__VA_ARGS__)
#define _call_chain_53_from_54(...) _mbrof_chain_53(__VA_ARGS__)
#define _link_54(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_55(var, vartype, mbr, ...) \
    _call_chain_54_from_55(_call_link_55(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_55(...) _link_55(__VA_ARGS__)
#define _call_chain_54_from_55(...) _mbrof_chain_54(__VA_ARGS__)
#define _link_55(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_56(var, vartype, mbr, ...) \
    _call_chain_55_from_56(_call_link_56(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_56(...) _link_56(__VA_ARGS__)
#define _call_chain_55_from_56(...) _mbrof_chain_55(__VA_ARGS__)
#define _link_56(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_57(var, vartype, mbr, ...) \
    _call_chain_56_from_57(_call_link_57(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_57(...) _link_57(__VA_ARGS__)
#define _call_chain_56_from_57(...) _mbrof_chain_56(__VA_ARGS__)
#define _link_57(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_58(var, vartype, mbr, ...) \
    _call_chain_57_from_58(_call_link_58(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_58(...) _link_58(__VA_ARGS__)
#define _call_chain_57_from_58(...) _mbrof_chain_57(__VA_ARGS__)
#define _link_58(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_59(var, vartype, mbr, ...) \
    _call_chain_58_from_59(_call_link_59(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_59(...) _link_59(__VA_ARGS__)
#define _call_chain_58_from_59(...) _mbrof_chain_58(__VA_ARGS__)
#define _link_59(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_60(var, vartype, mbr, ...) \
    _call_chain_59_from_60(_call_link_60(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_60(...) _link_60(__VA_ARGS__)
#define _call_chain_59_from_60(...) _mbrof_chain_59(__VA_ARGS__)
#define _link_60(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_61(var, vartype, mbr, ...) \
    _call_chain_60_from_61(_call_link_61(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_61(...) _link_61(__VA_ARGS__)
#define _call_chain_60_from_61(...) _mbrof_chain_60(__VA_ARGS__)
#define _link_61(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_62(var, vartype, mbr, ...) \
    _call_chain_61_from_62(_call_link_62(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_62(...) _link_62(__VA_ARGS__)
#define _call_chain_61_from_62(...) _mbrof_chain_61(__VA_ARGS__)
#define _link_62(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_63(var, vartype, mbr, ...) \
    _call_chain_62_from_63(_call_link_63(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_63(...) _link_63(__VA_ARGS__)
#define _call_chain_62_from_63(...) _mbrof_chain_62(__VA_ARGS__)
#define _link_63(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_64(var, vartype, mbr, ...) \
    _call_chain_63_from_64(_call_link_64(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_64(...) _link_64(__VA_ARGS__)
#define _call_chain_63_from_64(...) _mbrof_chain_63(__VA_ARGS__)
#define _link_64(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype



#define _mbrof_chain_65(var, vartype, mbr, ...) \
    _call_chain_64_from_65(_call_link_65(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_65(...) _link_65(__VA_ARGS__)
#define _call_chain_64_from_65(...) _mbrof_chain_64(__VA_ARGS__)
#define _link_65(prev, prevtype, mbrname, mbrtype) \
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype
