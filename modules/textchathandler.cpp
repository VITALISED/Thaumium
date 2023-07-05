#include "../pch.h"
#include "TextChatHandler.h"

cGcTextChatInput::ParseTextForCommands fpParseTextForCommands = NULL;

void __fastcall TextChatHandler::ParseTextForCommandsHook(cGcTextChatInput* _this, const cTkFixedString<1023, char> lMessageText)
{
    std::string text = lMessageText.macBuffer;
    if (text.length() < 2)
        return fpParseTextForCommands(_this, lMessageText); // avoid death
    std::string postSlash = text.substr(1); // whatever is after / (lazy)


    if (text[0] == '/')
    {
        spdlog::info("Potential command {}", text);

        if (text == "/wires")
        {
            spdlog::warn("god I hate computers");

            cGcApplication* gApplcation = GCAPPLICATION;
            cGcApplication::GetNetworkManager getNetworkManager = (cGcApplication::GetNetworkManager)OFFSET(0x1C2910);
            cGcNetworkManager* network = getNetworkManager(gApplcation);
            cGcTextChatManager* textChat = reinterpret_cast<cGcTextChatManager*>(network->mTextChatManager);
            cGcTextChatManager::Say say = (cGcTextChatManager::Say)OFFSET(0x94C160);
            cTkFixedString<1023, char> msg = cTkFixedString<1023, char>("wires in MY wireless device?!??!?!");
            say(textChat, &msg, true);
            return;
        }
    } 

    return fpParseTextForCommands(_this, lMessageText);
}

void TextChatHandler::Init()
{
    ADDHOOK(OFFSET(0x949870), ParseTextForCommandsHook, reinterpret_cast<LPVOID*>(&fpParseTextForCommands), cGcTextChatInput::ParseTextForCommands);
}

void TextChatHandler::RegisterStockCommands()
{
    // should use lookup tables, too lazy atm
}

