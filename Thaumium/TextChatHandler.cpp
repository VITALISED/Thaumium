#include "pch.h"
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
        if (IsStockCommandHack(&text))
            return fpParseTextForCommands(_this, lMessageText);

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
    else
        return fpParseTextForCommands(_this, lMessageText);
}

bool TextChatHandler::IsStockCommandHack(std::string* sCheck)
{
    if (sCheck->find("/local") != std::string::npos)
        return true;
    if (sCheck->find("/l") != std::string::npos)
        return true;
    if (sCheck->find("/group") != std::string::npos)
        return true;
    if (sCheck->find("/g") != std::string::npos)
        return true;
    if (sCheck->find("/whisper") != std::string::npos)
        return true;
    if (sCheck->find("/w") != std::string::npos)
        return true;
    if (sCheck->find("/join") != std::string::npos)
        return true;
    if (sCheck->find("/leave") != std::string::npos)
        return true;
    if (sCheck->find("/invite") != std::string::npos)
        return true;
    if (sCheck->find("/kick") != std::string::npos)
        return true;
    return false;
}

void TextChatHandler::Init()
{
    ADDHOOK(OFFSET(0x949870), ParseTextForCommandsHook, reinterpret_cast<LPVOID*>(&fpParseTextForCommands), cGcTextChatInput::ParseTextForCommands);
}