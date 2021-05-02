%module dbg

%{
    #include <tier0/dbg.h>
%}

void Msg(const char* fmt, ...);