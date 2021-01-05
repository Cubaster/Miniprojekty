#include "Wezel.h"


int main(){
    for(int i=0; i < 10; i++){
        //std::unique_ptr<Wezel>(new Wezel());
        std::shared_ptr<Wezel> w = std::make_shared<Wezel>();
        std::shared_ptr<Wezel> w1 = std::make_shared<Wezel>();
        std::weak_ptr<Wezel> wp(w);
        std::weak_ptr<Wezel> wp1(w1);
        w->next(w1);
        w1->next(w); 
        w->weaknext(wp);
        w1->weaknext(wp1);

    }
    return 0;
}

// in cpp object is destroyed at the and of the program but in java reference to object remains

// after changing unique_ptr to shared_ptr there is no difference

// after adding shared_ptr to Wezel class  destructor was not call