#pragma once

#include "pch.h"

#define HM_BLOCK_OPEN "{"
#define HM_BLOCK_CLOSE "}"
#define HM_SEMI ";"
#define HM_EMPTY " "
#define HM_NEWLINE "\n"

#define HM_CLASS(className) fmt::format("class {} : cTkMetaData::Registrar<{}>", className, className).c_str()

#define HM_NEWBLOCK(chars) chars + HM_NEWLINE + HM_BLOCK_OPEN
#define HM_ENBLOCK(chars) chars + HM_BLOCK_CLOSE