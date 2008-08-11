// Copyright (C) 2003-2008 Dolphin Project.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, version 2.0.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License 2.0 for more details.

// A copy of the GPL 2.0 should have been included with the program.
// If not, see http://www.gnu.org/licenses/

// Official SVN repository and contact information can be found at
// http://code.google.com/p/dolphin-emu/
#ifndef _CORE_H
#define _CORE_H

#include <vector>
#include <string>

#include "Common.h"
#include "CoreParameter.h"

namespace Core
{
    enum EState
    {
        CORE_UNINITIALIZED,
        CORE_PAUSE,
        CORE_RUN,
    };

    // Init core
    bool Init(const SCoreStartupParameter _CoreParameter);
    void Stop();

    // Get state
    bool SetState(EState _State);

    // Get state
    EState GetState();

    // get core parameters
	extern SCoreStartupParameter g_CoreStartupParameter; //uck
    const SCoreStartupParameter& GetStartupParameter();

    // make a screen shot
    bool MakeScreenshot(const std::string& _rFilename);
    void* GetWindowHandle();

	extern bool bReadTrace;
	extern bool bWriteTrace;

	void StartTrace(bool write);
	void DisplayMessage(const std::string &message, int time_in_ms); // This displays messages in a user-visible way.
	void DisplayMessage(const char *message, int time_in_ms); // This displays messages in a user-visible way.

	int SyncTrace();
	void SetBlockStart(u32 addr);
	void StopTrace();

} // end of namespace Core

#endif

