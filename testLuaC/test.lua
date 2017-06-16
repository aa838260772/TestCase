--print("This is executed from C")

c_diao_lua = function(int1,int2)
	print("函数参数:",int1,int2,"##")
end

ret = lua_diao_c(989)
if ret == nil then
	print("err ret")
end
