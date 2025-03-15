#pragma once

#include "Config.hpp"

#include <filesystem>
#include <fstream>
#include <string>
#include <map>
#include <variant>

namespace Serialization
{

void SerializePlainText(const std::filesystem::path& path, const Config& cfg);

Config DeserializePlainText(const std::filesystem::path& path);

void SerializeJSON(const std::filesystem::path& path, const Config& cfg);

Config DeserializeJSON(const std::filesystem::path& path);

void SerializeXML(const std::filesystem::path& path, const Config& cfg);

Config DeserializeXML(const std::filesystem::path& path);

void SerializeBinary(const std::filesystem::path& path, const Config& cfg);

Config DeserializeBinary(const std::filesystem::path& path);

void SerializeYAML(const std::filesystem::path& path);

Config DeserializeYAML(const std::filesystem::path& path);

} // namespace Serialization
