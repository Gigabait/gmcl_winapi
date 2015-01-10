#include "GarrysMod/Lua/Interface.h"
#include <stdio.h>
#include "string.h"
#include "stdafx.h"
using namespace GarrysMod::Lua;


void Easy_Messagebox(const char *str, const char *title, int flags)
{
	MessageBox(NULL, str, title, flags);
}

int LuaMessageBox( lua_State* state )
{
	if (LUA->IsType(1, Type::STRING) && LUA->IsType(2, Type::STRING) && LUA->IsType(3, Type::NUMBER))
	{
		char strOut[512];
		const char *Message = LUA->GetString( 1 );
		const char *Title = LUA->GetString(2);
		int flg = LUA->GetNumber(3);
		
		if (flg == 0)
			Easy_Messagebox(Message, Title, 0x00000002L);
		if (flg == 1)
			Easy_Messagebox(Message, Title, 0x00000006L);
		if (flg == 2)
			Easy_Messagebox(Message, Title, 0x00004000L);
		if (flg == 3)
			Easy_Messagebox(Message, Title, 0x00000000L);
		if (flg == 4)
			Easy_Messagebox(Message, Title, 0x00000001L);
		if (flg == 5)
			Easy_Messagebox(Message, Title, 0x00000005L);
		if (flg == 6)
			Easy_Messagebox(Message, Title, 0x00000004L);
		if (flg == 7)
			Easy_Messagebox(Message, Title, 0x00000003L);
		return 0;
	}

	return 0;
}

GMOD_MODULE_OPEN()
{

	LUA->PushSpecial( GarrysMod::Lua::SPECIAL_GLOB );	// Push global table
	LUA->PushString( "MessageBox" );					// Push Name
	LUA->PushCFunction(LuaMessageBox);			// Push function
	LUA->SetTable( -3 );								// Set the table 

	return 0;
}

GMOD_MODULE_CLOSE()
{
	return 0;
}