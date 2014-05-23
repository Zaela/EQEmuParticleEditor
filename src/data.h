
#ifndef DATA_H
#define DATA_H

#include <lua.hpp>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "types.h"

void LoadDataFunctions(lua_State* L);

struct Header
{
	char magic[4]; //EDD
	uint32 version;
	static const int SIZE = sizeof(uint32) * 2;
};

struct Data
{
	char name[64];
	char filename[32];
	int field1;
	int field2;
	int field3;
	int field4;
	int field5;
	int field6;
	float field7;
	float total_scale;
	int density_relatedA;
	int density_relatedB;
	float density;
	float emission_delayA;
	float emission_delayB;
	float fadeout_time;
	float particle_scaleA;
	float particle_scaleB;
	float field17;
	float field18;
	int field19;
	float field20;
	float x_axis_scale;
	float z_axis_scale;
	float translation_y;
	float translation_z;
	float translation_x;
	float field26;
	float field27;
	float image_stretch;
	float field29;
	int red_tint1;
	int green_tint1;
	int blue_tint1;
	int red_tint2;
	int green_tint2;
	int blue_tint2;
	float field36;
	float field37;
	float field38;
	float field39;
	float field40;
	float field41;
	float field42;
	float field43;
	float field44;
	float field45;
	float field46;
	float field47;
	float field48;
	float field49;
	float field50;
	float field51;
	float field52;
	int image_segments;
	float rotation_speed;
	float field55;
	float field56;
	float field57;
	float field58;
	float field59;
	float field60;
	float field61;
	float field62;
	float field63;
	float field64;
	float field65;
	float field66;
	float field67;
	float field68;
	float field69;
	int field70;
	int field71;
	float field72;
	float field73;
	float field74;
	float field75;
	int field76;
	float field77;
	float field78;
	float field79;
	int field80;
	static const int SIZE = 64 + 32 + sizeof(float) * 80;
};

#endif//DATA_H
