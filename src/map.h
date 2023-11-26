#include <raylib.h>
#include "star.h"
#include <vector>
#include <raymath.h>


class Map{

public:

    std::vector<Star> stars;
    int maxStars;
    Map(int a);
        

        
    

    void Update(Vector2 playerPos);


private:

    float GetRandomFloat(float min, float max);

};