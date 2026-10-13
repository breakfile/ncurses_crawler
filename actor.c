#include "actor.h"
#include <stddef.h>

ACTOR scene_actors[128];
int nactors = 0; // number of actors

ACTOR create_actor() { // default values
	static int instance = -1;
	instance++;
	ACTOR new_actor;
	new_actor.instance = instance;
	new_actor.x = 0;
	new_actor.y = 0;
	new_actor.r = 1;
	new_actor.represent = '-';
	new_actor.collide = 1;
	new_actor.update = NULL;
	
	return new_actor;
}

ACTOR *add_actor(ACTOR actor) { // add to scene_actors
	scene_actors[nactors++] = actor;
	return &scene_actors[nactors-1];
}

void clear_actors() {
	nactors = 0;
}

void update_actors(int ch) {
	for (int i = 0; i < nactors; i++) {
		if (scene_actors[0].update) {
			scene_actors[0].update(&scene_actors[0], ch);
		}
	}
}
