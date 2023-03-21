// Copyright 2023 Justus Zorn

#ifndef ANOMALY_SERVER_SERVER_H
#define ANOMALY_SERVER_SERVER_H

#include <string>
#include <vector>

#include <enet.h>

#include <Anomaly.h>
#include <Server/Script.h>

class ContentManager;

class Server {
public:
	Server(ContentManager& content, uint16_t port);
	Server(const Server&) = delete;
	~Server();

	Server& operator=(const Server&) = delete;

	void update(Script& script, double dt);

	void update_client_content(uint16_t client, ContentType type, uint32_t id, const std::vector<uint8_t>& data);
	void update_content(ContentType type, uint32_t id, const std::vector<uint8_t>& data);

	bool start_text_input(uint16_t client);
	bool stop_text_input(uint16_t client);

	int draw_sprite(uint16_t client, const std::string& path, float x, float y, float scale);
	int draw_text(uint16_t client, const std::string& path, float x, float y, float scale,
		uint8_t r, uint8_t g, uint8_t b, std::string text);

	bool kick(uint16_t client);

private:
	ContentManager* content;
	ENetHost* host;

	struct Client {
		bool connected = false;
		ENetPeer* peer;
		std::vector<Sprite> sprites;
		std::vector<Command> commands;
	};

	std::vector<Client> clients;

	ENetPacket* create_sprite_packet(Client& client);
	ENetPacket* create_command_packet(Client& client);
	static ENetPacket* create_content_packet(ContentType type, uint32_t id, const std::vector<uint8_t>& data);

	void client_input(uint16_t client, ENetPacket* input_packet, Script& script);
};

#endif
