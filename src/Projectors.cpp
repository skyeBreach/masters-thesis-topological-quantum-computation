
#include "Projectors.hpp"

IOFormat CleanFmt(4, 0, ", ", "\n", "	[", "]");

void Projectors::ProjectorsStart()
{
	VertexOperatorE = InitVertexOperator(SharedData::vertexPlusE, SharedData::vertexMinusE, SharedData::eKet, SharedData::eKet); // vector spin is the inversed g
	VertexOperatorC = InitVertexOperator(SharedData::vertexPlusC, SharedData::vertexMinusC, SharedData::cKet, SharedData::cKet);
	VertexOperatorCSq = InitVertexOperator(SharedData::vertexPlusCSQ, SharedData::vertexMinusCSQ, SharedData::cSqKet, SharedData::cSqKet);
	VertexOperatorT = InitVertexOperator(SharedData::vertexPlusT, SharedData::vertexMinusT, SharedData::tKet, SharedData::tKet);
	VertexOperatorTC = InitVertexOperator(SharedData::vertexPlusTC, SharedData::vertexMinusTC, SharedData::tcKet, SharedData::tcKet);
	VertexOperatorTCSq = InitVertexOperator(SharedData::vertexPlusTCSq, SharedData::vertexMinusTCSq, SharedData::tcSqKet, SharedData::tcSqKet);
	//Projectors::PrintInitVertexOperators();

	ProjectorA = (VertexOperatorE.VertexOperator
		+ VertexOperatorC.VertexOperator
		+ VertexOperatorCSq.VertexOperator
		+ VertexOperatorT.VertexOperator
		+ VertexOperatorTC.VertexOperator
		+ VertexOperatorTCSq.VertexOperator);// 1/6


	ProjectorACollapsed = (VertexOperatorE.VertexOperatorTruncated
		+ VertexOperatorC.VertexOperatorTruncated
		+ VertexOperatorCSq.VertexOperatorTruncated
		+ VertexOperatorT.VertexOperatorTruncated
		+ VertexOperatorTC.VertexOperatorTruncated
		+ VertexOperatorTCSq.VertexOperatorTruncated);// 1/6

	ProjectorB = (VertexOperatorE.VertexOperator
		+ VertexOperatorC.VertexOperator
		+ VertexOperatorCSq.VertexOperator
		- VertexOperatorT.VertexOperator
		- VertexOperatorTC.VertexOperator
		- VertexOperatorTCSq.VertexOperator);// 1/6


	ProjectorBCollapsed = (VertexOperatorE.VertexOperatorTruncated
		+ VertexOperatorC.VertexOperatorTruncated
		+ VertexOperatorCSq.VertexOperatorTruncated
		- VertexOperatorT.VertexOperatorTruncated
		- VertexOperatorTC.VertexOperatorTruncated
		- VertexOperatorTCSq.VertexOperatorTruncated);// 1/6


	//std::cout << "\n\n Projector A: \n";
	//std::cout << Projectors::ProjectorA.format(CleanFmt);

	//std::cout << "\n\n Projector A Collapsed: \n";
	//std::cout << Projectors::ProjectorACollapsed.format(CleanFmt);

	//std::cout << "\n\nProjector A BraKet:";
	//GetMatrixInBraKet(ProjectorA);
	//std::cout << "\n";

	//std::cout << "\n\nProjector A Collapsed BraKet:";
	//GetMatrixInBraKet(ProjectorACollapsed);
	//std::cout << "\n";

	//Creates the files
	//-------------------------------------------------------------------------------------------

	PrintToPFile("ProjectorA", ProjectorA, ProjectorACollapsed);
	PrintToPFile("ProjectorB", ProjectorB, ProjectorBCollapsed);

	//-------------------------------------------------------------------------------------------

	PrintToAFile("vertexOperators/VertexOperatorE", VertexOperatorE);
	PrintToAFile("vertexOperators/VertexOperatorC", VertexOperatorC);
	PrintToAFile("vertexOperators/VertexOperatorCSq", VertexOperatorCSq);
	PrintToAFile("vertexOperators/VertexOperatorT", VertexOperatorT);
	PrintToAFile("vertexOperators/VertexOperatorTC", VertexOperatorTC);
	PrintToAFile("vertexOperators/VertexOperatorTCSq", VertexOperatorTCSq);
}

VertexSet Projectors::InitVertexOperator(Matrix<float, 6, 6> matrixPlus, Matrix<float, 6, 6> matrixMinus, Matrix<float, 6, 1>  gVectorE, Matrix<float, 6, 1>  gVectorEMinus)
{
	/*//----------------------------------------------------------------------------------------
		// structure test, -++-
		Eigen::MatrixXf pTestOne = Eigen::KroneckerProduct(testEVector, matrixPlus);

		// get correct g vector (can be a matrix but should boil down to a vector

		Eigen::MatrixXf pTestTwo = Eigen::KroneckerProduct(matrixPlus, testEVector);

		return Eigen::KroneckerProduct(pTestOne, pTestTwo);

	//----------------------------------------------------------------------------------------*/
	/*
		Test shows that the orientation chosen drastically changes the look of the matrix by a specific multiplicity,
		Optimal orientation chosen should be --++ to keep all changing spins to the front of the matrix

		initial orientation return is below
		return Eigen::KroneckerProduct(pOne, pTwo); // initial structure of ++--
	*/
	// 4,3,2,1 -+-+
	
		Eigen::MatrixXf pOne = Eigen::KroneckerProduct(gVectorEMinus, gVectorE); // change these to the minus version
		Eigen::MatrixXf pTwo = Eigen::KroneckerProduct(matrixMinus, matrixPlus); // change this to an incomming Vector

		int k = 0;
		while (true)
		{
			if (pTwo(k, 0) != 0)
			{
				break;
			}
			k++;
		}

		Eigen::MatrixXf finalMatrix = Eigen::KroneckerProduct(pOne, pTwo);

		MatrixXf finalResized(36, 36);

		int i = 0;
		int j;
		int usefulRows = 0;
		int firstUsefulLine = 0;
		bool bSetUsefulLine = false;

		bool bCorrect;
		while (i < finalMatrix.rows())
		{
			bCorrect = false;
			j = 0;
			while (j < 36)
			{
				if (finalMatrix(i, j) != 0) {
					bCorrect = true;
					j = 36;
				}
				else
				{
					j++;
				}

			}

			if (bCorrect)
			{
				finalResized.row(usefulRows) = finalMatrix.row(i);
				if (firstUsefulLine == 0 && !bSetUsefulLine)
				{
					firstUsefulLine = i;
					bSetUsefulLine = true;
				}
				usefulRows++;
			}
			i++;
		}
		/**/
	

	VertexSet set;
	
	set.VertexOperator = finalMatrix;
	set.VertexOperatorTruncated = finalResized;
	set.firstRow = firstUsefulLine;
	set.multiplicity = firstUsefulLine / (36); 
	/**/


	return set; //inverted orientation of --++ (4321), seems to keep the diag structure alot better
}

void Projectors::PrintInitVertexOperators()
{
	std::cout << "\n\n VertexOperatorE: \n";
	std::cout << "First Row: " << Projectors::VertexOperatorE.firstRow << "\n";
	std::cout << "Row Multiplicity: " << Projectors::VertexOperatorE.multiplicity << "\n";
	std::cout << "Outside spin states: " << GetOutSpinStates(Projectors::VertexOperatorE.firstRow, false, true) << "\n";
	//std::cout << Projectors::VertexOperatorE.VertexOperatorTruncated.format(CleanFmt);

	std::cout << "\n\n VertexOperatorC: \n";
	std::cout << "First Row: " << Projectors::VertexOperatorC.firstRow << "\n";
	std::cout << "Row Multiplicity: " << Projectors::VertexOperatorC.multiplicity << "\n";
	std::cout << "Outside spin states: " << GetOutSpinStates(Projectors::VertexOperatorC.firstRow, false, true) << "\n";
	//std::cout << Projectors::VertexOperatorC.VertexOperatorTruncated.format(CleanFmt);

	std::cout << "\n\n VertexOperatorCSq: \n";
	std::cout << "First Row: " << Projectors::VertexOperatorCSq.firstRow << "\n";
	std::cout << "Row Multiplicity: " << Projectors::VertexOperatorCSq.multiplicity << "\n";
	std::cout << "Outside spin states: " << GetOutSpinStates(Projectors::VertexOperatorCSq.firstRow, false, true) << "\n";
	//std::cout << Projectors::VertexOperatorCSq.VertexOperatorTruncated.format(CleanFmt);

	std::cout << "\n\n VertexOperatorT: \n";
	std::cout << "First Row: " << Projectors::VertexOperatorT.firstRow << "\n";
	std::cout << "Row Multiplicity: " << Projectors::VertexOperatorT.multiplicity << "\n";
	std::cout << "Outside spin states: " << GetOutSpinStates(Projectors::VertexOperatorT.firstRow, false, true) << "\n";
	//std::cout << Projectors::VertexOperatorT.VertexOperatorTruncated.format(CleanFmt);

	std::cout << "\n\n VertexOperatorTC: \n";
	std::cout << "First Row: " << Projectors::VertexOperatorTC.firstRow << "\n";
	std::cout << "Row Multiplicity: " << Projectors::VertexOperatorTC.multiplicity << "\n";
	std::cout << "Outside spin states: " << GetOutSpinStates(Projectors::VertexOperatorTC.firstRow, false, true) << "\n";
	std::cout << Projectors::VertexOperatorTC.VertexOperatorTruncated.format(CleanFmt);

	std::cout << "\n\n VertexOperatorTCSq: \n";
	std::cout << "First Row: " << Projectors::VertexOperatorTCSq.firstRow << "\n";
	std::cout << "Row Multiplicity: " << Projectors::VertexOperatorTCSq.multiplicity << "\n";
	std::cout << "Outside spin states: " << GetOutSpinStates(Projectors::VertexOperatorTCSq.firstRow, false, true) << "\n";
	//std::cout << Projectors::VertexOperatorTCSq.VertexOperatorTruncated.format(CleanFmt);


}

std::string Projectors::GetOutSpinStates(int firstRow, bool bOtherStates, bool bLeftRight)//Rows
{
	int smallSetAmount = 36;
	int largeSetAmount = smallSetAmount * 6;

	int fourthSpinInt = 0;
	std::string fourthSpin = "";

	int thirdSpinInt = 0;
	std::string thirdSpin = "";

	int secondSpinInt = 0;
	std::string secondSpin = "";

	int firstSpinInt = 0;
	std::string firstSpin = "";

	int j = 0;
	int i = 0;
	int k = 0;
	int l = 0;

	int smallModified = 0;
	int secondModified = 0;
	int firstModified = 0;

	while (i < 6)
	{
		if ((largeSetAmount * i) <= firstRow && firstRow < (largeSetAmount * (i + 1)))
		{
			fourthSpinInt = i;
			fourthSpin = SharedData::spinIntToString[i];

			while (j < 6)
			{
				smallModified = firstRow - (largeSetAmount * i);
				if ((smallSetAmount * j) <= smallModified && smallModified < (smallSetAmount * (j + 1)))
				{
					//std::cout << "\n	set.firstRow - (largeSetAmount * i): (" << smallModified << ")\n";
					//std::cout << "	smallSetAmount * i: (" << smallSetAmount * j << ")\n";
					//std::cout << "	smallSetAmount * i+1: (" << smallSetAmount * (j + 1) << ")\n";

					thirdSpinInt = j;
					thirdSpin = SharedData::spinIntToString[j];

					if (bOtherStates)
					{
						while (k < 6) {
							secondModified = smallModified - (smallSetAmount * j);

							if ((6 * k) <= secondModified && secondModified < (6 * (k + 1)))
							{
								//std::cout << "\n	secondModified: " << secondModified << "\n";
								//std::cout << "\n	firstModified: " << secondModified - k << "\n";
								//std::cout << "\n	firstModified: " << secondModified - (6 * k) << "\n";

								secondSpinInt = k;
								secondSpin = SharedData::spinIntToString[k];

								switch (secondModified - (6 * k))
								{
								case 0:
									firstSpinInt = 0;
									break;
								case 1:
									firstSpinInt = 1;
									break;
								case 2:
									firstSpinInt = 2;
									break;
								case 3:
									firstSpinInt = 3;
									break;
								case 4:
									firstSpinInt = 4;
									break;
								case 5:
									firstSpinInt = 5;
									break;

								}
								firstSpin = SharedData::spinIntToString[firstSpinInt];
								break;
							}

							//std::cout << "	smallSetAmount * i: (" << smallSetAmount * j << ")\n";
							//std::cout << "	smallSetAmount * i+1: (" << smallSetAmount * (j + 1) << ")\n";

							k++;
						}
					}
					break;
				}
				j++;
			}

			break;
		}
		i++;
	}

	if (bLeftRight)
	{
		if (bOtherStates)
		{
			return fourthSpin + "," + thirdSpin + "," + secondSpin + "," + firstSpin;
		}
		else
		{
			return fourthSpin + "," + thirdSpin;
		}
	}
	else
	{
		if (bOtherStates)
		{
			return firstSpin + "," + secondSpin + "," + thirdSpin + "," + fourthSpin;
		}
		else
		{
			return thirdSpin + "," + fourthSpin;
		}

	}


}

std::string Projectors::GetSpinStatesCols(int col)
{
	int secondSpinInt = 0;
	std::string secondSpin = "";

	int firstSpinInt = 0;
	std::string firstSpin = "";

	int i = 0;
	int j = 0;

	while (i < 6)
	{
		if ((6 * i) <= col && col < (6 * (i + 1)))
		{
			secondSpinInt = i;
			secondSpin = SharedData::spinIntToString[i];

			switch (col - (6 * i))
			{
			case 0:
				firstSpinInt = 0;
				break;
			case 1:
				firstSpinInt = 1;
				break;
			case 2:
				firstSpinInt = 2;
				break;
			case 3:
				firstSpinInt = 3;
				break;
			case 4:
				firstSpinInt = 4;
				break;
			case 5:
				firstSpinInt = 5;
				break;
			}

			firstSpin = SharedData::spinIntToString[firstSpinInt];
		}
		i++;
	}
	return secondSpin + "," + firstSpin;
}

std::map<std::string, BraketSet> Projectors::GetMatrixInBraKet(MatrixXf matrix)
{
	std::map<std::string, BraketSet> braketMap;
	int i = 0;
	int j = 0;
	//std::cout << "\n	cols" << matrix.cols();
	std::string cRow = "";
	std::string cCol = "";

	while (i < matrix.rows())
	{
		j = 0;
		while (j < matrix.cols())
		{
			if (matrix(i, j) != 0)
			{
				cRow = "|" + GetOutSpinStates(i, true, true) + ">";
				cCol = "<" + GetSpinStatesCols(j) + "|";

				if (braketMap.find(cRow) != braketMap.end()) // extend
				{
					braketMap[cRow].braSet[cCol] = matrix(i, j);
				}
				else
				{
					std::map<std::string, float> braSetSetup = { {cCol, matrix(i, j)} };
					BraketSet set;
					set.ket = cRow;
					set.braSet = braSetSetup;

					braketMap[cRow] = set;

				}
			}
			j++;
		}
		i++;
	}

	return braketMap;
}

void Projectors::PrintToAFile(std::string name, VertexSet operatorStruct)
{
	std::ofstream A("dataFiles/" + name + ".txt");
	A << "Braket for " + name + ":\n";
	for (auto const& ket : GetMatrixInBraKet(operatorStruct.VertexOperator))
	{
		//std::cout << "\n" << ket.second.ket;
		A << "	" << ket.second.ket;
		for (auto const& bra : ket.second.braSet)
		{
			//std::cout << "\n	" << bra.second << " * " << bra.first;
			A << "\n		" << bra.second << " * " << bra.first;
		}
		A << "\n\n";
	}

	A << "\n\n\nMatrix for " + name + " truncated:\n";
	A << operatorStruct.VertexOperatorTruncated.format(CleanFmt);

	A << "\nMatrix for " + name + ":\n";
	A << operatorStruct.VertexOperator.format(CleanFmt);

	A.close();
}

void Projectors::PrintToPFile(std::string name, MatrixXf projecterFull, MatrixXf projecterCollapsed)
{
	std::ofstream ProjectorFullFile("dataFiles/projectors/" + name + "/Full.txt");
	ProjectorFullFile << "NOTE: All matrices in file have an ommitted factor of 1/6\n\n\n";

	ProjectorFullFile << "Braket for " + name + ":\n";
	for (auto const& ket : GetMatrixInBraKet(projecterFull))
	{
		//std::cout << "\n" << ket.second.ket;
		ProjectorFullFile << ket.second.ket;
		for (auto const& bra : ket.second.braSet)
		{
			//std::cout << "\n	" << bra.second << " * " << bra.first;
			ProjectorFullFile << "\n	" << bra.second << " * " << bra.first;
		}
		ProjectorFullFile << "\n\n";
	}

	ProjectorFullFile << "\nMatrix for " + name + ":\n";
	ProjectorFullFile << projecterFull.format(CleanFmt);

	ProjectorFullFile.close();

	std::ofstream ProjectorCollapsedFile("dataFiles/projectors/" + name + "/Collapsed.txt");
	ProjectorCollapsedFile << "NOTE: All matrices in file have an ommitted factor of 1/6\n\n\n";

	ProjectorCollapsedFile << "Braket for " + name + " Collapsed:\n";
	for (auto const& ket : GetMatrixInBraKet(projecterCollapsed))
	{
		//std::cout << "\n" << ket.second.ket;
		ProjectorCollapsedFile << "	" << ket.second.ket;
		for (auto const& bra : ket.second.braSet)
		{
			//std::cout << "\n	" << bra.second << " * " << bra.first;
			ProjectorCollapsedFile << "\n		" << bra.second << " * " << bra.first;
		}
		ProjectorCollapsedFile << "\n\n";
	}


	ProjectorCollapsedFile << "\nMatrix for " + name + " Collapsed:\n";
	ProjectorCollapsedFile << projecterCollapsed.format(CleanFmt);

	ProjectorCollapsedFile.close();
}

