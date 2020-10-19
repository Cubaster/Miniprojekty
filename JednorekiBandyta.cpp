#include <iostream>

using namespace std;

//Jednoręki Bandyta
class SlotMachine{

public:

SlotMachine();
bool define_single_game_cost(float cost);
float read_single_game_code();
bool define_single_game_percentage_to_pool(int percentage);
int read_single_game_percentage_to_pool();
bool define_win_probability(float win_prob);
float game_result(string state);
float read_pool_prize();
int played_games();
float daily_income(); 

protected:

float single_game_cost;
float win_probability;
int prize_pool_percentage;
float prize_pool;
int number_of_games;
float income;


private:


};

SlotMachine::SlotMachine(){
    this->number_of_games=0;
    this->prize_pool=0;
}

bool SlotMachine::define_single_game_cost(float cost){
    if(cost >0){
        this->single_game_cost=cost;
        return true;
    }
    return false;
}

float SlotMachine::read_single_game_code(){
    return this->single_game_cost;
}

bool SlotMachine::define_single_game_percentage_to_pool(int percentage){
    if(percentage> 0 && percentage <=70){
        this->prize_pool_percentage=percentage;
        return true;
    }
    return false;
}

int SlotMachine::read_single_game_percentage_to_pool(){
    return this->prize_pool_percentage;
}


bool SlotMachine::define_win_probability(float win_prob){
    if(win_prob >=0.1 && win_prob <= 0.2){
        this->win_probability=win_prob;
        return true;
    }
    return false;
}

float SlotMachine::game_result(string state){
    this->number_of_games++;
    if(state=="win"){
        return this->prize_pool;
    }
    this->prize_pool+=this->prize_pool_percentage * this->single_game_cost/100;
    return 0;
}

float SlotMachine::read_pool_prize(){
    return this->prize_pool;
}

int SlotMachine::played_games(){
    return this->number_of_games;
}

float SlotMachine::daily_income(){
    this->income = this->number_of_games* this->single_game_cost * (100 - this ->prize_pool_percentage ) / 100;
    return this->income;
}




int main(){
    SlotMachine sm;

    float cost=3.50, win_prob=0.15;
    int percentage= 40;
    string state="lose", state1="win";

    if(sm.define_single_game_cost(cost)){
    cout<<"Single game cost set to: "<<sm.read_single_game_code()<<endl;
    } 
    else{
        cout<<"Amount of money has to be greater then zero";
    }


    if(sm.define_single_game_percentage_to_pool(percentage)){
        cout<<sm.read_single_game_percentage_to_pool()<<"% of single game goes to pool prize"<<endl;
    }
    else{
        cout<<"Error! Percentage has to be from 1 to 70"<<endl;
    }


    if(sm.define_win_probability(win_prob)){
        cout<<"Win probability set"<<endl;
    }
    else{
        cout<<"Probability range is <0.1-0.2>";
    }

    
    cout<<"You won: "<<sm.game_result(state)<<endl;
    cout<<"Actual pool prize is: "<<sm.read_pool_prize()<<endl;
    cout<<"You won: "<<sm.game_result(state)<<endl;
    cout<<"Actual pool prize is: "<<sm.read_pool_prize()<<endl;
    cout<<"You won: "<<sm.game_result(state)<<endl;
    cout<<"Actual pool prize is: "<<sm.read_pool_prize()<<endl;
    cout<<"You won: "<<sm.game_result(state1)<<endl;
    cout<<"You played "<<sm.played_games()<<" games"<<endl;
    cout<<"Daily income is: "<<sm.daily_income()<<endl;
    return 0;
}