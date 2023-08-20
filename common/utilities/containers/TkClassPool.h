#pragma once

class cTkClassPoolHandle
{
    int miArrayIndex;
    int miUniqueID;
};

template <typename T, unsigned int uiSize>
class cTkClassPool
{
    T maPool[uiSize];
    int maiUniqueIds[uiSize];
    int maiRoster[uiSize];
    int miRosterPartition;
    int miUniqueIDGenerator;
}
