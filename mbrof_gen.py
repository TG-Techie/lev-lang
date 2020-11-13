
with open('_genreated_mbrof.txt', 'w') as file:
    for this in range(2, 66):
        next = this - 1

        file.write(f"""\
#define _mbrof_chain_{this}(var, vartype, mbr, ...) \\
    _call_chain_{next}_from_{this}(_call_link_{this}(var, vartype, _unpack_##mbr), __VA_ARGS__)
#define _call_link_{this}(...) _link_{this}(__VA_ARGS__)
#define _call_chain_{next}_from_{this}(...) _mbrof_chain_{next}(__VA_ARGS__)
#define _link_{this}(prev, prevtype, mbrname, mbrtype) \\
    content_ptr_##prevtype(&(prev))->mbr_##mbrname, mbrtype
\n\n
"""
        )
