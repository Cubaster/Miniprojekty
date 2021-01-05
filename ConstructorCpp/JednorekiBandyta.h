#include <iostream>
#include "Logger.h"
#include "Stopper.h"

class SlotMachine: Logger, Stopper{

   private:
    // enable lazy loading
    float* singleGameCost;
    float* wonProbability;
    int* prizePercentage;
    float* prizePool;
    int* numberOfGames;
    float* income;

    public:
    SlotMachine();
    //deep copy
    SlotMachine(const SlotMachine& M);
    // move
    SlotMachine(SlotMachine&& M); 
    // convert 
    SlotMachine(int parameter);

    // class destructor
    ~SlotMachine();
    void setCost(float cost);
    float getCost() const;
    void setWonp(float win);
    float getWonp() const;
    void setPercentage(int per);
    int getPercentage() const;
    float getPool() const;
    int getGames() const;
    float getIncome() const;

};

