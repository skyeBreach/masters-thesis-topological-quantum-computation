#include "shared.hpp"

IOFormat CleanFmt2(4, DontAlignCols, ", ", "\n", "	[", "]");

void SharedData::InitData()
{
	SharedData::eKet	<< 1, 0, 0, 0, 0, 0;
	SharedData::cKet	<< 0, 1, 0, 0, 0, 0;
	SharedData::cSqKet	<< 0, 0, 1, 0, 0, 0;
	SharedData::tKet	<< 0, 0, 0, 1, 0, 0;
	SharedData::tcKet	<< 0, 0, 0, 0, 1, 0;
	SharedData::tcSqKet << 0, 0, 0, 0, 0, 1;

	SharedData::eBra	<< 1, 0, 0, 0, 0, 0;
	SharedData::cBra	<< 0, 1, 0, 0, 0, 0;
	SharedData::cSqBra	<< 0, 0, 1, 0, 0, 0;
	SharedData::tBra	<< 0, 0, 0, 1, 0, 0;
	SharedData::tcBra	<< 0, 0, 0, 0, 1, 0;
	SharedData::tcSqBra << 0, 0, 0, 0, 0, 1;

	// L_e+
	SharedData::vertexPlusE << 1, 0, 0, 0, 0, 0,
		0, 1, 0, 0, 0, 0,
		0, 0, 1, 0, 0, 0,
		0, 0, 0, 1, 0, 0,
		0, 0, 0, 0, 1, 0,
		0, 0, 0, 0, 0, 1;

	// L_c+
	SharedData::vertexPlusC <<	0, 0, 1, 0, 0, 0,
					1, 0, 0, 0, 0, 0,
					0, 1, 0, 0, 0, 0,
					0, 0, 0, 0, 1, 0,
					0, 0, 0, 0, 0, 1,
					0, 0, 0, 1, 0, 0;

	// L_c2+
	SharedData::vertexPlusCSQ <<	0, 1, 0, 0, 0, 0,
						0, 0, 1, 0, 0, 0,
						1, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 1,
						0, 0, 0, 1, 0, 0,
						0, 0, 0, 0, 1, 0;

	// L_t+
	SharedData::vertexPlusT << 0, 0, 0, 1, 0, 0,
		0, 0, 0, 0, 1, 0,
		0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0,
		0, 1, 0, 0, 0, 0,
		0, 0, 1, 0, 0, 0;

	// L_tc+
	SharedData::vertexPlusTC << 0, 0, 0, 0, 1, 0,
		0, 0, 0, 0, 0, 1,
		0, 0, 0, 1, 0, 0,
		0, 0, 1, 0, 0, 0,
		1, 0, 0, 0, 0, 0,
		0, 1, 0, 0, 0, 0;

	// L_tc2+

	SharedData::vertexPlusTCSq << 0, 0, 0, 0, 0, 1,
		0, 0, 0, 1, 0, 0,
		0, 0, 0, 0, 1, 0,
		0, 1, 0, 0, 0, 0,
		0, 0, 1, 0, 0, 0,
		1, 0, 0, 0, 0, 0;


	// L_e-
	SharedData::vertexMinusE << 1, 0, 0, 0, 0, 0,
		0, 1, 0, 0, 0, 0,
		0, 0, 1, 0, 0, 0,
		0, 0, 0, 1, 0, 0,
		0, 0, 0, 0, 1, 0,
		0, 0, 0, 0, 0, 1;

	// L_c-
	SharedData::vertexMinusC << 0, 1, 0, 0, 0, 0,
					0, 0, 1, 0, 0, 0,
					1, 0, 0, 0, 0, 0,
					0, 0, 0, 0, 1, 0,
					0, 0, 0, 0, 0, 1,
					0, 0, 0, 1, 0, 0;

	// L_c2-
	SharedData::vertexMinusCSQ <<	0, 0, 1, 0, 0, 0,
						1, 0, 0, 0, 0, 0,
						0, 1, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 1,
						0, 0, 0, 1, 0, 0,
						0, 0, 0, 0, 1, 0;

	// L_t-
	SharedData::vertexMinusT << 0, 0, 0, 1, 0, 0,
		0, 0, 0, 0, 0, 1,
		0, 0, 0, 0, 1, 0,
		1, 0, 0, 0, 0, 0,
		0, 0, 1, 0, 0, 0,
		0, 1, 0, 0, 0, 0;

	// L_tc-
	SharedData::vertexMinusTC << 0, 0, 0, 0, 1, 0,
		0, 0, 0, 1, 0, 0,
		0, 0, 0, 0, 0, 1,
		0, 1, 0, 0, 0, 0,
		1, 0, 0, 0, 0, 0,
		0, 0, 1, 0, 0, 0;

	// L_tc2-
	SharedData::vertexMinusTCSq << 0, 0, 0, 0, 0, 1,
		0, 0, 0, 0, 1, 0,
		0, 0, 0, 1, 0, 0,
		0, 0, 1, 0, 0, 0,
		0, 1, 0, 0, 0, 0,
		1, 0, 0, 0, 0, 0;


}

void SharedData::PrintInitData(bool bOmegas, bool bBras, bool bKets, bool bLPlus, bool bLMinus)
{
	if (bOmegas)// Omega and Omega Bar
	{
		std::cout << "\n\n--------------------------------------------------------------\nOmega \n";
		std::cout << "\nOmega Exponent\n";
		std::cout << SharedData::omegaExponent;

		std::cout << "\nOmega\n";
		std::cout << SharedData::omega;

		std::cout << "\n\n--------------------------------------------------------------\nOmega Bar\n";
		std::cout << "\nOmega Bar Exponent\n";
		std::cout << SharedData::omegaBarExponent;

		std::cout << "\nOmega Bar\n";
		std::cout << SharedData::omegaBar;
	}
	if (bBras)// Bras
	{
		std::cout << "\n\n--------------------------------------------------------------\nBras \n";
		std::cout << "\n eBra\n";
		std::cout << SharedData::eBra.format(CleanFmt2);

		std::cout << "\n\n cBra\n";
		std::cout << SharedData::cBra.format(CleanFmt2);

		std::cout << "\n\n cSqBra\n";
		std::cout << SharedData::cSqBra.format(CleanFmt2);

		std::cout << "\n\n tBra\n";
		std::cout << SharedData::tBra.format(CleanFmt2);

		std::cout << "\n\n tcBra\n";
		std::cout << SharedData::tcBra.format(CleanFmt2);

		std::cout << "\n\n tcSqBra\n";
		std::cout << SharedData::tcSqBra.format(CleanFmt2);
	}
	if (bKets)// Kets
	{
		std::cout << "\n\n--------------------------------------------------------------\nKets \n";
		std::cout << "\n\n eKet\n";
		std::cout << SharedData::eKet.format(CleanFmt2);

		std::cout << "\n\n cKet\n";
		std::cout << SharedData::cKet.format(CleanFmt2);

		std::cout << "\n\n cSqKet\n";
		std::cout << SharedData::cSqKet.format(CleanFmt2);

		std::cout << "\n\n tKet\n";
		std::cout << SharedData::tKet.format(CleanFmt2);

		std::cout << "\n\n tcKet\n";
		std::cout << SharedData::tcKet.format(CleanFmt2);

		std::cout << "\n\n tcSqKet\n";
		std::cout << SharedData::tcSqKet.format(CleanFmt2);
	}
	if (bLPlus)// L Plus
	{
		std::cout << "\n\n--------------------------------------------------------------\nL Plus \n";
		std::cout << "\n\n L_e Plus\n";
		std::cout << SharedData::vertexPlusE.format(CleanFmt2);

		std::cout << "\n\n L_c Plus\n";
		std::cout << SharedData::vertexPlusC.format(CleanFmt2);

		std::cout << "\n\n L_c2 Plus\n";
		std::cout << SharedData::vertexPlusCSQ.format(CleanFmt2);

		std::cout << "\n\n L_t Plus\n";
		std::cout << SharedData::vertexPlusT.format(CleanFmt2);

		std::cout << "\n\n L_tc Plus\n";
		std::cout << SharedData::vertexPlusTC.format(CleanFmt2);

		std::cout << "\n\n L_tc2 Plus\n";
		std::cout << SharedData::vertexPlusTCSq.format(CleanFmt2);
	}
	if (bLMinus)// L Minus
	{
		std::cout << "\n\n--------------------------------------------------------------\nL Minus \n";
		std::cout << "\n\n L_e Minus\n";
		std::cout << SharedData::vertexMinusE.format(CleanFmt2);

		std::cout << "\n\n L_c Minus\n";
		std::cout << SharedData::vertexMinusC.format(CleanFmt2);

		std::cout << "\n\n L_c2 Minus\n";
		std::cout << SharedData::vertexMinusCSQ.format(CleanFmt2);

		std::cout << "\n\n L_t Minus\n";
		std::cout << SharedData::vertexMinusT.format(CleanFmt2);

		std::cout << "\n\n L_tc Minus\n";
		std::cout << SharedData::vertexMinusTC.format(CleanFmt2);

		std::cout << "\n\n L_tc2 Minus\n";
		std::cout << SharedData::vertexMinusTCSq.format(CleanFmt2);
	}

	std::cout << "\n\n--------------------------------------------------------------\n\n";
}

void RibbonCellData::Print()
{
	std::cout << "Value: " << value << "\n";
	std::cout << "Position: " << position << "\n";
	std::cout << "Row String: " << rowString << "\n";
	std::cout << "Column String: " << colString << "\n";
}

RibbonDataString::RibbonDataString(std::string name)
{
	ribbonName = name;
}

void RibbonDataString::Print(bool bPrintMatrix, bool bPrintPositions, bool bPrintDiagonals, bool bPrintSpinMap, bool bPrintSpinString)
{

	std::cout << "\n\n" << ribbonName;
	//std::cout << "\n\n" << maxUsefulRow;
	//std::cout << "\n" << maxUsefulCol;

	if (bPrintMatrix)
	{
		std::cout << "\n--------------------------------------------------------------\nMatrix \n";
		std::cout << stringMatrix.format(CleanFmt2);
	}
	if (bPrintPositions) 
	{
		std::cout << "\n\n--------------------------------------------------------------\nOmegas \n";
		for (auto& row : omegas)
		{
			std::cout << row.first << ":\n";
			row.second.Print();
			std::cout << "\n\n";
		}

		std::cout << "\n\n--------------------------------------------------------------\nOmega Bars \n";
		for (auto& row : omegaBars)
		{
			std::cout << row.first << ":\n";
			row.second.Print();
			std::cout << "\n\n";
		}

		std::cout << "\n\n--------------------------------------------------------------\nNumbers \n";
		for (auto& row : numbers)
		{
			std::cout << row.first << ":\n";
			row.second.Print();
			std::cout << "\n\n";
		}
	}
	if (bPrintDiagonals)
	{
		std::cout << "\n\n--------------------------------------------------------------\nDiagonal Elements \n";
		for (std::string element : diagonalElements)
		{
			std::cout << element << ", ";
		}
	}
	if (bPrintSpinMap)
	{
		std::cout << "\n\n--------------------------------------------------------------\nSpin Map \n";
		for (auto& row : spinMap)
		{
			std::cout << row.first << ":\n";
			row.second.Print();
			std::cout << "\n\n";
		}
	}
	if (bPrintSpinString)
	{
		std::cout << "\n\n--------------------------------------------------------------\nSpin String \n";
		for (auto& row : spinMap)
		{
			std::cout << row.second.value << "*" << row.first << " +\n";
			//std::cout << "\n\n";
		}
	}
	
	std::cout << "\n\n--------------------------------------------------------------\n";
	
}
IOFormat latexFormat1(0, DontAlignCols, " & ", "\n", "", "\\\\");
void RibbonDataString::OutputFiles()
{
	std::string path = "./data/ribbons/" + ribbonName + "/";

	// truncate the matrix
	
	bool usefullRow = false;
	int lastUsefulCol = 0;
	int lastUsefulRow = 0;
	for ( int i = 0; i < stringMatrix.rows(); i++)
	{
		for ( int j = 0; j < stringMatrix.cols(); j++)
		{
			if (stringMatrix(i,j) != "0")
			{
				usefullRow = true;
				if (j > lastUsefulCol)
				{
					lastUsefulCol = j;
				}
			}
		}
		if (usefullRow)
		{
			usefullRow = false;
			lastUsefulRow = i;
		}
	}
	
	Matrix<std::string, Dynamic, Dynamic> truncatedString;
	int size = 0;
	if (lastUsefulRow > 18)
	{
		size = 36;
	}
	else if  (lastUsefulRow > 9)
	{
		size = 18;
	}
	else 
	{
		size = 9;
	}
	
	truncatedString.resize(size, size);
	
	for ( int i = 0; i < size; i++)
	{
		for ( int j = 0; j < size; j++)
		{
			truncatedString(i,j) = stringMatrix(i,j);
		}
	}
	
	std::ofstream RibbonMatrix(path + "Matrix.txt");// 
		RibbonMatrix << "NOTE: All matrices in file have an ommitted factor\n\n\n";
		RibbonMatrix << "Standard Matrix Format\n\n";
		RibbonMatrix << truncatedString.format(CleanFmt2);
		RibbonMatrix << "\n\nLatex Matrix Format\n\n";
		RibbonMatrix << truncatedString.format(latexFormat1);
		RibbonMatrix.close();
	std::ofstream RibbonSpinMap(path + "SpinMap.txt");
	std::ofstream RibbonSpinString(path + "SpinString.txt");
	std::ofstream RibbonSpinStringLatex(path + "SpinStringLatex.txt");
	int i = 0;
	bool bInitial = true;

	std::string numberString = "";
	std::string omegaString = "";
	std::string omegaBarString = "";
		for (auto &spin: spinMap)
		{
			RibbonSpinMap << spin.first << ":\n";
			RibbonSpinMap << "    " << spin.second.value;
			RibbonSpinMap << "    " << spin.second.position;
			RibbonSpinMap << "    " << spin.second.rowString;
			RibbonSpinMap << "    " << spin.second.colString;
			RibbonSpinMap << "\n\n";

			std::string value;
			

			

			if (spin.second.value == "1")
			{
				value = "";
			} 
			else
			{
				value = spin.second.value;
			}


			RibbonSpinString << value << "*" << spin.first << " +\n";

			std::string row = spin.second.rowString;
			std::string col = spin.second.colString;

			row.erase(0, 1);
			col.erase(0, 1);

			row.pop_back();
			col.pop_back();

			row = "\\ket{" + row + "}";
			col = "\\bra{" + col + "}";
			std::string state = row + col;

			if (bInitial)
			{
				 RibbonSpinStringLatex << "& ";
				 bInitial = false;
			}

			if (value == "A")
			{
				value = "\\omega";
			}
			else if (value == "B")
			{
				value = "\\bar{\\omega}";
			}

			RibbonSpinStringLatex << value << state;

			if (i > 3)
			{
				RibbonSpinStringLatex << "\\nonumber\\\\ \n&+ ";
				i = 0;
			}
			else
			{
				RibbonSpinStringLatex << " +";
			}
			i++;
		}
	RibbonSpinMap.close();
	RibbonSpinString.close();
}

