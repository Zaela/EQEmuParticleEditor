
#include "data.h"

void SetInt(lua_State* L, int val, const char* name)
{
	lua_pushinteger(L, val);
	lua_setfield(L, -2, name);
}

void SetFloat(lua_State* L, float val, const char* name)
{
	char str[256];
	snprintf(str, 256, "%g", val);
	lua_pushnumber(L, strtod(str, nullptr));
	lua_setfield(L, -2, name);
}

int Read(lua_State* L)
{
	const char* path = luaL_checkstring(L, 1);

	FILE* fp = fopen(path, "rb");
	if (fp == nullptr)
		return luaL_argerror(L, 1, "could not open specified path");

	lua_newtable(L); //to return

	fseek(fp, 0, SEEK_END);
	int len = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	byte* data = (byte*)lua_newuserdata(L, len);
	fread(data, sizeof(byte), len, fp);
	fclose(fp);

	lua_setfield(L, -2, "raw_data");

	Header* header = (Header*)data;
	if (header->magic[0] != 'E' || header->magic[1] != 'D' || header->magic[2] != 'D' || header->magic[3] != '\0')
		return luaL_argerror(L, 1, "file is not a valid .edd file");

	int pos = Header::SIZE;
	int i = -1;
	while (pos < len)
	{
		lua_pushinteger(L, ++i);
		lua_createtable(L, 0, 84);

		Data* d = (Data*)&data[pos];

		SetInt(L, i, "id");
		SetInt(L, pos, "offset");
		lua_pushlstring(L, d->name, 64);
		lua_setfield(L, -2, "name");
		lua_pushlstring(L, d->filename, 32);
		lua_setfield(L, -2, "filename");

		SetInt(L, d->field1, "field1");
		SetInt(L, d->field2, "field2");
		SetInt(L, d->field3, "field3");
		SetInt(L, d->field4, "field4");
		SetInt(L, d->field5, "field5");
		SetInt(L, d->field6, "field6");
		SetFloat(L, d->field7, "field7");

		SetFloat(L, d->total_scale, "total_scale");
		SetInt(L, d->density_relatedA, "density_relatedA");
		SetInt(L, d->density_relatedB, "density_relatedB");
		SetFloat(L, d->density, "density");
		SetFloat(L, d->emission_delayA, "emission_delayA");
		SetFloat(L, d->emission_delayB, "emission_delayB");
		SetFloat(L, d->fadeout_time, "fadeout_time");
		SetFloat(L, d->particle_scaleA, "particle_scaleA");
		SetFloat(L, d->particle_scaleB, "particle_scaleB");

		SetFloat(L, d->field17, "field17");
		SetFloat(L, d->field18, "field18");
		SetInt(L, d->field19, "field19");
		SetFloat(L, d->field20, "field20");

		SetFloat(L, d->x_axis_scale, "x_axis_scale");
		SetFloat(L, d->z_axis_scale, "z_axis_scale");
		SetFloat(L, d->translation_x, "translation_x");
		SetFloat(L, d->translation_y, "translation_y");
		SetFloat(L, d->translation_z, "translation_z");

		SetFloat(L, d->field26, "field26");
		SetFloat(L, d->field27, "field27");

		SetFloat(L, d->image_stretch, "image_stretch");

		SetFloat(L, d->field29, "field29");

		SetInt(L, d->red_tint1, "red_tint1");
		SetInt(L, d->green_tint1, "green_tint1");
		SetInt(L, d->blue_tint1, "blue_tint1");
		SetInt(L, d->red_tint2, "red_tint2");
		SetInt(L, d->green_tint2, "green_tint2");
		SetInt(L, d->blue_tint2, "blue_tint2");

		SetFloat(L, d->field36, "field36");
		SetFloat(L, d->field37, "field37");
		SetFloat(L, d->field38, "field38");
		SetFloat(L, d->field39, "field39");
		SetFloat(L, d->field40, "field40");
		SetFloat(L, d->field41, "field41");
		SetFloat(L, d->field42, "field42");
		SetFloat(L, d->field43, "field43");
		SetFloat(L, d->field44, "field44");
		SetFloat(L, d->field45, "field45");
		SetFloat(L, d->field46, "field46");
		SetFloat(L, d->field47, "field47");
		SetFloat(L, d->field48, "field48");
		SetFloat(L, d->field49, "field49");
		SetFloat(L, d->field50, "field50");
		SetFloat(L, d->field51, "field51");
		SetFloat(L, d->field52, "field52");

		SetInt(L, d->image_segments, "image_segments");
		SetFloat(L, d->rotation_speed, "rotation_speed");

		SetFloat(L, d->field55, "field55");
		SetFloat(L, d->field56, "field56");
		SetFloat(L, d->field57, "field57");
		SetFloat(L, d->field58, "field58");
		SetFloat(L, d->field59, "field59");
		SetFloat(L, d->field60, "field60");
		SetFloat(L, d->field61, "field61");
		SetFloat(L, d->field62, "field62");
		SetFloat(L, d->field63, "field63");
		SetFloat(L, d->field64, "field64");
		SetFloat(L, d->field65, "field65");
		SetFloat(L, d->field66, "field66");
		SetFloat(L, d->field67, "field67");
		SetFloat(L, d->field68, "field68");
		SetFloat(L, d->field69, "field69");
		SetFloat(L, d->field70, "field70");
		SetInt(L, d->field71, "field71");
		SetFloat(L, d->field72, "field72");
		SetFloat(L, d->field73, "field73");
		SetFloat(L, d->field74, "field74");
		SetFloat(L, d->field75, "field75");
		SetInt(L, d->field76, "field76");
		SetFloat(L, d->field77, "field77");
		SetFloat(L, d->field78, "field78");
		SetFloat(L, d->field79, "field79");
		SetInt(L, d->field80, "field80");

		pos += Data::SIZE;

		lua_settable(L, -3);
	}

	return 1;
}

int GetInt(lua_State* L, const char* name)
{
	lua_getfield(L, 3, name);
	int val = lua_tointeger(L, -1);
	lua_pop(L, 1);
	return val;
}

float GetFloat(lua_State* L, const char* name)
{
	lua_getfield(L, 3, name);
	float val = static_cast<float>(lua_tonumber(L, -1));
	lua_pop(L, 1);
	return val;
}

int Write(lua_State* L)
{
	const char* path = luaL_checkstring(L, 1);
	if (!lua_istable(L, 2))
		return luaL_argerror(L, 2, "expected main .edd file table");
	if (!lua_istable(L, 3))
		return luaL_argerror(L, 3, "expected particle data table");

	lua_getfield(L, 2, "raw_data");
	byte* ptr = (byte*)lua_touserdata(L, -1);
	uint32 len = lua_objlen(L, -1);
	lua_pop(L, 1);

	Data d;
	lua_getfield(L, 3, "name");
	snprintf(d.name, 64, "%s", lua_tostring(L, -1));
	lua_getfield(L, 3, "filename");
	snprintf(d.filename, 32, "%s", lua_tostring(L, -1));
	lua_pop(L, 2);

	d.field1 = GetInt(L, "field1");
	d.field2 = GetInt(L, "field2");
	d.field3 = GetInt(L, "field3");
	d.field4 = GetInt(L, "field4");
	d.field5 = GetInt(L, "field5");
	d.field6 = GetInt(L, "field6");
	d.field7 = GetFloat(L, "field7");

	d.total_scale = GetFloat(L, "total_scale");
	d.density_relatedA = GetInt(L, "density_relatedA");
	d.density_relatedB = GetInt(L, "density_relatedB");
	d.density = GetFloat(L, "density");
	d.emission_delayA = GetFloat(L, "emission_delayA");
	d.emission_delayB = GetFloat(L, "emission_delayB");
	d.fadeout_time = GetFloat(L, "fadeout_time");
	d.particle_scaleA = GetFloat(L, "particle_scaleA");
	d.particle_scaleB = GetFloat(L, "particle_scaleB");

	d.field17 = GetFloat(L, "field17");
	d.field18 = GetFloat(L, "field18");
	d.field19 = GetInt(L, "field19");
	d.field20 = GetFloat(L, "field20");

	d.x_axis_scale = GetFloat(L, "x_axis_scale");
	d.z_axis_scale = GetFloat(L, "z_axis_scale");
	d.translation_x = GetFloat(L, "translation_x");
	d.translation_y = GetFloat(L, "translation_y");
	d.translation_z = GetFloat(L, "translation_z");

	d.field26 = GetFloat(L, "field26");
	d.field27 = GetFloat(L, "field27");

	d.image_stretch = GetFloat(L, "image_stretch");

	d.field29 = GetFloat(L, "field29");

	d.red_tint1 = GetInt(L, "red_tint1");
	d.green_tint1 = GetInt(L, "green_tint1");
	d.blue_tint1 = GetInt(L, "blue_tint1");
	d.red_tint2 = GetInt(L, "red_tint2");
	d.green_tint2 = GetInt(L, "green_tint2");
	d.blue_tint2 = GetInt(L, "blue_tint2");

	d.field36 = GetFloat(L, "field36");
	d.field37 = GetFloat(L, "field37");
	d.field38 = GetFloat(L, "field38");
	d.field39 = GetFloat(L, "field39");
	d.field40 = GetFloat(L, "field40");
	d.field41 = GetFloat(L, "field41");
	d.field42 = GetFloat(L, "field42");
	d.field43 = GetFloat(L, "field43");
	d.field44 = GetFloat(L, "field44");
	d.field45 = GetFloat(L, "field45");
	d.field46 = GetFloat(L, "field46");
	d.field47 = GetFloat(L, "field47");
	d.field48 = GetFloat(L, "field48");
	d.field49 = GetFloat(L, "field49");
	d.field50 = GetFloat(L, "field50");
	d.field51 = GetFloat(L, "field51");
	d.field52 = GetFloat(L, "field52");

	d.image_segments = GetInt(L, "image_segments");
	d.rotation_speed = GetFloat(L, "rotation_speed");

	d.field55 = GetFloat(L, "field55");
	d.field56 = GetFloat(L, "field56");
	d.field57 = GetFloat(L, "field57");
	d.field58 = GetFloat(L, "field58");
	d.field59 = GetFloat(L, "field59");
	d.field60 = GetFloat(L, "field60");
	d.field61 = GetFloat(L, "field61");
	d.field62 = GetFloat(L, "field62");
	d.field63 = GetFloat(L, "field63");
	d.field64 = GetFloat(L, "field64");
	d.field65 = GetFloat(L, "field65");
	d.field66 = GetFloat(L, "field66");
	d.field67 = GetFloat(L, "field67");
	d.field68 = GetFloat(L, "field68");
	d.field69 = GetFloat(L, "field69");
	d.field70 = GetFloat(L, "field70");
	d.field71 = GetInt(L, "field71");
	d.field72 = GetFloat(L, "field72");
	d.field73 = GetFloat(L, "field73");
	d.field74 = GetFloat(L, "field74");
	d.field75 = GetFloat(L, "field75");
	d.field76 = GetInt(L, "field76");
	d.field77 = GetFloat(L, "field77");
	d.field78 = GetFloat(L, "field78");
	d.field79 = GetFloat(L, "field79");
	d.field80 = GetInt(L, "field80");

	int offset = GetInt(L, "offset");

	if (offset != 0)
	{
		Data* in = (Data*)&ptr[offset];
		*in = d;
	}
	else
	{
		//new entry -- append and update
		lua_pushinteger(L, len);
		lua_setfield(L, 3, "offset");

		byte* in = (byte*)lua_newuserdata(L, len + Data::SIZE);
		memcpy(in, ptr, len);
		memcpy(&in[len], &d, Data::SIZE);
		ptr = in;
		len += Data::SIZE;
		lua_setfield(L, 2, "raw_data");
	}

	FILE* fp = fopen(path, "wb+");
	if (fp == nullptr)
		return luaL_argerror(L, 1, "could not open specified path for writing");

	fwrite(ptr, sizeof(byte), len, fp);
	fclose(fp);

	return 0;
}

static const luaL_Reg funcs[] = {
	{"Read", Read},
	{"Write", Write},
	{nullptr, nullptr}
};

void LoadDataFunctions(lua_State* L)
{
	luaL_register(L, "data", funcs);
}
