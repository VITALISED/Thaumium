#include "../pch.h"
#include "nguimbinexport.h"

cGcNGuiLayerData::Save fpSave = NULL;

void NGuiMBINExport::Init()
{
	//ADDHOOK(OFFSET(0x23C8350), SaveHook, reinterpret_cast<LPVOID*>(fpSave), cGcNGuiLayerData::Save);
}

bool NGuiMBINExport::SaveHook(cGcNGuiLayerData* thiscall, const char* lpacFileName, bool lbClearAllExistingData)
{
/*	std::string wires = lpacFileName;
	std::size_t found = wires.find(".mXml");

	if (found != std::string::npos)
	{
		wires.replace(found, wires.length(), ".mBin");
	}

	spdlog::info("Writing cGcNGuiLayerData to {}", wires);

	cTkMetaDataXML<cGcNGuiLayerData const>::WriteToXMLFile saveFunc = (cTkMetaDataXML<cGcNGuiLayerData const>::WriteToXMLFile)OFFSET(0x23AD9B0);
	return saveFunc(thiscall, "GcNGuiLayerData", wires.c_str(), false, false, lbClearAllExistingData, true);*/	
}