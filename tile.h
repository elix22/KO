/* KO
// Copyright (C) 2015 LucKey Productions (luckeyproductions.nl)
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#pragma once

#include "mastercontrol.h"
#include "dungeon.h"
#include <Urho3D/Physics/RigidBody.h>
#include <Urho3D/Core/CoreEvents.h>

namespace Urho3D {
class Drawable;
class Node;
class Scene;
class Sprite;
}

using namespace Urho3D;

class Dungeon;

class Tile : public Object
{
    friend class Dungeon;
    friend class Deco;
    OBJECT(Tile);
public:
    Tile(Context *context, const IntVector2 coords, Dungeon *platform);

    virtual void Start();
    virtual void Stop();


    IntVector2 coords_;
    TileType buildingType_ = TT_EMPTY;
    double GetHealth(){return health_;}
    double ApplyDamage(double damage){health_ = Max(health_ - damage, 0.0);}
private:
    void HandleUpdate(StringHash eventType, VariantMap& eventData);
    MasterControl* masterControl_;
    Dungeon* dungeon_;
    Node* rootNode_;
    CollisionShape* collisionShape_;
    Node* elements_[TE_LENGTH];
    double health_ = 1.0;
    void FixFringe();
};
