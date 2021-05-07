#include "Tile.h"

// For aa sette labelfarge i henhold til hvor mange miner som er rundt
const map<int, Color> minesToColor{{1, Color::blue},
								   {2, Color::red},
								   {3, Color::dark_green},
								   {4, Color::dark_magenta},
								   {5, Color::dark_blue},
								   {6, Color::dark_cyan},
								   {7, Color::dark_red},
								   {8, Color::dark_yellow}};

// For aa sette Tilelabel i henhold til state
const map<Cell, string> cellToSymbol{{Cell::closed, ""},
									 {Cell::open, ""},
									 {Cell::flagged, "@<"}};

void Tile::open()
{
	//Gjør ingenting dersom state er flagget
	//eller open
	if(state == Cell::flagged || state == Cell::open){
		return;
	}
	//Dersom state er closed åpner vi knappen
	//samt setter state til open
	if(state == Cell::closed){
		static_cast<Fl_Button *>(pw)->set(); //Setter en button som trykket paa, tilsvarer aapnet rute
		state = Cell::open;
	}

	//Hvis det er en mine setter vi
	//label til X og farge til rød
	if(isMine){
		set_label("X");
		set_label_color(Color::red);
	}
}

void Tile::flag()
{
	if(state == Cell::flagged){
		state = Cell::closed;
		set_label(cellToSymbol.at(Cell::closed));
	}else{
		state == Cell::flagged;
		set_label(cellToSymbol.at(Cell::flagged));
		set_label_color(minesToColor.at(1));
	}
}

bool Tile::getMine() const {
	return isMine;
} 

void Tile::setMine(bool value){
	isMine = value;
}

void Tile::setAdjMines(int n){
	set_label(to_string(n));
	set_label_color(minesToColor.at(n));
}

Point Tile::getPos() const{
	return pos;
}
