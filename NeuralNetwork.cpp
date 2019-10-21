#include "NeuralNetwork.h"

float sigmoid(float _x);

float sigmoidDerivative(float _x);

NeuralNetwork::NeuralNetwork()
{
	srand(1);
	for (int loop = 0; loop < 4; loop++)
	{
		m_weights[loop] = ((float)(rand()) / (float)(RAND_MAX / 2)) - 1;
	}
}


NeuralNetwork::~NeuralNetwork()
{

}

float NeuralNetwork::think(glm::vec4 _input)
{
	return sigmoid(glm::dot(_input, m_weights));
}

void NeuralNetwork::train(float _trueOutput[4])
{
	float adjustments[4];
	for (int loop = 0; loop < 4; loop++)
	{
		m_output[loop] = this->think(m_inputs[loop]);
	}
	for (int loop2 = 0; loop2 < 4; loop2++)
	{
		float error = _trueOutput[loop2] - m_output[loop2];
		adjustments[loop2] = error * sigmoidDerivative(m_output[loop2]);
	}
	for (int loop = 0; loop < 4; loop++)
	{
		m_weights[loop] += 0.1 * ((m_inputs[0][loop] * adjustments[0]) + (m_inputs[1][loop] * adjustments[1]) + (m_inputs[2][loop] * adjustments[2]) + (m_inputs[3][loop] * adjustments[3]));
	}
}

void NeuralNetwork::output()
{
	std::cout << "Weights after training: " << m_weights[0] << " " << m_weights[1] << " " << m_weights[2] << " " << m_weights[3] << std::endl;
	std::cout << "Test case: " << this->think(glm::vec4(1, 0, 0, 1)) << std::endl;
}

float sigmoid(float _x)
{
	return 1 / (1 + exp(-(_x)));
}

float sigmoidDerivative(float _x)
{
	return sigmoid(_x) * (1 - sigmoid(_x));
}