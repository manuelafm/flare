/*
Copyright © 2011-2012 Clint Bellanger

This file is part of FLARE.

FLARE is free software: you can redistribute it and/or modify it under the terms
of the GNU General Public License as published by the Free Software Foundation,
either version 3 of the License, or (at your option) any later version.

FLARE is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
FLARE.  If not, see http://www.gnu.org/licenses/
*/

/*
 * class Enemy
 */

#ifndef ENEMY_H
#define ENEMY_H


#include "Entity.h"
#include "Utils.h"
#include "Hazard.h"

#include <string>


class MapIso;
class PowerManager;


// active states
const int ENEMY_STANCE = 0;
const int ENEMY_MOVE = 1;
const int ENEMY_CHARGE = 2;
const int ENEMY_MELEE_PHYS = 3;
const int ENEMY_MELEE_MENT = 4;
const int ENEMY_RANGED_PHYS = 5;
const int ENEMY_RANGED_MENT = 6;
const int ENEMY_SPAWN = 7;

// interrupt states
const int ENEMY_BLOCK = 7;
const int ENEMY_HIT = 8;
const int ENEMY_DEAD = 9;
const int ENEMY_CRITDEAD = 10;
const int ENEMY_HALF_DEAD = 11;
const int ENEMY_DEBUFF = 12;
const int ENEMY_JOIN_COMBAT = 13;

class Enemy : public Entity {
protected:
	PowerManager *powers;

public:
	Enemy(PowerManager *_powers, MapIso *_map);
	~Enemy();
	bool lineOfSight();
	void logic();
	int faceNextBest(int mapx, int mapy);
	void newState(int state);
	int getDistance(Point dest) const;
	bool takeHit(Hazard h);
	void doRewards();

	virtual Renderable getRender() const;
	
	Hazard *haz;

	// sound effects flags
	bool sfx_phys;
	bool sfx_ment;
	
	bool sfx_hit;
	bool sfx_die;
	bool sfx_critdie;
	
	// other flags
	bool loot_drop;
	bool reward_xp;
};


#endif

