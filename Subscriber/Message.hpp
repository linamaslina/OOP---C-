#pragma once

class Message
{
public:
	Message() = default;
	Message(int data) : data(data) {};

	int getData() const
	{
		return data;
	}
	const int data;
};