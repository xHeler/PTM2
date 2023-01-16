#pragma once

#include <stdint.h>
#include "Arduino.h"

const uint8_t NUM_LINES_MASTER = 10;
const uint8_t NUM_LINES_SLAVE = 7;

class Throw{
    public:
    uint8_t multiplier;
    uint8_t value;

    Throw &operator=(const Throw &other);
    uint8_t getResult();
    bool operator==(const Throw &other) const;
    bool operator!=(const Throw &other) const;
    bool operator!() const;
    bool operator==(const int &other) const;
    bool operator>(const int &other) const;
    bool operator<(const int &other) const;

    Throw(const uint8_t &multiplier, const uint8_t &value);
    Throw();
};

uint16_t operator- (const uint16_t &points, const Throw &hit);
uint16_t operator+ (const uint16_t &points, const Throw &hit);

const Throw SETUP_MATRIX[NUM_LINES_MASTER][NUM_LINES_SLAVE]  ={
    // 3x				         2x			        	1x		        		center
    // 0            1           2           3           4           5           6
    {{3,1 },   	{3,  7}, 	{2,1 },	    {2,7 },	    {1,1},		{1,7 },		{1, 255}  },
    {{3,18 },   	{3, 19},	{2,18},	    {2,19},	    {1,18},		{1,19},		{1, 255}  },
    {{3,4 },	   	{3, 3 },	{2,4 },	    {2,3 },	    {1,4 },		{1,3 },		{1, 255}  },
    {{3,13 },   	{3, 17},	{2,13},	    {2,17},	    {1,13},		{1,17},		{1, 255}  },
    {{3,6 },	   	{3,  2},	{2,6},	    {2,2 },	    {1,6 },		{1,2 },		{1, 255}  },
    {{3,10 },   	{3,  15},	{2,10},	    {2,15},	    {1,10},		{1,15},		{1, 255}  },
    {{3,20 },	   	{3, 16},	{2,20},	    {2,16},	    {1,20},		{1,16},		{1, 255}  },
    {{3,5 },   	{3,  8},	{2,5 },	    {2, 8},	    {1,5},		{1,8 },		{1, 255}  },
    {{3,12 },	   	{3, 11},	{2,12},	    {2,11},	    {1,12},		{1,11},		{1,25}  },
    {{3,9 },   	{3, 14},	{2,10},	    {2,14},	    {1,9},		{1,14},		{2,25}  }
};

uint8_t fromByteToIndex(byte states);