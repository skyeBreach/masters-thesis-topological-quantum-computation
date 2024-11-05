#include "RibbonOperators.hpp"

IOFormat CleanFmt3(0, DontAlignCols, ", ", "\n", "[", "]");

void Ribbons::Main() //Need to check which way around to do tensors, second spin should be on the left i think
{
	/**
	* Look at the anti commuter and commutator
	* Code in braiding relation and check it against the two Fgs
	* Get the anti commutator and commutators simplified, see if they can be used for anything
	*/
		FAPositive = SharedData::eKet * SharedData::eBra + SharedData::cKet * SharedData::cBra + SharedData::cSqKet * SharedData::cSqBra + SharedData::tKet * SharedData::tBra + SharedData::tcKet * SharedData::tcBra + SharedData::tcSqKet * SharedData::tcSqBra;
		FANegative = SharedData::eKet * SharedData::eBra + SharedData::cSqKet * SharedData::cSqBra + SharedData::cKet * SharedData::cBra + SharedData::tKet * SharedData::tBra + SharedData::tcKet * SharedData::tcBra + SharedData::tcSqKet * SharedData::tcSqBra;
	
		FBPositive = SharedData::eKet * SharedData::eBra + SharedData::cKet * SharedData::cBra + SharedData::cSqKet * SharedData::cSqBra - (SharedData::tKet * SharedData::tBra + SharedData::tcKet * SharedData::tcBra + SharedData::tcSqKet * SharedData::tcSqBra);
		FBNegative = SharedData::eKet * SharedData::eBra + SharedData::cSqKet * SharedData::cSqBra + SharedData::cKet * SharedData::cBra - (SharedData::tKet * SharedData::tBra + SharedData::tcKet * SharedData::tcBra + SharedData::tcSqKet * SharedData::tcSqBra);

		FANegPlusFBNeg = FANegative + FBNegative;

		//std::cout << FAPositive.format(CleanFmt3) << "\n\n";
		//std::cout << FBNegative.format(CleanFmt3) << "\n\n";
		//std::cout << FANegPlusFBNeg.format(CleanFmt3);

	/*---------------------------------------------------------------------------------------------------------------------------------------*/
	// FG orientation 1

		FGRhoDirNegativeDualNegative = InitFG(false, false, false);//Rho 1
		FGRhoDirPositiveDualPositive = InitFG(true, false, true);//Rho 2 this new way fixes it

		GetFGAsString(FGRhoDirNegativeDualNegative, FGRhoDirNegativeDualNegativeData);
		GetFGAsString(FGRhoDirPositiveDualPositive, FGRhoDirPositiveDualPositiveData);

		FGRhoDirNegativeDualNegativeData.OutputFiles();
		FGRhoDirPositiveDualPositiveData.OutputFiles();

		//FGRhoDirPositiveDualPositiveData.Print(true, false, false, false, false);
		//FGRhoDirNegativeDualNegativeData.Print(true, false, false, false, false);
	
	/*---------------------------------------------------------------------------------------------------------------------------------------*/
	// FG orientation 2

		FGRhoDirNegativeDualPositive = InitFG(true, false, false);//Rho 1
		FGRhoDirPositiveDualNegative = InitFG(false, true, true);//Rho 2

		GetFGAsString(FGRhoDirNegativeDualNegative, FGRhoDirNegativeDualPositiveData);
		GetFGAsString(FGRhoDirPositiveDualNegative, FGRhoDirPositiveDualNegativeData);

		//FGRhoDirNegativeDualPositiveData.OutputFiles();
		//FGRhoDirPositiveDualNegativeData.OutputFiles();

		//FGRhoDirNegativeDualPositiveData.Print(true, false, false, false, false);
		//FGRhoDirPositiveDualNegativeData.Print(true, false, false, false, false);

	/*---------------------------------------------------------------------------------------------------------------------------------------*/
	// FG multiplied

		FGRhoMultiplied = FGRhoDirNegativeDualNegative * FGRhoDirPositiveDualPositive;
		FGRhoMultipliedTwo = FGRhoDirPositiveDualPositive * FGRhoDirNegativeDualNegative;
		FGRhoMultipliedThree = FGRhoDirNegativeDualPositive * FGRhoDirPositiveDualNegative;
		FGRhoMultipliedFour = FGRhoDirPositiveDualNegative * FGRhoDirNegativeDualPositive;

		GetFGAsString(FGRhoMultiplied, FGRhoMultipliedData);
		GetFGAsString(FGRhoMultipliedTwo, FGRhoMultipliedTwoData);
		GetFGAsString(FGRhoMultipliedThree, FGRhoMultipliedThreeData);
		GetFGAsString(FGRhoMultipliedFour, FGRhoMultipliedFourData);

		//FGRhoMultipliedData.OutputFiles();
		//FGRhoMultipliedTwoData.OutputFiles();
		//FGRhoMultipliedThreeData.OutputFiles();
		//FGRhoMultipliedFourData.OutputFiles();

		//FGRhoMultipliedData.Print(true, false, false, false, false);
		//FGRhoMultipliedTwoData.Print(true, false, false, false, false);
		//FGRhoMultipliedThreeData.Print(true, false, false, false, false);
		//FGRhoMultipliedFourData.Print(true, false, false, false, false);

	/*---------------------------------------------------------------------------------------------------------------------------------------*/
	// Squared Data

		FGRhoMultipliedSquaredOne = (FGRhoDirNegativeDualNegative * FGRhoDirNegativeDualNegative);
		FGRhoMultipliedSquaredTwo = FGRhoDirPositiveDualPositive * FGRhoDirPositiveDualPositive;
		FGRhoMultipliedSquaredThree = (FGRhoDirNegativeDualPositive * FGRhoDirNegativeDualPositive);
		

		GetFGAsString(FGRhoMultipliedSquaredOne, FGRhoMultipliedSquaredOneData);
		GetFGAsString(FGRhoMultipliedSquaredTwo, FGRhoMultipliedSquaredTwoData);
		GetFGAsString(FGRhoMultipliedSquaredThree, FGRhoMultipliedSquaredThreeData);

		FGRhoMultipliedSquaredOneData.OutputFiles();
		FGRhoMultipliedSquaredTwoData.OutputFiles();
		//FGRhoMultipliedSquaredThreeData.OutputFiles();
		//std::cout << "squared:\n" << (FGRhoMultipliedSquaredOne)(14,14) << "\n\n";
	
		FGRhoMultipliedSquaredOneData.Print(true, false, false, false, false);
		FGRhoMultipliedSquaredTwoData.Print(true, false, false, false, false);
		//FGRhoMultipliedSquaredThreeData.Print(true, false, false, false, false);	

	/*---------------------------------------------------------------------------------------------------------------------------------------*/
	// Commuter 

		FGRhoMultipliedCommuteCheck = FGRhoDirNegativeDualNegative*FGRhoDirPositiveDualPositive - FGRhoDirPositiveDualPositive*FGRhoDirNegativeDualNegative;
		FGRhoMultipliedCommuteCheckTwo = FGRhoMultipliedThree - FGRhoMultipliedFour;

		GetFGAsString(FGRhoMultipliedCommuteCheck, FGRhoMultipliedCommuteCheckData);
		GetFGAsString(FGRhoMultipliedCommuteCheckTwo, FGRhoMultipliedCommuteCheckTwoData);

		FGRhoMultipliedCommuteCheckData.OutputFiles();
	

		//FGRhoMultipliedCommuteCheckData.Print(true, false, false, false, false);
		//FGRhoMultipliedCommuteCheckTwoData.Print(true, false, false, false, false);

	/*---------------------------------------------------------------------------------------------------------------------------------------*/
	// Anti Commuter

		FGRhoMultipliedAntiCommuteCheck =  FGRhoDirNegativeDualNegative*FGRhoDirPositiveDualPositive + FGRhoDirPositiveDualPositive*FGRhoDirNegativeDualNegative;
		FGRhoMultipliedAntiCommuteCheckTwo = FGRhoMultipliedThree + FGRhoMultipliedFour;

		GetFGAsString(FGRhoMultipliedAntiCommuteCheck, FGRhoMultipliedAntiCommuteCheckData);
		GetFGAsString(FGRhoMultipliedAntiCommuteCheckTwo, FGRhoMultipliedAntiCommuteCheckTwoData);

		FGRhoMultipliedAntiCommuteCheckData.OutputFiles();
	
		//FGRhoMultipliedAntiCommuteCheckData.Print(true, false, false, false, false);
		//FGRhoMultipliedAntiCommuteCheckTwoData.Print(true, false, false, false, false);

	/*---------------------------------------------------------------------------------------------------------------------------------------*/
		
		NegativeDual_NegativeDir = GroupRibbonOperators(false, false, false);
		PositiveDual_PositveDir = GroupRibbonOperators(true, false, true);

		//NegativeDual_NegativeDir.Print(true, true, false, true, false, true);
		//PositiveDual_PositveDir.Print(false, false, false, false, false, false);
		
		std::cout << "F_C_E_1*F_C_E_2:	\n" << ( PositiveDual_PositveDir.F_C_E).format(CleanFmt3) << "\n\n";
		//std::cout << "F_C_E_1*F_C_E_2 spins:\n" << GroupRibbonOperators::GetRibbonSpinString(NegativeDual_NegativeDir.F_C_E * PositiveDual_PositveDir.F_C_E) << "\n\n";
	
		//std::cout << "F_C_E_2*F_C_E_1:	\n" << (PositiveDual_PositveDir.F_C_E  * NegativeDual_NegativeDir.F_C_E).format(CleanFmt3) << "\n\n";
		//std::cout << "F_C_E_2*F_C_E_1 spins:\n" << GroupRibbonOperators::GetRibbonSpinString(PositiveDual_PositveDir.F_C_E  * NegativeDual_NegativeDir.F_C_E) << "\n\n";
	
		//std::cout << "------------------------------------------------------------------------------------------------\n\n";
	
		//std::cout << "F_C_C_1*F_C_C_2:	\n" << (NegativeDual_NegativeDir.F_C_C * PositiveDual_PositveDir.F_C_C).format(CleanFmt3) << "\n\n";
		//std::cout << "F_C_C_2*F_C_C_1:	\n" << (PositiveDual_PositveDir.F_C_C  * NegativeDual_NegativeDir.F_C_C).format(CleanFmt3) << "\n\n";

		
		//std::cout << "F_C_C_2*F_C_C_1 spins:\n" << GroupRibbonOperators::GetRibbonSpinString(PositiveDual_PositveDir.F_C_C  * NegativeDual_NegativeDir.F_C_C) << "\n\n";
	
		//std::cout << "------------------------------------------------------------------------------------------------\n\n";
		/*
		std::cout << (
				NegativeDual_NegativeDir.F_CSq_E * PositiveDual_PositveDir.F_CSq_E
			+	NegativeDual_NegativeDir.F_CSq_E * PositiveDual_PositveDir.F_CSq_C
			+	NegativeDual_NegativeDir.F_CSq_E * PositiveDual_PositveDir.F_CSq_CSq

			+	NegativeDual_NegativeDir.F_C_E * PositiveDual_PositveDir.F_CSq_E
			+	NegativeDual_NegativeDir.F_C_E * PositiveDual_PositveDir.F_CSq_C
			+	NegativeDual_NegativeDir.F_C_E * PositiveDual_PositveDir.F_CSq_CSq
			).format(CleanFmt3) << "\n\n";
			*/
		//std::cout << "F_CSq_CSq _1*F_CSq_CSq _2 spins:\n" << GroupRibbonOperators::GetRibbonSpinString(NegativeDual_NegativeDir.F_CSq_C * PositiveDual_PositveDir.F_CSq_E) << "\n\n";
		// spins seem to be the wrong way round so may just want to start ommitting the spins in the paper
		
	//std::cout << "F_C_CSq_2*F_C_CSq_1:	\n" << (PositiveDual_PositveDir.F_C_CSq  * NegativeDual_NegativeDir.F_C_E).format(CleanFmt3) << "\n\n";

		//std::cout << "F_C_CSq_1*F_C_CSq_2 spins:\n" << GroupRibbonOperators::GetRibbonSpinString(NegativeDual_NegativeDir.F_C_CSq * PositiveDual_PositveDir.F_C_CSq) << "\n\n";
		//std::cout << "F_C_CSq_2*F_C_CSq_1 spins:\n" << GroupRibbonOperators::GetRibbonSpinString(PositiveDual_PositveDir.F_C_CSq  * NegativeDual_NegativeDir.F_C_CSq) << "\n\n";

	/*---------------------------------------------------------------------------------------------------------------------------------------*/
	
		//rho2rho1Map = FGRhoMultipliedTwo.inverse(); // FGRhoMultipliedTwo
		//Eigen::FullPivLU<MatrixXcf> lu(FGRhoDirPositiveDualPositive);
	
		//std::cout << "matrix:\n" << FGRhoDirPositiveDualPositive.format(CleanFmt3) << "\n\n";
		//std::cout << "LU decomposition matrix:\n" << lu.matrixLU().format(CleanFmt3) << "\n\n";
		//Eigen::FullPivHouseholderQR<Eigen::MatrixXcf> qr(FGRhoMultipliedTwo);//FGRhoMultipliedTwo
		//MatrixXcf inv = FGRhoMultipliedTwo.inverse();//completeOrthogonalDecomposition().pseudoInverse()
		//qr.solve( MatrixXcf::Identity(36, 36));
		//MatrixXcf Q,R;
		//Q = qr.matrixQ();
		//R = qr.matrixQR().triangularView<Upper>();
	
		//std::cout << "Q:\n" << Q.transpose() << "\n\n";
		//std::cout << "R:\n" << R.inverse() << "\n\n";
		//rho2rhoInverse.Print(true, false, false, false, false);
		//rho2rhoInverse.OutputFiles();
	/*---------------------------------------------------------------------------------------------------------------------------------------*/

	MatrixXcf oneTwoTrunc;
	MatrixXcf twoOneTrunc;

	oneTwoTrunc.resize(9,9);
	twoOneTrunc.resize(9,9);
	
	oneTwoTrunc<<	0, 0, 0,									0, SharedData::omega	, SharedData::omegaBar	,				0, SharedData::omegaBar	, SharedData::omega,
					0, 0, 0,									1, 0		, SharedData::omegaBar	,				1, 0			, SharedData::omega,
					0, 0, 0,									1, SharedData::omega  , 0			,				1, SharedData::omegaBar	, 0,
	
					0			, SharedData::omega	, SharedData::omegaBar,		0, 0, 0,								0			, 1		, 1, 
					SharedData::omega		, 0		, 1,				0, 0, 0,								SharedData::omega		, 0		, SharedData::omega,
					SharedData::omegaBar	, 1		, 0,				0, 0, 0,								SharedData::omegaBar	, SharedData::omegaBar, 0,
	
					0			, SharedData::omegaBar, SharedData::omega,			0				, 1	, 1,			0, 0, 0,
					SharedData::omegaBar	, 0		, 1,				SharedData::omegaBar		, 0	, SharedData::omegaBar,	0, 0, 0,
					SharedData::omega		, 1		, 0,				SharedData::omega			,SharedData::omega, 0,			0, 0, 0;

	twoOneTrunc<<	0, 0, 0,									0		, SharedData::omegaBar, SharedData::omega,			0		, SharedData::omega	, SharedData::omegaBar,
					0, 0, 0,									SharedData::omegaBar, 0		, 1,				SharedData::omega	, 0		, 1,
					0, 0, 0,									SharedData::omega	, 1		, 0,				SharedData::omegaBar, 1		, 0,
	
					0		, 1		, 1,						0, 0, 0,								0	, SharedData::omega, SharedData::omegaBar, 
					SharedData::omegaBar, 0		, SharedData::omegaBar,				0, 0, 0,								1	, 0	 , SharedData::omegaBar,
					SharedData::omega	, SharedData::omega	, 0 ,					0, 0, 0,								1	, SharedData::omega, 0,
	
					0		, 1		, 1,					0	, SharedData::omegaBar, SharedData::omega,				0, 0, 0,
					SharedData::omega	, 0		, SharedData::omega,				1	, 0		, SharedData::omega,				0, 0, 0,
					SharedData::omegaBar, SharedData::omegaBar,0 ,					1	,SharedData::omegaBar , 0,					0, 0, 0;

	MatrixXcf oneTwoTruncInverse = oneTwoTrunc.inverse();
	MatrixXcf twoOneTruncInverse = twoOneTrunc.inverse();


	//std::cout << "matrix inverse 1:\n" << ( oneTwoTruncInverse).format(CleanFmt3) << "\n\n";
	//std::cout << "matrix inverse 2:\n" << ( twoOneTruncInverse).format(CleanFmt3) << "\n\n";
	MatrixXcf oneTwoTruncIdent = oneTwoTruncInverse * oneTwoTrunc;
	MatrixXcf twoOneTruncIdent = twoOneTruncInverse * twoOneTrunc;


	spacetime = oneTwoTrunc* twoOneTruncInverse ;//oneTwoTrunc* twoOneTrunc * twoOneTruncInverse * twoOneTruncInverse;
	
	float tempReal = 0.0f;
	float tempImag = 0.0f;

	float zeroLimit = 0.0001f;
	
	for (int i = 0; i < 9; i++) // removes all small vids
	{
		for (int j = 0; j < 9; j++)
		{
			if (oneTwoTruncIdent(i,j).real() < zeroLimit)
				tempReal = 0.0f;
			else
				tempReal = oneTwoTruncIdent(i,j).real();

			if (oneTwoTruncIdent(i,j).imag() < zeroLimit)
				tempImag = 0.0f;
			else
				tempImag = oneTwoTruncIdent(i,j).imag();
			oneTwoTruncIdent(i,j) = std::complex<float>(tempReal, tempImag);

			tempReal = 0.0f;
			tempImag = 0.0f;
			
			if (twoOneTruncIdent(i,j).real() < zeroLimit)
				tempReal = 0.0f;
			else
				tempReal = twoOneTruncIdent(i,j).real();

			if (twoOneTruncIdent(i,j).imag() < zeroLimit)
				tempImag = 0.0f;
			else
				tempImag = twoOneTruncIdent(i,j).imag();
			twoOneTruncIdent(i,j) = std::complex<float>(tempReal, tempImag);

			tempReal = 0.0f;
			tempImag = 0.0f;

			if (spacetime(i,j).real() < zeroLimit)
				tempReal = 0.0f;
			else
				tempReal = spacetime(i,j).real();

			if (spacetime(i,j).imag() < zeroLimit)
				tempImag = 0.0f;
			else
				tempImag = spacetime(i,j).imag();
			spacetime(i,j) = std::complex<float>(tempReal, tempImag);
		}
	}
	
	//std::cout << "ident 1:\n" << (oneTwoTruncIdent).format(CleanFmt3) << "\n\n";
	//std::cout << "ident 2:\n" << (twoOneTruncIdent).format(CleanFmt3) << "\n\n";
	
	//std::cout << "Omega:\n" << SharedData::omega << "\n\n";
	//std::cout << "Spacetime relation unitary: " << spacetime.isUnitary() << "\n\n";
	//std::cout << "Spacetime relation:\n" << (spacetime).format(CleanFmt3) << "\n\n";
	GetFGAsString(spacetime, spacetimeData);
	
	//spacetimeData.Print(true, false, false, false, false);

	MatrixXcf RhoOneTrunc;
	MatrixXcf RhoTwoTrunc;
	
	RhoOneTrunc.resize(18,18);
	RhoTwoTrunc.resize(18,18);

	RhoOneTrunc <<
	0, 0, 0, 						1, 0, 0,						1, 0, 0,						0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 						0, SharedData::omega, 0,		0, SharedData::omegaBar, 0,		0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 						0, 0, SharedData::omegaBar,		0, 0, SharedData::omega,		0, 0, 0, 0, 0, 0, 0, 0, 0,

	1, 0, 0, 						0, 0, 0,  						1, 0, 0,						0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, SharedData::omegaBar, 0,		0, 0, 0,  						0, SharedData::omega, 0,		0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, SharedData::omega,		0, 0, 0,  						0, 0, SharedData::omegaBar,		0, 0, 0, 0, 0, 0, 0, 0, 0,

	1, 0, 0, 						1, 0, 0,  						0, 0, 0, 						0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, SharedData::omega, 0,		0, SharedData::omegaBar, 0,		0, 0, 0, 						0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, SharedData::omegaBar,		0, 0, SharedData::omega,		0, 0, 0, 						0, 0, 0, 0, 0, 0, 0, 0, 0,

	0, 0, 0, 						0, 0, 0,  						0, 0, 0, 						1, 0, 0,						1, 0, 0,						0, 0, 0,
	0, 0, 0, 						0, 0, 0,  						0, 0, 0, 						0, SharedData::omegaBar, 0,		0, SharedData::omega, 0,		0, 0, 0,
	0, 0, 0, 						0, 0, 0,  						0, 0, 0, 						0, 0, SharedData::omega,		0, 0, SharedData::omegaBar,		0, 0, 0,

	0, 0, 0, 						0, 0, 0,  						0, 0, 0, 						1, 0, 0,						0, 0, 0, 						1, 0, 0, 
	0, 0, 0, 						0, 0, 0,  						0, 0, 0, 						0, SharedData::omega, 0,		0, 0, 0, 						0, SharedData::omegaBar, 0, 
	0, 0, 0, 						0, 0, 0,  						0, 0, 0, 						0, 0, SharedData::omegaBar,		0, 0, 0, 						0, 0, SharedData::omega, 

	0, 0, 0, 						0, 0, 0,  						0, 0, 0, 						1, 0, 0,						0, 0, 0, 						1, 0, 0,
	0, 0, 0, 						0, 0, 0,  						0, 0, 0, 						0, SharedData::omegaBar, 0,		0, 0, 0, 						0, SharedData::omega, 0,
	0, 0, 0, 						0, 0, 0,  						0, 0, 0, 						0, 0, SharedData::omega,		0, 0, 0, 						0, 0, SharedData::omegaBar;

	RhoTwoTrunc <<
		0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, SharedData::omegaBar, SharedData::omega, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, SharedData::omega, 0, SharedData::omegaBar, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, SharedData::omegaBar, SharedData::omega, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, SharedData::omegaBar, SharedData::omega, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, SharedData::omega, 0, SharedData::omegaBar, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, SharedData::omegaBar, SharedData::omega, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, SharedData::omega, SharedData::omegaBar, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, SharedData::omegaBar, 0, SharedData::omega, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, SharedData::omega, SharedData::omegaBar, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, SharedData::omega, SharedData::omegaBar,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, SharedData::omegaBar, 0, SharedData::omega,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, SharedData::omega, SharedData::omegaBar, 0;

	//std::cout << "RhoOneTrunc:\n" << (RhoTwoTrunc*RhoOneTrunc).format(CleanFmt3) << "\n\n";
}

	MatrixXcf Ribbons::InitFG(bool bPositiveDual, bool bPositiveDir, bool bDualIsOne)
	{
		MatrixXcf returnData;

		MatrixXcf leftPartFG;
		MatrixXcf rightPartFG;

		MatrixXf LDualC;
		MatrixXf LDualCSq;

		MatrixXf LDualCSpin;
		MatrixXf LDualCSqSpin;
		
		MatrixXcf PDirE = SharedData::eKet * SharedData::eBra;
		MatrixXcf PDirC;
		MatrixXcf PDirCSq;

		
		MatrixXcf PFullLeft;
		MatrixXcf PFullRight;

		MatrixXcf PFullLeftSpin;
		MatrixXcf PFullRightSpin;

		MatrixXf Ident = MatrixXf::Identity(6, 6);
		MatrixXcf IdentC = MatrixXcf::Identity(6, 6);
		
		if (bPositiveDual) 
		{
			LDualC = SharedData::vertexPlusC;
			LDualCSq = SharedData::vertexPlusCSQ;
		} 
		else// idk which way to put these
		{
			LDualC = SharedData::vertexMinusC;
			LDualCSq = SharedData::vertexMinusCSQ;

			//LDualC = SharedData::vertexMinusCSQ;
			//LDualCSq = SharedData::vertexMinusC;
		}
		
		if (bPositiveDir)
		{
			PDirC = SharedData::cKet * SharedData::cBra;
			PDirCSq = SharedData::cSqKet * SharedData::cSqBra;
		}
		else
		{
			PDirC = SharedData::cSqKet * SharedData::cSqBra;
			PDirCSq = SharedData::cKet * SharedData::cBra;
		}
		
		PFullLeft = PDirE + (SharedData::omega * PDirC) + (SharedData::omegaBar * PDirCSq);
		PFullRight = PDirE + (SharedData::omegaBar * PDirC) + (SharedData::omega * PDirCSq);

		if (bDualIsOne)
		{
			LDualCSpin = KroneckerProduct(LDualC, Ident);
			LDualCSqSpin = KroneckerProduct(LDualCSq, Ident);

			PFullLeftSpin = KroneckerProduct(IdentC, PFullLeft);
			PFullRightSpin = KroneckerProduct(IdentC, PFullRight);
		}
		else
		{
			LDualCSpin = KroneckerProduct(Ident, LDualC);
			LDualCSqSpin = KroneckerProduct(Ident, LDualCSq);

			PFullLeftSpin = KroneckerProduct(PFullLeft, IdentC);
			PFullRightSpin = KroneckerProduct(PFullRight, IdentC);
		}

		leftPartFG = LDualCSpin * PFullLeftSpin;
		rightPartFG = LDualCSqSpin * PFullRightSpin;

		returnData = leftPartFG + rightPartFG;
		return returnData;
	}

	void Ribbons::GetFGAsString(MatrixXcf matrix, RibbonDataString& matrixData)
	{
		int i = 0;
		int j;
	
		matrixData.stringMatrix.resize(matrix.rows(),matrix.cols());
	
		int maxUsefulCol = 0;
		int maxUsefulRow = 0;

		int modOmega;
		std::string modOmegaString;
		float omegaImag = SharedData::omega.imag();

		bool bDataAssigned = false;

		std::complex<float> tempVar;
		RibbonCellData tempData;
		while (i < matrix.rows())
		{
			j = 0;
			while (j < matrix.cols())
			{
				tempVar = matrix(i, j);

				if (tempVar.real() != 0.0 && tempVar.imag() != 0.0)
				{
					tempData.position = std::to_string(i) + "," + std::to_string(j);
					
					modOmega = abs(tempVar.imag()) / omegaImag;
					if (modOmega == 1) 
					{
						modOmegaString = "";
					}
					else
					{
						modOmegaString = std::to_string(omegaImag);
					}

					if (modOmegaString == "0")
					{
						modOmegaString = "";
					}
					
					if (tempVar.imag() > 0)//omega
					{
						if (modOmegaString != "0")
						{
							matrixData.stringMatrix(i, j) = modOmegaString + "\\omega";
							tempData.value = modOmegaString + "\\omega";
						}
						else
						{
							matrixData.stringMatrix(i, j) = "0";
							tempData.value = "0";
						}
							
						matrixData.omegas[tempData.position] = tempData;
						
					}
					else //omega bar
					{
						if (modOmegaString != "0")
						{
							matrixData.stringMatrix(i, j) = modOmegaString + "\\bar{\\omega}";
							tempData.value = modOmegaString + "\\bar{\\omega}";
						}
						else
						{
							matrixData.stringMatrix(i, j) = "0";
							tempData.value = "0";
						}
						matrixData.omegaBars[tempData.position] = tempData;
					}
					bDataAssigned = true;
				}
				else if (tempVar.real() != 0.0)
				{
					matrixData.stringMatrix(i, j) = std::to_string(tempVar.real());//std::to_string((int)round(tempVar.real()));

					tempData.position = std::to_string(i) + "," + std::to_string(j);
					tempData.value = std::to_string((int)round(tempVar.real()));
					matrixData.numbers[tempData.position] = tempData;
					bDataAssigned = true;
				}
				else if (tempVar.imag() != 0.0)
				{
					tempData.position = std::to_string(i) + "," + std::to_string(j);
					if (std::to_string((int)round(tempVar.imag())) != "0")
					{
						matrixData.stringMatrix(i, j) = std::to_string(tempVar.imag()) + "i";// std::to_string((int)round(tempVar.imag())) + "i";
						tempData.value = std::to_string((int)round(tempVar.imag())) + "i";
					}
					else
					{
						matrixData.stringMatrix(i, j) = "0";
						tempData.value = "0";
					}
					matrixData.numbers[tempData.position] = tempData;
					bDataAssigned = true;
				}
				else
				{
					matrixData.stringMatrix(i, j) = "0";
				}

				if (bDataAssigned && j > maxUsefulCol)
				{
					maxUsefulCol = j;
				}
				if (bDataAssigned && i > maxUsefulRow)
				{
					maxUsefulRow = i;
				}

				j++;

				bDataAssigned = false;
			}
			i++;
		}

		i = 0;
		while (i < matrixData.stringMatrix.rows())
		{
			matrixData.diagonalElements(i) = matrixData.stringMatrix(i, i);
			i++;
		}

		matrixData.maxUsefulCol = maxUsefulCol;
		matrixData.maxUsefulRow = maxUsefulRow;

		
		i = 0;
		int rangeI = 0;
		int rangeJ = 0;

		RibbonCellData spinTempData;
		while (i < matrixData.stringMatrix.rows())
		{
			j = 0;
			while (j < matrixData.stringMatrix.cols())
			{
				if (matrixData.stringMatrix(i, j) != "0")
				{
					spinTempData.value = matrixData.stringMatrix(i, j);
					spinTempData.position = std::to_string(i) +","+std::to_string(j);
					
					std::string rowSpin = GetIndexesSpin(i);
					std::string colSpin = GetIndexesSpin(j);

					spinTempData.rowString = "|" + rowSpin + ">";
					spinTempData.colString = "<" + colSpin + "|";

					matrixData.spinMap["|" + rowSpin + ">" + "<" + colSpin + "|"] = spinTempData;
				}
				j++;
			}
			i++;
		}/**/
	}

	std::string Ribbons::GetIndexesSpin(int index) // two spin state system
	{
		std::string spin1;
		std::string spin2;

		int i = 0;
		int range = 0;
		while (i < 6)
		{
			if (6 * i <= index && index < (6 * i) + 6)
			{
				range = i;
				break;
			}
			i++;
		}

		switch (range)
		{
		case 0:
			spin2 = "e";
			
			break;
		case 1:
			spin2 = "c";
			break;
		case 2:
			spin2 = "c^2";
			break;
		case 3:
			spin2 = "t";
			break;
		case 4:
			spin2 = "tc";
			break;
		case 5:
			spin2 = "tc^2";
			break;
		}

		int reducedRange = index - ((range) * 6);
		switch (reducedRange)
		{
		case 0:
			spin1 = "e";
			break;
		case 1:
			spin1 = "c";
			break;
		case 2:
			spin1 = "c^2";
			break;
		case 3:
			spin1 = "t";
			break;
		case 4:
			spin1 = "tc";
			break;
		case 5:
			spin1 = "tc^2";
			break;
		}

		return spin2 + "," + spin1;
	}

	GroupRibbonOperators::GroupRibbonOperators()
	{
	}

	GroupRibbonOperators::GroupRibbonOperators(bool bDualIsPositve, bool bDirIsPositive, bool bDualIsSpinOne)
	{
		dualIsPositive = bDualIsPositve;
		dirIsPositive = bDirIsPositive;
		dualIsOne = bDualIsSpinOne;

		MatrixXf Ident = MatrixXf::Identity(6, 6);
		MatrixXcf IdentC = MatrixXcf::Identity(6, 6);

		MatrixXf LC;
		MatrixXf LCSq;

		MatrixXf LCSpin;
		MatrixXf LCSqSpin;

		MatrixXf PE;
		MatrixXf PC;
		MatrixXf PCSq;

		MatrixXf PESpin;
		MatrixXf PCSpin;
		MatrixXf PCSqSpin;

		if (bDualIsPositve)
		{
			LC = SharedData::vertexPlusC;
			LCSq = SharedData::vertexPlusCSQ;
		}
		else
		{
			LC = SharedData::vertexMinusC;
			LCSq = SharedData::vertexMinusCSQ;
		}

		PE = SharedData::eKet*SharedData::eBra;
		if (bDirIsPositive)
		{
			PC = SharedData::cKet * SharedData::cBra;
			PCSq = SharedData::cSqKet * SharedData::cSqBra;
		}
		else
		{
			PC = SharedData::cSqKet * SharedData::cSqBra;
			PCSq = SharedData::cKet * SharedData::cBra;
		}

		if (bDualIsSpinOne)
		{
			LCSpin		= KroneckerProduct(LC, Ident);
			LCSqSpin	= KroneckerProduct(LCSq, Ident);

			PESpin		= KroneckerProduct(Ident, PE);
			PCSpin		= KroneckerProduct(Ident, PC);
			PCSqSpin	= KroneckerProduct(Ident, PCSq);
		}
		else 
		{
			LCSpin		= KroneckerProduct(Ident, LC);
			LCSqSpin	= KroneckerProduct(Ident, LCSq);

			PESpin		= KroneckerProduct(PE, Ident);
			PCSpin		= KroneckerProduct(PC, Ident);
			PCSqSpin	= KroneckerProduct(PCSq, Ident);
		}

		F_C_E		= LCSpin * PESpin;
		F_C_C		= LCSpin * PCSpin;
		F_C_CSq		= LCSpin * PCSqSpin;

		F_CSq_E		= LCSqSpin * PESpin;
		F_CSq_C		= LCSqSpin * PCSpin;
		F_CSq_CSq	= LCSqSpin * PCSqSpin;

		FG = F_C_E + F_CSq_E + SharedData::omega*(F_C_C + F_CSq_CSq) + SharedData::omegaBar * (F_C_CSq + F_CSq_C);
		GetStringMatrix(FG, FGString);
		
		FGSquared = FG * FG;
		GetStringMatrix(FGSquared, FGSquaredString);
	}

	void GroupRibbonOperators::GetStringMatrix(MatrixXcf matrix, Matrix<std::string, Dynamic, Dynamic> &output)
	{
		//std::cout << "size:" << matrix.rows() << ","<< matrix.cols() <<  "\n";
		output.resize(matrix.rows(),matrix.cols());
		int i = 0;
		int j;

		int modOmega;
		std::string modOmegaString;
		float omegaImag = SharedData::omega.imag();

		bool bDataAssigned = false;

		std::complex<float> tempVar;

		while (i < matrix.rows())
		{
			j = 0;
			while (j < matrix.cols())
			{
				tempVar = matrix(i, j);

				if (tempVar.real() != 0.0 && tempVar.imag() != 0.0)
				{
					modOmega = round(abs(tempVar.imag()) / omegaImag);
					if (modOmega == 1)
					{
						modOmegaString = "";
					}
					else
					{
						modOmegaString = std::to_string(omegaImag);
					}

					if (modOmegaString == "0")
					{
						modOmegaString = "";
					}
					
					if (tempVar.imag() > 0)//omega
					{
						output(i, j) = modOmegaString + "A";
					}
					else //omega bar
					{
						output(i, j) = modOmegaString + "B";
					}
				}
				else if (tempVar.real() != 0.0)
				{
					output(i, j) = std::to_string((int)round(tempVar.real()));
				}
				else if (tempVar.imag() != 0.0)
				{
					output(i, j) = std::to_string((int)round(tempVar.imag())) + "i";
				}
				else
				{
					output(i, j) = "0";
				}
				j++;
			}
			i++;
		}
	}

	std::string GroupRibbonOperators::GetRibbonSpinString(MatrixXf inputMatrix)
{
	std::string returnData = "";
	int i = 0;
	int j = 0;
	int rangeI = 0;
	int rangeJ = 0;

	std::string tempSpinString = "";
	
	while (i < inputMatrix.rows())
	{
		j = 0;
		while (j < inputMatrix.cols())
		{
			if (inputMatrix(i, j) != 0)
			{
				std::string rowSpin = Ribbons::GetIndexesSpin(i);
				std::string colSpin = Ribbons::GetIndexesSpin(j);

				tempSpinString = "|" + rowSpin + "><"+ colSpin + "|";

				returnData += tempSpinString + "\n";
			}
			j++;
		}
		i++;
	}/**/
	
	return returnData;
}

	void GroupRibbonOperators::Print(bool bPrintBaseData, bool bPrintGroupRibbons, bool bPrintAnyonRibbon, bool bPrintAnyonRibbonString, bool bPrintAnyonSq, bool bPrintAnyonSqString )
	{
		std::cout << "\n\n" << name;


		if (bPrintBaseData)
		{
			std::cout << "\n\n--------------------------------------------------------------\nBase Data\n\n";
			std::cout << "Dual is "; if (dualIsPositive) std::cout << "Positive" << "\n"; else std::cout << "Negative" << "\n";
			std::cout << "Direct is "; if (dirIsPositive) std::cout << "Positive" << "\n"; else std::cout << "Negative" << "\n";
			std::cout << "Dual Spin is "; if (dualIsPositive) std::cout << "One" << "\n"; else std::cout << "Two" << "\n";
			std::cout << "Direct Spin is "; if (!dualIsPositive) std::cout << "One" << "\n"; else std::cout << "Two" << "\n";
		}
		if (bPrintGroupRibbons)
		{
			std::cout << "\n\n--------------------------------------------------------------\nGroup Ribbons\n";
			std::cout << "F_C_E:	\n" << F_C_E.format(CleanFmt3) << "\n\n";
			std::cout << "F_C_C:	\n" << F_C_C.format(CleanFmt3) << "\n\n";
			std::cout << "F_C_CSq:	\n" << F_C_CSq.format(CleanFmt3) << "\n\n\n\n";
			  
			std::cout << "F_CSq_E:	\n" << F_CSq_E.format(CleanFmt3) << "\n\n";
			std::cout << "F_CSq_C:  \n " << F_CSq_C.format(CleanFmt3) << "\n\n";
			std::cout << "F_CSq_CSq:\n" << F_CSq_CSq.format(CleanFmt3) << "\n\n";
		}
		if (bPrintAnyonRibbon)
		{
			std::cout << "\n\n--------------------------------------------------------------\nAnyon Ribbons\n";
			std::cout << "FG: \n" << FG.format(CleanFmt3) << "\n\n";
		}
		if (bPrintAnyonRibbonString)
		{
			std::cout << "\n\n--------------------------------------------------------------\nAnyon Ribbons String\n";
			std::cout << "FGString: \n" << FGString.format(CleanFmt3) << "\n\n";
		}

		if (bPrintAnyonSq)
		{
			std::cout << "\n\n--------------------------------------------------------------\nAnyon Squared\n";
			std::cout << "FG: \n" << FGSquared.format(CleanFmt3) << "\n\n";
		}
		if (bPrintAnyonSqString)
		{
			std::cout << "\n\n--------------------------------------------------------------\nAnyon Squared String\n";
			std::cout << "FGString: \n" << FGSquaredString.format(CleanFmt3) << "\n\n";
		}

		std::cout << "\n\n--------------------------------------------------------------\n";
	}
