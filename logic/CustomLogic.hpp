#pragma once
#include <libs/yaml.hpp>

namespace CustomLogic {
    enum LogicError{
        NONE = 0,
        WORLD_YAML_ERROR,
        MACROS_YAML_ERROR,
        NON_ESSENTIAL_FILE_ERROR
    };

    LogicError loadWorldYaml(fspath yamlPath, YAML::Node &out);
    LogicError loadMacrosYaml(fspath yamlPath, YAML::Node &out);
    LogicError loadAreaNamesYaml(fspath yamlPath, YAML::Node &out);
    LogicError loadDungeonEntranceInfoYaml(fspath yamlPath, YAML::Node &out);
    LogicError loadEntranceShuffleTableYaml(fspath yamlPath, YAML::Node &out);
    LogicError loadItemDataYaml(fspath yamlPath, YAML::Node &out);
    LogicError loadLocationDataYaml(fspath yamlPath, YAML::Node &out);
}