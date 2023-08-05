#pragma once

#include "../../common/metadata/TkMetaDataXML.h"
#include "../../common/metadata/TkID.h"
#include "../../simulation/GcPlayerSpawnState.h"

class cGcSceneSettings : public cTkMetaDataXML::Registrar<cGcSceneSettings>
{
	cTkFixedString<128, char> macNextSettingFile;
	cTkFixedString<128, char> macSceneFile;
	cTkDynamicArray<cTkFixedString<128, char> > maacPlanetSceneFiles;
	cTkFixedString<128, char> macSolarSystemFile;
	cTkFixedArray<cTkFixedString<128, char>, 5> maacPlanetFiles;
	cTkDynamicArray<cTkFixedString<128, char> > maacShipPreloadFiles;
	bool mbSpawnShip;
	bool mbSpawnInsideShip;
	cGcPlayerSpawnStateData mPlayerState;
	cTkDynamicArray<cTkClassPointer> maEvents;
	cTkDynamicArray<cTkClassPointer> maPostWarpEvents;
	TkID<128> mSpawnerOptionId;
};
