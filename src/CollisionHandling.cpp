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
#include "Artilary.h"

namespace {

    void grenade_worm(AbsObject& grenade, AbsObject& worm)
    {
    }

    void worm_grande(AbsObject& worm, AbsObject& granade)            
    {
        grenade_worm(granade, worm);
    }
//=============================================================
    void sheep_worm(AbsObject& sheep, AbsObject& worm)
    {
        //sound
    }

    void worm_sheep(AbsObject& worm, AbsObject& sheep)
    {
        sheep_worm(sheep, worm);
    }
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
    } 
    void staticObject_sheep(AbsObject& staticObject, AbsObject& sheep)
    {
        sheep_staticObject(sheep, staticObject);
    }
//=======================================================================
    void Stinky_Worm(AbsObject& stinky, AbsObject& worm)
    {
        auto i = static_cast<Worm&>(worm);
        i.setHelth();
        /*auto i = static_cast<Stinky&>(stinky);
        i.changeDirection();*/

    }
    void Worm_Stinky(AbsObject&  worm , AbsObject& Stinky)
    {
        Stinky_Worm(Stinky, worm);
	}
//=========================================================================
    void Stinky_staticObject(AbsObject&  stinky , AbsObject& staticObject)
    { 
        

     }
    void staticObject_Stinky(AbsObject&  staticObject , AbsObject& Stinky)
    {
        Stinky_staticObject(Stinky, staticObject);
	}
//=========================================================================
    void artilary_staticObject(AbsObject&  artilary , AbsObject& ALL)
    {
        auto i = static_cast<Artilary&>(artilary);
        i.setExplode();
	}
    void staticObject_artilary(AbsObject&  ALL , AbsObject& artilary)
    {
        artilary_staticObject(artilary, ALL);
	}
    
//=========================================================================
    void Worm_artilary(AbsObject& worm, AbsObject& artilary)
    {
        auto i = static_cast<Artilary&>(artilary);
        auto j = static_cast<Worm&>(worm);
        j.takeOffPoints(20);
        i.setExplode();
    }

    void artilary_Worm(AbsObject& artilary, AbsObject& worm)
    {
        Worm_artilary(worm, artilary);
    }

 //=======================================================================
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

        phm[Key(typeid(Dinamit), typeid(Worm))] = &Dinamit_worm;
        phm[Key(typeid(Worm), typeid(Dinamit))] = &worm_Dinamit;

        phm[Key(typeid(Grenade), typeid(staticObject))] = &Grenade_staticObject;
        phm[Key(typeid(staticObject), typeid(Grenade))] = &staticObject_Grenade;
        
        phm[Key(typeid(Stinky), typeid(Worm))] = &Stinky_Worm;
        phm[Key(typeid(Worm), typeid(Stinky))] = &Worm_Stinky;

        phm[Key(typeid(Stinky), typeid(staticObject))] = &Stinky_staticObject;
        phm[Key(typeid(staticObject), typeid(Stinky))] = &staticObject_Stinky;
        
        phm[Key(typeid(staticObject), typeid(Artilary))] = &staticObject_artilary;
        phm[Key(typeid(Artilary), typeid(staticObject))] = &artilary_staticObject;

        phm[Key(typeid(Worm), typeid(Artilary))] = &Worm_artilary;
        phm[Key(typeid(Artilary), typeid(Worm))] = &artilary_Worm;



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