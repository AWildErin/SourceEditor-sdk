@echo off

set "src_dir=../.."

set "swig_dir=%src_dir%/thirdparty/swigwin-4.0.2"

"%swig_dir%/swig" -csharp -c++ -dllimport "scriptsystem" -namespace "ScriptSystem.Bindings" -outdir "%CD%/generated" ScriptSystem.i