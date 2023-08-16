#include "hooks.h"

void Hooks::AddHook(LPVOID pTarget, LPVOID pDetour, void* ppOriginal, const char* name)
{
	std::string formatName = fmt::format("{} ({})", name, pTarget);

	if (MH_CreateHook(pTarget, pDetour, (LPVOID*)ppOriginal) == MH_OK)
	{
		if (MH_EnableHook(pTarget) == MH_OK)
			spdlog::info("Enabling hook: {}", formatName);
		else
			spdlog::error("MH_EnableHook failed for: {}", formatName);
	}
	else
		spdlog::error("MH_CreateHook failed for: {}", formatName);
}