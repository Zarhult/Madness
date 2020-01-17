#include "mob.hpp"

class cultist : public mobBase {
    public:
        const char* alertMsg = "You have encountered a cultist!";
        const char* descriptionMsg = "Worshippers of the Great Old Ones who have self-mutilated for dark power, corroding their sanity and making them dangerous and unpredictable.";
	cultist() : mobBase(5, 5, 5, alertMsg, descriptionMsg, '$') {}

        virtual void event(WINDOW* win); 
};
