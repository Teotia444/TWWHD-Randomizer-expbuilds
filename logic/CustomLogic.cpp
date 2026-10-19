#include "logic/CustomLogic.hpp"

#include <libs/yaml.hpp>

CustomLogic::LogicError CustomLogic::loadWorldYaml(fspath yamlPath, YAML::Node &out){
    bool isEmbed = Utility::toUtf8String(yamlPath)[0] == ':';
    return LoadYAML(out, yamlPath / "world.yaml", isEmbed) && !out.IsNull() ? CustomLogic::NONE : CustomLogic::WORLD_YAML_ERROR;
}
CustomLogic::LogicError CustomLogic::loadMacrosYaml(fspath yamlPath, YAML::Node &out){
    bool isEmbed = Utility::toUtf8String(yamlPath)[0] == ':';
    return LoadYAML(out, yamlPath / "macros.yaml", isEmbed) && !out.IsNull() ? CustomLogic::NONE : CustomLogic::MACROS_YAML_ERROR;
}
CustomLogic::LogicError CustomLogic::loadAreaNamesYaml(fspath yamlPath, YAML::Node &out){
    bool isEmbed = Utility::toUtf8String(yamlPath)[0] == ':';
    if(!LoadYAML(out, yamlPath / "area_names.yaml", isEmbed) || out.IsNull()){
        LoadYAML(out, Utility::get_data_path() / "logic/area_names.yaml", true);
        return CustomLogic::NON_ESSENTIAL_FILE_ERROR;
    }
    return CustomLogic::NONE;
}
CustomLogic::LogicError CustomLogic::loadDungeonEntranceInfoYaml(fspath yamlPath, YAML::Node &out){
    bool isEmbed = Utility::toUtf8String(yamlPath)[0] == ':';
    if(!LoadYAML(out, yamlPath / "dungeon_entrance_info.yaml", isEmbed) || out.IsNull()){
        LoadYAML(out, Utility::get_data_path() / "logic/dungeon_entrance_info.yaml", true);
        return CustomLogic::NON_ESSENTIAL_FILE_ERROR;
    }
    return CustomLogic::NONE;
}
CustomLogic::LogicError CustomLogic::loadEntranceShuffleTableYaml(fspath yamlPath, YAML::Node &out){
    bool isEmbed = Utility::toUtf8String(yamlPath)[0] == ':';
    if(!LoadYAML(out, yamlPath / "entrance_shuffle_table.yaml", isEmbed) || out.IsNull()){
        LoadYAML(out, Utility::get_data_path() / "logic/entrance_shuffle_table.yaml", true);
        return CustomLogic::NON_ESSENTIAL_FILE_ERROR;
    }
    return CustomLogic::NONE;
}
CustomLogic::LogicError CustomLogic::loadItemDataYaml(fspath yamlPath, YAML::Node &out){
    bool isEmbed = Utility::toUtf8String(yamlPath)[0] == ':';
    if(!LoadYAML(out, yamlPath / "item_data.yaml", isEmbed) || out.IsNull()){
        LoadYAML(out, Utility::get_data_path() / "logic/item_data.yaml", true);
        return CustomLogic::NON_ESSENTIAL_FILE_ERROR;
    }
    return CustomLogic::NONE;
}
CustomLogic::LogicError CustomLogic::loadLocationDataYaml(fspath yamlPath, YAML::Node &out){
    bool isEmbed = Utility::toUtf8String(yamlPath)[0] == ':';
    if(!LoadYAML(out, yamlPath / "location_data.yaml", isEmbed)|| out.IsNull()){
        LoadYAML(out, Utility::get_data_path() / "logic/location_data.yaml", true);
        return CustomLogic::NON_ESSENTIAL_FILE_ERROR;
    }
    return CustomLogic::NONE;
}

bool CustomLogic::validateCustomLogicEssential(fspath yamlPath){
    YAML::Node dummy;
    return CustomLogic::loadWorldYaml(yamlPath, dummy) == CustomLogic::NONE && CustomLogic::loadMacrosYaml(yamlPath, dummy) == CustomLogic::NONE;
}