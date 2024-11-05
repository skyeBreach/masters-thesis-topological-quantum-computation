#pragma once

#ifdef _MSC_VER
	#define _CRT_SECURE_NO_WARNINGS
#endif

#include "shared.hpp"
#include <vector>

struct GeneralMatrixData {
public:
	MatrixXcf matrix;
	MatrixXcf inverseMatrix;
	MatrixXcf daggerMatrix;
	MatrixXcf matrixInverseMatrix;
	MatrixXcf matrixDaggerMatrix;

	GeneralMatrixData(){}

	GeneralMatrixData(MatrixXcf inMatrix) 
	{
		matrix = inMatrix;

		//inverseMatrix = inMatrix.inverse();
		daggerMatrix = inMatrix.adjoint();
		//matrixInverseMatrix = matrix * inverseMatrix;
		matrixDaggerMatrix = matrix * daggerMatrix;
	}
};

class GroupRibbonOperators {
public:
	std::string name;

	bool dualIsPositive;
	bool dirIsPositive;
	bool dualIsOne;

	MatrixXf F_C_E;
	MatrixXf F_C_C;
	MatrixXf F_C_CSq;

	MatrixXf F_CSq_E;
	MatrixXf F_CSq_C;
	MatrixXf F_CSq_CSq;

	MatrixXcf FG;
	Matrix<std::string, Dynamic, Dynamic> FGString;


	MatrixXcf FGSquared;
	Matrix<std::string, Dynamic, Dynamic> FGSquaredString;

	void Print(bool bPrintBaseData, bool bPrintGroupRibbons, bool bPrintAnyonRibbon, bool bPrintAnyonRibbonString, bool bPrintAnyonSq, bool bPrintAnyonSqString);

	GroupRibbonOperators();
	GroupRibbonOperators(bool dualIsPositve, bool dirIsPositive, bool bDualIsSpinOne);

	void GetStringMatrix(MatrixXcf matrix, Matrix<std::string, Dynamic, Dynamic>& output);

	static std::string GetRibbonSpinString(MatrixXf inputMatrix);
	
}; 

class RibbonOperatorSet {
public:
	std::string name;

	GroupRibbonOperators Rho1;
	GroupRibbonOperators Rho2;
};

class Ribbons
{
public:
	static void Main();
	/*---------------------------------------------------------------------------------------------------------------------------------------*/

		inline static MatrixXcf FAPositive;
		inline static MatrixXcf FANegative;

		inline static MatrixXcf FBPositive;
		inline static MatrixXcf FBNegative;


		inline static MatrixXcf FANegPlusFBNeg;

	/*---------------------------------------------------------------------------------------------------------------------------------------*/

		inline static GroupRibbonOperators NegativeDual_NegativeDir;
		inline static GroupRibbonOperators PositiveDual_PositveDir;

	/*---------------------------------------------------------------------------------------------------------------------------------------*/
	
		inline static MatrixXcf FGRhoDirNegativeDualNegative;
		inline static MatrixXcf FGRhoDirPositiveDualPositive;

		inline static RibbonDataString FGRhoDirPositiveDualPositiveData = RibbonDataString("FGRhoDirPositiveDualPositive");
		inline static RibbonDataString FGRhoDirNegativeDualNegativeData = RibbonDataString("FGRhoDirNegativeDualNegative");

	/*---------------------------------------------------------------------------------------------------------------------------------------*/

		inline static MatrixXcf FGRhoDirNegativeDualPositive;
		inline static MatrixXcf FGRhoDirPositiveDualNegative;

		inline static RibbonDataString FGRhoDirNegativeDualPositiveData = RibbonDataString("FGRhoDirNegativeDualPositive");
		inline static RibbonDataString FGRhoDirPositiveDualNegativeData = RibbonDataString("FGRhoDirPositiveDualNegative");

	/*---------------------------------------------------------------------------------------------------------------------------------------*/

		inline static MatrixXcf FGRhoMultiplied;
		inline static MatrixXcf FGRhoMultipliedTwo;
		inline static MatrixXcf FGRhoMultipliedThree;
		inline static MatrixXcf FGRhoMultipliedFour;

		inline static RibbonDataString FGRhoMultipliedData = RibbonDataString("FGRhoMultiplied");
		inline static RibbonDataString FGRhoMultipliedTwoData = RibbonDataString("FGRhoMultipliedTwo");
		inline static RibbonDataString FGRhoMultipliedThreeData = RibbonDataString("FGRhoMultipliedThree");
		inline static RibbonDataString FGRhoMultipliedFourData = RibbonDataString("FGRhoMultipliedFour");

	/*---------------------------------------------------------------------------------------------------------------------------------------*/

		inline static MatrixXcf FGRhoMultipliedSquaredOne;
		inline static MatrixXcf FGRhoMultipliedSquaredTwo;
		inline static MatrixXcf FGRhoMultipliedSquaredThree;

		inline static RibbonDataString FGRhoMultipliedSquaredOneData = RibbonDataString("FGRhoMultipliedSquaredOne");
		inline static RibbonDataString FGRhoMultipliedSquaredTwoData = RibbonDataString("FGRhoMultipliedSquaredTwo");
		inline static RibbonDataString FGRhoMultipliedSquaredThreeData = RibbonDataString("FGRhoMultipliedSquaredThree");

	/*---------------------------------------------------------------------------------------------------------------------------------------*/

		inline static MatrixXcf FGRhoMultipliedCommuteCheck;
		inline static MatrixXcf FGRhoMultipliedCommuteCheckTwo;

		inline static RibbonDataString FGRhoMultipliedCommuteCheckData = RibbonDataString("FGRhoMultipliedCommuteCheck");
		inline static RibbonDataString FGRhoMultipliedCommuteCheckTwoData = RibbonDataString("FGRhoMultipliedCommuteCheckTwo");

	/*---------------------------------------------------------------------------------------------------------------------------------------*/

		inline static MatrixXcf FGRhoMultipliedAntiCommuteCheck;
		inline static MatrixXcf FGRhoMultipliedAntiCommuteCheckTwo;

		inline static RibbonDataString FGRhoMultipliedAntiCommuteCheckTwoData = RibbonDataString("FGRhoMultipliedAntiCommuteCheckTwo");
		inline static RibbonDataString FGRhoMultipliedAntiCommuteCheckData = RibbonDataString("FGRhoMultipliedAntiCommuteCheck");

	/*---------------------------------------------------------------------------------------------------------------------------------------*/

		inline static MatrixXcf rho2rho1Map;
		inline static RibbonDataString rho2rhoInverse = RibbonDataString("rho2rhoInverse");


		inline static MatrixXcf spacetime;
		inline static RibbonDataString spacetimeData = RibbonDataString("spacetime");
	
	/*---------------------------------------------------------------------------------------------------------------------------------------*/
		static std::string GetIndexesSpin(int index);
protected:
	static MatrixXcf InitFG(bool bPositiveDual, bool bPositiveDir, bool bDualIsOne);
	static void GetFGAsString(MatrixXcf matrix, RibbonDataString& matrixData);
};