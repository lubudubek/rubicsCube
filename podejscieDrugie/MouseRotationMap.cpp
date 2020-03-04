#include "MouseRotationMap.h"


namespace test
{
	std::ostream& operator<<(std::ostream& os, Direction2d dir)
	{
		switch (dir)
		{
		case Direction2d::UP:    os << "UP"; break;
		case Direction2d::DOWN:  os << "DOWN"; break;
		case Direction2d::RIGHT: os << "RIGHT"; break;
		case Direction2d::LEFT:  os << "LEFT"; break;
		}
		return os;
	}

	bool MouseRotationKey::operator<(const MouseRotationKey& l) const
	{
		if (positions != l.positions)
			return positions < l.positions;

		if (surface != l.surface)
			return surface < l.surface;

		return direction < l.direction;
	}
	bool MouseRotationKey::operator==(const MouseRotationKey & l) const
	{
		return (positions == l.positions && surface == l.surface && direction == l.direction);
	}

	MouseRotationKey::MouseRotationKey(const std::vector<Position> & position,
		Position surface,
		Direction2d direction) : positions(position), surface(surface), direction(direction)
	{
		std::sort(positions.begin(), positions.end());
	}

	std::map<MouseRotationKey, Rotation1> mouseRotationsMap{
//corner 1
	{ { { Position::FRONT, Position::LEFT,  Position::TOP    }, Position::FRONT, Direction2d::RIGHT }, Rotation1::TOP_ROTATE_LEFT  },
	{ { { Position::FRONT, Position::LEFT,  Position::TOP    }, Position::FRONT, Direction2d::LEFT  }, Rotation1::TOP_ROTATE_RIGHT },
	{ { { Position::FRONT, Position::LEFT,  Position::TOP    }, Position::FRONT, Direction2d::UP    }, Rotation1::LEFT_ROTATE_UP   },
	{ { { Position::FRONT, Position::LEFT,  Position::TOP    }, Position::FRONT, Direction2d::DOWN  }, Rotation1::LEFT_ROTATE_DOWN },

	{ { { Position::FRONT, Position::LEFT,  Position::TOP    }, Position::TOP, Direction2d::RIGHT }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::FRONT, Position::LEFT,  Position::TOP    }, Position::TOP, Direction2d::LEFT  }, Rotation1::FRONT_ROTATE_LEFT  },
	{ { { Position::FRONT, Position::LEFT,  Position::TOP    }, Position::TOP, Direction2d::UP    }, Rotation1::LEFT_ROTATE_UP     },
	{ { { Position::FRONT, Position::LEFT,  Position::TOP    }, Position::TOP, Direction2d::DOWN  }, Rotation1::LEFT_ROTATE_DOWN   },

	{ { { Position::FRONT, Position::LEFT,  Position::TOP    }, Position::LEFT, Direction2d::RIGHT }, Rotation1::TOP_ROTATE_LEFT    },
	{ { { Position::FRONT, Position::LEFT,  Position::TOP    }, Position::LEFT, Direction2d::LEFT  }, Rotation1::TOP_ROTATE_RIGHT   },
	{ { { Position::FRONT, Position::LEFT,  Position::TOP    }, Position::LEFT, Direction2d::UP    }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::FRONT, Position::LEFT,  Position::TOP    }, Position::LEFT, Direction2d::DOWN  }, Rotation1::FRONT_ROTATE_LEFT  },

//corner 2
	{ { { Position::FRONT, Position::RIGHT,  Position::TOP    }, Position::FRONT, Direction2d::RIGHT }, Rotation1::TOP_ROTATE_LEFT  },
	{ { { Position::FRONT, Position::RIGHT,  Position::TOP    }, Position::FRONT, Direction2d::LEFT  }, Rotation1::TOP_ROTATE_RIGHT },
	{ { { Position::FRONT, Position::RIGHT,  Position::TOP    }, Position::FRONT, Direction2d::UP    }, Rotation1::RIGHT_ROTATE_UP   },
	{ { { Position::FRONT, Position::RIGHT,  Position::TOP    }, Position::FRONT, Direction2d::DOWN  }, Rotation1::RIGHT_ROTATE_DOWN },
									 
	{ { { Position::FRONT, Position::RIGHT,  Position::TOP    }, Position::TOP, Direction2d::RIGHT }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::FRONT, Position::RIGHT,  Position::TOP    }, Position::TOP, Direction2d::LEFT  }, Rotation1::FRONT_ROTATE_LEFT  },
	{ { { Position::FRONT, Position::RIGHT,  Position::TOP    }, Position::TOP, Direction2d::UP    }, Rotation1::LEFT_ROTATE_UP     },
	{ { { Position::FRONT, Position::RIGHT,  Position::TOP    }, Position::TOP, Direction2d::DOWN  }, Rotation1::LEFT_ROTATE_DOWN   },
									 
	{ { { Position::FRONT, Position::RIGHT,  Position::TOP    }, Position::RIGHT, Direction2d::RIGHT }, Rotation1::TOP_ROTATE_LEFT    },
	{ { { Position::FRONT, Position::RIGHT,  Position::TOP    }, Position::RIGHT, Direction2d::LEFT  }, Rotation1::TOP_ROTATE_RIGHT   },
	{ { { Position::FRONT, Position::RIGHT,  Position::TOP    }, Position::RIGHT, Direction2d::UP    }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::FRONT, Position::RIGHT,  Position::TOP    }, Position::RIGHT, Direction2d::DOWN  }, Rotation1::FRONT_ROTATE_LEFT  },

//corner 3
	{ { { Position::BACK, Position::LEFT,  Position::TOP    }, Position::BACK, Direction2d::RIGHT }, Rotation1::FRONT_ROTATE_RIGHT},
	{ { { Position::BACK, Position::LEFT,  Position::TOP    }, Position::BACK, Direction2d::LEFT  }, Rotation1::FRONT_ROTATE_LEFT},
	{ { { Position::BACK, Position::LEFT,  Position::TOP    }, Position::BACK, Direction2d::UP    }, Rotation1::LEFT_ROTATE_UP},
	{ { { Position::BACK, Position::LEFT,  Position::TOP    }, Position::BACK, Direction2d::DOWN  }, Rotation1::LEFT_ROTATE_DOWN},
					
	{ { { Position::BACK, Position::LEFT,  Position::TOP    }, Position::LEFT, Direction2d::RIGHT }, Rotation1::FRONT_ROTATE_RIGHT},
	{ { { Position::BACK, Position::LEFT,  Position::TOP    }, Position::LEFT, Direction2d::LEFT  }, Rotation1::FRONT_ROTATE_RIGHT},
	{ { { Position::BACK, Position::LEFT,  Position::TOP    }, Position::LEFT, Direction2d::UP    }, Rotation1::FRONT_ROTATE_RIGHT},
	{ { { Position::BACK, Position::LEFT,  Position::TOP    }, Position::LEFT, Direction2d::DOWN  }, Rotation1::FRONT_ROTATE_RIGHT},
					
	{ { { Position::BACK, Position::LEFT,  Position::TOP    }, Position::TOP,  Direction2d::RIGHT }, Rotation1::FRONT_ROTATE_RIGHT},
	{ { { Position::BACK, Position::LEFT,  Position::TOP    }, Position::TOP,  Direction2d::LEFT  }, Rotation1::FRONT_ROTATE_RIGHT},
	{ { { Position::BACK, Position::LEFT,  Position::TOP    }, Position::TOP,  Direction2d::UP    }, Rotation1::FRONT_ROTATE_RIGHT},
	{ { { Position::BACK, Position::LEFT,  Position::TOP    }, Position::TOP,  Direction2d::DOWN  }, Rotation1::FRONT_ROTATE_RIGHT},

//corner 4
	{ { { Position::BACK, Position::RIGHT,  Position::TOP    }, Position::BACK, Direction2d::RIGHT }, Rotation1::FRONT_ROTATE_RIGHT},
	{ { { Position::BACK, Position::RIGHT,  Position::TOP    }, Position::BACK, Direction2d::LEFT  }, Rotation1::FRONT_ROTATE_LEFT},
	{ { { Position::BACK, Position::RIGHT,  Position::TOP    }, Position::BACK, Direction2d::UP    }, Rotation1::LEFT_ROTATE_UP},
	{ { { Position::BACK, Position::RIGHT,  Position::TOP    }, Position::BACK, Direction2d::DOWN  }, Rotation1::LEFT_ROTATE_DOWN},

	{ { { Position::BACK, Position::RIGHT,  Position::TOP    }, Position::RIGHT, Direction2d::RIGHT }, Rotation1::FRONT_ROTATE_RIGHT},
	{ { { Position::BACK, Position::RIGHT,  Position::TOP    }, Position::RIGHT, Direction2d::LEFT  }, Rotation1::FRONT_ROTATE_RIGHT},
	{ { { Position::BACK, Position::RIGHT,  Position::TOP    }, Position::RIGHT, Direction2d::UP    }, Rotation1::FRONT_ROTATE_RIGHT},
	{ { { Position::BACK, Position::RIGHT,  Position::TOP    }, Position::RIGHT, Direction2d::DOWN  }, Rotation1::FRONT_ROTATE_RIGHT},

	{ { { Position::BACK, Position::RIGHT,  Position::TOP    }, Position::TOP,  Direction2d::RIGHT }, Rotation1::FRONT_ROTATE_RIGHT},
	{ { { Position::BACK, Position::RIGHT,  Position::TOP    }, Position::TOP,  Direction2d::LEFT  }, Rotation1::FRONT_ROTATE_RIGHT},
	{ { { Position::BACK, Position::RIGHT,  Position::TOP    }, Position::TOP,  Direction2d::UP    }, Rotation1::FRONT_ROTATE_RIGHT},
	{ { { Position::BACK, Position::RIGHT,  Position::TOP    }, Position::TOP,  Direction2d::DOWN  }, Rotation1::FRONT_ROTATE_RIGHT},

	//corner 5
	{ { { Position::FRONT, Position::LEFT,  Position::BOTTOM    }, Position::FRONT, Direction2d::RIGHT }, Rotation1::TOP_ROTATE_LEFT  },
	{ { { Position::FRONT, Position::LEFT,  Position::BOTTOM    }, Position::FRONT, Direction2d::LEFT  }, Rotation1::TOP_ROTATE_RIGHT },
	{ { { Position::FRONT, Position::LEFT,  Position::BOTTOM    }, Position::FRONT, Direction2d::UP    }, Rotation1::LEFT_ROTATE_UP   },
	{ { { Position::FRONT, Position::LEFT,  Position::BOTTOM    }, Position::FRONT, Direction2d::DOWN  }, Rotation1::LEFT_ROTATE_DOWN },

	{ { { Position::FRONT, Position::LEFT,  Position::BOTTOM    }, Position::BOTTOM, Direction2d::RIGHT }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::FRONT, Position::LEFT,  Position::BOTTOM    }, Position::BOTTOM, Direction2d::LEFT  }, Rotation1::FRONT_ROTATE_LEFT  },
	{ { { Position::FRONT, Position::LEFT,  Position::BOTTOM    }, Position::BOTTOM, Direction2d::UP    }, Rotation1::LEFT_ROTATE_UP     },
	{ { { Position::FRONT, Position::LEFT,  Position::BOTTOM    }, Position::BOTTOM, Direction2d::DOWN  }, Rotation1::LEFT_ROTATE_DOWN   },

	{ { { Position::FRONT, Position::LEFT,  Position::BOTTOM    }, Position::LEFT, Direction2d::RIGHT }, Rotation1::TOP_ROTATE_LEFT    },
	{ { { Position::FRONT, Position::LEFT,  Position::BOTTOM    }, Position::LEFT, Direction2d::LEFT  }, Rotation1::TOP_ROTATE_RIGHT   },
	{ { { Position::FRONT, Position::LEFT,  Position::BOTTOM    }, Position::LEFT, Direction2d::UP    }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::FRONT, Position::LEFT,  Position::BOTTOM    }, Position::LEFT, Direction2d::DOWN  }, Rotation1::FRONT_ROTATE_LEFT  },

		//corner 6
	{ { { Position::FRONT, Position::RIGHT,  Position::BOTTOM    }, Position::FRONT, Direction2d::RIGHT }, Rotation1::TOP_ROTATE_LEFT  },
	{ { { Position::FRONT, Position::RIGHT,  Position::BOTTOM    }, Position::FRONT, Direction2d::LEFT  }, Rotation1::TOP_ROTATE_RIGHT },
	{ { { Position::FRONT, Position::RIGHT,  Position::BOTTOM    }, Position::FRONT, Direction2d::UP    }, Rotation1::RIGHT_ROTATE_UP   },
	{ { { Position::FRONT, Position::RIGHT,  Position::BOTTOM    }, Position::FRONT, Direction2d::DOWN  }, Rotation1::RIGHT_ROTATE_DOWN },

	{ { { Position::FRONT, Position::RIGHT,  Position::BOTTOM    }, Position::BOTTOM, Direction2d::RIGHT }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::FRONT, Position::RIGHT,  Position::BOTTOM    }, Position::BOTTOM, Direction2d::LEFT  }, Rotation1::FRONT_ROTATE_LEFT  },
	{ { { Position::FRONT, Position::RIGHT,  Position::BOTTOM    }, Position::BOTTOM, Direction2d::UP    }, Rotation1::LEFT_ROTATE_UP     },
	{ { { Position::FRONT, Position::RIGHT,  Position::BOTTOM    }, Position::BOTTOM, Direction2d::DOWN  }, Rotation1::LEFT_ROTATE_DOWN   },

	{ { { Position::FRONT, Position::RIGHT,  Position::BOTTOM    }, Position::RIGHT, Direction2d::RIGHT }, Rotation1::TOP_ROTATE_LEFT    },
	{ { { Position::FRONT, Position::RIGHT,  Position::BOTTOM    }, Position::RIGHT, Direction2d::LEFT  }, Rotation1::TOP_ROTATE_RIGHT   },
	{ { { Position::FRONT, Position::RIGHT,  Position::BOTTOM    }, Position::RIGHT, Direction2d::UP    }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::FRONT, Position::RIGHT,  Position::BOTTOM    }, Position::RIGHT, Direction2d::DOWN  }, Rotation1::FRONT_ROTATE_LEFT  },

			//corner 7
	{ { { Position::BACK, Position::LEFT,  Position::BOTTOM    }, Position::BACK, Direction2d::RIGHT }, Rotation1::FRONT_ROTATE_RIGHT},
	{ { { Position::BACK, Position::LEFT,  Position::BOTTOM    }, Position::BACK, Direction2d::LEFT }, Rotation1::FRONT_ROTATE_LEFT},
	{ { { Position::BACK, Position::LEFT,  Position::BOTTOM    }, Position::BACK, Direction2d::UP }, Rotation1::LEFT_ROTATE_UP},
	{ { { Position::BACK, Position::LEFT,  Position::BOTTOM    }, Position::BACK, Direction2d::DOWN }, Rotation1::LEFT_ROTATE_DOWN},

	{ { { Position::BACK, Position::LEFT,  Position::BOTTOM    }, Position::LEFT, Direction2d::RIGHT }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::BACK, Position::LEFT,  Position::BOTTOM    }, Position::LEFT, Direction2d::LEFT  }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::BACK, Position::LEFT,  Position::BOTTOM    }, Position::LEFT, Direction2d::UP    }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::BACK, Position::LEFT,  Position::BOTTOM    }, Position::LEFT, Direction2d::DOWN  }, Rotation1::FRONT_ROTATE_RIGHT },

	{ { { Position::BACK, Position::LEFT,  Position::BOTTOM    }, Position::BOTTOM, Direction2d::RIGHT }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::BACK, Position::LEFT,  Position::BOTTOM    }, Position::BOTTOM, Direction2d::LEFT  }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::BACK, Position::LEFT,  Position::BOTTOM    }, Position::BOTTOM, Direction2d::UP    }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::BACK, Position::LEFT,  Position::BOTTOM    }, Position::BOTTOM, Direction2d::DOWN  }, Rotation1::FRONT_ROTATE_RIGHT},

				//corner 8
	{ { { Position::BACK, Position::RIGHT,  Position::BOTTOM    }, Position::BACK, Direction2d::RIGHT }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::BACK, Position::RIGHT,  Position::BOTTOM    }, Position::BACK, Direction2d::LEFT }, Rotation1::FRONT_ROTATE_LEFT },
	{ { { Position::BACK, Position::RIGHT,  Position::BOTTOM    }, Position::BACK, Direction2d::UP }, Rotation1::LEFT_ROTATE_UP },
	{ { { Position::BACK, Position::RIGHT,  Position::BOTTOM    }, Position::BACK, Direction2d::DOWN }, Rotation1::LEFT_ROTATE_DOWN },

	{ { { Position::BACK, Position::RIGHT,  Position::BOTTOM    }, Position::RIGHT, Direction2d::RIGHT }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::BACK, Position::RIGHT,  Position::BOTTOM    }, Position::RIGHT, Direction2d::LEFT  }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::BACK, Position::RIGHT,  Position::BOTTOM    }, Position::RIGHT, Direction2d::UP    }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::BACK, Position::RIGHT,  Position::BOTTOM    }, Position::RIGHT, Direction2d::DOWN  }, Rotation1::FRONT_ROTATE_RIGHT },

	{ { { Position::BACK, Position::RIGHT,  Position::BOTTOM    }, Position::BOTTOM, Direction2d::RIGHT }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::BACK, Position::RIGHT,  Position::BOTTOM    }, Position::BOTTOM, Direction2d::LEFT  }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::BACK, Position::RIGHT,  Position::BOTTOM    }, Position::BOTTOM, Direction2d::UP    }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::BACK, Position::RIGHT,  Position::BOTTOM    }, Position::BOTTOM, Direction2d::DOWN  }, Rotation1::FRONT_ROTATE_RIGHT},

//edge 1
	{ { { Position::FRONT, Position::LEFT }, Position::FRONT, Direction2d::RIGHT }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::FRONT, Position::LEFT }, Position::FRONT, Direction2d::LEFT }, Rotation1::FRONT_ROTATE_LEFT },
	{ { { Position::FRONT, Position::LEFT }, Position::FRONT, Direction2d::UP }, Rotation1::LEFT_ROTATE_UP },
	{ { { Position::FRONT, Position::LEFT }, Position::FRONT, Direction2d::DOWN }, Rotation1::LEFT_ROTATE_DOWN },

	{ { { Position::FRONT, Position::LEFT }, Position::LEFT, Direction2d::RIGHT }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::FRONT, Position::LEFT }, Position::LEFT, Direction2d::LEFT  }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::FRONT, Position::LEFT }, Position::LEFT, Direction2d::UP    }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::FRONT, Position::LEFT }, Position::LEFT, Direction2d::DOWN  }, Rotation1::FRONT_ROTATE_RIGHT },

//edge 2
	{ { { Position::FRONT, Position::RIGHT }, Position::FRONT, Direction2d::RIGHT }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::FRONT, Position::RIGHT }, Position::FRONT, Direction2d::LEFT }, Rotation1::FRONT_ROTATE_LEFT },
	{ { { Position::FRONT, Position::RIGHT }, Position::FRONT, Direction2d::UP }, Rotation1::LEFT_ROTATE_UP },
	{ { { Position::FRONT, Position::RIGHT }, Position::FRONT, Direction2d::DOWN }, Rotation1::LEFT_ROTATE_DOWN },

	{ { { Position::FRONT, Position::RIGHT }, Position::RIGHT, Direction2d::RIGHT }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::FRONT, Position::RIGHT }, Position::RIGHT, Direction2d::LEFT  }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::FRONT, Position::RIGHT }, Position::RIGHT, Direction2d::UP    }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::FRONT, Position::RIGHT }, Position::RIGHT, Direction2d::DOWN  }, Rotation1::FRONT_ROTATE_RIGHT },

//edge 3
	{ { { Position::FRONT, Position::TOP }, Position::FRONT, Direction2d::RIGHT }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::FRONT, Position::TOP }, Position::FRONT, Direction2d::LEFT  }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::FRONT, Position::TOP }, Position::FRONT, Direction2d::UP    }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::FRONT, Position::TOP }, Position::FRONT, Direction2d::DOWN  }, Rotation1::FRONT_ROTATE_RIGHT },

	{ { { Position::FRONT, Position::TOP }, Position::TOP, Direction2d::RIGHT }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::FRONT, Position::TOP }, Position::TOP, Direction2d::LEFT }, Rotation1::FRONT_ROTATE_LEFT },
	{ { { Position::FRONT, Position::TOP }, Position::TOP, Direction2d::UP }, Rotation1::LEFT_ROTATE_UP },
	{ { { Position::FRONT, Position::TOP }, Position::TOP, Direction2d::DOWN }, Rotation1::LEFT_ROTATE_DOWN },

//edge 4
	{ { { Position::FRONT, Position::BOTTOM }, Position::FRONT, Direction2d::RIGHT }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::FRONT, Position::BOTTOM }, Position::FRONT, Direction2d::LEFT  }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::FRONT, Position::BOTTOM }, Position::FRONT, Direction2d::UP    }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::FRONT, Position::BOTTOM }, Position::FRONT, Direction2d::DOWN  }, Rotation1::FRONT_ROTATE_RIGHT },

	{ { { Position::FRONT, Position::BOTTOM }, Position::BOTTOM, Direction2d::RIGHT }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::FRONT, Position::BOTTOM }, Position::BOTTOM, Direction2d::LEFT  }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::FRONT, Position::BOTTOM }, Position::BOTTOM, Direction2d::UP    }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::FRONT, Position::BOTTOM }, Position::BOTTOM, Direction2d::DOWN  }, Rotation1::FRONT_ROTATE_RIGHT },

		//edge 5
	{ { { Position::TOP, Position::LEFT }, Position::TOP, Direction2d::RIGHT }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::TOP, Position::LEFT }, Position::TOP, Direction2d::LEFT  }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::TOP, Position::LEFT }, Position::TOP, Direction2d::UP    }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::TOP, Position::LEFT }, Position::TOP, Direction2d::DOWN  }, Rotation1::FRONT_ROTATE_RIGHT },

	{ { { Position::TOP, Position::LEFT }, Position::LEFT, Direction2d::RIGHT }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::TOP, Position::LEFT }, Position::LEFT, Direction2d::LEFT  }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::TOP, Position::LEFT }, Position::LEFT, Direction2d::UP    }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::TOP, Position::LEFT }, Position::LEFT, Direction2d::DOWN  }, Rotation1::FRONT_ROTATE_RIGHT },

		//edge 6
	{ { { Position::TOP, Position::RIGHT }, Position::TOP, Direction2d::RIGHT }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::TOP, Position::RIGHT }, Position::TOP, Direction2d::LEFT  }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::TOP, Position::RIGHT }, Position::TOP, Direction2d::UP    }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::TOP, Position::RIGHT }, Position::TOP, Direction2d::DOWN  }, Rotation1::FRONT_ROTATE_RIGHT },

	{ { { Position::TOP, Position::RIGHT }, Position::RIGHT, Direction2d::RIGHT }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::TOP, Position::RIGHT }, Position::RIGHT, Direction2d::LEFT  }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::TOP, Position::RIGHT }, Position::RIGHT, Direction2d::UP    }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::TOP, Position::RIGHT }, Position::RIGHT, Direction2d::DOWN  }, Rotation1::FRONT_ROTATE_RIGHT },

		//edge 7
	{ { { Position::BOTTOM, Position::LEFT }, Position::BOTTOM, Direction2d::RIGHT }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::BOTTOM, Position::LEFT }, Position::BOTTOM, Direction2d::LEFT  }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::BOTTOM, Position::LEFT }, Position::BOTTOM, Direction2d::UP    }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::BOTTOM, Position::LEFT }, Position::BOTTOM, Direction2d::DOWN  }, Rotation1::FRONT_ROTATE_RIGHT },

	{ { { Position::BOTTOM, Position::LEFT }, Position::LEFT, Direction2d::RIGHT }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::BOTTOM, Position::LEFT }, Position::LEFT, Direction2d::LEFT  }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::BOTTOM, Position::LEFT }, Position::LEFT, Direction2d::UP    }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::BOTTOM, Position::LEFT }, Position::LEFT, Direction2d::DOWN  }, Rotation1::FRONT_ROTATE_RIGHT },

		//edge 8
	{ { { Position::BOTTOM, Position::RIGHT }, Position::BOTTOM, Direction2d::RIGHT }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::BOTTOM, Position::RIGHT }, Position::BOTTOM, Direction2d::LEFT  }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::BOTTOM, Position::RIGHT }, Position::BOTTOM, Direction2d::UP    }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::BOTTOM, Position::RIGHT }, Position::BOTTOM, Direction2d::DOWN  }, Rotation1::FRONT_ROTATE_RIGHT },

	{ { { Position::BOTTOM, Position::RIGHT }, Position::RIGHT, Direction2d::RIGHT }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::BOTTOM, Position::RIGHT }, Position::RIGHT, Direction2d::LEFT  }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::BOTTOM, Position::RIGHT }, Position::RIGHT, Direction2d::UP    }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::BOTTOM, Position::RIGHT }, Position::RIGHT, Direction2d::DOWN  }, Rotation1::FRONT_ROTATE_RIGHT },

		//edge 9
	{ { { Position::BACK, Position::LEFT }, Position::BACK, Direction2d::RIGHT }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::BACK, Position::LEFT }, Position::BACK, Direction2d::LEFT }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::BACK, Position::LEFT }, Position::BACK, Direction2d::UP }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::BACK, Position::LEFT }, Position::BACK, Direction2d::DOWN }, Rotation1::FRONT_ROTATE_RIGHT },

	{ { { Position::BACK, Position::LEFT }, Position::LEFT, Direction2d::RIGHT }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::BACK, Position::LEFT }, Position::LEFT, Direction2d::LEFT }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::BACK, Position::LEFT }, Position::LEFT, Direction2d::UP }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::BACK, Position::LEFT }, Position::LEFT, Direction2d::DOWN }, Rotation1::FRONT_ROTATE_RIGHT },

	//edge 10
	{ { { Position::BACK, Position::RIGHT }, Position::BACK, Direction2d::RIGHT }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::BACK, Position::RIGHT }, Position::BACK, Direction2d::LEFT  }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::BACK, Position::RIGHT }, Position::BACK, Direction2d::UP    }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::BACK, Position::RIGHT }, Position::BACK, Direction2d::DOWN  }, Rotation1::FRONT_ROTATE_RIGHT },

	{ { { Position::BACK, Position::RIGHT }, Position::RIGHT, Direction2d::RIGHT }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::BACK, Position::RIGHT }, Position::RIGHT, Direction2d::LEFT  }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::BACK, Position::RIGHT }, Position::RIGHT, Direction2d::UP    }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::BACK, Position::RIGHT }, Position::RIGHT, Direction2d::DOWN  }, Rotation1::FRONT_ROTATE_RIGHT },

		//edge 11
	{ { { Position::BACK, Position::TOP }, Position::BACK, Direction2d::RIGHT }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::BACK, Position::TOP }, Position::BACK, Direction2d::LEFT }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::BACK, Position::TOP }, Position::BACK, Direction2d::UP }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::BACK, Position::TOP }, Position::BACK, Direction2d::DOWN }, Rotation1::FRONT_ROTATE_RIGHT },

	{ { { Position::BACK, Position::TOP }, Position::TOP, Direction2d::RIGHT }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::BACK, Position::TOP }, Position::TOP, Direction2d::LEFT }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::BACK, Position::TOP }, Position::TOP, Direction2d::UP }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::BACK, Position::TOP }, Position::TOP, Direction2d::DOWN }, Rotation1::FRONT_ROTATE_RIGHT },

	//edge 12
	{ { { Position::BACK, Position::BOTTOM}, Position::BACK, Direction2d::RIGHT }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::BACK, Position::BOTTOM}, Position::BACK, Direction2d::LEFT  }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::BACK, Position::BOTTOM}, Position::BACK, Direction2d::UP    }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::BACK, Position::BOTTOM}, Position::BACK, Direction2d::DOWN  }, Rotation1::FRONT_ROTATE_RIGHT },

	{ { { Position::BACK, Position::BOTTOM}, Position::BOTTOM, Direction2d::RIGHT }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::BACK, Position::BOTTOM}, Position::BOTTOM, Direction2d::LEFT  }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::BACK, Position::BOTTOM}, Position::BOTTOM, Direction2d::UP    }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::BACK, Position::BOTTOM}, Position::BOTTOM, Direction2d::DOWN  }, Rotation1::FRONT_ROTATE_RIGHT },

//surface 1
	{ { { Position::FRONT }, Position::FRONT, Direction2d::RIGHT }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::FRONT }, Position::FRONT, Direction2d::LEFT }, Rotation1::FRONT_ROTATE_LEFT },
	{ { { Position::FRONT }, Position::FRONT, Direction2d::UP }, Rotation1::LEFT_ROTATE_UP },
	{ { { Position::FRONT }, Position::FRONT, Direction2d::DOWN }, Rotation1::LEFT_ROTATE_DOWN },

		//surface 2
	{ { { Position::BACK }, Position::BACK, Direction2d::RIGHT }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::BACK }, Position::BACK, Direction2d::LEFT  }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::BACK }, Position::BACK, Direction2d::UP    }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::BACK }, Position::BACK, Direction2d::DOWN  }, Rotation1::FRONT_ROTATE_RIGHT },

		//surface 3
	{ { { Position::TOP }, Position::TOP, Direction2d::RIGHT }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::TOP }, Position::TOP, Direction2d::LEFT  }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::TOP }, Position::TOP, Direction2d::UP    }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::TOP }, Position::TOP, Direction2d::DOWN  }, Rotation1::FRONT_ROTATE_RIGHT },

		//surface 4
	{ { { Position::BOTTOM }, Position::BOTTOM, Direction2d::RIGHT }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::BOTTOM }, Position::BOTTOM, Direction2d::LEFT }, Rotation1::FRONT_ROTATE_LEFT },
	{ { { Position::BOTTOM }, Position::BOTTOM, Direction2d::UP }, Rotation1::LEFT_ROTATE_UP },
	{ { { Position::BOTTOM }, Position::BOTTOM, Direction2d::DOWN }, Rotation1::LEFT_ROTATE_DOWN },

		//surface 5
	{ { { Position::RIGHT }, Position::RIGHT, Direction2d::RIGHT }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::RIGHT }, Position::RIGHT, Direction2d::LEFT  }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::RIGHT }, Position::RIGHT, Direction2d::UP    }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::RIGHT }, Position::RIGHT, Direction2d::DOWN  }, Rotation1::FRONT_ROTATE_RIGHT },

		//surface 6
	{ { { Position::LEFT }, Position::LEFT, Direction2d::RIGHT }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::LEFT }, Position::LEFT, Direction2d::LEFT  }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::LEFT }, Position::LEFT, Direction2d::UP    }, Rotation1::FRONT_ROTATE_RIGHT },
	{ { { Position::LEFT }, Position::LEFT, Direction2d::DOWN  }, Rotation1::FRONT_ROTATE_RIGHT },

	};
}