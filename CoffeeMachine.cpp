#include <string>
#include <sstream>

extern "C"
{

    // === 1. Base Class: CoffeeMachine (Encapsulation, Abstraction, Constructor, Destructor) ===
    class CoffeeMachine
    {
    protected:
        int waterLevel;
        int beanLevel;

    public:
        CoffeeMachine() : waterLevel(0), beanLevel(0) {}
        virtual ~CoffeeMachine() {}

        std::string addWater(int ml)
        {
            waterLevel += ml;
            return "Added " + std::to_string(ml) + "ml water.";
        }

        std::string addBeans(int grams)
        {
            beanLevel += grams;
            return "Added " + std::to_string(grams) + "g beans.";
        }

        virtual std::string makeCoffee()
        {
            if (waterLevel >= 200 && beanLevel >= 15)
            {
                waterLevel -= 200;
                beanLevel -= 15;
                return "☕ Regular coffee made.";
            }
            else
            {
                return "Not enough water or beans.";
            }
        }

        std::string checkStatus()
        {
            std::ostringstream out;
            out << "Water: " << waterLevel << "ml | Beans: " << beanLevel << "g";
            return out.str();
        }
    };

    // === 2. Derived Class: SmartCoffeeMachine (Inheritance, Polymorphism) ===
    class SmartCoffeeMachine : public CoffeeMachine
    {
    public:
        SmartCoffeeMachine() : CoffeeMachine() {}

        std::string makeCoffee() override
        {
            if (waterLevel >= 150 && beanLevel >= 10)
            {
                waterLevel -= 150;
                beanLevel -= 10;
                return "☕ Smart coffee made (efficient mode).";
            }
            else
            {
                return "Smart machine needs more resources.";
            }
        }
    };

    // === 3. Instantiating Polymorphic Object ===
    CoffeeMachine *machine = new SmartCoffeeMachine();

    // === 4. Exposing C++ methods to JavaScript ===
    const char *addWater(int ml)
    {
        static std::string result;
        result = machine->addWater(ml);
        return result.c_str();
    }

    const char *addBeans(int grams)
    {
        static std::string result;
        result = machine->addBeans(grams);
        return result.c_str();
    }

    const char *makeCoffee()
    {
        static std::string result;
        result = machine->makeCoffee();
        return result.c_str();
    }

    const char *checkStatus()
    {
        static std::string result;
        result = machine->checkStatus();
        return result.c_str();
    }
}
