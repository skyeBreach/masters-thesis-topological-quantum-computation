#pragma once

#define _USE_MATH_DEFINES
#define OMEGA "\u03C9"
#define OMEGABAR "\u03CE"

#include <eigen3/Eigen/Dense>
#include <iostream>
#include <chrono>
#include <complex>
#include <fstream>
#include <eigen3/unsupported/Eigen/MatrixFunctions>
#include <eigen3/unsupported/Eigen/KroneckerProduct> 
#include <map>
#include <fstream>
#include <cmath>


using namespace Eigen;
using namespace std::literals;


struct BraketSet {
public:
	std::string ket;
	std::map<std::string, float> braSet;

};

struct VertexSet {
public:
	MatrixXf VertexOperator;
	MatrixXf VertexOperatorTruncated;
	int firstRow = 0;
	int multiplicity = 0;
};

struct RibbonCellData {
public:
	std::string value;
	std::string position;

	std::string rowString;
	std::string colString;
	RibbonCellData()
	{
		value = "";
		position = "";
		rowString = "";
		colString = "";
	}
	void Print();
};

struct RibbonDataString {
public:
	RibbonDataString(std::string name);

	std::string ribbonName;
	Matrix<std::string, Dynamic, Dynamic> stringMatrix;
	
	int firstUsefulRow = 0;
	int maxUsefulRow = 0;

	int firstUsefulCol = 0;
	int maxUsefulCol = 0;

	std::map<std::string, RibbonCellData> importantLocations;
	std::map<std::string, RibbonCellData> omegas;
	std::map<std::string, RibbonCellData> omegaBars;
	std::map<std::string, RibbonCellData> numbers;

	Eigen::Vector<std::string, 36> diagonalElements;

	std::map<std::string, RibbonCellData> spinMap;

	void Print(bool bPrintMatrix, bool bPrintPositions, bool bPrintDiagonals, bool bPrintSpinMap, bool bPrintSpinString);
	void OutputFiles();
};

class SharedData
{
public:
	static inline std::string spinIntToString[] = { "e","c","c2","t","tc","tc2" };

	inline static Matrix<float, 6, 6> vertexPlusE;
	inline static Matrix<float, 6, 6> vertexPlusC;
	inline static Matrix<float, 6, 6> vertexPlusCSQ;
	inline static Matrix<float, 6, 6> vertexPlusT;
	inline static Matrix<float, 6, 6> vertexPlusTC;
	inline static Matrix<float, 6, 6> vertexPlusTCSq;


	inline static Matrix<float, 6, 6> vertexMinusE;
	inline static Matrix<float, 6, 6> vertexMinusC;
	inline static Matrix<float, 6, 6> vertexMinusCSQ;
	inline static Matrix<float, 6, 6> vertexMinusT;
	inline static Matrix<float, 6, 6> vertexMinusTC;
	inline static Matrix<float, 6, 6> vertexMinusTCSq;

	inline static Matrix<float, 6, 1> eKet;
	inline static Matrix<float, 6, 1> cKet;
	inline static Matrix<float, 6, 1> cSqKet;
	inline static Matrix<float, 6, 1> tKet;
	inline static Matrix<float, 6, 1> tcKet;
	inline static Matrix<float, 6, 1> tcSqKet;

	inline static Matrix<float, 1, 6> eBra;
	inline static Matrix<float, 1, 6> cBra;
	inline static Matrix<float, 1, 6> cSqBra;
	inline static Matrix<float, 1, 6> tBra;
	inline static Matrix<float, 1, 6> tcBra;
	inline static Matrix<float, 1, 6> tcSqBra;

	inline static const std::complex<float> omegaExponent = (std::complex<float>) (M_PI * 2i/ 3.0);
	inline static const std::complex<float> omegaBarExponent = (float)(0-1.0) * omegaExponent;

	inline static const std::complex<float> omega = std::exp(omegaExponent);
	inline static const std::complex<float> omegaBar = std::exp(omegaBarExponent);

	inline static Matrix<std::complex<float>, 6, 6> RMatrix;
	inline static Matrix<std::complex<float>, 36, 36> RMatrixSpinOne;
	inline static Matrix<std::complex<float>, 36, 36> RMatrixSpinTwo;
	inline static Matrix<std::complex<float>, 36, 36> RMatrixSpinBoth;


	static void InitData();
	static void PrintInitData(bool bOmegas, bool bBras, bool bKets, bool bLPlus, bool bLMinus);
};
	

