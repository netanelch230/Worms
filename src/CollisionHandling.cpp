#pragma once
#include "CollisionHandling.h"
#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
#include <typeindex>

#include "Grenade.h"
#include "Worm.h"
#include "Axe.h"
#include "Sheep.h"
#include "Flik.h"
#include "staticObject.h"

namespace {

    void grenade_worm(AbsObject& grenade, AbsObject& worm)
    {
        auto gren = static_cast<Grenade&>(grenade);
        auto wrm = static_cast<Worm&>(worm);
        gren.explode();
        //wrm.
    }

    void worm_grande(AbsObject& object1, AbsObject& object2)            
    {

    }

    void sheep_worm(AbsObject& object1, AbsObject& object2)
    {

    }

    void worm_sheep(AbsObject& object1, AbsObject& object2)
    {

    }

    void axe_worm(AbsObject& object1, AbsObject& object2)
    {

    }

    void worm_axe(AbsObject& object1, AbsObject& object2)
    {

    }
    void Grenade_staticObject(AbsObject& Grenade, AbsObject& staticObject)
    {

    }
    void staticObject_Grenade(AbsObject& object1, AbsObject& object2)
    {

    }


    using HitFunctionPtr = void (*)(AbsObject&, AbsObject&);
    using Key = std::pair<std::type_index, std::type_index>;
    using HitMap = std::map<Key, HitFunctionPtr>;



    
    //---------------------------------------------
    //----------------------------------------------------------------------
    HitMap initializeCollisionMap()
    {
        HitMap phm;
        phm[Key(typeid(Grenade), typeid(Worm))] = &grenade_worm;
        phm[Key(typeid(Worm), typeid(Grenade))] = &worm_grande;

        phm[Key(typeid(Sheep), typeid(Worm))] = &sheep_worm;
        phm[Key(typeid(Worm), typeid(Sheep))] = &worm_sheep;

        phm[Key(typeid(Axe), typeid(Worm))] = &axe_worm;
        phm[Key(typeid(Worm), typeid(Axe))] = &worm_axe;

        phm[Key(typeid(Grenade), typeid(staticObject))] = &Grenade_staticObject;
        phm[Key(typeid(Worm), typeid(Grenade))] = &staticObject_Grenade;

        /* phm[Key(typeid(Flick), typeid(Worm   ))] = &flick_worm;
         phm[Key(typeid(Worm), typeid(Flick    ))] = &worm_flick;*/

        return phm;
    }
    HitFunctionPtr lookup(const std::type_index& class1, const std::type_index& class2)
    {
        static HitMap collisionMap = initializeCollisionMap();
        auto mapEntry = collisionMap.find(std::make_pair(class1, class2));
        if (mapEntry == collisionMap.end())
        {
            return nullptr;
        }
        return mapEntry->second;
    }
    
}

void processCollision(AbsObject& object1, AbsObject& object2)
{
    auto phf = lookup(typeid(object1), typeid(object2));
    if (!phf)
    {
        //  throw UnknownCollision(object1, object2);
    }
    phf(object1, object2);
}