// Copyright 2023 Justus Zorn

#ifndef ANOMALY_SERVER_SCRIPT_H
#define ANOMALY_SERVER_SCRIPT_H

#include <string>

#include <lua.hpp>

class Server;

class Script {
public:
	Script(Server& server);
	Script(const Script&) = delete;
	~Script();

	Script& operator=(const Script&) = delete;

	void reload();

	void on_tick(double dt);

	void on_join(uint16_t client, bool has_touch);
	void on_quit(uint16_t client);

	void on_key_event(uint16_t client, int32_t key, bool down);
	void on_finger_event(uint16_t client, float x, float y, uint8_t finger, uint8_t type);
	void on_mouse_button(uint16_t client, float x, float y, uint8_t button, bool down);
	void on_mouse_motion(uint16_t client, float x, float y);

private:
	Server* server;
	lua_State* L;

	void on_reload();

	static int start_text_input(lua_State* L);
	static int stop_text_input(lua_State* L);
	static int get_composition(lua_State* L);

	static int draw_sprite(lua_State* L);
	static int draw_text(lua_State* L);

	static int kick(lua_State* L);

	static int play_sound(lua_State* L);
	static int stop_sound(lua_State* L);
	static int stop_all_sounds(lua_State* L);

	bool get_function(const char* name);
	void register_callback(const char* name, lua_CFunction callback);
};

#endif
