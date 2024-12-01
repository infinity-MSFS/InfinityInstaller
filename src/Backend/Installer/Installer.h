#pragma once

#include <string>
#include <windows.h>
#include <ShlObj.h>

class Installer
{

public:
	static std::wstring OpenFolderDialog(const std::wstring& defaultPath);
	static std::wstring GetLocalAppDataPath();
};
