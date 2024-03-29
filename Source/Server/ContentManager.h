// Copyright 2023 Justus Zorn

#ifndef ANOMALY_SERVER_CONTENT_MANAGER_H
#define ANOMALY_SERVER_CONTENT_MANAGER_H

#include <filesystem>
#include <string>
#include <unordered_map>
#include <vector>

#include <Server/Server.h>

class ContentManager {
public:
	void reload(Server& server);
	void init_client(Server& server, uint16_t client);

	uint32_t get_image_id(const std::string& path) const;
	uint32_t get_font_id(const std::string& path) const;
	uint32_t get_sound_id(const std::string& path) const;

	float get_image_aspect_ratio(const std::string& path) const;

private:
	struct Image {
		std::vector<uint8_t> data;
		std::filesystem::file_time_type last_write;
		uint32_t id;
		float aspect_ratio;
	};

	struct Font {
		std::vector<uint8_t> data;
		std::filesystem::file_time_type last_write;
		uint32_t id;
	};

	struct Sound {
		std::vector<uint8_t> data;
		std::filesystem::file_time_type last_write;
		uint32_t id;
	};

	uint32_t image_id = 1;
	std::unordered_map<std::filesystem::path, Image> images;

	uint32_t font_id = 1;
	std::unordered_map<std::filesystem::path, Font> fonts;

	uint32_t sound_id = 1;
	std::unordered_map<std::filesystem::path, Sound> sounds;
};

#endif
