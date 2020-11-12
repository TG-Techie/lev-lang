/* USAGE:

#define body_mbrs(...) { VARAD_MACRO(body, __VA_ARGS__) }
#define IMPL_VARNT_body
#define IMPL_VARNT_bodymbr(name, type) type name;

#define bodyget_mbrs(...) VARAD_MACRO(bodyget, __VA_ARGS__)
#define IMPL_VARNT_bodyget
#define IMPL_VARNT_bodygetmbr(name, type) ref_##type(self.name),

#define foos(...) { VARAD_MACRO(, __VA_ARGS__) }
#define IMPL_VARNT_foo(name) foo_bar_##name,



#define struct(typename, members)\
    typedef struct typename\
         body_##members\
    typename;\
    typename get_##typename(typename self){\
        return (typename){ bodyget_##members };\
    }\



struct(barsct, mbrs(
    mbr(x, int),
    mbr(y, int),
    mbr(z, int)
))


foos(
    foo(5)
)
*/

#define VARAD_MACRO(impl_kind, ...) VARAD_MACRO_128(impl_kind, __VA_ARGS__)
#define IMPL_VARAD_

#define VARAD_MACRO_00(impl_kind, arg) IMPL_VARAD_##impl_kind##arg
#define VARAD_MACRO_01(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_00(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_02(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_01(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_03(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_02(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_04(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_03(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_05(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_04(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_06(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_05(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_07(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_06(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_08(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_07(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_09(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_08(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_10(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_09(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_11(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_10(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_12(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_11(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_13(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_12(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_14(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_13(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_15(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_14(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_16(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_15(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_17(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_16(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_18(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_17(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_19(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_18(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_20(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_19(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_21(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_20(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_22(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_21(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_23(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_22(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_24(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_23(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_25(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_24(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_26(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_25(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_27(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_26(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_28(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_27(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_29(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_28(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_30(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_29(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_31(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_30(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_32(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_31(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_33(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_32(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_34(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_33(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_35(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_34(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_36(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_35(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_37(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_36(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_38(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_37(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_39(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_38(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_40(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_39(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_41(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_40(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_42(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_41(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_43(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_42(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_44(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_43(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_45(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_44(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_46(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_45(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_47(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_46(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_48(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_47(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_49(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_48(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_50(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_49(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_51(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_50(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_52(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_51(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_53(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_52(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_54(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_53(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_55(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_54(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_56(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_55(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_57(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_56(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_58(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_57(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_59(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_58(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_60(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_59(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_61(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_60(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_62(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_61(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_63(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_62(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_64(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_63(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_65(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_64(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_66(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_65(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_67(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_66(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_68(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_67(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_69(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_68(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_70(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_69(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_71(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_70(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_72(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_71(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_73(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_72(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_74(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_73(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_75(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_74(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_76(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_75(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_77(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_76(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_78(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_77(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_79(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_78(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_80(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_79(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_81(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_80(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_82(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_81(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_83(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_82(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_84(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_83(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_85(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_84(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_86(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_85(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_87(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_86(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_88(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_87(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_89(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_88(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_90(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_89(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_91(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_90(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_92(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_91(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_93(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_92(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_94(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_93(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_95(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_94(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_96(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_95(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_97(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_96(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_98(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_97(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_99(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_98(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_100(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_99(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_101(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_100(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_102(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_101(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_103(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_102(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_104(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_103(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_105(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_104(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_106(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_105(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_107(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_106(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_108(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_107(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_109(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_108(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_110(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_109(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_111(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_110(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_112(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_111(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_113(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_112(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_114(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_113(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_115(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_114(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_116(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_115(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_117(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_116(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_118(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_117(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_119(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_118(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_120(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_119(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_121(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_120(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_122(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_121(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_123(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_122(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_124(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_123(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_125(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_124(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_126(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_125(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_127(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_126(impl_kind, __VA_ARGS__)
#define VARAD_MACRO_128(impl_kind, arg, ...) IMPL_VARAD_##impl_kind##arg VARAD_MACRO_127(impl_kind, __VA_ARGS__)





//////// MAJOR CHAGNE caller is responcible for reference counting!
//////// the callee is responcible for free-ing

typedef uint64_t RefCount;

/* need auto-gen:
new: new_<name>(args ... )
    makes a new instance of the type as a function call
get: get_<name>(self) -> Self
    get a local variable for use in expr
ref: reference: ref_<name>(self) -> void
    for ref-types this takes a refence to it, does nothing for structs.
    any ref must be released at scope exit
rel: release:  rel_<name>(self) -> void
    called when relasing a refernce or local struct. for both cls it decs the
    refcount and frees it if
ret:  ret_<name>(self) -> Self
    does nothing for structs beside pass thorugh, for classes it decs the
    ref count but does not free
getmbr: #this is a macro : getmbr_<name>() -> type(Member)
    used to get members
*/

// declarations


#define fn(name, args, type, body)\
    type fn_##name args body
    /*
        fn(print () bltn_nothing{
            ... blah
        })
    */
#define bodynew_from_mbrs(...) { VARAD_MACRO(bodynew, __VA_ARGS__) }
#define IMPL_VARAD_bodynew
#define IMPL_VARAD_bodynewmbr(name, type) type name;

#define bodyget_from_mbrs(...) VARAD_MACRO(bodyget, __VA_ARGS__)
#define IMPL_VARAD_bodyget
#define IMPL_VARAD_bodygetmbr(name, type) get_##type(self.name),


#define class(typename, members)\
    typedef struct content_##typename\
        bodynew_from_##members\
    content_##typename;\
    typedef struct typename\
        { RefCount rc;\
          content_##typename content;\
        }\
    *typename;\
    content_##typename getcontent_##typename(typename self){\
        return self->content;\
    }\
    typename new_##typename(content_##typename content) {\
        typename self = malloc(sizeof(struct typename));\
        self->rc = 0;\
        self->content = content;\
        return self;\
    }\
    typename ref_##typename(typename self){\
        self->rc +=1;\
        return self;\
    }\


#define struct(typename, members)\
    typedef struct typename\
        bodynew_from_##members\
    typename;\
    typedef typename content_##typename;\
    content_##typename getcontent_##typename(typename self){\
        return self;\
    }\
    typename new_##typename(content_##typename self) {\
        return self;\
    }\
    typename ref_##typename(typename self){\
        return self;\
    }\


// expressions
#define get(value, type)\
    get_##type(value)

#define call(fnname, args)\
    fn_##fnname args

#define getmbr(value, name, type) \
    getcontent_##type(value).mbr_##name

#define new(type, content) \
    new_##type(content)

// stamtements
#define dec(name, type)\
    type name;
#define ref(value, type)\
    ref_##type(value);
#define rel(value, type)\
    rel_##type(value);

// #define asn(name, value, type)\
//     rel_##type(name);\
//     name = value;\
//     ref_##type(name);

#define asn(name, value, type)\
    rel_##type(name);\
    name = value;\


#define ret(value, type)\
    return ret_##type(value);

#define brk break;

#define cont continue;

// compound statments
#define loop(body) \
    while (1) body;
/* usage:
    loop({
        code here ...
    })
*/

// #define cls(name) name
// #define sct(name) name


int main(void){
    return 0;
}




struct(mod_main_Point, mbrs(
    mbr(x, uint32)
    mbr(y, uint32)
))
