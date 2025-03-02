#ifndef CONFIG_SERIALIZER_HPP
#define CONFIG_SERIALIZER_HPP

#include "Config.hpp"

#include <filesystem>
#include <fstream>
#include <string>
#include <unordered_map>
#include <variant>

namespace Serialization
{

void SerializePlainText(const std::filesystem::path& path, const Config& cfg);

Config DeserializePlainText(const std::filesystem::path& path);

void SerializeJSON(const std::filesystem::path& path, const Config& cfg);

Config DeserializeJSON(const std::filesystem::path& path);

} // namespace Serialization

#endif // CONFIG_SERIALIZER_HPP