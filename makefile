# compiler
COMP=g++

# output files names
name_DLL=LuaHost54

# the files to compiles
files_DLL=src/*.cpp include/LuaHost54/host.hpp

# linking args
link_DLL=-llua54

# sup args
args_DLL=

#-------------------NO MORE MODIFICATIONS-------------------#

DEFAULT_LINKS=-I include/ -L lib/ -lmingw32

DLL:
	if not exist bin/ mkdir bin/
	if not exist lib/ mkdir lib/
	${COMP} -o bin/${name_DLL}.dll ${files_DLL} -shared -s -Wl,--out-implib,lib/lib${name_DLL}.a ${DEFAULT_LINKS} ${link_DLL} ${args_DLL}