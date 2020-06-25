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
        auto i = static_cast<Grenade&>(grenade);
        auto j = static_cast<Worm&>(worm);
        i.play();
        j.takeOffPoints(150);
    }

    void worm_grande(AbsObject& worm, AbsObject& granade)            
    {
        grenade_worm(granade, worm);
    }
//=============================================================
    void sheep_worm(AbsObject& sheep, AbsObject& worm)
    {
        auto i = static_cast<Sheep&>(sheep);
        auto j = static_cast<Worm&>(worm);
        i.play();
        j.takeOffPoints(100);
    }

    void worm_sheep(AbsObject& worm, AbsObject& sheep)
    {
        sheep_worm(sheep, worm);
    }
//=============================================================
    void axe_worm(AbsObject& axe, AbsObject& worm)
    {
        auto i= static_cast<Axe&>(axe);
        auto j = static_cast<Worm&>(worm);
        j.takeOffPoints(90);
    }

    void worm_axe(AbsObject& worm, AbsObject& axe)
    {
        axe_worm(axe, worm);
    }
//=============================================================
    void Grenade_staticObject(AbsObject& Grenade, AbsObject& staticObject)
    {

    }
    void staticObject_Grenade(AbsObject& staticObject, AbsObject& granade)
    {
          
    }
//=============================================================
    void sheep_staticObject(AbsObject& sheep, AbsObject& staticObject)
    {
        auto i= static_cast<Sheep&>(sheep);
        i.changeDirection();
    } 
    void staticObject_sheep(AbsObject& staticObject, AbsObject& sheep)
    {
        sheep_staticObject(sheep, staticObject);
    }
//=============================================================
    using HitFunctionPtr = void (*)(AbsObject&, AbsObject&);
    using Key = std::pair<std::type_index, std::type_index>;
    using HitMap = std::map<Key, HitFunctionPtr>;

    
    HitMap initializeCollisionMap()
    {
        HitMap phm;
        phm[Key(typeid(Grenade), typeid(Worm))] = &grenade_worm;
        phm[Key(typeid(Worm), typeid(Grenade))] = &worm_grande;

        phm[Key(typeid(Sheep), typeid(Worm))] = &sheep_worm;
        phm[Key(typeid(Worm), typeid(Sheep))] = &worm_sheep;
        
        phm[Key(typeid(Sheep), typeid(staticObject))] = &sheep_staticObject;
        phm[Key(typeid(staticObject), typeid(Sheep))] = &staticObject_sheep;

        phm[Key(typeid(Axe), typeid(Worm))] = &axe_worm;
        phm[Key(typeid(Worm), typeid(Axe))] = &worm_axe;

        phm[Key(typeid(Grenade), typeid(staticObject))] = &Grenade_staticObject;
        phm[Key(typeid(staticObject), typeid(Grenade))] = &staticObject_Grenade;

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
void processCollision(AbsObject* object1, AbsObject* object2)
{
    auto phf = lookup(typeid(*object1), typeid(*object2));
    if (phf)
    {
        phf(*object1, *object2);
        //  throw UnknownCollision(object1, object2);
    }
    
}