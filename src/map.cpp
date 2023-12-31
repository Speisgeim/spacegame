#include "map.h"





Map::Map(int a){
    maxStars = 1000;
    int numStars = maxStars/4; 

    // Calculate angle and distance for star positions
    for (int i = stars.size(); i < maxStars && i < static_cast<int>(stars.size()) + numStars; ++i) {
        float angle = GetRandomFloat(0, 2 * PI);
        float distance = GetRandomFloat(0, 2000);
        Vector2 starPos = {0 + distance * cosf(angle), 0 + distance * sinf(angle)};
        float starRadius = GetRandomFloat(1, 4); 
        stars.push_back(Star(starPos, starRadius));
    }
    
}

void Map::Update(Vector2 playerPos){

    const float spawnRadius = 2000.0f;   
    const float maxSpawnRadius = 1000.0f; 

    // Generate stars if the current count is less than the maximum
    if (static_cast<int>(stars.size()) < maxStars) {
        int numStars = 10; // Adjust this value based on how many stars you want to spawn

        // Calculate angle and distance for star positions
        for (int i = stars.size(); i < maxStars && i < static_cast<int>(stars.size()) + numStars; ++i) {
            float angle = GetRandomFloat(0, 2 * PI);
            float distance = GetRandomFloat(maxSpawnRadius, spawnRadius);
            Vector2 starPos = {playerPos.x + distance * cosf(angle), playerPos.y + distance * sinf(angle)};
            float starRadius = GetRandomFloat(1, 4); // Adjust this value based on the desired star radius
            stars.push_back(Star(starPos, starRadius));
        }
    }
    const float maxDistance = 1500.0f;
    for (auto it = stars.begin(); it != stars.end(); ) {
        float distance = Vector2Distance(playerPos, it->position);
        if (distance > maxDistance) {
            it = stars.erase(it);
        } else {
            ++it;
        }
    }

    for (Star& star : stars){

        star.Draw();
    }
}




float Map::GetRandomFloat(float min, float max) {
    return min + static_cast<float>(GetRandomValue(0, 10000)) / 10000.0f * (max - min);
}
