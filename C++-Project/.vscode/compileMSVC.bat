@echo off
cd /d "%3"
call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvarsall.bat" x64

set compilerflags=/Od /Zi /EHsc
set linkerflags=/OUT:"%2"
cl.exe %compilerflags% "%1" /link %linkerflags%
exit 0