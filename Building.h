
#ifndef BUILDING_H
#define BUILDING_H
#include "GameObject.h"
#include <iostream>
class Building: public GameObject{
private:
    unsigned int trainer_count;
public:
    Building();
    Building(char in_code, int in_id, Point2D in_loc);
    void AddOneTrainer();
    void RemoveOneTrainer();
    void ShowStatus();
    bool ShouldBeVisible();
    virtual ~Building();
};
#endif
