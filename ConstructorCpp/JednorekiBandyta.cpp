#include <iostream>
#include "JednorekiBandyta.h"

    //list initalization
    SlotMachine::SlotMachine(): singleGameCost(nullptr), wonProbability(nullptr), prizePercentage(nullptr), prizePool(nullptr), numberOfGames(nullptr), income(nullptr), Logger(true) {
    Stopper runner;
    runner.reset();
    Logger a(true);
    a.log("List constructor"); 
    }

    // move constructor
    SlotMachine::SlotMachine(SlotMachine&& M): singleGameCost(nullptr), wonProbability(nullptr), prizePercentage(nullptr), prizePool(nullptr), numberOfGames(nullptr), income(nullptr), Logger(false){
                Stopper runner;
                runner.reset();
                // pass addresses
                singleGameCost = M.singleGameCost;
                wonProbability = M.wonProbability;
                prizePercentage = M.prizePercentage;
                prizePool = M.prizePool;
                numberOfGames = M.numberOfGames;
                income = M.income;
                // reset M 
                M.singleGameCost = nullptr; 
                M.wonProbability = nullptr;
                M.prizePercentage = nullptr;
                M.prizePool = nullptr;
                M.numberOfGames = nullptr;
                M.income = nullptr;

                Logger a(true);
                a.log("Move constructor");
    }

    // deep copy constructor
    SlotMachine::SlotMachine(const SlotMachine& M): Logger(false){

        Stopper runner;
        runner.reset();
        Logger a(false);
        a.log("Copy constructor");
           
        if(M.singleGameCost != nullptr){
            this->singleGameCost = new float;
            *this->singleGameCost = M.getCost();
        }
        else singleGameCost = nullptr;

        if(M.wonProbability){ 
        wonProbability = new float;
        *wonProbability = M.getWonp();
        }
        else wonProbability = nullptr;

        if(M.prizePercentage){ 
        prizePercentage = new int;
        *prizePercentage = M.getPercentage();
        }
        else prizePercentage = nullptr;

        if(M.prizePool){ 
        prizePool = new float;
        *prizePool = M.getPool();
        }
        else prizePool = nullptr;

        if(M.numberOfGames){ 
        numberOfGames = new int;
        *numberOfGames = M.getGames();
        }
        else numberOfGames = nullptr;

        if(M.income){ 
        income = new float;
        *income = M.getIncome();
        }
        else income = nullptr;
    }

    SlotMachine::SlotMachine(int parametr): singleGameCost(new float (parametr)), wonProbability(new float(parametr)),
     prizePercentage(new int(parametr)), prizePool(new float(parametr)), numberOfGames(new int(parametr)), income(new float(parametr)), Logger(true) {
    Stopper runner;
    runner.reset();
    Logger a(false);
    a.log("List constructor");
     }

    // class destructor
    SlotMachine::~SlotMachine(){
       Logger a(false);
       a.log("Destructor");
       if(wonProbability != nullptr) delete wonProbability;
       if(prizePool != nullptr) delete prizePool;
       if(income != nullptr) delete income;
       if(prizePercentage != nullptr) delete prizePercentage;
       if(numberOfGames != nullptr) delete numberOfGames;
       if(singleGameCost != nullptr) delete singleGameCost;
        std::cout << "cos" << std::endl;
    }

    void SlotMachine::setCost(float cost){
        Stopper runner;
        runner.start();
        Logger a(false);
        a.log("Set cost");
        if (this->singleGameCost == nullptr) this->singleGameCost = new float;
        *this->singleGameCost = cost;
        runner.stop();
        std::cout << std::endl <<"Set cost run time: " <<runner.getTime() << "s" <<std::endl;
    }

    float SlotMachine::getCost() const{
        Stopper runner;
        runner.start();
        Logger a(true);
        a.log("Get cost");
        runner.stop();
        std::cout << std::endl <<"Get cost run time: " <<runner.getTime() << "s" <<std::endl;
        return *singleGameCost;
    }

    void SlotMachine::setWonp(float win){
        Stopper runner;
        runner.start();
        Logger a(false);
        a.log("Set win");
        if (this->wonProbability == nullptr) this->wonProbability = new float;
        *this->wonProbability = win;
        runner.stop();
        std::cout << std::endl <<"Set win run time: " <<runner.getTime() << "s" <<std::endl;
    }

    float SlotMachine::getWonp() const{
        Stopper runner;
        runner.start();
        Logger a(true);
        a.log("Get win");
        runner.stop();
        std::cout << std::endl <<"Get win run time: " <<runner.getTime() << "s" <<std::endl;
        return *wonProbability;
    }

    void SlotMachine::setPercentage(int per){
        Stopper runner;
        runner.start();
        Logger a(false);
        a.log("Set percent");
        if (this->prizePercentage == nullptr) this->prizePercentage = new int;
        *this->prizePercentage = per;
        runner.stop();
        std::cout << std::endl <<"Set percent run time: " <<runner.getTime() << "s" <<std::endl;
    }

    int SlotMachine::getPercentage() const{
        Stopper runner;
        runner.start();
        Logger a(true);
        a.log("Get percent");
        runner.stop();
        std::cout << std::endl <<"Get percent run time: " <<runner.getTime() << "s" <<std::endl;
        return *prizePercentage;
    }

    float SlotMachine::getPool() const{
        Stopper runner;
        runner.start();
        Logger a(true);
        a.log("Get prize");
        runner.stop();
        std::cout << std::endl <<"Get prize run time: " <<runner.getTime() << "s" <<std::endl;
        return *prizePool;
    }

    int SlotMachine::getGames() const{
        Stopper runner;
        runner.start();
        Logger a(true);
        a.log("Get games");
        runner.stop();
        std::cout << std::endl <<"Get games run time: " <<runner.getTime() << "s" <<std::endl;
        return *numberOfGames;
    }

    float SlotMachine::getIncome() const{
        Stopper runner;
        runner.start();
        Logger a(true);
        a.log("Get income");
        runner.stop();
        std::cout << std::endl <<"Get income run time: " <<runner.getTime() << "s" <<std::endl;
        return *income;
    }


   

