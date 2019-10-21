#pragma once
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string_cast.hpp>
#include <transform.hpp>

class NeuralNetwork
{
private:
	glm::vec4 m_inputs[4]{ {1,0,0,0}, {1,0,0,1}, {1,1,1,0}, {1,0,1,1} };
	glm::vec4 m_weights{ 0,0,0,0 };
	float m_bias;
	float m_output[4];
public:
	NeuralNetwork();
	~NeuralNetwork();
	float think(glm::vec4 _input);
	void train(float _trueOutput[4]);
	void output();
};

