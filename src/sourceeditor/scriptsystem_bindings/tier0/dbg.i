%module dbg

%{
    #include <tier0/dbg.h>
%}

void Msg(const char* fmt, ...);

void Warning(const char* fmt, ...);

void Log(const char* fmt, ...);
