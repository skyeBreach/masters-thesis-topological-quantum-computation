#pragma once


#ifdef _MSC_VER
	#define _CRT_SECURE_NO_WARNINGS
#endif

#include "shared.hpp"

class Projectors
{
public:
	static void ProjectorsStart();

	
	inline static VertexSet VertexOperatorE;
	inline static VertexSet VertexOperatorC;
	inline static VertexSet VertexOperatorCSq;
	inline static VertexSet VertexOperatorT;
	inline static VertexSet VertexOperatorTC;
	inline static VertexSet VertexOperatorTCSq;


	inline static MatrixXf ProjectorA;
	inline static MatrixXf ProjectorACollapsed;

	inline static MatrixXf ProjectorB;
	inline static MatrixXf ProjectorBCollapsed;

	
	static VertexSet InitVertexOperator(Matrix<float, 6, 6> matrixPlus, Matrix<float, 6, 6> matrixMinus, Matrix<float, 6, 1> gVectorE, Matrix<float, 6, 1> gVectorEMinus);
	static void PrintInitVertexOperators();

	static std::string GetOutSpinStates(int firstRow, bool bOtherStates, bool bLeftRight);//rows
	static std::string GetSpinStatesCols(int col);

	static std::map<std::string, BraketSet> GetMatrixInBraKet(MatrixXf matrix);

	static void PrintToAFile(std::string name, VertexSet operatorStruct);
	static void PrintToPFile(std::string name, MatrixXf projecterFull, MatrixXf projecterCollapsed);

};
