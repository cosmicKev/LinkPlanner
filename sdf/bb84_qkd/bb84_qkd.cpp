
#include "netxpto.h"
#include "binary_source.h"
#include "clock.h"
#include "alice_qkd.h"
#include "single_photon_source.h"
#include "polarizer.h"
#include "sink.h"

int main()
{
	// #####################################################################################################
	// ################################# System Input Parameters #########################################
	// #####################################################################################################

	double RateOfPhotons{ 1e3 };

	// #####################################################################################################
	// ########################### Signals Declaration and Inicialization ##################################
	// #####################################################################################################

	// Alice Implementation
	Binary NUM_A{ "NUM_A.sgn" };
	ElectricalSignal CLK_A{ "CLK_A.sgn" };
	ElectricalSignal S_A1{ "S_A1.sgn" };
	PhotonStream S_A3{ "S_A3.sgn" };
	PhotonStream Q_C_1{ "S_C_1.sgn" };
	ElectricalSignal S_A2{ "S_A2.sgn" };
	Messages C_C_1{ "C_C_1.sgn" };
	Messages C_C_6{ "C_C_1.sgn" };
	Binary Data_A{ "Data_A.sgn" };

	// #####################################################################################################
	// ########################### Blocks Declaration and Inicialization ##################################
	// #####################################################################################################

	BinarySource B1{ vector <Signal*> {}, vector <Signal*> {&NUM_A} };
	BS1.setMode( PseudoRandom );

	Clock B2{ vector <Signal*> {}, vector <Signal*> {&CLK_A} };

	AliceQkd B3{ vector <Signal*> {&CLK_A}, vector <Signal*> {&S_A1} };
	BS2.setNumberOfSamplesPerSymbol(16);
	
	SinglePhotonSource B4{ vector <Signal*> {&S_A1}, vector <Signal*> {&S_A3} };
	//BS4.setPolarization(S_A2);

	Polarizer B5{ vector <Signal*> {&S_A1}, vector <Signal*> {&S_A3} };

	Sink B6

	// ####################################################################################################
	// ########################### System Declaration and Inicialization ##################################
	// #####################################################################################################

	System MainSystem{ vector <Block*> {&BS1, &clk1, &BS2, &BS3, &BS4} };

	// ####################################################################################################
	// ########################### Run ##################################
	// #####################################################################################################

	MainSystem.run();


    return 0;
}

