#pragma once 
#include <Box2D/Box2D.h>

//----------class------------
class MyQueryCallback : public b2QueryCallback {
  public:
      
        //keep going to find all fixtures in the query area
      bool ReportFixture(b2Fixture* fixture) {
          m_foundBodies.push_back( fixture->GetBody() ); 
          return true;                             
      }
      std::vector<b2Body*> getFoundBodies() { return m_foundBodies; }
      virtual ~MyQueryCallback() = default;
private:
      std::vector<b2Body*> m_foundBodies;

  };
  