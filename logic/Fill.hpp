
#pragma once

#include <logic/World.hpp>

enum struct FillError
{
    NONE = 0,
    RAN_OUT_OF_RETRIES,
    MORE_ITEMS_THAN_LOCATIONS,
    NO_REACHABLE_LOCATIONS,
    GAME_NOT_BEATABLE,
    NOT_ENOUGH_PROGRESSION_LOCATIONS,
    PLANDOMIZER_ERROR,
};

FillError fill(std::vector<World>& worlds);
void clearWorlds(WorldPool& worlds);
const char* errorToName(FillError err);
