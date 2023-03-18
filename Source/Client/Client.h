// Copyright 2023 Justus Zorn

#ifndef ANOMALY_CLIENT_CLIENT_H
#define ANOMALY_CLIENT_CLIENT_H

#include <string>

#include <enet.h>

#include <Renderer/Window.h>

class Client {
public:
	Client(const std::string& hostname, uint16_t port, Window& window);
	Client(const Client&) = delete;
	~Client();

	Client& operator=(const Client&) = delete;

	bool update();

private:
	ENetHost* host = nullptr;
	ENetPeer* peer = nullptr;

	//void update_content(Renderer& window, ENetPacket* packet);
	//void draw(Renderer& renderer, ENetPacket* packet);
};

#endif
