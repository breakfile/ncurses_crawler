#pragma once

// Overworld actors

typedef struct actor {
	int instance; // how many times has an object been created (because you can't compare structs)
	int x, y, r; // position, render?
	char represent; // what will be drawn
	int collide; // collide with player?
	void (*update)(struct actor*, int ch); // called every frame
} ACTOR;

ACTOR create_actor();
ACTOR *add_actor(ACTOR actor);
void clear_actors();
void update_actors(int ch);
