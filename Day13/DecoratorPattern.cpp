#include <iostream>
#include<string>
using namespace std;

class Character{
    public:
        virtual string getAbilities() const = 0;
        virtual ~Character(){}
};

class Mario: public Character{
    public:
        string getAbilities() const override{
            return "Mario";
        }
};

// is-a relationship with Character
class CharacterDecorator: public Character{ 
    protected:
        Character* character; // has-a relationship with Character
    public:
        CharacterDecorator(Character* c){
            this->character = c;
        }
};

class HeightUp : public CharacterDecorator{
    public:
        HeightUp(Character* c): CharacterDecorator(c){}
        string getAbilities() const override{
            return character->getAbilities() + " with HeightUp";
        }
};

class GunPowerUp: public CharacterDecorator{
    public:
        GunPowerUp(Character* c): CharacterDecorator(c){}
        string getAbilities() const override{
            return character->getAbilities() + " with Gun";
        }
};

class StarPowerUp: public CharacterDecorator{
    public:
        StarPowerUp(Character* c): CharacterDecorator(c){};
        string getAbilities() const override{
            return character->getAbilities() + " with Start Power (Limited Time)";
        }
        
        ~StarPowerUp(){
            cout<<"Destroying StartPowerUp Decorator"<<endl;
        }
};


int main()
{
    Character* mario = new Mario();
    cout<< "Basic Character: "<< mario->getAbilities()<<endl;
    
    mario = new HeightUp(mario);
    cout<< "After HeightUp: "<< mario->getAbilities()<<endl;
    
    mario = new GunPowerUp(mario);
    cout<< "After GunPowerUp: "<< mario->getAbilities()<<endl;
    
    mario = new StarPowerUp(mario);
    cout<< "After StartPowerUp: "<< mario->getAbilities()<<endl;
    
    delete mario;

    return 0;
}