//
// Created by gnations on 8/6/2019.
//
#pragma once

#include <../Plutonium/include/pu/Plutonium>
#include "masterinc.h"
#include "soundlib.h"

#ifndef NXPLAYER_NXPLAYERUI_H
#define NXPLAYER_NXPLAYERUI_H


class NXPlayerUI : pu::Layout {
public:
	NXPlayerUI();
	void updateTrackName(std::string name);
	void addTracksToQueue(std::string dirname);
	Mix_Music * randomMusic();
	void playTrack(Mix_Music *track);
	void initializeTrackQueue();
	json_object * createJsonObject();
	json_object * createInt(int value);
	json_object * createString(const char* value);
	json_object * createArray(int value[4]);
	void addChildToJsonObject(json_object *parent, char* keyname, json_object *child);
	const char* getJsonString(json_object *parent);
	const char* getTrackName(json_object *json);
	Mix_Music* getTrack(json_object *json);
	const char* createTrackObject(std::string trackname, Mix_Music* track);
private:
	Mix_Music *currentTrack;
	std::vector<Mix_Music*> trackQueue;
	pu::element::TextBlock *trackName;
	pu::element::Button    *skipfButton;
	pu::element::Button    *skipbButton;
	pu::element::Button    *playButton;
	pu::element::Button    *pauseButton;
	pu::element::Button    *repeatButton;
};

class NXPlayer : public pu::Application
{
public:
	NXPlayer();

private:
	NXPlayerUI *ui;
};

#endif //NXPLAYER_NXPLAYERUI_H
