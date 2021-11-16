#pragma once

#include <vector>
#include <random>

class ExceptionCaughtFish : public std::exception
{
public:
	const char* what() const noexcept override
	{
		return "You caught a fish!";
	}
};

class ExceptionCaughtBoot : public std::exception
{
public:
	const char* what() const noexcept override
	{
		return "You caught a boot!";
	}
};

class ExceptionInvalidSectorNumber : public std::exception
{
public:
	const char* what() const noexcept override
	{
		return "Invalid sector number!";
	}
};

class Pond
{
private:
	char signEmpty{ ' ' };
	char signFish{ 'f' };
	char signBoot{ 'b' };

	const int numberOfFish{ 1 };
	const int numberOfBoots{ 3 };

	const int size{ 3 };
	std::vector<std::vector<char>> pond;

	std::random_device rd;
	std::default_random_engine dre;
	std::uniform_int_distribution<int> uid;

	void distributionOfEntities(int numberOfEntities, char entity);

public:
	Pond() : dre{ rd() }, uid{ std::uniform_int_distribution<int>(0, size - 1) }
	{
		pond.resize(size, std::vector<char>(size, signEmpty));

		distributionOfEntities(numberOfFish, signFish);
		distributionOfEntities(numberOfBoots, signBoot);
	}

	void pullFishingRod(int numberOfSector);

	void output() const;

};