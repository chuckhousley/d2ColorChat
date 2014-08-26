// d2ColorChat is based off of the Notepad++ Plugin Template (http://notepad-plus-plus.org/contribute/plugin-howto.html) by Don Ho, copyright 2003. d2ColorChat is copyright Chuck Housley (C) 2014
// d2ColorChat is a simple tool used to add obnoxious coloring to the chat functionality of Dota 2
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

#include "PluginDefinition.h"
#include "menuCmdID.h"
#include <cstring>
#include <string>

#define RED 0x12
#define YELLOW 0x14
#define ORANGE 0x1b
#define GREEN1 0x08
#define GREEN2 0x10
#define GREEN3 0x11
#define GREEN4 0x15
#define GREEN5 0x18
#define GREEN6 0x1c
#define BLUE 0x19
#define INDIGO 0x09
#define VIOLET 0x16
#define MAGENTA 0x0e
#define PURPLE 0x1a
#define SALMON 0x1c
#define GOLDENROD 0x1d
#define GRAY 0x17
#define BROWN 0x1b

//
// The plugin data that Notepad++ needs
//
FuncItem funcItem[nbFunc];

//
// The data of Notepad++ that you can use in your plugin commands
//
NppData nppData;


void pluginInit(HANDLE hModule)
{	
}


void pluginCleanUp()
{
}

void commandMenuInit()
{
    
	setCommand(0, TEXT("Red"), red, NULL, false);
	setCommand(1, TEXT("Orange"), orange, NULL, false);
	setCommand(2, TEXT("Yellow"), yellow, NULL, false);
	setCommand(3, TEXT("Green 1"), green1, NULL, false);
	setCommand(4, TEXT("Green 2"), green2, NULL, false);
	setCommand(5, TEXT("Green 3"), green3, NULL, false);
	setCommand(6, TEXT("Green 4"), green4, NULL, false);
	setCommand(7, TEXT("Green 5"), green5, NULL, false);
	setCommand(8, TEXT("Green 6"), green6, NULL, false);
	setCommand(9, TEXT("Blue"), blue, NULL, false);
	setCommand(10, TEXT("Indigo"), indigo, NULL, false);
	setCommand(11, TEXT("Violet"), violet, NULL, false);
	setCommand(12, TEXT("Magenta"), magenta, NULL, false);
	setCommand(13, TEXT("Purple"), purple, NULL, false);
	setCommand(14, TEXT("Pink"), pink, NULL, false);
	setCommand(15, TEXT("Gold"), gold, NULL, false);
	setCommand(16, TEXT("Gray"), gray, NULL, false);
	setCommand(17, TEXT("Brown"), brown, NULL, false);
	setCommand(18, TEXT("Rainbow Letters"), rainbowLetter, NULL, false);
	setCommand(19, TEXT("Rainbow Words"), rainbowWord, NULL, false);
	setCommand(20, TEXT("USA Letters"), usaLetter, NULL, false);
	setCommand(21, TEXT("USA Words"), usaWord, NULL, false);
	setCommand(22, TEXT("XxXSm0keW33dXxX"), smokeWeed, NULL, false);
	
}

void commandMenuCleanUp()
{
	// Don't forget to deallocate your shortcut here
	delete[] &funcItem; // deallocation?  c'mon don, you said this was easy
}

bool setCommand(size_t index, TCHAR *cmdName, PFUNCPLUGINCMD pFunc, ShortcutKey *sk, bool check0nInit) 
{
    if (index >= nbFunc)
        return false;

    if (!pFunc)
        return false;

    lstrcpy(funcItem[index]._itemName, cmdName);
    funcItem[index]._pFunc = pFunc;
    funcItem[index]._init2Check = check0nInit;
    funcItem[index]._pShKey = sk;

    return true;
}

//----------------------------------------------//
//-- STEP 4. DEFINE YOUR ASSOCIATED FUNCTIONS --//
//----------------------------------------------//
void rainbowLetter()
{
    // Get the current scintilla
    int which = -1;
    ::SendMessage(nppData._nppHandle, NPPM_GETCURRENTSCINTILLA, 0, (LPARAM)&which);
    if (which == -1)
        return;
    HWND curScintilla = (which == 0)?nppData._scintillaMainHandle:nppData._scintillaSecondHandle;

    // stupid junk starts here
	
	char* text = new char;
	::SendMessage(curScintilla, SCI_GETSELTEXT, 0, (LPARAM) text);

	char rainbow[] = { RED, ORANGE, YELLOW, GREEN4, BLUE, INDIGO, VIOLET };
	
	char oldtext = *text;
	unsigned int oldsize = strlen(text);
	char newtext[512]; // hope whatever you're trying to convert isn't over 256 chars lel
	
	int r = 0;
	int j = 0;

	for (unsigned int i = 0; i < oldsize; i++) {
		newtext[j] = rainbow[r];
		j++;
		newtext[j] = text[i];
		if (newtext[j] != ' ') { r++; }
		if (r > 6) { r = 0; }
		j++;
	}

    ::SendMessage(curScintilla, SCI_SETTEXT, 0, (LPARAM) (newtext));
	delete text; // muh memory leaks
	//::SendMessage(curScintilla, SCI_SELECTALL, 0, 0);
	//::SendMessage(curScintilla, SCI_COPYTEXT, 0, 0);
}

void rainbowWord()
{
	int which = -1;
	::SendMessage(nppData._nppHandle, NPPM_GETCURRENTSCINTILLA, 0, (LPARAM)&which);
	if (which == -1)
		return;
	HWND curScintilla = (which == 0) ? nppData._scintillaMainHandle : nppData._scintillaSecondHandle;

	char* text = new char;
	::SendMessage(curScintilla, SCI_GETSELTEXT, 0, (LPARAM)text);

	char rainbow[] = { RED, ORANGE, YELLOW, GREEN4, BLUE, INDIGO, VIOLET };

	char oldtext = *text;
	unsigned int oldsize = strlen(text);
	char newtext[512];

	int r = 0;
	int j = 0;

	for (unsigned int i = 0; i < oldsize; i++) {
		newtext[j] = rainbow[r];
		if (newtext[j] == ' ') 
		{ 
			r++;
			newtext[++j] = rainbow[r];
		}
		if (r > 6) { r = 0; }
		j++;
	}

	::SendMessage(curScintilla, SCI_SETTEXT, 0, (LPARAM)(newtext));
	delete text;
}
void red()
{
	int which = -1;
	::SendMessage(nppData._nppHandle, NPPM_GETCURRENTSCINTILLA, 0, (LPARAM)&which);
	if (which == -1)
		return;
	HWND curScintilla = (which == 0) ? nppData._scintillaMainHandle : nppData._scintillaSecondHandle;

	char* text = new char;
	::SendMessage(curScintilla, SCI_GETSELTEXT, 0, (LPARAM)text);

	//unsigned int length = -1;
	//bool end = false;
	//while (!end) {
	//	if (text[++length] == '\0') { end = true; }
	//}
	std::string buffer;
	buffer.append(text);

	char newtext[512];
	newtext[0] = RED;
	

	::SendMessage(curScintilla, SCI_SETTEXT, 0, (LPARAM) strcat(newtext, buffer.c_str()));
	delete text;
}
void orange()
{
	int which = -1;
	::SendMessage(nppData._nppHandle, NPPM_GETCURRENTSCINTILLA, 0, (LPARAM)&which);
	if (which == -1)
		return;
	HWND curScintilla = (which == 0) ? nppData._scintillaMainHandle : nppData._scintillaSecondHandle;

	char* text = new char;
	::SendMessage(curScintilla, SCI_GETSELTEXT, 0, (LPARAM)text);

	char oldtext = *text;
	unsigned int oldsize = strlen(text);
	char newtext[512];

	newtext[0] = ORANGE;
	for (unsigned int i = 0; i < oldsize; i++) {
		newtext[i + 1] = text[i];
	}

	::SendMessage(curScintilla, SCI_SETTEXT, 0, (LPARAM)(newtext));
	delete text;
}
void yellow()
{
	int which = -1;
	::SendMessage(nppData._nppHandle, NPPM_GETCURRENTSCINTILLA, 0, (LPARAM)&which);
	if (which == -1)
		return;
	HWND curScintilla = (which == 0) ? nppData._scintillaMainHandle : nppData._scintillaSecondHandle;

	char* text = new char;
	::SendMessage(curScintilla, SCI_GETSELTEXT, 0, (LPARAM)text);

	char oldtext = *text;
	unsigned int oldsize = strlen(text);
	char newtext[512];

	newtext[0] = YELLOW;
	for (unsigned int i = 0; i < oldsize; i++) {
		newtext[i + 1] = text[i];
	}

	::SendMessage(curScintilla, SCI_SETTEXT, 0, (LPARAM)(newtext));
	delete text;

}
void green1()
{

}
void green2()
{

}
void green3()
{

}
void green4()
{

}
void green5()
{

}
void green6()
{

}
void blue()
{

}
void indigo()
{

}
void violet()
{

}
void magenta()
{

}
void purple()
{

}
void pink()
{

}
void gold()
{

}
void gray()
{

}
void brown()
{

}
void usaLetter()
{

}
void usaWord()
{

}
void smokeWeed()
{

}
