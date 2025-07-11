#include <string>
#include <iostream>

extern "C"
{
    int waterLevel = 0;
    int coffeeBeans = 0;

    const char *addWater(int ml)
    {
        waterLevel += ml;
        return "Water added.";
    }

    const char *addBeans(int grams)
    {
        coffeeBeans += grams;
        return "Beans added.";
    }

    const char *makeCoffee()
    {
        if (waterLevel >= 200 && coffeeBeans >= 15)
        {
            waterLevel -= 200;
            coffeeBeans -= 15;
            return "☕ Coffee made!";
        }
        else
        {
            return "Not enough resources.";
        }
    }

    const char *checkStatus()
    {
        static std::string status;
        status = "Water: " + std::to_string(waterLevel) +
                 "ml, Beans: " + std::to_string(coffeeBeans) + "g";
        return status.c_str();
    }
}
