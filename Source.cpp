#include "NeuralNetwork.h"

int main()
{
	/*int trainingInputs[4][3]{ {0,0,1},{1,1,1},{1,0,1},{0,1,1} };
	int trainingOutputs[4]{ {0},{1},{1},{0} };
	srand(1);
	int inputLayer[3];
	float output[4];
	float synapticWeights[3]{ (2 * ((float)rand() / RAND_MAX)) - 1, (2 * ((float)rand() / RAND_MAX)) - 1, (2 * ((float)rand() / RAND_MAX)) - 1 };
	float error[4];
	float adjustments[4];
	std::cout << "starting weights" << std::endl << synapticWeights[0] << std::endl << synapticWeights[1] << std::endl << synapticWeights[2] << std::endl;
	for (int x = 0; x < 1000000; x++)
	{
		for (int loop = 0; loop < 4; loop++)
		{
			inputLayer[0] = trainingInputs[loop][0];
			inputLayer[1] = trainingInputs[loop][1];
			inputLayer[2] = trainingInputs[loop][2];
			output[loop] = sigmoid(((float)inputLayer[0] * synapticWeights[0]) + ((float)inputLayer[1] * synapticWeights[1]) + ((float)inputLayer[2] * synapticWeights[2]));
		}
		for (int loop = 0; loop < 4; loop++)
		{
			for (int loop2 = 0; loop2 < 4; loop2++)
			{
				error[loop2] = trainingOutputs[loop2] - output[loop2];
				adjustments[loop2] = error[loop2] * sigmoidDerivative(output[loop2]);
			}
			synapticWeights[loop] += (trainingInputs[loop][0] * adjustments[0]) + (trainingInputs[loop][1] * adjustments[1]) + (trainingInputs[loop][2] * adjustments[2]);
		}
	}
	std::cout << "Weights after training" << std::endl << synapticWeights[0] << std::endl << synapticWeights[1] << std::endl << synapticWeights[2] << std::endl;
	std::cout << "outputs after training" << std::endl << output[0] << std::endl << output[1] << std::endl << output[2] << std::endl << output[3];*/
	NeuralNetwork brain;
	float testOutputs[4]{ 0,1,0,1 };
	for (int loop = 0; loop < 500000; loop++)
	{
		brain.train(testOutputs);
	}
	brain.output();
	glm::ivec4 inputs;
	std::cout << "Enter your own test input" << std::endl;
	inputs[0] = 1;
	for (int loop = 1; loop < 4; loop++)
	{
		std::cin >> inputs[loop];	
	}
	float output = brain.think(inputs);
	std::cout << "The network believes the answer is " << output;
	std::cin.get();
	std::cin.get();
	return 0;
}

