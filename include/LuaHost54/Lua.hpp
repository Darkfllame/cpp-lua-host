#pragma once

class Lua {
	private:
		lua_State* L;
		bool checkLua(int res);

	public :
		/*
		constructor : create a new lua state and add basic libs
		*/
		Lua();
		/*
		deconstructor : close the lua state
		*/
		~Lua();
		/*
		return the lua state of this instance
		*/
		lua_State* getLuaState();
		/*
		call this to run string as lua program
		*/
		bool executeLua(string code);
		/*
		call this to run a lua file with name fileName + '.lua'
		*/
		bool executeFile(string fileName);
		/*
		call this to run a file call 'main.lua'
		*/
		bool executeFile();

		//global values momento
		/*
		call this to add a global function to the lua state
		*/
		void setFunc(string name, lua_CFunction func);
		/*
		call this to add a global number to the lua state
		*/
		void setNum(string name, lua_Number num);
		/*
		call this to add a global string to the lua state
		*/
		void setStr(string name, const char* str);

		//table set momento
		/*
		call this to make a new table to the lua state
		*/
		void setTable(string name);
		/*
		call this to modify/add a function argument from a table
		*/
		void setTableFunc(string name, string arg, lua_CFunction func);
		/*
		call this to modify/add a number argument from a table
		*/
		void setTableNum(string name, string arg, lua_Number num);
		/*
		call this to modify/add a string argument from a table
		*/
		void setTableStr(string name, string arg, const char* str);
};