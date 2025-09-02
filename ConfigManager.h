#pragma once
#include <windows.h>
#include <tuple>

#define CONFIG_NAME "downloadmonitor_config.cfg"

#define FOREGROUND_COLOUR "FOREGROUND_COLOUR"
#define CHILD_COLOUR "CHILD_COLOUR"
#define LAST_POS "LAST_POS"
#define OPACITY "OPACITY"
#define FIRST_RUN_MSG "FIRST_RUN_MSG"

class ConfigManager
{
private:
	void InitDefaults(bool resetMsgVar);
	void WriteData();
	void ReadData();
	int ProcessInt(char* dataStart);
	std::tuple<int, int> ProcessCoords(char* dataStart);
	COLORREF ProcessRGB(char* dataStart);
	void CopyRange(char* start, char* end, char* buf, int size);
	char* configDir = nullptr;
	bool retriedOnce = false;

public:
	bool failedToInit = false;

	int lastX = 0, lastY = 0;
	int opacity = 100;
	bool shownFirstRunMsg = false;

	void ResetConfig();


	ConfigManager(char* configDirOverride);
	~ConfigManager();

	void UpdateForegroundColour(COLORREF fg_col);
	void UpdateChildColour(COLORREF ch_col);
	void UpdateWindowPos(int x, int y);
	void UpdateOpacity(int newopacity);
	void UpdateShowFirstRunMsg(bool newBool);

	void GetFullConfigPath(char* buf);

	COLORREF* foregroundColour;
	COLORREF* childColour;
	COLORREF* customColBuf;

};

