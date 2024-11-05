// ProjectMphysProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Shared.hpp"
#include "Projectors.hpp"
#include "RibbonOperators.hpp"

int main()
{
    SharedData::InitData();
    //SharedData::PrintInitData(true, true, true, true, true);
    //SharedData::PrintInitData(true, false, false, false, false);

    Projectors::ProjectorsStart();

    Ribbons::Main();

    return 0;
}
