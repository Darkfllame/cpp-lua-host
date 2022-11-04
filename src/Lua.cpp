/// Lua class : main class of the host, don't touch or gay

#include "LuaHost54/host.hpp"

bool Lua::checkLua(int ret) {
	if (ret != LUA_OK) {
		string err = lua_tostring(L, -1);
		std::cout << err << std::endl;
		return false;
	}
	return true;
}

Lua::Lua() {
	L = luaL_newstate();
	luaL_openlibs(L);
}

Lua::~Lua() {
	lua_close(L);
}

lua_State* Lua::getLuaState() {
	return L;
}
bool Lua::executeLua(string code) {
	int ret = luaL_dostring(L, code.c_str());

	return checkLua(ret);
}
bool Lua::executeFile(string fileName) {
	int ret = luaL_dofile(L, fileName.c_str());

	return checkLua(ret);
}
bool Lua::executeFile() {
	return executeFile("main.lua");
}

//global value scripting
void Lua::setFunc(string name, lua_CFunction func) {
	lua_pushcfunction(L, func);
	lua_setglobal(L, name.c_str());
}
void Lua::setNum(string name, lua_Number num) {
	lua_pushnumber(L, num);
	lua_setglobal(L, name.c_str());
}
void Lua::setStr(string name, const char* str) {
	lua_pushstring(L, str);
	lua_setglobal(L, name.c_str());
}

void Lua::setTable(string name) {
	executeLua(name.append(" = ").append("{}"));
}
void Lua::setTableFunc(string name, string arg, lua_CFunction func) {
	const char* nm = name.c_str();
	const char* ag = arg.c_str();

	lua_getglobal(L, nm);
	lua_pushcfunction(L, func);
	lua_setfield(L, -2, ag);
}
void Lua::setTableNum(string name, string arg, lua_Number num) {
	const char* nm = name.c_str();
	const char* ag = arg.c_str();

	lua_getglobal(L, nm);
	lua_pushnumber(L, num);
	lua_setfield(L, -2, ag);
}
void Lua::setTableStr(string name, string arg, const char* str) {
	const char* nm = name.c_str();
	const char* ag = arg.c_str();

	lua_getglobal(L, nm);
	lua_pushstring(L, str);
	lua_setfield(L, -2, ag);
}