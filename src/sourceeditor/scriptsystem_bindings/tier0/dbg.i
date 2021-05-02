%module dbg

%{
    #include <tier0/dbg.h>
%}

/*
@todo Add all the developer log inputs
@todo Add color msg
*/

void Msg(const char* fmt, ...);

void Warning(const char* fmt, ...);

void Log(const char* fmt, ...);
