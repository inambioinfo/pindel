/*
 * ControlState.h
 *
 *  Created on: May 19, 2011
 *      Author: Leon Mei
 */

#ifndef CONTROLSTATE_H_
#define CONTROLSTATE_H_
#include <iostream>
#include <fstream>
#include "pindel.h"

struct BreakDancer {
	BreakDancer() {
		ChrName_A = "";
		ChrName_B = "";
		Size = 0;
		Score = 0;
		S1 = 0;
		S2 = 0;
		S3 = 0;
		S4 = 0;
	}
	std::string ChrName_A;
	std::string ChrName_B;
	std::string Type;
	int Size;
	int Score;
	unsigned S1;
	unsigned S2;
	unsigned S3;
	unsigned S4;
};

class ControlState {
public:

	ControlState();
	virtual ~ControlState();

	bool SpecifiedChrVisited;
	std::ifstream inf_Seq;
	std::ifstream inf_Pindel_Reads;
	std::string bam_file;
	std::string OutputFolder;
	std::string WhichChr;
	std::string line;
	std::vector<bam_info> bams_to_parse;
	std::ifstream config_file;
	bam_info info;

	std::ifstream inf_ReadsSeq; // input file name
	std::ifstream inf_BP_test; // input file name
	std::ifstream inf_BP; // input file name
	bool BAMDefined;
	bool PindelReadDefined;
	bool BreakDancerDefined;

	std::string SIOutputFilename;
	std::string DeletionOutputFilename;
	std::string TDOutputFilename;
	std::string InversionOutputFilename;
	std::string LargeInsertionOutputFilename;
	std::string RestOutputFilename;

	bool loopOverAllChromosomes;
	std::string CurrentChr;
	std::string CurrentChrName;

	std::vector<SPLIT_READ> InputReads, Reads, FutureReads;

	int lowerBinBorder;
	int upperBinBorder;
	int startOfRegion;
	int endOfRegion;
	int endRegionPlusBuffer;

	//TODO: explain what are stored in these two vectors.
	std::vector<BreakDancer> All_BD_events_WG, All_BD_events;
};

#endif /* CONTROLSTATE_H_ */
