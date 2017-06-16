#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
#include "comm.h" 
int main(){

	lua_State *L = luaL_newstate();  /* opens Lua */
	luaL_openlibs(L);   /* opens the standard libraries */

	lua_register(L, "lua_diao_c", lua_diao_c);    

	luaL_dofile(L,"test.lua"); /* runs Lua script */

	lua_getglobal(L, "c_diao_lua");
	if(lua_isnil(L,-1)){
		printf("get lua function fail!\n");
		return -1;
	}

	lua_pushnumber(L,99);
	lua_pushnumber(L,33);
	int iRet = lua_pcall(L,2,1,0);
	if(iRet != 0)
	{
		printf("exec lua func fail!\n");
		return -1;	
	}
	lua_close(L);     
	return 0;

}
