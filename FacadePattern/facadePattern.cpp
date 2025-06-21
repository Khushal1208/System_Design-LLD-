#include<iostream>
using namespace std;

class PowerSupply{
    public:
        void providePowe(){
            cout<<"Power Supply: Providing power..."<<endl;
        }
};
class CoolingSystem{
    public:
        void startFans(){
            cout<<"Cooling System: Fans started..."<<endl;
        }
};
class CPU{
    public:
        void initialize(){
            cout<<"CPU: Initialization started..."<<endl;
        }
};
class HardDrive{
    public:
        void spinUp(){
            cout<<"HardDrive: Spinning Up...."<<endl;
        }
};
class Memory{
    public:
        void selfTest(){
            cout<<"Memory: Self-test passed..."<<endl;
        }
};
class OperatingSystem {
    public:
        void load() {
        cout << "Operating System: Loading into memory..." << endl;
        }
};

class BIOS{
    public:
        void boot(CPU& cpu, Memory& memory){
            cout<<"BIOS: Booting CPU and Memory checks..."<<endl;
            cpu.initialize();
            memory.selfTest();
        }
};

class ComputerFacade{
    private:
        PowerSupply powersupply;
        CoolingSystem collingSystem;
        CPU cpu;
        Memory memory;
        HardDrive hardDrive;
        BIOS bios;
        OperatingSystem os;
    
    public:
        void startComputer(){
            cout << "----- Starting Computer -----" << endl;
            powersupply.providePowe();
            collingSystem.startFans();
            cpu.initialize();
            memory.selfTest();
            hardDrive.spinUp();
            bios.boot(cpu,memory);
            os.load();
            cout << "Computer Booted Successfully!" << endl;
        }
};


int main(){
    ComputerFacade computer;
    computer.startComputer();
    return 0;
}



