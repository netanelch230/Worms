#pragma once
#include "CollisionHandling.h"
#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
#include <typeindex>

#include "Grenade.h"
#include "Worm.h"
#include "Sheep.h"
#include "staticObject.h"
#include "Stinky.h"
#include"Dinamit.h"


namespace {

//=============================================================
    void Dinamit_worm(AbsObject& dinamit, AbsObject& worm)
    {
        auto i= static_cast<Dinamit&>(dinamit);
        auto j = static_cast<Worm&>(worm);
        j.takeOffPoints(90);
    }

    void worm_Dinamit(AbsObject& worm, AbsObject& Dinamit)
    {
        Dinamit_worm(Dinamit, worm);
    }
//========================================================================
   void Worm_Worm(AbsObject& worm1, AbsObject& worm2)
    {
       auto i = static_cast<Worm&>(worm1);
       auto j = static_cast<Worm&>(worm2);
       float y = i.getBody()->GetPosition().y;
       float y2 = j.getBody()->GetPosition().y;


        if (abs((i.getBody()->GetPosition().y) - (j.getBody()->GetPosition().y) < 20* MPP))
            i.getBody()->ApplyForce({ 15,10 }, i.getBody()->GetWorldCenter(), true);

    }
 //=======================================================================
    using HitFunctionPtr = void (*)(AbsObject&, AbsObject&);
    using Key = std::pair<std::type_index, std::type_index>;
    using HitMap = std::map<Key, HitFunctionPtr>;

    
    HitMap initializeCollisionMap()
    {
        HitMap phm;

        phm[Key(typeid(Dinamit), typeid(Worm))] = &Dinamit_worm;
        phm[Key(typeid(Worm), typeid(Dinamit))] = &worm_Dinamit;
        phm[Key(typeid(Worm), typeid(Worm))] = &Worm_Worm;
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

//=======================================================================
void processCollision(AbsObject* object1, AbsObject* object2)
{
        auto phf = lookup(typeid(*object1), typeid(*object2));
        if (phf)
        {
            phf(*object1, *object2);
            
        }
       
}