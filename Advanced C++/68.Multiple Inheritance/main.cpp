#include <iostream>
using namespace std;

class MusicalInstrument {
public:
    virtual void play(){ cout << "Playing instrument ..." << endl; }
    virtual void reset(){ cout << "Resetting instrument ..." << endl; }
    virtual ~MusicalInstrument(){};
};

class Machine {
public:
    virtual void start(){ cout << "Starting machine ..." << endl; }
    virtual void reset(){ cout << "Resetting machine ..." << endl; }
    virtual ~Machine(){}
};

class Synthesizer: public Machine, public MusicalInstrument {
public:
    virtual ~Synthesizer(){};  // error: calling a private destructor of class 'Synthesizer'
};

int main() {

    Synthesizer *pSynth = new Synthesizer();

    pSynth->play();  // Method in MusicalInstrument
    pSynth->start();  // Method in Machine
    cout << endl;

    /*
     * Problem arises if a method that exists in both classes is called:
     * error: member 'reset' found in multiple base classes of different types
     */

    // pSynth->reset(); // Error
    pSynth->MusicalInstrument::reset();
    pSynth->Machine::reset();

    /*
     * One reason multiple inheritance is bad because e.g. `pSynth->Machine::reset();`
     * requires you to know how Synthesizer is implemented and you want to encapsulate
     * details of implementation as much as possible, you do not want the user of
     * Synthesizer class to have to know what the superclasses of Synthesizer are. In
     * general it is better to avoid multiple inheritance. If superclasses have methods
     * with identical signatures or identical prototypes the problem of ambiguous methods
     * arises, so they methods need to be disambiguated which involves knowing implementation
     * details of the derived class or child class.
     *
     */

    delete pSynth;


    return 0;
}