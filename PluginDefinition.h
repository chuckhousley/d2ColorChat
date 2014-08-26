//this file is part of notepad++
//Copyright (C)2003 Don HO <donho@altern.org>
//
//This program is free software; you can redistribute it and/or
//modify it under the terms of the GNU General Public License
//as published by the Free Software Foundation; either
//version 2 of the License, or (at your option) any later version.
//
//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.
//
//You should have received a copy of the GNU General Public License
//along with this program; if not, write to the Free Software
//Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
#ifndef PLUGINDEFINITION_H
#define PLUGINDEFINITION_H

//
// All difinitions of plugin interface
//
#include "PluginInterface.h"

const TCHAR NPP_PLUGIN_NAME[] = TEXT("d2ColorChat");

// remember to increase this as obnoxious ideas come in.
const int nbFunc = 23;


//
// Initialization of your plugin data
// It will be called while plugin loading
//
void pluginInit(HANDLE hModule);

//
// Cleaning of your plugin
// It will be called while plugin unloading
//
void pluginCleanUp();

//
//Initialization of your plugin commands
//
void commandMenuInit();

//
//Clean up your plugin commands allocation (if any)
//
void commandMenuCleanUp();

//
// Function which sets your command 
//
bool setCommand(size_t index, TCHAR *cmdName, PFUNCPLUGINCMD pFunc, ShortcutKey *sk = NULL, bool check0nInit = false);


//
// Your plugin command functions
//
void red();				// 0
void orange();			// 1
void yellow();			// 2
void green1();			// 3 
void green2();			// 4
void green3();			// 5
void green4();			// 6
void green5();			// 7
void green6();			// 8
void blue();			// 9
void indigo();			// 10
void violet();			// 11
void magenta();			// 12
void purple();			// 13
void pink();			// 14
void gold();			// 15
void gray();			// 16
void brown();			// 17
void rainbowLetter();	// 18
void rainbowWord();		// 19
void usaLetter();		// 20
void usaWord();			// 21
void smokeWeed();		// 22


#endif //PLUGINDEFINITION_H
