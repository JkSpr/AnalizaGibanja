// AnalizaGibanja.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
    std::string fileContent;
    int height = 0;
    int heightPrevious = 0;
    float heightStepAvg = 0;
    int nrOfMountains = 0;
    int nrOfValleys = 0;
    int stepsMountains = 0;
    int stepsValleys = 0;
    int stepsSeaLevel = 0;
    int minHeight = 65536;
    int maxHeight = -65536;

    std::cout << "\nGreetings traveler!\n";

    std::ifstream RobotMovement;
    RobotMovement.open("D:/Privat/Naloga/AnalizaGibanja/RobotMovement.txt");

    if (RobotMovement.is_open())
    {
        std::cout << "file is open!\n";
        RobotMovement >> fileContent;
        RobotMovement.close();
        std::cout << "\nSteps total: " << fileContent.length() << "\n\n";
    }
    else
    {
        std::cout << "Couldn't open file\n";
    }

    for (int i = 0; i < 65535; i++)
    {
        if (fileContent[i] != '\0')
        {
            switch (fileContent[i])
            {
            case 'G':
            {
                if (height == 0)
                {
                    nrOfMountains += 1;
                }
                height += 1;
                break;
            }
            case 'D':
            {
                if (height == 0)
                {
                    nrOfValleys += 1;
                }
                height -= 1;
                break;
            }
            case 'I':
            {
                break;
            }
            default:
            {
                std::cout << "The file is corrupt!\n";
                break;
            }

            }
            std::cout << fileContent[i] << " | height: " << height << "\n";
            // steps
            heightStepAvg = float(height + heightPrevious) / 2;
            heightPrevious = height;
            stepsMountains += int(heightStepAvg > 0);
            stepsValleys += int(heightStepAvg < 0);
            stepsSeaLevel += int(heightStepAvg == 0);
            /*
            if (heightStepAvg > 0)
            {
                stepsMountains += 1;
            }
            else if (heightStepAvg < 0)
            {
                stepsValleys += 1;
            }
            else
            {
                stepsSeaLevel += 1;
            }
            */
            // find min height
            if (height < minHeight)
            {
                minHeight = height;
            }
            // find max height
            if (height > maxHeight)
            {
                maxHeight = height;
            }
        }
        else
        {
            break;
        }
    }

    std::cout << "\n\nStatistics:\n";
    std::cout << "Final height: " << height << "\n";
    std::cout << "Number of mountains: " << nrOfMountains << "\n";
    std::cout << "Number of valleys: " << nrOfValleys << "\n";
    std::cout << "Ain't no mountain higher: " << maxHeight << "\n";
    std::cout << "Ain't no valley lower: " << minHeight << "\n";
    std::cout << "Number of steps in mountains: " << stepsMountains << "\n";
    std::cout << "Number of steps in valleys: " << stepsValleys << "\n";
    std::cout << "Number of steps at sea level: " << stepsSeaLevel << "\n";

    std::cout << "\nPress any key to continue...\n";
    std::cin.get();

}





// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
