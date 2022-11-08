#pragma once

#include <string>

#include <command/RandoSession.hpp>
#include <logic/World.hpp>



extern RandoSession g_session; //defined in randomizer.cpp, shared between a couple files, cleaner than passing to every patch

enum struct [[nodiscard]] TweakError {
    NONE = 0,
    DATA_FILE_MISSING,
    RELOCATION_MISSING_KEY,
    FILE_OPEN_FAILED,
    FILE_COPY_FAILED,
    FILE_SAVE_FAILED,
    RPX_OPERATION_FAILED,
    FILETYPE_ERROR,
    MISSING_SYMBOL,
    MISSING_EVENT,
    MISSING_ENTITY,
    UNEXPECTED_VALUE,
    UNKNOWN,
    COUNT
};

TweakError apply_necessary_tweaks(const Settings& settings);

TweakError apply_necessary_post_randomization_tweaks(World& world, const bool& randomizeItems);

