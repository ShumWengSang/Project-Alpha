#pragma once
#define REGISTER_ENUM(x) x,
typedef enum
{
#include "names.h"
	OBJ_NUM
}Obj_Name;
#undef REGISTER_ENUM

//Create the string
#define REGISTER_ENUM(x) #x,
static const char* ObjNameText[] =
{
#include "names.h"
	"Invalid"
};
#undef REGISTER_ENUM