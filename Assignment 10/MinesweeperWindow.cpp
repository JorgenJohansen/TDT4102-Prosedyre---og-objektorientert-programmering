#include "MinesweeperWindow.h"
static void cb_restart(Address, Address pw){ static_cast<Fl_Button*>(pw)->value(0); };
static void cb_quit(Address, Address pw){ reference_to<MinesweeperWindow>(pw).hide(); };

MinesweeperWindow::MinesweeperWindow(Point xy, int width, int height, int mines, int counter, const string& title) :
	Graph_lib::Window{xy, width * cellSize, height*cellSize+100, title}, win{Point{10,450},"Gratulerer! Du vant!"}, fail{Point{10,450},"Game over!"}, 
	restart_btn{Point{200,420},80,20,"Restart",cb_restart}, quit_btn{Point{200,440},80,20,"Quit",cb_quit},
	message{Point{10,420},"Det er " + to_string(mines) + " miner på brettet"}, width{width}, height{height}, mines{mines}, counter{counter}
	
	//Graph_lib::Menu{Point{100,420},width,height,horizontal,title},
	//Initialiser medlemsvariabler, bruker konstruktoren til Windowsklassen
{
	// Legg til alle tiles i vinduet
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			tiles.push_back(new Tile{ Point{j * cellSize, i * cellSize}, cellSize, cb_click });
			attach(tiles.back());
		}
	}

	//Legg til miner paa tilfeldige posisjoner
	//Setter et frø
	srand(static_cast<unsigned int>(time(nullptr)));
	
	//Looper gjennom brettet
	//TODO: få miner nedover brettet
	for (int i = 0; i < tiles.size(); ++i) {
		int random = rand() % tiles.size() + 0;
		if(!tiles[random].getMine() && mines > 0){
			tiles[random].setMine(true);
			mines--;
		}
	}

	attach(message);
	attach(restart_btn);
	attach(quit_btn);

	// Fjern window reskalering
	resizable(nullptr);
	size_range(x_max(), y_max(), x_max(), y_max());
}

void MinesweeperWindow::restart(){
	//static_cast<
}

void MinesweeperWindow::quit(){
	
}


vector<Point> MinesweeperWindow::adjacentPoints(Point xy) const {
	vector<Point> points;
	for (int di = -1; di <= 1; ++di) {
		for (int dj = -1; dj <= 1; ++dj) {
			if (di == 0 && dj == 0) {
				continue;
			}

			Point neighbour{ xy.x + di * cellSize,xy.y + dj * cellSize };
			if (inRange(neighbour)) {
				points.push_back(neighbour);
			}
		}
	}

	return points;
}

void MinesweeperWindow::openTile(Point xy) {
	
	cout << counter << endl;
	int neighborMines = countMines(adjacentPoints(xy));
	//cout << neighborMines << endl;
	if(at(xy).getState() == Cell::closed){
		at(xy).open();
		if(at(xy).getMine() && counter > 1){
			attach(fail);
			for(auto* tile : tiles){
				if(tile->getMine()){
					tile->open();
				}
			}
		
		}else if(neighborMines == 0){
			counter++;
			for(Point point : adjacentPoints(xy)){
				//Rekursivt åpner de andre rutene
				openTile(point);
			}
		}else if(neighborMines > 0){
			counter++;
			at(xy).setAdjMines(neighborMines);
		}
	}

	if(counter == tiles.size()-mines){
		attach(win);
		for(auto* tile : tiles){
			if(tile->getMine()){
				tile->flag();
			}
		}
	}
	
}

void MinesweeperWindow::flagTile(Point xy) {
	
	if(at(xy).getState() == Cell::flagged || at(xy).getState() == Cell::closed){
		at(xy).flag();
	}
	
}

int MinesweeperWindow::countMines(vector<Point> points) const{
	int numberOfMines = 0;
	for(Point point : points){
		if(at(point).getMine()){
			numberOfMines++;
		}
	}
	return numberOfMines;
}

//Kaller openTile ved venstreklikk og flagTile ved hoyreklikk/trykke med to fingre paa mac
void MinesweeperWindow::click()
{
	Point xy{Fl::event_x(), Fl::event_y()};

	MouseButton mb = static_cast<MouseButton>(Fl::event_button());

	if (!inRange(xy)) {
		return;
	}

	switch (mb) {
	case MouseButton::left:
		openTile(xy);
		break;
	case MouseButton::right:
		flagTile(xy);
		break;
	}

	flush();
}
