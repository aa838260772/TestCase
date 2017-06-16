#include <stdio.h>
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

int lua_diao_c(lua_State *ls)	
{
	int a = 0;
	a = lua_tonumber(ls, -1);
	
	printf("lua diao c arg:%d\n", a);
	
	lua_pushnumber(ls,0);
	return 1;
}
