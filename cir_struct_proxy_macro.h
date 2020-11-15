
#define _mut_proxy_def(structtype)\
    __mut_proxy_def(mutble_proxy_##structtype, structtype)
#define __mut_proxy_def(proxytype, structtype)\
    _mut_proxy_body_def(proxytype, structtype)\
    _mut_proxy_get_expr_def(proxytype, structtype)\
    _mut_proxy_rel_expr_def(proxytype, structtype)\
    _mut_proxy_dec_deflt_def(proxytype, structtype)\
    _mut_proxy_ret_def(proxytype, structtype)\
    _mut_proxy_content_ptr_def(proxytype, structtype)\
    _mut_proxy_for_mut_proxy_def(proxytype, structtype)\

#define _mut_proxy_body_def(proxytype, structtype)\
    typedef structtype* proxytype;\
    // not used below //typedef content_##structtype content_##proxytype;\



#define _mut_proxy_get_expr_def(proxytype, structtype)\
    proxytype get_##proxytype(proxytype self){\
        get_##structtype(*self);\
        return self;\
    }

#define _mut_proxy_rel_expr_def(proxytype, structtype)\
    void rel_##proxytype(proxytype self){\
        return rel_##structtype(*self);\
    }


#define _mut_proxy_dec_deflt_def(proxytype, structtype)\
    proxytype dec_dflt_##proxytype(){\
        return NULL;\
    }

// ret returns a copy of the value
#define _mut_proxy_ret_def(proxytype, structtype)\
    structtype ret_##proxytype(proxytype self){\
        return *self;\
    }\


#define _mut_proxy_content_ptr_def(proxytype, structtype)\
    content_##structtype* content_ptr_##proxytype(proxytype* self_ptr){\
        proxytype self = *self_ptr; \
        return (content_##structtype*) self;\
    }

// a proxy of a proxy is just a proxy
#define _mut_proxy_for_mut_proxy_def(proxytype, structtype)\
    proxytype proxy_##proxytype(proxytype* self_ptr) { \
        return *self_ptr; \
    }
